% Acceptance diagram propagation movie
clc
box on
clear all

fig_handle = figure(1);

set(0,'DefaultAxesFontName', 'Times New Roman')
set(0,'DefaultAxesFontSize', 20)

beam_x_start = 1.5;
beam_x_div = 1.2;

L = linspace(0,60,61);
t_max=length(L);

t=t_max;
y{t} = linspace(-beam_x_div,beam_x_div,10);
x_left{t} = -0.5*beam_x_start+L(t)*tand(y{t});
x_right{t} = 0.5*beam_x_start+L(t)*tand(y{t});


lim_x(1) = x_left{t_max}(1)*1.7;
lim_x(2) = x_right{t_max}(end)*1.7;
text_x = x_left{t_max}(1)*1.3;

color = 'k';
width = 2;


%writerObj = VideoWriter('test.avi')%,'MPEG-4');
%getProfiles(writerObj)
%writerObj.FileFormat = 'MPEG-4';
%writerObj.Height = 200

%open(writerObj);



for t=1:4:t_max
y{t} = linspace(-beam_x_div,beam_x_div,10);
x_left{t} = -0.5*beam_x_start+L(t)*tand(y{t});
x_right{t} = 0.5*beam_x_start+L(t)*tand(y{t});

plot(x_left{t},y{t},'linewidth',width,'color',color)
hold on
plot(x_right{t},y{t},'linewidth',width,'color',color)
plot([x_left{t}(1) x_right{t}(1)],[y{t}(1) y{t}(1)],'linewidth',width,'color',color)
plot([x_left{t}(end) x_right{t}(end)],[y{t}(end) y{t}(end)],'linewidth',width,'color',color)
hold off

ylim([-beam_x_div(1)*1.5 beam_x_div(1)*1.5])
%xlim([x_left{t_max}(1)*1.5 x_right{t_max}(end)*1.5])
xlim(lim_x)
h = text(text_x,beam_x_div(1)*1.3,['L = ' num2str(L(t)) ' cm']);
set(h,'fontsize',20,'interpreter','latex')
xlabel('position [cm]','interpreter','latex')
ylabel('divergence [deg]','interpreter','latex')

frames(t) = getframe(fig_handle);
%print(fig_handle,'-depsc',['part' num2str(t) '.eps'])
%writeVideo(writerObj,frames(t));
eval(['print -dpng noguide_' num2str(t) '.png']);
end

%movie2avi(frames, 'without_guide.avi','compression','None','fps',10);

%close(writerObj);

%movie(frames,2)

%%

% Hvad nu hvis der var en guide ved guide_x ?

guide_x = beam_x_start*1.2;

for t=1:4:t_max
y{t} = linspace(-beam_x_div,beam_x_div,100);
for i = 1:length(y{t})
    x_left{t}(i) = -0.5*beam_x_start+L(t)*tand(y{t}(i));
    x_right{t}(i) = 0.5*beam_x_start+L(t)*tand(y{t}(i));
    if x_left{t}(i) < -guide_x*0.5
        x_left2{t}(i) = -guide_x - x_left{t}(i);
        x_left{t}(i) = -guide_x*0.5;
        x_2_l_on(t,i) = 1;
    else
        x_2_l_on(t,i) = 0;
    end
    if x_right{t}(i) > guide_x*0.5
        x_right2{t}(i) = guide_x - x_right{t}(i);
        x_right{t}(i) = guide_x*0.5;
        x_2_r_on(t,i) = 1;
    else
        x_2_r_on(t,i) = 0;
    end
end
plot([-guide_x*0.5 -guide_x*0.5],[-beam_x_div*1.5 beam_x_div*1.5],'--','color',[0.6 0.6 0.6])

hold on
plot([guide_x*0.5 guide_x*0.5],[-beam_x_div*1.5 beam_x_div*1.5],'--','color',[0.6 0.6 0.6])
plot(x_left{t},y{t},'linewidth',width,'color',color)
plot(x_right{t},y{t},'linewidth',width,'color',color)
plot([x_left{t}(1) x_right{t}(1)],[y{t}(1) y{t}(1)],'linewidth',width,'color',color)
plot([x_left{t}(end) x_right{t}(end)],[y{t}(end) y{t}(end)],'linewidth',width,'color',color)
logi = x_2_l_on(t,:)==1
if sum(x_2_l_on(t,:)) > 1
    log_a = find(logi);
    end_p = log_a(end);
    start_p = log_a(1);
    plot(x_left2{t}(logi),-y{t}(logi),'linewidth',width,'color',color)
    plot([-guide_x*0.5 x_left2{t}(start_p)],[-y{t}(start_p) -y{t}(start_p)],'linewidth',width,'color',color)
    plot([-guide_x*0.5 -guide_x*0.5],[-y{t}(logi(1)) -y{t}(end_p)],'linewidth',width,'color',color)
end
clear logi
logi = x_2_r_on(t,:)==1
if sum(x_2_r_on(t,:)) > 1
    
    log_a = find(logi);
    start_p = log_a(1);
    end_p = log_a(end);
    plot(x_right2{t}(logi),-y{t}(logi),'linewidth',width,'color',color)
    plot([guide_x*0.5 x_right2{t}(end_p)],[y{t}(logi(start_p)) y{t}(logi(start_p))],'linewidth',width,'color',color)
    plot([guide_x*0.5 guide_x*0.5],[-y{t}(start_p) -y{t}(end_p)],'linewidth',width,'color',color)
end


hold off

ylim([-beam_x_div(1)*1.5 beam_x_div(1)*1.5])
xlim(lim_x)
%xlim([x_left{t_max}(1)*1.5 x_right{t_max}(end)*1.5])
h = text(text_x,beam_x_div(1)*1.3,['L = ' num2str(L(t)) ' cm']);
set(h,'fontsize',20,'interpreter','latex')
xlabel('position [cm]','interpreter','latex')
ylabel('divergence [deg]','interpreter','latex')

frames(t) = getframe(fig_handle);
%print(fig_handle,'-depsc',['part' num2str(t) '.eps'])
%writeVideo(writerObj,frames(t));

eval(['print -dpng withguide_' num2str(t) '.png']);
end

%movie2avi(frames, 'guide.avi','compression','None','fps',10);

%%

% Acceptance diagram propagation movie
clc
box on
clear all

fig_handle = figure(1);

set(0,'DefaultAxesFontName', 'Times New Roman')
set(0,'DefaultAxesFontSize', 20)

beam_x_start = 1.5;
beam_x_div = 1.2;

L = linspace(0,60,61);
t_max=length(L);

t=t_max;
y{t} = linspace(-beam_x_div,beam_x_div,10);
x_left{t} = -0.5*beam_x_start+L(t)*tand(y{t});
x_right{t} = 0.5*beam_x_start+L(t)*tand(y{t});


lim_x(1) = x_left{t_max}(1)*1.7;
lim_x(2) = x_right{t_max}(end)*1.7;
text_x = x_left{t_max}(1)*1.3;

color = 'k';
width = 2;


%writerObj = VideoWriter('test.avi')%,'MPEG-4');
%getProfiles(writerObj)
%writerObj.FileFormat = 'MPEG-4';
%writerObj.Height = 200

%open(writerObj);



for t=1:4:t_max
y{t} = linspace(-beam_x_div,beam_x_div,10);
x_left{t} = -0.5*beam_x_start+L(t)*tand(y{t});
x_right{t} = 0.5*beam_x_start+L(t)*tand(y{t});

plot(x_left{t},y{t},'linewidth',width,'color',color)
hold on
plot(x_right{t},y{t},'linewidth',width,'color',color)
plot([x_left{t}(1) x_right{t}(1)],[y{t}(1) y{t}(1)],'linewidth',width,'color',color)
plot([x_left{t}(end) x_right{t}(end)],[y{t}(end) y{t}(end)],'linewidth',width,'color',color)
hold off

ylim([-beam_x_div(1)*1.5 beam_x_div(1)*1.5])
%xlim([x_left{t_max}(1)*1.5 x_right{t_max}(end)*1.5])
xlim(lim_x)
h = text(text_x,beam_x_div(1)*1.3,['L = ' num2str(L(t)) ' cm']);
set(h,'fontsize',20,'interpreter','latex')
xlabel('position [cm]','interpreter','latex')
ylabel('divergence [deg]','interpreter','latex')


t_frame = t_max - t + 1;
frames(t_frame) = getframe(fig_handle);
%print(fig_handle,'-depsc',['part' num2str(t) '.eps'])
%writeVideo(writerObj,frames(t));
%eval(['print -dpng 3guide_' num2str(t) '.png']);
end

%movie2avi(frames, 'backwards.avi','compression','None','fps',10);

%close(writerObj);

%%

% Acceptance diagram propagation movie
clc
box on
clear all

fig_handle = figure(1);

set(0,'DefaultAxesFontName', 'Times New Roman')
set(0,'DefaultAxesFontSize', 20)

beam_x_start = 1.5;
beam_x_div = 1.2;

L = linspace(0,60,61);
%L = linspace(0,-60,61);
t_max=length(L);

t=t_max;
y{t} = linspace(-beam_x_div,beam_x_div,10);
x_left{t} = -0.5*beam_x_start+L(t)*tand(y{t});
x_right{t} = 0.5*beam_x_start+L(t)*tand(y{t});


lim_x(1) = x_left{t_max}(1)*1.7;
lim_x(2) = x_right{t_max}(end)*1.7;
text_x = x_left{t_max}(1)*1.3;

color = 'k';
width = 2;


%writerObj = VideoWriter('test.avi')%,'MPEG-4');
%getProfiles(writerObj)
%writerObj.FileFormat = 'MPEG-4';
%writerObj.Height = 200

%open(writerObj);



for t=1:4:t_max
y{t} = linspace(-beam_x_div,beam_x_div,10);
x_left{t} = -0.5*beam_x_start-L(t)*tand(y{t});
x_right{t} = 0.5*beam_x_start-L(t)*tand(y{t});

plot(x_left{t},y{t},'linewidth',width,'color',color)
hold on
plot(x_right{t},y{t},'linewidth',width,'color',color)
plot([x_left{t}(1) x_right{t}(1)],[y{t}(1) y{t}(1)],'linewidth',width,'color',color)
plot([x_left{t}(end) x_right{t}(end)],[y{t}(end) y{t}(end)],'linewidth',width,'color',color)
hold off

ylim([-beam_x_div(1)*1.5 beam_x_div(1)*1.5])
%xlim([x_left{t_max}(1)*1.5 x_right{t_max}(end)*1.5])
xlim(lim_x)
h = text(text_x,beam_x_div(1)*1.3,['L = ' num2str(-L(t)) ' cm']);
set(h,'fontsize',20,'interpreter','latex')
xlabel('position [cm]','interpreter','latex')
ylabel('divergence [deg]','interpreter','latex')


%t_frame = t_max - t + 1;
%frames(t_frame) = getframe(fig_handle);

frames(t) = getframe(fig_handle);
%print(fig_handle,'-depsc',['part' num2str(t) '.eps'])
%writeVideo(writerObj,frames(t));
%eval(['print -dpng 4guide_' num2str(t) '.png']);
end

%movie2avi(frames, 'backwards_secondary.avi','compression','None','fps',10);

%close(writerObj);

%% Multiply reflecting guide

% Acceptance diagram propagation movie
clc
box on
clear all

fig_handle = figure(1);

set(0,'DefaultAxesFontName', 'Times New Roman')
set(0,'DefaultAxesFontSize', 20)

beam_x_div = 1.2;
beam_x_start = 1.5;


L = linspace(0,60,61);
t_max=length(L);


t_max=length(L);
t=t_max;
y{t} = linspace(-beam_x_div,beam_x_div,10);
x_left{t} = -0.5*beam_x_start+L(t)*tand(y{t});
x_right{t} = 0.5*beam_x_start+L(t)*tand(y{t});

lim_x(1) = x_left{t_max}(1)*1.7;
lim_x(2) = x_right{t_max}(end)*1.7;
text_x = x_left{t_max}(1)*1.3;


t=t_max;
y{t} = linspace(-beam_x_div,beam_x_div,10);
x_left{t} = -0.5*beam_x_start+L(t)*tand(y{t})-0.60*tand(beam_x_div);
x_right{t} = 0.5*beam_x_start+L(t)*tand(y{t})+0.60*tand(beam_x_div);

%lim_x(1) = x_left{t_max}(1)*1.5;
%lim_x(2) = x_right{t_max}(end)*1.5;
%text_x = x_left{t_max}(1)*1.3;

color = 'k';
width = 2;


%writerObj = VideoWriter('test.avi')%,'MPEG-4');
%getProfiles(writerObj)
%writerObj.FileFormat = 'MPEG-4';
%writerObj.Height = 200

%open(writerObj);



for t=1:4:t_max
y{t} = linspace(-beam_x_div,beam_x_div,10);
x_left{t} = -0.5*beam_x_start+L(t)*tand(y{t})-61*tand(beam_x_div);
x_right{t} = 0.5*beam_x_start+L(t)*tand(y{t})+61*tand(beam_x_div);


plot([beam_x_start*0.5 beam_x_start*0.5],[-beam_x_div*1.5 beam_x_div*1.5],'--','color',[0.6 0.6 0.6],'linewidth',2)
hold on
plot([-beam_x_start*0.5 -beam_x_start*0.5],[-beam_x_div*1.5 beam_x_div*1.5],'--','color',[0.6 0.6 0.6],'linewidth',2)
plot(x_left{t},y{t},'linewidth',width,'color',color)
plot(x_right{t},y{t},'linewidth',width,'color',color)
plot([x_left{t}(1) x_right{t}(1)],[y{t}(1) y{t}(1)],'linewidth',width,'color',color)
plot([x_left{t}(end) x_right{t}(end)],[y{t}(end) y{t}(end)],'linewidth',width,'color',color)
hold off

ylim([-beam_x_div(1)*1.5 beam_x_div(1)*1.5])
%xlim([x_left{t_max}(1)*1.5 x_right{t_max}(end)*1.5])
xlim(lim_x)
h = text(text_x,beam_x_div(1)*1.3,['L = ' num2str(L(t)) ' cm']);
set(h,'fontsize',20,'interpreter','latex')
xlabel('position [cm]','interpreter','latex')
ylabel('divergence [deg]','interpreter','latex')


frames(t) = getframe(fig_handle);
%print(fig_handle,'-depsc',['part' num2str(t) '.eps'])
%writeVideo(writerObj,frames(t));
end

%movie2avi(frames, 'multiply.avi','compression','None','fps',10);

%close(writerObj);


%% Moderator

% Acceptance diagram propagation movie
clc
box on
clear all

fig_handle = figure(1);

set(0,'DefaultAxesFontName', 'Times New Roman')
set(0,'DefaultAxesFontSize', 20)

beam_x_start = 12;
beam_x_div = 5;

L = linspace(0,202,102);
t_max=length(L);

t=t_max;
y{t} = linspace(-beam_x_div,beam_x_div,10);
x_left{t} = -0.5*beam_x_start+L(t)*tand(y{t});
x_right{t} = 0.5*beam_x_start+L(t)*tand(y{t});


lim_x(1) = x_left{t_max}(1)*1.05;
lim_x(2) = x_right{t_max}(end)*1.05;
text_x = x_left{t_max}(1)*0.9;

color = 'k';
width = 2;


%writerObj = VideoWriter('test.avi')%,'MPEG-4');
%getProfiles(writerObj)
%writerObj.FileFormat = 'MPEG-4';
%writerObj.Height = 200

%open(writerObj);

guide_start = 7;

for t=1:4:t_max
y{t} = linspace(-beam_x_div,beam_x_div,10);
x_left{t} = -0.5*beam_x_start+L(t)*tand(y{t});
x_right{t} = 0.5*beam_x_start+L(t)*tand(y{t});


x_fill = [-guide_start*0.5 -guide_start*0.5 guide_start*0.5 guide_start*0.5];
y_fill = [-2.75 0.75 2.75 -0.75];

if t > t_max - 2
    fill_handle = fill(x_fill,y_fill,'k')
    set(fill_handle,'facecolor',[0.8 0.8 0.8])
    %set(fill_handle,'facealpha',0.8)
    hold on
    plot([-guide_start*0.5 -guide_start*0.5],[-beam_x_div*1.5 beam_x_div*1.5],'--','color',[0.6 0.6 0.6],'linewidth',2)
else
    plot([-guide_start*0.5 -guide_start*0.5],[-beam_x_div*1.5 beam_x_div*1.5],'--','color',[0.6 0.6 0.6],'linewidth',2)
    hold on
end



plot([guide_start*0.5 guide_start*0.5],[-beam_x_div*1.5 beam_x_div*1.5],'--','color',[0.6 0.6 0.6],'linewidth',2)
plot(x_left{t},y{t},'linewidth',width,'color',color)
plot(x_right{t},y{t},'linewidth',width,'color',color)
plot([x_left{t}(1) x_right{t}(1)],[y{t}(1) y{t}(1)],'linewidth',width,'color',color)
plot([x_left{t}(end) x_right{t}(end)],[y{t}(end) y{t}(end)],'linewidth',width,'color',color)
hold off

ylim([-beam_x_div(1)*0.9 beam_x_div(1)*0.9])
%xlim([x_left{t_max}(1)*1.5 x_right{t_max}(end)*1.5])
xlim(lim_x)
h = text(text_x,beam_x_div(1)*0.8,['L = ' num2str(L(t)) ' cm']);
set(h,'fontsize',20,'interpreter','latex')
xlabel('position [cm]','interpreter','latex')
ylabel('divergence [deg]','interpreter','latex')




frames(t) = getframe(fig_handle);
%print(fig_handle,'-depsc',['part' num2str(t) '.eps'])
%writeVideo(writerObj,frames(t));
end

%movie2avi(frames, 'moderator.avi','compression','None','fps',10);



