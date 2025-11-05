import numpy as np
import mcstastox
import plopp as pp
import plopp.widgets as pw
import scipp as sc
import numpy as np
import ipywidgets as ipw

def merge_on_first_col_strict(A, B, C):
    """
    Join A with B and C by first column (unique integer id in each).
    If an id from A is missing in B or C, that row is dropped.

    Returns:
      merged : array with columns [A | B(:,1:) | C(:,1:)] for ids present in all three
      A_kept : rows from A that were kept (aligned to merged)
      B_sub  : rows from B aligned to A_kept (includes id col)
      C_sub  : rows from C aligned to A_kept (includes id col)
      dropped_info : dict with 'dropped_ids' and counts per reason
    """
    a_ids = A[:, 0]
    b_ids = B[:, 0]
    c_ids = C[:, 0]

    # Keep only A rows whose id appears in BOTH B and C
    in_b = np.isin(a_ids, b_ids, assume_unique=False)
    in_c = np.isin(a_ids, c_ids, assume_unique=False)
    keep_mask = in_b & in_c

    A_kept = A[keep_mask]
    keep_ids = A_kept[:, 0]

    # Build indexers mapping keep_ids -> rows in B and C
    b_sort = np.argsort(b_ids)
    c_sort = np.argsort(c_ids)
    b_pos = np.searchsorted(b_ids[b_sort], keep_ids)
    c_pos = np.searchsorted(c_ids[c_sort], keep_ids)
    b_idx = b_sort[b_pos]
    c_idx = c_sort[c_pos]

    # Safety (now guaranteed true by keep_mask, but left here if you want to re-enable)
    assert np.array_equal(b_ids[b_idx], keep_ids)
    assert np.array_equal(c_ids[c_idx], keep_ids)

    B_cols = B[b_idx, 1:] if B.shape[1] > 1 else np.empty((A_kept.shape[0], 0), dtype=B.dtype)
    C_cols = C[c_idx, 1:] if C.shape[1] > 1 else np.empty((A_kept.shape[0], 0), dtype=C.dtype)

    merged = np.concatenate([A_kept, B_cols, C_cols], axis=1)

    # Helpful diagnostics
    dropped_ids = a_ids[~keep_mask]
    dropped_info = {
        "dropped_ids": dropped_ids,
        "num_dropped": dropped_ids.size,
        "missing_in_B": a_ids[~in_b],
        "missing_in_C": a_ids[~in_c],
    }

    return merged, A_kept, B[b_idx], C[c_idx], dropped_info


def reduced_scipp(file_path):
        
    with mcstastox.Read(file_path) as loaded_data:
        before = loaded_data.get_event_data(variables=["vx", "vy", "vz", "n"], component_name="before_sample")
        after = loaded_data.get_event_data(variables=["x", "y", "z", "vx", "vy", "vz", "n"], component_name="after_sample")
        detector_raw = loaded_data.get_event_data(variables=["th", "y", "t", "p", "n"], component_name="Banana_1")
    
    import numpy as np
    V2K = 0.0015882536
    before_array = np.stack((before["n"], V2K*before["vx"], V2K*before["vy"], V2K*before["vz"]))
    
    distance_from_center = np.sqrt(after["x"]**2 + after["y"]**2 + after["z"]**2)
    
    after_array = np.stack((after["n"], V2K*after["vx"], V2K*after["vy"], V2K*after["vz"], distance_from_center))
    
    detector = np.stack((detector_raw["n"], detector_raw["th"], detector_raw["y"], detector_raw["t"], detector_raw["p"]))
    
    combined, A_kept, B_ids, C_ids, info = merge_on_first_col_strict(detector.T, before_array.T, after_array.T)
    
    del A_kept
    del B_ids
    del C_ids
    del before_array
    del after_array
    del detector
    
    columns = ["n", "th", "y", "t", "p", "kx_before", "ky_before", "kz_before", "kx_after", "ky_after", "kz_after", "sample_r"]
    
    import scipp as sc
    
    k_before = np.sqrt(combined[:, columns.index("kx_before")]**2 + combined[:, columns.index("ky_before")]**2 + combined[:, columns.index("kz_before")]**2)
    k_after = np.sqrt(combined[:, columns.index("kx_after")]**2 + combined[:, columns.index("ky_after")]**2 + combined[:, columns.index("kz_after")]**2)
    
    VS2E = 0.00000522703725000000
    K2V = 629.62236800000005132461
    
    e_change = VS2E*(k_before*K2V)**2 - VS2E*(k_after*K2V)**2
    
    qx = combined[:, columns.index("kx_before")] - combined[:, columns.index("kx_after")]
    qy = combined[:, columns.index("ky_before")] - combined[:, columns.index("ky_after")]
    qz = combined[:, columns.index("kz_before")] - combined[:, columns.index("kz_after")]
    
    
    da = sc.DataArray(
    data=sc.array(dims=["events"], values=combined[:, columns.index("p")], unit=sc.units.counts),
    coords={
      "qx": sc.array(dims=["events"], values=qx, unit="Å^-1"),
      "qy": sc.array(dims=["events"], values=qy, unit="Å^-1"),
      "qz": sc.array(dims=["events"], values=qz, unit="Å^-1"),
      "delta_E": sc.array(dims=["events"], values=e_change, unit="meV"),
      "t": sc.array(dims=["events"], values=combined[:, columns.index("t")], unit="s"),
      "y": sc.array(dims=["events"], values=combined[:, columns.index("y")], unit="m"),
      "th": sc.array(dims=["events"], values=combined[:, columns.index("th")], unit="deg"),
      "sample_r": sc.array(dims=["events"], values=combined[:, columns.index("sample_r")], unit="m"),
      },
    )
    radius = sc.scalar(1.0, unit="m")
    da.coords["x"] = radius * sc.sin(da.coords["th"])
    da.coords["z"] = radius * sc.cos(da.coords["th"])

    return da

def make_widget(da, point_size=0.005):
    from plopp.core.utils import coord_as_bin_edges

    def cut_multi(data, params):
        # params has dim, lim list of length 3, lim1, lim2, unit for each dimension to be cut
    
        bins = {dim: sc.array(dims=[dim], values=[lim[0], lim[1]], unit=lim[2]) for dim, lim in params.items()}
        
        return data.bin(**bins).bins.concat().value
    
    slider_dict = {}
    for cut_variable in ["qx", "qy", "qz", "th", "t", "y", "sample_r", "delta_E"]:
        var_min = da.coords[cut_variable].min().value
        var_max = da.coords[cut_variable].max().value
        
        var_range = var_max - var_min 
        
        var_slider = ipw.FloatSlider(min=var_min,
                                    max=var_max,
                                    value=0.5*var_range + var_min,
                                    step=0.01*var_range,
                                    readout_format='.3f',
                                    description=f"{cut_variable} center")
        var_slider_node = pp.widget_node(var_slider)
        
        var_size_slider = ipw.FloatSlider(min=0.01*var_range,
                                          max=2.0*var_range,
                                          value=2.0*var_range,
                                          step=0.01*var_range,
                                          readout_format='.3f',
                                          description=f"{cut_variable} width")
        var_size_slider_node = pp.widget_node(var_size_slider)
    
        slider_dict[cut_variable] = dict(var_slider=var_slider,
                                         var_slider_node=var_slider_node,
                                         var_size_slider=var_size_slider,
                                         var_size_slider_node=var_size_slider_node)
    
    
    def slider_params(th_slider, th_size_slider, 
                      t_slider, t_size_slider,
                      y_slider, y_size_slider,
                      qx_slider, qx_size_slider,
                      qy_slider, qy_size_slider,
                      qz_slider, qz_size_slider,
                      delta_E_slider, delta_E_size_slider,
                      sample_r_slider, sample_r_size_slider):
    
        return dict(
                    y=[y_slider - y_size_slider/2, y_slider + y_size_slider/2, "m"], 
                    t=[t_slider - t_size_slider/2, t_slider + t_size_slider/2, "s"],
                    th=[th_slider - th_size_slider/2, th_slider + th_size_slider/2, "deg"],
                    qx=[qx_slider - qx_size_slider/2, qx_slider + qx_size_slider/2, "Å^-1"],
                    qy=[qy_slider - qy_size_slider/2, qy_slider + qy_size_slider/2, "Å^-1"],
                    qz=[qz_slider - qz_size_slider/2, qz_slider + qz_size_slider/2, "Å^-1"],
                    delta_E=[delta_E_slider - delta_E_size_slider/2, delta_E_slider + delta_E_size_slider/2, "meV"],
                    sample_r=[sample_r_slider - sample_r_size_slider/2, sample_r_slider + sample_r_size_slider/2, "m"],
                  )
        
    slider_params_node = pp.Node(slider_params,
                                 th_slider=slider_dict["th"]["var_slider_node"],
                                 th_size_slider=slider_dict["th"]["var_size_slider_node"],
                                 t_slider=slider_dict["t"]["var_slider_node"],
                                 t_size_slider=slider_dict["t"]["var_size_slider_node"],
                                 y_slider=slider_dict["y"]["var_slider_node"],
                                 y_size_slider=slider_dict["y"]["var_size_slider_node"],
                                 qx_slider=slider_dict["qx"]["var_slider_node"],
                                 qx_size_slider=slider_dict["qx"]["var_size_slider_node"],
                                 qy_slider=slider_dict["qy"]["var_slider_node"],
                                 qy_size_slider=slider_dict["qy"]["var_size_slider_node"],
                                 qz_slider=slider_dict["qz"]["var_slider_node"],
                                 qz_size_slider=slider_dict["qz"]["var_size_slider_node"],
                                 delta_E_slider=slider_dict["delta_E"]["var_slider_node"],
                                 delta_E_size_slider=slider_dict["delta_E"]["var_size_slider_node"],
                                 sample_r_slider=slider_dict["sample_r"]["var_slider_node"],
                                 sample_r_size_slider=slider_dict["sample_r"]["var_size_slider_node"])
        
    def slider_cut(da, cut_params):
        return cut_multi(da, cut_params)
    
    subset_node = pp.Node(slider_cut, da=da, cut_params=slider_params_node)
    
    # keep autoscale False for speed
    plot_xz_node = pp.Node(lambda da : da.hist(qx=100, qz=100), da=subset_node)
    fig_xz = pp.imagefigure(plot_xz_node, autoscale=True, cbar=True)#, aspect="equal")
    
    plot_yz_node = pp.Node(lambda da : da.hist(qy=100, qz=100), da=subset_node)
    fig_yz = pp.imagefigure(plot_yz_node, autoscale=True, cbar=True)#, aspect="equal")
    
    plot_Ez_node = pp.Node(lambda da : da.hist(delta_E=100, qz=100), da=subset_node)
    fig_Ez = pp.imagefigure(plot_Ez_node, autoscale=True, cbar=True)#, aspect="equal")
     
    
    def update_image_xz(da):
        image, = fig_xz.artists.values()
    
        for i, k in enumerate("yx"):
            image._bin_edge_coords[k] = coord_as_bin_edges(
                image._data, image._data.dims[i]
            )
    
        image._xmin, image._xmax = image._bin_edge_coords["x"].values[[0, -1]]
        image._ymin, image._ymax = image._bin_edge_coords["y"].values[[0, -1]]
        image._dx = np.diff(image._bin_edge_coords["x"].values[:2])
        image._dy = np.diff(image._bin_edge_coords["y"].values[:2])
    
        image._image.set_extent([image._xmin, image._xmax, image._ymin, image._ymax])
    
        fig_xz.view.autoscale()
    
        return 
    
    def update_image_yz(da):
        image, = fig_yz.artists.values()
    
        for i, k in enumerate("yx"):
            image._bin_edge_coords[k] = coord_as_bin_edges(
                image._data, image._data.dims[i]
            )
    
        image._xmin, image._xmax = image._bin_edge_coords["x"].values[[0, -1]]
        image._ymin, image._ymax = image._bin_edge_coords["y"].values[[0, -1]]
        image._dx = np.diff(image._bin_edge_coords["x"].values[:2])
        image._dy = np.diff(image._bin_edge_coords["y"].values[:2])
    
        image._image.set_extent([image._xmin, image._xmax, image._ymin, image._ymax])
    
        fig_yz.view.autoscale()
    
        return 
    
    def update_image_Ez(da):
        image, = fig_Ez.artists.values()
    
        for i, k in enumerate("yx"):
            image._bin_edge_coords[k] = coord_as_bin_edges(
                image._data, image._data.dims[i]
            )
    
        image._xmin, image._xmax = image._bin_edge_coords["x"].values[[0, -1]]
        image._ymin, image._ymax = image._bin_edge_coords["y"].values[[0, -1]]
        image._dx = np.diff(image._bin_edge_coords["x"].values[:2])
        image._dy = np.diff(image._bin_edge_coords["y"].values[:2])
    
        image._image.set_extent([image._xmin, image._xmax, image._ymin, image._ymax])
    
        fig_Ez.view.autoscale()
    
        return 
    
    update_image_node_xz = pp.Node(update_image_xz, da=plot_xz_node)
    update_image_node_yz = pp.Node(update_image_yz, da=plot_yz_node)
    update_image_node_Ez = pp.Node(update_image_Ez, da=plot_Ez_node)
    
    #update_image_node_xz = pp.Node(update_image_xz, da=plot_xz_node)
    #update_image_node_yz = pp.Node(update_image_yz, da=plot_yz_node)
    
    def cut2(data, dim, limit1, limit2, unit):
        coord = data.coords[dim]
        selection = (coord >= sc.scalar(limit1, unit=unit)) & (coord <= sc.scalar(limit2, unit=unit))
        
        return da[selection]
    
    def mask_function(da, cut_params):
        out = da[::100].copy()
        #out.data = out.coords["t"]
    
        for key, value in cut_params.items():        
            out.masks[key] = (out.coords[key] < sc.scalar(value[0], unit=value[2])) | (out.coords[key] > sc.scalar(value[1], unit=value[2]))
            
        return out
    
    fig = pp.scatter3dfigure(pp.Node(mask_function, da=da, cut_params=slider_params_node), size=point_size, cbar=True)
    
    all_sliders = pp.widgets.Box([[slider_dict["th"]["var_slider"],  slider_dict["th"]["var_size_slider"], ipw.Label("deg")],
                    [slider_dict["t"]["var_slider"],  slider_dict["t"]["var_size_slider"], ipw.Label("s")],
                    [slider_dict["y"]["var_slider"], slider_dict["y"]["var_size_slider"], ipw.Label("m")],
                    [slider_dict["qx"]["var_slider"],  slider_dict["qx"]["var_size_slider"], ipw.Label("Å^-1")],
                    [slider_dict["qy"]["var_slider"],  slider_dict["qy"]["var_size_slider"], ipw.Label("Å^-1")],
                    [slider_dict["qz"]["var_slider"], slider_dict["qz"]["var_size_slider"], ipw.Label("Å^-1")],
                    [slider_dict["delta_E"]["var_slider"], slider_dict["delta_E"]["var_size_slider"], ipw.Label("meV")],
                    [slider_dict["sample_r"]["var_slider"], slider_dict["sample_r"]["var_size_slider"], ipw.Label("m")]],)
    
    return pp.widgets.Box([[fig_xz, fig_yz,],
                    [all_sliders, fig_Ez],
                    fig]
                    ), subset_node