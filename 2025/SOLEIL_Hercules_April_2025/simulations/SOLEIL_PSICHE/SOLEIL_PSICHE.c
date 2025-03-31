/* Automatically generated file. Do not edit. 
 * Format:     ANSI C source code
 * Creator:    McXtrace <http://www.mcxtrace.org>
 * Instrument: SOLEIL_PSICHE.instr (SOLEIL_PSICHE)
 * Date:       Tue Mar  5 17:33:48 2024
 * File:       ./SOLEIL_PSICHE.c
 * CFLAGS= -std=c99 -Wl,-rpath,GETPATH(lib) -LGETPATH(lib) -lxrl -IGETPATH(include) -DUSE_OFF -DFUNNEL 
 */

#ifndef WIN32
#  define _POSIX_C_SOURCE 200809L
#endif
/* In case of cl.exe on Windows, supppress warnings about #pragma acc */
#ifdef _MSC_EXTENSIONS
#pragma warning(disable: 4068)
#endif

#define MCCODE_STRING "McXtrace 3.4-20240304 - mars. 05, 2024"
#define FLAVOR        "mcxtrace"
#define FLAVOR_UPPER  "MCXTRACE"

#define MC_USE_DEFAULT_MAIN
#define MC_TRACE_ENABLED

#include <string.h>

typedef double MCNUM;
typedef struct {MCNUM x, y, z;} Coords;
typedef MCNUM Rotation[3][3];
#define MCCODE_BASE_TYPES

#ifndef MC_NUSERVAR
#define MC_NUSERVAR 10
#endif

/* Particle JUMP control logic */
struct particle_logic_struct {
int dummy;
};

struct _struct_particle {
  double x,y,z; /* position [m] */
  double kx,ky,kz; /* wave-vector */
  double phi, Ex,Ey,Ez; /* phase and electrical field */
  /* Generic Temporaries: */
  /* May be used internally by components e.g. for special */
  /* return-values from functions used in trace, thusreturned via */
  /* particle struct. (Example: Wolter Conics from McStas, silicon slabs.) */
  double _mctmp_a; /* temp a */
  double _mctmp_b; /* temp b */
  double _mctmp_c; /* temp c */
  unsigned long randstate[7];
  double t, p;     /* time, event weight */
  long long _uid;  /* Unique event ID */
  long _index;     /* component index where to send this event */
  long _absorbed;  /* flag set to TRUE when this event is to be removed/ignored */
  long _scattered; /* flag set to TRUE when this event has interacted with the last component instance */
  long _restore;   /* set to true if neutron event must be restored */
  long flag_nocoordschange;   /* set to true if particle is jumping */
  struct particle_logic_struct _logic;
};
typedef struct _struct_particle _class_particle;

_class_particle _particle_global_randnbuse_var;
_class_particle* _particle = &_particle_global_randnbuse_var;

#pragma acc routine
_class_particle mcgenstate(void);
#pragma acc routine
_class_particle mcsetstate(double x, double y, double z, double kx, double ky, double kz,
			   double phi, double t, double Ex, double Ey, double Ez, double p, int mcgravitation, void *mcMagnet, int mcallowbackprop);
#pragma acc routine
_class_particle mcgetstate(_class_particle mcphoton, double *x, double *y, double *z, double *kx, double *ky, double *kz,
			   double *phi, double *t, double *Ex, double *Ey, double *Ez, double *p);

extern int mcgravitation;      /* flag to enable gravitation */
#pragma acc declare create ( mcgravitation )
int mcallowbackprop;        
#pragma acc declare create ( mcallowbackprop )

_class_particle mcgenstate(void) {
  _class_particle particle = mcsetstate(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, mcgravitation, NULL, mcallowbackprop);
  return(particle);
}
/*Generated user variable handlers:*/

#pragma acc routine
double particle_getvar(_class_particle *p, char *name, int *suc);

#ifdef OPENACC
#pragma acc routine
int str_comp(char *str1, char *str2);
#endif

double particle_getvar(_class_particle *p, char *name, int *suc){
#ifndef OPENACC
#define str_comp strcmp
#endif
  int s=1;
  double rval=0;
  if(!str_comp("x",name)){rval=p->x;s=0;}
  if(!str_comp("y",name)){rval=p->y;s=0;}
  if(!str_comp("z",name)){rval=p->z;s=0;}
  if(!str_comp("phi",name)){rval=p->phi;s=0;}
  if(!str_comp("kx",name)){rval=p->kx;s=0;}
  if(!str_comp("ky",name)){rval=p->ky;s=0;}
  if(!str_comp("kz",name)){rval=p->kz;s=0;}
  if(!str_comp("Ex",name)){rval=p->Ex;s=0;}
  if(!str_comp("Ey",name)){rval=p->Ey;s=0;}
  if(!str_comp("Ez",name)){rval=p->Ez;s=0;}
  if(!str_comp("t",name)){rval=p->t;s=0;}
  if(!str_comp("p",name)){rval=p->p;s=0;}
  if(!str_comp("_mctmp_a",name)){rval=p->_mctmp_a;s=0;}
  if(!str_comp("_mctmp_b",name)){rval=p->_mctmp_b;s=0;}
  if(!str_comp("_mctmp_c",name)){rval=p->_mctmp_c;s=0;}
  if (suc!=0x0) {*suc=s;}
  return rval;
}

#pragma acc routine
void* particle_getvar_void(_class_particle *p, char *name, int *suc);

#ifdef OPENACC
#pragma acc routine
int str_comp(char *str1, char *str2);
#endif

void* particle_getvar_void(_class_particle *p, char *name, int *suc){
#ifndef OPENACC
#define str_comp strcmp
#endif
  int s=1;
  void* rval=0;
  if(!str_comp("x",name)) {rval=(void*)&(p->x); s=0;}
  if(!str_comp("y",name)) {rval=(void*)&(p->y); s=0;}
  if(!str_comp("z",name)) {rval=(void*)&(p->z); s=0;}
  if(!str_comp("kx",name)){rval=(void*)&(p->kx);s=0;}
  if(!str_comp("ky",name)){rval=(void*)&(p->ky);s=0;}
  if(!str_comp("kz",name)){rval=(void*)&(p->kz);s=0;}
  if(!str_comp("Ex",name)){rval=(void*)&(p->Ex);s=0;}
  if(!str_comp("Ey",name)){rval=(void*)&(p->Ey);s=0;}
  if(!str_comp("Ez",name)){rval=(void*)&(p->Ez);s=0;}
  if(!str_comp("phi",name)){rval=(void*)&(p->phi);s=0;}
  if(!str_comp("t",name)) {rval=(void*)&(p->t); s=0;}
  if(!str_comp("p",name)) {rval=(void*)&(p->p); s=0;}
  if (suc!=0x0) {*suc=s;}
  return rval;
}

#pragma acc routine
int particle_setvar_void(_class_particle *, char *, void*);

int particle_setvar_void(_class_particle *p, char *name, void* value){
#ifndef OPENACC
#define str_comp strcmp
#endif
  int rval=1;
  if(!str_comp("x",name)) {memcpy(&(p->x),  value, sizeof(double)); rval=0;}
  if(!str_comp("y",name)) {memcpy(&(p->y),  value, sizeof(double)); rval=0;}
  if(!str_comp("z",name)) {memcpy(&(p->z),  value, sizeof(double)); rval=0;}
  if(!str_comp("kx",name)){memcpy(&(p->kx), value, sizeof(double)); rval=0;}
  if(!str_comp("ky",name)){memcpy(&(p->ky), value, sizeof(double)); rval=0;}
  if(!str_comp("kz",name)){memcpy(&(p->kz), value, sizeof(double)); rval=0;}
  if(!str_comp("Ex",name)){memcpy(&(p->Ex), value, sizeof(double)); rval=0;}
  if(!str_comp("Ey",name)){memcpy(&(p->Ey), value, sizeof(double)); rval=0;}
  if(!str_comp("Ez",name)){memcpy(&(p->Ez), value, sizeof(double)); rval=0;}
  if(!str_comp("phi",name)){memcpy(&(p->phi), value, sizeof(double)); rval=0;}
  if(!str_comp("p",name)) {memcpy(&(p->p),  value, sizeof(double)); rval=0;}
  if(!str_comp("t",name)) {memcpy(&(p->t),  value, sizeof(double)); rval=0;}
  return rval;
}

#pragma acc routine
int particle_setvar_void_array(_class_particle *, char *, void*, int);

int particle_setvar_void_array(_class_particle *p, char *name, void* value, int elements){
#ifndef OPENACC
#define str_comp strcmp
#endif
  int rval=1;
  return rval;
}

#pragma acc routine
void particle_restore(_class_particle *p, _class_particle *p0);

void particle_restore(_class_particle *p, _class_particle *p0) {
  p->x  = p0->x;  p->y  = p0->y;  p->z  = p0->z;
  p->kx = p0->kx; p->ky = p0->ky; p->kz = p0->kz;
  p->Ex = p0->Ex; p->Ey = p0->Ey; p->Ez = p0->Ez;
  p->t = p0->t;   p->p  = p0->p;  p->phi  = p0->phi;
  p->_absorbed=0; p->_restore=0;
}

#pragma acc routine
double particle_getuservar_byid(_class_particle *p, int id, int *suc){
  int s=1;
  double rval=0;
  switch(id){
  }
  if (suc!=0x0) {*suc=s;}
  return rval;
}

#pragma acc routine
void particle_uservar_init(_class_particle *p){
}

#define MC_EMBEDDED_RUNTIME
/* embedding file "mccode-r.h" */

/*******************************************************************************
*
* McCode, neutron/xray ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mccode-r.h
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McXtrace 3.4-20240304
* Version: $Revision$
*
* Runtime system header for McStas/McXtrace.
*
* In order to use this library as an external library, the following variables
* and macros must be declared (see details in the code)
*
*   struct mcinputtable_struct mcinputtable[];
*   int numipar;
*   metadata_table_t metadata_table[];
*   int num_metadata;
*   char instrument_name[], instrument_source[];
*   int traceenabled, defaultmain;
*   extern MCNUM  mccomp_storein[];
*   extern MCNUM  mcAbsorbProp[];
*   extern MCNUM  mcScattered;
*   #define MCCODE_STRING "the McStas/McXtrace version"
*
* Usage: Automatically embbeded in the c code.
*
* $Id$
*
*******************************************************************************/

#ifndef MCCODE_R_H
#define MCCODE_R_H "$Revision$"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#ifndef _MSC_EXTENSIONS
#include <sys/time.h>
#endif
#include <float.h>
#include <inttypes.h>
#include <stdint.h>
#ifdef OPENACC
#include <openacc.h>
#ifndef GCCOFFLOAD
#include <accelmath.h>
#else
#include <math.h>
#endif
#pragma acc routine
int noprintf();
#pragma acc routine
size_t str_len(const char *s);
#else
#include <math.h>
#endif

#ifdef _MSC_EXTENSIONS
#ifndef _TIMES_H
#define _TIMES_H

#ifdef _WIN32
#include <sys/timeb.h>
#include <sys/types.h>
#include <winsock2.h>

int gettimeofday(struct timeval* t,void* timezone);

#define __need_clock_t
#include <time.h>


/* Structure describing CPU time used by a process and its children.  */
struct tms
  {
    clock_t tms_utime;          /* User CPU time.  */
    clock_t tms_stime;          /* System CPU time.  */

    clock_t tms_cutime;         /* User CPU time of dead children.  */
    clock_t tms_cstime;         /* System CPU time of dead children.  */
  };

/* Store the CPU time used by this process and all its
   dead children (and their dead children) in BUFFER.
   Return the elapsed real time, or (clock_t) -1 for errors.
   All times are in CLK_TCKths of a second.  */
clock_t times (struct tms *__buffer);

typedef long long suseconds_t ;



int gettimeofday(struct timeval* t,void* timezone)
{       struct _timeb timebuffer;
        _ftime( &timebuffer );
        t->tv_sec=timebuffer.time;
        t->tv_usec=1000*timebuffer.millitm;
		return 0;
}

clock_t times (struct tms *__buffer) {

	__buffer->tms_utime = clock();
	__buffer->tms_stime = 0;
	__buffer->tms_cstime = 0;
	__buffer->tms_cutime = 0;
	return __buffer->tms_utime;
}


#endif
#endif
#endif

/* If the runtime is embedded in the simulation program, some definitions can
   be made static. */

#ifdef MC_EMBEDDED_RUNTIME
#  define mcstatic
#else
#  define mcstatic
#endif

#ifdef __dest_os
#  if (__dest_os == __mac_os)
#    define MAC
#  endif
#endif

#ifdef __FreeBSD__
#  define NEED_STAT_H
#endif

#if defined(__APPLE__) && defined(__GNUC__)
#  define NEED_STAT_H
#endif

#ifdef WIN32
#  define NEED_STAT_H
#  define NEED_TYPES_H
#endif

#ifdef NEED_STAT_H
#  include <sys/stat.h>
#endif

#ifdef NEED_TYPES_H
#  include <sys/types.h>
#endif

#ifndef MC_PATHSEP_C
#  ifdef WIN32
#    define MC_PATHSEP_C '\\'
#    define MC_PATHSEP_S "\\"
#  else  /* !WIN32 */
#    define MC_PATHSEP_C '/'
#    define MC_PATHSEP_S "/"
#  endif /* !WIN32 */
#endif /* MC_PATHSEP_C */

#ifdef WIN32
#  define mkdir(a,b) mkdir(a)
#  define getpid() NULL
#endif

/* the version string is replaced when building distribution with mkdist */
#ifndef MCCODE_STRING
#  define MCCODE_STRING "McXtrace 3.4-20240304 - mars. 05, 2024"
#endif

#ifndef MCCODE_DATE
#  define MCCODE_DATE "mars. 05, 2024"
#endif

#ifndef MCCODE_VERSION
#  define MCCODE_VERSION "3.4-20240304"
#endif

#ifndef MCCODE_NAME
#  define MCCODE_NAME "McXtrace"
#endif

#ifndef MCCODE_PARTICLE
#  define MCCODE_PARTICLE "xray"
#endif

#ifndef MCCODE_PARTICLE_CODE
#  define MCCODE_PARTICLE_CODE 22
#endif

#ifndef MCCODE_LIBENV
#  define MCCODE_LIBENV "MCXTRACE"
#endif

#ifndef FLAVOR_UPPER
#  define FLAVOR_UPPER MCCODE_NAME
#endif

#ifdef MC_PORTABLE
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#ifdef MAC
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#if (USE_MPI == 0)
#  undef USE_MPI
#endif

#ifdef USE_MPI  /* default is to disable signals with MPI, as MPICH uses them to communicate */
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#ifdef OPENACC  /* default is to disable signals with PGI/OpenACC */
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#ifndef OPENACC
#  ifndef USE_OFF  /* default is to enable OFF when not using PGI/OpenACC */
#    define USE_OFF
#  endif
#  ifndef CPUFUNNEL  /* allow to enable FUNNEL-mode on CPU */
#  ifdef FUNNEL      /* by default disable FUNNEL-mode when not using PGI/OpenACC */
#    undef FUNNEL
#  endif
#  endif
#endif

#if (NOSIGNALS == 0)
#  undef NOSIGNALS
#endif

/** Header information for metadata-r.c ----------------------------------------------------------------------------- */
struct metadata_table_struct { /* stores metadata strings from components */
  char * source;  // component name which provided the metadata
  char * name;    // the name of the metadata
  char * type;    // the MIME type of the metadata (free form, valid identifier)
  char * value;   // the metadata string contents
};
typedef struct metadata_table_struct metadata_table_t;
char * metadata_table_key_component(char* key);
char * metadata_table_key_literal(char * key);
int metadata_table_defined(int, metadata_table_t *, char *);
char * metadata_table_type(int, metadata_table_t *, char *);
char * metadata_table_literal(int, metadata_table_t *, char *);
void metadata_table_print_all_keys(int no, metadata_table_t * tab);
int metadata_table_print_all_components(int no, metadata_table_t * tab);
int metadata_table_print_component_keys(int no, metadata_table_t * tab, char * key);
/* -------------------------------------------------------------------------- Header information for metadata-r.c --- */

/* Note: the enum instr_formal_types definition MUST be kept
   synchronized with the one in mccode.h and with the
   instr_formal_type_names array in cogen.c. */
enum instr_formal_types
  {
    instr_type_int,
    instr_type_string, instr_type_char,
    instr_type_vector, instr_type_double
  };
struct mcinputtable_struct { /* defines instrument parameters */
  char *name; /* name of parameter */
  void *par;  /* pointer to instrument parameter (variable) */
  enum instr_formal_types type;
  char *val;  /* default value */
  char *unit; /* expected unit for parameter; informational only */
};


#ifndef MCCODE_BASE_TYPES
typedef double MCNUM;
typedef struct {MCNUM x, y, z;} Coords;
typedef MCNUM Rotation[3][3];
#endif

/* the following variables are defined in the McStas generated C code
   but should be defined externally in case of independent library usage */
#ifndef DANSE
extern struct mcinputtable_struct mcinputtable[];         /* list of instrument parameters */
extern int    numipar;                                    /* number of instrument parameters */
extern metadata_table_t metadata_table[];                 /* list of component-defined string metadata */
extern int    num_metadata;                               /* number of component-defined string metadata */
extern char   instrument_name[], instrument_source[]; /* instrument name and filename */
extern char  *instrument_exe;                           /* executable path = argv[0] or NULL */
extern char   instrument_code[];                        /* contains the initial 'instr' file */

#ifndef MC_ANCIENT_COMPATIBILITY
extern int traceenabled, defaultmain;
#endif
#endif


/* Useful macros ============================================================ */


/* SECTION: Dynamic Arrays */
typedef int* IArray1d;
IArray1d create_iarr1d(int n);
void destroy_iarr1d(IArray1d a);

typedef int** IArray2d;
IArray2d create_iarr2d(int nx, int ny);
void destroy_iarr2d(IArray2d a);

typedef int*** IArray3d;
IArray3d create_iarr3d(int nx, int ny, int nz);
void destroy_iarr3d(IArray3d a);

typedef double* DArray1d;
DArray1d create_darr1d(int n);
void destroy_darr1d(DArray1d a);

typedef double** DArray2d;
DArray2d create_darr2d(int nx, int ny);
void destroy_darr2d(DArray2d a);

typedef double*** DArray3d;
DArray3d create_darr3d(int nx, int ny, int nz);
void destroy_darr3d(DArray3d a);


/* MPI stuff */
#ifdef USE_MPI
#include "mpi.h"

#ifdef OMPI_MPI_H  /* openmpi does not use signals: we may install our sighandler */
#ifndef OPENACC    /* ... but only if we are not also running on GPU */
#undef NOSIGNALS
#endif
#endif

/*
 * MPI_MASTER(i):
 * execution of i only on master node
 */
#define MPI_MASTER(statement) { \
  if(mpi_node_rank == mpi_node_root)\
  { statement; } \
}

#ifndef MPI_REDUCE_BLOCKSIZE
#define MPI_REDUCE_BLOCKSIZE 1000
#endif

int mc_MPI_Sum(double* buf, long count);
int mc_MPI_Send(void *sbuf, long count, MPI_Datatype dtype, int dest);
int mc_MPI_Recv(void *rbuf, long count, MPI_Datatype dtype, int source);

/* MPI_Finalize exits gracefully and should be preferred to MPI_Abort */
#define exit(code) do {                                   \
    MPI_Finalize();                                       \
    exit(code);                                           \
  } while(0)

#else /* !USE_MPI */
#define MPI_MASTER(instr) instr
#endif /* USE_MPI */


#ifdef USE_MPI
static int mpi_node_count;
#endif

#ifdef USE_THREADS  /* user want threads */
#error Threading (USE_THREADS) support has been removed for very poor efficiency. Use MPI/SSH grid instead.
#endif


void   mcset_ncount(unsigned long long count);    /* wrapper to get mcncount */
#pragma acc routine
unsigned long long int mcget_ncount(void);            /* wrapper to set mcncount */
unsigned long long mcget_run_num(void);           /* wrapper to get mcrun_num=0:mcncount-1 */

/* Following part is only embedded when not redundant with mccode.h ========= */

#ifndef MCCODE_H

#ifndef NOSIGNALS
#include <signal.h>
char  *mcsig_message;
#define SIG_MESSAGE(msg) mcsig_message=(char *)(msg);
#else
#define SIG_MESSAGE(...)
#endif /* !NOSIGNALS */


/* Useful macros and constants ============================================== */


#ifndef FLT_MAX
#define FLT_MAX         3.40282347E+38F /* max decimal value of a "float" */
#endif

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif
#ifndef SQR
#define SQR(x) ( (x) * (x) )
#endif
#ifndef SIGN
#define SIGN(x) (((x)>0.0)?(1):(-1))
#endif


#  ifndef M_E
#    define M_E        2.71828182845904523536  // e
#  endif
#  ifndef M_LOG2E
#    define M_LOG2E    1.44269504088896340736  //  log2(e)
#  endif
#  ifndef M_LOG10E
#    define M_LOG10E   0.434294481903251827651 //  log10(e)
#  endif
#  ifndef M_LN2
#    define M_LN2      0.693147180559945309417 //  ln(2)
#  endif
#  ifndef M_LN10
#    define M_LN10     2.30258509299404568402  //  ln(10)
#  endif
#  ifndef M_PI
#    define M_PI       3.14159265358979323846  //  pi
#  endif
#  ifndef PI
#    define PI       M_PI                      //  pi - also used in some places
#  endif
#  ifndef M_PI_2
#    define M_PI_2     1.57079632679489661923  //  pi/2
#  endif
#  ifndef M_PI_4
#    define M_PI_4     0.785398163397448309616 //  pi/4
#  endif
#  ifndef M_1_PI
#    define M_1_PI     0.318309886183790671538 //  1/pi
#  endif
#  ifndef M_2_PI
#    define M_2_PI     0.636619772367581343076 //  2/pi
#  endif
#  ifndef M_2_SQRTPI
#    define M_2_SQRTPI 1.12837916709551257390  //  2/sqrt(pi)
#  endif
#  ifndef M_SQRT2
#    define M_SQRT2    1.41421356237309504880  //  sqrt(2)
#  endif
#  ifndef M_SQRT1_2
#    define M_SQRT1_2  0.707106781186547524401 //  1/sqrt(2)
#  endif

#define RAD2MIN  ((180*60)/PI)
#define MIN2RAD  (PI/(180*60))
#define DEG2RAD  (PI/180)
#define RAD2DEG  (180/PI)
#define FWHM2RMS 0.424660900144    /* Convert between full-width-half-max and */
#define RMS2FWHM 2.35482004503     /* root-mean-square (standard deviation) */
#define HBAR     1.05457168e-34    /* [Js] h bar Planck constant CODATA 2002 */
#define MNEUTRON 1.67492728e-27    /* [kg] mass of neutron CODATA 2002 */
#define GRAVITY  9.81              /* [m/s^2] gravitational acceleration */
#define NA       6.02214179e23     /* [#atoms/g .mole] Avogadro's number*/


#define UNSET nan("0x6E6F74736574")
int nans_match(double, double);
int is_unset(double);
int is_valid(double);
int is_set(double);
int all_unset(int n, ...);
int all_set(int n, ...);
int any_unset(int n, ...);
int any_set(int n, ...);


/* wrapper to get absolute and relative position of comp */
/* mccomp_posa and mccomp_posr are defined in McStas generated C code */
#define POS_A_COMP_INDEX(index) (instrument->_position_absolute[index])
#define POS_R_COMP_INDEX(index) (instrument->_position_relative[index])

/* setting parameters based COMP_GETPAR (returned as pointer)         */
/* compname must be given as a string, type and par are symbols.      */
#define COMP_GETPAR3(type, compname, par) \
    &( ((_class_ ## type ##_parameters *) _getvar_parameters(compname))->par )
/* the body of this function depends on component instances, and is cogen'd */
void* _getvar_parameters(char* compname);

int _getcomp_index(char* compname);

/* Note: The two-stage approach to COMP_GETPAR is NOT redundant; without it,
* after #define C sample, COMP_GETPAR(C,x) would refer to component C, not to
* component sample. Such are the joys of ANSI C.

* Anyway the usage of COMP_GETPAR requires that we use sometimes bare names...
* NOTE: This can ONLY be used in instrument descriptions, not components.
*/
#define COMP_GETPAR2(comp, par) (_ ## comp ## _var._parameters.par)
#define COMP_GETPAR(comp, par) COMP_GETPAR2(comp,par)

#define INSTRUMENT_GETPAR(par) (_instrument_var._parameters.par)

/* Current component name, index, position and orientation */
/* These macros work because, using class-based functions, "comp" is usually
*  the local variable of the active/current component. */
#define INDEX_CURRENT_COMP (_comp->_index)
#define NAME_CURRENT_COMP (_comp->_name)
#define TYPE_CURRENT_COMP (_comp->_type)
#define POS_A_CURRENT_COMP (_comp->_position_absolute)
#define POS_R_CURRENT_COMP (_comp->_position_relative)
#define ROT_A_CURRENT_COMP (_comp->_rotation_absolute)
#define ROT_R_CURRENT_COMP (_comp->_rotation_relative)

#define NAME_INSTRUMENT (instrument->_name)


/* MCDISPLAY/trace and debugging message sent to stdout */
#ifdef MC_TRACE_ENABLED
#define DEBUG
#endif

#ifdef DEBUG
#define DEBUG_INSTR() if(!mcdotrace); else { printf("INSTRUMENT:\n"); printf("Instrument '%s' (%s)\n", instrument_name, instrument_source); }
#define DEBUG_COMPONENT(name,c,t) if(!mcdotrace); else {\
  printf("COMPONENT: \"%s\"\n" \
         "POS: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
         name, c.x, c.y, c.z, t[0][0], t[0][1], t[0][2], \
         t[1][0], t[1][1], t[1][2], t[2][0], t[2][1], t[2][2]); \
  printf("Component %30s AT (%g,%g,%g)\n", name, c.x, c.y, c.z); \
  }
#define DEBUG_INSTR_END() if(!mcdotrace); else printf("INSTRUMENT END:\n");
#define DEBUG_ENTER() if(!mcdotrace); else printf("ENTER:\n");
#define DEBUG_COMP(c) if(!mcdotrace); else printf("COMP: \"%s\"\n", c);
#define DEBUG_LEAVE() if(!mcdotrace); else printf("LEAVE:\n");
#define DEBUG_ABSORB() if(!mcdotrace); else printf("ABSORB:\n");
#else
#define DEBUG_INSTR()
#define DEBUG_COMPONENT(name,c,t)
#define DEBUG_INSTR_END()
#define DEBUG_ENTER()
#define DEBUG_COMP(c)
#define DEBUG_LEAVE()
#define DEBUG_ABSORB()
#endif

// mcDEBUG_STATE and mcDEBUG_SCATTER are defined by mcstas-r.h and mcxtrace-r.h



#ifdef TEST
#define test_printf printf
#else
#define test_printf while(0) printf
#endif

/* send MCDISPLAY message to stdout to show gemoetry */
void mcdis_magnify(char *what);
void mcdis_line(double x1, double y1, double z1,
                double x2, double y2, double z2);
void mcdis_dashed_line(double x1, double y1, double z1,
		       double x2, double y2, double z2, int n);
void mcdis_multiline(int count, ...);
void mcdis_rectangle(char* plane, double x, double y, double z,
		     double width, double height);
void mcdis_box(double x, double y, double z,
	       double width, double height, double length);
void mcdis_circle(char *plane, double x, double y, double z, double r);
void mcdis_Circle(double x, double y, double z, double r, double nx, double ny, double nz);
void mcdis_cylinder( double x, double y, double z,
        double r, double height, int N, double nx, double ny, double nz);
void mcdis_sphere(double x, double y, double z, double r, int N);


/* random number generation. ================================================ */

/* available random number generators */
#define _RNG_ALG_MT         1
#define _RNG_ALG_KISS       2

/* selection of random number generator */
#ifndef RNG_ALG
#  define RNG_ALG  _RNG_ALG_KISS
#endif


#if RNG_ALG == _RNG_ALG_MT  // MT (currently not functional for gpu)
#  define MC_RAND_MAX ((unsigned long)0xffffffff)
#  define randstate_t unsigned long // this could be anything
#  define RANDSTATE_LEN 1
#  define srandom(seed) mt_srandom_empty()
#  define random() mt_random()
#  define _random() mt_random()
#elif RNG_ALG == _RNG_ALG_KISS  // KISS
#  ifndef ULONG_MAX
#    define ULONG_MAX ((unsigned long)0xffffffffffffffffUL)
#  endif
#  define MC_RAND_MAX ULONG_MAX
#  define randstate_t unsigned long
#  define RANDSTATE_LEN 7
#  define srandom(seed) kiss_srandom(_particle->randstate, seed)
#  define random() kiss_random(_particle->randstate)
#  define _random() kiss_random(state)
#endif

#pragma acc routine
double _randnorm2(randstate_t* state);


// component writers interface
#define randnorm() _randnorm2(_particle->randstate) // NOTE: can not use _randnorm on gpu
#define rand01() _rand01(_particle->randstate)
#define randpm1() _randpm1(_particle->randstate)
#define rand0max(p1) _rand0max(p1, _particle->randstate)
#define randminmax(p1, p2) _randminmax(p1, p2, _particle->randstate)
#define randtriangle() _randtriangle(_particle->randstate)

// Mersenne Twister rng
unsigned long mt_random(void);
void mt_srandom (unsigned long x);
void mt_srandom_empty();

// KISS rng
#pragma acc routine
unsigned long *kiss_srandom(unsigned long state[7], unsigned long seed);
#pragma acc routine
unsigned long kiss_random(unsigned long state[7]);

// Scrambler / hash function
#pragma acc routine seq
randstate_t _hash(randstate_t x);

// internal RNG (transforms) interface
#pragma acc routine
double _rand01(randstate_t* state);
#pragma acc routine
double _randpm1(randstate_t* state);
#pragma acc routine
double _rand0max(double max, randstate_t* state);
#pragma acc routine
double _randminmax(double min, double max, randstate_t* state);
#pragma acc routine
double _randtriangle(randstate_t* state);


#ifdef USE_OPENCL
#include "opencl-lib.h"
#include "opencl-lib.c"
#endif

#ifndef DANSE
int init(void);
int raytrace(_class_particle*);
int save(FILE *);
int finally(void);
int display(void);
#endif


/* GPU related algorithms =================================================== */

/*
*  Divide-and-conquer strategy for parallel sort absorbed last.
*/
#ifdef FUNNEL
long sort_absorb_last(_class_particle* particles, _class_particle* pbuffer, long len, long buffer_len, long flag_split, long* multiplier);
#endif
long sort_absorb_last_serial(_class_particle* particles, long len);


/* simple vector algebra ==================================================== */


#define vec_prod(x, y, z, x1, y1, z1, x2, y2, z2) \
	vec_prod_func(&x, &y, &z, x1, y1, z1, x2, y2, z2)
#pragma acc routine seq
mcstatic void vec_prod_func(double *x, double *y, double *z,
		double x1, double y1, double z1, double x2, double y2, double z2);

#pragma acc routine seq
mcstatic double scalar_prod(
		double x1, double y1, double z1, double x2, double y2, double z2);

#pragma acc routine seq
mcstatic void norm_func(double *x, double *y, double *z);
#define NORM(x,y,z)	norm_func(&x, &y, &z)

#pragma acc routine seq
void normal_vec(double *nx, double *ny, double *nz,
    double x, double y, double z);

/**
 * Rotate the vector vx,vy,vz psi radians around the vector ax,ay,az
 * and put the result in x,y,z.
 */
#define rotate(x, y, z, vx, vy, vz, phi, ax, ay, az) \
  do { \
    double mcrt_tmpx = (ax), mcrt_tmpy = (ay), mcrt_tmpz = (az); \
    double mcrt_vp, mcrt_vpx, mcrt_vpy, mcrt_vpz; \
    double mcrt_vnx, mcrt_vny, mcrt_vnz, mcrt_vn1x, mcrt_vn1y, mcrt_vn1z; \
    double mcrt_bx, mcrt_by, mcrt_bz; \
    double mcrt_cos, mcrt_sin; \
    NORM(mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_vp = scalar_prod((vx), (vy), (vz), mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_vpx = mcrt_vp*mcrt_tmpx; \
    mcrt_vpy = mcrt_vp*mcrt_tmpy; \
    mcrt_vpz = mcrt_vp*mcrt_tmpz; \
    mcrt_vnx = (vx) - mcrt_vpx; \
    mcrt_vny = (vy) - mcrt_vpy; \
    mcrt_vnz = (vz) - mcrt_vpz; \
    vec_prod(mcrt_bx, mcrt_by, mcrt_bz, \
             mcrt_tmpx, mcrt_tmpy, mcrt_tmpz, mcrt_vnx, mcrt_vny, mcrt_vnz); \
    mcrt_cos = cos((phi)); mcrt_sin = sin((phi)); \
    mcrt_vn1x = mcrt_vnx*mcrt_cos + mcrt_bx*mcrt_sin; \
    mcrt_vn1y = mcrt_vny*mcrt_cos + mcrt_by*mcrt_sin; \
    mcrt_vn1z = mcrt_vnz*mcrt_cos + mcrt_bz*mcrt_sin; \
    (x) = mcrt_vpx + mcrt_vn1x; \
    (y) = mcrt_vpy + mcrt_vn1y; \
    (z) = mcrt_vpz + mcrt_vn1z; \
  } while(0)

/**
 * Mirror (xyz) in the plane given by the point (rx,ry,rz) and normal (nx,ny,nz)
 *
 * TODO: This define is seemingly never used...
 */
#define mirror(x,y,z,rx,ry,rz,nx,ny,nz) \
  do { \
    double mcrt_tmpx= (nx), mcrt_tmpy = (ny), mcrt_tmpz = (nz); \
    double mcrt_tmpt; \
    NORM(mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_tmpt=scalar_prod((rx),(ry),(rz),mcrt_tmpx,mcrt_tmpy,mcrt_tmpz); \
    (x) = rx -2 * mcrt_tmpt*mcrt_rmpx; \
    (y) = ry -2 * mcrt_tmpt*mcrt_rmpy; \
    (z) = rz -2 * mcrt_tmpt*mcrt_rmpz; \
  } while (0)

#pragma acc routine
Coords coords_set(MCNUM x, MCNUM y, MCNUM z);
#pragma acc routine
Coords coords_get(Coords a, MCNUM *x, MCNUM *y, MCNUM *z);
#pragma acc routine
Coords coords_add(Coords a, Coords b);
#pragma acc routine
Coords coords_sub(Coords a, Coords b);
#pragma acc routine
Coords coords_neg(Coords a);
#pragma acc routine
Coords coords_scale(Coords b, double scale);
#pragma acc routine
double coords_sp(Coords a, Coords b);
#pragma acc routine
Coords coords_xp(Coords b, Coords c);
#pragma acc routine
double coords_len(Coords a);
#pragma acc routine seq
void   coords_print(Coords a);
#pragma acc routine seq
mcstatic void coords_norm(Coords* c);

#pragma acc routine seq
void rot_set_rotation(Rotation t, double phx, double phy, double phz);
#pragma acc routine seq
int  rot_test_identity(Rotation t);
#pragma acc routine seq
void rot_mul(Rotation t1, Rotation t2, Rotation t3);
#pragma acc routine seq
void rot_copy(Rotation dest, Rotation src);
#pragma acc routine seq
void rot_transpose(Rotation src, Rotation dst);
#pragma acc routine seq
Coords rot_apply(Rotation t, Coords a);

#pragma acc routine seq
void mccoordschange(Coords a, Rotation t, _class_particle *particle);
#pragma acc routine seq
void mccoordschange_polarisation(Rotation t, double *sx, double *sy, double *sz);

double mcestimate_error(double N, double p1, double p2);
void mcreadparams(void);

/* this is now in mcstas-r.h and mcxtrace-r.h as the number of state parameters
is no longer equal */

_class_particle mcgenstate(void);

// trajectory/shape intersection routines
#pragma acc routine seq
int inside_rectangle(double, double, double, double);
#pragma acc routine seq
int box_intersect(double *dt_in, double *dt_out, double x, double y, double z,
      double vx, double vy, double vz, double dx, double dy, double dz);
#pragma acc routine seq
int cylinder_intersect(double *t0, double *t1, double x, double y, double z,
      double vx, double vy, double vz, double r, double h);
#pragma acc routine seq
int sphere_intersect(double *t0, double *t1, double x, double y, double z,
      double vx, double vy, double vz, double r);
// second order equation roots
#pragma acc routine seq
int solve_2nd_order(double *t1, double *t2,
      double A,  double B,  double C);

// random vector generation to shape
// defines silently introducing _particle as the last argument
#define randvec_target_circle(xo, yo, zo, solid_angle, xi, yi, zi, radius) \
  _randvec_target_circle(xo, yo, zo, solid_angle, xi, yi, zi, radius, _particle)
#define randvec_target_rect_angular(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A) \
  _randvec_target_rect_angular(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A, _particle)
#define randvec_target_rect_real(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A, lx, ly, lz, order) \
  _randvec_target_rect_real(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A, lx, ly, lz, order, _particle)
// defines forwarding to "inner" functions
#define randvec_target_sphere randvec_target_circle
#define randvec_target_rect(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9) \
  randvec_target_rect_real(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,0,0,0,1)
// headers for randvec
#pragma acc routine seq
void _randvec_target_circle(double *xo, double *yo, double *zo,
  double *solid_angle, double xi, double yi, double zi, double radius,
  _class_particle* _particle);
#pragma acc routine seq
void _randvec_target_rect_angular(double *xo, double *yo, double *zo,
  double *solid_angle, double xi, double yi, double zi, double height,
  double width, Rotation A,
  _class_particle* _particle);
#pragma acc routine seq
void _randvec_target_rect_real(double *xo, double *yo, double *zo, double *solid_angle,
  double xi, double yi, double zi, double height, double width, Rotation A,
  double lx, double ly, double lz, int order,
  _class_particle* _particle);


// this is the main()
int mccode_main(int argc, char *argv[]);


#endif /* !MCCODE_H */

#ifndef MCCODE_R_IO_H
#define MCCODE_R_IO_H "$Revision$"

#if (USE_NEXUS == 0)
#undef USE_NEXUS
#endif

#ifndef CHAR_BUF_LENGTH
#define CHAR_BUF_LENGTH 1024
#endif


/* I/O section part ========================================================= */

/* ========================================================================== */

/*                               MCCODE_R_IO_C                                */

/* ========================================================================== */


/* main DETECTOR structure which stores most information to write to data files */
struct mcdetector_struct {
  char   filename[CHAR_BUF_LENGTH];   /* file name of monitor */
  char   position[CHAR_BUF_LENGTH];   /* position of detector component */
  char   component[CHAR_BUF_LENGTH];  /* component instance name */
  char   instrument[CHAR_BUF_LENGTH]; /* instrument name */
  char   type[CHAR_BUF_LENGTH];       /* data type, e.g. 0d, 1d, 2d, 3d */
  char   user[CHAR_BUF_LENGTH];       /* user name, e.g. HOME */
  char   date[CHAR_BUF_LENGTH];       /* date of simulation end/write time */
  char   title[CHAR_BUF_LENGTH];      /* title of detector */
  char   xlabel[CHAR_BUF_LENGTH];     /* X axis label */
  char   ylabel[CHAR_BUF_LENGTH];     /* Y axis label */
  char   zlabel[CHAR_BUF_LENGTH];     /* Z axis label */
  char   xvar[CHAR_BUF_LENGTH];       /* X variable name */
  char   yvar[CHAR_BUF_LENGTH];       /* Y variable name */
  char   zvar[CHAR_BUF_LENGTH];       /* Z variable name */
  char   ncount[CHAR_BUF_LENGTH];     /* number of events initially generated */
  char   limits[CHAR_BUF_LENGTH];     /* X Y Z limits, e.g. [xmin xmax ymin ymax zmin zmax] */
  char   variables[CHAR_BUF_LENGTH];  /* variables written into data block */
  char   statistics[CHAR_BUF_LENGTH]; /* center, mean and half width along axis */
  char   signal[CHAR_BUF_LENGTH];     /* min max and mean of signal (data block) */
  char   values[CHAR_BUF_LENGTH];     /* integrated values e.g. [I I_err N] */
  double xmin,xmax;                   /* min max of axes */
  double ymin,ymax;
  double zmin,zmax;
  double intensity;                   /* integrated values for data block */
  double error;
  double events;
  double min;                         /* statistics for data block */
  double max;
  double mean;
  double centerX;                     /* statistics for axes */
  double halfwidthX;
  double centerY;
  double halfwidthY;
  int    rank;                        /* dimensionaly of monitor, e.g. 0 1 2 3 */
  char   istransposed;                /* flag to transpose matrix for some formats */

  long   m,n,p;                       /* dimensions of data block and along axes */
  long   date_l;                      /* same as date, but in sec since 1970 */

  double *p0, *p1, *p2;               /* pointers to saved data, NULL when freed */
  char   format[CHAR_BUF_LENGTH];    /* format for file generation */
};

typedef struct mcdetector_struct MCDETECTOR;

static   char *dirname             = NULL;      /* name of output directory */
static   char *siminfo_name        = "mccode";  /* default output sim file name */
char    *mcformat                    = NULL;      /* NULL (default) or a specific format */

/* file I/O definitions and function prototypes */

#ifndef MC_EMBEDDED_RUNTIME /* the mcstatic variables (from mccode-r.c) */
extern FILE * siminfo_file;     /* handle to the output siminfo file */
extern int    mcgravitation;      /* flag to enable gravitation */
extern int    mcdotrace;          /* flag to print MCDISPLAY messages */
#else
mcstatic FILE *siminfo_file        = NULL;
#endif

/* I/O function prototypes ================================================== */

// from msysgit: https://code.google.com/p/msysgit/source/browse/compat/strcasestr.c
char *strcasestr(const char *haystack, const char *needle);

/* output functions */
MCDETECTOR mcdetector_out_0D(char *t, double p0, double p1, double p2, char *c, Coords pos);
MCDETECTOR mcdetector_out_1D(char *t, char *xl, char *yl,
                  char *xvar, double x1, double x2, long n,
                  double *p0, double *p1, double *p2, char *f, char *c, Coords pos);
MCDETECTOR mcdetector_out_2D(char *t, char *xl, char *yl,
                  double x1, double x2, double y1, double y2, long m,
                  long n, double *p0, double *p1, double *p2, char *f,
                  char *c, Coords pos);
MCDETECTOR mcdetector_out_list(char *t, char *xl, char *yl,
                  long m, long n,
                  double *p1, char *f,
                  char *c, Coords posa);

/* wrappers to output functions, that automatically set NAME and POSITION */
#define DETECTOR_OUT(p0,p1,p2) mcdetector_out_0D(NAME_CURRENT_COMP,p0,p1,p2,NAME_CURRENT_COMP,POS_A_CURRENT_COMP)
#define DETECTOR_OUT_0D(t,p0,p1,p2) mcdetector_out_0D(t,p0,p1,p2,NAME_CURRENT_COMP,POS_A_CURRENT_COMP)
#define DETECTOR_OUT_1D(t,xl,yl,xvar,x1,x2,n,p0,p1,p2,f) \
     mcdetector_out_1D(t,xl,yl,xvar,x1,x2,n,p0,p1,p2,f,NAME_CURRENT_COMP,POS_A_CURRENT_COMP)
#define DETECTOR_OUT_2D(t,xl,yl,x1,x2,y1,y2,m,n,p0,p1,p2,f) \
     mcdetector_out_2D(t,xl,yl,x1,x2,y1,y2,m,n,p0,p1,p2,f,NAME_CURRENT_COMP,POS_A_CURRENT_COMP)

#ifdef USE_NEXUS
#include "napi.h"
NXhandle nxhandle;
#endif

#endif /* ndef MCCODE_R_IO_H */

#endif /* MCCODE_R_H */
/* End of file "mccode-r.h". */

/* embedding file "mcxtrace-r.h" */

/*******************************************************************************
*
* McXtrace, X-ray ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Synchrotron SOLEIL, Saint-Aubin, France
*
* Runtime: share/mcxtrace-r.h
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McXtrace X.Y
* Version: $Revision$
*
* Runtime system header for McXtrace.
*
* In order to use this library as an external library, the following variables
* and macros must be declared (see details in the code)
*
*   struct mcinputtable_struct mcinputtable[];
*   int mcnumipar;
*   char instrument_name[], instrument_source[];
*   int traceenabled, defaultmain;
*   extern MCNUM  mccomp_storein[];
*   extern MCNUM  instrument.counter_AbsorbProp[];
*   extern MCNUM  mcScattered;
*   #define MCCODE_STRING "the McXtrace version"
*
* Usage: Automatically embbeded in the c code.
*
*******************************************************************************/

#ifndef MCXTRACE_R_H
#define MCXTRACE_R_H "$Revision$"

/* Following part is only embedded when not redundant with mcxtrace.h */

#ifndef MCCODE_H

#define CELE     1.602176487e-19   /* [C] Elementary charge CODATA 2006*/
#define MELECTRON 9.10938291e-31    /* [kg] Electron mass CODATA 2006*/
#define M_C      299792458         /* [m/s] speed of light CODATA 2006*/
#define E2K      0.506773091264796 /* Convert k[1/AA] to E [keV] (CELE/(HBAR*M_C)*1e-10)*1e3 */
#define K2E      1.97326972808327  /*Convert E[keV] to k[1/AA] (1e10*M_C*HBAR/CELE)/1e3 */
#define RE       2.8179402894e-5   /*[AA] Thomson scattering length*/
#define ALPHA    7.2973525698e-3   /*[ ] Fine structure constant CODATA 2006*/

#define SCATTER0 do {DEBUG_SCATTER(); SCATTERED++;} while(0)
#define SCATTER SCATTER0

#define JUMPTOCOMP(comp) mcphoton->_index = INDEX_COMP(comp);

/*magnet stuff is probably redundant*/
#define MAGNET_ON \
  do { \
  } while(0)

#define MAGNET_OFF \
  do { \
  } while(0)

#define ALLOW_BACKPROP \
  do { \
    mcallowbackprop = 1; \
  } while(0)

#define DISALLOW_BACKPROP \
  do { \
    mcallowbackprop = 0; \
  } while(0)

#define PROP_MAGNET(dt) \
  do { \
    /* change coordinates from local system to magnet system */ \
    Rotation rotLM, rotTemp; \
    Coords   posLM = coords_sub(POS_A_CURRENT_COMP, mcMagnetPos); \
    rot_transpose(ROT_A_CURRENT_COMP, rotTemp); \
    rot_mul(rotTemp, mcMagnetRot, rotLM); \
    mcMagnetPrecession(mcnlx, mcnly, mcnlz, mcnlt, mcnlvx, mcnlvy, mcnlvz, \
	   	       &mcnlsx, &mcnlsy, &mcnlsz, dt, posLM, rotLM); \
  } while(0)

#define mcPROP_DT(dt) \
  do { \
    if (mcMagnet && dt > 0) PROP_MAGNET(dt);\
    x += kx*(dt); \
    y += ky*(dt); \
    z += kz*(dt); \
    t += (dt); \
    if (isnan(p) || isinf(p)) { instrument->counter_AbsorbProp[INDEX_CURRENT_COMP]++; ABSORB; }\
  } while(0)

/*An interrupt a'la mcMagnet should be inserted below if there's non-zero permeability*/
/*perhaps some kind of PROP_POL*/

#define mcPROP_DL(dl) \
  do { \
    MCNUM mc_k=sqrt( scalar_prod(kx,ky,kz,kx,ky,kz));\
    x = x+ (dl)*kx/mc_k;\
    y = y+ (dl)*ky/mc_k;\
    z = z+ (dl)*kz/mc_k;\
    phi = phi+ 1e10*mc_k*(dl);\
    t = t + (dl)/((double)M_C);\
  }while (0)
/* this had to be taken out to avoid error 700. This may need to be atomic, but probably should be somewhere else.*/
/*    if (isnan(p) || isinf(p)) { instrument->counter_AbsorbProp[INDEX_CURRENT_COMP] =  instrument->counter_AbsorbProp[INDEX_CURRENT_COMP] + 1; ABSORB; }\
*/

/*gravity not an issue with x-rays*/
/* ADD: E. Farhi, Aug 6th, 2001 PROP_GRAV_DT propagation with acceleration. */
#define PROP_GRAV_DT(dt, Ax, Ay, Az) \
  do { \
    if(dt < 0 && mcallowbackprop == 0) { instrument->counter_AbsorbProp[INDEX_CURRENT_COMP]++; ABSORB; }\
    if (mcMagnet) /*printf("Spin precession gravity\n")*/; \
    x  += vx*(dt) + (Ax)*(dt)*(dt)/2; \
    y  += vy*(dt) + (Ay)*(dt)*(dt)/2; \
    z  += vz*(dt) + (Az)*(dt)*(dt)/2; \
    vx += (Ax)*(dt); \
    vy += (Ay)*(dt); \
    vz += (Az)*(dt); \
    t  += (dt); \
    DISALLOW_BACKPROP;\
  } while(0)

/*adapted from PROP_DT(dt)*/
#define PROP_DL(dl) \
  do{ \
    if(dl < 0) { RESTORE=1; ABSORB; }; \
    mcPROP_DL(dl); \
    DISALLOW_BACKPROP;\
  } while (0)

#define PROP_DT(dt) \
  do { \
    if(dt < 0) { RESTORE=1; ABSORB; }; \
    if (mcgravitation) { Coords mcLocG; double mc_gx, mc_gy, mc_gz; \
    mcLocG = rot_apply(ROT_A_CURRENT_COMP, coords_set(0,-GRAVITY,0)); \
    coords_get(mcLocG, &mc_gx, &mc_gy, &mc_gz); \
    PROP_GRAV_DT(dt, mc_gx, mc_gy, mc_gz); } \
    else mcPROP_DT(dt); \
    DISALLOW_BACKPROP;\
  } while(0)

#define PROP_X0 \
  do { \
    mcPROP_X0; \
    DISALLOW_BACKPROP; \
  }while(0)

#define mcPROP_X0 \
  do { \
    MCNUM mc_dl,mc_k; \
    if(kx == 0) { ABSORB; }; \
    mc_k=sqrt(scalar_prod(kx,ky,kz,kx,ky,kz)); \
    mc_dl= -x * mc_k / kx; \
    if(mc_dl<0 && mcallowbackprop==0) { ABSORB; };\
    PROP_DL(mc_dl); \
  } while(0)

#define PROP_Y0 \
  do { \
    mcPROP_Y0; \
    DISALLOW_BACKPROP; \
  }while(0)

#define mcPROP_Y0 \
  do { \
    MCNUM mc_dl,mc_k; \
    if(ky == 0) { ABSORB; }; \
    mc_k=sqrt(scalar_prod(kx,ky,kz,kx,ky,kz)); \
    mc_dl= -y * mc_k / ky; \
    if(mc_dl<0 && mcallowbackprop==0) { ABSORB; };\
    PROP_DL(mc_dl); \
  } while(0)

#define PROP_Z0 \
  do { \
    mcPROP_Z0; \
    DISALLOW_BACKPROP; \
  }while(0)

#define mcPROP_Z0 \
  do { \
    MCNUM mc_dl,mc_k; \
    if(kz == 0) { ABSORB; }; \
    mc_k=sqrt(scalar_prod(kx,ky,kz,kx,ky,kz)); \
    mc_dl= -z * mc_k / kz; \
    if(mc_dl<0 && mcallowbackprop==0) { ABSORB; };\
    PROP_DL(mc_dl); \
  } while(0)

#ifdef DEBUG

#define DEBUG_STATE() if(!mcdotrace); else \
  printf("STATE: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
      x,y,z,kx,ky,kz,phi,t,Ex,Ey,Ez,p);
#define DEBUG_SCATTER() if(!mcdotrace); else \
  printf("SCATTER: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
      x,y,z,kx,ky,kz,phi,t,Ex,Ey,Ez,p);

#else

#define DEBUG_STATE()
#define DEBUG_SCATTER()

#endif

#endif /* !MCCODE_H */

#endif /* MCXTRACE_R_H */
/* End of file "mcxtrace-r.h". */

/* embedding file "mccode-r.c" */

/*******************************************************************************
*
* McCode, neutron/xray ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mccode-r.c
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McStas X.Y/McXtrace X.Y
* Version: $Revision$
*
* Runtime system for McStas and McXtrace.
* Embedded within instrument in runtime mode.
* Contains SECTIONS:
*   MPI handling (sum, send, recv)
*   format definitions
*   I/O
*   mcdisplay support
*   random numbers
*   coordinates handling
*   vectors math (solve 2nd order, normals, randvec...)
*   parameter handling
*   signal and main handlers
*
* Usage: Automatically embbeded in the c code whenever required.
*
* $Id$
*
*******************************************************************************/

/*******************************************************************************
* The I/O format definitions and functions
*******************************************************************************/


/** Include header files to avoid implicit declarations (not allowed on LLVM) */
#include <ctype.h>
#include <sys/types.h>

// UNIX specific headers (non-Windows)
#if defined(__unix__) || defined(__APPLE__)
#include <unistd.h>
#include <sys/stat.h>
#endif


#ifndef DANSE
#ifdef MC_ANCIENT_COMPATIBILITY
int traceenabled = 0;
int defaultmain  = 0;
#endif
/* else defined directly in the McCode generated C code */

static   long mcseed                 = 0; /* seed for random generator */
#pragma acc declare create ( mcseed )
static   long mcstartdate            = 0; /* start simulation time */
static   int  mcdisable_output_files = 0; /* --no-output-files */
mcstatic int  mcgravitation          = 0; /* use gravitation flag, for PROP macros */
mcstatic int  mcdotrace              = 0; /* flag for --trace and messages for DISPLAY */
#pragma acc declare create ( mcdotrace )
int      mcallowbackprop             = 0;         /* flag to enable negative/backprop */

/* OpenACC-related segmentation parameters: */
int vecsize = 128;
int numgangs = 7813;
long gpu_innerloop = 2147483647;

/* Monitor_nD list/buffer-size default */
long MONND_BUFSIZ = 1000000;

/* Number of particle histories to simulate. */
#ifdef NEUTRONICS
mcstatic unsigned long long int mcncount             = 1;
mcstatic unsigned long long int mcrun_num            = 0;
#else
#ifdef MCDEFAULT_NCOUNT
mcstatic unsigned long long int mcncount             = MCDEFAULT_NCOUNT;
#else
mcstatic unsigned long long int mcncount             = 1000000;
#endif
#pragma acc declare create ( mcncount )
mcstatic unsigned long long int mcrun_num            = 0;
#pragma acc declare create ( mcrun_num )
#endif /* NEUTRONICS */

#else
#include "mcstas-globals.h"
#endif /* !DANSE */

#ifndef NX_COMPRESSION
#define NX_COMPRESSION NX_COMP_NONE
#endif

/* String nullification on GPU and other replacements */
#ifdef OPENACC
int noprintf() {
  return 0;
}

int str_comp(char *str1, char *str2) {
  while (*str1 && *str1 == *str2) {
    str1++;
    str2++;
  }
  return (*str1 - *str2);
}

size_t str_len(const char *s)
{
  size_t len = 0;
  if(s != NULL)
  {
    while(*s != '\0')
    {
      ++len;
      ++s;
    }
  }
  return len;
}

#endif

/* SECTION: Predefine (component) parameters ================================= */

int nans_match(double a, double b){
  return (*(uint64_t*)&a == *(uint64_t*)&b);
}
int is_unset(double x){
  return nans_match(x, UNSET);
}
int is_set(double x){
  return !nans_match(x, UNSET);
}
int is_valid(double x){
  return !isnan(x)||is_unset(x);
}
int all_unset(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=1;
  for (int i=0; i<n; ++i) if(is_set(va_arg(ptr, double))) ret=0;
  va_end(ptr);
  return ret;
}
int all_set(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=1;
  for (int i=0; i<n; ++i) if(is_unset(va_arg(ptr, double))) ret=0;
  va_end(ptr);
  return ret;
}
int any_unset(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=0;
  for (int i=0; i<n; ++i) if(is_unset(va_arg(ptr, double))) ret=1;
  va_end(ptr);
  return ret;
}
int any_set(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=0;
  for (int i=0; i<n; ++i) if(is_set(va_arg(ptr, double))) ret=1;
  va_end(ptr);
  return ret;
}


/* SECTION: Dynamic Arrays ================================================== */
IArray1d create_iarr1d(int n){
  IArray1d arr2d;
  arr2d = calloc(n, sizeof(int));
  return arr2d;
}
void destroy_iarr1d(IArray1d a){
  free(a);
}

IArray2d create_iarr2d(int nx, int ny){
  IArray2d arr2d;
  arr2d = calloc(nx, sizeof(int *));

  int *p1;
  p1 = calloc(nx*ny, sizeof(int));

  int i;
  for (i=0; i<nx; i++){
    arr2d[i] = &(p1[i*ny]);
  }
  return arr2d;
}
void destroy_iarr2d(IArray2d a){
  free(a[0]);
  free(a);
}

IArray3d create_iarr3d(int nx, int ny, int nz){
  IArray3d arr3d;
  int i, j;

  // 1d
  arr3d = calloc(nx, sizeof(int **));

  // d2
  int **p1;
  p1 = calloc(nx*ny, sizeof(int *));

  for (i=0; i<nx; i++){
    arr3d[i] = &(p1[i*ny]);
  }

  // 3d
  int *p2;
  p2 = calloc(nx*ny*nz, sizeof(int));
  for (i=0; i<nx; i++){
    for (j=0; j<ny; j++){
      arr3d[i][j] = &(p2[(i*ny+j)*nz]);
    }
  }
  return arr3d;
}

void destroy_iarr3d(IArray3d a){
  free(a[0][0]);
  free(a[0]);
  free(a);
}

DArray1d create_darr1d(int n){
  DArray1d arr2d;
  arr2d = calloc(n, sizeof(double));
  return arr2d;
}

void destroy_darr1d(DArray1d a){
  free(a);
}

DArray2d create_darr2d(int nx, int ny){
  DArray2d arr2d;
  arr2d = calloc(nx, sizeof(double *));

  double *p1;
  p1 = calloc(nx*ny, sizeof(double));

  int i;
  for (i=0; i<nx; i++){
    arr2d[i] = &(p1[i*ny]);
  }
  return arr2d;
}

void destroy_darr2d(DArray2d a){
  free(a[0]);
  free(a);
}

DArray3d create_darr3d(int nx, int ny, int nz){
  DArray3d arr3d;

  int i, j;

  // 1d
  arr3d = calloc(nx, sizeof(double **));

  // d2
  double **p1;
  p1 = calloc(nx*ny, sizeof(double *));

  for (i=0; i<nx; i++){
    arr3d[i] = &(p1[i*ny]);
  }

  // 3d
  double *p2;
  p2 = calloc(nx*ny*nz, sizeof(double));
  for (i=0; i<nx; i++){
    for (j=0; j<ny; j++){
      arr3d[i][j] = &(p2[(i*ny+j)*nz]);
    }
  }
  return arr3d;
}

void destroy_darr3d(DArray3d a){
  free(a[0][0]);
  free(a[0]);
  free(a);
}


/* SECTION: MPI handling ==================================================== */

#ifdef USE_MPI
/* MPI rank */
static int mpi_node_rank;
static int mpi_node_root = 0;


/*******************************************************************************
* mc_MPI_Reduce: Gathers arrays from MPI nodes using Reduce function.
*******************************************************************************/
int mc_MPI_Sum(double *sbuf, long count)
{
  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to reduce */
  else {
    /* we must cut the buffer into blocks not exceeding the MPI max buffer size of 32000 */
    long   offset=0;
    double *rbuf=NULL;
    int    length=MPI_REDUCE_BLOCKSIZE; /* defined in mccode-r.h */
    int    i=0;
    rbuf = calloc(count, sizeof(double));
    if (!rbuf)
      exit(-fprintf(stderr, "Error: Out of memory %li (mc_MPI_Sum)\n", count*sizeof(double)));
    while (offset < count) {
      if (!length || offset+length > count-1) length=count-offset;
      else length=MPI_REDUCE_BLOCKSIZE;
      if (MPI_Allreduce((double*)(sbuf+offset), (double*)(rbuf+offset),
              length, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD) != MPI_SUCCESS)
        return MPI_ERR_COUNT;
      offset += length;
    }

    for (i=0; i<count; i++) sbuf[i] = rbuf[i];
    free(rbuf);
  }
  return MPI_SUCCESS;
} /* mc_MPI_Sum */

/*******************************************************************************
* mc_MPI_Send: Send array to MPI node by blocks to avoid buffer limit
*******************************************************************************/
int mc_MPI_Send(void *sbuf,
                  long count, MPI_Datatype dtype,
                  int dest)
{
  int dsize;
  long offset=0;
  int  tag=1;
  int  length=MPI_REDUCE_BLOCKSIZE; /* defined in mccode-r.h */

  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to send */
  MPI_Type_size(dtype, &dsize);

  while (offset < count) {
    if (offset+length > count-1) length=count-offset;
    else length=MPI_REDUCE_BLOCKSIZE;
    if (MPI_Send((void*)((char*)sbuf+offset*dsize), length, dtype, dest, tag++, MPI_COMM_WORLD) != MPI_SUCCESS)
      return MPI_ERR_COUNT;
    offset += length;
  }

  return MPI_SUCCESS;
} /* mc_MPI_Send */

/*******************************************************************************
* mc_MPI_Recv: Receives arrays from MPI nodes by blocks to avoid buffer limit
*             the buffer must have been allocated previously.
*******************************************************************************/
int mc_MPI_Recv(void *sbuf,
                  long count, MPI_Datatype dtype,
                  int source)
{
  int dsize;
  long offset=0;
  int  tag=1;
  int  length=MPI_REDUCE_BLOCKSIZE; /* defined in mccode-r.h */

  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to recv */
  MPI_Type_size(dtype, &dsize);

  while (offset < count) {
    if (offset+length > count-1) length=count-offset;
    else length=MPI_REDUCE_BLOCKSIZE;
    if (MPI_Recv((void*)((char*)sbuf+offset*dsize), length, dtype, source, tag++,
            MPI_COMM_WORLD, MPI_STATUS_IGNORE) != MPI_SUCCESS)
      return MPI_ERR_COUNT;
    offset += length;
  }

  return MPI_SUCCESS;
} /* mc_MPI_Recv */

#endif /* USE_MPI */

/* SECTION: parameters handling ============================================= */

/* Instrument input parameter type handling. */
/*******************************************************************************
* mcparm_double: extract double value from 's' into 'vptr'
*******************************************************************************/
static int
mcparm_double(char *s, void *vptr)
{
  char *p;
  double *v = (double *)vptr;

  if (!s) { *v = 0; return(1); }
  *v = strtod(s, &p);
  if(*s == '\0' || (p != NULL && *p != '\0') || errno == ERANGE)
    return 0;                        /* Failed */
  else
    return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_double: display parameter type double
*******************************************************************************/
static char *
mcparminfo_double(char *parmname)
{
  return "double";
}

/*******************************************************************************
* mcparmerror_double: display error message when failed extract double
*******************************************************************************/
static void
mcparmerror_double(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for floating point parameter %s (mcparmerror_double)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_double: convert double to string
*******************************************************************************/
static void
mcparmprinter_double(char *f, void *vptr)
{
  double *v = (double *)vptr;
  sprintf(f, "%g", *v);
}

/*******************************************************************************
* mcparm_int: extract int value from 's' into 'vptr'
*******************************************************************************/
static int
mcparm_int(char *s, void *vptr)
{
  char *p;
  int *v = (int *)vptr;
  long x;

  if (!s) { *v = 0; return(1); }
  *v = 0;
  x = strtol(s, &p, 10);
  if(x < INT_MIN || x > INT_MAX)
    return 0;                        /* Under/overflow */
  *v = x;
  if(*s == '\0' || (p != NULL && *p != '\0') || errno == ERANGE)
    return 0;                        /* Failed */
  else
    return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_int: display parameter type int
*******************************************************************************/
static char *
mcparminfo_int(char *parmname)
{
  return "int";
}

/*******************************************************************************
* mcparmerror_int: display error message when failed extract int
*******************************************************************************/
static void
mcparmerror_int(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for integer parameter %s (mcparmerror_int)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_int: convert int to string
*******************************************************************************/
static void
mcparmprinter_int(char *f, void *vptr)
{
  int *v = (int *)vptr;
  sprintf(f, "%d", *v);
}

/*******************************************************************************
* mcparm_string: extract char* value from 's' into 'vptr' (copy)
*******************************************************************************/
static int
mcparm_string(char *s, void *vptr)
{
  char **v = (char **)vptr;
  if (!s) { *v = NULL; return(1); }
  *v = (char *)malloc(strlen(s) + 1);
  if(*v == NULL)
  {
    exit(-fprintf(stderr, "Error: Out of memory %li (mcparm_string).\n", (long)strlen(s) + 1));
  }
  strcpy(*v, s);
  return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_string: display parameter type string
*******************************************************************************/
static char *
mcparminfo_string(char *parmname)
{
  return "string";
}

/*******************************************************************************
* mcparmerror_string: display error message when failed extract string
*******************************************************************************/
static void
mcparmerror_string(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for string parameter %s (mcparmerror_string)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_string: convert string to string (including esc chars)
*******************************************************************************/
static void
mcparmprinter_string(char *f, void *vptr)
{
  char **v = (char **)vptr;
  char *p;

  if (!*v) { *f='\0'; return; }
  strcpy(f, "");
  for(p = *v; *p != '\0'; p++)
  {
    switch(*p)
    {
      case '\n':
        strcat(f, "\\n");
        break;
      case '\r':
        strcat(f, "\\r");
        break;
      case '"':
        strcat(f, "\\\"");
        break;
      case '\\':
        strcat(f, "\\\\");
        break;
      default:
        strncat(f, p, 1);
    }
  }
  /* strcat(f, "\""); */
} /* mcparmprinter_string */

/* now we may define the parameter structure, using previous functions */
static struct
  {
    int (*getparm)(char *, void *);
    char * (*parminfo)(char *);
    void (*error)(char *, char *);
    void (*printer)(char *, void *);
} mcinputtypes[] = {
  {
    mcparm_int, mcparminfo_int, mcparmerror_int,
    mcparmprinter_int
  }, {
    mcparm_string, mcparminfo_string, mcparmerror_string,
    mcparmprinter_string
  }, {
    mcparm_string, mcparminfo_string, mcparmerror_string,
    mcparmprinter_string
  }, {
    mcparm_double, mcparminfo_double, mcparmerror_double,
    mcparmprinter_double
  }, {
    mcparm_double, mcparminfo_double, mcparmerror_double,
    mcparmprinter_double
  }
};

/*******************************************************************************
* mcestimate_error: compute sigma from N,p,p2 in Gaussian large numbers approx
*******************************************************************************/
double mcestimate_error(double N, double p1, double p2)
{
  double pmean, n1;
  if(N <= 1)
    return p1;
  pmean = p1 / N;
  n1 = N - 1;
  /* Note: underflow may cause p2 to become zero; the fabs() below guards
     against this. */
  return sqrt((N/n1)*fabs(p2 - pmean*pmean));
}

double (*mcestimate_error_p)
  (double V2, double psum, double p2sum)=mcestimate_error;

/* ========================================================================== */

/*                               MCCODE_R_IO_C                                */

/* ========================================================================== */

#ifndef MCCODE_R_IO_C
#define MCCODE_R_IO_C "$Revision$"

/* SECTION: file i/o handling ================================================ */

#ifndef HAVE_STRCASESTR
// from msysgit: https://code.google.com/p/msysgit/source/browse/compat/strcasestr.c
char *strcasestr(const char *haystack, const char *needle)
{
  int nlen = strlen(needle);
  int hlen = strlen(haystack) - nlen + 1;
  int i;

  for (i = 0; i < hlen; i++) {
    int j;
    for (j = 0; j < nlen; j++) {
            unsigned char c1 = haystack[i+j];
            unsigned char c2 = needle[j];
            if (toupper(c1) != toupper(c2))
                    goto next;
    }
    return (char *) haystack + i;
  next:
    ;
  }
  return NULL;
}


#endif
#ifndef HAVE_STRCASECMP
int strcasecmp( const char *s1, const char *s2 )
{
  int c1, c2;
  do {
    c1 = tolower( (unsigned char) *s1++ );
    c2 = tolower( (unsigned char) *s2++ );
  } while (c1 == c2 && c1 != 0);
  return c2 > c1 ? -1 : c1 > c2;
}
#endif

#ifndef STRACPY
/* this is a replacement to strncpy, but ensures that the copy ends with NULL */
/* http://stracpy.blogspot.fr/2011/04/stracpy-strncpy-replacement.html */
#define STRACPY
char *stracpy(char *destination, const char *source, size_t amount)
{
        if (!destination || !source || !amount) return(NULL);
        while(amount--)
          if((*destination++ = *source++) == '\0') break;
        *destination = '\0';
        return destination;
}
#endif

/*******************************************************************************
* mcfull_file: allocates a full file name=dirname+file. Catenate extension if missing.
*******************************************************************************/
char *mcfull_file(char *name, char *ext)
{
  int   dirlen=0;
  char *mem   =NULL;

  dirlen = dirname ? strlen(dirname) : 0;
  mem = (char*)malloc(dirlen + strlen(name) + CHAR_BUF_LENGTH);
  if(!mem) {
    exit(-fprintf(stderr, "Error: Out of memory %li (mcfull_file)\n", (long)(dirlen + strlen(name) + 256)));
  }
  strcpy(mem, "");

  /* prepend directory name to path if name does not contain a path */
  if (dirlen > 0 && !strchr(name, MC_PATHSEP_C)) {
    strcat(mem, dirname);
    strcat(mem, MC_PATHSEP_S);
  } /* dirlen */

  strcat(mem, name);
  if (!strchr(name, '.') && ext && strlen(ext))
  { /* add extension if not in file name already */
    strcat(mem, ".");
    strcat(mem, ext);
  }
  return(mem);
} /* mcfull_file */

/*******************************************************************************
* mcnew_file: opens a new file within dirname if non NULL
*             the file is opened in "a" (append, create if does not exist)
*             the extension 'ext' is added if the file name does not include one.
*             the last argument is set to 0 if file did not exist, else to 1.
*******************************************************************************/
FILE *mcnew_file(char *name, char *ext, int *exists)
{
  char *mem;
  FILE *file=NULL;

  if (!name || strlen(name) == 0 || mcdisable_output_files) return(NULL);

  mem  = mcfull_file(name, ext); /* create dirname/name.ext */

  /* check for existence */
  file = fopen(mem, "r"); /* for reading -> fails if does not exist */
  if (file) {
    fclose(file);
    *exists=1;
  } else
    *exists=0;

  /* open the file for writing/appending */
#ifdef USE_NEXUS
  if (mcformat && strcasestr(mcformat, "NeXus")) {
    /* NXhandle nxhandle is defined in the .h with USE_NEXUS */
    NXaccess mode = (*exists ? NXACC_CREATE5 | NXACC_RDWR : NXACC_CREATE5);

    if (NXopen(mem, mode, &nxhandle) != NX_OK)
      file = NULL;
    else
      file = (FILE*)&nxhandle; /* to make it non NULL */
  } else
#endif
    file = fopen(mem, "a+");

  if(!file)
    fprintf(stderr, "Warning: could not open output file '%s' for %s (mcnew_file)\n",
      mem, *exists ? "append" : "create");
  free(mem);

  return file;
} /* mcnew_file */

/*******************************************************************************
* mcdetector_statistics: compute detector statistics, error bars, [x I I_err N] 1D
* RETURN:            updated detector structure
* Used by: detector_import
*******************************************************************************/
MCDETECTOR mcdetector_statistics(
  MCDETECTOR detector)
{

  if (!detector.p1 || !detector.m)
    return(detector);

  /* compute statistics and update MCDETECTOR structure ===================== */
  double sum_z  = 0, min_z  = 0, max_z  = 0;
  double fmon_x =0,  smon_x = 0, fmon_y =0, smon_y=0, mean_z=0;
  double Nsum=0, P2sum=0;

  double sum_xz = 0, sum_yz = 0, sum_x = 0, sum_y = 0, sum_x2z = 0, sum_y2z = 0;
  int    i,j;
  char   hasnan=0, hasinf=0;
  char   israw = ((char*)strcasestr(detector.format,"raw") != NULL);
  double *this_p1=NULL; /* new 1D McCode array [x I E N]. Freed after writing data */

  /* if McCode/PGPLOT and rank==1 we create a new m*4 data block=[x I E N] */
  if (detector.rank == 1 && strcasestr(detector.format,"McCode")) {
    this_p1 = (double *)calloc(detector.m*detector.n*detector.p*4, sizeof(double));
    if (!this_p1)
      exit(-fprintf(stderr, "Error: Out of memory creating %li 1D " MCCODE_STRING " data set for file '%s' (detector_import)\n",
        detector.m*detector.n*detector.p*4*sizeof(double*), detector.filename));
  }

  max_z = min_z = detector.p1[0];

  /* compute sum and moments (not for lists) */
  if (!strcasestr(detector.format,"list") && detector.m)
  for(j = 0; j < detector.n*detector.p; j++)
  {
    for(i = 0; i < detector.m; i++)
    {
      double x,y,z;
      double N, E;
      long   index= !detector.istransposed ? i*detector.n*detector.p + j : i+j*detector.m;
      char   hasnaninf=0;

      if (detector.m)
        x = detector.xmin + (i + 0.5)/detector.m*(detector.xmax - detector.xmin);
      else x = 0;
      if (detector.n && detector.p)
        y = detector.ymin + (j + 0.5)/detector.n/detector.p*(detector.ymax - detector.ymin);
      else y = 0;
      z = detector.p1[index];
      N = detector.p0 ? detector.p0[index] : 1;
      E = detector.p2 ? detector.p2[index] : 0;
      if (detector.p2 && !israw)
        detector.p2[index] = (*mcestimate_error_p)(detector.p0[index],detector.p1[index],detector.p2[index]); /* set sigma */

      if (detector.rank == 1 && this_p1 && strcasestr(detector.format,"McCode")) {
        /* fill-in 1D McCode array [x I E N] */
        this_p1[index*4]   = x;
        this_p1[index*4+1] = z;
        this_p1[index*4+2] = detector.p2 ? detector.p2[index] : 0;
        this_p1[index*4+3] = N;
      }

      if (isnan(z) || isnan(E) || isnan(N)) hasnaninf=hasnan=1;
      if (isinf(z) || isinf(E) || isinf(N)) hasnaninf=hasinf=1;

      /* compute stats integrals */
      if (!hasnaninf) {
        sum_xz += x*z;
        sum_yz += y*z;
        sum_x  += x;
        sum_y  += y;
        sum_z  += z;
        sum_x2z += x*x*z;
        sum_y2z += y*y*z;
        if (z > max_z) max_z = z;
        if (z < min_z) min_z = z;

        Nsum += N;
        P2sum += E;
      }

    }
  } /* for j */

  /* compute 1st and 2nd moments. For lists, sum_z=0 so this is skipped. */
  if (sum_z && detector.n*detector.m*detector.p)
  {
    fmon_x = sum_xz/sum_z;
    fmon_y = sum_yz/sum_z;
    smon_x = sum_x2z/sum_z-fmon_x*fmon_x; smon_x = smon_x > 0 ? sqrt(smon_x) : 0;
    smon_y = sum_y2z/sum_z-fmon_y*fmon_y; smon_y = smon_y > 0 ? sqrt(smon_y) : 0;
    mean_z = sum_z/detector.n/detector.m/detector.p;
  }
  /* store statistics into detector */
  detector.intensity = sum_z;
  detector.error     = Nsum ? (*mcestimate_error_p)(Nsum, sum_z, P2sum) : 0;
  detector.events    = Nsum;
  detector.min       = min_z;
  detector.max       = max_z;
  detector.mean      = mean_z;
  detector.centerX   = fmon_x;
  detector.halfwidthX= smon_x;
  detector.centerY   = fmon_y;
  detector.halfwidthY= smon_y;

  /* if McCode/PGPLOT and rank==1 replace p1 with new m*4 1D McCode and clear others */
  if (detector.rank == 1 && this_p1 && strcasestr(detector.format,"McCode")) {

    detector.p1 = this_p1;
    detector.n  = detector.m; detector.m  = 4;
    detector.p0 = detector.p2 = NULL;
    detector.istransposed = 1;
  }

  if (detector.n*detector.m*detector.p > 1)
    snprintf(detector.signal, CHAR_BUF_LENGTH,
      "Min=%g; Max=%g; Mean=%g;", detector.min, detector.max, detector.mean);
  else
    strcpy(detector.signal, "None");
  snprintf(detector.values, CHAR_BUF_LENGTH,
    "%g %g %g", detector.intensity, detector.error, detector.events);

  switch (detector.rank) {
    case 1:  snprintf(detector.statistics, CHAR_BUF_LENGTH, "X0=%g; dX=%g;",
      detector.centerX, detector.halfwidthX); break;
    case 2:
    case 3:  snprintf(detector.statistics, CHAR_BUF_LENGTH, "X0=%g; dX=%g; Y0=%g; dY=%g;",
      detector.centerX, detector.halfwidthX, detector.centerY, detector.halfwidthY);
      break;
    default: strcpy(detector.statistics, "None");
  }

  if (hasnan)
    printf("WARNING: Nan detected in component/file %s %s\n",
      detector.component, strlen(detector.filename) ? detector.filename : "");
  if (hasinf)
    printf("WARNING: Inf detected in component/file %s %s\n",
      detector.component, strlen(detector.filename) ? detector.filename : "");

  return(detector);

} /* mcdetector_statistics */

/*******************************************************************************
* detector_import: build detector structure, merge non-lists from MPI
*                    compute basic stat, write "Detector:" line
* RETURN:            detector structure. Invalid data if detector.p1 == NULL
*                    Invalid detector sets m=0 and filename=""
*                    Simulation data  sets m=0 and filename=siminfo_name
* This function is equivalent to the old 'mcdetector_out', returning a structure
*******************************************************************************/
MCDETECTOR detector_import(
  char *format,
  char *component, char *title,
  long m, long n,  long p,
  char *xlabel, char *ylabel, char *zlabel,
  char *xvar, char *yvar, char *zvar,
  double x1, double x2, double y1, double y2, double z1, double z2,
  char *filename,
  double *p0, double *p1, double *p2,
  Coords position)
{
  time_t t;       /* for detector.date */
  long   date_l;  /* date as a long number */
  char   istransposed=0;
  char   c[CHAR_BUF_LENGTH]; /* temp var for signal label */

  MCDETECTOR detector;

  /* build MCDETECTOR structure ============================================= */
  /* make sure we do not have NULL for char fields */

  /* these also apply to simfile */
  strncpy (detector.filename,  filename ? filename : "",        CHAR_BUF_LENGTH);
  strncpy (detector.format,    format   ? format   : "McCode" , CHAR_BUF_LENGTH);
  /* add extension if missing */
  if (strlen(detector.filename) && !strchr(detector.filename, '.'))
  { /* add extension if not in file name already */
    strcat(detector.filename, ".dat");
  }
  strncpy (detector.component, component ? component : MCCODE_STRING " component", CHAR_BUF_LENGTH);

  snprintf(detector.instrument, CHAR_BUF_LENGTH, "%s (%s)", instrument_name, instrument_source);
  snprintf(detector.user, CHAR_BUF_LENGTH,      "%s on %s",
        getenv("USER") ? getenv("USER") : MCCODE_NAME,
        getenv("HOST") ? getenv("HOST") : "localhost");
  time(&t);         /* get current write time */
  date_l = (long)t; /* same but as a long */
  snprintf(detector.date, CHAR_BUF_LENGTH, "%s", ctime(&t));
  if (strlen(detector.date))   detector.date[strlen(detector.date)-1] = '\0'; /* remove last \n in date */
  detector.date_l = date_l;

  if (!mcget_run_num() || mcget_run_num() >= mcget_ncount())
    snprintf(detector.ncount, CHAR_BUF_LENGTH, "%llu", mcget_ncount()
#ifdef USE_MPI
*mpi_node_count
#endif
  );
  else
    snprintf(detector.ncount, CHAR_BUF_LENGTH, "%g/%g", (double)mcget_run_num(), (double)mcget_ncount());

  detector.p0         = p0;
  detector.p1         = p1;
  detector.p2         = p2;

  /* handle transposition (not for NeXus) */
  if (!strcasestr(detector.format, "NeXus")) {
    if (m<0 || n<0 || p<0)             istransposed = !istransposed;
    if (strcasestr(detector.format, "transpose")) istransposed = !istransposed;
    if (istransposed) { /* do the swap once for all */
      long i=m; m=n; n=i;
    }
  }

  m=labs(m); n=labs(n); p=labs(p); /* make sure dimensions are positive */
  detector.istransposed = istransposed;

  /* determine detector rank (dimensionality) */
  if (!m || !n || !p || !p1) detector.rank = 4; /* invalid: exit with m=0 filename="" */
  else if (m*n*p == 1)       detector.rank = 0; /* 0D */
  else if (n == 1 || m == 1) detector.rank = 1; /* 1D */
  else if (p == 1)           detector.rank = 2; /* 2D */
  else                       detector.rank = 3; /* 3D */

  /* from rank, set type */
  switch (detector.rank) {
    case 0:  strcpy(detector.type,  "array_0d"); m=n=p=1; break;
    case 1:  snprintf(detector.type, CHAR_BUF_LENGTH, "array_1d(%ld)", m*n*p); m *= n*p; n=p=1; break;
    case 2:  snprintf(detector.type, CHAR_BUF_LENGTH, "array_2d(%ld, %ld)", m, n*p); n *= p; p=1; break;
    case 3:  snprintf(detector.type, CHAR_BUF_LENGTH, "array_3d(%ld, %ld, %ld)", m, n, p); break;
    default: m=0; strcpy(detector.type, ""); strcpy(detector.filename, "");/* invalid */
  }

  detector.m    = m;
  detector.n    = n;
  detector.p    = p;

  /* these only apply to detector files ===================================== */

  snprintf(detector.position, CHAR_BUF_LENGTH, "%g %g %g", position.x, position.y, position.z);
  /* may also store actual detector orientation in the future */

  strncpy(detector.title,      title && strlen(title) ? title : component,       CHAR_BUF_LENGTH);
  strncpy(detector.xlabel,     xlabel && strlen(xlabel) ? xlabel : "X", CHAR_BUF_LENGTH); /* axis labels */
  strncpy(detector.ylabel,     ylabel && strlen(ylabel) ? ylabel : "Y", CHAR_BUF_LENGTH);
  strncpy(detector.zlabel,     zlabel && strlen(zlabel) ? zlabel : "Z", CHAR_BUF_LENGTH);
  strncpy(detector.xvar,       xvar && strlen(xvar) ? xvar :       "x", CHAR_BUF_LENGTH); /* axis variables */
  strncpy(detector.yvar,       yvar && strlen(yvar) ? yvar :       detector.xvar, CHAR_BUF_LENGTH);
  strncpy(detector.zvar,       zvar && strlen(zvar) ? zvar :       detector.yvar, CHAR_BUF_LENGTH);

  /* set "variables" as e.g. "I I_err N" */
  strcpy(c, "I ");
  if (strlen(detector.zvar))      strncpy(c, detector.zvar,32);
  else if (strlen(detector.yvar)) strncpy(c, detector.yvar,32);
  else if (strlen(detector.xvar)) strncpy(c, detector.xvar,32);

  if (detector.rank == 1)
    snprintf(detector.variables, CHAR_BUF_LENGTH, "%s %s %s_err N", detector.xvar, c, c);
  else
    snprintf(detector.variables, CHAR_BUF_LENGTH, "%s %s_err N", c, c);

  /* limits */
  detector.xmin = x1;
  detector.xmax = x2;
  detector.ymin = y1;
  detector.ymax = y2;
  detector.zmin = z1;
  detector.zmax = z2;
  if (abs(detector.rank) == 1)
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g", x1, x2);
  else if (detector.rank == 2)
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g %g %g", x1, x2, y1, y2);
  else
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g %g %g %g %g", x1, x2, y1, y2, z1, z2);

  /* if MPI and nodes_nb > 1: reduce data sets when using MPI =============== */
#ifdef USE_MPI
  if (!strcasestr(detector.format,"list") && mpi_node_count > 1 && m) {
    /* we save additive data: reduce everything into mpi_node_root */
    if (p0) mc_MPI_Sum(p0, m*n*p);
    if (p1) mc_MPI_Sum(p1, m*n*p);
    if (p2) mc_MPI_Sum(p2, m*n*p);
    if (!p0) {  /* additive signal must be then divided by the number of nodes */
      int i;
      for (i=0; i<m*n*p; i++) {
        p1[i] /= mpi_node_count;
        if (p2) p2[i] /= mpi_node_count;
      }
    }
  }
#endif /* USE_MPI */

  /* compute statistics, Nsum, intensity, Error bars */
  detector = mcdetector_statistics(detector);

#ifdef USE_MPI
  /* slaves are done */
  if(mpi_node_rank != mpi_node_root) {
    return detector;
  }
#endif

  /* output "Detector:" line ================================================ */
  /* when this is a detector written by a component (not the SAVE from instrument),
     not an event lists */
  if (!m) return(detector);
  if (!strcasestr(detector.format,"list")) {
    if (!strcmp(detector.component, instrument_name)) {
      if (strlen(detector.filename))  /* we name it from its filename, or from its title */
        strncpy(c, detector.filename, CHAR_BUF_LENGTH);
      else
        snprintf(c, CHAR_BUF_LENGTH, "%s", instrument_name);
    } else
      strncpy(c, detector.component, CHAR_BUF_LENGTH);  /* usual detectors written by components */

    printf("Detector: %s_I=%g %s_ERR=%g %s_N=%g",
           c, detector.intensity,
           c, detector.error,
           c, detector.events);
    printf(" \"%s\"\n", strlen(detector.filename) ? detector.filename : detector.component);
  }


  return(detector);
} /* detector_import */

/* end MCDETECTOR import section ============================================ */

















/* ========================================================================== */

/*                               ASCII output                                 */
/*     The SIM file is YAML based, the data files have '#' headers            */

/* ========================================================================== */


/*******************************************************************************
* mcinfo_out: output instrument tags/info (only in SIM)
* Used in: siminfo_init (ascii), mcinfo(stdout)
*******************************************************************************/
static void mcinfo_out(char *pre, FILE *f)
{
  char Parameters[CHAR_BUF_LENGTH] = "";
  int  i;

  if (!f || mcdisable_output_files) return;

  /* create parameter string ================================================ */
  for(i = 0; i < numipar; i++)
  {
    char ThisParam[CHAR_BUF_LENGTH];
    if (strlen(mcinputtable[i].name) > CHAR_BUF_LENGTH) break;
    snprintf(ThisParam, CHAR_BUF_LENGTH, " %s(%s)", mcinputtable[i].name,
            (*mcinputtypes[mcinputtable[i].type].parminfo)
                (mcinputtable[i].name));
    if (strlen(Parameters) + strlen(ThisParam) + 1 >= CHAR_BUF_LENGTH) break;
    strcat(Parameters, ThisParam);
  }

  /* output data ============================================================ */
  if (f != stdout)
    fprintf(f, "%sFile: %s%c%s\n",    pre, dirname, MC_PATHSEP_C, siminfo_name);
  else
    fprintf(f, "%sCreator: %s\n",     pre, MCCODE_STRING);

  fprintf(f, "%sSource: %s\n",   pre, instrument_source);
  fprintf(f, "%sParameters: %s\n",    pre, Parameters);

  fprintf(f, "%sTrace_enabled: %s\n", pre, traceenabled ? "yes" : "no");
  fprintf(f, "%sDefault_main: %s\n",  pre, defaultmain ?  "yes" : "no");
  fprintf(f, "%sEmbedded_runtime: %s\n", pre,
#ifdef MC_EMBEDDED_RUNTIME
         "yes"
#else
         "no"
#endif
         );

  fflush(f);
} /* mcinfo_out */

/*******************************************************************************
* mcruninfo_out: output simulation tags/info (both in SIM and data files)
* Used in: siminfo_init (ascii case), mcdetector_out_xD_ascii
*******************************************************************************/
static void mcruninfo_out(char *pre, FILE *f)
{
  int i;
  char Parameters[CHAR_BUF_LENGTH];

  if (!f || mcdisable_output_files) return;

  fprintf(f, "%sFormat: %s%s\n",      pre,
    mcformat && strlen(mcformat) ? mcformat : MCCODE_NAME,
    mcformat && strcasestr(mcformat,"McCode") ? " with text headers" : "");
  fprintf(f, "%sURL: %s\n",         pre, "http://www.mccode.org");
  fprintf(f, "%sCreator: %s\n",     pre, MCCODE_STRING);
  fprintf(f, "%sInstrument: %s\n", pre, instrument_source);
  fprintf(f, "%sNcount: %llu\n",        pre, mcget_ncount());
  fprintf(f, "%sTrace: %s\n",       pre, mcdotrace ? "yes" : "no");
  fprintf(f, "%sGravitation: %s\n", pre, mcgravitation ? "yes" : "no");
  snprintf(Parameters, CHAR_BUF_LENGTH, "%ld", mcseed);
  fprintf(f, "%sSeed: %s\n",        pre, Parameters);
  fprintf(f, "%sDirectory: %s\n",        pre, dirname ? dirname : ".");
#ifdef USE_MPI
  if (mpi_node_count > 1)
    fprintf(f, "%sNodes: %i\n",        pre, mpi_node_count);
#endif

  // TODO Consider replacing this by a a call to `mcparameterinfo_out(pre+"Param: ", f)`
  /* output parameter string ================================================ */
  for(i = 0; i < numipar; i++) {
      if (mcinputtable[i].par){
	/* Parameters with a default value */
	if(mcinputtable[i].val && strlen(mcinputtable[i].val)){
	  (*mcinputtypes[mcinputtable[i].type].printer)(Parameters, mcinputtable[i].par);
	  fprintf(f, "%sParam: %s=%s\n", pre, mcinputtable[i].name, Parameters);
        /* ... and those without */
	}else{
	  fprintf(f, "%sParam: %s=NULL\n", pre, mcinputtable[i].name);
	}
      }
  }
  fflush(f);
} /* mcruninfo_out */

/*******************************************************************************
 * @brief Print parameter information to the specified file
 * @param pre any beginning-of-line padding
 * @param f the output file
 */
static void mcparameterinfo_out(char * pre, FILE *f){
  if (!f || mcdisable_output_files) return;

  unsigned int nchar = 4;
  for (int i=0; i < numipar; ++i){
    if (mcinputtable[i].par && mcinputtable[i].val && strlen(mcinputtable[i].val) > nchar)
      nchar = strlen(mcinputtable[i].val);
  }
  char * buffer = calloc(nchar+1, sizeof(char));

  if (!buffer) {
    exit(1);
  }

  for (int i=0; i < numipar; ++i) {
    if (mcinputtable[i].par) {
      char * name = mcinputtable[i].name;
      if (mcinputtable[i].val && strlen(mcinputtable[i].val)) {
        mcinputtypes[mcinputtable[i].type].printer(buffer, mcinputtable[i].par);
      } else {
        strcpy(buffer, "NULL");
      }
      if (strlen(mcinputtable[i].unit)){
        //fprintf(f, "%s%s %s (\"%s\") = %s\n", pre, mcinputtypes[mcinputtable[i].type].parminfo(name), name, mcinputtable[i].unit, buffer);
        fprintf(f, "%s%s %s/\"%s\" = %s\n", pre, mcinputtypes[mcinputtable[i].type].parminfo(name), name, mcinputtable[i].unit, buffer);
      } else {
        fprintf(f, "%s%s %s = %s\n", pre, mcinputtypes[mcinputtable[i].type].parminfo(name), name, buffer);
      }
    }
  }

  free(buffer);
}

/*******************************************************************************
* siminfo_out:    wrapper to fprintf(siminfo_file)
*******************************************************************************/
void siminfo_out(char *format, ...)
{
  va_list ap;

  if(siminfo_file && !mcdisable_output_files)
  {
    va_start(ap, format);
    vfprintf(siminfo_file, format, ap);
    va_end(ap);
  }
} /* siminfo_out */


/*******************************************************************************
* mcdatainfo_out: output detector header
*   mcdatainfo_out(prefix, file_handle, detector) writes info to data file
*******************************************************************************/
static void
mcdatainfo_out(char *pre, FILE *f, MCDETECTOR detector)
{
  if (!f || !detector.m || mcdisable_output_files) return;

  /* output data ============================================================ */
  fprintf(f, "%sDate: %s (%li)\n",       pre, detector.date, detector.date_l);
  fprintf(f, "%stype: %s\n",       pre, detector.type);
  fprintf(f, "%sSource: %s\n",     pre, detector.instrument);
  fprintf(f, "%scomponent: %s\n",  pre, detector.component);
  fprintf(f, "%sposition: %s\n",   pre, detector.position);

  fprintf(f, "%stitle: %s\n",      pre, detector.title);
  fprintf(f, !mcget_run_num() || mcget_run_num() >= mcget_ncount() ?
             "%sNcount: %s\n" :
             "%sratio: %s\n",  pre, detector.ncount);

  if (strlen(detector.filename)) {
    fprintf(f, "%sfilename: %s\n", pre, detector.filename);
  }

  fprintf(f, "%sstatistics: %s\n", pre, detector.statistics);
  fprintf(f, "%ssignal: %s\n",     pre, detector.signal);
  fprintf(f, "%svalues: %s\n",     pre, detector.values);

  if (detector.rank >= 1)
  {
    fprintf(f, "%sxvar: %s\n",     pre, detector.xvar);
    fprintf(f, "%syvar: %s\n",     pre, detector.yvar);
    fprintf(f, "%sxlabel: %s\n",   pre, detector.xlabel);
    fprintf(f, "%sylabel: %s\n",   pre, detector.ylabel);
    if (detector.rank > 1) {
      fprintf(f, "%szvar: %s\n",   pre, detector.zvar);
      fprintf(f, "%szlabel: %s\n", pre, detector.zlabel);
    }
  }

  fprintf(f,
    abs(detector.rank)==1 ?
             "%sxlimits: %s\n" :
             "%sxylimits: %s\n", pre, detector.limits);
  fprintf(f, "%svariables: %s\n", pre,
    strcasestr(detector.format, "list") ? detector.ylabel : detector.variables);

  fflush(f);

} /* mcdatainfo_out */

/* mcdetector_out_array_ascii: output a single array to a file
 *   m: columns
 *   n: rows
 *   p: array
 *   f: file handle (already opened)
 */
static void mcdetector_out_array_ascii(long m, long n, double *p, FILE *f, char istransposed)
{
  if(f)
  {
    int i,j;
    for(j = 0; j < n; j++)
    {
      for(i = 0; i < m; i++)
      {
          fprintf(f, "%.10g ", p[!istransposed ? i*n + j : j*m+i]);
      }
      fprintf(f,"\n");
    }
  }
} /* mcdetector_out_array_ascii */

/*******************************************************************************
* mcdetector_out_0D_ascii: called by mcdetector_out_0D for ascii output
*******************************************************************************/
MCDETECTOR mcdetector_out_0D_ascii(MCDETECTOR detector)
{
  int exists=0;
  FILE *outfile = NULL;

  /* Write data set information to simulation description file. */
  MPI_MASTER(
    siminfo_out("\nbegin data\n"); // detector.component
    mcdatainfo_out("  ", siminfo_file, detector);
    siminfo_out("end data\n");
    /* Don't write if filename is NULL: mcnew_file handles this (return NULL) */
    outfile = mcnew_file(detector.component, "dat", &exists);
    if(outfile)
    {
      /* write data file header and entry in simulation description file */
      mcruninfo_out( "# ", outfile);
      mcdatainfo_out("# ", outfile, detector);
      /* write I I_err N */
      fprintf(outfile, "%g %g %g\n",
        detector.intensity, detector.error, detector.events);
      fclose(outfile);
    }
  ); /* MPI_MASTER */
  return(detector);
} /* mcdetector_out_0D_ascii */

/*******************************************************************************
* mcdetector_out_1D_ascii: called by mcdetector_out_1D for ascii output
*******************************************************************************/
MCDETECTOR mcdetector_out_1D_ascii(MCDETECTOR detector)
{
  int exists=0;
  FILE *outfile = NULL;

  MPI_MASTER(
    /* Write data set information to simulation description file. */
    siminfo_out("\nbegin data\n"); // detector.filename
    mcdatainfo_out("  ", siminfo_file, detector);
    siminfo_out("end data\n");
    /* Loop over array elements, writing to file. */
    /* Don't write if filename is NULL: mcnew_file handles this (return NULL) */
    outfile = mcnew_file(detector.filename, "dat", &exists);
    if(outfile)
    {
      /* write data file header and entry in simulation description file */
      mcruninfo_out( "# ", outfile);
      mcdatainfo_out("# ", outfile, detector);
      /* output the 1D array columns */
      mcdetector_out_array_ascii(detector.m, detector.n, detector.p1, outfile, detector.istransposed);

      fclose(outfile);
    }
  ); /* MPI_MASTER */
  return(detector);

}  /* mcdetector_out_1D_ascii */

/*******************************************************************************
* mcdetector_out_2D_ascii: called by mcdetector_out_2D for ascii output
*******************************************************************************/
MCDETECTOR mcdetector_out_2D_ascii(MCDETECTOR detector)
{
  int exists=0;
  FILE *outfile = NULL;

  MPI_MASTER(
    /* Loop over array elements, writing to file. */
    /* Don't write if filename is NULL: mcnew_file handles this (return NULL) */
    outfile = mcnew_file(detector.filename, "dat", &exists);
    if(outfile)
    {
      /* write header only if file has just been created (not appending) */
      if (!exists) {
        /* Write data set information to simulation description file. */
        siminfo_out("\nbegin data\n"); // detector.filename
        mcdatainfo_out("  ", siminfo_file, detector);
        siminfo_out("end data\n");

        mcruninfo_out( "# ", outfile);
        mcdatainfo_out("# ", outfile,   detector);
        fprintf(outfile, "# Data [%s/%s] %s:\n", detector.component, detector.filename, detector.zvar);
      }
      mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p1,
        outfile, detector.istransposed);
      if (detector.p2) {
        fprintf(outfile, "# Errors [%s/%s] %s_err:\n", detector.component, detector.filename, detector.zvar);
        mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p2,
          outfile, detector.istransposed);
      }
      if (detector.p0) {
        fprintf(outfile, "# Events [%s/%s] N:\n", detector.component, detector.filename);
        mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p0,
          outfile, detector.istransposed);
      }
      fclose(outfile);

      if (!exists) {
        if (strcasestr(detector.format, "list"))
          printf("Events:   \"%s\"\n",
            strlen(detector.filename) ? detector.filename : detector.component);
      }
    } /* if outfile */
  ); /* MPI_MASTER */
#ifdef USE_MPI
  if (strcasestr(detector.format, "list") && mpi_node_count > 1) {
    int node_i=0;
    /* loop along MPI nodes to write sequentially */
    for(node_i=0; node_i<mpi_node_count; node_i++) {
      /* MPI: slaves wait for the master to write its block, then append theirs */
      MPI_Barrier(MPI_COMM_WORLD);
      if (node_i != mpi_node_root && node_i == mpi_node_rank) {
        if(strlen(detector.filename) && !mcdisable_output_files)	/* Don't write if filename is NULL */
          outfile = mcnew_file(detector.filename, "dat", &exists);
        if (!exists)
          fprintf(stderr, "Warning: [MPI node %i] file '%s' does not exist yet, "
                          "MASTER should have opened it before.\n",
            mpi_node_rank, detector.filename);
        if(outfile) {
          mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p1,
            outfile, detector.istransposed);
          fclose(outfile);
        }
      }
    }
  } /* if strcasestr list */
#endif
  return(detector);
} /* mcdetector_out_2D_ascii */

/*******************************************************************************
* strcpy_valid: makes a valid string for variable names.
*   copy 'original' into 'valid', replacing invalid characters by '_'
*   char arrays must be pre-allocated
*******************************************************************************/
static char *strcpy_valid(char *valid, char *original)
{
  long i;
  int  n=CHAR_BUF_LENGTH; /* max length of valid names */

  if (original == NULL || !strlen(original)) return(NULL);

  if (n > strlen(original)) n = strlen(original);
  else original += strlen(original)-n;
  strncpy(valid, original, n);

  for (i=0; i < n; i++)
  {
    if ( (valid[i] > 122)
      || (valid[i] < 32)
      || (strchr("!\"#$%&'()*+,-.:;<=>?@[\\]^`/ \n\r\t", valid[i]) != NULL) )
    {
      if (i) valid[i] = '_'; else valid[i] = 'm';
    }
  }
  valid[i] = '\0';

  return(valid);
} /* strcpy_valid */

/* end ascii output section ================================================= */







#ifdef USE_NEXUS

/* ========================================================================== */

/*                               NeXus output                                 */

/* ========================================================================== */

#define nxprintf(...)    nxstr('d', __VA_ARGS__)
#define nxprintattr(...) nxstr('a', __VA_ARGS__)

/*******************************************************************************
* nxstr: output a tag=value data set (char) in NeXus/current group
*   when 'format' is larger that 1024 chars it is used as value for the 'tag'
*   else the value is assembled with format and following arguments.
*   type='d' -> data set
*        'a' -> attribute for current data set
*******************************************************************************/
static int nxstr(char type, NXhandle *f, char *tag, char *format, ...)
{
  va_list ap;
  char value[CHAR_BUF_LENGTH];
  int  i;
  int  ret=NX_OK;

  if (!tag || !format || !strlen(tag) || !strlen(format)) return(NX_OK);

  /* assemble the value string */
  if (strlen(format) < CHAR_BUF_LENGTH) {
    va_start(ap, format);
    ret = vsnprintf(value, CHAR_BUF_LENGTH, format, ap);
    va_end(ap);

    i = strlen(value);
  } else {
    i = strlen(format);
  }

  if (type == 'd') {
    /* open/put/close data set */
    if (NXmakedata (f, tag, NX_CHAR, 1, &i) != NX_OK) return(NX_ERROR);
    NXopendata (f, tag);
    if (strlen(format) < CHAR_BUF_LENGTH)
      ret = NXputdata  (f, value);
    else
      ret = NXputdata  (f, format);
    NXclosedata(f);
  } else {
    if (strlen(format) < CHAR_BUF_LENGTH)
      ret = NXputattr  (f, tag, value, strlen(value), NX_CHAR);
    else
      ret = NXputattr  (f, tag, format, strlen(format), NX_CHAR);
  }

  return(ret);

} /* nxstr */

/*******************************************************************************
* mcinfo_readfile: read a full file into a string buffer which is allocated
*   Think to free the buffer after use.
* Used in: mcinfo_out_nexus (nexus)
*******************************************************************************/
char *mcinfo_readfile(char *filename)
{
  FILE *f = fopen(filename, "rb");
  if (!f) return(NULL);
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  rewind(f);
  char *string = malloc(fsize + 1);
  if (string) {
    int n = fread(string, fsize, 1, f);
    fclose(f);

    string[fsize] = 0;
  }
  return(string);
}

/*******************************************************************************
* mcinfo_out: output instrument/simulation groups in NeXus file
* Used in: siminfo_init (nexus)
*******************************************************************************/
static void mcinfo_out_nexus(NXhandle f)
{
  FILE  *fid;     /* for intrument source code/C/IDF */
  char  *buffer=NULL;
  time_t t     =time(NULL); /* for date */
  char   entry0[CHAR_BUF_LENGTH];
  int    count=0;
  char   name[CHAR_BUF_LENGTH];
  char   class[CHAR_BUF_LENGTH];

  if (!f || mcdisable_output_files) return;

  /* write NeXus NXroot attributes */
  /* automatically added: file_name, HDF5_Version, file_time, NeXus_version */
  nxprintattr(f, "creator",   "%s generated with " MCCODE_STRING, instrument_name);

  /* count the number of existing NXentry and create the next one */
  NXgetgroupinfo(f, &count, name, class);
  sprintf(entry0, "entry%i", count+1);

  /* create the main NXentry (mandatory in NeXus) */
  if (NXmakegroup(f, entry0, "NXentry") == NX_OK)
  if (NXopengroup(f, entry0, "NXentry") == NX_OK) {

    nxprintf(nxhandle, "program_name", MCCODE_STRING);
    nxprintf(f, "start_time", ctime(&t));
    nxprintf(f, "title", "%s%s%s simulation generated by instrument %s",
      dirname && strlen(dirname) ? dirname : ".", MC_PATHSEP_S, siminfo_name,
      instrument_name);
    nxprintattr(f, "program_name", MCCODE_STRING);
    nxprintattr(f, "instrument",   instrument_name);
    nxprintattr(f, "simulation",   "%s%s%s",
        dirname && strlen(dirname) ? dirname : ".", MC_PATHSEP_S, siminfo_name);

    /* write NeXus instrument group */
    if (NXmakegroup(f, "instrument", "NXinstrument") == NX_OK)
    if (NXopengroup(f, "instrument", "NXinstrument") == NX_OK) {
      int   i;
      char *string=NULL;

      /* write NeXus parameters(types) data =================================== */
      string = (char*)malloc(CHAR_BUF_LENGTH);
      if (string) {
        strcpy(string, "");
        for(i = 0; i < numipar; i++)
        {
          char ThisParam[CHAR_BUF_LENGTH];
          snprintf(ThisParam, CHAR_BUF_LENGTH, " %s(%s)", mcinputtable[i].name,
                  (*mcinputtypes[mcinputtable[i].type].parminfo)
                      (mcinputtable[i].name));
          if (strlen(string) + strlen(ThisParam) < CHAR_BUF_LENGTH)
            strcat(string, ThisParam);
        }
        nxprintattr(f, "Parameters",    string);
        free(string);
      }

      nxprintattr(f, "name",          instrument_name);
      nxprintf   (f, "name",          instrument_name);
      nxprintattr(f, "Source",        instrument_source);

      nxprintattr(f, "Trace_enabled", traceenabled ? "yes" : "no");
      nxprintattr(f, "Default_main",  defaultmain ?  "yes" : "no");
      nxprintattr(f, "Embedded_runtime",
  #ifdef MC_EMBEDDED_RUNTIME
           "yes"
  #else
           "no"
  #endif
           );

      /* add instrument source code when available */
      buffer = mcinfo_readfile(instrument_source);
      if (buffer && strlen(buffer)) {
        long length=strlen(buffer);
        nxprintf (f, "description", buffer);
        NXopendata(f,"description");
        nxprintattr(f, "file_name", instrument_source);
        nxprintattr(f, "file_size", "%li", length);
        nxprintattr(f, "MCCODE_STRING", MCCODE_STRING);
        NXclosedata(f);
        nxprintf (f,"instrument_source", "%s " MCCODE_NAME " " MCCODE_PARTICLE " Monte Carlo simulation", instrument_name);
        free(buffer);
      } else
        nxprintf (f, "description", "File %s not found (instrument description %s is missing)",
          instrument_source, instrument_name);

      /* add Mantid/IDF.xml when available */
      char *IDFfile=NULL;
      IDFfile = (char*)malloc(CHAR_BUF_LENGTH);
      sprintf(IDFfile,"%s%s",instrument_source,".xml");
      buffer = mcinfo_readfile(IDFfile);
      if (buffer && strlen(buffer)) {
        NXmakegroup (nxhandle, "instrument_xml", "NXnote");
        NXopengroup (nxhandle, "instrument_xml", "NXnote");
        nxprintf(f, "data", buffer);
        nxprintf(f, "description", "IDF.xml file found with instrument %s", instrument_source);
        nxprintf(f, "type", "text/xml");
        NXclosegroup(f); /* instrument_xml */
        free(buffer);
      }
      free(IDFfile);
      NXclosegroup(f); /* instrument */
    } /* NXinstrument */

    /* write NeXus simulation group */
    if (NXmakegroup(f, "simulation", "NXnote") == NX_OK)
    if (NXopengroup(f, "simulation", "NXnote") == NX_OK) {

      nxprintattr(f, "name",   "%s%s%s",
        dirname && strlen(dirname) ? dirname : ".", MC_PATHSEP_S, siminfo_name);

      nxprintf   (f, "name",      "%s",     siminfo_name);
      nxprintattr(f, "Format",    mcformat && strlen(mcformat) ? mcformat : MCCODE_NAME);
      nxprintattr(f, "URL",       "http://www.mccode.org");
      nxprintattr(f, "program",   MCCODE_STRING);
      nxprintattr(f, "Instrument",instrument_source);
      nxprintattr(f, "Trace",     mcdotrace ?     "yes" : "no");
      nxprintattr(f, "Gravitation",mcgravitation ? "yes" : "no");
      nxprintattr(f, "Seed",      "%li", mcseed);
      nxprintattr(f, "Directory", dirname);
    #ifdef USE_MPI
      if (mpi_node_count > 1)
        nxprintf(f, "Nodes", "%i",        mpi_node_count);
    #endif

      /* output parameter string ================================================ */
      if (NXmakegroup(f, "Param", "NXparameters") == NX_OK)
      if (NXopengroup(f, "Param", "NXparameters") == NX_OK) {
        int i;
        char string[CHAR_BUF_LENGTH];
        for(i = 0; i < numipar; i++) {
          if (mcget_run_num() || (mcinputtable[i].val && strlen(mcinputtable[i].val))) {
            if (mcinputtable[i].par == NULL)
              strncpy(string, (mcinputtable[i].val ? mcinputtable[i].val : ""), CHAR_BUF_LENGTH);
            else
              (*mcinputtypes[mcinputtable[i].type].printer)(string, mcinputtable[i].par);

            nxprintf(f,  mcinputtable[i].name, "%s", string);
            nxprintattr(f, mcinputtable[i].name, string);
          }
        }
        NXclosegroup(f); /* Param */
      } /* NXparameters */

      NXclosegroup(f); /* simulation */
    } /* NXsimulation */

    /* create a group to hold all monitors */
    NXmakegroup(f, "data", "NXdetector");

    /* leave the NXentry opened (closed at exit) */
  } /* NXentry */
} /* mcinfo_out_nexus */

/*******************************************************************************
* mcdatainfo_out_nexus: output detector header
*   mcdatainfo_out_nexus(detector) create group and write info to NeXus data file
*   open data:NXdetector then filename:NXdata and write headers/attributes
*   requires: NXentry to be opened
*******************************************************************************/
static void
mcdatainfo_out_nexus(NXhandle f, MCDETECTOR detector)
{
  char data_name[CHAR_BUF_LENGTH];
  if (!f || !detector.m || mcdisable_output_files) return;

  strcpy_valid(data_name,
    detector.filename && strlen(detector.filename) ?
      detector.filename : detector.component);

  /* the NXdetector group has been created in mcinfo_out_nexus (siminfo_init) */
  if (NXopengroup(f, "data", "NXdetector") == NX_OK) {

    /* create and open the data group */
    /* this may fail when appending to list -> ignore/skip */
    NXMDisableErrorReporting(); /* unactivate NeXus error messages, as creation may fail */

    if (NXmakegroup(f, data_name, "NXdata") == NX_OK)
    if (NXopengroup(f, data_name, "NXdata") == NX_OK) {

      /* output metadata (as attributes) ======================================== */
      nxprintattr(f, "Date",       detector.date);
      nxprintattr(f, "type",       detector.type);
      nxprintattr(f, "Source",     detector.instrument);
      nxprintattr(f, "component",  detector.component);
      nxprintattr(f, "position",   detector.position);

      nxprintattr(f, "title",      detector.title);
      nxprintattr(f, !mcget_run_num() || mcget_run_num() >= mcget_ncount() ?
                 "Ncount" :
                 "ratio",  detector.ncount);

      if (strlen(detector.filename)) {
        nxprintattr(f, "filename", detector.filename);
      }

      nxprintattr(f, "statistics", detector.statistics);
      nxprintattr(f, "signal",     detector.signal);
      nxprintattr(f, "values",     detector.values);

      if (detector.rank >= 1)
      {
        nxprintattr(f, "xvar",     detector.xvar);
        nxprintattr(f, "yvar",     detector.yvar);
        nxprintattr(f, "xlabel",   detector.xlabel);
        nxprintattr(f, "ylabel",   detector.ylabel);
        if (detector.rank > 1) {
          nxprintattr(f, "zvar",   detector.zvar);
          nxprintattr(f, "zlabel", detector.zlabel);
        }
      }

      nxprintattr(f, abs(detector.rank)==1 ?
                 "xlimits" :
                 "xylimits", detector.limits);
      nxprintattr(f, "variables",
        strcasestr(detector.format, "list") ? detector.ylabel : detector.variables);
      nxprintf(f, "distance", detector.position);
      nxprintf(f, "acquisition_mode",
        strcasestr(detector.format, "list") ? "event" : "summed");

      NXclosegroup(f);
    } /* NXdata (filename) */
    NXMEnableErrorReporting();  /* re-enable NeXus error messages */
    NXclosegroup(f);
  } /* NXdetector (data) */

} /* mcdatainfo_out_nexus */

/*******************************************************************************
* mcdetector_out_axis_nexus: write detector axis into current NXdata
*   requires: NXdata to be opened
*******************************************************************************/
int mcdetector_out_axis_nexus(NXhandle f, char *label, char *var, int rank, long length, double min, double max)
{
  if (!f || length <= 1 || mcdisable_output_files || max == min) return(NX_OK);
  else {
    double axis[length];
    char valid[CHAR_BUF_LENGTH];
    int dim=(int)length;
    int i;
    int nprimary=1;
    /* create an axis from [min:max] */
    for(i = 0; i < length; i++)
      axis[i] = min+(max-min)*(i+0.5)/length;
    /* create the data set */
    strcpy_valid(valid, label);
    NXcompmakedata(f, valid, NX_FLOAT64, 1, &dim, NX_COMPRESSION, &dim);
    /* open it */
    if (NXopendata(f, valid) != NX_OK) {
      fprintf(stderr, "Warning: could not open axis rank %i '%s' (NeXus)\n",
        rank, valid);
      return(NX_ERROR);
    }
    /* put the axis and its attributes */
    NXputdata  (f, axis);
    nxprintattr(f, "long_name",  label);
    nxprintattr(f, "short_name", var);
    NXputattr  (f, "axis",       &rank,     1, NX_INT32);
    nxprintattr(f, "units",      var);
    NXputattr  (f, "primary",    &nprimary, 1, NX_INT32);
    NXclosedata(f);

    return(NX_OK);
  }
} /* mcdetector_out_axis_nexus */

/*******************************************************************************
* mcdetector_out_array_nexus: write detector array into current NXdata (1D,2D)
*   requires: NXdata to be opened
*******************************************************************************/
int mcdetector_out_array_nexus(NXhandle f, char *part, double *data, MCDETECTOR detector)
{

  int64_t dims[3]={detector.m,detector.n,detector.p};  /* number of elements to write */
  int64_t fulldims[3]={detector.m,detector.n,detector.p};
  int signal=1;
  int exists=0;
  int64_t current_dims[3]={0,0,0};
  int ret=NX_OK;

  if (!f || !data || !detector.m || mcdisable_output_files) return(NX_OK);

  /* when this is a list, we set 1st dimension to NX_UNLIMITED for creation */
  if (strcasestr(detector.format, "list")) fulldims[0] = NX_UNLIMITED;

  /* create the data set in NXdata group */
  NXMDisableErrorReporting(); /* unactivate NeXus error messages, as creation may fail */
  ret = NXcompmakedata64(f, part, NX_FLOAT64, detector.rank, fulldims, NX_COMPRESSION, dims);
  if (ret != NX_OK) {
    /* failed: data set already exists */
    int datatype=0;
    int rank=0;
    exists=1;
    /* inquire current size of data set (nb of events stored) */
    NXopendata(f, part);
    NXgetinfo64(f, &rank, current_dims, &datatype);
    NXclosedata(f);
  }
  NXMEnableErrorReporting();  /* re-enable NeXus error messages */

  /* open the data set */
  if (NXopendata(f, part) == NX_ERROR) {
    fprintf(stderr, "Warning: could not open DataSet %s '%s' (NeXus)\n",
      part, detector.title);
    return(NX_ERROR);
  }
  if (strcasestr(detector.format, "list")) {
    current_dims[1] = current_dims[2] = 0; /* set starting location for writing slab */
    NXputslab64(f, data, current_dims, dims);
    if (!exists)
      printf("Events:   \"%s\"\n",
        strlen(detector.filename) ? detector.filename : detector.component);
    else
      printf("Append:   \"%s\"\n",
	     strlen(detector.filename) ? detector.filename : detector.component);
  } else {
    NXputdata (f, data);
  }

  if (strstr(part,"data") || strstr(part, "events")) {
    NXputattr(f, "signal", &signal, 1, NX_INT32);
    nxprintattr(f, "short_name", detector.filename && strlen(detector.filename) ?
      detector.filename : detector.component);
  }
  nxprintattr(f, "long_name", "%s '%s'", part, detector.title);
  NXclosedata(f);

  return(NX_OK);
} /* mcdetector_out_array_nexus */

/*******************************************************************************
* mcdetector_out_data_nexus: write detector axes+data into current NXdata
*   The data:NXdetector is opened, then filename:NXdata
*   requires: NXentry to be opened
*******************************************************************************/
int mcdetector_out_data_nexus(NXhandle f, MCDETECTOR detector)
{
  char data_name[CHAR_BUF_LENGTH];

  if (!f || !detector.m || mcdisable_output_files) return(NX_OK);

  strcpy_valid(data_name,
    detector.filename && strlen(detector.filename) ?
      detector.filename : detector.component);

  /* the NXdetector group has been created in mcinfo_out_nexus (siminfo_init) */
  if (NXopengroup(f, "data", "NXdetector") == NX_OK) {

    /* the NXdata group has been created in mcdatainfo_out_nexus */
    if (NXopengroup(f, data_name, "NXdata") == NX_OK) {

      /* write axes, for histogram data sets, not for lists */
      if (!strcasestr(detector.format, "list")) {
        mcdetector_out_axis_nexus(f, detector.xlabel, detector.xvar,
          1, detector.m, detector.xmin, detector.xmax);

        mcdetector_out_axis_nexus(f, detector.ylabel, detector.yvar,
          2, detector.n, detector.ymin, detector.ymax);

        mcdetector_out_axis_nexus(f, detector.zlabel, detector.zvar,
          3, detector.p, detector.zmin, detector.zmax);

      } /* !list */

      /* write the actual data (appended if already exists) */
      if (!strcasestr(detector.format, "list")) {
        mcdetector_out_array_nexus(f, "data", detector.p1, detector);
        mcdetector_out_array_nexus(f, "errors", detector.p2, detector);
        mcdetector_out_array_nexus(f, "ncount", detector.p0, detector);
      } else
        mcdetector_out_array_nexus(  f, "events", detector.p1, detector);

      NXclosegroup(f);
    } /* NXdata */
    NXclosegroup(f);
  } /* NXdetector */

  return(NX_OK);
} /* mcdetector_out_array_nexus */

#ifdef USE_MPI
/*******************************************************************************
* mcdetector_out_list_slaves: slaves send their list data to master which writes
*   requires: NXentry to be opened
* WARNING: this method has a flaw: it requires all nodes to flush the lists
*   the same number of times. In case one node is just below the buffer size
*   when finishing (e.g. monitor_nd), it may not trigger save but others may.
*   Then the number of recv/send is not constant along nodes, and simulation stalls.
*******************************************************************************/
MCDETECTOR mcdetector_out_list_slaves(MCDETECTOR detector)
{
  int     node_i=0;
  MPI_MASTER(
	     printf("\n** MPI master gathering slave node list data ** \n");
  );

  if (mpi_node_rank != mpi_node_root) {
    /* MPI slave: slaves send their data to master: 2 MPI_Send calls */
    /* m, n, p must be sent first, since all slaves do not have the same number of events */
    int mnp[3]={detector.m,detector.n,detector.p};

    if (mc_MPI_Send(mnp, 3, MPI_INT, mpi_node_root)!= MPI_SUCCESS)
      fprintf(stderr, "Warning: proc %i to master: MPI_Send mnp list error (mcdetector_out_list_slaves)\n", mpi_node_rank);
    if (!detector.p1
     || mc_MPI_Send(detector.p1, mnp[0]*mnp[1]*mnp[2], MPI_DOUBLE, mpi_node_root) != MPI_SUCCESS)
      fprintf(stderr, "Warning: proc %i to master: MPI_Send p1 list error: mnp=%i (mcdetector_out_list_slaves)\n", mpi_node_rank, abs(mnp[0]*mnp[1]*mnp[2]));
    /* slaves are done: sent mnp and p1 */
    return (detector);
  } /* end slaves */

  /* MPI master: receive data from slaves sequentially: 2 MPI_Recv calls */

  if (mpi_node_rank == mpi_node_root) {
    for(node_i=0; node_i<mpi_node_count; node_i++) {
      double *this_p1=NULL;                               /* buffer to hold the list from slaves */
      int     mnp[3]={0,0,0};  /* size of this buffer */
      if (node_i != mpi_node_root) { /* get data from slaves */
	if (mc_MPI_Recv(mnp, 3, MPI_INT, node_i) != MPI_SUCCESS)
	  fprintf(stderr, "Warning: master from proc %i: "
		  "MPI_Recv mnp list error (mcdetector_write_data)\n", node_i);
	if (mnp[0]*mnp[1]*mnp[2]) {
	  this_p1 = (double *)calloc(mnp[0]*mnp[1]*mnp[2], sizeof(double));
	  if (!this_p1 || mc_MPI_Recv(this_p1, abs(mnp[0]*mnp[1]*mnp[2]), MPI_DOUBLE, node_i)!= MPI_SUCCESS)
	    fprintf(stderr, "Warning: master from proc %i: "
		    "MPI_Recv p1 list error: mnp=%i (mcdetector_write_data)\n", node_i, mnp[0]*mnp[1]*mnp[2]);
	  else {
	    printf(". MPI master writing data for slave node %i\n",node_i);
	    detector.p1 = this_p1;
	    detector.m  = mnp[0]; detector.n  = mnp[1]; detector.p  = mnp[2];

	    mcdetector_out_data_nexus(nxhandle, detector);
	  }
	}
      } /* if not master */
      free(this_p1);
    } /* for */
  MPI_MASTER(
	     printf("\n** Done ** \n");
  );
  }
}
#endif

MCDETECTOR mcdetector_out_0D_nexus(MCDETECTOR detector)
{
  /* Write data set information to NeXus file. */
  MPI_MASTER(
    mcdatainfo_out_nexus(nxhandle, detector);
  );

  return(detector);
} /* mcdetector_out_0D_ascii */

MCDETECTOR mcdetector_out_1D_nexus(MCDETECTOR detector)
{
  MPI_MASTER(
  mcdatainfo_out_nexus(nxhandle, detector);
  mcdetector_out_data_nexus(nxhandle, detector);
  );
  return(detector);
} /* mcdetector_out_1D_ascii */

MCDETECTOR mcdetector_out_2D_nexus(MCDETECTOR detector)
{
  MPI_MASTER(
  mcdatainfo_out_nexus(nxhandle, detector);
  mcdetector_out_data_nexus(nxhandle, detector);
  );

#ifdef USE_MPI // and USE_NEXUS
  /* NeXus: slave nodes have master write their lists */
  if (strcasestr(detector.format, "list") && mpi_node_count > 1) {
    mcdetector_out_list_slaves(detector);
  }
#endif /* USE_MPI */

  return(detector);
} /* mcdetector_out_2D_nexus */

#endif /* USE_NEXUS*/








/* ========================================================================== */

/*                            Main input functions                            */
/*            DETECTOR_OUT_xD function calls -> ascii or NeXus                */

/* ========================================================================== */

/*******************************************************************************
* siminfo_init:   open SIM and write header
*******************************************************************************/
FILE *siminfo_init(FILE *f)
{
  int exists=0;

  /* check format */
  if (!mcformat || !strlen(mcformat)
   || !strcasecmp(mcformat, "MCSTAS") || !strcasecmp(mcformat, "MCXTRACE")
   || !strcasecmp(mcformat, "PGPLOT") || !strcasecmp(mcformat, "GNUPLOT") || !strcasecmp(mcformat, "MCCODE")
   || !strcasecmp(mcformat, "MATLAB")) {
    mcformat="McCode";
#ifdef USE_NEXUS
  } else if (strcasestr(mcformat, "NeXus")) {
    /* Do nothing */
#endif
  } else {
    fprintf(stderr,
	    "Warning: You have requested the output format %s which is unsupported by this binary. Resetting to standard %s format.\n",mcformat ,"McCode");
    mcformat="McCode";
  }

  /* open the SIM file if not defined yet */
  if (siminfo_file || mcdisable_output_files)
    return (siminfo_file);

#ifdef USE_NEXUS
  /* only master writes NeXus header: calls NXopen(nxhandle) */
  if (mcformat && strcasestr(mcformat, "NeXus")) {
	  MPI_MASTER(
	  siminfo_file = mcnew_file(siminfo_name, "h5", &exists);
    if(!siminfo_file)
      fprintf(stderr,
	      "Warning: could not open simulation description file '%s'\n",
	      siminfo_name);
	  else
	    mcinfo_out_nexus(nxhandle);
	  );
    return(siminfo_file); /* points to nxhandle */
  }
#endif

  /* write main description file (only MASTER) */
  MPI_MASTER(

  siminfo_file = mcnew_file(siminfo_name, "sim", &exists);
  if(!siminfo_file)
    fprintf(stderr,
	    "Warning: could not open simulation description file '%s'\n",
	    siminfo_name);
  else
  {
    /* write SIM header */
    time_t t=time(NULL);
    siminfo_out("%s simulation description file for %s.\n",
      MCCODE_NAME, instrument_name);
    siminfo_out("Date:    %s", ctime(&t)); /* includes \n */
    siminfo_out("Program: %s\n\n", MCCODE_STRING);

    siminfo_out("begin instrument: %s\n", instrument_name);
    mcinfo_out(   "  ", siminfo_file);
    siminfo_out("end instrument\n");

    siminfo_out("\nbegin simulation: %s\n", dirname);
    mcruninfo_out("  ", siminfo_file);
    siminfo_out("end simulation\n");

  }
  return (siminfo_file);

  ); /* MPI_MASTER */

} /* siminfo_init */

/*******************************************************************************
*   siminfo_close:  close SIM
*******************************************************************************/
void siminfo_close()
{
#ifdef USE_MPI
  if(mpi_node_rank == mpi_node_root) {
#endif
  if(siminfo_file && !mcdisable_output_files) {
#ifdef USE_NEXUS
    if (mcformat && strcasestr(mcformat, "NeXus")) {
      time_t t=time(NULL);
      nxprintf(nxhandle, "end_time", ctime(&t));
      nxprintf(nxhandle, "duration", "%li", (long)t-mcstartdate);
      NXclosegroup(nxhandle); /* NXentry */
      NXclose(&nxhandle);
    } else {
#endif
      fclose(siminfo_file);
#ifdef USE_NEXUS
    }
#endif
#ifdef USE_MPI
  }
#endif
    siminfo_file = NULL;
  }
} /* siminfo_close */

/*******************************************************************************
* mcdetector_out_0D: wrapper for 0D (single value).
*   Output single detector/monitor data (p0, p1, p2).
*   Title is t, component name is c.
*******************************************************************************/
MCDETECTOR mcdetector_out_0D(char *t, double p0, double p1, double p2,
                         char *c, Coords posa)
{
  /* import and perform basic detector analysis (and handle MPI reduce) */
  MCDETECTOR detector = detector_import(mcformat,
    c, (t ? t : MCCODE_STRING " data"),
    1, 1, 1,
    "I", "", "",
    "I", "", "",
    0, 0, 0, 0, 0, 0, "",
    &p0, &p1, &p2, posa); /* write Detector: line */

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    return(mcdetector_out_0D_nexus(detector));
  else
#endif
    return(mcdetector_out_0D_ascii(detector));

} /* mcdetector_out_0D */



/*******************************************************************************
* mcdetector_out_1D: wrapper for 1D.
*   Output 1d detector data (p0, p1, p2) for n bins linearly
*   distributed across the range x1..x2 (x1 is lower limit of first
*   bin, x2 is upper limit of last bin). Title is t, axis labels are xl
*   and yl. File name is f, component name is c.
*
*   t:    title
*   xl:   x-label
*   yl:   y-label
*   xvar: measured variable length
*   x1:   x axus min
*   x2:   x axis max
*   n:    1d data vector lenght
*   p0:   pntr to start of data block#0
*   p1:   pntr to start of data block#1
*   p2:   pntr to start of data block#2
*   f:    filename
*
*   Not included in the macro, and here forwarded to detector_import:
*   c:    ?
*   posa: ?
*******************************************************************************/
MCDETECTOR mcdetector_out_1D(char *t, char *xl, char *yl,
        char *xvar, double x1, double x2,
        long n,
        double *p0, double *p1, double *p2, char *f,
        char *c, Coords posa)
{
  /* import and perform basic detector analysis (and handle MPI_Reduce) */
  // detector_import calls mcdetector_statistics, which will return different
  // MCDETECTOR versions for 1-D data based on the value of mcformat.
  //
  MCDETECTOR detector = detector_import(mcformat,
    c, (t ? t : MCCODE_STRING " 1D data"),
    n, 1, 1,
    xl, yl, (n > 1 ? "Signal per bin" : " Signal"),
    xvar, "(I,I_err)", "I",
    x1, x2, 0, 0, 0, 0, f,
    p0, p1, p2, posa); /* write Detector: line */
  if (!detector.p1 || !detector.m) return(detector);

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    detector = mcdetector_out_1D_nexus(detector);
  else
#endif
    detector = mcdetector_out_1D_ascii(detector);
  if (detector.p1 != p1 && detector.p1) {
    // mcdetector_statistics allocated memory but it hasn't been freed.
    free(detector.p1);
    // plus undo the other damage done there:
    detector.p0 = p0; // was set to NULL
    detector.p1 = p1; // was set to this_p1
    detector.p2 = p2; // was set to NULL
    detector.m = detector.n; // (e.g., labs(n))
    detector.n = 1;  // not (n x n)
    detector.istransposed = n < 0 ? 1 : 0;
  }
  return detector;

} /* mcdetector_out_1D */

/*******************************************************************************
* mcdetector_out_2D: wrapper for 2D.
*   Special case for list: master creates file first, then slaves append their
*   blocks without header-
*
*   t:    title
*   xl:   x-label
*   yl:   y-label
*   x1:   x axus min
*   x2:   x axis max
*   y1:   y axis min
*   y2:   y axis max
*   m:    dim 1 (x) size
*   n:    dim 2 (y) size
*   p0:   pntr to start of data block#0
*   p1:   pntr to start of data block#1
*   p2:   pntr to start of data block#2
*   f:    filename
*
*   Not included in the macro, and here forwarded to detector_import:
*   c:    ?
*   posa: ?
*******************************************************************************/
MCDETECTOR mcdetector_out_2D(char *t, char *xl, char *yl,
                  double x1, double x2, double y1, double y2,
                  long m, long n,
                  double *p0, double *p1, double *p2, char *f,
                  char *c, Coords posa)
{
  char xvar[CHAR_BUF_LENGTH];
  char yvar[CHAR_BUF_LENGTH];

  /* create short axes labels */
  if (xl && strlen(xl)) { strncpy(xvar, xl, CHAR_BUF_LENGTH); xvar[2]='\0'; }
  else strcpy(xvar, "x");
  if (yl && strlen(yl)) { strncpy(yvar, yl, CHAR_BUF_LENGTH); yvar[2]='\0'; }
  else strcpy(yvar, "y");

  MCDETECTOR detector;

  /* import and perform basic detector analysis (and handle MPI_Reduce) */
  if (labs(m) == 1) {/* n>1 on Y, m==1 on X: 1D, no X axis*/
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 1D data"),
      n, 1, 1,
      yl, "", "Signal per bin",
      yvar, "(I,Ierr)", "I",
      y1, y2, x1, x2, 0, 0, f,
      p0, p1, p2, posa); /* write Detector: line */
  } else if (labs(n)==1) {/* m>1 on X, n==1 on Y: 1D, no Y axis*/
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 1D data"),
      m, 1, 1,
      xl, "", "Signal per bin",
      xvar, "(I,Ierr)", "I",
      x1, x2, y1, y2, 0, 0, f,
      p0, p1, p2, posa); /* write Detector: line */
  }else {
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 2D data"),
      m, n, 1,
      xl, yl, "Signal per bin",
      xvar, yvar, "I",
      x1, x2, y1, y2, 0, 0, f,
      p0, p1, p2, posa); /* write Detector: line */
  }

  if (!detector.p1 || !detector.m) return(detector);

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    return(mcdetector_out_2D_nexus(detector));
  else
#endif
    return(mcdetector_out_2D_ascii(detector));

} /* mcdetector_out_2D */

/*******************************************************************************
* mcdetector_out_list: wrapper for list output (calls out_2D with mcformat+"list").
*   m=number of events, n=size of each event
*******************************************************************************/
MCDETECTOR mcdetector_out_list(char *t, char *xl, char *yl,
                  long m, long n,
                  double *p1, char *f,
                  char *c, Coords posa)
{
  char       format_new[CHAR_BUF_LENGTH];
  char      *format_org;
  MCDETECTOR detector;

  format_org = mcformat;
  strcpy(format_new, mcformat);
  strcat(format_new, " list");
  mcformat = format_new;

  detector = mcdetector_out_2D(t, xl, yl,
                  1,labs(m),1,labs(n),
                  m,n,
                  NULL, p1, NULL, f,
                  c, posa);

  mcformat = format_org;
  return(detector);
}

/*******************************************************************************
 * mcuse_dir: set data/sim storage directory and create it,
 * or exit with error if exists
 ******************************************************************************/
static void
mcuse_dir(char *dir)
{
  if (!dir || !strlen(dir)) return;
#ifdef MC_PORTABLE
  fprintf(stderr, "Error: "
          "Directory output cannot be used with portable simulation (mcuse_dir)\n");
  exit(1);
#else  /* !MC_PORTABLE */
  /* handle file://directory URL type */
  if (strncmp(dir, "file://", strlen("file://")))
    dirname = dir;
  else
    dirname = dir+strlen("file://");


#ifdef USE_MPI
  if(mpi_node_rank == mpi_node_root) {
#endif
    if(mkdir(dirname, 0777)) {
#ifndef DANSE
      fprintf(stderr, "Error: unable to create directory '%s' (mcuse_dir)\n", dir);
      fprintf(stderr, "(Maybe the directory already exists?)\n");
#endif
#ifdef USE_MPI
      MPI_Abort(MPI_COMM_WORLD, -1);
#endif
    exit(-1);
    }
#ifdef USE_MPI
    }
#endif

  /* remove trailing PATHSEP (if any) */
  while (strlen(dirname) && dirname[strlen(dirname) - 1] == MC_PATHSEP_C)
    dirname[strlen(dirname) - 1]='\0';
#endif /* !MC_PORTABLE */
} /* mcuse_dir */

/*******************************************************************************
* mcinfo: display instrument simulation info to stdout and exit
*******************************************************************************/
static void
mcinfo(void)
{
  fprintf(stdout, "begin instrument: %s\n", instrument_name);
  mcinfo_out("  ", stdout);
  fprintf(stdout, "end instrument\n");
  fprintf(stdout, "begin simulation: %s\n", dirname ? dirname : ".");
  mcruninfo_out("  ", stdout);
  fprintf(stdout, "end simulation\n");
  exit(0); /* includes MPI_Finalize in MPI mode */
} /* mcinfo */

/*******************************************************************************
* mcparameterinfo: display instrument parameter info to stdout and exit
*******************************************************************************/
static void
mcparameterinfo(void)
{
  mcparameterinfo_out("  ", stdout);
  exit(0); /* includes MPI_Finalize in MPI mode */
} /* mcparameterinfo */



#endif /* ndef MCCODE_R_IO_C */

/* end of the I/O section =================================================== */







/*******************************************************************************
* mcset_ncount: set total number of rays to generate
*******************************************************************************/
void mcset_ncount(unsigned long long int count)
{
  mcncount = count;
}

/* mcget_ncount: get total number of rays to generate */
unsigned long long int mcget_ncount(void)
{
  return mcncount;
}

/* mcget_run_num: get curent number of rays */
/* Within the TRACE scope we are now using _particle->uid directly */
unsigned long long int mcget_run_num() // shuld be (_class_particle* _particle) somehow
{
  /* This function only remains for the few cases outside TRACE where we need to know
     the number of simulated particles */
  return mcrun_num;
}

/* mcsetn_arg: get ncount from a string argument */
static void
mcsetn_arg(char *arg)
{
  mcset_ncount((long long int) strtod(arg, NULL));
}

/* mcsetseed: set the random generator seed from a string argument */
static void
mcsetseed(char *arg)
{
  mcseed = atol(arg);
  if(!mcseed) {
  //  srandom(mcseed);
  //} else {
    fprintf(stderr, "Error: seed must not be zero (mcsetseed)\n");
    exit(1);
  }
}

/* Following part is only embedded when not redundent with mccode-r.h ========= */

#ifndef MCCODE_H

/* SECTION: MCDISPLAY support. =============================================== */

/*******************************************************************************
* Just output MCDISPLAY keywords to be caught by an external plotter client.
*******************************************************************************/

void mcdis_magnify(char *what){
  // Do nothing here, better use interactive zoom from the tools
}

void mcdis_line(double x1, double y1, double z1,
                double x2, double y2, double z2){
  printf("MCDISPLAY: multiline(2,%g,%g,%g,%g,%g,%g)\n",
         x1,y1,z1,x2,y2,z2);
}

void mcdis_dashed_line(double x1, double y1, double z1,
		       double x2, double y2, double z2, int n){
  int i;
  const double dx = (x2-x1)/(2*n+1);
  const double dy = (y2-y1)/(2*n+1);
  const double dz = (z2-z1)/(2*n+1);

  for(i = 0; i < n+1; i++)
    mcdis_line(x1 + 2*i*dx,     y1 + 2*i*dy,     z1 + 2*i*dz,
	       x1 + (2*i+1)*dx, y1 + (2*i+1)*dy, z1 + (2*i+1)*dz);
}

void mcdis_multiline(int count, ...){
  va_list ap;
  double x,y,z;

  printf("MCDISPLAY: multiline(%d", count);
  va_start(ap, count);
  while(count--)
    {
    x = va_arg(ap, double);
    y = va_arg(ap, double);
    z = va_arg(ap, double);
    printf(",%g,%g,%g", x, y, z);
    }
  va_end(ap);
  printf(")\n");
}

void mcdis_rectangle(char* plane, double x, double y, double z,
		     double width, double height){
  /* draws a rectangle in the plane           */
  /* x is ALWAYS width and y is ALWAYS height */
  if (strcmp("xy", plane)==0) {
    mcdis_multiline(5,
		    x - width/2, y - height/2, z,
		    x + width/2, y - height/2, z,
		    x + width/2, y + height/2, z,
		    x - width/2, y + height/2, z,
		    x - width/2, y - height/2, z);
  } else if (strcmp("xz", plane)==0) {
    mcdis_multiline(5,
		    x - width/2, y, z - height/2,
		    x + width/2, y, z - height/2,
		    x + width/2, y, z + height/2,
		    x - width/2, y, z + height/2,
		    x - width/2, y, z - height/2);
  } else if (strcmp("yz", plane)==0) {
    mcdis_multiline(5,
		    x, y - height/2, z - width/2,
		    x, y - height/2, z + width/2,
		    x, y + height/2, z + width/2,
		    x, y + height/2, z - width/2,
		    x, y - height/2, z - width/2);
  } else {

    fprintf(stderr, "Error: Definition of plane %s unknown\n", plane);
    exit(1);
  }
}

/*  draws a box with center at (x, y, z) and
    width (deltax), height (deltay), length (deltaz) */
void mcdis_box(double x, double y, double z,
	       double width, double height, double length){

  mcdis_rectangle("xy", x, y, z-length/2, width, height);
  mcdis_rectangle("xy", x, y, z+length/2, width, height);
  mcdis_line(x-width/2, y-height/2, z-length/2,
	     x-width/2, y-height/2, z+length/2);
  mcdis_line(x-width/2, y+height/2, z-length/2,
	     x-width/2, y+height/2, z+length/2);
  mcdis_line(x+width/2, y-height/2, z-length/2,
	     x+width/2, y-height/2, z+length/2);
  mcdis_line(x+width/2, y+height/2, z-length/2,
	     x+width/2, y+height/2, z+length/2);
}

void mcdis_circle(char *plane, double x, double y, double z, double r){
  printf("MCDISPLAY: circle('%s',%g,%g,%g,%g)\n", plane, x, y, z, r);
}

/* Draws a circle with center (x,y,z), radius (r), and in the plane
 * with normal (nx,ny,nz)*/
void mcdis_Circle(double x, double y, double z, double r, double nx, double ny, double nz){
    int i;
    if(nx==0 && ny && nz==0){
        for (i=0;i<24; i++){
            mcdis_line(x+r*sin(i*2*PI/24),y,z+r*cos(i*2*PI/24),
                    x+r*sin((i+1)*2*PI/24),y,z+r*cos((i+1)*2*PI/24));
        }
    }else{
        double mx,my,mz;
        /*generate perpendicular vector using (nx,ny,nz) and (0,1,0)*/
        vec_prod(mx,my,mz, 0,1,0, nx,ny,nz);
        NORM(mx,my,mz);
        /*draw circle*/
        for (i=0;i<24; i++){
            double ux,uy,uz;
            double wx,wy,wz;
            rotate(ux,uy,uz, mx,my,mz, i*2*PI/24, nx,ny,nz);
            rotate(wx,wy,wz, mx,my,mz, (i+1)*2*PI/24, nx,ny,nz);
            mcdis_line(x+ux*r,y+uy*r,z+uz*r,
                    x+wx*r,y+wy*r,z+wz*r);
        }
    }
}

/* Draws a cylinder with center at (x,y,z) with extent (r,height).
 * The cylinder axis is along the vector nx,ny,nz.
 * N determines how many vertical lines are drawn.*/
void mcdis_cylinder( double x, double y, double z,
        double r, double height, int N, double nx, double ny, double nz){
    int i;
    /*no lines make little sense - so trigger the default*/
    if(N<=0) N=5;

    NORM(nx,ny,nz);
    double h_2=height/2.0;
    mcdis_Circle(x+nx*h_2,y+ny*h_2,z+nz*h_2,r,nx,ny,nz);
    mcdis_Circle(x-nx*h_2,y-ny*h_2,z-nz*h_2,r,nx,ny,nz);

    double mx,my,mz;
    /*generate perpendicular vector using (nx,ny,nz) and (0,1,0)*/
    if(nx==0 && ny && nz==0){
        mx=my=0;mz=1;
    }else{
        vec_prod(mx,my,mz, 0,1,0, nx,ny,nz);
        NORM(mx,my,mz);
    }
    /*draw circle*/
    for (i=0; i<24; i++){
        double ux,uy,uz;
        rotate(ux,uy,uz, mx,my,mz, i*2*PI/24, nx,ny,nz);
        mcdis_line(x+nx*h_2+ux*r, y+ny*h_2+uy*r, z+nz*h_2+uz*r,
                 x-nx*h_2+ux*r, y-ny*h_2+uy*r, z-nz*h_2+uz*r);
    }
}

/* draws a sphere with center at (x,y,z) with extent (r)
 * The sphere is drawn using N longitudes and N latitudes.*/
void mcdis_sphere(double x, double y, double z, double r, int N){
    double nx,ny,nz;
    int i;
    /*no lines make little sense - so trigger the default*/
    if(N<=0) N=5;

    nx=0;ny=0;nz=1;
    mcdis_Circle(x,y,z,r,nx,ny,nz);
    for (i=1;i<N;i++){
        rotate(nx,ny,nz, nx,ny,nz, PI/N, 0,1,0);
        mcdis_Circle(x,y,z,r,nx,ny,nz);
    }
    /*lastly draw a great circle perpendicular to all N circles*/
    //mcdis_Circle(x,y,z,radius,1,0,0);

    for (i=1;i<=N;i++){
        double yy=-r+ 2*r*((double)i/(N+1));
        mcdis_Circle(x,y+yy ,z,  sqrt(r*r-yy*yy) ,0,1,0);
    }
}

/* SECTION: coordinates handling ============================================ */

/*******************************************************************************
* Since we use a lot of geometric calculations using Cartesian coordinates,
* we collect some useful routines here. However, it is also permissible to
* work directly on the underlying struct coords whenever that is most
* convenient (that is, the type Coords is not abstract).
*
* Coordinates are also used to store rotation angles around x/y/z axis.
*
* Since coordinates are used much like a basic type (such as double), the
* structure itself is passed and returned, rather than a pointer.
*
* At compile-time, the values of the coordinates may be unknown (for example
* a motor position). Hence coordinates are general expressions and not simple
* numbers. For this we used the type Coords_exp which has three CExp
* fields. For runtime (or calculations possible at compile time), we use
* Coords which contains three double fields.
*******************************************************************************/

/* coords_set: Assign coordinates. */
Coords coords_set(MCNUM x, MCNUM y, MCNUM z)
{
  Coords a;

  a.x = x;
  a.y = y;
  a.z = z;
  return a;
}

/* coords_get: get coordinates. Required when 'x','y','z' are #defined as ray pars */
Coords coords_get(Coords a, MCNUM *x, MCNUM *y, MCNUM *z)
{
  *x = a.x;
  *y = a.y;
  *z = a.z;
  return a;
}

/* coords_add: Add two coordinates. */
Coords coords_add(Coords a, Coords b)
{
  Coords c;

  c.x = a.x + b.x;
  c.y = a.y + b.y;
  c.z = a.z + b.z;
  if (fabs(c.z) < 1e-14) c.z=0.0;
  return c;
}

/* coords_sub: Subtract two coordinates. */
Coords coords_sub(Coords a, Coords b)
{
  Coords c;

  c.x = a.x - b.x;
  c.y = a.y - b.y;
  c.z = a.z - b.z;
  if (fabs(c.z) < 1e-14) c.z=0.0;
  return c;
}

/* coords_neg: Negate coordinates. */
Coords coords_neg(Coords a)
{
  Coords b;

  b.x = -a.x;
  b.y = -a.y;
  b.z = -a.z;
  return b;
}

/* coords_scale: Scale a vector. */
Coords coords_scale(Coords b, double scale) {
  Coords a;

  a.x = b.x*scale;
  a.y = b.y*scale;
  a.z = b.z*scale;
  return a;
}

/* coords_sp: Scalar product: a . b */
double coords_sp(Coords a, Coords b) {
  double value;

  value = a.x*b.x + a.y*b.y + a.z*b.z;
  return value;
}

/* coords_xp: Cross product: a = b x c. */
Coords coords_xp(Coords b, Coords c) {
  Coords a;

  a.x = b.y*c.z - c.y*b.z;
  a.y = b.z*c.x - c.z*b.x;
  a.z = b.x*c.y - c.x*b.y;
  return a;
}

/* coords_len: Gives length of coords set. */
double coords_len(Coords a) {
  return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

/* coords_mirror: Mirror a in plane (through the origin) defined by normal n*/
Coords coords_mirror(Coords a, Coords n) {
  double t = scalar_prod(n.x, n.y, n.z, n.x, n.y, n.z);
  Coords b;
  if (t!=1) {
    t = sqrt(t);
    n.x /= t;
    n.y /= t;
    n.z /= t;
  }
  t=scalar_prod(a.x, a.y, a.z, n.x, n.y, n.z);
  b.x = a.x-2*t*n.x;
  b.y = a.y-2*t*n.y;
  b.z = a.z-2*t*n.z;
  return b;
}

/* coords_print: Print out vector values. */
void coords_print(Coords a) {
  #ifndef OPENACC
  fprintf(stdout, "(%f, %f, %f)\n", a.x, a.y, a.z);
  #endif
  return;
}

mcstatic void coords_norm(Coords* c) {
	double temp = coords_sp(*c,*c);

	// Skip if we will end dividing by zero
	if (temp == 0) return;

	temp = sqrt(temp);

	c->x /= temp;
	c->y /= temp;
	c->z /= temp;
}

/* coords_test_zero: check if zero vector*/
int coords_test_zero(Coords a){
  return ( a.x==0 && a.y==0 && a.z==0 );
}

/*******************************************************************************
* The Rotation type implements a rotation transformation of a coordinate
* system in the form of a double[3][3] matrix.
*
* Contrary to the Coords type in coords.c, rotations are passed by
* reference. Functions that yield new rotations do so by writing to an
* explicit result parameter; rotations are not returned from functions. The
* reason for this is that arrays cannot by returned from functions (though
* structures can; thus an alternative would have been to wrap the
* double[3][3] array up in a struct). Such are the ways of C programming.
*
* A rotation represents the tranformation of the coordinates of a vector when
* changing between coordinate systems that are rotated with respect to each
* other. For example, suppose that coordinate system Q is rotated 45 degrees
* around the Z axis with respect to coordinate system P. Let T be the
* rotation transformation representing a 45 degree rotation around Z. Then to
* get the coordinates of a vector r in system Q, apply T to the coordinates
* of r in P. If r=(1,0,0) in P, it will be (sqrt(1/2),-sqrt(1/2),0) in
* Q. Thus we should be careful when interpreting the sign of rotation angles:
* they represent the rotation of the coordinate systems, not of the
* coordinates (which has opposite sign).
*******************************************************************************/

/*******************************************************************************
* rot_set_rotation: Get transformation for rotation first phx around x axis,
* then phy around y, then phz around z.
*******************************************************************************/
void rot_set_rotation(Rotation t, double phx, double phy, double phz)
{
  if ((phx == 0) && (phy == 0) && (phz == 0)) {
    t[0][0] = 1.0;
    t[0][1] = 0.0;
    t[0][2] = 0.0;
    t[1][0] = 0.0;
    t[1][1] = 1.0;
    t[1][2] = 0.0;
    t[2][0] = 0.0;
    t[2][1] = 0.0;
    t[2][2] = 1.0;
  } else {
    double cx = cos(phx);
    double sx = sin(phx);
    double cy = cos(phy);
    double sy = sin(phy);
    double cz = cos(phz);
    double sz = sin(phz);

    t[0][0] = cy*cz;
    t[0][1] = sx*sy*cz + cx*sz;
    t[0][2] = sx*sz - cx*sy*cz;
    t[1][0] = -cy*sz;
    t[1][1] = cx*cz - sx*sy*sz;
    t[1][2] = sx*cz + cx*sy*sz;
    t[2][0] = sy;
    t[2][1] = -sx*cy;
    t[2][2] = cx*cy;
  }
}

/*******************************************************************************
* rot_test_identity: Test if rotation is identity
*******************************************************************************/
int rot_test_identity(Rotation t)
{
  return (t[0][0] + t[1][1] + t[2][2] == 3);
}

/*******************************************************************************
* rot_mul: Matrix multiplication of transformations (this corresponds to
* combining transformations). After rot_mul(T1, T2, T3), doing T3 is
* equal to doing first T2, then T1.
* Note that T3 must not alias (use the same array as) T1 or T2.
*******************************************************************************/
void rot_mul(Rotation t1, Rotation t2, Rotation t3)
{
  if (rot_test_identity(t1)) {
    rot_copy(t3, t2);
  } else if (rot_test_identity(t2)) {
    rot_copy(t3, t1);
  } else {
    int i,j;
    for(i = 0; i < 3; i++)
      for(j = 0; j < 3; j++)
	t3[i][j] = t1[i][0]*t2[0][j] + t1[i][1]*t2[1][j] + t1[i][2]*t2[2][j];
  }
}

/*******************************************************************************
* rot_copy: Copy a rotation transformation (arrays cannot be assigned in C).
*******************************************************************************/
void rot_copy(Rotation dest, Rotation src)
{
  int i,j;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      dest[i][j] = src[i][j];
}

/*******************************************************************************
* rot_transpose: Matrix transposition, which is inversion for Rotation matrices
*******************************************************************************/
void rot_transpose(Rotation src, Rotation dst)
{
  dst[0][0] = src[0][0];
  dst[0][1] = src[1][0];
  dst[0][2] = src[2][0];
  dst[1][0] = src[0][1];
  dst[1][1] = src[1][1];
  dst[1][2] = src[2][1];
  dst[2][0] = src[0][2];
  dst[2][1] = src[1][2];
  dst[2][2] = src[2][2];
}

/*******************************************************************************
* rot_apply: returns t*a
*******************************************************************************/
Coords rot_apply(Rotation t, Coords a)
{
  Coords b;
  if (rot_test_identity(t)) {
    return a;
  } else {
    b.x = t[0][0]*a.x + t[0][1]*a.y + t[0][2]*a.z;
    b.y = t[1][0]*a.x + t[1][1]*a.y + t[1][2]*a.z;
    b.z = t[2][0]*a.x + t[2][1]*a.y + t[2][2]*a.z;
    return b;
  }
}

/**
 * Pretty-printing of rotation matrices.
 */
void rot_print(Rotation rot) {
	printf("[ %4.2f %4.2f %4.2f ]\n",
			rot[0][0], rot[0][1], rot[0][2]);
	printf("[ %4.2f %4.2f %4.2f ]\n",
			rot[1][0], rot[1][1], rot[1][2]);
	printf("[ %4.2f %4.2f %4.2f ]\n\n",
			rot[2][0], rot[2][1], rot[2][2]);
}

/**
 * Vector product: used by vec_prod (mccode-r.h). Use coords_xp for Coords.
 */
void vec_prod_func(double *x, double *y, double *z,
		double x1, double y1, double z1,
		double x2, double y2, double z2) {
    *x = (y1)*(z2) - (y2)*(z1);
    *y = (z1)*(x2) - (z2)*(x1);
    *z = (x1)*(y2) - (x2)*(y1);
}

/**
 * Scalar product: use coords_sp for Coords.
 */
double scalar_prod(
		double x1, double y1, double z1,
		double x2, double y2, double z2) {
	return ((x1 * x2) + (y1 * y2) + (z1 * z2));
}

mcstatic void norm_func(double *x, double *y, double *z) {
	double temp = (*x * *x) + (*y * *y) + (*z * *z);
	if (temp != 0) {
		temp = sqrt(temp);
		*x /= temp;
		*y /= temp;
		*z /= temp;
	}
}


/* SECTION: GPU algorithms ================================================== */


/*
*  Divide-and-conquer strategy for parallelizing this task: Sort absorbed
*  particles last.
*
*   particles:  the particle array, required to checking _absorbed
*   pbuffer:    same-size particle buffer array required for parallel sort
*   len:        sorting area-of-interest size (e.g. from previous calls)
*   buffer_len: total array size
*   flag_split: if set, multiply live particles into absorbed slots, up to buffer_len
*   multiplier: output arg, becomes the  SPLIT multiplier if flag_split is set
*/
#ifdef FUNNEL
long sort_absorb_last(_class_particle* particles, _class_particle* pbuffer, long len, long buffer_len, long flag_split, long* multiplier) {
  #define SAL_THREADS 1024 // num parallel sections
  if (len<SAL_THREADS) return sort_absorb_last_serial(particles, len);

  if (multiplier != NULL) *multiplier = -1; // set default out value for multiplier
  long newlen = 0;
  long los[SAL_THREADS]; // target array startidxs
  long lens[SAL_THREADS]; // target array sublens
  long l = floor(len/(SAL_THREADS-1)); // subproblem_len
  long ll = len - l*(SAL_THREADS-1); // last_subproblem_len

  // TODO: The l vs ll is too simplistic, since ll can become much larger
  // than l, resulting in idling. We should distribute lengths more evenly.

  // step 1: sort sub-arrays
  #pragma acc parallel loop present(particles, pbuffer)
  for (unsigned long tidx=0; tidx<SAL_THREADS; tidx++) {
    long lo = l*tidx;
    long loclen = l;
    if (tidx==(SAL_THREADS-1)) loclen = ll; // last sub-problem special case
    long i = lo;
    long j = lo + loclen - 1;

    // write into pbuffer at i and j
    #pragma acc loop seq
    while (i < j) {
      #pragma acc loop seq
      while (!particles[i]._absorbed && i<j) {
        pbuffer[i] = particles[i];
        i++;
      }
      #pragma acc loop seq
      while (particles[j]._absorbed && i<j) {
        pbuffer[j] = particles[j];
        j--;
      }
      if (i < j) {
        pbuffer[j] = particles[i];
        pbuffer[i] = particles[j];
        i++;
        j--;
      }
    }
    // transfer edge case
    if (i==j)
      pbuffer[i] = particles[i];

    lens[tidx] = i - lo;
    if (i==j && !particles[i]._absorbed) lens[tidx]++;
  }

  // determine lo's
  long accumlen = 0;
  #pragma acc loop seq
  for (long idx=0; idx<SAL_THREADS; idx++) {
    los[idx] = accumlen;
    accumlen = accumlen + lens[idx];
  }

  // step 2: write non-absorbed sub-arrays to psorted/output from the left
  #pragma acc parallel loop present(pbuffer)
  for (unsigned long tidx=0; tidx<SAL_THREADS; tidx++) {
    long j, k;
    #pragma acc loop seq
    for (long i=0; i<lens[tidx]; i++) {
      j = i + l*tidx;
      k = i + los[tidx];
      particles[k] = pbuffer[j];
    }
  }
  //for (int ii=0;ii<accumlen;ii++) printf("%ld ", (psorted[ii]->_absorbed));

  // return (no SPLIT)
  if (flag_split != 1)
    return accumlen;

  // SPLIT - repeat the non-absorbed block N-1 times, where len % accumlen = N + R
  int mult = buffer_len / accumlen; // TODO: possibly use a new arg, bufferlen, rather than len

  // not enough space for full-block split, return
  if (mult <= 1)
    return accumlen;

  // copy non-absorbed block
  #pragma acc parallel loop present(particles)
  for (long tidx = 0; tidx < accumlen; tidx++) { // tidx: thread index
    unsigned long randstate[7];
    _class_particle sourcebuffer;
    _class_particle targetbuffer;
    // assign reduced weight to all particles
    particles[tidx].p=particles[tidx].p/mult;
    #pragma acc loop seq
    for (long bidx = 1; bidx < mult; bidx++) { // bidx: block index
      // preserve absorbed particle (for randstate)
      sourcebuffer = particles[bidx*accumlen + tidx];
      // buffer full particle struct
      targetbuffer = particles[tidx];
      // reassign previous randstate
      targetbuffer.randstate[0] = sourcebuffer.randstate[0];
      targetbuffer.randstate[1] = sourcebuffer.randstate[1];
      targetbuffer.randstate[2] = sourcebuffer.randstate[2];
      targetbuffer.randstate[3] = sourcebuffer.randstate[3];
      targetbuffer.randstate[4] = sourcebuffer.randstate[4];
      targetbuffer.randstate[5] = sourcebuffer.randstate[5];
      targetbuffer.randstate[6] = sourcebuffer.randstate[6];
      // apply
      particles[bidx*accumlen + tidx] = targetbuffer;
    }
  }

  // set out split multiplier value
  *multiplier = mult;

  // return expanded array size
  return accumlen * mult;
}

#endif

/*
*  Fallback serial version of the one above.
*/
long sort_absorb_last_serial(_class_particle* particles, long len) {
  long i = 0;
  long j = len - 1;
  _class_particle pbuffer;

  // bubble
  while (i < j) {
    while (!particles[i]._absorbed && i<j) i++;
    while (particles[j]._absorbed && i<j) j--;
    if (i < j) {
      pbuffer = particles[j];
      particles[j] = particles[i];
      particles[i] = pbuffer;
      i++;
      j--;
    }
  }

  // return new length
  if (i==j && !particles[i]._absorbed)
    return i + 1;
  else
    return i;
}

/*******************************************************************************
* mccoordschange: applies rotation to (x y z) and (vx vy vz) and Spin (sx,sy,sz)
*******************************************************************************/
void mccoordschange(Coords a, Rotation t, _class_particle *particle)
{
  Coords b, c;

  b.x = particle->x;
  b.y = particle->y;
  b.z = particle->z;
  c = rot_apply(t, b);
  b = coords_add(c, a);
  particle->x = b.x;
  particle->y = b.y;
  particle->z = b.z;

#if MCCODE_PARTICLE_CODE == 2112
    if (particle->vz != 0.0 || particle->vx != 0.0 || particle->vy != 0.0)
      mccoordschange_polarisation(t, &(particle->vx), &(particle->vy), &(particle->vz));

    if (particle->sz != 0.0 || particle->sx != 0.0 || particle->sy != 0.0)
      mccoordschange_polarisation(t, &(particle->sx), &(particle->sy), &(particle->sz));
#elif MCCODE_PARTICLE_CODE == 22
    if (particle->kz != 0.0 || particle->kx != 0.0 || particle->ky != 0.0)
      mccoordschange_polarisation(t, &(particle->kx), &(particle->ky), &(particle->kz));

    if (particle->Ez != 0.0 || particle->Ex != 0.0 || particle->Ey != 0.0)
      mccoordschange_polarisation(t, &(particle->Ex), &(particle->Ey), &(particle->Ez));
#endif
}

/*******************************************************************************
* mccoordschange_polarisation: applies rotation to vector (sx sy sz)
*******************************************************************************/
void mccoordschange_polarisation(Rotation t, double *sx, double *sy, double *sz)
{
  Coords b, c;

  b.x = *sx;
  b.y = *sy;
  b.z = *sz;
  c = rot_apply(t, b);
  *sx = c.x;
  *sy = c.y;
  *sz = c.z;
}

/* SECTION: vector math  ==================================================== */

/* normal_vec_func: Compute normal vector to (x,y,z). */
void normal_vec(double *nx, double *ny, double *nz,
                double x, double y, double z)
{
  double ax = fabs(x);
  double ay = fabs(y);
  double az = fabs(z);
  double l;
  if(x == 0 && y == 0 && z == 0)
  {
    *nx = 0;
    *ny = 0;
    *nz = 0;
    return;
  }
  if(ax < ay)
  {
    if(ax < az)
    {                           /* Use X axis */
      l = sqrt(z*z + y*y);
      *nx = 0;
      *ny = z/l;
      *nz = -y/l;
      return;
    }
  }
  else
  {
    if(ay < az)
    {                           /* Use Y axis */
      l = sqrt(z*z + x*x);
      *nx = z/l;
      *ny = 0;
      *nz = -x/l;
      return;
    }
  }
  /* Use Z axis */
  l = sqrt(y*y + x*x);
  *nx = y/l;
  *ny = -x/l;
  *nz = 0;
} /* normal_vec */

/*******************************************************************************
 * solve_2nd_order: second order equation solve: A*t^2 + B*t + C = 0
 * solve_2nd_order(&t1, NULL, A,B,C)
 *   returns 0 if no solution was found, or set 't1' to the smallest positive
 *   solution.
 * solve_2nd_order(&t1, &t2, A,B,C)
 *   same as with &t2=NULL, but also returns the second solution.
 * EXAMPLE usage for intersection of a trajectory with a plane in gravitation
 * field (gx,gy,gz):
 * The neutron starts at point r=(x,y,z) with velocityv=(vx vy vz). The plane
 * has a normal vector n=(nx,ny,nz) and contains the point W=(wx,wy,wz).
 * The problem consists in solving the 2nd order equation:
 *      1/2.n.g.t^2 + n.v.t + n.(r-W) = 0
 * so that A = 0.5 n.g; B = n.v; C = n.(r-W);
 * Without acceleration, t=-n.(r-W)/n.v
 ******************************************************************************/
int solve_2nd_order_old(double *t1, double *t2,
                  double A,  double B,  double C)
{
  int ret=0;

  if (!t1) return 0;
  *t1 = 0;
  if (t2) *t2=0;

  if (fabs(A) < 1E-10) /* approximate to linear equation: A ~ 0 */
  {
    if (B) {  *t1 = -C/B; ret=1; if (t2) *t2=*t1; }
    /* else no intersection: A=B=0 ret=0 */
  }
  else
  {
    double D;
    D = B*B - 4*A*C;
    if (D >= 0) /* Delta > 0: two solutions */
    {
      double sD, dt1, dt2;
      sD = sqrt(D);
      dt1 = (-B + sD)/2/A;
      dt2 = (-B - sD)/2/A;
      /* we identify very small values with zero */
      if (fabs(dt1) < 1e-10) dt1=0.0;
      if (fabs(dt2) < 1e-10) dt2=0.0;

      /* now we choose the smallest positive solution */
      if      (dt1<=0.0 && dt2>0.0) ret=2; /* dt2 positive */
      else if (dt2<=0.0 && dt1>0.0) ret=1; /* dt1 positive */
      else if (dt1> 0.0 && dt2>0.0)
      {  if (dt1 < dt2) ret=1; else ret=2; } /* all positive: min(dt1,dt2) */
      /* else two solutions are negative. ret=-1 */
      if (ret==1) { *t1 = dt1;  if (t2) *t2=dt2; }
      else        { *t1 = dt2;  if (t2) *t2=dt1; }
      ret=2;  /* found 2 solutions and t1 is the positive one */
    } /* else Delta <0: no intersection. ret=0 */
  }
  return(ret);
} /* solve_2nd_order */

int solve_2nd_order(double *t0, double *t1, double A, double B, double C){
  int retval=0;
  double sign=copysign(1.0,B);
  double dt0,dt1;

  dt0=0;
  dt1=0;
  if(t1){ *t1=0;}

  /*protect against rounding errors by locally equating DBL_EPSILON with 0*/
  if (fabs(A)<DBL_EPSILON){
    A=0;
  }
  if (fabs(B)<DBL_EPSILON){
    B=0;
  }
  if (fabs(C)<DBL_EPSILON){
    C=0;
  }

  /*check if coefficient are sane*/
  if( A==0  && B==0){
    retval=0;
  }else{
    if(A==0){
      /*equation is linear*/
      dt0=-C/B;
      retval=1;
    }else if (C==0){
      /*one root is 0*/
      if(sign<0){
        dt0=0;dt1=-B/A;
      }else{
        dt0=-B/A;dt1=0;
      }
      retval=2;
    }else{
      /*a regular 2nd order eq. Also works out fine for B==0.*/
      double D;
      D=B*B-4*A*C;
      if (D>=0){
        dt0=(-B - sign*sqrt(B*B-4*A*C))/(2*A);
        dt1=C/(A*dt0);
        retval=2;
      }else{
        /*no real roots*/
        retval=0;
      }
    }
    /*sort the solutions*/
    if (retval==1){
      /*put both solutions in t0 and t1*/
      *t0=dt0;
      if(t1) *t1=dt1;
    }else{
      /*we have two solutions*/
      /*swap if both are positive and t1 smaller than t0 or t1 the only positive*/
      int swap=0;
      if(dt1>0 && ( dt1<dt0 || dt0<=0) ){
        swap=1;
      }
      if (swap){
        *t0=dt1;
        if(t1) *t1=dt0;
      }else{
        *t0=dt0;
        if(t1) *t1=dt0;
      }
    }

  }
  return retval;

} /*solve_2nd_order_improved*/


/*******************************************************************************
 * randvec_target_circle: Choose random direction towards target at (x,y,z)
 * with given radius.
 * If radius is zero, choose random direction in full 4PI, no target.
 ******************************************************************************/
void _randvec_target_circle(double *xo, double *yo, double *zo, double *solid_angle,
        double xi, double yi, double zi, double radius,
        _class_particle* _particle)
{
  double l2, phi, theta, nx, ny, nz, xt, yt, zt, xu, yu, zu;

  if(radius == 0.0)
  {
    /* No target, choose uniformly a direction in full 4PI solid angle. */
    theta = acos(1 - rand0max(2));
    phi = rand0max(2 * PI);
    if(solid_angle)
      *solid_angle = 4*PI;
    nx = 1;
    ny = 0;
    nz = 0;
    yi = sqrt(xi*xi+yi*yi+zi*zi);
    zi = 0;
    xi = 0;
  }
  else
  {
    double costheta0;
    l2 = xi*xi + yi*yi + zi*zi; /* sqr Distance to target. */
    costheta0 = sqrt(l2/(radius*radius+l2));
    if (radius < 0) costheta0 *= -1;
    if(solid_angle)
    {
      /* Compute solid angle of target as seen from origin. */
        *solid_angle = 2*PI*(1 - costheta0);
    }

    /* Now choose point uniformly on circle surface within angle theta0 */
    theta = acos (1 - rand0max(1 - costheta0)); /* radius on circle */
    phi = rand0max(2 * PI); /* rotation on circle at given radius */
    /* Now, to obtain the desired vector rotate (xi,yi,zi) angle theta around a
       perpendicular axis u=i x n and then angle phi around i. */
    if(xi == 0 && zi == 0)
    {
      nx = 1;
      ny = 0;
      nz = 0;
    }
    else
    {
      nx = -zi;
      nz = xi;
      ny = 0;
    }
  }

  /* [xyz]u = [xyz]i x n[xyz] (usually vertical) */
  vec_prod(xu,  yu,  zu, xi, yi, zi,        nx, ny, nz);
  /* [xyz]t = [xyz]i rotated theta around [xyz]u */
  rotate  (xt,  yt,  zt, xi, yi, zi, theta, xu, yu, zu);
  /* [xyz]o = [xyz]t rotated phi around n[xyz] */
  rotate (*xo, *yo, *zo, xt, yt, zt, phi, xi, yi, zi);
}
/* randvec_target_circle */

/*******************************************************************************
 * randvec_target_rect_angular: Choose random direction towards target at
 * (xi,yi,zi) with given ANGULAR dimension height x width. height=phi_x=[0,PI],
 * width=phi_y=[0,2*PI] (radians)
 * If height or width is zero, choose random direction in full 4PI, no target.
 *******************************************************************************/
void _randvec_target_rect_angular(double *xo, double *yo, double *zo, double *solid_angle,
        double xi, double yi, double zi, double width, double height, Rotation A,
        _class_particle* _particle)
{
  double theta, phi, nx, ny, nz, xt, yt, zt, xu, yu, zu;
  Coords tmp;
  Rotation Ainverse;

  rot_transpose(A, Ainverse);

  if(height == 0.0 || width == 0.0)
  {
    randvec_target_circle(xo, yo, zo, solid_angle, xi, yi, zi, 0);
    return;
  }
  else
  {
    if(solid_angle)
    {
      /* Compute solid angle of target as seen from origin. */
      *solid_angle = 2*fabs(width*sin(height/2));
    }

    /* Go to global coordinate system */

    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(Ainverse, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    /* Now choose point uniformly on the unit sphere segment with angle theta/phi */
    phi   = width*randpm1()/2.0;
    theta = asin(randpm1()*sin(height/2.0));
    /* Now, to obtain the desired vector rotate (xi,yi,zi) angle theta around
       n, and then phi around u. */
    if(xi == 0 && zi == 0)
    {
      nx = 1;
      ny = 0;
      nz = 0;
    }
    else
    {
      nx = -zi;
      nz = xi;
      ny = 0;
    }
  }

  /* [xyz]u = [xyz]i x n[xyz] (usually vertical) */
  vec_prod(xu,  yu,  zu, xi, yi, zi,        nx, ny, nz);
  /* [xyz]t = [xyz]i rotated theta around [xyz]u */
  rotate  (xt,  yt,  zt, xi, yi, zi, theta, nx, ny, nz);
  /* [xyz]o = [xyz]t rotated phi around n[xyz] */
  rotate (*xo, *yo, *zo, xt, yt, zt, phi, xu,  yu,  zu);

  /* Go back to local coordinate system */
  tmp = coords_set(*xo, *yo, *zo);
  tmp = rot_apply(A, tmp);
  coords_get(tmp, &*xo, &*yo, &*zo);
}
/* randvec_target_rect_angular */

/*******************************************************************************
 * randvec_target_rect_real: Choose random direction towards target at (xi,yi,zi)
 * with given dimension height x width (in meters !).
 *
 * Local emission coordinate is taken into account and corrected for 'order' times.
 * (See remarks posted to mcstas-users by George Apostolopoulus <gapost@ipta.demokritos.gr>)
 *
 * If height or width is zero, choose random direction in full 4PI, no target.
 *
 * Traditionally, this routine had the name randvec_target_rect - this is now a
 * a define (see mcstas-r.h) pointing here. If you use the old rouine, you are NOT
 * taking the local emmission coordinate into account.
*******************************************************************************/
void _randvec_target_rect_real(double *xo, double *yo, double *zo, double *solid_angle,
        double xi, double yi, double zi,
        double width, double height, Rotation A,
        double lx, double ly, double lz, int order,
        _class_particle* _particle)
{
  double dx, dy, dist, dist_p, nx, ny, nz, mx, my, mz, n_norm, m_norm;
  double cos_theta;
  Coords tmp;
  Rotation Ainverse;

  rot_transpose(A, Ainverse);

  if(height == 0.0 || width == 0.0)
  {
    randvec_target_circle(xo, yo, zo, solid_angle,
               xi, yi, zi, 0);
    return;
  }
  else
  {
    /* Now choose point uniformly on rectangle within width x height */
    dx = width*randpm1()/2.0;
    dy = height*randpm1()/2.0;

    /* Determine distance to target plane*/
    dist = sqrt(xi*xi + yi*yi + zi*zi);
    /* Go to global coordinate system */

    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(Ainverse, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    /* Determine vector normal to trajectory axis (z) and gravity [0 1 0] */
    vec_prod(nx, ny, nz, xi, yi, zi, 0, 1, 0);

    /* This now defines the x-axis, normalize: */
    n_norm=sqrt(nx*nx + ny*ny + nz*nz);
    nx = nx/n_norm;
    ny = ny/n_norm;
    nz = nz/n_norm;

    /* Now, determine our y-axis (vertical in many cases...) */
    vec_prod(mx, my, mz, xi, yi, zi, nx, ny, nz);
    m_norm=sqrt(mx*mx + my*my + mz*mz);
    mx = mx/m_norm;
    my = my/m_norm;
    mz = mz/m_norm;

    /* Our output, random vector can now be defined by linear combination: */

    *xo = xi + dx * nx + dy * mx;
    *yo = yi + dx * ny + dy * my;
    *zo = zi + dx * nz + dy * mz;

    /* Go back to local coordinate system */
    tmp = coords_set(*xo, *yo, *zo);
    tmp = rot_apply(A, tmp);
    coords_get(tmp, &*xo, &*yo, &*zo);

    /* Go back to local coordinate system */
    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(A, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    if (solid_angle) {
      /* Calculate vector from local point to remote random point */
      lx = *xo - lx;
      ly = *yo - ly;
      lz = *zo - lz;
      dist_p = sqrt(lx*lx + ly*ly + lz*lz);

      /* Adjust the 'solid angle' */
      /* 1/r^2 to the chosen point times cos(\theta) between the normal */
      /* vector of the target rectangle and direction vector of the chosen point. */
      cos_theta = (xi * lx + yi * ly + zi * lz) / (dist * dist_p);
      *solid_angle = width * height / (dist_p * dist_p);
      int counter;
      for (counter = 0; counter < order; counter++) {
        *solid_angle = *solid_angle * cos_theta;
      }
    }
  }
}
/* randvec_target_rect_real */


/* SECTION: random numbers ==================================================

  How to add a new RNG:

  - Use an rng with a manegable state vector, e.g. of lengt 4 or 7. The state
  will sit on the particle struct as a "randstate_t state[RANDSTATE_LEN]"
  - If the rng has a long state (as MT), set an empty "srandom" and initialize
  it explicitly using the appropriate define (RNG_ALG)
  - Add a seed and a random function (the transforms will be reused)
  - Write the proper defines in mccode-r.h, e.g. randstate_t and RANDSTATE_LEN,
  srandom and random.
  - Compile using -DRNG_ALG=<selector int value>

============================================================================= */


/* "Mersenne Twister", by Makoto Matsumoto and Takuji Nishimura. */
/* See http://www.math.keio.ac.jp/~matumoto/emt.html for original source. */
/*
   A C-program for MT19937, with initialization improved 2002/1/26.
   Coded by Takuji Nishimura and Makoto Matsumoto.

   Before using, initialize the state by using mt_srandom(seed)
   or init_by_array(init_key, key_length).

   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote
        products derived from this software without specific prior written
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


   Any feedback is very welcome.
   http://www.math.keio.ac.jp/matumoto/emt.html
   email: matumoto@math.keio.ac.jp
*/
#include <stdio.h>
/* Period parameters */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

unsigned long mt[N]; /* the array for the state vector  */
int mti=N+1; /* mti==N+1 means mt[N] is not initialized */

// required for common rng alg interface (see RNG_ALG usage in mccode-r.h)
void mt_srandom_empty() {}

// initializes mt[N] with a seed
void mt_srandom(unsigned long s)
{
    mt[0]= s & 0xffffffffUL;
    for (mti=1; mti<N; mti++) {
        mt[mti] =
            (1812433253UL * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti);
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array mt[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        mt[mti] &= 0xffffffffUL;
        /* for >32 bit machines */
    }
}
/* Initialize by an array with array-length.
   Init_key is the array for initializing keys.
   key_length is its length. */
void init_by_array(unsigned long init_key[], unsigned long key_length)
{
    int i, j, k;
    mt_srandom(19650218UL);
    i=1; j=0;
    k = (N>key_length ? N : key_length);
    for (; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525UL))
          + init_key[j] + j; /* non linear */
        mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++; j++;
        if (i>=N) { mt[0] = mt[N-1]; i=1; }
        if (j>=key_length) j=0;
    }
    for (k=N-1; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941UL))
          - i; /* non linear */
        mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++;
        if (i>=N) { mt[0] = mt[N-1]; i=1; }
    }

    mt[0] = 0x80000000UL; /* MSB is 1; assuring non-zero initial array */
}
/* generates a random number on [0,0xffffffff]-interval */
unsigned long mt_random(void)
{
    unsigned long y;
    unsigned long mag01[2]={0x0UL, MATRIX_A};
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (mti >= N) { /* generate N words at one time */
        int kk;

        if (mti == N+1)   /* if mt_srandom() has not been called, */
            mt_srandom(5489UL); /* a default initial seed is used */

        for (kk=0;kk<N-M;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (;kk<N-1;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (mt[N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
        mt[N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

        mti = 0;
    }

    y = mt[mti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return y;
}
#undef N
#undef M
#undef MATRIX_A
#undef UPPER_MASK
#undef LOWER_MASK
/* End of "Mersenne Twister". */


/*
KISS

 From: http://www.helsbreth.org/random/rng_kiss.html
 Scott Nelson 1999

 Based on Marsaglia's KISS or (KISS+SWB) <http://www.cs.yorku.ca/~oz/marsaglia-
rng.html>

 KISS - Keep it Simple Stupid PRNG

 the idea is to use simple, fast, individually promising
 generators to get a composite that will be fast, easy to code
 have a very long period and pass all the tests put to it.
 The three components of KISS are
        x(n)=a*x(n-1)+1 mod 2^32
        y(n)=y(n-1)(I+L^13)(I+R^17)(I+L^5),
        z(n)=2*z(n-1)+z(n-2) +carry mod 2^32
 The y's are a shift register sequence on 32bit binary vectors
 period 2^32-1;
 The z's are a simple multiply-with-carry sequence with period
 2^63+2^32-1.  The period of KISS is thus
      2^32*(2^32-1)*(2^63+2^32-1) > 2^127
*/

/* the KISS state is stored as a vector of 7 unsigned long        */
/*   0  1  2  3  4      5  6   */
/* [ x, y, z, w, carry, k, m ] */

unsigned long *kiss_srandom(unsigned long state[7], unsigned long seed) {
  if (seed == 0) seed = 1;
  state[0] = seed | 1; // x
  state[1] = seed | 2; // y
  state[2] = seed | 4; // z
  state[3] = seed | 8; // w
  state[4] = 0;        // carry
  return 0;
}

unsigned long kiss_random(unsigned long state[7]) {
    state[0] = state[0] * 69069 + 1;
    state[1] ^= state[1] << 13;
    state[1] ^= state[1] >> 17;
    state[1] ^= state[1] << 5;
    state[5] = (state[2] >> 2) + (state[3] >> 3) + (state[4] >> 2);
    state[6] = state[3] + state[3] + state[2] + state[4];
    state[2] = state[3];
    state[3] = state[6];
    state[4] = state[5] >> 30;
    return state[0] + state[1] + state[3];
}
/* end of "KISS" rng */


/* FAST KISS in another implementation (Hundt) */

//////////////////////////////////////////////////////////////////////////////
// fast keep it simple stupid generator
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Thomas Mueller hash for initialization of rngs
// http://stackoverflow.com/questions/664014/
//        what-integer-hash-function-are-good-that-accepts-an-integer-hash-key
//////////////////////////////////////////////////////////////////////////////
randstate_t _hash(randstate_t x) {
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = ((x >> 16) ^ x);
  return x;
}


// SECTION: random number transforms ==========================================



// generate a random number from normal law
double _randnorm(randstate_t* state)
{
  static double v1, v2, s; /* removing static breaks comparison with McStas <= 2.5 */
  static int phase = 0;
  double X, u1, u2;

  if(phase == 0)
  {
    do
    {
      u1 = _rand01(state);
      u2 = _rand01(state);
      v1 = 2*u1 - 1;
      v2 = 2*u2 - 1;
      s = v1*v1 + v2*v2;
    } while(s >= 1 || s == 0);

    X = v1*sqrt(-2*log(s)/s);
  }
  else
  {
    X = v2*sqrt(-2*log(s)/s);
  }

  phase = 1 - phase;
  return X;
}
// another one
double _randnorm2(randstate_t* state) {
  double x, y, r;
  do {
      x = 2.0 * _rand01(state) - 1.0;
      y = 2.0 * _rand01(state) - 1.0;
      r = x*x + y*y;
  } while (r == 0.0 || r >= 1.0);
  return x * sqrt((-2.0 * log(r)) / r);
}

// Generate a random number from -1 to 1 with triangle distribution
double _randtriangle(randstate_t* state) {
	double randnum = _rand01(state);
	if (randnum>0.5) return(1-sqrt(2*(randnum-0.5)));
	else return(sqrt(2*randnum)-1);
}
double _rand01(randstate_t* state) {
	double randnum;
	randnum = (double) _random();
  // TODO: can we mult instead of div?
	randnum /= (double) MC_RAND_MAX + 1;
	return randnum;
}
// Return a random number between 1 and -1
double _randpm1(randstate_t* state) {
	double randnum;
	randnum = (double) _random();
	randnum /= ((double) MC_RAND_MAX + 1) / 2;
	randnum -= 1;
	return randnum;
}
// Return a random number between 0 and max.
double _rand0max(double max, randstate_t* state) {
	double randnum;
	randnum = (double) _random();
	randnum /= ((double) MC_RAND_MAX + 1) / max;
	return randnum;
}
// Return a random number between min and max.
double _randminmax(double min, double max, randstate_t* state) {
	return _rand0max(max - min, state) + max;
}


/* SECTION: main and signal handlers ======================================== */

/*******************************************************************************
* mchelp: displays instrument executable help with possible options
*******************************************************************************/
static void
mchelp(char *pgmname)
{
  int i;

  fprintf(stderr, "%s (%s) instrument simulation, generated with " MCCODE_STRING " (" MCCODE_DATE ")\n", instrument_name, instrument_source);
  fprintf(stderr, "Usage: %s [options] [parm=value ...]\n", pgmname);
  fprintf(stderr,
"Options are:\n"
"  -s SEED   --seed=SEED      Set random seed (must be != 0)\n"
"  -n COUNT  --ncount=COUNT   Set number of particles to simulate.\n"
"  -d DIR    --dir=DIR        Put all data files in directory DIR.\n"
"  -t        --trace          Enable trace of " MCCODE_PARTICLE "s through instrument.\n"
"  -g        --gravitation    Enable gravitation for all trajectories.\n"
"  --no-output-files          Do not write any data files.\n"
"  -h        --help           Show this help message.\n"
"  -i        --info           Detailed instrument information.\n"
"  --list-parameters          Print the instrument parameters to standard out\n"
"  --meta-list                Print names of components which defined metadata\n"
"  --meta-defined COMP[:NAME] Print component defined metadata names, or (0,1) if NAME provided\n"
"  --meta-type COMP:NAME      Print metadata format type specified in definition\n"
"  --meta-data COMP:NAME      Print the metadata text\n"
"  --source                   Show the instrument code which was compiled.\n"
#ifdef OPENACC
"\n"
"  --vecsize                  OpenACC vector-size (default: 128)\n"
"  --numgangs                 Number of OpenACC gangs (default: 7813)\n"
"  --gpu_innerloop            Maximum rays to process pr. OpenACC \n"
"                             kernel run (default: 2147483647)\n"
"\n"
#endif
"\n"
"  --bufsiz                   Monitor_nD list/buffer-size (default: 1000000)\n"
"  --format=FORMAT            Output data files using FORMAT="
   FLAVOR_UPPER
#ifdef USE_NEXUS
   " NEXUS"
#endif
"\n\n"
);
#ifdef USE_MPI
  fprintf(stderr,
  "This instrument has been compiled with MPI support.\n  Use 'mpirun %s [options] [parm=value ...]'.\n", pgmname);
#endif
#ifdef OPENACC
  fprintf(stderr,
  "This instrument has been compiled with NVIDIA GPU support through OpenACC.\n  Running on systems without such devices will lead to segfaults.\nFurter, fprintf, sprintf and printf have been removed from any component TRACE.\n");
#endif

  if(numipar > 0)
  {
    fprintf(stderr, "Instrument parameters are:\n");
    for(i = 0; i < numipar; i++)
      if (mcinputtable[i].val && strlen(mcinputtable[i].val))
        fprintf(stderr, "  %-16s(%s) [default='%s']\n", mcinputtable[i].name,
        (*mcinputtypes[mcinputtable[i].type].parminfo)(mcinputtable[i].name),
        mcinputtable[i].val);
      else
        fprintf(stderr, "  %-16s(%s)\n", mcinputtable[i].name,
        (*mcinputtypes[mcinputtable[i].type].parminfo)(mcinputtable[i].name));
  }

#ifndef NOSIGNALS
  fprintf(stderr, "Known signals are: "
#ifdef SIGUSR1
  "USR1 (status) "
#endif
#ifdef SIGUSR2
  "USR2 (save) "
#endif
#ifdef SIGBREAK
  "BREAK (save) "
#endif
#ifdef SIGTERM
  "TERM (save and exit)"
#endif
  "\n");
#endif /* !NOSIGNALS */
} /* mchelp */


/* mcshowhelp: show help and exit with 0 */
static void
mcshowhelp(char *pgmname)
{
  mchelp(pgmname);
  exit(0);
}

/* mcusage: display usage when error in input arguments and exit with 1 */
static void
mcusage(char *pgmname)
{
  fprintf(stderr, "Error: incorrect command line arguments\n");
  mchelp(pgmname);
  exit(1);
}

/* mcenabletrace: enable trace/mcdisplay or error if requires recompile */
static void
mcenabletrace(void)
{
 if(traceenabled) {
  mcdotrace = 1;
  #pragma acc update device ( mcdotrace )
 } else {
   fprintf(stderr,
           "Error: trace not enabled (mcenabletrace)\n"
           "Please re-run the " MCCODE_NAME " compiler "
                   "with the --trace option, or rerun the\n"
           "C compiler with the MC_TRACE_ENABLED macro defined.\n");
   exit(1);
 }
}

/*******************************************************************************
* mcreadparams: request parameters from the prompt (or use default)
*******************************************************************************/
void
mcreadparams(void)
{
  int i,j,status;
  static char buf[CHAR_BUF_LENGTH];
  char *p;
  int len;

  MPI_MASTER(printf("Instrument parameters for %s (%s)\n",
                    instrument_name, instrument_source));

  for(i = 0; mcinputtable[i].name != 0; i++)
  {
    do
    {
      MPI_MASTER(
                 if (mcinputtable[i].val && strlen(mcinputtable[i].val))
                   printf("Set value of instrument parameter %s (%s) [default='%s']:\n",
                          mcinputtable[i].name,
                          (*mcinputtypes[mcinputtable[i].type].parminfo)
                          (mcinputtable[i].name), mcinputtable[i].val);
                 else
                   printf("Set value of instrument parameter %s (%s):\n",
                          mcinputtable[i].name,
                          (*mcinputtypes[mcinputtable[i].type].parminfo)
                          (mcinputtable[i].name));
                 fflush(stdout);
                 );
#ifdef USE_MPI
      if(mpi_node_rank == mpi_node_root)
        {
          p = fgets(buf, CHAR_BUF_LENGTH, stdin);
          if(p == NULL)
            {
              fprintf(stderr, "Error: empty input for paramater %s (mcreadparams)\n", mcinputtable[i].name);
              exit(1);
            }
        }
      else
        p = buf;
      MPI_Bcast(buf, CHAR_BUF_LENGTH, MPI_CHAR, mpi_node_root, MPI_COMM_WORLD);
#else /* !USE_MPI */
      p = fgets(buf, CHAR_BUF_LENGTH, stdin);
      if(p == NULL)
        {
          fprintf(stderr, "Error: empty input for paramater %s (mcreadparams)\n", mcinputtable[i].name);
          exit(1);
        }
#endif /* USE_MPI */
      len = strlen(buf);
      if (!len || (len == 1 && (buf[0] == '\n' || buf[0] == '\r')))
      {
        if (mcinputtable[i].val && strlen(mcinputtable[i].val)) {
          strncpy(buf, mcinputtable[i].val, CHAR_BUF_LENGTH);  /* use default value */
          len = strlen(buf);
        }
      }
      for(j = 0; j < 2; j++)
      {
        if(len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r'))
        {
          len--;
          buf[len] = '\0';
        }
      }

      status = (*mcinputtypes[mcinputtable[i].type].getparm)
                   (buf, mcinputtable[i].par);
      if(!status)
      {
        (*mcinputtypes[mcinputtable[i].type].error)(mcinputtable[i].name, buf);
        if (!mcinputtable[i].val || strlen(mcinputtable[i].val)) {
          fprintf(stderr, "       Change %s default value in instrument definition.\n", mcinputtable[i].name);
          exit(1);
        }
      }
    } while(!status);
  }
} /* mcreadparams */

/*******************************************************************************
* mcparseoptions: parse command line arguments (options, parameters)
*******************************************************************************/
void
mcparseoptions(int argc, char *argv[])
{
  int i, j;
  char *p;
  int paramset = 0, *paramsetarray;
  char *usedir=NULL;

  /* Add one to numipar to avoid allocating zero size memory block. */
  paramsetarray = (int*)malloc((numipar + 1)*sizeof(*paramsetarray));
  if(paramsetarray == NULL)
  {
    fprintf(stderr, "Error: insufficient memory (mcparseoptions)\n");
    exit(1);
  }
  for(j = 0; j < numipar; j++)
    {
      paramsetarray[j] = 0;
      if (mcinputtable[j].val != NULL && strlen(mcinputtable[j].val))
      {
        int  status;
        char buf[CHAR_BUF_LENGTH];
        strncpy(buf, mcinputtable[j].val, CHAR_BUF_LENGTH);
        status = (*mcinputtypes[mcinputtable[j].type].getparm)
                   (buf, mcinputtable[j].par);
        if(!status) fprintf(stderr, "Invalid '%s' default value %s in instrument definition (mcparseoptions)\n", mcinputtable[j].name, buf);
        else paramsetarray[j] = 1;
      } else {
        (*mcinputtypes[mcinputtable[j].type].getparm)
          (NULL, mcinputtable[j].par);
        paramsetarray[j] = 0;
      }
    }
  for(i = 1; i < argc; i++)
  {
    if(!strcmp("-s", argv[i]) && (i + 1) < argc)
      mcsetseed(argv[++i]);
    else if(!strncmp("-s", argv[i], 2))
      mcsetseed(&argv[i][2]);
    else if(!strcmp("--seed", argv[i]) && (i + 1) < argc)
      mcsetseed(argv[++i]);
    else if(!strncmp("--seed=", argv[i], 7))
      mcsetseed(&argv[i][7]);
    else if(!strcmp("-n", argv[i]) && (i + 1) < argc)
      mcsetn_arg(argv[++i]);
    else if(!strncmp("-n", argv[i], 2))
      mcsetn_arg(&argv[i][2]);
    else if(!strcmp("--ncount", argv[i]) && (i + 1) < argc)
      mcsetn_arg(argv[++i]);
    else if(!strncmp("--ncount=", argv[i], 9))
      mcsetn_arg(&argv[i][9]);
    else if(!strcmp("-d", argv[i]) && (i + 1) < argc)
      usedir=argv[++i];  /* will create directory after parsing all arguments (end of this function) */
    else if(!strncmp("-d", argv[i], 2))
      usedir=&argv[i][2];
    else if(!strcmp("--dir", argv[i]) && (i + 1) < argc)
      usedir=argv[++i];
    else if(!strncmp("--dir=", argv[i], 6))
      usedir=&argv[i][6];
    else if(!strcmp("-h", argv[i]))
      mcshowhelp(argv[0]);
    else if(!strcmp("--help", argv[i]) || !strcmp("--version", argv[i]))
      mcshowhelp(argv[0]);
    else if(!strcmp("-i", argv[i])) {
      mcformat=FLAVOR_UPPER;
      mcinfo();
    }
    else if(!strcmp("--info", argv[i]))
      mcinfo();
    else if (!strcmp("--list-parameters", argv[i]))
      mcparameterinfo();
    else if (!strcmp("--meta-list", argv[i]) && ((i+1) >= argc || argv[i+1][0] == '-')){
      //printf("Components with metadata defined:\n");
      exit(metadata_table_print_all_components(num_metadata, metadata_table) == 0);
    }
    else if (!strcmp("--meta-defined", argv[i]) && (i+1) < argc){
      exit(metadata_table_print_component_keys(num_metadata, metadata_table, argv[i+1]) == 0);
    }
    else if (!strcmp("--meta-type", argv[i]) && (i+1) < argc){
      char * literal_type = metadata_table_type(num_metadata, metadata_table, argv[i+1]);
      if (literal_type == NULL) exit(1);
      printf("%s\n", literal_type);
      exit(0);
    }
    else if (!strcmp("--meta-data", argv[i]) && (i+1) < argc){
      char * literal = metadata_table_literal(num_metadata, metadata_table, argv[i+1]);
      if (literal == NULL) exit(1);
      printf("%s\n", literal);
      exit(0);
    }
    else if(!strcmp("-t", argv[i]))
      mcenabletrace();
    else if(!strcmp("--trace", argv[i]) || !strcmp("--verbose", argv[i]))
      mcenabletrace();
    else if(!strcmp("--gravitation", argv[i]))
      mcgravitation = 1;
    else if(!strcmp("-g", argv[i]))
      mcgravitation = 1;
    else if(!strncmp("--format=", argv[i], 9)) {
      mcformat=&argv[i][9];
    }
    else if(!strcmp("--format", argv[i]) && (i + 1) < argc) {
      mcformat=argv[++i];
    }
    else if(!strncmp("--vecsize=", argv[i], 10)) {
      vecsize=atoi(&argv[i][10]);
    }    
    else if(!strcmp("--vecsize", argv[i]) && (i + 1) < argc) {
      vecsize=atoi(argv[++i]);
    }
    else if(!strcmp("--bufsiz", argv[i]) && (i + 1) < argc) {
      MONND_BUFSIZ=atoi(argv[++i]);
    }
    else if(!strncmp("--numgangs=", argv[i], 11)) {
      numgangs=atoi(&argv[i][11]);
    }
    else if(!strcmp("--numgangs", argv[i]) && (i + 1) < argc) {
      numgangs=atoi(argv[++i]);
    }
    else if(!strncmp("--gpu_innerloop=", argv[i], 16)) {
      gpu_innerloop=(long)strtod(&argv[i][16], NULL);
    }
    else if(!strcmp("--gpu_innerloop", argv[i]) && (i + 1) < argc) {
      gpu_innerloop=(long)strtod(argv[++i], NULL);
    }

    else if(!strcmp("--no-output-files", argv[i]))
      mcdisable_output_files = 1;
    else if(!strcmp("--source", argv[i])) {
      printf("/* Source code %s from %s: */\n"
        "/******************************************************************************/\n"
        "%s\n"
        "/******************************************************************************/\n"
        "/* End of source code %s from %s */\n",
        instrument_name, instrument_source, instrument_code,
        instrument_name, instrument_source);
      exit(1);
    }
    else if(argv[i][0] != '-' && (p = strchr(argv[i], '=')) != NULL)
    {
      *p++ = '\0';

      for(j = 0; j < numipar; j++)
        if(!strcmp(mcinputtable[j].name, argv[i]))
        {
          int status;
          status = (*mcinputtypes[mcinputtable[j].type].getparm)(p,
                        mcinputtable[j].par);
          if(!status || !strlen(p))
          {
            (*mcinputtypes[mcinputtable[j].type].error)
              (mcinputtable[j].name, p);
            exit(1);
          }
          paramsetarray[j] = 1;
          paramset = 1;
          break;
        }
      if(j == numipar)
      {                                /* Unrecognized parameter name */
        fprintf(stderr, "Error: unrecognized parameter %s (mcparseoptions)\n", argv[i]);
        exit(1);
      }
    }
    else if(argv[i][0] == '-') {
      fprintf(stderr, "Error: unrecognized option argument %s (mcparseoptions). Ignored.\n", argv[i++]);
    }
    else {
      fprintf(stderr, "Error: unrecognized argument %s (mcparseoptions). Aborting.\n", argv[i]);
      mcusage(argv[0]);
    }
  }
  if(!paramset)
    mcreadparams();                /* Prompt for parameters if not specified. */
  else
  {
    for(j = 0; j < numipar; j++)
      if(!paramsetarray[j])
      {
        fprintf(stderr, "Error: Instrument parameter %s left unset (mcparseoptions)\n",
                mcinputtable[j].name);
        exit(1);
      }
  }
  free(paramsetarray);
#ifdef USE_MPI
  if (mcdotrace) mpi_node_count=1; /* disable threading when in trace mode */
#endif
  if (usedir && strlen(usedir) && !mcdisable_output_files) mcuse_dir(usedir);
} /* mcparseoptions */

#ifndef NOSIGNALS
/*******************************************************************************
* sighandler: signal handler that makes simulation stop, and save results
*******************************************************************************/
void sighandler(int sig)
{
  /* MOD: E. Farhi, Sep 20th 2001: give more info */
  time_t t1, t0;
#define SIG_SAVE 0
#define SIG_TERM 1
#define SIG_STAT 2
#define SIG_ABRT 3

  printf("\n# " MCCODE_STRING ": [pid %i] Signal %i detected", getpid(), sig);
#ifdef USE_MPI
  printf(" [proc %i]", mpi_node_rank);
#endif
#if defined(SIGUSR1) && defined(SIGUSR2) && defined(SIGKILL)
  if (!strcmp(mcsig_message, "sighandler") && (sig != SIGUSR1) && (sig != SIGUSR2))
  {
    printf("\n# Fatal : unrecoverable loop ! Suicide (naughty boy).\n");
    kill(0, SIGKILL); /* kill myself if error occurs within sighandler: loops */
  }
#endif
  switch (sig) {
#ifdef SIGINT
    case SIGINT : printf(" SIGINT (interrupt from terminal, Ctrl-C)"); sig = SIG_TERM; break;
#endif
#ifdef SIGILL
    case SIGILL  : printf(" SIGILL (Illegal instruction)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGFPE
    case SIGFPE  : printf(" SIGFPE (Math Error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGSEGV
    case SIGSEGV : printf(" SIGSEGV (Mem Error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGTERM
    case SIGTERM : printf(" SIGTERM (Termination)"); sig = SIG_TERM; break;
#endif
#ifdef SIGABRT
    case SIGABRT : printf(" SIGABRT (Abort)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGQUIT
    case SIGQUIT : printf(" SIGQUIT (Quit from terminal)"); sig = SIG_TERM; break;
#endif
#ifdef SIGTRAP
    case SIGTRAP : printf(" SIGTRAP (Trace trap)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGPIPE
    case SIGPIPE : printf(" SIGPIPE (Broken pipe)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGUSR1
    case SIGUSR1 : printf(" SIGUSR1 (Display info)"); sig = SIG_STAT; break;
#endif
#ifdef SIGUSR2
    case SIGUSR2 : printf(" SIGUSR2 (Save simulation)"); sig = SIG_SAVE; break;
#endif
#ifdef SIGHUP
    case SIGHUP  : printf(" SIGHUP (Hangup/update)"); sig = SIG_SAVE; break;
#endif
#ifdef SIGBUS
    case SIGBUS  : printf(" SIGBUS (Bus error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGURG
    case SIGURG  : printf(" SIGURG (Urgent socket condition)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGBREAK
    case SIGBREAK: printf(" SIGBREAK (Break signal, Ctrl-Break)"); sig = SIG_SAVE; break;
#endif
    default : printf(" (look at signal list for signification)"); sig = SIG_ABRT; break;
  }
  printf("\n");
  printf("# Simulation: %s (%s) \n", instrument_name, instrument_source);
  printf("# Breakpoint: %s ", mcsig_message);
  if (strstr(mcsig_message, "Save") && (sig == SIG_SAVE))
    sig = SIG_STAT;
  SIG_MESSAGE("sighandler");
  if (mcget_ncount() == 0)
    printf("(0 %%)\n" );
  else
  {
    printf("%.2f %% (%10.1f/%10.1f)\n", 100.0*mcget_run_num()/mcget_ncount(), 1.0*mcget_run_num(), 1.0*mcget_ncount());
  }
  t0 = (time_t)mcstartdate;
  t1 = time(NULL);
  printf("# Date:      %s", ctime(&t1));
  printf("# Started:   %s", ctime(&t0));

  if (sig == SIG_STAT)
  {
    printf("# " MCCODE_STRING ": Resuming simulation (continue)\n");
    fflush(stdout);
    return;
  }
  else
  if (sig == SIG_SAVE)
  {
    printf("# " MCCODE_STRING ": Saving data and resume simulation (continue)\n");
    save(NULL);
    fflush(stdout);
    return;
  }
  else
  if (sig == SIG_TERM)
  {
    printf("# " MCCODE_STRING ": Finishing simulation (save results and exit)\n");
    finally();
    exit(0);
  }
  else
  {
    fflush(stdout);
    perror("# Last I/O Error");
    printf("# " MCCODE_STRING ": Simulation stop (abort).\n");
// This portion of the signal handling only works on UNIX
#if defined(__unix__) || defined(__APPLE__)
    signal(sig, SIG_DFL); /* force to use default sighandler now */
    kill(getpid(), sig);  /* and trigger it with the current signal */
#endif
    exit(-1);
  }
#undef SIG_SAVE
#undef SIG_TERM
#undef SIG_STAT
#undef SIG_ABRT

} /* sighandler */
#endif /* !NOSIGNALS */

#ifdef NEUTRONICS
/*Main neutronics function steers the McStas calls, initializes parameters etc */
/* Only called in case NEUTRONICS = TRUE */
void neutronics_main_(float *inx, float *iny, float *inz, float *invx, float *invy, float *invz, float *intime, float *insx, float *insy, float *insz, float *inw, float *outx, float *outy, float *outz, float *outvx, float *outvy, float *outvz, float *outtime, float *outsx, float *outsy, float *outsz, float *outwgt)
{

  extern double mcnx, mcny, mcnz, mcnvx, mcnvy, mcnvz;
  extern double mcnt, mcnsx, mcnsy, mcnsz, mcnp;

  /* External code governs iteration - McStas is iterated once per call to neutronics_main. I.e. below counter must be initiancated for each call to neutronics_main*/
  mcrun_num=0;

  time_t t;
  t = (time_t)mcstartdate;
  mcstartdate = t;  /* set start date before parsing options and creating sim file */
  init();

  /* *** parse options *** */
  SIG_MESSAGE("[" __FILE__ "] main START");
  mcformat=getenv(FLAVOR_UPPER "_FORMAT") ?
           getenv(FLAVOR_UPPER "_FORMAT") : FLAVOR_UPPER;

  /* Set neutron state based on input from neutronics code */
  mcsetstate(*inx,*iny,*inz,*invx,*invy,*invz,*intime,*insx,*insy,*insz,*inw);

  /* main neutron event loop - runs only one iteration */

  //mcstas_raytrace(&mcncount); /* prior to McStas 1.12 */

  mcallowbackprop = 1; //avoid absorbtion from negative dt
  int argc=1;
  char *argv[0];
  int dummy = mccode_main(argc, argv);

  *outx =  mcnx;
  *outy =  mcny;
  *outz =  mcnz;
  *outvx =  mcnvx;
  *outvy =  mcnvy;
  *outvz =  mcnvz;
  *outtime =  mcnt;
  *outsx =  mcnsx;
  *outsy =  mcnsy;
  *outsz =  mcnsz;
  *outwgt =  mcnp;

  return;
} /* neutronics_main */

#endif /*NEUTRONICS*/

#endif /* !MCCODE_H */
/* End of file "mccode-r.c". */
/* End of file "mccode-r.c". */

/* embedding file "mcxtrace-r.c" */

/*******************************************************************************
*
* McXtrace, X-ray tracing package
*           Copyright (C) 1997-2009, All rights reserved
*           DTU Physics , Kgs. Lyngby, Denmark
*
* Runtime: share/mcxtrace-r.c
*
* %Identification
* Edited by: EK
* Date:    May 29, 2009
* Release: McXtrace X.Y
* Version: $Revision$
*
* Runtime system for McXtrace.
* Embedded within instrument in runtime mode.
*
* Usage: Automatically embedded in the c code whenever required.
*
*******************************************************************************/

#ifndef MCXTRACE_R_H
#include "mcxtrace-r.h"
#endif

/*******************************************************************************
* The I/O format definitions and functions
*******************************************************************************/

#ifndef MCXTRACE_H


/*******************************************************************************
* mcsetstate: transfer parameters into global McXtrace variables
*******************************************************************************/
_class_particle mcsetstate(double x, double y, double z, double kx, double ky, double kz,
			   double phi, double t, double Ex, double Ey, double Ez, double p, int mcgravitation, void *mcMagnet, int mcallowbackprop)
{
  _class_particle mcphoton;

  mcphoton.x  = x;
  mcphoton.y  = y;
  mcphoton.z  = z;
  mcphoton.kx = kx;
  mcphoton.ky = ky;
  mcphoton.kz = kz;
  mcphoton.phi  = phi;
  mcphoton.t  = t;
  mcphoton.Ex = Ex;
  mcphoton.Ey = Ey;
  mcphoton.Ez = Ez;
  mcphoton.p  = p;
  /*mcphoton.mcgravitation = mcgravitation;
  mcphoton.mcMagnet = mcMagnet;
  mcphoton.allow_backprop = mcallowbackprop;*/
  mcphoton._uid       = 0;
  mcphoton._index     = 1;
  mcphoton._absorbed  = 0;
  mcphoton._restore   = 0;
  mcphoton._scattered = 0;

  return(mcphoton);
} /* mcsetstate */

/*******************************************************************************
* mcgetstate: get photon parameters from particle structure
*******************************************************************************/
_class_particle mcgetstate(_class_particle mcphoton, double *x, double *y, double *z,
               double *kx, double *ky, double *kz, double *phi, double *t,
               double *Ex, double *Ey, double *Ez, double *p)
{
  *x  =  mcphoton.x;
  *y  =  mcphoton.y;
  *z  =  mcphoton.z;
  *kx =  mcphoton.kx;
  *ky =  mcphoton.ky;
  *kz =  mcphoton.kz;
  *phi  =  mcphoton.phi;
  *t  =  mcphoton.t;
  *Ex =  mcphoton.Ex;
  *Ey =  mcphoton.Ey;
  *Ez =  mcphoton.Ez;
  *p  =  mcphoton.p;

  return(mcphoton);
} /* mcgetstate */


/*******************************************************************************
* mcgenstate: set default photon parameters 
*******************************************************************************/
/*moved to generated code*/
/*#pragma acc routine seq*/
/*_class_particle mcgenstate(void)*/
/*{*/
/*  return(mcsetstate(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, mcgravitation, mcMagnet, mcallowbackprop));*/
/*}*/

/*******************************************************************************
* mccoordschanges: old style rotation routine rot -> (x y z) ,(vx vy vz),(sx,sy,sz)
*******************************************************************************/
void
mccoordschanges(Coords a, Rotation t, double *x, double *y, double *z,
               double *kx, double *ky, double *kz, double *Ex, double *Ey, double *Ez)
{
  Coords b, c;

  b.x = *x;
  b.y = *y;
  b.z = *z;
  c = rot_apply(t, b);
  b = coords_add(c, a);
  *x = b.x;
  *y = b.y;
  *z = b.z;

  if ( (kz && ky  && kx) && (*kz != 0.0 || *kx != 0.0 || *ky != 0.0) )
    mccoordschange_polarisation(t, kx, ky, kz);

  if ( (Ez && Ey  && Ex) && (*Ez != 0.0 || *Ex != 0.0 || *Ey != 0.0) )
    mccoordschange_polarisation(t, Ex, Ey, Ez);

}

/* intersection routines ==================================================== */

/*******************************************************************************
* inside_rectangle: Check if (x,y) is inside rectangle (xwidth, yheight)
* return 0 if outside and 1 if inside
*******************************************************************************/
int inside_rectangle(double x, double y, double xwidth, double yheight)
{
  if (x>-xwidth/2 && x<xwidth/2 && y>-yheight/2 && y<yheight/2)
    return 1;
  else
    return 0;
}

/*******************************************************************************
 * box_intersect: compute length intersection with a box
 * returns 0 when no intersection is found
 *      or 1 in case of intersection with resulting lengths dl_in and dl_out
*******************************************************************************/
int box_intersect(double *dl_in, double *dl_out,
                  double x, double y, double z,
                  double kx, double ky, double kz,
                  double dx, double dy, double dz)
{

  double k, l,xf,yf,zf, l_[6],dx_2,dy_2,dz_2;
  double ab[2];
  unsigned int count=0;
  k=sqrt(scalar_prod(kx,ky,kz,kx,ky,kz));
  dx_2=dx/2.0;dy_2=dy/2.0;dz_2=dz/2.0; 
  /*we really don't need to store the 6 intersects as only two are possible. i.e. should remove that.*/
  if (kx) {
    l=(-dx_2-x)/kx*k;
    yf=l*ky/k+y;zf=l*kz/k+z;
    if(yf > -dy_2 && yf<dy_2 && zf > -dz_2 && zf<dz_2){
      l_[0]=l;
      ab[count++]=l_[0];
    }else{
      l_[0]=0;
    }
    l=(dx_2-x)/kx*k;
    yf=l*ky/k+y;zf=l*kz/k+z;
    if(yf > -dy_2 && yf<dy_2 && zf > -dz_2 && zf<dz_2){
      l_[1]=l;
      ab[count++]=l_[1];
    }else{
      l_[1]=0;
    }
  }
  if (ky) {
    l=(-dy_2-y)/ky*k;
    xf=l*kx/k+x;zf=l*kz/k+z;
    if(xf > -dx_2 && xf<dx_2 && zf > -dz_2 && zf<dz_2){
      l_[2]=l;
      ab[count++]=l_[2];
    }else{
      l_[2]=0;
    } 
    l=(dy_2-y)/ky*k;
    xf=l*kx/k+x;zf=l*kz/k+z;
    if(xf > -dx_2 && xf<dx_2 && zf > -dz_2 && zf<dz_2){
      l_[3]=l;
      ab[count++]=l_[3];
    }else{
      l_[3]=0;
    }
  }
  if (kz) {
    l=(-dz_2-z)/kz*k;
    xf=l*kx/k+x; yf=l*ky/k+y;
    if(xf > -dx_2 && xf<dx_2 && yf > -dy_2 && yf<dy_2){
      l_[4]=l;
      ab[count++]=l_[4];
    }else{
      l_[4]=0;
    }
    l=(dz_2-z)/kz*k;
    xf=l*kx/k+x; yf=l*ky/k+y;
    if(xf > -dx_2 && xf<dx_2 && yf > -dy_2 && yf<dy_2){
      l_[5]=l;
      ab[count++]=l_[5];
    }else{
      l_[5]=0;
    }
  }
  if (!count){
    *dl_in=0;*dl_out=0;
    return 0;
  }

  if (ab[0]<ab[1]){
    *dl_in=ab[0];*dl_out=ab[1];
    return 1;
  }else{
    *dl_in=ab[1];*dl_out=ab[0];
    return 1;
  }

} /* box_intersect */

/*******************************************************************************
 * cylinder_intersect: compute intersection with a cylinder
 * returns 0 when no intersection is found
 *      or 1/2/4/8/16 bits depending on intersection,
 *     and resulting times l0 and l1
 * Written by: EK 11.6.09 
 *******************************************************************************/
int cylinder_intersect(double *l0, double *l1, double x, double y, double z,
                   double kx, double ky, double kz, double r, double h)
{
  double A,B,C,D,k2,k;
  double dl1p=0,dl0p=0,dl1c=0,dl0c=0,y0,y1;
  int ret=1,stat=0,plane_stat=0;
  enum {HIT_CYL=01,ENTER_TOP=02,ENTER_BOT=04,EXIT_TOP=010,EXIT_BOT=020,ENTER_MASK=06,EXIT_MASK=030};
  k2=(kx*kx + ky*ky + kz*kz);
  k=sqrt(k2);

  /*check for prop. vector 0*/
  if(!k2) return 0;

  A= (k2 - ky*ky);
  B= 2*(x*kx + z*kz);
  C=(x*x + z*z - r*r);
  D=B*B-4*A*C;
  if(D>=0){
    if (kx || kz){
      stat|=HIT_CYL;
    /*propagation not parallel to y-axis*/
    /*hit infinitely high cylinder?*/
      D=sqrt(D);
      dl0c=k*(-B-D)/(2*A);
      dl1c=k*(-B+D)/(2*A);
      y0=dl0c*ky/k+y;
      y1=dl1c*ky/k+y;
      if ( (y0<-h/2 && y1<-h/2) || (y0>h/2 && y1>h/2) ){
        /*ray passes above or below cylinder*/
        return 0;
      }
    }
    /*now check top and bottom planes*/
    if (ky){
      dl0p = k*(-h/2-y)/ky;
      dl1p = k*(h/2-y)/ky;
      /*switch solutions?*/
      if (dl0p<dl1p){
        plane_stat|=(ENTER_BOT|EXIT_TOP);
      }else{
        double tmp=dl1p;
        dl1p=dl0p;dl0p=tmp;
        plane_stat|=(ENTER_TOP|EXIT_BOT);
      }
    }
  }
  if (stat & HIT_CYL){
    if (ky && dl0p>dl0c){
      *l0=dl0p;/*1st top/bottom plane intersection happens after 1st cylinder intersect*/
      stat|= plane_stat & ENTER_MASK;
    } else
      *l0=dl0c;
    if(ky && dl1p<dl1c){
      *l1=dl1p;/*2nd top/bottom plane intersection happens before 2nd cylinder intersect*/
      stat|= plane_stat & EXIT_MASK;
    }else
      *l1=dl1c;
  }
  return stat;
} /* cylinder_intersect */


/*******************************************************************************
 * sphere_intersect: Calculate intersection between a line and a sphere.
 * returns 0 when no intersection is found
 *      or 1 in case of intersection with resulting lengths l0 and l1 
 *******************************************************************************/
#pragma acc routine seq
int sphere_intersect(double *l0, double *l1, double x, double y, double z,
                 double kx, double ky, double kz, double r)
{
  double B, C, D, k;

  k = kx*kx + ky*ky + kz*kz;
  B = (x*kx + y*ky + z*kz);
  C = x*x + y*y + z*z - r*r;
  D = B*B - k*C;
  if(D < 0)
    return 0;
  D = sqrt(D);
  *l0 = (-B - D) / sqrt(k);
  *l1 = (-B + D) / sqrt(k);
  return 1;
} /* sphere_intersect */

/******************************************************************************
 * ellipsoid_intersect: Calculate intersection between a line and an ellipsoid.
 * They ellisoid is fixed by a set of half-axis (a,b,c) and a matrix Q, with the
 * columns of Q being the (orthogonal) vectors along which the half-axis lie.
 * This allows for complete freedom in orienting the ellipsoid.
 * returns 0 when no intersection is found
 *      or 1 when they _are_ found with resulting lengths l0 and l1.
 *****************************************************************************/
int ellipsoid_intersect(double *l0, double *l1, double x, double y, double z,
    double kx, double ky, double kz, double a, double b, double c,
    Rotation Q)
{
  Rotation A,Gamma,Q_t,Tmp;
  double u,v,w;

  Gamma[0][0]=Gamma[0][1]=Gamma[0][2]=0;
  Gamma[1][1]=Gamma[1][0]=Gamma[1][2]=0;
  Gamma[2][2]=Gamma[2][0]=Gamma[2][1]=0;
  /* now set diagonal to ellipsoid half axis if non-zero.
   * This way a zero value means the ellipsoid extends infinitely along that axis,
   * which is useful for objects only curved in one direction*/ 
  if (a!=0){
    Gamma[0][0]=1/(a*a);
  }
  if (b!=0){
    Gamma[1][1]=1/(b*b);
  }
  if (c!=0){
    Gamma[2][2]=1/(c*c);
  }

  if (Q!=NULL){
    rot_transpose(Q,Q_t);
    rot_mul(Gamma,Q_t,Tmp);
    rot_mul(Q,Tmp,A);
  }else{
    rot_copy(A,Gamma);
  }

  /*to get the solutions as lengths in m use unit vector along k*/
  double ex,ey,ez,k;
  k=sqrt(kx*kx+ky*ky+kz*kz);
  ex=kx/k;
  ey=ky/k;
  ez=kz/k;

  u=ex*(A[0][0]*ex + A[1][0]*ey + A[2][0]*ez) + ey*( A[0][1]*ex + A[1][1]*ey + A[2][1]*ez) + ez*(A[0][2]*ex + A[1][2]*ey + A[2][2]*ez);
  v=x *(A[0][0]*ex + A[1][0]*ey + A[2][0]*ez) + ex*(A[0][0]*x + A[1][0]*y + A[2][0]*z) +
    y *(A[0][1]*ex + A[1][1]*ey + A[2][1]*ez) + ey*(A[0][1]*x + A[1][1]*y + A[2][1]*z) +
    z *(A[0][2]*ex + A[1][2]*ey + A[2][2]*ez) + ez*(A[0][2]*x + A[1][2]*y + A[2][2]*z);
  w=x*(A[0][0]*x + A[1][0]*y + A[2][0]*z) + y*(A[0][1]*x + A[1][1]*y + A[2][1]*z) + z*(A[0][2]*x + A[1][2]*y + A[2][2]*z);

  double D=v*v-4*u*w+4*u;
  if (D<0) return 0;

  D=sqrt(D);

  *l0=(-v-D) / (2*u);
  *l1=(-v+D) / (2*u);
  return 1;
}


/*******************************************************************************
 * plane_intersect: Calculate intersection between a plane (with normal n including the point w)
 * and a line through x along the direction k.
 * returns 0 when no intersection is found (i.e. line is parallel to the plane)
 * returns 1 or -1 when intersection length is positive and negative, respectively
 *******************************************************************************/
int plane_intersect(double *l, double x, double y, double z,
                 double kx, double ky, double kz, double nx, double ny, double nz, double wx, double wy, double wz)
{
  double s,k2;
  k2=scalar_prod(kx,ky,kz,kx,ky,kz);
  s=scalar_prod(kx,ky,kz,nx,ny,nz);
  if (k2<FLT_EPSILON || fabs(s)<FLT_EPSILON) return 0;
  *l = - sqrt(k2)*scalar_prod(nx,ny,nz,x-wx,y-wy,z-wz)/s;
  if (*l<0) return -1;
  else return 1;
} /* plane_intersect */

/*******************************************************************************
 * paraboloid_intersect: Calculate intersection between a rotational paraboloid
 * and a line with direction k through the point x,y,z.
 * The paraboloid is oriented such that it opens towards positive y,with the scaling
 * prms  a and b for x and y resp.. The paex is on the z=0-axis. I.e. the equation for the paraboloid is:
 * z=(x/a)^2 + (y/b)^2
 * If the other direction (opening towards z<0) is wanted simply set the sign parameter to -1
 *******************************************************************************/
int
paraboloid_intersect(double *l0, double *l1, double x, double y, double z,
    double kx, double ky, double kz, double a, double b, int sign)
{
  double A,B,C,D,k;
  double a2i,b2i;
  int retval=0;
  if(a!=0 && b!=0){
    a2i=1.0/(a*a);b2i=1.0/(b*b);
  }else if (a!=0){
    /*paraboloid is infinite/invariant along y, must check if k||y */
    if (kx==0 && kz==0){
      *l0=*l1=0;return 0;
    }
    a2i=1.0/(a*a);b2i=0;
  }else if (b!=0){
    /*paraboloid is infinite/invariant along x, must check if k||x */
    if (ky==0 && kz==0){
      *l0=*l1=0;return 0;
    }
    a2i=0;b2i=1.0/(b*b);
  }
  k=sqrt(kx*kx + ky*ky + kz*kz);

  A=sign*(kx*kx*a2i + ky*ky*b2i);
  B=sign*2*kx*x*a2i + sign*ky*y*b2i - kz;
  C=sign*x*x*a2i + sign*y*y*b2i - z;

  retval=solve_2nd_order(l0,l1,A,B,C);
  /*convert to solution in m*/
  *l0 *= k; *l1 *=k;
  return retval;
}

/******************************************************************************
 * paraboloid_normal: Calucate the normal vector to the given paraboloid at the
 * point (x,y,z) and put the result i nx,ny,nz. No check is performed if the
 * the point is on th surface. In that case the result is undefined.
 *****************************************************************************/
int paraboloid_normal(double *nx, double *ny, double *nz, double x,double y, double z, double a, double b, int sign){
  double a2i,b2i;
  double tx,ty,tz;
  if(a!=0 && b!=0){
    a2i=1.0/(a*a);b2i=1.0/(b*b);
  }else if (a!=0){
    a2i=1.0/(a*a);b2i=0;
  }else if (b!=0){
    a2i=0;b2i=1.0/(b*b);
  }else{
    *nx=0; *ny=0; *nz=1;
    return 1;
  }
  tx=-sign*2*x*a2i;
  ty=-sign*2*y*b2i;
  tz=1;
  NORM(tx,ty,tz);
  *nx=tx; *ny=ty; *nz=tz;
  return 1;
}



#endif /* !MCXTRACE_H */
/* End of file "mcxtrace-r.c". */


/* *****************************************************************************
* Start of instrument 'SOLEIL_PSICHE' generated code
***************************************************************************** */

#ifdef MC_TRACE_ENABLED
int traceenabled = 1;
#else
int traceenabled = 0;
#endif
#define MCXTRACE "/usr/share/mcxtrace/3.4-20240304/"
int   defaultmain         = 1;
char  instrument_name[]   = "SOLEIL_PSICHE";
char  instrument_source[] = "SOLEIL_PSICHE.instr";
char *instrument_exe      = NULL; /* will be set to argv[0] in main */
char  instrument_code[]   = "Instrument SOLEIL_PSICHE source code SOLEIL_PSICHE.instr is not embedded in this executable.\n  Use --source option when running McXtrace.\n";

int main(int argc, char *argv[]){return mccode_main(argc, argv);}

/* *****************************************************************************
* instrument 'SOLEIL_PSICHE' and components DECLARE
***************************************************************************** */

/* Instrument parameters: structure and a table for the initialisation
   (Used in e.g. inputparse and I/O function (e.g. detector_out) */

struct _struct_instrument_parameters {
  MCNUM E0;
  MCNUM dE;
  MCNUM DCM_present;
  MCNUM sample_theta;
  char* sample_material;
  char* sample_geometry;
  MCNUM dcm_theta;
};
typedef struct _struct_instrument_parameters _class_instrument_parameters;

struct _instrument_struct {
  char   _name[256]; /* the name of this instrument e.g. 'SOLEIL_PSICHE' */
/* Counters per component instance */
  double counter_AbsorbProp[20]; /* absorbed events in PROP routines */
  double counter_N[20], counter_P[20], counter_P2[20]; /* event counters after each component instance */
  _class_particle _trajectory[20]; /* current trajectory for STORE/RESTORE */
/* Components position table (absolute and relative coords) */
  Coords _position_relative[20]; /* positions of all components */
  Coords _position_absolute[20];
  _class_instrument_parameters _parameters; /* instrument parameters */
} _instrument_var;
struct _instrument_struct *instrument = & _instrument_var;
#pragma acc declare create ( _instrument_var )
#pragma acc declare create ( instrument )

int numipar = 7;
struct mcinputtable_struct mcinputtable[] = {
  "E0", &(_instrument_var._parameters.E0), instr_type_double, "31", "",
  "dE", &(_instrument_var._parameters.dE), instr_type_double, "1", "",
  "DCM_present", &(_instrument_var._parameters.DCM_present), instr_type_double, "0", "",
  "sample_theta", &(_instrument_var._parameters.sample_theta), instr_type_double, "0", "",
  "sample_material", &(_instrument_var._parameters.sample_material), instr_type_string, "Ag", "",
  "sample_geometry", &(_instrument_var._parameters.sample_geometry), instr_type_string, "wire.ply", "",
  "dcm_theta", &(_instrument_var._parameters.dcm_theta), instr_type_double, "0", "",
  NULL, NULL, instr_type_double, ""
};

struct metadata_table_struct metadata_table[] = {
  "", "", "", ""
};
int num_metadata = 0;

/* ************************************************************************** */
/*             SHARE user declarations for all components                     */
/* ************************************************************************** */

/* Shared user declarations for all components types 'Wiggler'. */
#ifndef MCCODE_BESSELKNU
#define MCCODE_BESSELKNU 1

#pragma acc routine seq
double besselKnu(double nu, double x){
    const double h=0.5;
    double KK=0,dK;
    int r=0;
    const int maxiter=1000;
    KK=exp(-x)/2.0;
    dK=1;
    while (dK>DBL_EPSILON && r<maxiter){
      r++;
      dK=exp(-x*cosh(r*h))*cosh(nu*r*h);
      KK+=dK;
    }
#ifndef OPENACC
    if (r>=maxiter) {
      fprintf(stderr,"Warning: Maximum number of iterations exceeded in besselKnu(%g,%g).\n",nu,x);
    }
#endif
    KK*=h;
    return KK;
  }
#endif /*MCCODE_BESSELKNU*/

#ifndef M_SQRT1_2
#define M_SQRT1_2 0.70710678118654752440
#endif


/* Shared user declarations for all components types 'Monitor_nD'. */
/*******************************************************************************
*
* McXtrace, x-ray-tracing package
*         Copyright 1997-2013, All rights reserved
*         DTU Physics, Kgs. Lyngby, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/monitor_nd-lib.h
*
* %Identification
* Written by: EF
* Date: Aug 28, 2002
* Origin: ILL
* Release: McXtrace 0.9
* Version: $Revision$
*
* This file is to be imported by the monitor_nd related components
* It handles some shared functions.
*
* Usage: within SHARE
* %include "monitor_nd-lib"
*
*******************************************************************************/

#ifndef MONITOR_ND_LIB_H

#define MONITOR_ND_LIB_H "$Revision$"
#define MONnD_COORD_NMAX  30  /* max number of variables to record */

  typedef struct MonitornD_Defines
  {
    int COORD_NONE  ;
    int COORD_X     ;
    int COORD_Y     ;
    int COORD_Z     ;
    int COORD_RADIUS; 
    int COORD_VX    ;
    int COORD_VY    ;
    int COORD_VZ    ;
    int COORD_V     ;
    int COORD_T     ;
    int COORD_P     ;
    int COORD_EX    ;
    int COORD_EY    ;
    int COORD_EZ    ;
    int COORD_KX    ;
    int COORD_KY    ;
    int COORD_KZ    ;
    int COORD_K     ;
    int COORD_ENERGY;
    int COORD_LAMBDA;
    int COORD_KXY   ;
    int COORD_KYZ   ;
    int COORD_KXZ   ;
    int COORD_VXY   ;
    int COORD_VYZ   ;
    int COORD_VXZ   ;
    int COORD_HDIV  ;
    int COORD_VDIV  ;
    int COORD_ANGLE ;
    int COORD_NCOUNT;
    int COORD_THETA ;
    int COORD_PHI   ;
    int COORD_USER1 ;
    int COORD_USER2 ;
    int COORD_USER3 ;
    int COORD_XY    ;
    int COORD_XZ    ;
    int COORD_YZ    ;
    int COORD_PHASE ;
    int COORD_PIXELID;

    /* token modifiers */
    int COORD_VAR   ; /* next token should be a variable or normal option */
    int COORD_MIN   ; /* next token is a min value */
    int COORD_MAX   ; /* next token is a max value */
    int COORD_DIM   ; /* next token is a bin value */
    int COORD_FIL   ; /* next token is a filename */
    int COORD_EVNT  ; /* next token is a buffer size value */
    //int COORD_3HE   ; /* next token is a 3He pressure value */
    int COORD_LOG   ; /* next variable will be in log scale */
    int COORD_ABS   ; /* next variable will be in abs scale */
    int COORD_SIGNAL; /* next variable will be the signal var */
    int COORD_AUTO  ; /* set auto limits */

    char TOKEN_DEL[32]; /* token separators */

    char SHAPE_SQUARE; /* shape of the monitor */
    char SHAPE_DISK  ;
    char SHAPE_SPHERE;
    char SHAPE_CYLIND;
    char SHAPE_BANANA; /* cylinder without top/bottom, on restricted angular area */
    char SHAPE_BOX   ;
    char SHAPE_PREVIOUS;
    char SHAPE_OFF;

  } MonitornD_Defines_type;

  typedef struct MonitornD_Variables
  {
    double area;
    double Sphere_Radius     ;
    double Cylinder_Height   ;
    char   Flag_With_Borders ;   /* 2 means xy borders too */
    char   Flag_List         ;   /* 1 store 1 buffer, 2 is list all, 3 list all+append */
    char   Flag_Multiple     ;   /* 1 when n1D, 0 for 2D */
    char   Flag_Verbose      ;
    int    Flag_Shape        ;
    char   Flag_Auto_Limits  ;   /* get limits from first Buffer */
    char   Flag_Absorb       ;   /* monitor is also a slit */
    char   Flag_per_cm2      ;   /* flux is per cm2 */
    char   Flag_log          ;   /* log10 of the flux */
    char   Flag_parallel     ;   /* set photon state back after detection (parallel components) */
    char   Flag_Binary_List  ;
    char   Flag_capture      ;   /* lambda monitor with lambda/lambda(2200m/s = 1.7985 Angs) weightening */
    int    Flag_signal       ;   /* 0:monitor p, else monitor a mean value */
    int    Flag_OFF          ;   /* Flag to indicate external geometry from OFF file */
    unsigned long OFF_polyidx;   /* When intersection is done externally by off_intersect, this gives the 
				    polygon number, i.e. pixel index */

    unsigned long Coord_Number      ;   /* total number of variables to monitor, plus intensity (0) */
    unsigned long Coord_NumberNoPixel;  /* same but without counting PixelID */
    unsigned long Buffer_Block      ;   /* Buffer size for list or auto limits */
    unsigned long Photon_Counter    ;   /* event counter, simulation total counts is mcget_ncount() */
    unsigned long Buffer_Counter    ;   /* index in Buffer size (for realloc) */
    unsigned long Buffer_Size       ;
    int    Coord_Type[MONnD_COORD_NMAX];      /* type of variable */
    char   Coord_Label[MONnD_COORD_NMAX][30]; /* label of variable */
    char   Coord_Var[MONnD_COORD_NMAX][30];   /* short id of variable */
    long   Coord_Bin[MONnD_COORD_NMAX];       /* bins of variable array */
    long   Coord_BinProd[MONnD_COORD_NMAX];   /* product of bins of variable array */
    double Coord_Min[MONnD_COORD_NMAX];
    double Coord_Max[MONnD_COORD_NMAX];
    char   Monitor_Label[MONnD_COORD_NMAX*30];/* Label for monitor */
    char   Mon_File[128];                     /* output file name */

    /* these don't seem to be used anymore as they are superseded by _particle
    double cx, cy, cz;
    double cvx, cvy, cvz;
    double ckx, cky, ckz;
    double cEx, cEy, cEz;
    double ct, cphi, cp;*/
    double He3_pressure;
    char   Flag_UsePreMonitor    ;   /* use a previously stored photon parameter set */
    char   UserName1[128];
    char   UserName2[128];
    char   UserName3[128];
    char   UserVariable1[128];
    char   UserVariable2[128];
    char   UserVariable3[128];
    char   option[CHAR_BUF_LENGTH];

    long long int Nsum;
    double psum, p2sum;
    double **Mon2D_N;
    double **Mon2D_p;
    double **Mon2D_p2;
    double *Mon2D_Buffer;
    unsigned long PixelID;

    double mxmin,mxmax,mymin,mymax,mzmin,mzmax;
    double mean_dx, mean_dy, min_x, min_y, max_x, max_y, mean_p;

    char   compcurname[128];
    Coords compcurpos;

  } MonitornD_Variables_type;

/* monitor_nd-lib function prototypes */
/* ========================================================================= */

void Monitor_nD_Init(MonitornD_Defines_type *, MonitornD_Variables_type *, MCNUM, MCNUM, MCNUM, MCNUM, MCNUM, MCNUM, MCNUM, MCNUM, MCNUM, int);
#pragma acc routine
int Monitor_nD_Trace(MonitornD_Defines_type *, MonitornD_Variables_type *, _class_particle* _particle);
MCDETECTOR Monitor_nD_Save(MonitornD_Defines_type *, MonitornD_Variables_type *);
void Monitor_nD_Finally(MonitornD_Defines_type *, MonitornD_Variables_type *);
void Monitor_nD_McDisplay(MonitornD_Defines_type *, MonitornD_Variables_type *);

#endif

/* end of monitor_nd-lib.h */
/*******************************************************************************
*
* McXtrace, x-ray-tracing package
*         Copyright 1997-2013, All rights reserved
*         DTU Physics, Kgs. Lyngby, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/monitor_nd-lib.c
*
* %Identification
* Written by: EF
* Date: Aug 28, 2002
* Origin: ILL
* Release: McXtrace 0.9
* Version: $Revision$
*
* This file is to be imported by the monitor_nd related components
* It handles some shared functions. Embedded within instrument in runtime mode.
*
* Usage: within SHARE
* %include "monitor_nd-lib"
*
*******************************************************************************/

#ifndef MONITOR_ND_LIB_H
#error McXtrace : please import this library with %include "monitor_nd-lib"
#endif

/* ========================================================================= */
/* Monitor_nD_Init: this routine is used to parse options                    */
/* ========================================================================= */

void Monitor_nD_Init(MonitornD_Defines_type *DEFS,
  MonitornD_Variables_type *Vars,
  MCNUM xwidth,
  MCNUM yheight,
  MCNUM zdepth,
  MCNUM xmin,
  MCNUM xmax,
  MCNUM ymin,
  MCNUM ymax,
  MCNUM zmin,
  MCNUM zmax,
  int offflag)
  {
    long carg = 1;
    char *option_copy, *token;
    char Flag_New_token = 1;
    char Flag_End       = 1;
    char Flag_All       = 0;
    char Flag_No        = 0;
    char Flag_abs       = 0;
    int  Flag_auto      = 0;  /* -1: all, 1: the current variable */
    int  Set_Vars_Coord_Type;
    char Set_Vars_Coord_Label[64];
    char Set_Vars_Coord_Var[64];
    char Short_Label[MONnD_COORD_NMAX][64];
    int  Set_Coord_Mode;
    long i=0, j=0;
    double lmin, lmax, XY=0;
    long t;


    t = (long)time(NULL);

/* initialize DEFS */
/* Variables to monitor */
    DEFS->COORD_NONE   =0;
    DEFS->COORD_X      =1;
    DEFS->COORD_Y      =2;
    DEFS->COORD_Z      =3;
    DEFS->COORD_RADIUS =19;
    DEFS->COORD_VX     =4;
    DEFS->COORD_VY     =5;
    DEFS->COORD_VZ     =6;
    DEFS->COORD_V      =16;
    DEFS->COORD_PHASE  =39;
    DEFS->COORD_T      =7;
    DEFS->COORD_P      =8;
    DEFS->COORD_EX     =9;
    DEFS->COORD_EY     =10;
    DEFS->COORD_EZ     =11;
    DEFS->COORD_KX     =12;
    DEFS->COORD_KY     =13;
    DEFS->COORD_KZ     =14;
    DEFS->COORD_K      =15;
    DEFS->COORD_ENERGY =17;
    DEFS->COORD_LAMBDA =18;
    DEFS->COORD_HDIV   =20;
    DEFS->COORD_VDIV   =21;
    DEFS->COORD_ANGLE  =22;
    DEFS->COORD_NCOUNT =23;
    DEFS->COORD_THETA  =24;
    DEFS->COORD_PHI    =25;
    DEFS->COORD_USER1  =26;
    DEFS->COORD_USER2  =27;
    DEFS->COORD_USER3  =28;
    DEFS->COORD_XY     =37;
    DEFS->COORD_YZ     =31;
    DEFS->COORD_XZ     =32;
    DEFS->COORD_VXY    =30;
    DEFS->COORD_VYZ    =34;
    DEFS->COORD_VXZ    =36;
    DEFS->COORD_KXY    =29;
    DEFS->COORD_KYZ    =33;
    DEFS->COORD_KXZ    =35;
    DEFS->COORD_PIXELID=38;

/* token modifiers */
    DEFS->COORD_VAR    =0;    /* next token should be a variable or normal option */
    DEFS->COORD_MIN    =1;    /* next token is a min value */
    DEFS->COORD_MAX    =2;    /* next token is a max value */
    DEFS->COORD_DIM    =3;    /* next token is a bin value */
    DEFS->COORD_FIL    =4;    /* next token is a filename */
    DEFS->COORD_EVNT   =5;    /* next token is a buffer size value */
    //DEFS->COORD_3HE    =6;    /* next token is a 3He pressure value */
    DEFS->COORD_LOG    =64;   /* next variable will be in log scale */
    DEFS->COORD_ABS    =128;  /* next variable will be in abs scale */
    DEFS->COORD_SIGNAL =256;  /* next variable will be the signal var */
    DEFS->COORD_AUTO   =512;  /* set auto limits */

    strcpy(DEFS->TOKEN_DEL, " =,;[](){}:");  /* token separators */

    DEFS->SHAPE_SQUARE =0;    /* shape of the monitor */
    DEFS->SHAPE_DISK   =1;
    DEFS->SHAPE_SPHERE =2;
    DEFS->SHAPE_CYLIND =3;
    DEFS->SHAPE_BANANA =4;
    DEFS->SHAPE_BOX    =5;
    DEFS->SHAPE_PREVIOUS=6;
    DEFS->SHAPE_OFF=7;

    Vars->Sphere_Radius     = 0;
    Vars->Cylinder_Height   = 0;
    Vars->Flag_With_Borders = 0;   /* 2 means xy borders too */
    Vars->Flag_List         = 0;   /* 1=store 1 buffer, 2=list all, 3=re-use buffer */
    Vars->Flag_Multiple     = 0;   /* 1 when n1D, 0 for 2D */
    Vars->Flag_Verbose      = 0;
    Vars->Flag_Shape        = DEFS->SHAPE_SQUARE;
    Vars->Flag_Auto_Limits  = 0;   /* get limits from first Buffer */
    Vars->Flag_Absorb       = 0;   /* monitor is also a slit */
    Vars->Flag_per_cm2      = 0;   /* flux is per cm2 */
    Vars->Flag_log          = 0;   /* log10 of the flux */
    Vars->Flag_parallel     = 0;   /* set photon state back after detection (parallel components) */
    Vars->Flag_Binary_List  = 0;   /* save list as a binary file (smaller) */
    Vars->Coord_Number      = 0;   /* total number of variables to monitor, plus intensity (0) */
    Vars->Coord_NumberNoPixel=0;   /* same but without counting PixelID */

/* Allow to specify size of Monitor_nD buffer via a define*/
#ifndef MONND_BUFSIZ
    Vars->Buffer_Block      = 100000;     /* Buffer size for list or auto limits */
#else
	Vars->Buffer_Block      = MONND_BUFSIZ;     /* Buffer size for list or auto limits */	
#endif
    Vars->Photon_Counter   = 0;   /* event counter, simulation total counts is mcget_ncount() */
    Vars->Buffer_Counter    = 0;   /* index in Buffer size (for realloc) */
    Vars->Buffer_Size       = 0;
    Vars->He3_pressure      = 0;
    Vars->Flag_capture      = 0;
    Vars->Flag_signal       = DEFS->COORD_P;
    Vars->Flag_OFF          = offflag;
    Vars->OFF_polyidx       = -1;
    Vars->mean_dx=Vars->mean_dy=0;
    Vars->min_x = Vars->max_x  =0;
    Vars->min_y = Vars->max_y  =0;

    Set_Vars_Coord_Type = DEFS->COORD_NONE;
    Set_Coord_Mode = DEFS->COORD_VAR;

    /* handle size parameters */
    /* normal use is with xwidth, yheight, zdepth */
    /* if xmin,xmax,ymin,ymax,zmin,zmax are non 0, use them */
    if (fabs(xmin-xmax) == 0)
      { Vars->mxmin = -fabs(xwidth)/2; Vars->mxmax = fabs(xwidth)/2; }
    else
      { if (xmin < xmax) {Vars->mxmin = xmin; Vars->mxmax = xmax;}
        else {Vars->mxmin = xmax; Vars->mxmax = xmin;}
      }
    if (fabs(ymin-ymax) == 0)
      { Vars->mymin = -fabs(yheight)/2; Vars->mymax = fabs(yheight)/2; }
    else
      { if (ymin < ymax) {Vars->mymin = ymin; Vars->mymax = ymax;}
        else {Vars->mymin = ymax; Vars->mymax = ymin;}
      }
    if (fabs(zmin-zmax) == 0)
      { Vars->mzmin = -fabs(zdepth)/2; Vars->mzmax = fabs(zdepth)/2; }
    else
      { if (zmin < zmax) {Vars->mzmin = zmin; Vars->mzmax = zmax; }
        else {Vars->mzmin = zmax; Vars->mzmax = zmin; }
      }

    if (fabs(Vars->mzmax-Vars->mzmin) == 0)
      Vars->Flag_Shape        = DEFS->SHAPE_SQUARE;
    else
      Vars->Flag_Shape        = DEFS->SHAPE_BOX;

    if (Vars->Flag_OFF) {
      Vars->Flag_Shape        = DEFS->SHAPE_OFF;
    }
    
    /* parse option string */

    option_copy = (char*)malloc(strlen(Vars->option)+1);
    if (option_copy == NULL)
    {
      fprintf(stderr,"Monitor_nD: %s cannot allocate 'options' copy (%li). Fatal.\n", Vars->compcurname, (long)strlen(Vars->option));
      exit(-1);
    }

    if (strlen(Vars->option))
    {
      Flag_End = 0;
      strcpy(option_copy, Vars->option);
    }

    if (strstr(Vars->option, "cm2") || strstr(Vars->option, "cm^2")) Vars->Flag_per_cm2 = 1;

    if (strstr(Vars->option, "binary") || strstr(Vars->option, "float"))
      Vars->Flag_Binary_List  = 1;
    if (strstr(Vars->option, "double"))
      Vars->Flag_Binary_List  = 2;

    strcpy(Vars->Coord_Label[0], "Intensity");
    strncpy(Vars->Coord_Var[0], "p", 30);
    Vars->Coord_Type[0] = DEFS->COORD_P;
    Vars->Coord_Bin[0] = 1;
    Vars->Coord_Min[0] = 0;
    Vars->Coord_Max[0] = FLT_MAX;

    /* default file name is comp_name+dateID */
    sprintf(Vars->Mon_File, "%s_%li", Vars->compcurname, t);

    carg = 1;
    while((Flag_End == 0) && (carg < 128))
    {
      if (Flag_New_token) /* retain previous token or get a new one */
      {
        if (carg == 1) token=(char *)strtok(option_copy,DEFS->TOKEN_DEL);
        else token=(char *)strtok(NULL,DEFS->TOKEN_DEL);
        if (token == NULL) Flag_End=1;
      }
      Flag_New_token = 1;
      if ((token != NULL) && (strlen(token) != 0))
      {
        char iskeyword=0; /* left at 0 when variables are processed, 1 for modifiers */
        int  old_Mode;
        /* change token to lower case */
        for (i=0; i<strlen(token); i++) token[i]=tolower(token[i]);
        /* first handle option values from preceeding keyword token detected */
        old_Mode = Set_Coord_Mode;
        if (Set_Coord_Mode == DEFS->COORD_MAX)  /* max=%i */
        {
          if (!Flag_All)
            Vars->Coord_Max[Vars->Coord_Number] = atof(token);
          else
            for (i = 0; i <= Vars->Coord_Number; Vars->Coord_Max[i++] = atof(token));
          Set_Coord_Mode = DEFS->COORD_VAR; Flag_All = 0;
        }
        if (Set_Coord_Mode == DEFS->COORD_MIN)  /* min=%i */
        {
          if (!Flag_All)
            Vars->Coord_Min[Vars->Coord_Number] = atof(token);
          else
            for (i = 0; i <= Vars->Coord_Number; Vars->Coord_Min[i++] = atof(token));
          Set_Coord_Mode = DEFS->COORD_MAX;
        }
        if (Set_Coord_Mode == DEFS->COORD_DIM)  /* bins=%i */
        {
          if (!Flag_All)
            Vars->Coord_Bin[Vars->Coord_Number] = atoi(token);
          else
            for (i = 0; i <= Vars->Coord_Number; Vars->Coord_Bin[i++] = atoi(token));
          Set_Coord_Mode = DEFS->COORD_VAR; Flag_All = 0;
        }
        if (Set_Coord_Mode == DEFS->COORD_FIL)  /* file=%s */
        {
          if (!Flag_No) strncpy(Vars->Mon_File,token,128);
          else { strcpy(Vars->Mon_File,""); Vars->Coord_Number = 0; Flag_End = 1;}
          Set_Coord_Mode = DEFS->COORD_VAR;
        }
        if (Set_Coord_Mode == DEFS->COORD_EVNT) /* list=%i */
        {
          if (!strcmp(token, "all") || Flag_All) Vars->Flag_List = 2;
          else { i = (long)ceil(atof(token)); if (i) Vars->Buffer_Block = i;
            Vars->Flag_List = 1; }
          Set_Coord_Mode = DEFS->COORD_VAR; Flag_All = 0;
        }
        /*if (Set_Coord_Mode == DEFS->COORD_3HE)*/  /* pressure=%g */
        /*{*/
        /*    Vars->He3_pressure = atof(token);*/
        /*    Set_Coord_Mode = DEFS->COORD_VAR; Flag_All = 0;*/
        /*}*/

        /* now look for general option keywords */
        if (!strcmp(token, "borders"))  {Vars->Flag_With_Borders = 1; iskeyword=1; }
        if (!strcmp(token, "verbose"))  {Vars->Flag_Verbose      = 1; iskeyword=1; }
        if (!strcmp(token, "log"))      {Vars->Flag_log          = 1; iskeyword=1; }
        if (!strcmp(token, "abs"))      {Flag_abs                = 1; iskeyword=1; }
        if (!strcmp(token, "multiple")) {Vars->Flag_Multiple     = 1; iskeyword=1; }
        if (!strcmp(token, "list") || !strcmp(token, "events")) {
          Vars->Flag_List = 1; Set_Coord_Mode = DEFS->COORD_EVNT;  }
        if (!strcmp(token, "limits") || !strcmp(token, "min"))
          Set_Coord_Mode = DEFS->COORD_MIN;
        if (!strcmp(token, "slit") || !strcmp(token, "absorb")) {
          Vars->Flag_Absorb = 1;  iskeyword=1; }
        if (!strcmp(token, "max"))  Set_Coord_Mode = DEFS->COORD_MAX;
        if (!strcmp(token, "bins") || !strcmp(token, "dim")) Set_Coord_Mode = DEFS->COORD_DIM;
        if (!strcmp(token, "file") || !strcmp(token, "filename")) {
          Set_Coord_Mode = DEFS->COORD_FIL;
          if (Flag_No) { strcpy(Vars->Mon_File,""); Vars->Coord_Number = 0; Flag_End = 1; }
        }
        if (!strcmp(token, "unactivate")) {
          Flag_End = 1; Vars->Coord_Number = 0; iskeyword=1; }
        if (!strcmp(token, "all"))    { Flag_All = 1;  iskeyword=1; }
        if (!strcmp(token, "sphere")) { Vars->Flag_Shape = DEFS->SHAPE_SPHERE; iskeyword=1; }
        if (!strcmp(token, "cylinder")) { Vars->Flag_Shape = DEFS->SHAPE_CYLIND; iskeyword=1; }
        if (!strcmp(token, "banana")) { Vars->Flag_Shape = DEFS->SHAPE_BANANA; iskeyword=1; }
        if (!strcmp(token, "square")) { Vars->Flag_Shape = DEFS->SHAPE_SQUARE; iskeyword=1; }
        if (!strcmp(token, "disk"))   { Vars->Flag_Shape = DEFS->SHAPE_DISK; iskeyword=1; }
        if (!strcmp(token, "box"))     { Vars->Flag_Shape = DEFS->SHAPE_BOX; iskeyword=1; }
        if (!strcmp(token, "previous")) { Vars->Flag_Shape = DEFS->SHAPE_PREVIOUS; iskeyword=1; }
        if (!strcmp(token, "parallel")){ Vars->Flag_parallel = 1; iskeyword=1; }
        if (!strcmp(token, "capture")) { Vars->Flag_capture = 1; iskeyword=1; }
        if (!strcmp(token, "auto")) { 
        #ifndef OPENACC
          if (Flag_auto != -1) {
	    Vars->Flag_Auto_Limits = 1;
	    if (Flag_All) Flag_auto = -1;
	    else          Flag_auto = 1;
	    iskeyword=1; Flag_All=0;
	  }
	#endif
	}
        if (!strcmp(token, "premonitor")) {
          Vars->Flag_UsePreMonitor = 1; iskeyword=1; }
        if (!strcmp(token, "3He_pressure") || !strcmp(token, "pressure")) {
          Vars->He3_pressure = 3; iskeyword=1; }
        if (!strcmp(token, "no") || !strcmp(token, "not")) { Flag_No = 1;  iskeyword=1; }
        if (!strcmp(token, "signal")) Set_Coord_Mode = DEFS->COORD_SIGNAL;

        /* Mode has changed: this was a keyword or value  ? */
        if (Set_Coord_Mode != old_Mode) iskeyword=1;

        /* now look for variable names to monitor */
        Set_Vars_Coord_Type = DEFS->COORD_NONE; lmin = 0; lmax = 0;

        if (!strcmp(token, "x"))
          { Set_Vars_Coord_Type = DEFS->COORD_X; strcpy(Set_Vars_Coord_Label,"x [m]"); strcpy(Set_Vars_Coord_Var,"x");
          lmin = Vars->mxmin; lmax = Vars->mxmax;
          Vars->Coord_Min[Vars->Coord_Number+1] = Vars->mxmin;
          Vars->Coord_Max[Vars->Coord_Number+1] = Vars->mxmax;}
        if (!strcmp(token, "y"))
          { Set_Vars_Coord_Type = DEFS->COORD_Y; strcpy(Set_Vars_Coord_Label,"y [m]"); strcpy(Set_Vars_Coord_Var,"y");
          lmin = Vars->mymin; lmax = Vars->mymax;
          Vars->Coord_Min[Vars->Coord_Number+1] = Vars->mymin;
          Vars->Coord_Max[Vars->Coord_Number+1] = Vars->mymax;}
        if (!strcmp(token, "z"))
          { Set_Vars_Coord_Type = DEFS->COORD_Z; strcpy(Set_Vars_Coord_Label,"z [m]"); strcpy(Set_Vars_Coord_Var,"z"); lmin = Vars->mzmin; lmax = Vars->mzmax; }
        if (!strcmp(token, "k") || !strcmp(token, "wavevector"))
          { Set_Vars_Coord_Type = DEFS->COORD_K; strcpy(Set_Vars_Coord_Label,"|k| [Angs-1]"); strcpy(Set_Vars_Coord_Var,"k"); lmin = 0; lmax = 10; }
        if (!strcmp(token, "v"))
          { Set_Vars_Coord_Type = DEFS->COORD_V; strcpy(Set_Vars_Coord_Label,"Velocity [m/s]"); strcpy(Set_Vars_Coord_Var,"v"); lmin = 0; lmax = 10000; }
        if (!strcmp(token, "t") || !strcmp(token, "time") || !strcmp(token, "tof"))
          { Set_Vars_Coord_Type = DEFS->COORD_T; strcpy(Set_Vars_Coord_Label,"TOF [s]"); strcpy(Set_Vars_Coord_Var,"t"); lmin = 0; lmax = .1; }
        if (!strcmp(token, "phase"))
        { Set_Vars_Coord_Type = DEFS->COORD_PHASE; strcpy(Set_Vars_Coord_Label,"phase [rad]"); strcpy(Set_Vars_Coord_Var,"pha"); lmin = 0; lmax = 2*M_PI; }
        if ((!strcmp(token, "p") || !strcmp(token, "i") || !strcmp(token, "intensity") || !strcmp(token, "flux")))
          { Set_Vars_Coord_Type = DEFS->COORD_P;
            strcpy(Set_Vars_Coord_Label,"Intensity");
            strncat(Set_Vars_Coord_Label, " [p/s", 30);
            if (Vars->Flag_per_cm2) strncat(Set_Vars_Coord_Label, "/cm2", 30);
            if (XY > 1 && Vars->Coord_Number)
              strncat(Set_Vars_Coord_Label, "/bin", 30);
            strncat(Set_Vars_Coord_Label, "]", 30);
            strcpy(Set_Vars_Coord_Var,"I");
            lmin = 0; lmax = FLT_MAX;
            if (Flag_auto>0) Flag_auto=0;
          }

        if (!strcmp(token, "vx"))
          { Set_Vars_Coord_Type = DEFS->COORD_VX; strcpy(Set_Vars_Coord_Label,"vx [m/s]"); strcpy(Set_Vars_Coord_Var,"vx"); lmin = -1000; lmax = 1000; }
        if (!strcmp(token, "vy"))
          { Set_Vars_Coord_Type = DEFS->COORD_VY; strcpy(Set_Vars_Coord_Label,"vy [m/s]"); strcpy(Set_Vars_Coord_Var,"vy"); lmin = -1000; lmax = 1000; }
        if (!strcmp(token, "vz"))
          { Set_Vars_Coord_Type = DEFS->COORD_VZ; strcpy(Set_Vars_Coord_Label,"vz [m/s]"); strcpy(Set_Vars_Coord_Var,"vz"); lmin = -10000; lmax = 10000; }
        if (!strcmp(token, "kx"))
          { Set_Vars_Coord_Type = DEFS->COORD_KX; strcpy(Set_Vars_Coord_Label,"kx [Angs-1]"); strcpy(Set_Vars_Coord_Var,"kx"); lmin = -1; lmax = 1; }
        if (!strcmp(token, "ky"))
          { Set_Vars_Coord_Type = DEFS->COORD_KY; strcpy(Set_Vars_Coord_Label,"ky [Angs-1]"); strcpy(Set_Vars_Coord_Var,"ky"); lmin = -1; lmax = 1; }
        if (!strcmp(token, "kz"))
          { Set_Vars_Coord_Type = DEFS->COORD_KZ; strcpy(Set_Vars_Coord_Label,"kz [Angs-1]"); strcpy(Set_Vars_Coord_Var,"kz"); lmin = -10; lmax = 10; }
        if (!strcmp(token, "Ex"))
          { Set_Vars_Coord_Type = DEFS->COORD_EX; strcpy(Set_Vars_Coord_Label,"Ex [1]"); strcpy(Set_Vars_Coord_Var,"Ex"); lmin = -1; lmax = 1; }
        if (!strcmp(token, "Ey"))
          { Set_Vars_Coord_Type = DEFS->COORD_EY; strcpy(Set_Vars_Coord_Label,"Ey [1]"); strcpy(Set_Vars_Coord_Var,"Ey"); lmin = -1; lmax = 1; }
        if (!strcmp(token, "Ez"))
          { Set_Vars_Coord_Type = DEFS->COORD_EZ; strcpy(Set_Vars_Coord_Label,"Ez [1]"); strcpy(Set_Vars_Coord_Var,"Ez"); lmin = -1; lmax = 1; }

        if (!strcmp(token, "energy") || !strcmp(token, "omega") || !strcmp(token, "e"))
          { Set_Vars_Coord_Type = DEFS->COORD_ENERGY; strcpy(Set_Vars_Coord_Label,"Energy [keV]"); strcpy(Set_Vars_Coord_Var,"E"); lmin = 0; lmax = 100; }
        if (!strcmp(token, "lambda") || !strcmp(token, "wavelength") || !strcmp(token, "l"))
          { Set_Vars_Coord_Type = DEFS->COORD_LAMBDA; strcpy(Set_Vars_Coord_Label,"Wavelength [Angs]"); strcpy(Set_Vars_Coord_Var,"L"); lmin = 0; lmax = 100; }
        if (!strcmp(token, "radius") || !strcmp(token, "r"))
          { Set_Vars_Coord_Type = DEFS->COORD_RADIUS; strcpy(Set_Vars_Coord_Label,"Radius [m]"); strcpy(Set_Vars_Coord_Var,"xy"); lmin = 0; lmax = xmax; }
        if (!strcmp(token, "xy"))
          { Set_Vars_Coord_Type = DEFS->COORD_XY; strcpy(Set_Vars_Coord_Label,"Radius (xy) [m]"); strcpy(Set_Vars_Coord_Var,"xy"); lmin = 0; lmax = xmax; }
        if (!strcmp(token, "yz"))
          { Set_Vars_Coord_Type = DEFS->COORD_YZ; strcpy(Set_Vars_Coord_Label,"Radius (yz) [m]"); strcpy(Set_Vars_Coord_Var,"yz"); lmin = 0; lmax = xmax; }
        if (!strcmp(token, "xz"))
          { Set_Vars_Coord_Type = DEFS->COORD_XZ; strcpy(Set_Vars_Coord_Label,"Radius (xz) [m]"); strcpy(Set_Vars_Coord_Var,"xz"); lmin = 0; lmax = xmax; }
        if (!strcmp(token, "vxy"))
          { Set_Vars_Coord_Type = DEFS->COORD_VXY; strcpy(Set_Vars_Coord_Label,"Radial Velocity (xy) [m]"); strcpy(Set_Vars_Coord_Var,"Vxy"); lmin = 0; lmax = 2000; }
        if (!strcmp(token, "kxy"))
          { Set_Vars_Coord_Type = DEFS->COORD_KXY; strcpy(Set_Vars_Coord_Label,"Radial Wavevector (xy) [Angs-1]"); strcpy(Set_Vars_Coord_Var,"Kxy"); lmin = 0; lmax = 2; }
        if (!strcmp(token, "vyz"))
          { Set_Vars_Coord_Type = DEFS->COORD_VYZ; strcpy(Set_Vars_Coord_Label,"Radial Velocity (yz) [m]"); strcpy(Set_Vars_Coord_Var,"Vyz"); lmin = 0; lmax = 2000; }
        if (!strcmp(token, "kyz"))
          { Set_Vars_Coord_Type = DEFS->COORD_KYZ; strcpy(Set_Vars_Coord_Label,"Radial Wavevector (yz) [Angs-1]"); strcpy(Set_Vars_Coord_Var,"Kyz"); lmin = 0; lmax = 2; }
        if (!strcmp(token, "vxz"))
          { Set_Vars_Coord_Type = DEFS->COORD_VXZ; strcpy(Set_Vars_Coord_Label,"Radial Velocity (xz) [m]"); strcpy(Set_Vars_Coord_Var,"Vxz"); lmin = 0; lmax = 2000; }
        if (!strcmp(token, "kxz"))
          { Set_Vars_Coord_Type = DEFS->COORD_KXZ; strcpy(Set_Vars_Coord_Label,"Radial Wavevector (xz) [Angs-1]"); strcpy(Set_Vars_Coord_Var,"Kxz"); lmin = 0; lmax = 2; }
        if (!strcmp(token, "angle") || !strcmp(token, "a"))
          { Set_Vars_Coord_Type = DEFS->COORD_ANGLE; strcpy(Set_Vars_Coord_Label,"Angle [deg]"); strcpy(Set_Vars_Coord_Var,"A"); lmin = -50; lmax = 50; }
        if (!strcmp(token, "hdiv")|| !strcmp(token, "divergence") || !strcmp(token, "xdiv") || !strcmp(token, "hd") || !strcmp(token, "dx"))
          { Set_Vars_Coord_Type = DEFS->COORD_HDIV; strcpy(Set_Vars_Coord_Label,"Hor. Divergence [deg]"); strcpy(Set_Vars_Coord_Var,"hd"); lmin = -5; lmax = 5; }
        if (!strcmp(token, "vdiv") || !strcmp(token, "ydiv") || !strcmp(token, "vd") || !strcmp(token, "dy"))
          { Set_Vars_Coord_Type = DEFS->COORD_VDIV; strcpy(Set_Vars_Coord_Label,"Vert. Divergence [deg]"); strcpy(Set_Vars_Coord_Var,"vd"); lmin = -5; lmax = 5; }
        if (!strcmp(token, "theta") || !strcmp(token, "longitude") || !strcmp(token, "th"))
          { Set_Vars_Coord_Type = DEFS->COORD_THETA; strcpy(Set_Vars_Coord_Label,"Longitude [deg]"); strcpy(Set_Vars_Coord_Var,"th"); lmin = -180; lmax = 180; }
        if (!strcmp(token, "phi") || !strcmp(token, "latitude") || !strcmp(token, "ph"))
          { Set_Vars_Coord_Type = DEFS->COORD_PHI; strcpy(Set_Vars_Coord_Label,"Latitude [deg]"); strcpy(Set_Vars_Coord_Var,"ph"); lmin = -90; lmax = 90; }
        if (!strcmp(token, "ncounts") || !strcmp(token, "n") || !strcmp(token, "photon"))
          { Set_Vars_Coord_Type = DEFS->COORD_NCOUNT; strcpy(Set_Vars_Coord_Label,"Photon ID [1]"); strcpy(Set_Vars_Coord_Var,"n"); lmin = 0; lmax = mcget_ncount(); if (Flag_auto>0) Flag_auto=0; }
        if (!strcmp(token, "id") || !strcmp(token, "pixel"))
          { Set_Vars_Coord_Type = DEFS->COORD_PIXELID; 
            strcpy(Set_Vars_Coord_Label,"Pixel ID [1]"); 
            strcpy(Set_Vars_Coord_Var,"id"); lmin = 0; lmax = FLT_MAX; 
            if (Flag_auto>0) Flag_auto=0;
            Vars->Flag_List = 1; }
        if (!strcmp(token, "user") || !strcmp(token, "user1") || !strcmp(token, "u1"))
          { Set_Vars_Coord_Type = DEFS->COORD_USER1; strncpy(Set_Vars_Coord_Label,Vars->UserName1,30); strcpy(Set_Vars_Coord_Var,"U1"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "user2") || !strcmp(token, "u2"))
          { Set_Vars_Coord_Type = DEFS->COORD_USER2; strncpy(Set_Vars_Coord_Label,Vars->UserName2,30); strcpy(Set_Vars_Coord_Var,"U2"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "user3") || !strcmp(token, "u3"))
          { Set_Vars_Coord_Type = DEFS->COORD_USER3; strncpy(Set_Vars_Coord_Label,Vars->UserName3,30); strcpy(Set_Vars_Coord_Var,"U3"); lmin = -1e10; lmax = 1e10; }

        /* now stores variable keywords detected, if any */
        if (Set_Vars_Coord_Type != DEFS->COORD_NONE)
        {
          int Coord_Number = Vars->Coord_Number;
          if (Vars->Flag_log) { Set_Vars_Coord_Type |= DEFS->COORD_LOG; Vars->Flag_log = 0; }
          if (Flag_abs) { Set_Vars_Coord_Type |= DEFS->COORD_ABS; Flag_abs = 0; }
          if (Flag_auto != 0) { Set_Vars_Coord_Type |= DEFS->COORD_AUTO; 
            if (Flag_auto > 0) Flag_auto = 0; }
          if (Set_Coord_Mode == DEFS->COORD_SIGNAL)
          {
            Coord_Number = 0;
            Vars->Flag_signal = Set_Vars_Coord_Type;
          }
          else
          {
            if (Coord_Number < MONnD_COORD_NMAX)
            { Coord_Number++;
              Vars->Coord_Number = Coord_Number; 
              if (Set_Vars_Coord_Type != DEFS->COORD_PIXELID)
                Vars->Coord_NumberNoPixel++;
            }
            else if (Vars->Flag_Verbose) printf("Monitor_nD: %s reached max number of variables (%i).\n", Vars->compcurname, MONnD_COORD_NMAX);
          }
          Vars->Coord_Type[Coord_Number] = Set_Vars_Coord_Type;
          strncpy(Vars->Coord_Label[Coord_Number], Set_Vars_Coord_Label,30);
          strncpy(Vars->Coord_Var[Coord_Number], Set_Vars_Coord_Var,30);
          if (lmin > lmax) { XY = lmin; lmin=lmax; lmax = XY; }
          Vars->Coord_Min[Coord_Number] = lmin;
          Vars->Coord_Max[Coord_Number] = lmax;
          if (Set_Vars_Coord_Type == DEFS->COORD_NCOUNT || Set_Vars_Coord_Type == DEFS->COORD_PIXELID || Set_Vars_Coord_Type == DEFS->COORD_SIGNAL)
            Vars->Coord_Bin[Coord_Number] = 1;
          else
            Vars->Coord_Bin[Coord_Number] = 20;
          Set_Coord_Mode = DEFS->COORD_VAR;
          Flag_All = 0;
          Flag_No  = 0;
        } else {
          /* no variable name could be read from options */
          if (!iskeyword) {
            if (strcmp(token, "cm2") && strcmp(token, "incoming")
             && strcmp(token, "outgoing") && strcmp(token, "cm2")
             && strcmp(token, "cm^2") && strcmp(token, "float")
             && strcmp(token, "double") && strcmp(token, "binary")
             && strcmp(token, "steradian") && Vars->Flag_Verbose)
              printf("Monitor_nD: %s: unknown '%s' keyword in 'options'. Ignoring.\n", Vars->compcurname, token);
          }
        }
      carg++;
      } /* end if token */
    } /* end while carg */
    free(option_copy);
    if (carg == 128) printf("Monitor_nD: %s reached max number of tokens (%i). Skipping.\n", Vars->compcurname, 128);

    if ((Vars->Flag_Shape == DEFS->SHAPE_BOX) && (fabs(Vars->mzmax - Vars->mzmin) == 0)) Vars->Flag_Shape = DEFS->SHAPE_SQUARE;

    if (Vars->Flag_log == 1) Vars->Coord_Type[0] |= DEFS->COORD_LOG;
    if (Vars->Coord_Number == 0)
    { Vars->Flag_Auto_Limits=0; Vars->Flag_Multiple=0; Vars->Flag_List=0; }

    /* now setting Monitor Name from variable labels */
    strcpy(Vars->Monitor_Label,"");
    XY = 1; /* will contain total bin number */
    for (i = 0; i <= Vars->Coord_Number; i++)
    {
      if (Flag_auto != 0) Vars->Coord_Type[i] |= DEFS->COORD_AUTO;
      Set_Vars_Coord_Type = (Vars->Coord_Type[i] & (DEFS->COORD_LOG-1));
      if ((Set_Vars_Coord_Type == DEFS->COORD_X)
       || (Set_Vars_Coord_Type == DEFS->COORD_Y)
       || (Set_Vars_Coord_Type == DEFS->COORD_Z))
       strcpy(Short_Label[i],"Position");
      else
      if ((Set_Vars_Coord_Type == DEFS->COORD_THETA)
       || (Set_Vars_Coord_Type == DEFS->COORD_PHI)
       || (Set_Vars_Coord_Type == DEFS->COORD_ANGLE))
       strcpy(Short_Label[i],"Angle");
      else
      if ((Set_Vars_Coord_Type == DEFS->COORD_XY)
       || (Set_Vars_Coord_Type == DEFS->COORD_XZ)
       || (Set_Vars_Coord_Type == DEFS->COORD_YZ)
       || (Set_Vars_Coord_Type == DEFS->COORD_RADIUS))
       strcpy(Short_Label[i],"Radius");
      else
      if ((Set_Vars_Coord_Type == DEFS->COORD_VX)
       || (Set_Vars_Coord_Type == DEFS->COORD_VY)
       || (Set_Vars_Coord_Type == DEFS->COORD_VZ)
       || (Set_Vars_Coord_Type == DEFS->COORD_V)
       || (Set_Vars_Coord_Type == DEFS->COORD_VXY)
       || (Set_Vars_Coord_Type == DEFS->COORD_VYZ)
       || (Set_Vars_Coord_Type == DEFS->COORD_VXZ))
       strcpy(Short_Label[i],"Velocity");
      else
      if ((Set_Vars_Coord_Type == DEFS->COORD_KX)
       || (Set_Vars_Coord_Type == DEFS->COORD_KY)
       || (Set_Vars_Coord_Type == DEFS->COORD_KZ)
       || (Set_Vars_Coord_Type == DEFS->COORD_KXY)
       || (Set_Vars_Coord_Type == DEFS->COORD_KYZ)
       || (Set_Vars_Coord_Type == DEFS->COORD_KXZ)
       || (Set_Vars_Coord_Type == DEFS->COORD_K))
       strcpy(Short_Label[i],"Wavevector");
      else
      if ((Set_Vars_Coord_Type == DEFS->COORD_EX)
       || (Set_Vars_Coord_Type == DEFS->COORD_EY)
       || (Set_Vars_Coord_Type == DEFS->COORD_EZ))
       strcpy(Short_Label[i],"Polarisation");
      else
      if ((Set_Vars_Coord_Type == DEFS->COORD_HDIV)
       || (Set_Vars_Coord_Type == DEFS->COORD_VDIV))
       strcpy(Short_Label[i],"Divergence");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_ENERGY)
       strcpy(Short_Label[i],"Energy");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_LAMBDA)
       strcpy(Short_Label[i],"Wavelength");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_NCOUNT)
       strcpy(Short_Label[i],"Photon_ID");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_PIXELID)
       strcpy(Short_Label[i],"Pixel_ID");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_T)
          strcpy(Short_Label[i],"Time_Of_Flight");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_PHASE)
          strcpy(Short_Label[i],"Phase");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_P)
          strcpy(Short_Label[i],"Intensity");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_USER1)
          strncpy(Short_Label[i],Vars->UserName1,30);
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_USER2)
          strncpy(Short_Label[i],Vars->UserName2,30);
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_USER3)
          strncpy(Short_Label[i],Vars->UserName3,30);
      else
          strcpy(Short_Label[i],"Unknown");

      if (Vars->Coord_Type[i] & DEFS->COORD_ABS)
      { strcat(Vars->Coord_Label[i]," (abs)"); }

      if (Vars->Coord_Type[i] & DEFS->COORD_LOG)
      { strcat(Vars->Coord_Label[i]," (log)"); }

      strcat(Vars->Monitor_Label, " ");
      strcat(Vars->Monitor_Label, Short_Label[i]);
      XY *= Vars->Coord_Bin[i];

    } /* end for Short_Label */

    if ((Vars->Coord_Type[0] & (DEFS->COORD_LOG-1)) == DEFS->COORD_P) {
      strncat(Vars->Coord_Label[0], " [p/s", 30);
      if (Vars->Flag_per_cm2) strncat(Vars->Coord_Label[0], "/cm2", 30);

      if (XY > 1 && Vars->Coord_Number)
        strncat(Vars->Coord_Label[0], "/bin", 30);
      strncat(Vars->Coord_Label[0], "]", 30);
    }

    /* update label 'signal per bin' if more than 1 bin */
    if (XY > 1 && Vars->Coord_Number) {
      if (Vars->Flag_capture)
        printf("Monitor_nD: %s: Using capture flux weightening on %ld bins.\n"
               "WARNING     Use binned data with caution, and prefer monitor integral value (I,Ierr).\n", Vars->compcurname, (long)XY);
    }

    strcat(Vars->Monitor_Label, " Monitor");
    if (Vars->Flag_Shape == DEFS->SHAPE_SQUARE) strcat(Vars->Monitor_Label, " (Square)");
    if (Vars->Flag_Shape == DEFS->SHAPE_DISK)   strcat(Vars->Monitor_Label, " (Disk)");
    if (Vars->Flag_Shape == DEFS->SHAPE_SPHERE) strcat(Vars->Monitor_Label, " (Sphere)");
    if (Vars->Flag_Shape == DEFS->SHAPE_CYLIND) strcat(Vars->Monitor_Label, " (Cylinder)");
    if (Vars->Flag_Shape == DEFS->SHAPE_BANANA) strcat(Vars->Monitor_Label, " (Banana)");
    if (Vars->Flag_Shape == DEFS->SHAPE_BOX)    strcat(Vars->Monitor_Label, " (Box)");
    if (Vars->Flag_Shape == DEFS->SHAPE_PREVIOUS) strcat(Vars->Monitor_Label, " (on PREVIOUS)");
    if (Vars->Flag_Shape == DEFS->SHAPE_OFF) strcat(Vars->Monitor_Label, " (OFF geometry)");
    if ((Vars->Flag_Shape == DEFS->SHAPE_CYLIND) || (Vars->Flag_Shape == DEFS->SHAPE_BANANA) || (Vars->Flag_Shape == DEFS->SHAPE_SPHERE) || (Vars->Flag_Shape == DEFS->SHAPE_BOX))
    {
      if (strstr(Vars->option, "incoming"))
      {
        Vars->Flag_Shape = abs(Vars->Flag_Shape);
        strcat(Vars->Monitor_Label, " [in]");
      }
      else /* if strstr(Vars->option, "outgoing")) */
      {
        Vars->Flag_Shape = -abs(Vars->Flag_Shape);
        strcat(Vars->Monitor_Label, " [out]");
      }
    }
    if (Vars->Flag_UsePreMonitor == 1)
    {
        strcat(Vars->Monitor_Label, " at ");
        strncat(Vars->Monitor_Label, Vars->UserName1,30);
    }
    if (Vars->Flag_log == 1) strcat(Vars->Monitor_Label, " [log] ");

    /* now allocate memory to store variables in TRACE */

    /* Vars->Coord_Number  0   : intensity or signal
     * Vars->Coord_Number  1:n : detector variables */

    if ((Vars->Coord_NumberNoPixel != 2) && !Vars->Flag_Multiple && !Vars->Flag_List)
    { Vars->Flag_Multiple = 1; /* default is n1D */
      if (Vars->Coord_Number != Vars->Coord_NumberNoPixel) Vars->Flag_List = 1; }

    /* list and auto limits case : Vars->Flag_List or Vars->Flag_Auto_Limits
     * -> Buffer to flush and suppress after Vars->Flag_Auto_Limits
     */
    if ((Vars->Flag_Auto_Limits || Vars->Flag_List) && Vars->Coord_Number)
    { /* Dim : (Vars->Coord_Number+1)*Vars->Buffer_Block matrix (for p, dp) */
      Vars->Mon2D_Buffer = (double *)malloc((Vars->Coord_Number+1)*Vars->Buffer_Block*sizeof(double));
      if (Vars->Mon2D_Buffer == NULL)
      { printf("Monitor_nD: %s cannot allocate Vars->Mon2D_Buffer (%li). No list and auto limits.\n", Vars->compcurname, Vars->Buffer_Block*(Vars->Coord_Number+1)*sizeof(double)); Vars->Flag_List = 0; Vars->Flag_Auto_Limits = 0; }
      else
      {
        for (i=0; i < (Vars->Coord_Number+1)*Vars->Buffer_Block; Vars->Mon2D_Buffer[i++] = (double)0);
      }
      Vars->Buffer_Size = Vars->Buffer_Block;
    }

    /* 1D and n1D case : Vars->Flag_Multiple */
    if (Vars->Flag_Multiple && Vars->Coord_NumberNoPixel)
    { /* Dim : Vars->Coord_Number*Vars->Coord_Bin[i] vectors */
      Vars->Mon2D_N  = (double **)malloc((Vars->Coord_Number)*sizeof(double *));
      Vars->Mon2D_p  = (double **)malloc((Vars->Coord_Number)*sizeof(double *));
      Vars->Mon2D_p2 = (double **)malloc((Vars->Coord_Number)*sizeof(double *));
      if ((Vars->Mon2D_N == NULL) || (Vars->Mon2D_p == NULL) || (Vars->Mon2D_p2 == NULL))
      { fprintf(stderr,"Monitor_nD: %s n1D cannot allocate Vars->Mon2D_N/p/p2 (%li). Fatal.\n", Vars->compcurname, (Vars->Coord_Number)*sizeof(double *)); exit(-1); }
      for (i= 1; i <= Vars->Coord_Number; i++)
      {
        Vars->Mon2D_N[i-1]  = (double *)malloc(Vars->Coord_Bin[i]*sizeof(double));
        Vars->Mon2D_p[i-1]  = (double *)malloc(Vars->Coord_Bin[i]*sizeof(double));
        Vars->Mon2D_p2[i-1] = (double *)malloc(Vars->Coord_Bin[i]*sizeof(double));
        if ((Vars->Mon2D_N == NULL) || (Vars->Mon2D_p == NULL) || (Vars->Mon2D_p2 == NULL))
        { fprintf(stderr,"Monitor_nD: %s n1D cannot allocate %s Vars->Mon2D_N/p/p2[%li] (%li). Fatal.\n", Vars->compcurname, Vars->Coord_Var[i], i, (Vars->Coord_Bin[i])*sizeof(double *)); exit(-1); }
        else
        {
          for (j=0; j < Vars->Coord_Bin[i]; j++ )
          { Vars->Mon2D_N[i-1][j] = (double)0; Vars->Mon2D_p[i-1][j] = (double)0; Vars->Mon2D_p2[i-1][j] = (double)0; }
        }
      }
    }
    else /* 2D case : Vars->Coord_Number==2 and !Vars->Flag_Multiple and !Vars->Flag_List */
    if ((Vars->Coord_NumberNoPixel == 2) && !Vars->Flag_Multiple)
    { /* Dim : Vars->Coord_Bin[1]*Vars->Coord_Bin[2] matrix */
      Vars->Mon2D_N  = (double **)malloc((Vars->Coord_Bin[1])*sizeof(double *));
      Vars->Mon2D_p  = (double **)malloc((Vars->Coord_Bin[1])*sizeof(double *));
      Vars->Mon2D_p2 = (double **)malloc((Vars->Coord_Bin[1])*sizeof(double *));
      if ((Vars->Mon2D_N == NULL) || (Vars->Mon2D_p == NULL) || (Vars->Mon2D_p2 == NULL))
      { fprintf(stderr,"Monitor_nD: %s 2D cannot allocate %s Vars->Mon2D_N/p/p2 (%li). Fatal.\n", Vars->compcurname, Vars->Coord_Var[1], (Vars->Coord_Bin[1])*sizeof(double *)); exit(-1); }
      for (i= 0; i < Vars->Coord_Bin[1]; i++)
      {
        Vars->Mon2D_N[i]  = (double *)malloc(Vars->Coord_Bin[2]*sizeof(double));
        Vars->Mon2D_p[i]  = (double *)malloc(Vars->Coord_Bin[2]*sizeof(double));
        Vars->Mon2D_p2[i] = (double *)malloc(Vars->Coord_Bin[2]*sizeof(double));
        if ((Vars->Mon2D_N == NULL) || (Vars->Mon2D_p == NULL) || (Vars->Mon2D_p2 == NULL))
        { fprintf(stderr,"Monitor_nD: %s 2D cannot allocate %s Vars->Mon2D_N/p/p2[%li] (%li). Fatal.\n", Vars->compcurname, Vars->Coord_Var[1], i, (Vars->Coord_Bin[2])*sizeof(double *)); exit(-1); }
        else
        {
          for (j=0; j < Vars->Coord_Bin[2]; j++ )
          { Vars->Mon2D_N[i][j] = (double)0; Vars->Mon2D_p[i][j] = (double)0; Vars->Mon2D_p2[i][j] = (double)0; }
        }
      }
    }
    else {
      Vars->Mon2D_N = Vars->Mon2D_p = Vars->Mon2D_p2 = NULL;
    }
      /* no Mon2D allocated for
       * (Vars->Coord_Number != 2) && !Vars->Flag_Multiple && Vars->Flag_List */
    Vars->psum  = 0;
    Vars->p2sum = 0;
    Vars->Nsum  = 0;

    Vars->area  = fabs(Vars->mxmax - Vars->mxmin)*fabs(Vars->mymax - Vars->mymin)*1E4; /* in cm**2 for square and box shapes */
    Vars->Sphere_Radius = fabs(Vars->mxmax - Vars->mxmin)/2;
    if ((abs(Vars->Flag_Shape) == DEFS->SHAPE_DISK) || (abs(Vars->Flag_Shape) == DEFS->SHAPE_SPHERE))
    {
      Vars->area = PI*Vars->Sphere_Radius*Vars->Sphere_Radius*1E4; /* disk shapes */
    }


    if (Vars->area == 0 && abs(Vars->Flag_Shape) != DEFS->SHAPE_PREVIOUS ) {
      if (abs(Vars->Flag_Shape) != DEFS->SHAPE_OFF) {  
	Vars->Coord_Number = 0;
      }
    }
    if (Vars->Coord_Number == 0 && Vars->Flag_Verbose)
      printf("Monitor_nD: %s is unactivated (0D)\n", Vars->compcurname);
    Vars->Cylinder_Height = fabs(Vars->mymax - Vars->mymin);

    if (Vars->Flag_Verbose)
    {
      printf("Monitor_nD: %s is a %s.\n", Vars->compcurname, Vars->Monitor_Label);
      printf("Monitor_nD: version %s with options=%s\n", MONITOR_ND_LIB_H, Vars->option);
    }
    
    /* compute the product of bin dimensions for PixelID */
    Vars->Coord_BinProd[0]=1;
    for (i = 1; i <= Vars->Coord_Number; i++)
      Vars->Coord_BinProd[i]=Vars->Coord_Bin[i]*Vars->Coord_BinProd[i-1];
  } /* end Monitor_nD_Init */

/* ========================================================================= */
/* Monitor_nD_Trace: this routine is used to monitor one propagating particle */
/* return values: 0=photon was absorbed, -1=photon was outside bounds, 1=photon was measured*/
/* ========================================================================= */
int Monitor_nD_Trace(MonitornD_Defines_type *DEFS, MonitornD_Variables_type *Vars, _class_particle* _particle)
{

  double  XY=0, pp=0;
  long    i =0, j =0;
  double  Coord[MONnD_COORD_NMAX];
  long    Coord_Index[MONnD_COORD_NMAX];
  char    While_End   =0;
  long    While_Buffer=0;
  char    Set_Vars_Coord_Type = DEFS->COORD_NONE;
  
  /* the logic below depends mainly on:
       Flag_List:        1=store 1 buffer, 2=list all, 3=re-use buffer 
       Flag_Auto_Limits: 0 (no auto limits/list), 1 (store events into Buffer), 2 (re-emit store events)
   */

  /* Vars->Flag_Auto_Limits=1: buffer full, we read the Buffer, and determine min and max bounds */
  if ((Vars->Buffer_Counter >= Vars->Buffer_Block) && (Vars->Flag_Auto_Limits == 1) && (Vars->Coord_Number > 0))
  {
    /* auto limits case : get limits in Buffer for each variable */
          /* Dim : (Vars->Coord_Number+1)*Vars->Buffer_Block matrix (for p, dp) */
    if (Vars->Flag_Verbose) printf("Monitor_nD: %s getting %li Auto Limits from List (%li events) in TRACE.\n", Vars->compcurname, Vars->Coord_Number, Vars->Buffer_Counter);
    for (i = 1; i <= Vars->Coord_Number; i++)
    {
      if (Vars->Coord_Type[i] & DEFS->COORD_AUTO)
      {
        Vars->Coord_Min[i] =  FLT_MAX;
        Vars->Coord_Max[i] = -FLT_MAX;
        for (j = 0; j < Vars->Buffer_Counter; j++)
        {
          XY = Vars->Mon2D_Buffer[i+j*(Vars->Coord_Number+1)];  /* scanning variables in Buffer */
          if (XY < Vars->Coord_Min[i]) Vars->Coord_Min[i] = XY;
          if (XY > Vars->Coord_Max[i]) Vars->Coord_Max[i] = XY;
        }
        if  (Vars->Flag_Verbose)  
          printf("  %s: min=%g max=%g\n", Vars->Coord_Var[i], Vars->Coord_Min[i], Vars->Coord_Max[i]);
      }
    }
    Vars->Flag_Auto_Limits = 2;  /* pass to 2nd auto limits step (read Buffer and generate new events to store in histograms) */
  } /* end if Flag_Auto_Limits == 1 */

#ifndef OPENACC
  /* manage realloc for 'list all' if Buffer size exceeded: flush Buffer to file */
  if ((Vars->Buffer_Counter >= Vars->Buffer_Block) && (Vars->Flag_List >= 2))
  {
    if (Vars->Buffer_Size >= 1000000 || Vars->Flag_List == 3)
    { /* save current (possibly append) and re-use Buffer */

      Monitor_nD_Save(DEFS, Vars);
      Vars->Flag_List = 3;
      Vars->Buffer_Block = Vars->Buffer_Size;
      Vars->Buffer_Counter  = 0;
      Vars->Photon_Counter = 0;
    }
    else
    {
      Vars->Mon2D_Buffer  = (double *)realloc(Vars->Mon2D_Buffer, (Vars->Coord_Number+1)*(Vars->Photon_Counter+Vars->Buffer_Block)*sizeof(double));
      if (Vars->Mon2D_Buffer == NULL)
            { printf("Monitor_nD: %s cannot reallocate Vars->Mon2D_Buffer[%li] (%li). Skipping.\n", Vars->compcurname, i, (Vars->Photon_Counter+Vars->Buffer_Block)*sizeof(double)); Vars->Flag_List = 1; }
      else { Vars->Buffer_Counter = 0; Vars->Buffer_Size = Vars->Photon_Counter+Vars->Buffer_Block; }
    }
  } /* end if Buffer realloc */
#endif

  char    outsidebounds=0;
  while (!While_End)
  { /* we generate Coord[] and Coord_index[] from Buffer (auto limits) or passing photon */
    if ((Vars->Flag_Auto_Limits == 2) && (Vars->Coord_Number > 0))
    { /* Vars->Flag_Auto_Limits == 2: read back from Buffer (Buffer is filled or auto limits have been computed) */
      if (While_Buffer < Vars->Buffer_Block)
      {
        /* first while loop (While_Buffer) */
        /* auto limits case : scan Buffer within limits and store in Mon2D */
        Coord[0] = pp = Vars->Mon2D_Buffer[While_Buffer*(Vars->Coord_Number+1)];

        for (i = 1; i <= Vars->Coord_Number; i++)
        {
          /* scanning variables in Buffer */
          if (Vars->Coord_Bin[i] <= 1) continue;
          XY = (Vars->Coord_Max[i]-Vars->Coord_Min[i]);

          Coord[i] = Vars->Mon2D_Buffer[i+While_Buffer*(Vars->Coord_Number+1)];
          if (XY > 0) Coord_Index[i] = floor((Coord[i]-Vars->Coord_Min[i])*Vars->Coord_Bin[i]/XY);
          else        Coord_Index[i] = 0;
          if (Vars->Flag_With_Borders)
          {
            if (Coord_Index[i] < 0)                   Coord_Index[i] = 0;
            if (Coord_Index[i] >= Vars->Coord_Bin[i]) Coord_Index[i] = Vars->Coord_Bin[i] - 1;
          }
        } /* end for */
        
        /* update the PixelID, we compute it from the previous variables index */
        if (Vars->Coord_NumberNoPixel < Vars->Coord_Number) /* there is a Pixel variable */
        for (i = 1; i <= Vars->Coord_Number; i++) {
          char Set_Vars_Coord_Type = (Vars->Coord_Type[i] & (DEFS->COORD_LOG-1));
          if (Set_Vars_Coord_Type == DEFS->COORD_PIXELID) {
            char flag_outside=0;
            Coord_Index[i] = Coord[i] = 0;
            for (j= 1; j < i; j++) {
              /* not for 1D variables with Bin=1 such as PixelID, NCOUNT, Intensity */
              if (Vars->Coord_Bin[j] == 1) continue; 
              if (0 > Coord_Index[j] || Coord_Index[j] >= Vars->Coord_Bin[j]) {
                flag_outside=1;
                Coord[i] = 0;
                break;
              }
              Coord[i] += Coord_Index[j]*Vars->Coord_BinProd[j-1];
            }
            if (!flag_outside) {
              Vars->Mon2D_Buffer[i+While_Buffer*(Vars->Coord_Number+1)] = Coord[i];
            }
          } /* end if PixelID */
        }
        While_Buffer++;
      } /* end if in Buffer */
      else /* (While_Buffer >= Vars->Buffer_Block) && (Vars->Flag_Auto_Limits == 2) */
      {
        Vars->Flag_Auto_Limits = 0;
        if (!Vars->Flag_List) /* free Buffer not needed anymore (no list to output) */
        { /* Dim : (Vars->Coord_Number+1)*Vars->Buffer_Block matrix (for p, p2) */
          free(Vars->Mon2D_Buffer); Vars->Mon2D_Buffer = NULL;
        }
        if (Vars->Flag_Verbose) printf("Monitor_nD: %s flushed %li Auto Limits from List (%li) in TRACE.\n", Vars->compcurname, Vars->Coord_Number, Vars->Buffer_Counter);
      }
    } /* if Vars->Flag_Auto_Limits == 2 */
    
    if (Vars->Flag_Auto_Limits != 2 || !Vars->Coord_Number) /* Vars->Flag_Auto_Limits == 0 (no auto limits/list) or 1 (store events into Buffer) */
    {
      /* automatically compute area and steradian solid angle when in AUTO mode */
      /* compute the steradian solid angle incoming on the monitor */
      double k;
      double tmp;
      k=sqrt(_particle->kx*_particle->kx + _particle->ky*_particle->ky + _particle->kz*_particle->kz);
      tmp=_particle->x;
      if (Vars->min_x > _particle->x){
        #pragma acc atomic write
        Vars->min_x = tmp;
      }
      if (Vars->max_x < _particle->x){
        #pragma acc atomic write
        Vars->max_x = tmp;
      }
      tmp=_particle->y;
      if (Vars->min_y > _particle->y){
        #pragma acc atomic write
        Vars->min_y = tmp;
      }
      if (Vars->max_y < _particle->y){
	tmp=_particle->y;
        #pragma acc atomic write
	Vars->max_y = tmp;
      }

      #pragma acc atomic
      Vars->mean_p = Vars->mean_p + _particle->p;
      if (k) {
        tmp=_particle->p*fabs(_particle->kx/k);
        #pragma acc atomic
        Vars->mean_dx = Vars->mean_dx + tmp; //_particle->p*fabs(_particle->kx/k);
        tmp=_particle->p*fabs(_particle->ky/k);
        #pragma acc atomic
        Vars->mean_dy = Vars->mean_dy + tmp; //_particle->p*fabs(_particle->ky/k);
      }

      for (i = 0; i <= Vars->Coord_Number; i++)
      { /* handle current photon : last while */
        XY = 0;
        Set_Vars_Coord_Type = (Vars->Coord_Type[i] & (DEFS->COORD_LOG-1));
        /* get values for variables to monitor */
        if (Set_Vars_Coord_Type == DEFS->COORD_X) XY = _particle->x;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_Y) XY = _particle->y;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_Z) XY = _particle->z;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_VX) XY = _particle->kx/k*M_C;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_VY) XY = _particle->ky/k*M_C;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_VZ) XY = _particle->kz/k*M_C;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_KX) XY = _particle->kx;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_KY) XY = _particle->ky;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_KZ) XY = _particle->kz;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_PHASE) XY = _particle->phi;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_T) XY = _particle->t;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_P) XY = _particle->p;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_HDIV) XY = RAD2DEG*atan2(_particle->kx,_particle->kz);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_VDIV) XY = RAD2DEG*atan2(_particle->ky,_particle->kz);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_V) XY = M_C;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_RADIUS)
          XY = sqrt(_particle->x*_particle->x+_particle->y*_particle->y+_particle->z*_particle->z);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_XY)
          XY = sqrt(_particle->x*_particle->x+_particle->y*_particle->y)*(_particle->x > 0 ? 1 : -1);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_YZ) XY = sqrt(_particle->y*_particle->y+_particle->z*_particle->z);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_XZ)
          XY = sqrt(_particle->x*_particle->x+_particle->z*_particle->z);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_VXY) XY = sqrt(_particle->kx*_particle->kx+_particle->ky*_particle->ky)/k*M_C;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_VXZ) XY = sqrt(_particle->kx*_particle->kx+_particle->kz*_particle->kz)/k*M_C;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_VYZ) XY = sqrt(_particle->ky*_particle->ky+_particle->kz*_particle->kz)/k*M_C;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_K) XY = k;//sqrt(_particle->kx*_particle->kx+_particle->ky*_particle->ky+_particle->kz*_particle->kz);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_KXY) XY = sqrt(_particle->kx*_particle->kx+_particle->ky*_particle->ky);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_KXZ) XY = sqrt(_particle->kx*_particle->kx+_particle->kz*_particle->kz);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_KYZ) XY = sqrt(_particle->ky*_particle->ky+_particle->kz*_particle->kz);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_ENERGY) XY = k*K2E;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_LAMBDA) { if (k!=0) XY = 2*M_PI/k; }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_NCOUNT) XY = Vars->Photon_Counter;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_ANGLE)
        {  XY = sqrt(_particle->kx*_particle->kx+_particle->ky*_particle->ky);
           if (_particle->kz != 0)
                XY = RAD2DEG*atan2(XY,_particle->kz)*(_particle->x > 0 ? 1 : -1);
           else XY = 0;
        }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_THETA)  { if (_particle->z != 0) XY = RAD2DEG*atan2(_particle->x,_particle->z); }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_PHI) { double rr=sqrt(_particle->x*_particle->x+ _particle->y*_particle->y + _particle->z*_particle->z); if (rr != 0) XY = RAD2DEG*asin(_particle->y/rr); }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USER1) {int fail; XY = particle_getvar(_particle,Vars->UserVariable1,&fail); if(fail) XY=0; }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USER2) {int fail; XY = particle_getvar(_particle,Vars->UserVariable2,&fail); if(fail) XY=0; }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USER3) {int fail; XY = particle_getvar(_particle,Vars->UserVariable3,&fail); if(fail) XY=0; }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_PIXELID && !Vars->Flag_Auto_Limits) {
          /* compute the PixelID from previous coordinates 
             the PixelID is the product of Coord_Index[i] in the detector geometry 
             pixelID = sum( Coord_Index[j]*prod(Vars->Coord_Bin[1:(j-1)]) )
             
             this does not apply when we store events in the buffer as Coord_Index
             is not set. Then the pixelID will be re-computed during SAVE.
          */
          char flag_outside=0;
          for (j= 1; j < i; j++) {
            /* not for 1D variables with Bin=1 such as PixelID, NCOUNT, Intensity */
            if (Vars->Coord_Bin[j] <= 1) continue; 
            if (0 > Coord_Index[j] || Coord_Index[j] >= Vars->Coord_Bin[j]) { 
              flag_outside=1; XY=0; break;
            }
            XY += Coord_Index[j]*Vars->Coord_BinProd[j-1];
          }
	  //if (Vars->Flag_mantid && Vars->Flag_OFF && Vars->OFF_polyidx >=0) XY=Vars->OFF_polyidx;
          if (!flag_outside) XY += Vars->Coord_Min[i];
        }
        
        /* handle 'abs' and 'log' keywords */
        if (Vars->Coord_Type[i] & DEFS->COORD_ABS) XY=fabs(XY);

        if (Vars->Coord_Type[i] & DEFS->COORD_LOG) /* compute log of variable if requested */
        {  if (XY > 0) XY = log(XY)/log(10);
           else        XY = -100; }

        Coord[i] = XY; Coord_Index[i] = 0;
        if (i == 0) { pp = XY; Coord_Index[i] = 0; }
        else {
        /* check bounds for variables which have no automatic limits */
          if ((!Vars->Flag_Auto_Limits || !(Vars->Coord_Type[i] & DEFS->COORD_AUTO)) && Vars->Coord_Bin[i]>1)
          { /* compute index in histograms for each variable to monitor */
            XY = (Vars->Coord_Max[i]-Vars->Coord_Min[i]);
            if (XY > 0) Coord_Index[i] = floor((Coord[i]-Vars->Coord_Min[i])*Vars->Coord_Bin[i]/XY);
            if (Vars->Flag_With_Borders)
            {
              if (Coord_Index[i] >= Vars->Coord_Bin[i]) Coord_Index[i] = Vars->Coord_Bin[i] - 1;
              if (Coord_Index[i] < 0) Coord_Index[i] = 0;
            }
            //if (0 > Coord_Index[i] || Coord_Index[i] >= Vars->Coord_Bin[i])
            //  outsidebounds=1;
          } /* else will get Index later from Buffer when Flag_Auto_Limits == 2 */
        }
        
      } /* end for i */
      While_End = 1;
    }/* end else if Vars->Flag_Auto_Limits == 2 */
    
    /* ====================================================================== */
    /* store n1d/2d photon from Buffer (Auto_Limits == 2) or current photon in while */
    if (Vars->Flag_Auto_Limits != 1) /* not when storing auto limits Buffer */
    {
      /* apply per cm2 */
      if (Vars->Flag_per_cm2 && Vars->area != 0)
        pp /= Vars->area;

      /* 2D case : Vars->Coord_Number==2 and !Vars->Flag_Multiple and !Vars->Flag_List */
      if ( Vars->Coord_NumberNoPixel == 2 && !Vars->Flag_Multiple)
      { /* Dim : Vars->Coord_Bin[1]*Vars->Coord_Bin[2] matrix */
        
        i = Coord_Index[1];
        j = Coord_Index[2];
        if (i >= 0 && i < Vars->Coord_Bin[1] && j >= 0 && j < Vars->Coord_Bin[2])
        {
          if (Vars->Mon2D_N) {
	    double p2 = pp*pp;
            #pragma acc atomic
	    Vars->Mon2D_N[i][j] = Vars->Mon2D_N[i][j]+1;
            #pragma acc atomic
	    Vars->Mon2D_p[i][j] = Vars->Mon2D_p[i][j]+pp;
            #pragma acc atomic
	    Vars->Mon2D_p2[i][j] = Vars->Mon2D_p2[i][j] + p2;
	  }
        } else {
          outsidebounds=1; 
        }
      } else {
        /* 1D and n1D case : Vars->Flag_Multiple */
        /* Dim : Vars->Coord_Number*Vars->Coord_Bin[i] vectors (intensity is not included) */
          
        for (i= 1; i <= Vars->Coord_Number; i++) {
          j = Coord_Index[i];
          if (j >= 0 && j < Vars->Coord_Bin[i]) {
            if  (Vars->Flag_Multiple && Vars->Mon2D_N) {
	      if (Vars->Mon2D_N) {
		double p2 = pp*pp;
                #pragma acc atomic
		Vars->Mon2D_N[i-1][j] = Vars->Mon2D_N[i-1][j]+1;
                #pragma acc atomic
		Vars->Mon2D_p[i-1][j] = Vars->Mon2D_p[i-1][j]+pp;
		#pragma acc atomic
		Vars->Mon2D_p2[i-1][j] = Vars->Mon2D_p2[i-1][j] + p2;
	      }
	    }
          } else { 
            outsidebounds=1;
            break;
          }
        }
      }
    } /* end (Vars->Flag_Auto_Limits != 1) */
    
    if (Vars->Flag_Auto_Limits != 2 && !outsidebounds) /* not when reading auto limits Buffer */
    { /* now store Coord into Buffer (no index needed) if necessary (list or auto limits) */
      if ((Vars->Buffer_Counter < Vars->Buffer_Block) && ((Vars->Flag_List) || (Vars->Flag_Auto_Limits == 1)))
      {
        for (i = 0; i <= Vars->Coord_Number; i++)
        {
	  // This is is where the list is appended. How to make this "atomic"?
          #pragma acc atomic write 
          Vars->Mon2D_Buffer[i + Vars->Photon_Counter*(Vars->Coord_Number+1)] = Coord[i];
        }
	#pragma acc atomic 
        Vars->Buffer_Counter = Vars->Buffer_Counter + 1;
        if (Vars->Flag_Verbose && (Vars->Buffer_Counter >= Vars->Buffer_Block) && (Vars->Flag_List == 1)) 
          printf("Monitor_nD: %s %li photons stored in List.\n", Vars->compcurname, Vars->Buffer_Counter);
      }
      #pragma acc atomic
      Vars->Photon_Counter = Vars->Photon_Counter + 1;
    } /* end (Vars->Flag_Auto_Limits != 2) */
    
  } /* end while */
  #pragma acc atomic
  Vars->Nsum = Vars->Nsum + 1;
  #pragma acc atomic
  Vars->psum  = Vars->psum + pp;
  #pragma acc atomic
  Vars->p2sum = Vars->p2sum + pp*pp;

  /*determine return value: 1:photon was in bounds and measured, -1: outside bounds, 0: outside bounds, should be absorbed.*/
  if(outsidebounds){
      if(Vars->Flag_Absorb){
          return 0;
      }else{
          return -1;
      }
  }
  return 1;
} /* end Monitor_nD_Trace */

/* ========================================================================= */
/* Monitor_nD_Save: this routine is used to save data files                  */
/* ========================================================================= */
MCDETECTOR Monitor_nD_Save(MonitornD_Defines_type *DEFS, MonitornD_Variables_type *Vars)
  {
    char   *fname;
    long    i,j;
    double *p0m = NULL;
    double *p1m = NULL;
    double *p2m = NULL;
    char    Coord_X_Label[CHAR_BUF_LENGTH];
    double  min1d, max1d;
    double  min2d, max2d;
    char    While_End = 0;
    long    While_Buffer = 0;
    double  XY=0, pp=0;
    double  Coord[MONnD_COORD_NMAX];
    long    Coord_Index[MONnD_COORD_NMAX];
    char    label[CHAR_BUF_LENGTH];
    double  ratio;

    MCDETECTOR detector;

    ratio = 100.0*mcget_run_num()/mcget_ncount();
    if (Vars->Flag_Verbose && Vars->Flag_per_cm2) {
      printf("Monitor_nD: %s: active flat detector area is %g [cm^2], total area is %g [cm^2]\n",
        Vars->compcurname, (Vars->max_x-Vars->min_x)
                          *(Vars->max_y-Vars->min_y)*1E4, Vars->area);
      printf("Monitor_nD: %s: beam solid angle is %g [st] (%g x %g [deg^2])\n",
        Vars->compcurname,
        2*fabs(2*atan(Vars->mean_dx/Vars->mean_p)
         *sin(2*atan(Vars->mean_dy/Vars->mean_p)/2)),
        atan(Vars->mean_dx/Vars->mean_p)*RAD2DEG,
        atan(Vars->mean_dy/Vars->mean_p)*RAD2DEG);
    }

    /* check Buffer flush when end of simulation reached */
    if ((Vars->Buffer_Counter <= Vars->Buffer_Block) && Vars->Flag_Auto_Limits && Vars->Mon2D_Buffer && Vars->Buffer_Counter)
    {
      /* Get Auto Limits */
      if (Vars->Flag_Verbose) printf("Monitor_nD: %s getting %li Auto Limits from List (%li events).\n", Vars->compcurname, Vars->Coord_Number, Vars->Buffer_Counter);

      for (i = 1; i <= Vars->Coord_Number; i++)
      {
        if ((Vars->Coord_Type[i] & DEFS->COORD_AUTO) && Vars->Coord_Bin[i] > 1)
        {
          Vars->Coord_Min[i] = FLT_MAX;
          Vars->Coord_Max[i] = -FLT_MAX;
          for (j = 0; j < Vars->Buffer_Counter; j++)
          {
            XY = Vars->Mon2D_Buffer[i+j*(Vars->Coord_Number+1)];  /* scanning variables in Buffer */
            if (XY < Vars->Coord_Min[i]) Vars->Coord_Min[i] = XY;
            if (XY > Vars->Coord_Max[i]) Vars->Coord_Max[i] = XY;
          }
          if  (Vars->Flag_Verbose)  
            printf("  %s: min=%g max=%g in %li bins\n", Vars->Coord_Var[i], Vars->Coord_Min[i], Vars->Coord_Max[i], Vars->Coord_Bin[i]);
        }
      }
      Vars->Flag_Auto_Limits = 2;  /* pass to 2nd auto limits step */
      Vars->Buffer_Block = Vars->Buffer_Counter;

      while (!While_End)
      { /* we generate Coord[] and Coord_index[] from Buffer (auto limits) */
        /* simulation ended before Buffer was filled. Limits have to be computed, and stored events must be sent into histograms */
        
        if (While_Buffer < Vars->Buffer_Block)
        {
          /* first while loops (While_Buffer) */
          Coord[0] = Vars->Mon2D_Buffer[While_Buffer*(Vars->Coord_Number+1)];

          /* auto limits case : scan Buffer within limits and store in Mon2D */
          for (i = 1; i <= Vars->Coord_Number; i++)
          {
            /* scanning variables in Buffer */
            if (Vars->Coord_Bin[i] <= 1) Coord_Index[i] = 0;
            else {
              XY = (Vars->Coord_Max[i]-Vars->Coord_Min[i]);
              Coord[i] = Vars->Mon2D_Buffer[i+While_Buffer*(Vars->Coord_Number+1)];
              if (XY > 0) Coord_Index[i] = floor((Coord[i]-Vars->Coord_Min[i])*Vars->Coord_Bin[i]/XY);
              else Coord_Index[i] = 0;
              if (Vars->Flag_With_Borders)
              {
                if (Coord_Index[i] < 0) Coord_Index[i] = 0;
                if (Coord_Index[i] >= Vars->Coord_Bin[i]) Coord_Index[i] = Vars->Coord_Bin[i] - 1;
              }
            }
          } /* end for */

          /* update the PixelID, we compute it from the previous variables index */
          for (i = 1; i <= Vars->Coord_Number; i++) {
            char Set_Vars_Coord_Type = (Vars->Coord_Type[i] & (DEFS->COORD_LOG-1));
            if (Set_Vars_Coord_Type == DEFS->COORD_PIXELID) {
              char outsidebounds=0;
              Coord_Index[i] = Coord[i] = 0;
              for (j= 1; j < i; j++) {
                /* not for 1D variables with Bin=1 such as PixelID, NCOUNT, Intensity */
                if (Vars->Coord_Bin[j] == 1) continue; 
                if (0 > Coord_Index[j] || Coord_Index[j] >= Vars->Coord_Bin[j]) {
                  outsidebounds=1;
                  Coord[i] = 0;
                  break;
                }
                Coord[i] += Coord_Index[j]*Vars->Coord_BinProd[j-1];
              }
              if (!outsidebounds) {
                Vars->Mon2D_Buffer[i+While_Buffer*(Vars->Coord_Number+1)] = Coord[i];
              }
            } /* end if PixelID */
          }
          While_Buffer++;
        } /* end if in Buffer */
        else /* (While_Buffer >= Vars->Buffer_Block) && (Vars->Flag_Auto_Limits == 2) */
        {
          Vars->Flag_Auto_Limits = 0;
          While_End = 1;
          if (Vars->Flag_Verbose) printf("Monitor_nD: %s flushed %li Auto Limits from List (%li).\n", Vars->compcurname, Vars->Coord_Number, Vars->Buffer_Counter);
        }

        /* store n1d/2d section from Buffer */

        pp = Coord[0];
        /* apply per cm2 or per st */
        if (Vars->Flag_per_cm2 && Vars->area      != 0)
          pp /= Vars->area;
        
        /* 2D case : Vars->Coord_Number==2 and !Vars->Flag_Multiple and !Vars->Flag_List */
        if (!Vars->Flag_Multiple && Vars->Coord_NumberNoPixel == 2)
        { /* Dim : Vars->Coord_Bin[1]*Vars->Coord_Bin[2] matrix */
          i = Coord_Index[1];
          j = Coord_Index[2];
          if (i >= 0 && i < Vars->Coord_Bin[1] && j >= 0 && j < Vars->Coord_Bin[2])
          {
            if (Vars->Mon2D_N) {
              Vars->Mon2D_N[i][j]++;
              Vars->Mon2D_p[i][j] += pp;
              Vars->Mon2D_p2[i][j] += pp*pp;
            }
          } else if (Vars->Flag_Absorb) pp=0;
        }
        else
        /* 1D and n1D case : Vars->Flag_Multiple */
        { /* Dim : Vars->Coord_Number*Vars->Coord_Bin[i] vectors (intensity is not included) */
          for (i= 1; i <= Vars->Coord_Number; i++)
          {
            j = Coord_Index[i];
            if (j >= 0 && j < Vars->Coord_Bin[i])
            {
              if (Vars->Flag_Multiple && Vars->Mon2D_N) {
                Vars->Mon2D_N[i-1][j]++;
                Vars->Mon2D_p[i-1][j] += pp;
                Vars->Mon2D_p2[i-1][j] += pp*pp;
              }
            } else if (Vars->Flag_Absorb) {
              pp=0; break;
            }
          }
        } /* end store 2D/1D */
        
      } /* end while */
    } /* end Force Get Limits */

    /* write output files (sent to file as p[i*n + j] vectors) */
    if (Vars->Coord_Number == 0)
    {
      double Nsum;
      double psum, p2sum;
      Nsum = Vars->Nsum;
      psum = Vars->psum;
      p2sum= Vars->p2sum;
      if (Vars->Flag_signal != DEFS->COORD_P && Nsum > 0)
      { psum /=Nsum; p2sum /= Nsum*Nsum; }
      /* DETECTOR_OUT_0D(Vars->Monitor_Label, Vars->Nsum, Vars->psum, Vars->p2sum); */
      detector = mcdetector_out_0D(Vars->Monitor_Label, Nsum, psum, p2sum, Vars->compcurname, Vars->compcurpos);
    }
    else
    if (strlen(Vars->Mon_File) > 0)
    {
      fname = (char*)malloc(strlen(Vars->Mon_File)+10*Vars->Coord_Number);
      if (Vars->Flag_List && Vars->Mon2D_Buffer) /* List: DETECTOR_OUT_2D */
      {
       
        if (Vars->Flag_List >= 2) Vars->Buffer_Size = Vars->Photon_Counter;
        if (Vars->Buffer_Size >= Vars->Photon_Counter)
          Vars->Buffer_Size = Vars->Photon_Counter;
        strcpy(fname,Vars->Mon_File);
        if (strchr(Vars->Mon_File,'.') == NULL) strcat(fname, "_list");

        strcpy(Coord_X_Label,"");
        for (i= 0; i <= Vars->Coord_Number; i++)
        {
          strcat(Coord_X_Label, Vars->Coord_Var[i]);
          strcat(Coord_X_Label, " ");
          if (strchr(Vars->Mon_File,'.') == NULL)
          { strcat(fname, "."); strcat(fname, Vars->Coord_Var[i]); }
        }
        if (Vars->Flag_Verbose) printf("Monitor_nD: %s write monitor file %s List (%lix%li).\n", Vars->compcurname, fname,Vars->Photon_Counter,Vars->Coord_Number);

        /* handle the type of list output */
        strcpy(label, Vars->Monitor_Label);
        
        detector = mcdetector_out_list(
              label, "List of photon events", Coord_X_Label,
              -Vars->Buffer_Size, Vars->Coord_Number+1,
              Vars->Mon2D_Buffer,
              fname, Vars->compcurname, Vars->compcurpos);
      }
      if (Vars->Flag_Multiple) /* n1D: DETECTOR_OUT_1D */
      {
        for (i= 0; i < Vars->Coord_Number; i++)
        {

          strcpy(fname,Vars->Mon_File);
          if (strchr(Vars->Mon_File,'.') == NULL)
          { strcat(fname, "."); strcat(fname, Vars->Coord_Var[i+1]); }
          sprintf(Coord_X_Label, "%s monitor", Vars->Coord_Label[i+1]);
          strcpy(label, Coord_X_Label);
          if (Vars->Coord_Bin[i+1] > 0) { /* 1D monitor */
            if (Vars->Flag_Verbose) printf("Monitor_nD: %s write monitor file %s 1D (%li).\n", Vars->compcurname, fname, Vars->Coord_Bin[i+1]);
            min1d = Vars->Coord_Min[i+1];
            max1d = Vars->Coord_Max[i+1];
            if (min1d == max1d) max1d = min1d+1e-6;
            p1m = (double *)malloc(Vars->Coord_Bin[i+1]*sizeof(double));
            p2m = (double *)malloc(Vars->Coord_Bin[i+1]*sizeof(double));
            if (p2m == NULL) /* use Raw Buffer line output */
            {
              if (Vars->Flag_Verbose) printf("Monitor_nD: %s cannot allocate memory for output. Using raw data.\n", Vars->compcurname);
              if (p1m != NULL) free(p1m);
              detector = mcdetector_out_1D(
              label,
              Vars->Coord_Label[i+1],
              Vars->Coord_Label[0],
              Vars->Coord_Var[i+1],
              min1d, max1d,
              Vars->Coord_Bin[i+1],
              Vars->Mon2D_N[i],Vars->Mon2D_p[i],Vars->Mon2D_p2[i],
              fname, Vars->compcurname, Vars->compcurpos);
            } /* if (p2m == NULL) */
            else
            {
              if (Vars->Flag_log != 0)
              {
                XY = FLT_MAX;
                for (j=0; j < Vars->Coord_Bin[i+1]; j++) /* search min of signal */
                  if ((XY > Vars->Mon2D_p[i][j]) && (Vars->Mon2D_p[i][j] > 0)) XY = Vars->Mon2D_p[i][j];
                if (XY <= 0) XY = -log(FLT_MAX)/log(10); else XY = log(XY)/log(10)-1;
              } /* if */

              for (j=0; j < Vars->Coord_Bin[i+1]; j++)
              {
                p1m[j] = Vars->Mon2D_p[i][j];
                p2m[j] = Vars->Mon2D_p2[i][j];
                if (Vars->Flag_signal != DEFS->COORD_P && Vars->Mon2D_N[i][j] > 0)
                { /* normalize mean signal to the number of events */
                  p1m[j] /= Vars->Mon2D_N[i][j];
                  p2m[j] /= Vars->Mon2D_N[i][j]*Vars->Mon2D_N[i][j];
                }
                if (Vars->Flag_log != 0)
                {
                  if ((p1m[j] > 0) && (p2m[j] > 0))
                  {
                    p2m[j] /= p1m[j]*p1m[j];
                    p1m[j] = log(p1m[j])/log(10);
                  }
                  else
                  {
                    p1m[j] = XY;
                    p2m[j] = 0;
                  }
                }
              } /* for */
              detector = mcdetector_out_1D(
                label,
                Vars->Coord_Label[i+1],
                Vars->Coord_Label[0],
                Vars->Coord_Var[i+1],
                min1d, max1d,
                Vars->Coord_Bin[i+1],
                Vars->Mon2D_N[i],p1m,p2m,
                fname, Vars->compcurname, Vars->compcurpos);

            } /* else */
            /* comment out 'free memory' lines to avoid loosing arrays if
               'detector' structure is used by other instrument parts
            if (p1m != NULL) free(p1m); p1m=NULL;
            if (p2m != NULL) free(p2m); p2m=NULL;
            */
          } else { /* 0d monitor */
            detector = mcdetector_out_0D(label, Vars->Mon2D_p[i][0], Vars->Mon2D_p2[i][0], Vars->Mon2D_N[i][0], Vars->compcurname, Vars->compcurpos);
          }


        } /* for */
      } /* if 1D */
      else
      if (Vars->Coord_NumberNoPixel == 2)  /* 2D: DETECTOR_OUT_2D */
      {
        strcpy(fname,Vars->Mon_File);

        p0m = (double *)malloc(Vars->Coord_Bin[1]*Vars->Coord_Bin[2]*sizeof(double));
        p1m = (double *)malloc(Vars->Coord_Bin[1]*Vars->Coord_Bin[2]*sizeof(double));
        p2m = (double *)malloc(Vars->Coord_Bin[1]*Vars->Coord_Bin[2]*sizeof(double));
        if (p2m == NULL)
        {
          if (Vars->Flag_Verbose) printf("Monitor_nD: %s cannot allocate memory for 2D array (%li). Skipping.\n", Vars->compcurname, 3*Vars->Coord_Bin[1]*Vars->Coord_Bin[2]*sizeof(double));
          /* comment out 'free memory' lines to avoid loosing arrays if
               'detector' structure is used by other instrument parts
          if (p0m != NULL) free(p0m);
          if (p1m != NULL) free(p1m);
          */
        }
        else
        {
          if (Vars->Flag_log != 0)
          {
            XY = FLT_MAX;
            for (i= 0; i < Vars->Coord_Bin[1]; i++)
              for (j= 0; j < Vars->Coord_Bin[2]; j++) /* search min of signal */
                if ((XY > Vars->Mon2D_p[i][j]) && (Vars->Mon2D_p[i][j]>0)) XY = Vars->Mon2D_p[i][j];
            if (XY <= 0) XY = -log(FLT_MAX)/log(10); else XY = log(XY)/log(10)-1;
          }
          for (i= 0; i < Vars->Coord_Bin[1]; i++)
          {
            for (j= 0; j < Vars->Coord_Bin[2]; j++)
            {
              long index;
              index = j + i*Vars->Coord_Bin[2];
              p0m[index] = Vars->Mon2D_N[i][j];
              p1m[index] = Vars->Mon2D_p[i][j];
              p2m[index] = Vars->Mon2D_p2[i][j];
              if (Vars->Flag_signal != DEFS->COORD_P && p0m[index] > 0)
              {
                  p1m[index] /= p0m[index];
                  p2m[index] /= p0m[index]*p0m[index];
              }

              if (Vars->Flag_log != 0)
              {
                if ((p1m[index] > 0) && (p2m[index] > 0))
                {
                  p2m[index] /= (p1m[index]*p1m[index]);
                  p1m[index] = log(p1m[index])/log(10);

                }
                else
                {
                  p1m[index] = XY;
                  p2m[index] = 0;
                }
              }
            }
          }
          if (strchr(Vars->Mon_File,'.') == NULL)
          { strcat(fname, "."); strcat(fname, Vars->Coord_Var[1]);
              strcat(fname, "_"); strcat(fname, Vars->Coord_Var[2]); }
          if (Vars->Flag_Verbose) printf("Monitor_nD: %s write monitor file %s 2D (%lix%li).\n", Vars->compcurname, fname, Vars->Coord_Bin[1], Vars->Coord_Bin[2]);

          min1d = Vars->Coord_Min[1];
          max1d = Vars->Coord_Max[1];
          if (min1d == max1d) max1d = min1d+1e-6;
          min2d = Vars->Coord_Min[2];
          max2d = Vars->Coord_Max[2];
          if (min2d == max2d) max2d = min2d+1e-6;
          strcpy(label, Vars->Monitor_Label);
          if (Vars->Coord_Bin[1]*Vars->Coord_Bin[2] > 1
           && Vars->Flag_signal == DEFS->COORD_P)
            strcat(label, " per bin");

          detector = mcdetector_out_2D(
            label,
            Vars->Coord_Label[1],
            Vars->Coord_Label[2],
            min1d, max1d,
            min2d, max2d,
            Vars->Coord_Bin[1],
            Vars->Coord_Bin[2],
            p0m,p1m,p2m,
            fname, Vars->compcurname, Vars->compcurpos);

          /* comment out 'free memory' lines to avoid loosing arrays if
               'detector' structure is used by other instrument parts
          if (p0m != NULL) free(p0m);
          if (p1m != NULL) free(p1m);
          if (p2m != NULL) free(p2m);
          */
        }
      }
      free(fname);
    }
    return(detector);
  } /* end Monitor_nD_Save */

/* ========================================================================= */
/* Monitor_nD_Finally: this routine is used to free memory                   */
/* ========================================================================= */

void Monitor_nD_Finally(MonitornD_Defines_type *DEFS,
  MonitornD_Variables_type *Vars)
  {
    int i;

    /* Now Free memory Mon2D.. */
    if ((Vars->Flag_Auto_Limits || Vars->Flag_List) && Vars->Coord_Number)
    { /* Dim : (Vars->Coord_Number+1)*Vars->Buffer_Block matrix (for p, dp) */
      if (Vars->Mon2D_Buffer != NULL) free(Vars->Mon2D_Buffer);
    }

    /* 1D and n1D case : Vars->Flag_Multiple */
    if (Vars->Flag_Multiple && Vars->Coord_Number)
    { /* Dim : Vars->Coord_Number*Vars->Coord_Bin[i] vectors */
      for (i= 0; i < Vars->Coord_Number; i++)
      {
        free(Vars->Mon2D_N[i]);
        free(Vars->Mon2D_p[i]);
        free(Vars->Mon2D_p2[i]);
      }
      free(Vars->Mon2D_N);
      free(Vars->Mon2D_p);
      free(Vars->Mon2D_p2);
    }


    /* 2D case : Vars->Coord_Number==2 and !Vars->Flag_Multiple and !Vars->Flag_List */
    if ((Vars->Coord_NumberNoPixel == 2) && !Vars->Flag_Multiple)
    { /* Dim : Vars->Coord_Bin[1]*Vars->Coord_Bin[2] matrix */
      for (i= 0; i < Vars->Coord_Bin[1]; i++)
      {
        free(Vars->Mon2D_N[i]);
        free(Vars->Mon2D_p[i]);
        free(Vars->Mon2D_p2[i]);
      }
      free(Vars->Mon2D_N);
      free(Vars->Mon2D_p);
      free(Vars->Mon2D_p2);
    }
  } /* end Monitor_nD_Finally */

/* ========================================================================= */
/* Monitor_nD_McDisplay: this routine is used to display component           */
/* ========================================================================= */

void Monitor_nD_McDisplay(MonitornD_Defines_type *DEFS,
  MonitornD_Variables_type *Vars)
  {
    double radius, h;
    double xmin;
    double xmax;
    double ymin;
    double ymax;
    double zmin;
    double zmax;
    int    i;
    double hdiv_min=-180, hdiv_max=180, vdiv_min=-90, vdiv_max=90;
    char   restricted = 0;

    radius = Vars->Sphere_Radius;
    h = Vars->Cylinder_Height;
    xmin = Vars->mxmin;
    xmax = Vars->mxmax;
    ymin = Vars->mymin;
    ymax = Vars->mymax;
    zmin = Vars->mzmin;
    zmax = Vars->mzmax;

    /* determine if there are angular limits set at start (no auto) in coord_types
     * cylinder/banana: look for hdiv
     * sphere: look for angle, radius (->atan2(val,radius)), hdiv, vdiv
     * this activates a 'restricted' flag, to draw a region as blades on cylinder/sphere
     */
    for (i= 0; i <= Vars->Coord_Number; i++)
    {
      int Set_Vars_Coord_Type;
      Set_Vars_Coord_Type = (Vars->Coord_Type[i] & (DEFS->COORD_LOG-1));
      if (Set_Vars_Coord_Type == DEFS->COORD_HDIV || Set_Vars_Coord_Type == DEFS->COORD_THETA)
      { hdiv_min = Vars->Coord_Min[i]; hdiv_max = Vars->Coord_Max[i]; restricted = 1; }
      else if (Set_Vars_Coord_Type == DEFS->COORD_VDIV || Set_Vars_Coord_Type == DEFS->COORD_PHI)
      { vdiv_min = Vars->Coord_Min[i]; vdiv_max = Vars->Coord_Max[i];restricted = 1;  }
      else if (Set_Vars_Coord_Type == DEFS->COORD_ANGLE)
      { hdiv_min = vdiv_min = Vars->Coord_Min[i];
        hdiv_max = vdiv_max = Vars->Coord_Max[i];
        restricted = 1; }
      else if (Set_Vars_Coord_Type == DEFS->COORD_RADIUS)
      { double angle;
        angle = RAD2DEG*atan2(Vars->Coord_Max[i], radius);
        hdiv_min = vdiv_min = angle;
        hdiv_max = vdiv_max = angle;
        restricted = 1; }
      else if (Set_Vars_Coord_Type == DEFS->COORD_Y && abs(Vars->Flag_Shape) == DEFS->SHAPE_SPHERE)
      {
        vdiv_min = atan2(ymin,radius)*RAD2DEG;
        vdiv_max = atan2(ymax,radius)*RAD2DEG;
        restricted = 1;
      }
    }
    /* full sphere */
    if ((!restricted && (abs(Vars->Flag_Shape) == DEFS->SHAPE_SPHERE))
    || abs(Vars->Flag_Shape) == DEFS->SHAPE_PREVIOUS)
    {
      mcdis_magnify("");
      mcdis_circle("xy",0,0,0,radius);
      mcdis_circle("xz",0,0,0,radius);
      mcdis_circle("yz",0,0,0,radius);
    }
    /* banana/cylinder/sphere portion */
    else
    if (restricted && ((abs(Vars->Flag_Shape) == DEFS->SHAPE_CYLIND)
                    || (abs(Vars->Flag_Shape) == DEFS->SHAPE_BANANA)
                    || (abs(Vars->Flag_Shape) == DEFS->SHAPE_SPHERE)))
    {
      int NH=24, NV=24;
      int ih, iv;
      double width, height;
      int issphere;
      issphere = (abs(Vars->Flag_Shape) == DEFS->SHAPE_SPHERE);
      width = (hdiv_max-hdiv_min)/NH;
      if (!issphere) NV=1; /* cylinder has vertical axis */
      else height= (vdiv_max-vdiv_min)/NV;
      
      /* check width and height of elements (sphere) to make sure the nb
         of plates remains limited */
      if (width < 10  && NH > 1) { width = 10;  NH=(hdiv_max-hdiv_min)/width; width=(hdiv_max-hdiv_min)/NH; }
      if (height < 10 && NV > 1) { height = 10; NV=(vdiv_max-vdiv_min)/height; height= (vdiv_max-vdiv_min)/NV; }
      
      mcdis_magnify("xyz");
      for(ih = 0; ih < NH; ih++)
        for(iv = 0; iv < NV; iv++)
        {
          double theta0, phi0, theta1, phi1;          /* angles in spherical coordinates */
          double x0,y0,z0,x1,y1,z1,x2,y2,z2,x3,y3,z3; /* vertices at plate edges */
          phi0 = (hdiv_min+ width*ih-90)*DEG2RAD;        /* in xz plane */
          phi1 = (hdiv_min+ width*(ih+1)-90)*DEG2RAD;
          if (issphere)
          {
            theta0= (vdiv_min+height* iv + 90)   *DEG2RAD; /* in vertical plane */
            theta1= (vdiv_min+height*(iv+1) + 90)*DEG2RAD;
            if (y0 < ymin) y0=ymin; 
            if (y0 > ymax) y0=ymax;
            if (y1 < ymin) y1=ymin; 
            if (y1 > ymax) y1=ymax;
            
            y0 = -radius*cos(theta0);            /* z with Z vertical */
            y1 = -radius*cos(theta1);
            if (y0 < ymin) y0=ymin;
            if (y0 > ymax) y0=ymax;
            if (y1 < ymin) y1=ymin;
            if (y1 > ymax) y1=ymax;
          } else {
            y0 = ymin;
            y1 = ymax;
            theta0=theta1=90*DEG2RAD;
          }

          x0 = radius*sin(theta0)*cos(phi0); /* x with Z vertical */
          z0 =-radius*sin(theta0)*sin(phi0); /* y with Z vertical */
          x1 = radius*sin(theta1)*cos(phi0); 
          z1 =-radius*sin(theta1)*sin(phi0);
          x2 = radius*sin(theta1)*cos(phi1); 
          z2 =-radius*sin(theta1)*sin(phi1);
          x3 = radius*sin(theta0)*cos(phi1); 
          z3 =-radius*sin(theta0)*sin(phi1);
          y2 = y1; y3 = y0;

          mcdis_multiline(5,
            x0,y0,z0,
            x1,y1,z1,
            x2,y2,z2,
            x3,y3,z3,
            x0,y0,z0);
        }
    }
    /* disk (circle) */
    else
    if (abs(Vars->Flag_Shape) == DEFS->SHAPE_DISK)
    {
      mcdis_magnify("");
      mcdis_circle("xy",0,0,0,radius);
    }
    /* rectangle (square) */
    else
    if (abs(Vars->Flag_Shape) == DEFS->SHAPE_SQUARE)
    {
      mcdis_magnify("xy");
      mcdis_multiline(5, (double)xmin, (double)ymin, 0.0,
             (double)xmax, (double)ymin, 0.0,
             (double)xmax, (double)ymax, 0.0,
             (double)xmin, (double)ymax, 0.0,
             (double)xmin, (double)ymin, 0.0);
    }
    /* full cylinder/banana */
    else
    if (!restricted && ((abs(Vars->Flag_Shape) == DEFS->SHAPE_CYLIND) || (abs(Vars->Flag_Shape) == DEFS->SHAPE_BANANA)))
    {
      mcdis_magnify("xyz");
      mcdis_circle("xz", 0,  h/2.0, 0, radius);
      mcdis_circle("xz", 0, -h/2.0, 0, radius);
      mcdis_line(-radius, -h/2.0, 0, -radius, +h/2.0, 0);
      mcdis_line(+radius, -h/2.0, 0, +radius, +h/2.0, 0);
      mcdis_line(0, -h/2.0, -radius, 0, +h/2.0, -radius);
      mcdis_line(0, -h/2.0, +radius, 0, +h/2.0, +radius);
    }
    else
    /* box */
    if (abs(Vars->Flag_Shape) == DEFS->SHAPE_BOX)
    {
      mcdis_magnify("xyz");
      mcdis_multiline(5, xmin, ymin, zmin,
                   xmax, ymin, zmin,
                   xmax, ymax, zmin,
                   xmin, ymax, zmin,
                   xmin, ymin, zmin);
      mcdis_multiline(5, xmin, ymin, zmax,
                   xmax, ymin, zmax,
                   xmax, ymax, zmax,
                   xmin, ymax, zmax,
                   xmin, ymin, zmax);
      mcdis_line(xmin, ymin, zmin, xmin, ymin, zmax);
      mcdis_line(xmax, ymin, zmin, xmax, ymin, zmax);
      mcdis_line(xmin, ymax, zmin, xmin, ymax, zmax);
      mcdis_line(xmax, ymax, zmin, xmax, ymax, zmax);
    }
  } /* end Monitor_nD_McDisplay */

/* end of monitor_nd-lib.c */

/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright 1997-2002, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/read_table-lib.h
*
* %Identification
* Written by: EF
* Date: Aug 28, 2002
* Origin: ILL
* Release: McStas 1.6
* Version: $Revision$
*
* This file is to be imported by components that may read data from table files
* It handles some shared functions.
*
* This library may be used directly as an external library. It has no dependency
*
* Usage: within SHARE
* %include "read_table-lib"
*
*******************************************************************************/

#ifndef READ_TABLE_LIB_H
#define READ_TABLE_LIB_H "$Revision$"

#define READ_TABLE_STEPTOL  0.04 /* tolerancy for constant step approx */

#ifndef MC_PATHSEP_C
#ifdef WIN32
#define MC_PATHSEP_C '\\'
#define MC_PATHSEP_S "\\"
#else  /* !WIN32 */
#ifdef MAC
#define MC_PATHSEP_C ':'
#define MC_PATHSEP_S ":"
#else  /* !MAC */
#define MC_PATHSEP_C '/'
#define MC_PATHSEP_S "/"
#endif /* !MAC */
#endif /* !WIN32 */
#endif /* !MC_PATHSEP_C */

#ifndef MCSTAS
#ifdef WIN32
#define MCSTAS "C:\\mcstas\\lib"
#else  /* !WIN32 */
#ifdef MAC
#define MCSTAS ":mcstas:lib" /* ToDo: What to put here? */
#else  /* !MAC */
#define MCSTAS "/usr/local/lib/mcstas"
#endif /* !MAC */
#endif /* !WIN32 */
#endif /* !MCSTAS */

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef _MSC_EXTENSIONS
#include <strings.h>
#else
#  include <string.h>
#  define strcasecmp _stricmp
#  define strncasecmp _strnicmp
#endif

  typedef struct struct_table
  {
    char    filename[1024];
    long    filesize;
    char   *header;  /* text header, e.g. comments */
    double *data;    /* vector { x[0], y[0], ... x[n-1], y[n-1]... } */
    double  min_x;   /* min value of first column */
    double  max_x;   /* max value of first column */
    double  step_x;  /* minimal step value of first column */
    long    rows;    /* number of rows in matrix block */
    long    columns; /* number of columns in matrix block */

    long    begin;   /* start fseek index of block */
    long    end;     /* stop  fseek index of block */
    long    block_number;  /* block index. 0 is catenation of all */
    long    array_length;  /* number of elements in the t_Table array */
    char    monotonic;     /* true when 1st column/vector data is monotonic */
    char    constantstep;  /* true when 1st column/vector data has constant step */
    char    method[32];    /* interpolation method: nearest, linear */
    char    quiet;   /*output level for messages to the console 0: print all messages, 1:only print some/including errors, 2: never print anything.*/
  } t_Table;

/*maximum number of rows to rebin a table = 1M*/
enum { mcread_table_rebin_maxsize = 1000000 };

typedef struct t_Read_table_file_item {
    int ref_count;
    t_Table *table_ref;
} t_Read_table_file_item;

typedef enum enum_Read_table_file_actions {STORE,FIND,GC}  t_Read_table_file_actions;

/* read_table-lib function prototypes */
/* ========================================================================= */

/* 'public' functions */
long     Table_Read              (t_Table *Table, char *File, long block_number);
long     Table_Read_Offset       (t_Table *Table, char *File, long block_number,
                                  long *offset, long max_lines);
long     Table_Read_Offset_Binary(t_Table *Table, char *File, char *Type,
                                  long *Offset, long Rows, long Columns);
long     Table_Rebin(t_Table *Table); /* rebin table with regular 1st column and interpolate all columns 2:end */
long     Table_Info (t_Table Table);
#pragma acc routine
double   Table_Index(t_Table Table,   long i, long j); /* get indexed value */
#pragma acc routine
double   Table_Value(t_Table Table, double X, long j); /* search X in 1st column and return interpolated value in j-column */
t_Table *Table_Read_Array(char *File, long *blocks);
void     Table_Free_Array(t_Table *Table);
long     Table_Info_Array(t_Table *Table);
int      Table_SetElement(t_Table *Table, long i, long j, double value);
long     Table_Init(t_Table *Table, long rows, long columns); /* create a Table */
#pragma acc routine
double   Table_Value2d(t_Table Table, double X, double Y);    /* same as Table_Index with non-integer indices and 2d interpolation */
MCDETECTOR Table_Write(t_Table Table, char*file, char*xl, char*yl, 
           double x1, double x2, double y1, double y2); /* write Table to disk */
void * Table_File_List_Handler(t_Read_table_file_actions action, void *item, void *item_modifier);
t_Table *Table_File_List_find(char *name, int block, int offset);
int Table_File_List_gc(t_Table *tab);
void *Table_File_List_store(t_Table *tab);

#define Table_ParseHeader(header, ...) \
  Table_ParseHeader_backend(header,__VA_ARGS__,NULL);

char **Table_ParseHeader_backend(char *header, ...);

/* private functions */
void Table_Free(t_Table *Table);
long Table_Read_Handle(t_Table *Table, FILE *fid, long block_number, long max_lines, char *name);
static void Table_Stat(t_Table *Table);
#pragma acc routine
double Table_Interp1d(double x, double x1, double y1, double x2, double y2);
#pragma acc routine
double Table_Interp1d_nearest(double x, double x1, double y1, double x2, double y2);
#pragma acc routine
double Table_Interp2d(double x, double y, double x1, double y1, double x2, double y2,
double z11, double z12, double z21, double z22);


#endif

/* end of read_table-lib.h */
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/read_table-lib.c
*
* %Identification
* Written by: EF
* Date: Aug 28, 2002
* Origin: ILL
* Release: McStas CVS_090504
* Version: $Revision$
*
* This file is to be imported by components that may read data from table files
* It handles some shared functions. Embedded within instrument in runtime mode.
*
* Usage: within SHARE
* %include "read_table-lib"
*
*******************************************************************************/

#ifndef READ_TABLE_LIB_H
#include "read_table-lib.h"
#endif


/*******************************************************************************
 * void *Table_File_List_Handler(action, item, item_modifier)
 *   ACTION: handle file entries in the read_table-lib file list. If a file is read - it is supposed to be
 *   stored in a list such that we can avoid reading the same file many times.
 *   input  action: FIND, STORE, GC. check if file exists in the list, store an item in the list, or check if it can be garbage collected.
 *   input item: depends on the action.
 *    FIND)  item is a filename, and item_modifier is the block number
 *    STORE) item is the Table to store - item_modifier is ignored
 *    GC)    item is the Table to check. If it has a ref_count >1 then this is simply decremented.
 *   return  depends on the action
 *    FIND)  return a reference to a table+ref_count item if found - NULL otherwise. I.e. NULL means the file has not been read before and must be read again.
 *    STORE) return NULL always
 *    GC)    return NULL if no garbage collection is needed, return an adress to the t_Table which should be garbage collected. 0x1 is returned if
 *           the item is not found in the list
*******************************************************************************/
void * Table_File_List_Handler(t_Read_table_file_actions action, void *item, void *item_modifier){

    /* logic here is Read_Table should include a call to FIND. If found the return value should just be used as
     * if the table had been read from disk. If not found then read the table and STORE.
     * Table_Free should include a call to GC. If this returns non-NULL then we should proceed with freeing the memory
     * associated with the table item - otherwise only decrement the reference counter since there are more references
     * that may need it.*/

    static t_Read_table_file_item read_table_file_list[1024];  
    static int read_table_file_count=0;

    t_Read_table_file_item *tr;
    switch(action){
        case FIND:
            /*interpret data item as a filename, if it is found return a pointer to the table and increment refcount.
             * if not found return the item itself*/
            tr=read_table_file_list;
            while ( tr->table_ref!=NULL ){
                int i=*((int*) item_modifier);
                int j=*( ((int*) item_modifier)+1);
                if ( !strcmp(tr->table_ref->filename,(char *) item) &&
                        tr->table_ref->block_number==i && tr->table_ref->begin==j ){
                    tr->ref_count++;
                    return (void *) tr;
                }
                tr++;
            }
            return NULL;
        case STORE:
            /*find an available slot and store references to table there*/
            tr=&(read_table_file_list[read_table_file_count++]);
            tr->table_ref = ((t_Table *) item);
            tr->ref_count++;
            return NULL;
        case GC:
            /* Should this item be garbage collected (freed) - if so scratch the entry and return the address of the item - 
             * else decrement ref_count and return NULL.
             * A non-NULL return expects the item to actually be freed afterwards.*/
            tr=read_table_file_list;
            while ( tr->table_ref!=NULL ){
                if ( tr->table_ref->data ==((t_Table *)item)->data && 
                        tr->table_ref->block_number == ((t_Table *)item)->block_number){
                    /*matching item found*/
                    if (tr->ref_count>1){
                        /*the item is found and no garbage collection needed*/
                        tr->ref_count--;
                        return NULL;
                    }else{
                        /* The item is found and the reference counter is 1.
                         * This means we should garbage collect. Move remaining list items up one slot,
                         * and return the table for garbage collection by caller*/
                        while (tr->table_ref!=NULL){
                            *tr=*(tr+1);
                            tr++;
                        }
                        read_table_file_count--;
                        return (t_Table *) item;
                    }
                }
                tr++;
            }
            /* item not found, and so should be garbage collected. This could be the case if freeing a
             * Table that has been constructed from code - not read from file. Return 0x1 to flag it for
             * collection.*/
            return (void *) 0x1 ;
    }
    /* If we arrive here, nothing worked, return NULL */
    return NULL;
}

/* Access functions to the handler*/

/********************************************
 * t_Table *Table_File_List_find(char *name, int block, int offset)
 * input name: filename to search for in the file list
 * input block: data block in the file as each file may contain more than 1 data block.
 * return a ref. to a table if it is found (you may use this pointer and skip reading the file), NULL otherwise (i.e. go ahead and read the file)
*********************************************/
t_Table *Table_File_List_find(char *name, int block, int offset){
    int vars[2]={block,offset};
    t_Read_table_file_item *item = Table_File_List_Handler(FIND,name, vars);
    if (item == NULL){
        return NULL;
    }else{
        return item->table_ref;
    }
}
/********************************************
 * int Table_File_List_gc(t_Table *tab)
 * input tab: the table to check for references.
 * return 0: no garbage collection needed
 *        1: Table's data and header (at least) should be freed.
*********************************************/
int Table_File_List_gc(t_Table *tab){
    void *rval=Table_File_List_Handler(GC,tab,0);
    if (rval==NULL) return 0;
    else return 1;
}


/*****************************************************************************
 * void *Table_File_List_store(t_Table *tab)
 * input tab: pointer to table to store.
 * return None. 
*******************************************************************************/
void *Table_File_List_store(t_Table *tab){
    return Table_File_List_Handler(STORE,tab,0);
}


/*******************************************************************************
* FILE *Open_File(char *name, char *Mode, char *path)
*   ACTION: search for a file and open it. Optionally return the opened path.
*   input   name:  file name from which table should be extracted
*           mode: "r", "w", "a" or any valid fopen mode
*           path:  NULL or a pointer to at least 1024 allocated chars
*   return  initialized file handle or NULL in case of error
*******************************************************************************/

  FILE *Open_File(char *File, const char *Mode, char *Path)
  {
    char path[1024];
    FILE *hfile = NULL;
    
    if (!File || File[0]=='\0')                     return(NULL);
    if (!strcmp(File,"NULL") || !strcmp(File,"0"))  return(NULL);
    
    /* search in current or full path */
    strncpy(path, File, 1024);
    hfile = fopen(path, Mode);
    if(!hfile)
    {
      char dir[1024];

      if (!hfile && instrument_source[0] != '\0' && strlen(instrument_source)) /* search in instrument source location */
      {
        char *path_pos   = NULL;
        /* extract path: searches for last file separator */
        path_pos    = strrchr(instrument_source, MC_PATHSEP_C);  /* last PATHSEP */
        if (path_pos) {
          long path_length = path_pos +1 - instrument_source;  /* from start to path+sep */
          if (path_length) {
            strncpy(dir, instrument_source, path_length);
            dir[path_length] = '\0';
            snprintf(path, 1024, "%s%c%s", dir, MC_PATHSEP_C, File);
            hfile = fopen(path, Mode);
          }
        }
      }
      if (!hfile && instrument_exe[0] != '\0' && strlen(instrument_exe)) /* search in PWD instrument executable location */
      {
        char *path_pos   = NULL;
        /* extract path: searches for last file separator */
        path_pos    = strrchr(instrument_exe, MC_PATHSEP_C);  /* last PATHSEP */
        if (path_pos) {
          long path_length = path_pos +1 - instrument_exe;  /* from start to path+sep */
          if (path_length) {
            strncpy(dir, instrument_exe, path_length);
            dir[path_length] = '\0';
            snprintf(path, 1024, "%s%c%s", dir, MC_PATHSEP_C, File);
            hfile = fopen(path, Mode);
          }
        }
      }
      if (!hfile) /* search in HOME or . */
      {
        strcpy(dir, getenv("HOME") ? getenv("HOME") : ".");
        snprintf(path, 1024, "%s%c%s", dir, MC_PATHSEP_C, File);
        hfile = fopen(path, Mode);
      }
      if (!hfile) /* search in MCSTAS/data */
      {
        strcpy(dir, getenv(FLAVOR_UPPER) ? getenv(FLAVOR_UPPER) : MCSTAS);
        snprintf(path, 1024, "%s%c%s%c%s", dir, MC_PATHSEP_C, "data", MC_PATHSEP_C, File);
        hfile = fopen(path, Mode);
      }
      if (!hfile) /* search in MVCSTAS/contrib */
      {
        strcpy(dir, getenv(FLAVOR_UPPER) ? getenv(FLAVOR_UPPER) : MCSTAS);
        snprintf(path, 1024, "%s%c%s%c%s", dir, MC_PATHSEP_C, "contrib", MC_PATHSEP_C, File);
        hfile = fopen(path, Mode);
      }
      if(!hfile)
      {
        // fprintf(stderr, "Warning: Could not open input file '%s' (Open_File)\n", File);
        return (NULL);
      }
    }
    if (Path) strncpy(Path, path, 1024);
    return(hfile);
  } /* end Open_File */

/*******************************************************************************
* long Read_Table(t_Table *Table, char *name, int block_number)
*   ACTION: read a single Table from a text file
*   input   Table: pointer to a t_Table structure
*           name:  file name from which table should be extracted
*           block_number: if the file does contain more than one
*                 data block, then indicates which one to get (from index 1)
*                 a 0 value means append/catenate all
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
* The routine stores any line starting with '#', '%' and ';' into the header
* File is opened, read and closed
* Other lines are interpreted as numerical data, and stored.
* Data block should be a rectangular matrix or vector.
* Data block may be rebinned with Table_Rebin (also sort in ascending order)
*******************************************************************************/
  long Table_Read(t_Table *Table, char *File, long block_number)
  { /* reads all or a single data block from 'file' and returns a Table structure  */
    return(Table_Read_Offset(Table, File, block_number, NULL, 0));
  } /* end Table_Read */

/*******************************************************************************
* long Table_Read_Offset(t_Table *Table, char *name, int block_number, long *offset
*                        long max_rows)
*   ACTION: read a single Table from a text file, starting at offset
*     Same as Table_Read(..) except:
*   input   offset:    pointer to an offset (*offset should be 0 at start)
*           max_rows: max number of data rows to read from file (0 means all)
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
*           updated *offset position (where end of reading occured)
*******************************************************************************/
  long Table_Read_Offset(t_Table *Table, char *File,
                         long block_number, long *offset,
                         long max_rows)
  { /* reads all/a data block in 'file' and returns a Table structure  */
    FILE *hfile;
    long  nelements=0;
    long  begin=0;
    long  filesize=0;
    char  name[1024];
    char  path[1024];
    struct stat stfile;

    /*Need to be able to store the pointer*/
    if (!Table) return(-1);

    /*TK: Valgrind flags it as usage of uninitialised variable: */
    Table->quiet = 0;

    //if (offset && *offset) snprintf(name, 1024, "%s@%li", File, *offset);
    //else                   
    strncpy(name, File, 1024);
    if(offset && *offset){
        begin=*offset;
    }
    /* Check if the table has already been read from file.
     * If so just reuse the table, if not (this is flagged by returning NULL
     * set up a new table and read the data into it */
    t_Table *tab_p= Table_File_List_find(name,block_number,begin);
    if ( tab_p!=NULL ){
        /*table was found in the Table_File_List*/
        *Table=*tab_p;
        MPI_MASTER(
            if(Table->quiet<1)
              printf("Reusing input file '%s' (Table_Read_Offset)\n", name);
            );
        return Table->rows*Table->columns;
    }

    /* open the file */
    hfile = Open_File(File, "r", path);
    if (!hfile) return(-1);
    else {
      MPI_MASTER(
          if(Table->quiet<1)
            printf("Opening input file '%s' (Table_Read_Offset)\n", path);
          );
    }
    
    /* read file state */
    stat(path,&stfile); filesize = stfile.st_size;
    if (offset && *offset) fseek(hfile, *offset, SEEK_SET);
    begin     = ftell(hfile);
    
    Table_Init(Table, 0, 0);

    /* read file content and set the Table */
    nelements = Table_Read_Handle(Table, hfile, block_number, max_rows, name);
    Table->begin = begin;
    Table->end   = ftell(hfile);
    Table->filesize = (filesize>0 ? filesize : 0);
    Table_Stat(Table);
    
    Table_File_List_store(Table);

    if (offset) *offset=Table->end;
    fclose(hfile);
    return(nelements);

  } /* end Table_Read_Offset */

/*******************************************************************************
* long Table_Read_Offset_Binary(t_Table *Table, char *File, char *type,
*                               long *offset, long rows, long columns)
*   ACTION: read a single Table from a binary file, starting at offset
*     Same as Table_Read_Offset(..) except that it handles binary files.
*   input   type: may be "float"/NULL or "double"
*           offset: pointer to an offset (*offset should be 0 at start)
*           rows   : number of rows (0 means read all)
*           columns: number of columns
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
*           updated *offset position (where end of reading occured)
*******************************************************************************/
  long Table_Read_Offset_Binary(t_Table *Table, char *File, char *type,
                                long *offset, long rows, long columns)
  { /* reads all/a data block in binary 'file' and returns a Table structure  */
    long    nelements, sizeofelement;
    long    filesize;
    FILE   *hfile;
    char    path[1024];
    struct stat stfile;
    double *data;
    long    i;
    long    begin;

    if (!Table) return(-1);

    Table_Init(Table, 0, 0);
    
    /* open the file */
    hfile = Open_File(File, "r", path);
    if (!hfile) return(-1);
    else {
      MPI_MASTER(
          if(Table->quiet<1)
            printf("Opening input file '%s' (Table_Read, Binary)\n", path);
      );
    }
    
    /* read file state */
    stat(File,&stfile);
    filesize = stfile.st_size;
    Table->filesize=filesize;
    
    /* read file content */
    if (type && !strcmp(type,"double")) sizeofelement = sizeof(double);
    else  sizeofelement = sizeof(float);
    if (offset && *offset) fseek(hfile, *offset, SEEK_SET);
    begin     = ftell(hfile);
    if (rows && filesize > sizeofelement*columns*rows)
      nelements = columns*rows;
    else nelements = (long)(filesize/sizeofelement);
    if (!nelements || filesize <= *offset) return(0);
    data    = (double*)malloc(nelements*sizeofelement);
    if (!data) {
      if(!(Table->quiet>1))
        fprintf(stderr,"Error: allocating %ld elements for %s file '%s'. Too big (Table_Read_Offset_Binary).\n", nelements, type, File);
      exit(-1);
    }
    nelements = fread(data, sizeofelement, nelements, hfile);

    if (!data || !nelements)
    {
      if(!(Table->quiet>1))
        fprintf(stderr,"Error: reading %ld elements from %s file '%s' (Table_Read_Offset_Binary)\n", nelements, type, File);
      exit(-1);
    }
    Table->begin   = begin;
    Table->end     = ftell(hfile);
    if (offset) *offset=Table->end;
    fclose(hfile);
    data = (double*)realloc(data, (double)nelements*sizeofelement);
    if (!data) {
      fprintf(stderr,"Error: reallocating %ld elements for %s file '%s'. Too big (Table_Read_Offset_Binary).\n", nelements, type, File);
      exit(-1);
    }
    /* copy file data into Table */
    if (type && !strcmp(type,"double")) Table->data = data;
    else {
      float  *s;
      double *dataf;
      s     = (float*)data;
      dataf = (double*)malloc(sizeof(double)*nelements);
      for (i=0; i<nelements; i++)
        dataf[i]=s[i];
      free(data);
      Table->data = dataf;
    }
    strncpy(Table->filename, File, 1024);
    Table->rows    = nelements/columns;
    Table->columns = columns;
    Table->array_length = 1;
    Table->block_number = 1;

    Table_Stat(Table);

    return(nelements);
  } /* end Table_Read_Offset_Binary */

/*******************************************************************************
* long Table_Read_Handle(t_Table *Table, FILE *fid, int block_number, long max_rows, char *name)
*   ACTION: read a single Table from a text file handle (private)
*   input   Table:pointer to a t_Table structure
*           fid:  pointer to FILE handle
*           block_number: if the file does contain more than one
*                 data block, then indicates which one to get (from index 1)
*                 a 0 value means append/catenate all
*           max_rows: if non 0, only reads that number of lines
*   return  initialized single Table t_Table structure containing data, header, ...
*           modified Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
* The routine stores any line starting with '#', '%' and ';' into the header
* Other lines are interpreted as numerical data, and stored.
* Data block should be a rectangular matrix or vector.
* Data block may be rebined with Table_Rebin (also sort in ascending order)
*******************************************************************************/
  long Table_Read_Handle(t_Table *Table, FILE *hfile,
                         long block_number, long max_rows, char *name)
  { /* reads all/a data block from 'file' handle and returns a Table structure  */
    double *Data;
    char *Header              = NULL;
    long  malloc_size         = CHAR_BUF_LENGTH;
    long  malloc_size_h       = 4096;
    long  Rows = 0,   Columns = 0;
    long  count_in_array      = 0;
    long  count_in_header     = 0;
    long  count_invalid       = 0;
    long  block_Current_index = 0;
    char  flag_End_row_loop   = 0;

    if (!Table) return(-1);
    Table_Init(Table, 0, 0);
    if (name && name[0]!='\0') strncpy(Table->filename, name, 1024);

    if(!hfile) {
       fprintf(stderr, "Error: File handle is NULL (Table_Read_Handle).\n");
       return (-1);
    }
    Header = (char*)  calloc(malloc_size_h, sizeof(char));
    Data   = (double*)calloc(malloc_size,   sizeof(double));
    if ((Header == NULL) || (Data == NULL)) {
       fprintf(stderr, "Error: Could not allocate Table and Header (Table_Read_Handle).\n");
       return (-1);
    }

    int flag_In_array = 0;
    do { /* while (!flag_End_row_loop) */
      char  *line=malloc(1024*CHAR_BUF_LENGTH*sizeof(char));
      long  back_pos=0;   /* ftell start of line */

      back_pos = ftell(hfile);
      if (fgets(line, 1024*CHAR_BUF_LENGTH, hfile) != NULL) { /* analyse line */
        /* first skip blank and tabulation characters */
        int i = strspn(line, " \t");

        /* handle comments: stored in header */
        if (NULL != strchr("#%;/", line[i]))
        { /* line is a comment */
          count_in_header += strlen(line);
          if (count_in_header >= malloc_size_h) {
            /* if succeed and in array : add (and realloc if necessary) */
            malloc_size_h = count_in_header+4096;
            Header        = (char*)realloc(Header, malloc_size_h*sizeof(char));
	    if(!Header) {
	             fprintf(stderr, "Error: Could not reallocate Header (Table_Read_Handle).\n");
		     return (-1);
	    }
          }
          strncat(Header, line, 4096);
          flag_In_array=0;
          /* exit line and file if passed desired block */
          if (block_number > 0 && block_number == block_Current_index) {
            flag_End_row_loop = 1;
          }

          /* Continue with next line */
          continue;
        }
        if (strstr(line, "***"))
        {
          count_invalid++;
          /* Continue with next line */
          continue;
        }

        /* get the number of columns splitting line with strtok */
        char  *lexeme;
        char  flag_End_Line = 0;
        long  block_Num_Columns = 0;
        const char seps[] = " ,;\t\n\r";

        lexeme = strtok(line, seps);
        while (!flag_End_Line) {
          if ((lexeme != NULL) && (lexeme[0] != '\0')) {
            /* reading line: the token is not empty */
            double X;
            int    count=1;
            /* test if we have 'NaN','Inf' */
            if (!strncasecmp(lexeme,"NaN",3))
              X = 0;
            else if (!strncasecmp(lexeme,"Inf",3) || !strncasecmp(lexeme,"+Inf",4))
              X = FLT_MAX;
            else if (!strncasecmp(lexeme,"-Inf",4))
              X = -FLT_MAX;
            else
              count = sscanf(lexeme,"%lg",&X);
            if (count == 1) {
              /* reading line: the token is a number in the line */
              if (!flag_In_array) {
                /* reading num: not already in a block: starts a new data block */
                block_Current_index++;
                flag_In_array    = 1;
                block_Num_Columns= 0;
                if (block_number > 0) {
                  /* initialise a new data block */
                  Rows = 0;
                  count_in_array = 0;
                } /* else append */
              }
              /* reading num: all blocks or selected block */
              if (flag_In_array && (block_number == 0 ||
                  block_number == block_Current_index)) {
                /* starting block: already the desired number of rows ? */
                if (block_Num_Columns == 0 &&
                    max_rows > 0 && Rows >= max_rows) {
                  flag_End_Line      = 1;
                  flag_End_row_loop  = 1;
                  flag_In_array      = 0;
                  /* reposition to begining of line (ignore line) */
                  fseek(hfile, back_pos, SEEK_SET);
                } else { /* store into data array */
                  if (count_in_array >= malloc_size) {
                    /* realloc data buffer if necessary */
                    malloc_size = count_in_array*1.5;
                    Data = (double*) realloc(Data, malloc_size*sizeof(double));
                    if (Data == NULL) {
                      fprintf(stderr, "Error: Can not re-allocate memory %li (Table_Read_Handle).\n",
                              malloc_size*sizeof(double));
                      return (-1);
                    }
                  }
                  if (0 == block_Num_Columns) Rows++;
                  Data[count_in_array] = X;
                  count_in_array++;
                  block_Num_Columns++;
                }
              } /* reading num: end if flag_In_array */
            } /* end reading num: end if sscanf lexeme -> numerical */
            else {
              /* reading line: the token is not numerical in that line. end block */
              if (block_Current_index == block_number) {
                flag_End_Line = 1;
                flag_End_row_loop = 1;
              } else {
                flag_In_array = 0;
                flag_End_Line = 1;
              }
            }
          }
          else {
            /* no more tokens in line */
            flag_End_Line = 1;
            if (block_Num_Columns > 0) Columns = block_Num_Columns;
          }

          // parse next token
          lexeme = strtok(NULL, seps);

        } /* while (!flag_End_Line) */
      } /* end: if fgets */
      else flag_End_row_loop = 1; /* else fgets : end of file */
      free(line);
    } while (!flag_End_row_loop); /* end while flag_End_row_loop */

    Table->block_number = block_number;
    Table->array_length = 1;

    // shrink header to actual size (plus terminating 0-byte)
    if (count_in_header) {
      Header = (char*)realloc(Header, count_in_header*sizeof(char) + 1);
      if(!Header) {
	fprintf(stderr, "Error: Could not shrink Header (Table_Read_Handle).\n");
	return (-1);
      }
    }
    Table->header = Header;

    if (count_in_array*Rows*Columns == 0)
    {
      Table->rows         = 0;
      Table->columns      = 0;
      free(Data);
      return (0);
    }
    if (Rows * Columns != count_in_array)
    {
      fprintf(stderr, "Warning: Read_Table :%s %s Data has %li values that should be %li x %li\n",
        (Table->filename[0] != '\0' ? Table->filename : ""),
        (!block_number ? " catenated" : ""),
        count_in_array, Rows, Columns);
      Columns = count_in_array; Rows = 1;
    }
    if (count_invalid)
    {
      fprintf(stderr,"Warning: Read_Table :%s %s Data has %li invalid lines (*****). Ignored.\n",
      (Table->filename[0] != '\0' ? Table->filename : ""),
        (!block_number ? " catenated" : ""),
        count_invalid);
    }
    Data     = (double*)realloc(Data, count_in_array*sizeof(double));
    if(!Data) {
      fprintf(stderr, "Error: Could reallocate Data block to %li doubles (Table_Read_Handle).\n", count_in_array);
      return (-1);
    }
    Table->data         = Data;
    Table->rows         = Rows;
    Table->columns      = Columns;

    return (count_in_array);

  } /* end Table_Read_Handle */

/*******************************************************************************
* long Table_Rebin(t_Table *Table)
*   ACTION: rebin a single Table, sorting 1st column in ascending order
*   input   Table: single table containing data.
*                  The data block is reallocated in this process
*   return  updated Table with increasing, evenly spaced first column (index 0)
*           number of data elements (-1: error, 0:empty data)
*******************************************************************************/
  long Table_Rebin(t_Table *Table)
  {
    double new_step=0;
    long   i;
    /* performs linear interpolation on X axis (0-th column) */

    if (!Table) return(-1);
    if (!Table->data 
    || Table->rows*Table->columns == 0 || !Table->step_x)
      return(0);
    Table_Stat(Table); /* recompute statitstics and minimal step */
    new_step = Table->step_x; /* minimal step in 1st column */

    if (!(Table->constantstep)) /* not already evenly spaced */
    {
      long Length_Table;
      double *New_Table;

      Length_Table = ceil(fabs(Table->max_x - Table->min_x)/new_step)+1;
      /*return early if the rebinned table will become too large*/
      if (Length_Table > mcread_table_rebin_maxsize){
        fprintf(stderr,"WARNING: (Table_Rebin): Rebinning table from %s would exceed 1M rows. Skipping.\n", Table->filename); 
        return(Table->rows*Table->columns);
      }
      New_Table    = (double*)malloc(Length_Table*Table->columns*sizeof(double));

      for (i=0; i < Length_Table; i++)
      {
        long   j;
        double X;
        X = Table->min_x + i*new_step;
        New_Table[i*Table->columns] = X;
        for (j=1; j < Table->columns; j++)
          New_Table[i*Table->columns+j]
                = Table_Value(*Table, X, j);
      } /* end for i */

      Table->rows = Length_Table;
      Table->step_x = new_step;
      Table->max_x = Table->min_x + (Length_Table-1)*new_step; 
      /*max might not be the same anymore
       * Use Length_Table -1 since the first and laset rows are the limits of the defined interval.*/
      free(Table->data);
      Table->data = New_Table;
      Table->constantstep=1;
    } /* end else (!constantstep) */
    return (Table->rows*Table->columns);
  } /* end Table_Rebin */

/*******************************************************************************
* double Table_Index(t_Table Table, long i, long j)
*   ACTION: read an element [i,j] of a single Table
*   input   Table: table containing data
*           i : index of row      (0:Rows-1)
*           j : index of column   (0:Columns-1)
*   return  Value = data[i][j]
* Returns Value from the i-th row, j-th column of Table
* Tests are performed on indexes i,j to avoid errors
*******************************************************************************/

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif

double Table_Index(t_Table Table, long i, long j)
{
  long AbsIndex;

  if (Table.rows == 1 || Table.columns == 1) {
    /* vector */
    j = MIN(MAX(0, i+j), Table.columns*Table.rows - 1);
    i = 0;
  } else {
    /* matrix */
    i = MIN(MAX(0, i), Table.rows - 1);
    j = MIN(MAX(0, j), Table.columns - 1);
  }

  /* handle vectors specifically */
  AbsIndex = i*(Table.columns)+j;

  if (Table.data != NULL)
    return (Table.data[AbsIndex]);
  else
    return 0;
} /* end Table_Index */

/*******************************************************************************
* void Table_SetElement(t_Table *Table, long i, long j, double value)
*   ACTION: set an element [i,j] of a single Table
*   input   Table: table containing data
*           i : index of row      (0:Rows-1)
*           j : index of column   (0:Columns-1)
*           value = data[i][j]
* Returns 0 in case of error
* Tests are performed on indexes i,j to avoid errors
*******************************************************************************/
int Table_SetElement(t_Table *Table, long i, long j,
                     double value)
{
  long AbsIndex;

  if (Table->rows == 1 || Table->columns == 1) {
    /* vector */
    j = MIN(MAX(0, i+j), Table->columns*Table->rows - 1); i=0;
  } else {
    /* matrix */
    i = MIN(MAX(0, i), Table->rows - 1);
    j = MIN(MAX(0, j), Table->columns - 1);
  }

  AbsIndex = i*(Table->columns)+j;
  if (Table->data != NULL) {
    Table->data[AbsIndex] = value;
    return 1;
  }

  return 0;
} /* end Table_SetElement */

/*******************************************************************************
* double Table_Value(t_Table Table, double X, long j)
*   ACTION: read column [j] of a single Table at row which 1st column is X
*   input   Table: table containing data.
*           X : data value in the first column (index 0)
*           j : index of column from which is extracted the Value (0:Columns-1)
*   return  Value = data[index for X][j] with linear interpolation
* Returns Value from the j-th column of Table corresponding to the
* X value for the 1st column (index 0)
* Tests are performed (within Table_Index) on indexes i,j to avoid errors
* NOTE: data should rather be monotonic, and evenly sampled.
*******************************************************************************/
double Table_Value(t_Table Table, double X, long j)
{
  long   Index = -1;
  double X1=0, Y1=0, X2=0, Y2=0;
  double ret=0;

  if (X > Table.max_x) return Table_Index(Table,Table.rows-1  ,j);
  if (X < Table.min_x) return Table_Index(Table,0  ,j);

  // Use constant-time lookup when possible
  if(Table.constantstep) {
    Index = (long)floor(
              (X - Table.min_x) / (Table.max_x - Table.min_x) * (Table.rows-1));
    X1 = Table_Index(Table,Index-1,0);
    X2 = Table_Index(Table,Index  ,0);
  }
  // Use binary search on large, monotonic tables
  else if(Table.monotonic && Table.rows > 100) {
    long left = Table.min_x;
    long right = Table.max_x;

    while (!((X1 <= X) && (X < X2)) && (right - left > 1)) {
      Index = (left + right) / 2;

      X1 = Table_Index(Table, Index-1, 0);
      X2 = Table_Index(Table, Index,   0);

      if (X < X1) {
        right = Index;
      } else {
        left  = Index;
      }
    }
  }

  // Fall back to linear search, if no-one else has set X1, X2 correctly
  if (!((X1 <= X) && (X < X2))) {
    /* look for index surrounding X in the table -> Index */
    for (Index=1; Index <= Table.rows-1; Index++) {
        X1 = Table_Index(Table, Index-1,0);
        X2 = Table_Index(Table, Index  ,0);
        if ((X1 <= X) && (X < X2)) break;
      } /* end for Index */
  }

  Y1 = Table_Index(Table,Index-1, j);
  Y2 = Table_Index(Table,Index  , j);

#ifdef OPENACC
#define strcmp(a,b) str_comp(a,b)
#endif

  if (!strcmp(Table.method,"linear")) {
    ret = Table_Interp1d(X, X1,Y1, X2,Y2);
  }
  else if (!strcmp(Table.method,"nearest")) {
    ret = Table_Interp1d_nearest(X, X1,Y1, X2,Y2);
  }

#ifdef OPENACC
#ifdef strcmp
#undef strcmp
#endif
#endif

  return ret;
} /* end Table_Value */

/*******************************************************************************
* double Table_Value2d(t_Table Table, double X, double Y)
*   ACTION: read element [X,Y] of a matrix Table
*   input   Table: table containing data.
*           X : row index, may be non integer
*           Y : column index, may be non integer
*   return  Value = data[index X][index Y] with bi-linear interpolation
* Returns Value for the indices [X,Y]
* Tests are performed (within Table_Index) on indexes i,j to avoid errors
* NOTE: data should rather be monotonic, and evenly sampled.
*******************************************************************************/
double Table_Value2d(t_Table Table, double X, double Y)
  {
    long   x1,x2,y1,y2;
    double z11,z12,z21,z22;
    double ret=0;

    x1 = (long)floor(X);
    y1 = (long)floor(Y);

    if (x1 > Table.rows-1 || x1 < 0) {
      x2 = x1;
    } else {
      x2 = x1 + 1;
    }

    if (y1 > Table.columns-1 || y1 < 0) {
      y2 = y1;
    } else {
      y2 = y1 + 1;
    }

    z11 = Table_Index(Table, x1, y1);

    if (y2 != y1) z12=Table_Index(Table, x1, y2); else z12 = z11;
    if (x2 != x1) z21=Table_Index(Table, x2, y1); else z21 = z11;
    if (y2 != y1) z22=Table_Index(Table, x2, y2); else z22 = z21;

#ifdef OPENACC
#define strcmp(a,b) str_comp(a,b)
#endif

    if (!strcmp(Table.method,"linear"))
      ret = Table_Interp2d(X,Y, x1,y1,x2,y2, z11,z12,z21,z22);
#ifdef OPENACC
#ifdef strcmp
#undef strcmp
#endif
#endif
    else {
      if (fabs(X-x1) < fabs(X-x2)) {
        if (fabs(Y-y1) < fabs(Y-y2)) ret = z11; else ret = z12;
      } else {
        if (fabs(Y-y1) < fabs(Y-y2)) ret = z21; else ret = z22;
      }
    }
    return ret;
  } /* end Table_Value2d */


/*******************************************************************************
* void Table_Free(t_Table *Table)
*   ACTION: free a single Table. First Call Table_File_list_gc. If this returns
*   non-zero it means there are more refernces to the table, and so the table
*   should not bee freed.
*   return: empty Table
*******************************************************************************/
  void Table_Free(t_Table *Table)
  {
    if( !Table_File_List_gc(Table) ){
       return;
    } 
    if (!Table) return;
    if (Table->data   != NULL) free(Table->data);
    if (Table->header != NULL) free(Table->header);
    Table->data   = NULL;
    Table->header = NULL;
  } /* end Table_Free */

/******************************************************************************
* void Table_Info(t_Table Table)
*    ACTION: print informations about a single Table
*******************************************************************************/
  long Table_Info(t_Table Table)
  {
    char buffer[256];
    long ret=0;

    if (!Table.block_number) strcpy(buffer, "catenated");
    else sprintf(buffer, "block %li", Table.block_number);
    printf("Table from file '%s' (%s)",
        Table.filename[0] != '\0' ? Table.filename : "", buffer);
    if ((Table.data != NULL) && (Table.rows*Table.columns))
    {
      printf(" is %li x %li ", Table.rows, Table.columns);
      if (Table.rows*Table.columns > 1)
        printf("(x=%g:%g)", Table.min_x, Table.max_x);
      else printf("(x=%g) ", Table.min_x);
      ret = Table.rows*Table.columns;
      if (Table.monotonic)    printf(", monotonic");
      if (Table.constantstep) printf(", constant step");
      printf(". interpolation: %s\n", Table.method);
    }
    else printf(" is empty.\n");

    if (Table.header && strlen(Table.header)) {
      char *header;
      int  i;
      header = malloc(80);
      if (!header) return(ret);
      for (i=0; i<80; header[i++]=0);
      strncpy(header, Table.header, 75);
      if (strlen(Table.header) > 75) {
        strcat( header, " ...");
      }
      for (i=0; i<strlen(header); i++)
        if (header[i] == '\n' || header[i] == '\r') header[i] = ';';
      printf("  '%s'\n", header);
      free(header);
    }

    return(ret);
  } /* end Table_Info */

/******************************************************************************
* long Table_Init(t_Table *Table, m, n)
*   ACTION: initialise a Table to empty m by n table
*   return: empty Table
******************************************************************************/
long Table_Init(t_Table *Table, long rows, long columns)
{
  double *data=NULL;
  long   i;

  if (!Table) return(0);

  Table->header  = NULL;
  Table->filename[0]= '\0';
  Table->filesize= 0;
  Table->min_x   = 0;
  Table->max_x   = 0;
  Table->step_x  = 0;
  Table->block_number = 0;
  Table->array_length = 0;
  Table->monotonic    = 0;
  Table->constantstep = 0;
  Table->begin   = 0;
  Table->end     = 0;
  strcpy(Table->method,"linear");

  if (rows*columns >= 1) {
    data    = (double*)malloc(rows*columns*sizeof(double));
    if (data) for (i=0; i < rows*columns; data[i++]=0);
    else {
      if(Table->quiet<2)
        fprintf(stderr,"Error: allocating %ld double elements."
            "Too big (Table_Init).\n", rows*columns);
      rows = columns = 0;
    }
  }
  Table->rows    = (rows >= 1 ? rows : 0);
  Table->columns = (columns >= 1 ? columns : 0);
  Table->data    = data;
  return(Table->rows*Table->columns);
} /* end Table_Init */

/******************************************************************************
* long Table_Write(t_Table Table, char *file, x1,x2, y1,y2)
*   ACTION: write a Table to disk (ascii).
*     when x1=x2=0 or y1=y2=0, the table default limits are used.
*   return: 0=all is fine, non-0: error
*******************************************************************************/
MCDETECTOR Table_Write(t_Table Table, char *file, char *xl, char *yl, 
  double x1, double x2, double y1, double y2)
{
  MCDETECTOR detector;

  if ((Table.data == NULL) && (Table.rows*Table.columns)) {
    detector.m = 0;
    return(detector); /* Table is empty - nothing to do */
  }
  if (!x1 && !x2) {
    x1 = Table.min_x;
    x2 = Table.max_x;
  }
  if (!y1 && !y2) {
    y1 = 1;
    y2 = Table.columns;
  }

  /* transfer content of the Table into a 2D detector */
  Coords coords = { 0, 0, 0};

  if (Table.rows == 1 || Table.columns == 1) {
    detector = mcdetector_out_1D(Table.filename,
                      xl ? xl : "", yl ? yl : "",
                      "x", x1, x2,
                      Table.rows * Table.columns,
                      NULL, Table.data, NULL,
                      file, file, coords);
  } else {
    detector = mcdetector_out_2D(Table.filename,
                      xl ? xl : "", yl ? yl : "",
                      x1, x2, y1, y2,
                      Table.rows, Table.columns,
                      NULL, Table.data, NULL,
                      file, file, coords);
  }
  return(detector);
}

/******************************************************************************
* void Table_Stat(t_Table *Table)
*   ACTION: computes min/max/mean step of 1st column for a single table (private)
*   return: updated Table
*******************************************************************************/
  static void Table_Stat(t_Table *Table)
  {
    long   i;
    double max_x, min_x;
    double row=1;
    char   monotonic=1;
    char   constantstep=1;
    double step=0;
    long n;

    if (!Table) return;
    if (!Table->rows || !Table->columns) return;
    if (Table->rows == 1) row=0; // single row
    max_x = -FLT_MAX;
    min_x =  FLT_MAX;
    n     = (row ? Table->rows : Table->columns);
    /* get min and max of first column/vector */
    for (i=0; i < n; i++)
    {
      double X;
      X = (row ? Table_Index(*Table,i  ,0)
                               : Table_Index(*Table,0, i));
      if (X < min_x) min_x = X;
      if (X > max_x) max_x = X;
    } /* for */
    
    /* test for monotonicity and constant step if the table is an XY or single vector */
    if (n > 1) {
      /* mean step */
      step = (max_x - min_x)/(n-1);
      /* now test if table is monotonic on first column, and get minimal step size */
      for (i=0; i < n-1; i++) {
        double X, diff;;
        X    = (row ? Table_Index(*Table,i  ,0)
                    : Table_Index(*Table,0,  i));
        diff = (row ? Table_Index(*Table,i+1,0)
                    : Table_Index(*Table,0,  i+1)) - X;
        if (diff && fabs(diff) < fabs(step)) step = diff;
        /* change sign ? */
        if ((max_x - min_x)*diff < 0 && monotonic)
          monotonic = 0;
      } /* end for */
      
      /* now test if steps are constant within READ_TABLE_STEPTOL */
      if(!step){
        /*means there's a disconitnuity -> not constantstep*/
        constantstep=0;
      }else if (monotonic) {
        for (i=0; i < n-1; i++) {
          double X, diff;
          X    = (row ? Table_Index(*Table,i  ,0)
              : Table_Index(*Table,0,  i));
          diff = (row ? Table_Index(*Table,i+1,0)
              : Table_Index(*Table,0,  i+1)) - X;
          if ( fabs(step)*(1+READ_TABLE_STEPTOL) < fabs(diff) ||
                fabs(diff) < fabs(step)*(1-READ_TABLE_STEPTOL) )
          { constantstep = 0; break; }
        }
      }

    }
    Table->step_x= step;
    Table->max_x = max_x;
    Table->min_x = min_x;
    Table->monotonic = monotonic;
    Table->constantstep = constantstep;
  } /* end Table_Stat */

/******************************************************************************
* t_Table *Table_Read_Array(char *File, long *blocks)
*   ACTION: read as many data blocks as available, iteratively from file
*   return: initialized t_Table array, last element is an empty Table.
*           the number of extracted blocks in non NULL pointer *blocks
*******************************************************************************/
  t_Table *Table_Read_Array(char *File, long *blocks)
  {
    t_Table *Table_Array=NULL;
    long offset=0;
    long block_number=0;
    long allocated=256;
    long nelements=1;

    /* first allocate an initial empty t_Table array */
    Table_Array = (t_Table *)malloc(allocated*sizeof(t_Table));
    if (!Table_Array) {
      fprintf(stderr, "Error: Can not allocate memory %li (Table_Read_Array).\n",
         allocated*sizeof(t_Table));
      *blocks = 0;
      return (NULL);
    }

    while (nelements > 0)
    {
      t_Table Table;

      /* if ok, set t_Table block number else exit loop */
      block_number++;
      Table.block_number = block_number;
      
      /* access file at offset and get following block. Block number is from the set offset
       * hence the hardcoded 1 - i.e. the next block counted from offset.*/
      nelements = Table_Read_Offset(&Table, File, 1, &offset,0);
      /*if the block is empty - don't store it*/
      if (nelements>0){
          /* if t_Table array is not long enough, expand and realocate */
          if (block_number >= allocated-1) {
              allocated += 256;
              Table_Array = (t_Table *)realloc(Table_Array,
                      allocated*sizeof(t_Table));
              if (!Table_Array) {
                  fprintf(stderr, "Error: Can not re-allocate memory %li (Table_Read_Array).\n",
                          allocated*sizeof(t_Table));
                  *blocks = 0;
                  return (NULL);
              }
          }
          /* store it into t_Table array */
          //snprintf(Table.filename, 1024, "%s#%li", File, block_number-1);
          Table_Array[block_number-1] = Table;
      }
      /* continues until we find an empty block */
    }
    /* send back number of extracted blocks */
    if (blocks) *blocks = block_number-1;

    /* now store total number of elements in Table array */
    for (offset=0; offset < block_number;
      Table_Array[offset++].array_length = block_number-1);

    return(Table_Array);
  } /* end Table_Read_Array */
/*******************************************************************************
* void Table_Free_Array(t_Table *Table)
*   ACTION: free a Table array
*******************************************************************************/
  void Table_Free_Array(t_Table *Table)
  {
    long index;
    if (!Table) return;
    for (index=0;index < Table[0].array_length; index++){
            Table_Free(&Table[index]);
    }
    free(Table);
  } /* end Table_Free_Array */

/******************************************************************************
* long Table_Info_Array(t_Table *Table)
*    ACTION: print informations about a Table array
*    return: number of elements in the Table array
*******************************************************************************/
  long Table_Info_Array(t_Table *Table)
  {
    long index=0;

    if (!Table) return(-1);
    while (index < Table[index].array_length
       && (Table[index].data || Table[index].header)
       && (Table[index].rows*Table[index].columns) ) {
      Table_Info(Table[index]);
      index++;
    }
    printf("This Table array contains %li elements\n", index);
    return(index);
  } /* end Table_Info_Array */

/******************************************************************************
* char **Table_ParseHeader(char *header, symbol1, symbol2, ..., NULL)
*    ACTION: search for char* symbols in header and return their value or NULL
*            the search is not case sensitive.
*            Last argument MUST be NULL
*    return: array of char* with line following each symbol, or NULL if not found
*******************************************************************************/
#ifndef MyNL_ARGMAX
#define MyNL_ARGMAX 50
#endif

char **Table_ParseHeader_backend(char *header, ...){
  va_list ap;
  char exit_flag=0;
  int counter   =0;
  char **ret    =NULL;
  if (!header || header[0]=='\0') return(NULL);

  ret = (char**)calloc(MyNL_ARGMAX, sizeof(char*));
  if (!ret) {
    printf("Table_ParseHeader: Cannot allocate %i values array for Parser (Table_ParseHeader).\n",
      MyNL_ARGMAX);
    return(NULL);
  }
  for (counter=0; counter < MyNL_ARGMAX; ret[counter++] = NULL);
  counter=0;

  va_start(ap, header);
  while(!exit_flag && counter < MyNL_ARGMAX-1)
  {
    char *arg_char=NULL;
    char *pos     =NULL;
    /* get variable argument value as a char */
    arg_char = va_arg(ap, char *);
    if (!arg_char || arg_char[0]=='\0'){
      exit_flag = 1; break;
    }
    /* search for the symbol in the header */
    pos = (char*)strcasestr(header, arg_char);
    if (pos) {
      char *eol_pos;
      eol_pos = strchr(pos+strlen(arg_char), '\n');
      if (!eol_pos)
        eol_pos = strchr(pos+strlen(arg_char), '\r');
      if (!eol_pos)
        eol_pos = pos+strlen(pos)-1;
      ret[counter] = (char*)malloc(eol_pos - pos);
      if (!ret[counter]) {
        printf("Table_ParseHeader: Cannot allocate value[%i] array for Parser searching for %s (Table_ParseHeader).\n",
          counter, arg_char);
        exit_flag = 1; break;
      }
      strncpy(ret[counter], pos+strlen(arg_char), eol_pos - pos - strlen(arg_char));
      ret[counter][eol_pos - pos - strlen(arg_char)]='\0';
    }
    counter++;
  }
  va_end(ap);
  return(ret);
} /* Table_ParseHeader */

/******************************************************************************
* double Table_Interp1d(x, x1, y1, x2, y2)
*    ACTION: interpolates linearly at x between y1=f(x1) and y2=f(x2)
*    return: y=f(x) value
*******************************************************************************/
double Table_Interp1d(double x,
  double x1, double y1,
  double x2, double y2)
{
  double slope;
  if (x2 == x1) return (y1+y2)/2;
  if (y1 == y2) return  y1;
  slope = (y2 - y1)/(x2 - x1);
  return y1+slope*(x - x1);
} /* Table_Interp1d */

/******************************************************************************
* double Table_Interp1d_nearest(x, x1, y1, x2, y2)
*    ACTION: table lookup with nearest method at x between y1=f(x1) and y2=f(x2)
*    return: y=f(x) value
*******************************************************************************/
double Table_Interp1d_nearest(double x,
  double x1, double y1,
  double x2, double y2)
{
  if (fabs(x-x1) < fabs(x-x2)) return (y1);
  else return(y2);
} /* Table_Interp1d_nearest */

/******************************************************************************
* double Table_Interp2d(x,y, x1,y1, x2,y2, z11,z12,z21,z22)
*    ACTION: interpolates bi-linearly at (x,y) between z1=f(x1,y1) and z2=f(x2,y2)
*    return: z=f(x,y) value
*    x,y |   x1   x2
*    ----------------
*     y1 |   z11  z21
*     y2 |   z12  z22
*******************************************************************************/
double Table_Interp2d(double x, double y,
  double x1, double y1,
  double x2, double y2,
  double z11, double z12, double z21, double z22)
{
  double ratio_x, ratio_y;
  if (x2 == x1) return Table_Interp1d(y, y1,z11, y2,z12);
  if (y1 == y2) return Table_Interp1d(x, x1,z11, x2,z21);

  ratio_y = (y - y1)/(y2 - y1);
  ratio_x = (x - x1)/(x2 - x1);
  return (1-ratio_x)*(1-ratio_y)*z11 + ratio_x*(1-ratio_y)*z21
    + ratio_x*ratio_y*z22         + (1-ratio_x)*ratio_y*z12;
} /* Table_Interp2d */

/* end of read_table-lib.c */

/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2008, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/interoff.h
*
* %Identification
* Written by: Reynald Arnerin
* Date:    Jun 12, 2008
* Release:
* Version:
*
* Object File Format intersection header for McStas. Requires the qsort function.
*
* Such files may be obtained with e.g.
*   qhull < points.xyz Qx Qv Tv o > points.off
* where points.xyz has format:
*   3
*   <nb_points>
*   <x> <y> <z>
*   ...
* The resulting file should have its first line being changed from '3' into 'OFF'.
* It can then be displayed with geomview.
* A similar, but somewhat older solution is to use 'powercrust' with e.g.
*   powercrust -i points.xyz
* which will generate a 'pc.off' file to be renamed as suited.
*
*******************************************************************************/

#ifndef INTEROFF_LIB_H
#define INTEROFF_LIB_H "$Revision$"

#ifndef OFF_EPSILON
#define OFF_EPSILON 1e-13
#endif

#ifndef OFF_INTERSECT_MAX
#ifdef OPENACC
#define OFF_INTERSECT_MAX 100
#else
#define OFF_INTERSECT_MAX 1024
#endif
#endif

//#include <float.h>

#define N_VERTEX_DISPLAYED    200000

typedef struct intersection {
	MCNUM time;  	  //time of the intersection
	Coords v;	      //intersection point
	Coords normal;  //normal vector of the surface intersected
	short in_out;	  //1 if the ray enters the volume, -1 otherwise
	short edge;	    //1 if the intersection is on the boundary of the polygon, and error is possible
	unsigned long index; // index of the face
} intersection;

typedef struct polygon {
  MCNUM* p;       //vertices of the polygon in adjacent order, this way : x1 | y1 | z1 | x2 | y2 | z2 ...
  int npol;       //number of vertices
  #pragma acc shape(p[0:npol]) init_needed(npol)
  Coords normal;
  double D;
} polygon;

typedef struct off_struct {
    long vtxSize;
    long polySize;
    long faceSize;
    Coords* vtxArray;
    #pragma acc shape(vtxArray[0:vtxSize]) init_needed(vtxSize)
    Coords* normalArray;
    #pragma acc shape(vtxArray[0:faceSize]) init_needed(faceSize)
    unsigned long* faceArray;
    #pragma acc shape(vtxArray[0:faceSize][0:polySize]) init_needed(faceSize,polySize)
    double* DArray;
    #pragma acc shape(vtxArray[0:polySize]) init_needed(polySize)
    char *filename;
    int mantidflag;
    long mantidoffset;
    intersection intersects[OFF_INTERSECT_MAX]; // After a call to off_intersect_all contains the list of intersections.
    int nextintersect;                 // 'Next' intersection (first t>0) solution after call to off_intersect_all
    int numintersect;               // Number of intersections after call to off_intersect_all
} off_struct;

/*******************************************************************************
* long off_init(  char *offfile, double xwidth, double yheight, double zdepth, off_struct* data)
* ACTION: read an OFF file, optionally center object and rescale, initialize OFF data structure
* INPUT: 'offfile' OFF file to read
*        'xwidth,yheight,zdepth' if given as non-zero, apply bounding box.
*           Specifying only one of these will also use the same ratio on all axes
*        'notcenter' center the object to the (0,0,0) position in local frame when set to zero
* RETURN: number of polyhedra and 'data' OFF structure
*******************************************************************************/
long off_init(  char *offfile, double xwidth, double yheight, double zdepth,
                int notcenter, off_struct* data);

/*******************************************************************************
* int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         ax, ay, az are the local acceleration vector
*         data points to the OFF data structure
* RETURN: the number of polyhedra which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*         data is the full OFF structure, including a list intersection type
*******************************************************************************/
#pragma acc routine
int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data );

/*******************************************************************************
* int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         ax, ay, az are the local acceleration vector
*         data points to the OFF data structure
* RETURN: the number of polyhedra which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
#pragma acc routine
int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct data );

/*****************************************************************************
* int off_intersectx(double* l0, double* l3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double kx, double ky, double kz,
     off_struct data )
* ACTION: computes intersection of an xray trajectory with an object.
* INPUT:  x,y,z and kx,ky,kz, are spatial coordinates and wavevector of the x-ray
*         respectively. data points to the OFF data structure.
* RETURN: the number of polyhedra the trajectory intersects
*         l0 and l3 are the smallest incoming and outgoing intersection lengths
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
#pragma acc routine
int off_x_intersect(double *l0,double *l3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double kx, double ky, double kz,
     off_struct data );

/*******************************************************************************
* void off_display(off_struct data)
* ACTION: display up to N_VERTEX_DISPLAYED points from the object
*******************************************************************************/
void off_display(off_struct);

/*******************************************************************************
void p_to_quadratic(double eq[], Coords acc,
                    Coords pos, Coords vel,
                    double* teq)
* ACTION: define the quadratic for the intersection of a parabola with a plane
* INPUT: 'eq' plane equation
*        'acc' acceleration vector
*        'vel' velocity of the particle
*        'pos' position of the particle
*         equation of plane A * x + B * y + C * z - D = 0
*         eq[0] = (C*az)/2+(B*ay)/2+(A*ax)/2
*         eq[1] = C*vz+B*vy+A*vx
*         eq[2] = C*z0+B*y0+A*x0-D
* RETURN: equation of parabola: teq(0) * t^2 + teq(1) * t + teq(2)
*******************************************************************************/
void p_to_quadratic(Coords norm, MCNUM d, Coords acc, Coords pos, Coords vel,
		    double* teq);

/*******************************************************************************
int quadraticSolve(double eq[], double* x1, double* x2);
* ACTION: solves the quadratic for the roots x1 and x2 
*         eq[0] * t^2 + eq[1] * t + eq[2] = 0
* INPUT: 'eq' the coefficients of the parabola
* RETURN: roots x1 and x2 and the number of solutions
*******************************************************************************/
int quadraticSolve(double* eq, double* x1, double* x2);

#endif

/* end of interoff-lib.h */
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2008, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/interoff-lib.c
*
* %Identification
* Written by: Reynald Arnerin
* Date:    Jun 12, 2008
* Origin: ILL
* Release: $Revision$
* Version: McStas X.Y
*
* Object File Format intersection library for McStas. Requires the qsort function.
*
* Such files may be obtained with e.g.
*   qhull < points.xyz Qx Qv Tv o > points.off
* where points.xyz has format (it supports comments):
*   3
*   <nb_points>
*   <x> <y> <z>
*   ...
* The resulting file should have its first line being changed from '3' into 'OFF'.
* It can then be displayed with geomview.
* A similar, but somewhat older solution is to use 'powercrust' with e.g.
*   powercrust -i points.xyz
* which will generate a 'pc.off' file to be renamed as suited.
*
*******************************************************************************/

#ifndef INTEROFF_LIB_H
#include "interoff-lib.h"
#endif

#pragma acc routine
double off_F(double x, double y,double z,double A,double B,double C,double D) {
  return ( A*x + B*y + C*z + D );
}

#pragma acc routine
char off_sign(double a) {
  if (a<0)       return(-1);
  else if (a==0) return(0);
  else           return(1);
}

// off_normal ******************************************************************
//gives the normal vector of p
#pragma acc routine
void off_normal(Coords* n, polygon p)
{
  //using Newell method
  int i=0,j=0;
  n->x=0;n->y=0;n->z=0;
  for (i = 0, j = p.npol-1; i < p.npol; j = i++)
  {
    MCNUM x1=p.p[3*i],
          y1=p.p[3*i+1],
          z1=p.p[3*i+2];
    MCNUM x2=p.p[3*j],
          y2=p.p[3*j+1],
          z2=p.p[3*j+2];
    // n is the cross product of v1*v2
    n->x += (y1 - y2) * (z1 + z2);
    n->y += (z1 - z2) * (x1 + x2);
    n->z += (x1 - x2) * (y1 + y2);
  }
} /* off_normal */

// off_pnpoly ******************************************************************
//based on http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html
//return 0 if the vertex is out
//    1 if it is in
//   -1 if on the boundary
#pragma acc routine
int off_pnpoly(polygon p, Coords v)
{
  int i=0, c = 0;
  MCNUM minx=FLT_MAX,maxx=-FLT_MAX,miny=FLT_MAX,maxy=-FLT_MAX,minz=FLT_MAX,maxz=-FLT_MAX;
  MCNUM areax=0,areay=0,areaz=0;

  int pol2dx=0,pol2dy=1;          //2d restriction of the poly
  MCNUM x=v.x,y=v.y;

  /*areax: projected area with x-scratched = |v1_yz x v2_yz|, where v1=(x1-x0,0,z1-z0) & v2=(x2-x0,0,z2-z0).*/
  /* In principle, if polygon is triangle area should be scaled by 1/2, but this is irrelevant for finding the maximum area.*/
  /* Similarly for y and z scratched.*/
  areax=coords_len(coords_xp(
        coords_set(0,p.p[3*1+1]-p.p[0+1],p.p[3*1+2]-p.p[0+2]),
        coords_set(0,p.p[3*2+1]-p.p[0+1],p.p[3*2+2]-p.p[0+2])));
  areay=coords_len(coords_xp(
        coords_set(p.p[3*1+0]-p.p[0+0],0,p.p[3*1+2]-p.p[0+2]),
        coords_set(p.p[3*2+0]-p.p[0+0],0,p.p[3*2+2]-p.p[0+2])));
  areaz=coords_len(coords_xp(
        coords_set(p.p[3*1+0]-p.p[0+0],p.p[3*1+1]-p.p[0+1],0),
        coords_set(p.p[3*2+0]-p.p[0+0],p.p[3*2+1]-p.p[0+1],0)));

  if(areaz<areax){
    if(areax<areay){
      /*pick areay - i.e. scratch y*/
      pol2dy=2;
      y=v.z;
    }else{
      /*scratch x*/
      pol2dx=2;
      x=v.z;
    }
  }else if (areaz<areay){
    pol2dy=2;
    y=v.z;
  }

  //trace rays and test number of intersection
  int j;
  for (i = 0, j = p.npol-1; i < p.npol; j = i++) {
    if (((((p.p[3*i+pol2dy])<=y) && (y<(p.p[3*j+pol2dy]))) ||
         (((p.p[3*j+pol2dy])<=y) && (y<(p.p[3*i+pol2dy])))) &&
        (x < ( (p.p[3*j+pol2dx] - p.p[3*i+pol2dx]) * (y - p.p[3*i+pol2dy])
             / (p.p[3*j+pol2dy] - p.p[3*i+pol2dy]) + p.p[3*i+pol2dx]) ))
      c = !c;

    if (((fabs(p.p[3*i+pol2dy]-y)<=OFF_EPSILON) || ((fabs(p.p[3*j+pol2dy]-y)<=OFF_EPSILON))) &&
        fabs(x -((p.p[3*j+pol2dx] - p.p[3*i+pol2dx]) * (y - p.p[3*i+pol2dy])
          / (p.p[3*j+pol2dy] - p.p[3*i+pol2dy]) + p.p[3*i+pol2dx])) < OFF_EPSILON)
    {
      //the point lies on the edge
      c=-1;
      break;
    }
  }

  return c;
} /* off_pnpoly */

// off_intersectPoly ***********************************************************
//gives the intersection vertex between ray [a,b) and polygon p and its parametric value on (a b)
//based on http://geometryalgorithms.com/Archive/algorithm_0105/algorithm_0105.htm
#pragma acc routine
int off_intersectPoly(intersection *inter, Coords a, Coords b, polygon p)
{
  //direction vector of [a,b]
  Coords dir = {b.x-a.x, b.y-a.y, b.z-a.z};

  //the normal vector to the polygon
  Coords normale=p.normal;
  //off_normal(&normale, p); done at the init stage

  //direction vector from a to a vertex of the polygon
  Coords w0 = {a.x-p.p[0], a.y-p.p[1], a.z-p.p[2]};

  //scalar product
  MCNUM nw0  =-scalar_prod(normale.x,normale.y,normale.z,w0.x,w0.y,w0.z);
  MCNUM ndir = scalar_prod(normale.x,normale.y,normale.z,dir.x,dir.y,dir.z);
  inter->time = inter->edge = inter->in_out=0;
  inter->v = inter->normal = coords_set(0,0,1);

  if (fabs(ndir) < OFF_EPSILON)    // ray is parallel to polygon plane
  {
    if (nw0 == 0)              // ray lies in polygon plane (infinite number of solution)
      return 0;
    else return 0;             // ray disjoint from plane (no solution)
  }

  // get intersect point of ray with polygon plane
  inter->time = nw0 / ndir;            //parametric value the point on line (a,b)

  inter->v = coords_set(a.x + inter->time * dir.x,// intersect point of ray and plane
    a.y + inter->time * dir.y,
    a.z + inter->time * dir.z);

  int res=off_pnpoly(p,inter->v);

  inter->edge=(res==-1);
  if (ndir<0)
    inter->in_out=1;  //the negative dot product means we enter the surface
  else
    inter->in_out=-1;

  inter->normal=p.normal;

  return res;         //true if the intersection point lies inside the poly
} /* off_intersectPoly */


// off_getBlocksIndex **********************************************************
/*reads the indexes at the beginning of the off file as this :
line 1  OFF
line 2  nbVertex nbFaces nbEdges
*/
FILE *off_getBlocksIndex(char* filename, long* vtxSize, long* polySize )
{
  FILE* f = Open_File(filename,"r", NULL); /* from read_table-lib: FILE *Open_File(char *name, char *Mode, char *path) */
  if (!f) return (f);

  char line[CHAR_BUF_LENGTH];
  char *ret=0;
  *vtxSize = *polySize = 0;

  /* **************** start to read the file header */
  /* OFF file:
     'OFF' or '3'
   */

  ret=fgets(line,CHAR_BUF_LENGTH , f);// line 1 = "OFF"
  if (ret == NULL)
  {
    fprintf(stderr, "Error: Can not read 1st line in file %s (interoff/off_getBlocksIndex)\n", filename);
    exit(1);
  }
  if (strlen(line)>5)
  {
      fprintf(stderr,"Error: First line in %s is too long (=%lu). Possibly the line is not terminated by '\\n'.\n"
              "       The first line is required to be exactly 'OFF', '3' or 'ply'.\n",
              filename,(long unsigned)strlen(line));
      fclose(f);
      return(NULL);
  }

  if (strncmp(line,"OFF",3) && strncmp(line,"3",1) && strncmp(line,"ply",1))
  {
    fprintf(stderr, "Error: %s is probably not an OFF, NOFF or PLY file (interoff/off_getBlocksIndex).\n"
                    "       Requires first line to be 'OFF', '3' or 'ply'.\n",filename);
    fclose(f);
    return(NULL);
  }

  if (!strncmp(line,"OFF",3) || !strncmp(line,"3",1)) {
    do  /* OFF file: skip # comments which may be there */
    {
      ret=fgets(line,CHAR_BUF_LENGTH , f);
      if (ret == NULL)
      {
        fprintf(stderr, "Error: Can not read line in file %s (interoff/off_getBlocksIndex)\n", filename);
        exit(1);
      }
    } while (line[0]=='#');
    //line = nblines of vertex,faces and edges arrays
    sscanf(line,"%lu %lu",vtxSize,polySize);
  } else {
    do  /* PLY file: read all lines until find 'end_header'
           and locate 'element faces' and 'element vertex' */
    {
      ret=fgets(line,CHAR_BUF_LENGTH , f);
      if (ret == NULL)
      {
        fprintf(stderr, "Error: Can not read line in file %s (interoff/off_getBlocksIndex)\n", filename);
        exit(1);
      }
      if (!strncmp(line,"element face",12))
        sscanf(line,"element face %lu",polySize);
      else if (!strncmp(line,"element vertex",14))
        sscanf(line,"element vertex %lu",vtxSize);
      else if (!strncmp(line,"format binary",13))
        exit(fprintf(stderr,
          "Error: Can not read binary PLY file %s, only 'format ascii' (interoff/off_getBlocksIndex)\n%s\n",
          filename, line));
    } while (strncmp(line,"end_header",10));
  }

  /* The FILE is left opened ready to read 'vtxSize' vertices (vtxSize *3 numbers)
     and then polySize polygons (rows) */

  return(f);
} /* off_getBlocksIndex */

// off_init_planes *************************************************************
//gives the equations of 2 perpandicular planes of [ab]
#pragma acc routine
void off_init_planes(Coords a, Coords b,
  MCNUM* A1, MCNUM* C1, MCNUM* D1, MCNUM *A2, MCNUM* B2, MCNUM* C2, MCNUM* D2)
{
  //direction vector of [a b]
  Coords dir={b.x-a.x, b.y-a.y, b.z-a.z};

  //the plane parallel to the 'y' is computed with the normal vector of the projection of [ab] on plane 'xz'
  *A1= dir.z;
  *C1=-dir.x;
  if(*A1!=0 || *C1!=0)
    *D1=-(a.x)*(*A1)-(a.z)*(*C1);
  else
  {
    //the plane does not support the vector, take the one parallel to 'z''
    *A1=1;
    //B1=dir.x=0
    *D1=-(a.x);
  }
  //the plane parallel to the 'x' is computed with the normal vector of the projection of [ab] on plane 'yz'
  *B2= dir.z;
  *C2=-dir.y;
  *A2= 0;
  if (*B2==0 && *C2==0)
  {
    //the plane does not support the vector, take the one parallel to 'z'
    *B2=1;
    //B1=dir.x=0
    *D2=-(a.y);
  }
  else {
    if (dir.z==0)
    {
      //the planes are the same, take the one parallel to 'z'
      *A2= dir.y;
      *B2=-dir.x;
      *D2=-(a.x)*(*A2)-(a.y)*(*B2);
    }
    else
      *D2=-(a.y)**B2-(a.z)**C2;
  }
} /* off_init_planes */

// off_clip_3D_mod *************************************************************
#pragma acc routine
int off_clip_3D_mod(intersection* t, Coords a, Coords b,
  Coords* vtxArray, unsigned long vtxSize, unsigned long* faceArray,
  unsigned long faceSize, Coords* normalArray)
{
  MCNUM A1=0, C1=0, D1=0, A2=0, B2=0, C2=0, D2=0;      //perpendicular plane equations to [a,b]
  off_init_planes(a, b, &A1, &C1, &D1, &A2, &B2, &C2, &D2);

  int t_size=0;
  MCNUM popol[3*4]; /*3 dimensions and max 4 vertices to form a polygon*/
  unsigned long i=0,indPoly=0;

  //exploring the polygons :
  i=indPoly=0;
  while (i<faceSize)
  {
    polygon pol;
    pol.npol  = faceArray[i];                //nb vertex of polygon
    pol.p     = popol;
    pol.normal= coords_set(0,0,1);
    unsigned long indVertP1=faceArray[++i];  //polygon's first vertex index in vtxTable
    int j=1;
    /*check whether vertex is left or right of plane*/
    char sg0=off_sign(off_F(vtxArray[indVertP1].x,vtxArray[indVertP1].y,vtxArray[indVertP1].z,A1,0,C1,D1));
    while (j<pol.npol)
    {
      //polygon's j-th vertex index in vtxTable
      unsigned long indVertP2=faceArray[i+j];
      /*check whether vertex is left or right of plane*/
      char sg1=off_sign(off_F(vtxArray[indVertP2].x,vtxArray[indVertP2].y,vtxArray[indVertP2].z,A1,0,C1,D1));
      if (sg0!=sg1) //if the plane intersect the polygon
        break;

      ++j;
    }

    if (j<pol.npol)          //ok, let's test with the second plane
    {
      char sg1=off_sign(off_F(vtxArray[indVertP1].x,vtxArray[indVertP1].y,vtxArray[indVertP1].z,A2,B2,C2,D2));//tells if vertex is left or right of the plane

      j=1;
      while (j<pol.npol)
      {
        //unsigned long indVertPi=faceArray[i+j];  //polyg's j-th vertex index in vtxTable
        Coords vertPi=vtxArray[faceArray[i+j]];
        if (sg1!=off_sign(off_F(vertPi.x,vertPi.y,vertPi.z,A2,B2,C2,D2)))//if the plane intersect the polygon
          break;
        ++j;
      }
      if (j<pol.npol)
      {
#ifdef OFF_LEGACY
        if (t_size>OFF_INTERSECT_MAX)
        {
#ifndef OPENACC
          fprintf(stderr, "Warning: number of intersection exceeded (%d) (interoff-lib/off_clip_3D_mod)\n", OFF_INTERSECT_MAX);
#endif
            return (t_size);
        }
#endif
        //both planes intersect the polygon, let's find the intersection point
        //our polygon :
        int k;
        for (k=0; k<pol.npol; ++k)
        {
          Coords vertPk=vtxArray[faceArray[i+k]];
          pol.p[3*k]  =vertPk.x;
          pol.p[3*k+1]=vertPk.y;
          pol.p[3*k+2]=vertPk.z;
        }
        pol.normal=normalArray[indPoly];
        intersection x;
        if (off_intersectPoly(&x, a, b, pol))
        {
          x.index = indPoly;
#ifdef OFF_LEGACY
          t[t_size++]=x;
#else
	  /* Check against our 4 existing times, starting from [-FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX] */
	  /* Case 1, negative time? */
	  if (t_size < 4) t_size++;	  
	  if (x.time < 0) {
	    if (x.time > t[0].time) {
	      t[0]=x;
	    }
	  } else {
	    /* Case 2, positive time */
	    intersection xtmp;
	    if (x.time < t[3].time) {
	      t[3]=x;
	      if (t[3].time < t[2].time) {
		xtmp = t[2];
		t[2] = t[3];
		t[3] = xtmp;
	      }
	      if (t[2].time < t[1].time) {
		xtmp = t[1];
		t[1] = t[2];
		t[2] = xtmp;
	      }
	    } 
	  }
#endif
	}
      } /* if (j<pol.npol) */
    } /* if (j<pol.npol) */
    i += pol.npol;
    indPoly++;
  } /* while i<faceSize */
  return t_size;
} /* off_clip_3D_mod */

// off_clip_3D_mod_grav *************************************************************
/*******************************************************************************
version of off_clip_3D_mod_grav
*******************************************************************************/
#pragma acc routine seq
int off_clip_3D_mod_grav(intersection* t, Coords pos, Coords vel, Coords acc,
  Coords* vtxArray, unsigned long vtxSize, unsigned long* faceArray,
  unsigned long faceSize, Coords* normalArray, double* DArray)
{
  int t_size=0;
  MCNUM popol[3*CHAR_BUF_LENGTH];
  double plane_Eq [4];
  double quadratic [3];
  unsigned long i=0,indPoly=0;
  //exploring the polygons :
  i=indPoly=0;
  while (i<faceSize)
  {
    polygon pol;
    pol.npol  = faceArray[i];                //nb vertex of polygon
    pol.p     = popol;
    pol.normal= coords_set(0,0,1);
    unsigned long indVertP1=faceArray[++i];  //polygon's first vertex index in vtxTable
    
    if (t_size>CHAR_BUF_LENGTH)
      {
#ifndef OPENACC
	fprintf(stderr, "Warning: number of intersection exceeded (%d) (interoff-lib/off_clip_3D_mod)\n", CHAR_BUF_LENGTH);
#endif
	return (t_size);
      }
    //both planes intersect the polygon, let's find the intersection point
    //our polygon :
    int k;
    for (k=0; k<pol.npol; ++k)
      {
	Coords vertPk=vtxArray[faceArray[i+k]];
	pol.p[3*k]  =vertPk.x;
	pol.p[3*k+1]=vertPk.y;
	pol.p[3*k+2]=vertPk.z;
      }
    pol.normal=normalArray[indPoly];
    pol.D=DArray[indPoly];
    p_to_quadratic(pol.normal, pol.D, acc, pos, vel, quadratic);
    double x1, x2;
    int nsol = quadraticSolve(quadratic, &x1, &x2);

    if (nsol >= 1) {
      double time = 1.0e36;
      if (x1 < time && x1 > 0.0) {
	time = x1;
      }
      if (nsol == 2 && x2 < time && x2 > 0.0) {
	time = x2;
      }
      if (time != 1.0e36) {
	intersection inters;
	double t2 = time * time * 0.5;
	double tx = pos.x + time * vel.x;
	if (acc.x != 0.0) {
	  tx = tx + t2 * acc.x;
	}
	double ty = pos.y + time * vel.y;
	if (acc.y != 0.0) {
	  ty = ty + t2 * acc.y;
	}
	double tz = pos.z + time * vel.z;
	if (acc.z != 0.0) {
	  tz = tz + t2 * acc.z;
	}
	inters.v = coords_set(tx, ty, tz);
	Coords tvel = coords_set(vel.x + time * acc.x,
				 vel.y + time * acc.y,
				 vel.z + time * acc.z);
	inters.time = time;
	inters.normal = pol.normal;
	inters.index = indPoly;
	int res=off_pnpoly(pol,inters.v);
	if (res != 0) {
	  inters.edge=(res==-1);
	  MCNUM ndir = scalar_prod(pol.normal.x,pol.normal.y,pol.normal.z,tvel.x,tvel.y,tvel.z);
	  if (ndir<0) {
	    inters.in_out=1;  //the negative dot product means we enter the surface
	  } else {
	    inters.in_out=-1;
	  }
#ifdef OFF_LEGACY
          t[t_size++]=inters;
#else
    /* Check against our 4 existing times, starting from [-FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX] */
    /* Case 1, negative time? */
    if (t_size < 4) t_size++;
    if (inters.time < 0) {
      if (inters.time > t[0].time) {
        t[0]=inters;
      }
    } else {
      /* Case 2, positive time */
      intersection xtmp;
      if (inters.time < t[3].time) {
      t[3]=inters;
        if (t[3].time < t[2].time) {
    xtmp = t[2];
    t[2] = t[3];
    t[3] = xtmp;
        }
        if (t[2].time < t[1].time) {
    xtmp = t[1];
    t[1] = t[2];
    t[2] = xtmp;
        }
      }
    }
#endif
	}
      }
    }
    i += pol.npol;
    indPoly++;
  } /* while i<faceSize */
  return t_size;
} /* off_clip_3D_mod_grav */

// off_compare *****************************************************************
#pragma acc routine
int off_compare (void const *a, void const *b)
{
   intersection const *pa = a;
   intersection const *pb = b;

   return off_sign(pa->time - pb->time);
} /* off_compare */

// off_cleanDouble *************************************************************
//given an array of intersections throw those which appear several times
//returns 1 if there is a possibility of error
#pragma acc routine
int off_cleanDouble(intersection* t, int* t_size)
{
  int i=1;
  intersection prev=t[0];
  while (i<*t_size)
  {
    int j=i;
    //for each intersection with the same time
    while (j<*t_size && fabs(prev.time-t[j].time)<OFF_EPSILON)
    {
      //if the intersection is the exact same erase it
      if (prev.in_out==t[j].in_out)
      {
        int k;
        for (k=j+1; k<*t_size; ++k)
        {
          t[k-1]=t[k];
        }
        *t_size-=1;
      }
      else
        ++j;
    }
    prev=t[i];
    ++i;

  }
  return 1;
} /* off_cleanDouble */

// off_cleanInOut **************************************************************
//given an array of intesections throw those which enter and exit in the same time
//Meaning the ray passes very close to the volume
//returns 1 if there is a possibility of error
#pragma acc routine
int off_cleanInOut(intersection* t, int* t_size)
{
  int i=1;
  intersection prev=t[0];
  while (i<*t_size)
  {
    //if two intersection have the same time but one enters and the other exits erase both
    //(such intersections must be adjacent in the array : run off_cleanDouble before)
    if (fabs(prev.time-t[i].time)<OFF_EPSILON && prev.in_out!=t[i].in_out)
    {
      int j=0;
      for (j=i+1; j<*t_size; ++j)
      {
        t[j-2]=t[j];
      }
      *t_size-=2;
      prev=t[i-1];
    }
    else
    {
      prev=t[i];
      ++i;
    }
  }
  return (*t_size);
} /* off_cleanInOut */

/* PUBLIC functions ******************************************************** */

/*******************************************************************************
* long off_init(  char *offfile, double xwidth, double yheight, double zdepth, off_struct* data)
* ACTION: read an OFF file, optionally center object and rescale, initialize OFF data structure
* INPUT: 'offfile' OFF file to read
*        'xwidth,yheight,zdepth' if given as non-zero, apply bounding box.
*           Specifying only one of these will also use the same ratio on all axes
*        'notcenter' center the object to the (0,0,0) position in local frame when set to zero
* RETURN: number of polyhedra and 'data' OFF structure
*******************************************************************************/
long off_init(  char *offfile, double xwidth, double yheight, double zdepth,
                int notcenter, off_struct* data)
{
  // data to be initialized
  long    vtxSize =0, polySize=0, i=0, ret=0, faceSize=0;
  Coords* vtxArray        =NULL;
  Coords* normalArray     =NULL;
  double* DArray          =NULL;
  unsigned long* faceArray=NULL;
  FILE*   f               =NULL; /* the FILE with vertices and polygons */
  double minx=FLT_MAX,maxx=-FLT_MAX,miny=FLT_MAX,maxy=-FLT_MAX,minz=FLT_MAX,maxz=-FLT_MAX;

  // get the indexes
  if (!data) return(0);

  MPI_MASTER(
  printf("Loading geometry file (OFF/PLY): %s\n", offfile);
  );

  f=off_getBlocksIndex(offfile,&vtxSize,&polySize);
  if (!f) return(0);

  // read vertex table = [x y z | x y z | ...] =================================
  // now we read the vertices as 'vtxSize*3' numbers and store it in vtxArray
  MPI_MASTER(
  printf("  Number of vertices: %ld\n", vtxSize);
  );
  vtxArray   = malloc(vtxSize*sizeof(Coords));
  if (!vtxArray) return(0);
  i=0;
  while (i<vtxSize && ~feof(f))
  {
    double x,y,z;
    ret=fscanf(f, "%lg%lg%lg", &x,&y,&z);
    if (!ret) {
      // invalid line: we skip it (probably a comment)
      char line[CHAR_BUF_LENGTH];
      char *s=fgets(line, CHAR_BUF_LENGTH, f);
      continue;
    }
    if (ret != 3) {
      fprintf(stderr, "Error: can not read [xyz] coordinates for vertex %li in file %s (interoff/off_init). Read %li values.\n",
        i, offfile, ret);
      exit(2);
    }
    vtxArray[i].x=x;
    vtxArray[i].y=y;
    vtxArray[i].z=z;

    //bounding box
    if (vtxArray[i].x<minx) minx=vtxArray[i].x;
    if (vtxArray[i].x>maxx) maxx=vtxArray[i].x;
    if (vtxArray[i].y<miny) miny=vtxArray[i].y;
    if (vtxArray[i].y>maxy) maxy=vtxArray[i].y;
    if (vtxArray[i].z<minz) minz=vtxArray[i].z;
    if (vtxArray[i].z>maxz) maxz=vtxArray[i].z;
    i++; // inquire next vertex
  }

  // resizing and repositioning params
  double centerx=0, centery=0, centerz=0;
  if (!notcenter) {
    centerx=(minx+maxx)*0.5;
    centery=(miny+maxy)*0.5;
    centerz=(minz+maxz)*0.5;
  }

  double rangex=-minx+maxx,
         rangey=-miny+maxy,
         rangez=-minz+maxz;

  double ratiox=1,ratioy=1,ratioz=1;

  if (xwidth && rangex)
  {
    ratiox=xwidth/rangex;
    ratioy=ratiox;
    ratioz=ratiox;
  }

  if (yheight && rangey)
  {
    ratioy=yheight/rangey;
    if(!xwidth)  ratiox=ratioy;
    ratioz=ratioy;
  }

  if (zdepth && rangez)
  {
    ratioz=zdepth/rangez;
    if(!xwidth)  ratiox=ratioz;
    if(!yheight) ratioy=ratioz;
  }

  rangex *= ratiox;
  rangey *= ratioy;
  rangez *= ratioz;

  //center and resize the object
  for (i=0; i<vtxSize; ++i)
  {
    vtxArray[i].x=(vtxArray[i].x-centerx)*ratiox+(!notcenter ? 0 : centerx);
    vtxArray[i].y=(vtxArray[i].y-centery)*ratioy+(!notcenter ? 0 : centery);
    vtxArray[i].z=(vtxArray[i].z-centerz)*ratioz+(!notcenter ? 0 : centerz);
  }

  // read face table = [nbvertex v1 v2 vn | nbvertex v1 v2 vn ...] =============
  MPI_MASTER(
  printf("  Number of polygons: %ld\n", polySize);
  );
  normalArray= malloc(polySize*sizeof(Coords));
  faceArray  = malloc(polySize*10*sizeof(unsigned long)); // we assume polygons have less than 9 vertices
  DArray     = malloc(polySize*sizeof(double));
  if (!normalArray || !faceArray || !DArray) return(0);

  // fill faces
  faceSize=0;
  i=0;
  while (i<polySize && ~feof(f)) {
    int  nbVertex=0, j=0;
    // read the length of this polygon
    ret=fscanf(f, "%d", &nbVertex);
    if (!ret) {
      // invalid line: we skip it (probably a comment)
      char line[CHAR_BUF_LENGTH];
      char *s=fgets(line, CHAR_BUF_LENGTH, f);
      continue;
    }
    if (ret != 1) {
      fprintf(stderr, "Error: can not read polygon %li length in file %s (interoff/off_init)\n",
        i, offfile);
      exit(3);
    }
    if (faceSize > polySize*10) {
      fprintf(stderr, "Error: %li exceeded allocated polygon array[%li] in file %s (interoff/off_init)\n",
        faceSize, polySize*10, offfile);
    }
    faceArray[faceSize++] = nbVertex; // length of the polygon/face
    // then read the vertex ID's
    for (j=0; j<nbVertex; j++) {
      double vtx=0;
      ret=fscanf(f, "%lg", &vtx);
      faceArray[faceSize++] = vtx;   // add vertices index after length of polygon
    }
    i++;
  }

  // precomputes normals
  long indNormal=0;//index in polyArray
  i=0;    //index in faceArray
  while (i<faceSize)
  {
    int    nbVertex=faceArray[i];//nb of vertices of this polygon
    double *vertices=malloc(3*nbVertex*sizeof(double));
    int j;

    for (j=0; j<nbVertex; ++j)
    {
      unsigned long indVertPj=faceArray[i+j+1];
      vertices[3*j]  =vtxArray[indVertPj].x;
      vertices[3*j+1]=vtxArray[indVertPj].y;
      vertices[3*j+2]=vtxArray[indVertPj].z;
    }

    polygon p;
    p.p   =vertices;
    p.npol=nbVertex;
    off_normal(&(p.normal),p);

    normalArray[indNormal]=p.normal;
    p.D = scalar_prod(p.normal.x,p.normal.y,p.normal.z,
		      vertices[0],vertices[1],vertices[2]);
    DArray[indNormal]=p.D;

    i += nbVertex+1;
    indNormal++;
    free(vertices);
  }

  MPI_MASTER(
  if (ratiox!=ratioy || ratiox!=ratioz || ratioy!=ratioz)
    printf("Warning: Aspect ratio of the geometry %s was modified.\n"
           "         If you want to keep the original proportions, specifiy only one of the dimensions.\n",
           offfile);
  if ( xwidth==0 && yheight==0 && zdepth==0 ) {
    printf("Warning: Neither xwidth, yheight or zdepth are defined.\n"
	   "           The file-defined (non-scaled) geometry the OFF geometry %s will be applied!\n",
           offfile);
  }
  printf("  Bounding box dimensions for geometry %s:\n", offfile);
  printf("    Length=%f (%.3f%%)\n", rangex, ratiox*100);
  printf("    Width= %f (%.3f%%)\n", rangey, ratioy*100);
  printf("    Depth= %f (%.3f%%)\n", rangez, ratioz*100);
  );

  data->vtxArray   = vtxArray;
  data->normalArray= normalArray;
  data->DArray     = DArray;
  data->faceArray  = faceArray;
  data->vtxSize    = vtxSize;
  data->polySize   = polySize;
  data->faceSize   = faceSize;
  data->filename   = offfile;
  #ifdef OPENACC
  acc_attach((void *)&vtxArray);
  acc_attach((void *)&normalArray);
  acc_attach((void *)&faceArray);
  #endif

  return(polySize);
} /* off_init */

#pragma acc routine
int Min_int(int x, int y) {
  return (x<y)? x :y;
}

 
#pragma acc routine
void merge(intersection *arr, int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 =  r - m;

/* create temp arrays */
intersection *L, *R;
 L = (intersection *)malloc(sizeof(intersection) * n1);
 R = (intersection *)malloc(sizeof(intersection) * n2);
/* Copy data to temp arrays L[] and R[] */
 #pragma acc loop independent
for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
 #pragma acc loop independent
for (j = 0; j < n2; j++)
    R[j] = arr[m + 1+ j];

/* Merge the temp arrays back into arr[l..r]*/
i = 0;
j = 0;
k = l;

while (i < n1 && j < n2)
{
    if (L[i].time <= R[j].time)
    {
        arr[k] = L[i];
        i++;
    }
    else
    {
        arr[k] = R[j];
        j++;
    }
    k++;
}

/* Copy the remaining elements of L[], if there are any */

while (i < n1)
{
    arr[k] = L[i];
    i++;
    k++;
}

/* Copy the remaining elements of R[], if there are any */
while (j < n2)
{
    arr[k] = R[j];
    j++;
    k++;
}
free(L);
free(R);
}


#ifdef USE_OFF
#pragma acc routine
void gpusort(intersection *arr, int size)
{
  int curr_size;  // For current size of subarrays to be merged
  // curr_size varies from 1 to n/2
  int left_start; // For picking starting index of left subarray
  // to be merged
  // pcopying (R[0:n2])
  {
    for (curr_size=1; curr_size<=size-1; curr_size = 2*curr_size)
      {
	// Pick starting point of different subarrays of current size
	for (left_start=0; left_start<size-1; left_start += 2*curr_size)
	  {
	    // Find ending point of left subarray. mid+1 is starting
	    // point of right
	    int mid = left_start + curr_size - 1;

	    int right_end = Min_int(left_start + 2*curr_size - 1, size-1);

	    // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
	    if (mid < right_end) merge(arr, left_start, mid, right_end);
	  }
      }
  }
}
#endif

/*******************************************************************************
void p_to_quadratic(double eq[], Coords acc,
                    Coords pos, Coords vel,
                    double* teq)
* ACTION: define the quadratic for the intersection of a parabola with a plane
* INPUT: 'eq' plane equation
*        'acc' acceleration vector
*        'vel' velocity of the particle
*        'pos' position of the particle
*         equation of plane A * x + B * y + C * z - D = 0
*         eq[0] = (C*az)/2+(B*ay)/2+(A*ax)/2
*         eq[1] = C*vz+B*vy+A*vx
*         eq[2] = C*z0+B*y0+A*x0-D
* RETURN: equation of parabola: teq(0) * t^2 + teq(1) * t + teq(2)
*******************************************************************************/
void p_to_quadratic(Coords norm, MCNUM d, Coords acc, Coords pos, Coords vel,
		    double* teq)
{
  teq[0] = scalar_prod(norm.x, norm.y, norm.z, acc.x, acc.y, acc.z) * 0.5;
  teq[1] = scalar_prod(norm.x, norm.y, norm.z, vel.x, vel.y, vel.z);
  teq[2] = scalar_prod(norm.x, norm.y, norm.z, pos.x, pos.y, pos.z) - d;
  return;
}

/*******************************************************************************
int quadraticSolve(double eq[], double* x1, double* x2);
* ACTION: solves the quadratic for the roots x1 and x2 
*         eq[0] * t^2 + eq[1] * t + eq[2] = 0
* INPUT: 'eq' the coefficients of the parabola
* RETURN: roots x1 and x2 and the number of solutions
*******************************************************************************/
int quadraticSolve(double* eq, double* x1, double* x2)
{
  if (eq[0] == 0.0) { // This is a linear equation
    if (eq[1] != 0.0) { // one solution
      *x1 = -eq[2]/eq[1];
      *x2 = 1.0e36;
      return 1;
    }else { // no solutions, 1.0e36 will be ignored.
      *x1 = 1.0e36;
      *x2 = 1.0e36;
      return 0;
    }
  }
  double delta = eq[1]*eq[1]-4.0*eq[0]*eq[2];
  if (delta < 0.0) { // no solutions, both are imaginary
    *x1 = 1.0e36;
    *x2 = 1.0e36;
    return 0;
  }
  double s = 1.0;
  if (eq[1] < 0) {
    s = -1.0;
  }
  *x1 = (-eq[1] - s * sqrt(delta))/(2.0*eq[0]);
  if (eq[0] != 0.0) { //two solutions
    *x2 = eq[2]/(eq[0]*(*x1));
    return 2;
  } else { //one solution
    *x2 = 1.0e36;
    return 1;
  }
}

/*******************************************************************************
* int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         ax, ay, az are the local acceleration vector
*         data points to the OFF data structure
* RETURN: the number of polyhedra which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*         data is the full OFF structure, including a list intersection type
*******************************************************************************/
int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data )
{

    int t_size = 0;
#ifdef OFF_LEGACY

    if(mcgravitation) {
      Coords pos={ x,  y,  z};
      Coords vel={vx, vy, vz};
      Coords acc={ax, ay, az};
      t_size=off_clip_3D_mod_grav(data->intersects, pos, vel, acc,
				  data->vtxArray, data->vtxSize, data->faceArray,
				  data->faceSize, data->normalArray, data->DArray );
    } else {
    ///////////////////////////////////
    // non-grav
      Coords A={x, y, z};
      Coords B={x+vx, y+vy, z+vz};
      t_size=off_clip_3D_mod(data->intersects, A, B,
			     data->vtxArray, data->vtxSize, data->faceArray,
			     data->faceSize, data->normalArray );
    }
    #ifndef OPENACC
    qsort(data->intersects, t_size, sizeof(intersection),  off_compare);
    #else
    #ifdef USE_OFF
    gpusort(data->intersects, t_size);
    #endif
    #endif
    off_cleanDouble(data->intersects, &t_size);
    off_cleanInOut(data->intersects,  &t_size);

    /*find intersections "closest" to 0 (favouring positive ones)*/
    if(t_size>0){
      int i=0;
      if(t_size>1) {
        for (i=1; i < t_size-1; i++){
          if (data->intersects[i-1].time > 0 && data->intersects[i].time > 0)
            break;
        }

	data->nextintersect=i-1;
	data->numintersect=t_size;

        if (t0) *t0 = data->intersects[i-1].time;
        if (n0) *n0 = data->intersects[i-1].normal;
        if (t3) *t3 = data->intersects[i].time;
        if (n3) *n3 = data->intersects[i].normal;
      } else {
        if (t0) *t0 = data->intersects[0].time;
	      if (n0) *n0 = data->intersects[0].normal;
      }
      /* should also return t[0].index and t[i].index as polygon ID */
      data->nextintersect=(data->intersects[data->nextintersect]).index;
      return t_size;
    }
#else
    intersection intersect4[4];
    intersect4[0].time=-FLT_MAX;
    intersect4[1].time=FLT_MAX;
    intersect4[2].time=FLT_MAX;
    intersect4[3].time=FLT_MAX;
    if(mcgravitation) {
      Coords pos={ x,  y,  z};
      Coords vel={vx, vy, vz};
      Coords acc={ax, ay, az};
      t_size=off_clip_3D_mod_grav(intersect4, pos, vel, acc,
				  data->vtxArray, data->vtxSize, data->faceArray,
				  data->faceSize, data->normalArray, data->DArray);
    } else {
    ///////////////////////////////////
    // non-grav
      Coords A={x, y, z};
      Coords B={x+vx, y+vy, z+vz};
      t_size=off_clip_3D_mod(intersect4, A, B,
	  data->vtxArray, data->vtxSize, data->faceArray, data->faceSize, data->normalArray );
    }
    if(t_size>0){
      int i=0;
      if (intersect4[0].time == -FLT_MAX) i=1;
      data->numintersect=t_size;
      if (t0) *t0 = intersect4[i].time;
      if (n0) *n0 = intersect4[i].normal;
      if (t3) *t3 = intersect4[i+1].time;
      if (n3) *n3 = intersect4[i+1].normal;

      if (intersect4[1].time == FLT_MAX)
      {
        if (t3) *t3 = 0.0;
      }

      /* should also return t[0].index and t[i].index as polygon ID */
      data->nextintersect=(int)intersect4[i].index;
      return t_size;
    }
#endif
    return 0;
} /* off_intersect */

/*******************************************************************************
* int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     off_struct data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         data points to the OFF data structure
* RETURN: the number of polyhedra which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct data )
{
  return off_intersect_all(t0, t3, n0, n3, x, y, z, vx, vy, vz, ax, ay, az, &data );
} /* off_intersect */

/*****************************************************************************
* int off_x_intersect(double* l0, double* l3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double kx, double ky, double kz,
     off_struct data )
* ACTION: computes intersection of an xray trajectory with an object.
* INPUT:  x,y,z and kx,ky,kz, are spatial coordinates and wavevector of the x-ray
*         respectively. data points to the OFF data structure.
* RETURN: the number of polyhedra the trajectory intersects
*         l0 and l3 are the smallest incoming and outgoing intersection lengths
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
int off_x_intersect(double *l0,double *l3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double kx, double ky, double kz,
     off_struct data )
{
  /*This function simply reformats and calls off_intersect (as for neutrons)
   *by normalizing the wavevector - this will yield the intersection lengths
   *in m*/
  double jx,jy,jz,invk;
  int n;
  invk=1/sqrt(scalar_prod(kx,ky,kz,kx,ky,kz));
  jx=kx*invk;jy=ky*invk;jz=kz*invk;
  n=off_intersect(l0,l3,n0,n3,x,y,z,jx,jy,jz,0.0,0.0,0.0,data);
  return n;
}


/*******************************************************************************
* void off_display(off_struct data)
* ACTION: display up to N_VERTEX_DISPLAYED polygons from the object
*******************************************************************************/
void off_display(off_struct data)
{
  unsigned int i;
  double ratio=(double)(N_VERTEX_DISPLAYED)/(double)data.faceSize;
  unsigned int pixel=0;
  for (i=0; i<data.faceSize-1; i++) {
    int j;
    int nbVertex = data.faceArray[i];
    double x0,y0,z0;
    x0 = data.vtxArray[data.faceArray[i+1]].x;
    y0 = data.vtxArray[data.faceArray[i+1]].y;
    z0 = data.vtxArray[data.faceArray[i+1]].z;
    double x1=x0,y1=y0,z1=z0;
    double cmx=0,cmy=0,cmz=0;

    int drawthis = rand01() < ratio;
    // First pass, calculate center of mass location...
    for (j=1; j<=nbVertex; j++) {
      cmx = cmx+data.vtxArray[data.faceArray[i+j]].x;
      cmy = cmy+data.vtxArray[data.faceArray[i+j]].y;
      cmz = cmz+data.vtxArray[data.faceArray[i+j]].z;
    }
    cmx /= nbVertex;
    cmy /= nbVertex;
    cmz /= nbVertex;

    char pixelinfo[1024];
    sprintf(pixelinfo, "%li,%li,%li,%i,%g,%g,%g,%g,%g,%g", data.mantidoffset+pixel, data.mantidoffset, data.mantidoffset+data.polySize-1, nbVertex, cmx, cmy, cmz, x1-cmx, y1-cmy, z1-cmz);
    for (j=2; j<=nbVertex; j++) {
      double x2,y2,z2;
      x2 = data.vtxArray[data.faceArray[i+j]].x;
      y2 = data.vtxArray[data.faceArray[i+j]].y;
      z2 = data.vtxArray[data.faceArray[i+j]].z;
      sprintf(pixelinfo, "%s,%g,%g,%g", pixelinfo, x2-cmx, y2-cmy, z2-cmz);
      if (ratio > 1 || drawthis) {
	mcdis_line(x1,y1,z1,x2,y2,z2);
      }
      x1 = x2; y1 = y2; z1 = z2;
    }
    if (ratio > 1 || drawthis) {
	mcdis_line(x1,y1,z1,x0,y0,z0);
      }
    if (data.mantidflag) {
      printf("MANTID_PIXEL: %s\n", pixelinfo);
      pixel++;
    }
    i += nbVertex;
  }
} /* off_display */

/* end of interoff-lib.c */


/* Shared user declarations for all components types 'Bragg_crystal'. */
#ifndef MX_CRYSTALS_H
#define MX_CRYSTALS_H

#include <complex.h>

enum {Mx_crystal_explicit=0, Mx_crystal_diamond, Mx_crystal_fcc,Mx_crystal_bcc};

/* make proper function declaration to be standards-compliant */
#pragma acc routine
void Mx_CubicCrystalChi(double complex *chi0, double complex *chih, double *k0mag, double *hscale, double *thetaB,
                         double f00, double f0h, double fp, double fpp, double V, int h, int k, int l,
                         double debye_waller_B, double E,
                         int crystal_type, double fscaler, double fscalei);

#pragma acc routine
int Mx_DiffractionDispersion(double complex kqvals[4], double complex xi0[4], double complex xih[4],
        const double k0[3], const double nhat[3],
        const double H[3],
        double complex chi0, double complex chih_chihbar, double C, int nroots);

#pragma acc routine
int Mx_DarwinReflectivityBC(double *Rsig, double *Rpi, double kh[3],
	const double k0hat[3], const double nhat[3],
	const double alpha[3],
	double complex chi0, double complex chih, double complex chihbar,
	double k0mag, double hscale, double thetaB);

#pragma acc routine
int Mx_LaueReflectivityBC(double *Rsig, double *Rpi, double *Tsig, double *Tpi,
	double *Asig, double *Api, // primary attenuation
	double kh[3],
	const double k0hat[3], const double nhat[3],
	const double alpha[3],
	double complex chi0, double complex chih, double complex chihbar,
	double k0mag, double hscale, double thetaB, double thickness);

/*This is the old Darwin function*/
#pragma acc routine
void Mx_DarwinReflectivity(double *R, double *Thetah, double *Theta0, double *DeltaTheta0,
        double f00, double f0h, double fp, double fpp, double V, double alpha, int h, int k, int l,
        double debye_waller_B, double E, double Thetain, int pol,
        int crystal_type, double fscaler, double fscalei);

#pragma acc routine
void cross(double res[3], const double v1[3], const double v2[3], int unitize);



#define vdot(a,b) (a[0]*b[0]+a[1]*b[1]+a[2]*b[2])
#define vplus(res, a, b) { res[0]=a[0]+b[0]; res[1]=a[1]+b[1]; res[2]=a[2]+b[2]; }
// solve a quadratic a x^2 + b x + c safely, a la Numerical Recipes.  r1 always has the larger magnitude
#define qsolve(r1, r2, a, b, c, sqrtfn) { \
    if(creal(b) > 0) { r1=(-b-sqrtfn(b*b-4*a*c))/(2*a); } \
    else { r1=(-b+sqrtfn(b*b-4*a*c))/(2*a); } \
    r2=(c/a)/r1; }

#endif /* MX_CRYSTALS_H SHARE section */
#ifndef MX_CRYSTALS_C
#define MX_CRYSTALS_C

void Mx_CubicCrystalChi(double complex *chi0, double complex *chih, double *k0mag, double *hscale, double *thetaB,
                         double f00, double f0h, double fp, double fpp, double V, int h, int k, int l,
                         double debye_waller_B, double E,
                         int crystal_type, double fscaler, double fscalei)
{
    double lambda, a, d;
    
    lambda = 2*PI/(E2K*E);  			/* wavelength in Å, E in keV, using built-in constants for safety    */
    a = cbrt(V); 				/* side length of unit cubic cell (Å)*/
    d = a/sqrt(h*h + k*k + l*l); 		/* d-spacing (Å)*/

    if (lambda>2*d){
      /*cannot close scattering triangle, set all returns to 0 and exit*/
      *thetaB=0;
      *k0mag=0;
      *hscale=0;
      *chi0=*chih=0;
      return;
    }

    *thetaB = asin(lambda/(2*d));  		/* kinematical bragg angle (rad) */
    *k0mag=2.0*M_PI/lambda; /* magnitude of k0 consistent with energy scale */
    *hscale=2.0*M_PI/d; /* minus sign to make it point into the crystal */
    
    /* structure factor rules from:
     https://en.wikipedia.org/wiki/Structure_factor section on diamond cubic crystals
     */
    
    double complex fscaleh;
    double fscale0;
    
    switch(crystal_type) {
        case Mx_crystal_explicit:
            /* use explicitly provided structure factor scale factor */
            break;
        case Mx_crystal_diamond: /* diamond lattice rules */
            if (((h+k+l)%2) != 0){ 		/* (111) etc. odd sum eflection */
                fscaleh=4+4*I;
                fscale0=8;
            }
            else if (((h+k+l)%4)==0){ 		/* (400) etc. h+k+l=4n reflection */
                fscaleh=8;
                fscale0=8;
            } else {
                /* any other reflection is forbidden, will get a divide-by-zero somewhere, but user is
                 responsible for only using allowed reflections */
                fscaleh=0;
                fscale0=0;
            }
            break;
        case Mx_crystal_fcc: /* fcc lattice rules */
        {
            int hpar=h%2, kpar=k%2, lpar=l%2;
            if ( hpar==kpar && kpar==lpar ) { /* all parities the same */
                fscaleh=4;
                fscale0=4;
            }
            else { 		/* mixed parity forbidden */
                fscaleh=0;
                fscale0=0;
            }
        }
            break;
        case Mx_crystal_bcc: /* bcc lattice rules */
            if ( ((h+k+l)%2) == 0 ) { /* h+k+l even */
                fscaleh=2;
                fscale0=2;
            }
            else { 		/* otherwise forbidden */
                fscaleh=0;
                fscale0=0;
            }
            break;
        default:
            fscaleh=fscale0=0; /* fail later if unknown crystal type */
            break;
    }
    
    double complex F0=fscale0*((f00+fp)+fpp*I); // NEVER CHECKED for crystals other than diamond structure
    double complex Fh=cabs(fscaleh)*((f0h+fp)+fpp*I);
    
    double GAMMA=RE*lambda*lambda/(PI*V);
    double M=debye_waller_B*SQR(sin(*thetaB)/lambda)*(2./3.); /* isotropic temperature factor */
    *chi0 = -F0*GAMMA;
    *chih = -Fh*GAMMA*exp(-M);
}

int Mx_DarwinReflectivityBC(double *Rsig, double *Rpi, double kh[3],
                         const double k0hat[3], const double nhat[3],
                         const double alpha[3],
                         double complex chi0, double complex chih, double complex chihbar,
                         double k0mag, double hscale, double thetaB
                         )
{
    double k0[3]={k0hat[0]*k0mag, k0hat[1]*k0mag, k0hat[2]*k0mag}; /* actual incoming k vector */
    double H[3]={alpha[0]*hscale, alpha[1]*hscale, alpha[2]*hscale};
    
    /* now we have to solve for the free-space kh vector outside the crystal.
     The requirement is that kh = Kh + q2 * nhat, and is pure real and has the same magnitude as k0.
     Thus, kh = k0 + q1 * nhat + H + q2 * nhat, |kh| = |k0|, and (q1 + q2) must be real to make kh real.
     if (q1 + q2) == q,
     q^2 + H^2 + 2 q (k0+H).nhat + 2 k0.H = 0
     Note that this is independent of the messy dispersion relationship, and the same for both polarizations.
     */
    double k0plusH[3];
    vplus(k0plusH, k0, H); // temporary k0+H as needed in second poly term above
    double bb=2*vdot(k0plusH, nhat);
    double cc = vdot(H,H) +2*vdot(k0,H);
    double root1, root2;
    qsolve(root1, root2, 1., bb, cc, sqrt); //root2 is the small root
    vplus(kh, k0plusH, root2*nhat);
    
    for (int i=0; i<2; i++) { // do reflectivity using shared geometry for both polarizations
        double C=(i==0)?fabs(cos(2*thetaB)) : 1; // polarization factor
        double complex xi0;
        double K0[3], Kh[3];
        double complex kqvals[4], xi0vals[4], xihvals[4];

        int fail=Mx_DiffractionDispersion(kqvals, xi0vals, xihvals,
                   k0, nhat, H, chi0, chih*chihbar, C, 1); // get first (interesting) root only

        double complex kq=kqvals[0];
        xi0=xi0vals[0];
        vplus(K0, k0, creal(kq)*nhat);
        vplus(Kh, K0, H);

        /* compute the asymmetry b which is the ratio of the sizes of the footprint of the beam on the crystal */
        double b = (vdot(K0, nhat)/sqrt(vdot(K0,K0)))/(vdot(Kh, nhat)/sqrt(vdot(Kh, Kh)));
        
        if(fail) {
            *Rsig=0;
            *Rpi=0;
            return 1;
        }
        
        double complex eq24=2*xi0/(k0mag*C*chih); // B&C equation 24
        double eratio=cabs(eq24);
        
#ifdef MCDEBUG
#ifndef OPENACC
        fprintf(stderr,
                "Bragg Geometry results: k0=(%.3f %.3f %.3f), kh=(%.3f %.3f %.3f) "
                "xi0 = (%.3e + %.3e i) "
                "b0=%.4f "
                "eq24 = (%.3e + %.3e i) "
                "R = %.3e "
                "\n",
                k0[0], k0[1], k0[2], kh[0], kh[1], kh[2],
                creal(xi0), cimag(xi0),
                b,
                creal(eq24), cimag(eq24), eratio*eratio/fabs(b));
#endif
#endif
        
        if(i==0)  *Rpi=eratio*eratio/fabs(b); // the fabs(b0) is the footprint correction
        else      *Rsig=eratio*eratio/fabs(b);
    }
    return 0;
}

void cross(double res[3], const double v1[3], const double v2[3], int unitize)
{   // use our own cross product which takes arrays directly to reduce pointer shuffling
    res[0]=v1[1]*v2[2]-v1[2]*v2[1];
    res[1]=v1[2]*v2[0]-v1[0]*v2[2];
    res[2]=v1[0]*v2[1]-v1[1]*v2[0];
    if(unitize) {
        double l=sqrt(res[0]*res[0]+res[1]*res[1]+res[2]*res[2]);
        res[0]/=l;
        res[1]/=l;
        res[2]/=l;
    }
}
    
int Mx_DiffractionDispersion(double complex kqvals[4], double complex xi0[4], double complex xih[4],
                          const double k0[3], const double nhat[3],
                          const double H[3],
                          double complex chi0, double complex chih_chihbar, double C, int nroots){
    /* compute the Batterman & Cole eq. 17 dispersion relation, and associated quantities.
       nroots sets how many roots to find.  They are sorted, with the first root being the attenuated incoming ray,
       then the amplified incoming ray, then the two 'big roots'.
       Normally only nroots=1 is interesting for Bragg diffraction.
     */

    double k0mag=sqrt(vdot(k0,k0));
    
    /* B&C equation 17 is ( |k0 + kq nhat|^2 - k0^2(1+chi0) ) ( |k0 + kq nhat + H|^2 - k0^2(1+chi0) ) = k^4 C^2 chih chihbar */
    double k0plusH[3];
    vplus(k0plusH, k0, H); // temporary k0+H as needed in second poly term above
    double complex poly1[3], poly2[3], poly[5], deriv[4];
    poly1[2]=1;
    poly1[1]=2*vdot(k0,nhat);
    poly1[0]=-k0mag*k0mag*chi0;
    poly2[2]=1.;
    poly2[1]=2*vdot(k0plusH,nhat);
    poly2[0]=-k0mag*k0mag*chi0+vdot(H,H)+2*vdot(k0,H);
    /* for multiplying these polys, just write it out explicitly */
    poly[0]=poly1[0]*poly2[0];
    poly[1]=poly1[0]*poly2[1]+poly1[1]*poly2[0];
    poly[2]=poly1[0]*poly2[2]+poly1[1]*poly2[1]+poly1[2]*poly2[0];
    poly[3]=poly1[1]*poly2[2]+poly1[2]*poly2[1];
    poly[4]=poly1[2]*poly2[2];
    double complex epsilon=(k0mag*k0mag*k0mag*k0mag*C*C)*chih_chihbar; // right-hand side of dispersion
    poly[0]-=epsilon;
    deriv[3]=4*poly[4];
    deriv[2]=3*poly[3];
    deriv[1]=2*poly[2];
    deriv[0]=1*poly[1];
    
    /* the dispersion polynomial is p1*p2-epsilon = 0; first, find big roots and factor out to leave only a quadratic with small (interesting) roots */
    /* big roots will be _close_ to big roots of p1 and p2, use these as guesses */
    double complex p1b, p1s, p2b, p2s;
    // p1b and p2b are always larger root in magnitude
    qsolve(p1b, p1s, poly1[2], poly1[1], poly1[0], csqrt);
    qsolve(p2b, p2s, poly2[2], poly2[1], poly2[0], csqrt);
    
    /* now, (x-p1b)(x-p2b)(x-p1s)(x-p2s)-epsilon is the full poly, but near the interesting region around p1s, p2s, flatten first two terms */
    /* so x0 = (p1s+p2s)*0.5, this is (x-p1s)(x-p2s)-epsilon/((x0-p1b)(x0-p2b)) = 0 to get approximate roots of full poly */
    double complex x0=(p1s+p2s)*0.5;
    double complex fp[3] = {p1s*p2s-epsilon/((x0-p1b)*(x0-p2b)), -(p1s+p2s), 1.0 };
    // factored poly roots, should be very close to exact roots
    // practical note:  looking at convergence, these roots are so close, one could probably drop the Newton's method refinement
    // completely.  However, since this code is intended to be pedantically correct, I will do the refinement.
    double complex initroots[4];
    qsolve(initroots[0], initroots[1], fp[2], fp[1], fp[0], csqrt); // solution to factored polynomial is starting point for newton's method
    
    int rootloops, fail=0;
    // make sure the first root has im(k).re(k) < 0 so beam is attenuated. Since re(k) is nearly k0 and im(k) is im(kq)*nhat,
    // we need k0.nhat * im(k) < 0
    double kdotnhat=vdot(k0, nhat);
    if(cimag(initroots[0])*kdotnhat > 0) {
        if(cimag(initroots[1])*kdotnhat < 0) {
            double complex swap;
            swap=initroots[0]; initroots[0]=initroots[1]; initroots[1]=swap;
        } else {
            // neither root has im(k) < 0, no physically possible solution.  Should never happen.
#ifndef OPENACC
            fprintf(stderr, "PerfectCrystal: No attenuating solution for incoming vector found, r1=(%.3e + %.3e i) 	r2=(%.3e + %.3e i) \n",
                    creal(initroots[0]), cimag(initroots[0]), creal(initroots[1]), cimag(initroots[1]));
#endif
            return -1;
        }
    }
    initroots[2]=p1b;
    initroots[3]=p2b; // the two big roots are last in the list

    for(rootloops=0; rootloops < nroots; rootloops++) {
        double complex dd, kq, pv, dv;
        kq=initroots[rootloops];
#if MCDEBUG
#ifndef OPENACC
        fprintf(stderr,"Batterman Cole dispersion Newton Iterations, starting at root =(%.3e + %.3e i) \n",
                creal(kq), cimag(kq)
                );
#endif
#endif
        int stepcount=0;
        do {
            pv=(((poly[4]*kq+poly[3])*kq+poly[2])*kq+poly[1])*kq+poly[0]; // poly value
            dv=((deriv[3]*kq+deriv[2])*kq+deriv[1])*kq+deriv[0]; // derivative value
            dd=-pv/dv; // Newton's method step
            kq+=dd;
            stepcount++;
#ifdef MCDEBUG_EXTRA
#ifndef OPENACC
        fprintf(stderr,"Batterman Cole dispersion Newton Iterations, starting at root =(%.3e + %.3e i) \n",
            fprintf(stderr,"Batterman Cole dispersion Newton Iterations, step count=%d, pv=%.3e dv=%.3e "
                    "kq=(%.3e + %.3e I) shift=%.3e\n",
                    stepcount,
                    cabs(pv), cabs(dv), creal(kq), cimag(kq), cabs(dd) );
#endif
#endif
        } while ( ((cabs(dd) > 1e-15) && (stepcount < 20)) );
        kqvals[rootloops]=kq;

        fail= (stepcount == 20);
        if(fail) { // should never happen. always converges in about 3 steps!
#ifndef OPENACC
            fprintf(stderr,"****Newton's method convergence failure in Bragg_Geometry, killing particle!\n");
#endif
            kq=initroots[rootloops]; // leave offset plausible, close to quadratic start
        }


        // batterman and cole eq. 18, exact definitions of xi0 and xih
        // but adjust for numerical stability.
        // The smaller of xi0, xih depends on delicate cancellation of the polynomial.  The larger doesn't.
        // Thus, replace the small polynomial with epsilon / (large one)
        // This is equivalent to the Numerical Recipes trick for stable computation of quadratic roots
        double complex poly1v=(poly1[2]*kq+poly1[1])*kq+poly1[0];
        double complex poly2v=(poly2[2]*kq+poly2[1])*kq+poly2[0];
        if( fabs(creal(poly1v)) < fabs(creal(poly2v)) ) {
            poly1v=epsilon/poly2v;
        } else {
            poly2v=epsilon/poly1v;
        }
        xi0[rootloops]=poly1v/(2*k0mag);
        xih[rootloops]=poly2v/(2*k0mag);
        
    }
    return fail;
}

int Mx_LaueReflectivityBC(double *Rsig, double *Rpi, double *Tsig, double *Tpi,
                         double *Asig, double *Api, // primary attenuation
                         double kh[3],
                         const double k0hat[3], const double nhat[3],
                         const double alpha[3],
                         double complex chi0, double complex chih, double complex chihbar,
                         double k0mag, double hscale, double thetaB, double thickness)
{
    double k0[3]={k0hat[0]*k0mag, k0hat[1]*k0mag, k0hat[2]*k0mag}; /* actual incoming k vector */
    double H[3]={alpha[0]*hscale, alpha[1]*hscale, alpha[2]*hscale};

    /* a bunch of precomputed dot products we will use over and over.*/
    double k0dotnhat=vdot(k0,nhat);
    double Hdotnhat=vdot(H, nhat);
    double k0dotH=vdot(k0,H);
    double HdotH=vdot(H,H);
    
    /* now we have to solve for the free-space kh vector outside the crystal.
     The requirement is that kh = Kh + e * nhat, and is pure real and has the same magnitude as k0.
     Thus, kh = k0 + kq*nhat + H + e*nhat, |kh| = |k0|, and kq+e must be real to make kh real.
     if kq+e == q,
     q^2 + H^2 + 2 q (k0+H).nhat + 2 k0.H = 0
     Note that this is independent of the messy dispersion relationship, and the same for both polarizations.
     */
    double k0plusH[3];
    vplus(k0plusH, k0, H);
    double bb=2*(k0dotnhat+Hdotnhat);
    double cc = HdotH +2*k0dotH;
    double root1, root2;
    qsolve(root1, root2, 1., bb, cc, sqrt); //root2 is the small root
    vplus(kh, k0plusH, root2*nhat);

    for (int i=0; i<2; i++) { // do reflectivity using shared geometry for both polarizations
        double C=(i==0)?fabs(cos(2*thetaB)) : 1; // polarization factor
        double complex kqvals[4], xi0vals[4], xihvals[4];

        int fail=Mx_DiffractionDispersion(kqvals, xi0vals, xihvals,
                   k0, nhat, H, chi0, chih*chihbar, C, 2); // get first 2 (alpha and beta) roots only

        double complex a1=2*xi0vals[0]/(k0mag*C*chih);  // complex Eha/E0a from B&C eq. 24
        double complex a2=2*xi0vals[1]/(k0mag*C*chih);  // complex Ehb/E0a from B&C eq. 24
        // compute amplitudes from solving B&C eqns. 40
        double complex i1=a2/(a2-a1); // e0a/e0i
        double complex i2=-a1/(a2-a1); // e0a/e0i
        double complex ix=-thickness*1e10*I; // convert thickness to angstroms for absorption

        // factor out main K vector and difference explicitly,
        // so that dphi, the relative phase & amplitude of the alpha and beta
        // rays can be calculated to high accuracy
        // note: K0=k0 + r nhat, so K0.nhat = k0.nhat + r
        // similarly for Kh=k0 + H + r nhat so Kh.nhat = k0.nhat + H.nhat + r

        // we don't actually use the main phase (yet), so only compute real part
        // of transport exponentials
        // double complex phi0t=cexp((k0dotnhat+kqvals[0])*ix) #alpha transmitted wave factor
        // double complex phi0r=cexp((k0dotnhat+Hdotnhat+kqvals[0])*ix) #alpha reflected factor
        double phi0t=exp(creal((k0dotnhat+kqvals[0])*ix)); // alpha transmitted wave factor
        double phi0r=exp(creal((k0dotnhat+Hdotnhat+kqvals[0])*ix)); // alpha reflected factor
        double complex dphi=cexp((kqvals[1]-kqvals[0])*ix); // beta-alpha transmission ratio

        double complex t0zz=phi0t*(i1+i2*dphi); // transmitted complex field amplitude at exit
        double complex thzz=phi0r*(a1*i1+a2*i2*dphi); // reflected complex field amplitude at exit
#ifdef MCDEBUG
#ifndef OPENACC
        fprintf(stderr, "LAUE: "
        " k0 = (%.3f %.3f %.3f) thickness=%.3e"
        " a1=(%.3f + %.3fj) "
        " a2=(%.3f + %.3fj) "
        " i1=(%.3f + %.3fj) "
        " i2=(%.3f + %.3fj) "
        " phi0t = %.3e phi0r = %.3e "
        " dphi=(%.3f + %.3fj) "
        " t0zz=(%.3f + %.3fj) "
        " thzz=(%.3f + %.3fj) "
        " \n",
        k0[0], k0[1], k0[2], thickness,
        creal(a1), cimag(a1),
        creal(a2), cimag(a2),
        creal(i1), cimag(i1),
        creal(i2), cimag(i2),
        phi0t, phi0r,
        creal(dphi), cimag(dphi),
        creal(t0zz), cimag(t0zz),
        creal(thzz), cimag(thzz)
        );
#endif
#endif

        /* compute the asymmetry b which is the ratio of the sizes of the footprint of the beam on the crystal.
        Assume it is the same for alpha and beta branches!
        */
        double K0[3], Kh[3];
        vplus(K0, k0, creal(kqvals[0])*nhat);
        vplus(Kh, K0, H);
        double b = (vdot(K0, nhat)/sqrt(vdot(K0,K0)))/(vdot(Kh, nhat)/sqrt(vdot(Kh, Kh)));

        double R=cabs(thzz*thzz)/fabs(b); // the fabs(b) is the footprint correction
        double T=cabs(t0zz*t0zz)/fabs(b);

        if(i==0) {
            *Rpi= R; *Tpi= T; *Api=phi0t*phi0t;
        } else {
            *Rsig=R; *Tsig=T; *Asig=phi0t*phi0t;
        }
    }
    return 0;
}

/*This is the old Darwin function*/ 
void Mx_DarwinReflectivity(double *R, double *Thetah, double *Theta0, double *DeltaTheta0,
                             double f00, double f0h, double fp, double fpp, double V, double alpha, int h, int k, int l,
                             double debye_waller_B, double E, double Thetain, int pol,
                            int crystal_type, double fscaler, double fscalei
                             )
{

    double lambda,theta,theta0,DeltaThetas,a,d,b,C,W,kappa,g,L;
    double F0r,F0i,Fhr,Fhi,psi0r,psi0i,psihr,psihi;

    lambda = 2*PI/(E2K*E);  			/* wavelength in Å, E in keV, using built-in constants for safety    */
    a = cbrt(V); 				/* side length of unit cubic cell (Å)*/
    d = a/sqrt(h*h + k*k + l*l); 		/* d-spacing (Å)*/
    theta = asin(lambda/(2*d));  		/* kinematical bragg angle (rad) */
    b = sin(theta + alpha)/sin(theta - alpha);  /* asymmetry factor */

    *Theta0 = Thetain - alpha; 			/* (rad) angle between Bragg planes and incident ray */
    *Thetah = b*(*Theta0 - theta) + theta;   	/* (rad) Angle betweeb Bragg planes and reflected ray */
    /*check if Bragg angle is less than alpha. If so return 0 reflectivity*/
    if (theta<alpha) {
        *R=0;
        *DeltaTheta0 = -1; /*to mark it irrelevant*/
    }

    /* Define polarization factor: */
    switch(pol){
        case 0:
            C = (1 + fabs(cos(2*theta)))/2;         	/* unpolarized */
            break;
        case 1:
            C = fabs(cos(2*theta));  		/* polarization in the scattering plane */
            break;
        case 2:
            C = 1;                          	/* polarization perpendicular to the scattering plane*/
            break;
    }

    /* structure factor rules from:
https://en.wikipedia.org/wiki/Structure_factor section on diamond cubic crystals
     */

    switch(crystal_type) {
        case Mx_crystal_explicit:
            /* use explicitly provided structure factor scale factor */
            break;
        case Mx_crystal_diamond: /* diamond lattice rules */
            if (((h+k+l)%2) != 0){ 		/* (111) etc. odd sum eflection */
                fscaler=fscalei=4.0;
            }
            else if (((h+k+l)%4)==0){ 		/* (400) etc. h+k+l=4n reflection */
                fscaler=8; fscalei=0;
            } else {
                /* any other reflection is forbidden, will get a divide-by-zero somewhere, but user is
                   responsible for only using allowed reflections */
                fscaler=0; fscalei=0;
            }
            break;
        case Mx_crystal_fcc: /* fcc lattice rules */
            {
                int hpar=h%2, kpar=k%2, lpar=l%2;
                if ( hpar==kpar && kpar==lpar ) { /* all parities the same */
                    fscaler=4.0; fscalei=0.0;
                }
                else { 		/* mixed parity forbidden */
                    fscaler=0; fscalei=0;
                }
            }
            break;
        case Mx_crystal_bcc: /* bcc lattice rules */
            if ( ((h+k+l)%2) == 0 ) { /* h+k+l even */
                fscaler=2.0; fscalei=0.0;
            }
            else { 		/* otherwise forbidden */
                fscaler=0; fscalei=0;
            }
            break;
        default:
            fscaler=0; fscalei=0; /* fail later if unknown crystal type */
            break;
    }

    F0r=8*(f00+fp);
    F0i=8*fpp;
    double scalemag=sqrt(fscaler*fscaler+fscalei*fscalei);
    Fhr=scalemag*(f0h+fp);
    Fhi=scalemag*fpp;

    double main_scale=RE*lambda*lambda/(PI*V);
    double M=debye_waller_B*SQR(sin(Thetain)/lambda)*(2./3.); /* temperature factor */
    psi0r = F0r*main_scale;
    psi0i = F0i*main_scale;
    psihr = Fhr*main_scale*exp(-M); /* Eq 23*/
    psihi = Fhi*main_scale*exp(-M); /* only angle-dependent part gets scaled by temp factor */

    W = 0.5 * (sqrt(b) + 1/sqrt(b)) * psi0r/(C * psihr) +  sqrt(b)*sin(2*theta)*(theta - *Theta0)/(C * psihr); /* eq 28*/
    kappa = psihi/psihr;                                              	/* eq 22 */
    g = 0.5*(sqrt(b) + 1/sqrt(b))*psi0i/(C*psihr);               	/* eq 21 */
    L = (1/(1 + kappa*kappa))*( W*W + g*g + sqrt(SQR(W*W - g*g - 1 + kappa*kappa) + 4*SQR(g*W - kappa)));

    /* *R = L - sqrt(L*L - 1); */
    /* replace x-sqrt(x^2-1) with exactly equal 1/(x+sqrt(x^2-1)) to avoid roundoff when x is large ... MHM */
    *R = 1/(L + sqrt(L*L - 1));

    DeltaThetas = psi0r/sin(2*theta);               	/* eq 32 */
#ifdef MCDEBUG
#ifndef OPENACC
    printf("E,lambda= %f , %f \n",E,lambda);
    printf("theta= %f \n",theta*180/PI);
    printf("Theta0= %f \n",*Theta0*180/PI);
    printf("theta = %g rad, alpha=%g rad.\n",theta,alpha);
    printf("b,sqrt(b)= %f %f\n",b,sqrt(b));
    printf("1/sqrt(b)= %f \n",1/sqrt(b));
    printf("Fhr, Fhi, F0r, F0i= %g %g %g %g\n",Fhr, Fhi, F0r, F0i);
    printf("psihr, psihi, psi0r, psi0i= %g %g %g %g\n",psihr, psihi, psi0r, psi0i);
    printf("sqrt(b)*sin(2*theta)= %g \n",sqrt(b)*sin(2*theta));
    printf("C, pis0r,C * psihr= %g %g %g\n",C, psi0r,C * psihr);
    printf("W= %f \n",W);
    printf("kappa= %f \n",kappa);
    printf("g= %f \n",g);
    printf("L= %f \n",L);
    printf("R= %f \n",*R);
    printf("DeltaThetas %f \n",3600*DeltaThetas*180/PI);
#endif
#endif
    *DeltaTheta0 = 0.5*(1 + 1/b)*DeltaThetas;                        	/* center of reflectivity curve is at theta + DeltaTheta0 eq 31 */
}


#endif /* MX_CRYSTALS_C */


/* Shared user declarations for all components types 'Fluorescence'. */
  #ifndef XRAYLIB_LINES_MAX
  #define XRAYLIB_LINES_MAX 383
  #define FLUORESCENCE 0  // Fluo
  #define RAYLEIGH     1  // Coherent
  #define COMPTON      2  // Incoherent
  #define TRANSMISSION 3
  #include <xraylib/xraylib.h>
  #endif

 // for OFF/PLY geometry
  
/* See XrayLib code (c) T. Schoonjans
 * /usr/include/xraylib/xraylib-parser.h      for compoundData
 * /usr/include/xraylib/xraylib.h             for XS
 */

/* inspired from:
 * https://github.com/golosio/xrmc src/photon/photon.cpp (c) Bruno Golosio    
 */
  
/* XRMC_CrossSections: Compute interaction cross sections in [barn/atom]
 * Return total cross section, given Z and E0:
 *   total_xs = XRMC_CrossSections(Z, E0, xs[3]);
 */
double XRMC_CrossSections(int Z, double E0, double *xs) {
  int    i_line;
  
  if (xs == NULL) return 0;
  
  // loop on possible fluorescence lines
  for (i_line=0; i_line<XRAYLIB_LINES_MAX; i_line++) { 
    // cumulative sum of the line cross sections
    xs[FLUORESCENCE] += CSb_FluorLine(Z, -i_line, E0, NULL); /* XRayLib */
  }

  // coherent and incoherent cross sections
  xs[RAYLEIGH] = CSb_Rayl( Z, E0, NULL);
  xs[COMPTON]  = CSb_Compt(Z, E0, NULL);
  
  // total interaction cross section, should converge to CSb_Total(Z, E0, NULL)
  return xs[FLUORESCENCE] + xs[RAYLEIGH] + xs[COMPTON];
} // XRMC_CrossSections

/* XRMC_SelectFromDistribution: select a random element from a distribution
 *   index = XRMC_SelectFromDistribution(cum_sum[N], N);
 * index is returned within 0 and N-1
 * The x_arr must be a continuously increasing cumulated sum, which last element is the max
 */
int XRMC_SelectFromDistribution(double x_arr[], int N)
{
  double x=rand01()*x_arr[N-1];
  if (x<x_arr[0]) {    // x is smaller than lower limit
    return 0;
  }
  if (x>=x_arr[N-1]) { // x is greater or equal to upper limit
    return N-1;
  }
  int id=0, iu=N-1; // lower and upper index of the subarray to search
  while (iu-id>1) { // search until the size of the subarray to search is >1
    int im = (id + iu)/2; // use the midpoint for equal partition
    // decide which subarray to search
    if (x>=x_arr[im]) id=im; // change min index to search upper subarray
    else iu=im; // change max index to search lower subarray
  }

  return id;
} // XRMC_SelectFromDistribution

/* XRMC_SelectInteraction: select interaction type Fluo/Compton/Rayleigh
 * Return the interaction type from a random choice within cross sections 'xs'
 *   type = XRMC_SelectInteraction(xs[3]);
 * 'xs' is computed with XRMC_CrossSections.
 * type is one of FLUORESCENCE | RAYLEIGH | COMPTON
 */
int XRMC_SelectInteraction(double *xs)
{
  double sum_xs, cum_xs[4];
  int    i;
  
  cum_xs[0]=sum_xs=0;
  for (i=0; i< 3; i++) {
    sum_xs += xs[i];
    cum_xs[i+1]= sum_xs;
  }
  return XRMC_SelectFromDistribution(cum_xs, 4);
} // XRMC_SelectInteraction

/* XRMC_SelectFluorescenceEnergy: select outgoing fluo photon energy, when incoming with 'E0'
 *   Ef = XRMC_SelectFluorescenceEnergy(Z, E0, &dE);
 */
double XRMC_SelectFluorescenceEnergy(int Z, double E0, double *dE)
{
  int i_line;
  double sum_xs, cum_xs_lines[XRAYLIB_LINES_MAX+1];

  // compute cumulated XS for all fluo lines
  cum_xs_lines[0] = sum_xs = 0;
  for (i_line=0; i_line<XRAYLIB_LINES_MAX; i_line++) { // loop on fluorescent lines
    double xs = CSb_FluorLine(Z, -i_line, E0, NULL); /* XRayLib */
    // when a line is inactive: E=xs=0
    sum_xs += xs;
    cum_xs_lines[i_line+1] = sum_xs; // cumulative sum of their cross sections
  }
  // select randomly one of these lines
  i_line = XRMC_SelectFromDistribution(cum_xs_lines, XRAYLIB_LINES_MAX); // extract a line
  // get the K shell line width as approximation of fluorescence line width
  if (dE) *dE = AtomicLevelWidth(Z, K_SHELL, NULL); // keV

  return LineEnergy(Z, -i_line, NULL); // fluorescent line energy
} // XRMC_SelectFluorescenceEnergy

  // Function removing spaces from string
  char * removeSpacesFromStr(char *string)
  {
      // non_space_count to keep the frequency of non space characters
      int non_space_count = 0;
   
      //Traverse a string and if it is non space character then, place it at index non_space_count
      for (int i = 0; string[i] != '\0'; i++)
      {
          if (isalpha(string[i]) || isdigit(string[i]))
          {
              string[non_space_count] = string[i];
              non_space_count++; //non_space_count incremented
          }    
      }
      
      //Finally placing final character at the string end
      string[non_space_count] = '\0';
      return string;
  }

  // ok = fluo_get_material(material, formula)
  // extracts material atoms from file header
  // the result is concatenated into 'formula'
  int fluo_get_material(char *filename, char *formula) {
  
    int  ret = 0;
    char Line[65535];
    int flag_found_cif=0;
    FILE *file = fopen(filename, "r");
    if (!file)
      exit(fprintf(stderr, "%s: ERROR: can not open file %s\n", 
      __FILE__, filename));
    
    // Read the file, and search tokens in rows
    formula[0]=0;
    while (fgets(Line, sizeof(Line), file) != NULL) {
      char *token = NULL;
      int   flag_exit=0;
      char *first_non_space=NULL;
      char *next_non_space =NULL;
      // CIF: _chemical_formula_structural 'chemical_formulae'
      // CIF: _chemical_formula_sum 'chemical_formulae'
      // LAZ/LAU: # ATOM <at> <trailing>
      // LAZ/LAU: # Atom <at> <trailing>
      // LAZ/LAU: # TITLE <at> <at> ... [ trailing...]
      // CFL: Title <chemical_formulae>
      // CFL: Atom <at> <trailing>
      
      // search for CIF token
      // single line: search " '\'" delimiter after CIF token, marks reading the formula
      if (!strncasecmp(Line, "_chemical_formula_structural", 28) 
       || !strncasecmp(Line, "_chemical_formula_sum", 21) 
       || !strncasecmp(Line, "_chemical_formula_moiety", 24)
       || flag_found_cif) {
        if  (flag_found_cif) { flag_found_cif=0; /* can not span on more that 2 lines */} 
        else flag_found_cif=1;
        // search for delimiter after the CIF token
        char *first_space_after_token=strpbrk(Line, " \'\n");
        if (first_space_after_token) {
          // search for the characters that may compose the formula
          first_non_space = strpbrk(first_space_after_token, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789()[]");
          if (strchr(first_space_after_token,'?')) {
            // we have an invalid/unknown formula in the CIF. Skip CIF token/line
            flag_found_cif=0;
            continue;
          }
        }
        if (first_non_space) 
          next_non_space  = strpbrk(first_non_space+1, "\'\n\r"); // position of formula end
        if (next_non_space) { 
          flag_exit = 1;
          token = first_non_space;
        }
      } else if (!strncasecmp(Line, "# TITLE", 7) && strchr(Line, '['))
        token = Line+7;
      else if (!strncasecmp(Line, "# Atom", 6))
        token = Line+6;
      else if (!strncasecmp(Line, "Atom", 4))
        token = Line+4;
      else if (!strncasecmp(Line, "Title", 5))
        token = Line+7;
      if (!token) continue;
      if (!strncasecmp(Line, "# TITLE", 7)) {
        first_non_space = Line+7;
        next_non_space  = strchr(Line+7, '[');
        if (next_non_space) flag_exit = 1;
      }
      if (!first_non_space) first_non_space = strtok(token, " \t\n");
      if (!first_non_space) continue;
      if (!next_non_space)  next_non_space  = strtok(NULL,  " \t\n"); // end of formulae
      if (!next_non_space)  next_non_space = Line+strlen(Line);
      // remove spaces
      strncat(formula, first_non_space, next_non_space-first_non_space);
      ret++;
      if (flag_exit) break;
    }
    fclose(file);
    removeSpacesFromStr(formula);
    return(ret);
  } // fluo_get_material



/* ************************************************************************** */
/*             End of SHARE user declarations for all components              */
/* ************************************************************************** */


/* ********************** component definition declarations. **************** */

/* component origin=Progress_bar() [1] DECLARE */
/* Parameter definition for component type 'Progress_bar' */
struct _struct_Progress_bar_parameters {
  /* Component type 'Progress_bar' setting parameters */
  char profile[16384];
  MCNUM percent;
  MCNUM flag_save;
  MCNUM minutes;
  /* Component type 'Progress_bar' private parameters */
  double  IntermediateCnts;
  time_t  StartTime;
  time_t  EndTime;
  time_t  CurrentTime;
}; /* _struct_Progress_bar_parameters */
typedef struct _struct_Progress_bar_parameters _class_Progress_bar_parameters;

/* Parameters for component type 'Progress_bar' */
struct _struct_Progress_bar {
  char     _name[256]; /* e.g. origin */
  char     _type[256]; /* Progress_bar */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Progress_bar_parameters _parameters;
};
typedef struct _struct_Progress_bar _class_Progress_bar;
_class_Progress_bar _origin_var;
#pragma acc declare create ( _origin_var )

/* component source=Wiggler() [2] DECLARE */
/* Parameter definition for component type 'Wiggler' */
struct _struct_Wiggler_parameters {
  /* Component type 'Wiggler' setting parameters */
  MCNUM E0;
  MCNUM dE;
  MCNUM lambda0;
  MCNUM dlambda;
  MCNUM phase;
  MCNUM randomphase;
  MCNUM Ee;
  MCNUM Ie;
  MCNUM B;
  MCNUM K;
  int Nper;
  MCNUM length;
  MCNUM sigey;
  MCNUM sigex;
  MCNUM focus_xw;
  MCNUM focus_yh;
  MCNUM dist;
  MCNUM gauss_t;
  int verbose;
  MCNUM Br;
  /* Component type 'Wiggler' private parameters */
  double  gamma;
  double  gamma2;
  double  igamma;
  double  kc;
  double  s1x;
  double  s1y;
  double  lu;
  double  gap;
  double  p0;
}; /* _struct_Wiggler_parameters */
typedef struct _struct_Wiggler_parameters _class_Wiggler_parameters;

/* Parameters for component type 'Wiggler' */
struct _struct_Wiggler {
  char     _name[256]; /* e.g. source */
  char     _type[256]; /* Wiggler */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Wiggler_parameters _parameters;
};
typedef struct _struct_Wiggler _class_Wiggler;
_class_Wiggler _source_var;
#pragma acc declare create ( _source_var )

/* component mon_src_e=Monitor_nD() [3] DECLARE */
/* Parameter definition for component type 'Monitor_nD' */
struct _struct_Monitor_nD_parameters {
  /* Component type 'Monitor_nD' setting parameters */
  char user1[16384];
  char user2[16384];
  char user3[16384];
  MCNUM xwidth;
  MCNUM yheight;
  MCNUM zdepth;
  MCNUM bins;
  MCNUM min;
  MCNUM max;
  MCNUM restore_xray;
  MCNUM radius;
  char options[16384];
  char filename[16384];
  char geometry[16384];
  int nowritefile;
  char username1[16384];
  char username2[16384];
  char username3[16384];
  /* Component type 'Monitor_nD' private parameters */
  MonitornD_Defines_type  DEFS;
  MonitornD_Variables_type  Vars;
  MCDETECTOR  detector;
  off_struct  offdata;
}; /* _struct_Monitor_nD_parameters */
typedef struct _struct_Monitor_nD_parameters _class_Monitor_nD_parameters;

/* Parameters for component type 'Monitor_nD' */
struct _struct_Monitor_nD {
  char     _name[256]; /* e.g. mon_src_e */
  char     _type[256]; /* Monitor_nD */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Monitor_nD_parameters _parameters;
};
typedef struct _struct_Monitor_nD _class_Monitor_nD;
_class_Monitor_nD _mon_src_e_var;
#pragma acc declare create ( _mon_src_e_var )

_class_Monitor_nD _mon_src_xy_var;
#pragma acc declare create ( _mon_src_xy_var )

/* component DCM_location=Arm() [5] DECLARE */
/* Parameter definition for component type 'Arm' */
struct _struct_Arm_parameters {
  char Arm_has_no_parameters;
}; /* _struct_Arm_parameters */
typedef struct _struct_Arm_parameters _class_Arm_parameters;

/* Parameters for component type 'Arm' */
struct _struct_Arm {
  char     _name[256]; /* e.g. DCM_location */
  char     _type[256]; /* Arm */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Arm_parameters _parameters;
};
typedef struct _struct_Arm _class_Arm;
_class_Arm _DCM_location_var;
#pragma acc declare create ( _DCM_location_var )

/* component dcm_xtal0=Bragg_crystal() [6] DECLARE */
/* Parameter definition for component type 'Bragg_crystal' */
struct _struct_Bragg_crystal_parameters {
  /* Component type 'Bragg_crystal' setting parameters */
  MCNUM length;
  MCNUM width;
  MCNUM V;
  char form_factors[16384];
  char material[16384];
  MCNUM alpha;
  MCNUM R0;
  MCNUM debye_waller_B;
  int crystal_type;
  int h;
  int k;
  int l;
  MCNUM structure_factor_scale_r;
  MCNUM structure_factor_scale_i;
  /* Component type 'Bragg_crystal' private parameters */
  int  Z;
  double  rho;
  double  At;
  double  f_rel;
  double  f_nt;
  t_Table  m_t;
  t_Table  f0_t;
}; /* _struct_Bragg_crystal_parameters */
typedef struct _struct_Bragg_crystal_parameters _class_Bragg_crystal_parameters;

/* Parameters for component type 'Bragg_crystal' */
struct _struct_Bragg_crystal {
  char     _name[256]; /* e.g. dcm_xtal0 */
  char     _type[256]; /* Bragg_crystal */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Bragg_crystal_parameters _parameters;
};
typedef struct _struct_Bragg_crystal _class_Bragg_crystal;
_class_Bragg_crystal _dcm_xtal0_var;
#pragma acc declare create ( _dcm_xtal0_var )

_class_Arm _dcm0_var;
#pragma acc declare create ( _dcm0_var )

_class_Bragg_crystal _dcm_xtal1_var;
#pragma acc declare create ( _dcm_xtal1_var )

_class_Arm _dcm1_var;
#pragma acc declare create ( _dcm1_var )

_class_Monitor_nD _mon_dcm_e_var;
#pragma acc declare create ( _mon_dcm_e_var )

_class_Monitor_nD _mon_dcm_xy_var;
#pragma acc declare create ( _mon_dcm_xy_var )

/* component slit=Slit() [12] DECLARE */
/* Parameter definition for component type 'Slit' */
struct _struct_Slit_parameters {
  /* Component type 'Slit' setting parameters */
  MCNUM xmin;
  MCNUM xmax;
  MCNUM ymin;
  MCNUM ymax;
  MCNUM radius;
  MCNUM xwidth;
  MCNUM yheight;
  MCNUM dist;
  MCNUM focus_xw;
  MCNUM focus_yh;
  MCNUM focus_x0;
  MCNUM focus_y0;
}; /* _struct_Slit_parameters */
typedef struct _struct_Slit_parameters _class_Slit_parameters;

/* Parameters for component type 'Slit' */
struct _struct_Slit {
  char     _name[256]; /* e.g. slit */
  char     _type[256]; /* Slit */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Slit_parameters _parameters;
};
typedef struct _struct_Slit _class_Slit;
_class_Slit _slit_var;
#pragma acc declare create ( _slit_var )

_class_Arm _sample_stage_var;
#pragma acc declare create ( _sample_stage_var )

/* component sample=Fluorescence() [14] DECLARE */
/* Parameter definition for component type 'Fluorescence' */
struct _struct_Fluorescence_parameters {
  /* Component type 'Fluorescence' setting parameters */
  char geometry[16384];
  MCNUM radius;
  MCNUM thickness;
  MCNUM xwidth;
  MCNUM yheight;
  MCNUM zdepth;
  int concentric;
  char material[16384];
  MCNUM packing_factor;
  MCNUM rho;
  MCNUM density;
  MCNUM weight;
  MCNUM p_interact;
  MCNUM target_x;
  MCNUM target_y;
  MCNUM target_z;
  MCNUM focus_r;
  MCNUM focus_xw;
  MCNUM focus_yh;
  MCNUM focus_aw;
  MCNUM focus_ah;
  int target_index;
  int flag_compton;
  int flag_rayleigh;
  int flag_lorentzian;
  int order;
  /* Component type 'Fluorescence' private parameters */
  struct   compoundData * compound;
  DArray1d  cum_massFractions;
  DArray1d  cum_xs_fluo;
  DArray1d  cum_xs_Compton;
  DArray1d  cum_xs_Rayleigh;
  int   shape;
  off_struct  offdata;
  int   n_fluo;
  int   n_Compton;
  int   n_Rayleigh;
  double  p_fluo;
  double  p_Compton;
  double  p_Rayleigh;
  int     reuse_nb;
  int     reuse_intersect;
  double  reuse_ki;
  double  reuse_l0;
  double  reuse_l1;
  double  reuse_l2;
  double  reuse_l3;
  double  reuse_sigma_barn;
  DArray1d  reuse_cum_xs_fluo;
  DArray1d  reuse_cum_xs_Compton;
  DArray1d  reuse_cum_xs_Rayleigh;
  char * filename;
}; /* _struct_Fluorescence_parameters */
typedef struct _struct_Fluorescence_parameters _class_Fluorescence_parameters;

/* Parameters for component type 'Fluorescence' */
struct _struct_Fluorescence {
  char     _name[256]; /* e.g. sample */
  char     _type[256]; /* Fluorescence */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Fluorescence_parameters _parameters;
};
typedef struct _struct_Fluorescence _class_Fluorescence;
_class_Fluorescence _sample_var;
#pragma acc declare create ( _sample_var )

_class_Arm _fluo_holder_var;
#pragma acc declare create ( _fluo_holder_var )

_class_Monitor_nD _mon_spl_fluo_var;
#pragma acc declare create ( _mon_spl_fluo_var )

_class_Monitor_nD _mon_spl_e_var;
#pragma acc declare create ( _mon_spl_e_var )

_class_Monitor_nD _mon_spl_xy_var;
#pragma acc declare create ( _mon_spl_xy_var )

int mcNUMCOMP = 18;

/* User declarations from instrument definition. Can define functions. */
  double dcm_gap;
  double dcm_scatter;
  #pragma acc declare create(dcm_scatter)

#undef compcurname
#undef compcurtype
#undef compcurindex
/* end of instrument 'SOLEIL_PSICHE' and components DECLARE */

/* *****************************************************************************
* instrument 'SOLEIL_PSICHE' and components INITIALISE
***************************************************************************** */

double index_getdistance(int first_index, int second_index)
/* Calculate the distance two components from their indexes*/
{
  return coords_len(coords_sub(POS_A_COMP_INDEX(first_index), POS_A_COMP_INDEX(second_index)));
}

double getdistance(char* first_component, char* second_component)
/* Calculate the distance between two named components */
{
  int first_index = _getcomp_index(first_component);
  int second_index = _getcomp_index(second_component);
  return index_getdistance(first_index, second_index);
}

double checked_setpos_getdistance(int current_index, char* first_component, char* second_component)
/* Calculate the distance between two named components at *_setpos() time, with component index checking */
{
  int first_index = _getcomp_index(first_component);
  int second_index = _getcomp_index(second_component);
  if (first_index >= current_index || second_index >= current_index) {
    printf("setpos_getdistance can only be used with the names of components before the current one!\n");
    return 0;
  }
  return index_getdistance(first_index, second_index);
}
#define setpos_getdistance(first, second) checked_setpos_getdistance(current_setpos_index, first, second)

/* component origin=Progress_bar() SETTING, POSITION/ROTATION */
int _origin_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_origin_setpos] component origin=Progress_bar() SETTING [/usr/share/mcxtrace/3.4-20240304/misc/Progress_bar.comp:60]");
  stracpy(_origin_var._name, "origin", 16384);
  stracpy(_origin_var._type, "Progress_bar", 16384);
  _origin_var._index=1;
  int current_setpos_index = 1;
  if("NULL" && strlen("NULL"))
    stracpy(_origin_var._parameters.profile, "NULL" ? "NULL" : "", 16384);
  else 
  _origin_var._parameters.profile[0]='\0';
  _origin_var._parameters.percent = 10;
  _origin_var._parameters.flag_save = 0;
  _origin_var._parameters.minutes = 0;


  /* component origin=Progress_bar() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(_origin_var._rotation_absolute,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_copy(_origin_var._rotation_relative, _origin_var._rotation_absolute);
    _origin_var._rotation_is_identity =  rot_test_identity(_origin_var._rotation_relative);
    _origin_var._position_absolute = coords_set(
      0, 0, 0);
    tc1 = coords_neg(_origin_var._position_absolute);
    _origin_var._position_relative = rot_apply(_origin_var._rotation_absolute, tc1);
  } /* origin=Progress_bar() AT ROTATED */
  DEBUG_COMPONENT("origin", _origin_var._position_absolute, _origin_var._rotation_absolute);
  instrument->_position_absolute[1] = _origin_var._position_absolute;
  instrument->_position_relative[1] = _origin_var._position_relative;
    _origin_var._position_relative_is_zero =  coords_test_zero(_origin_var._position_relative);
  instrument->counter_N[1]  = instrument->counter_P[1] = instrument->counter_P2[1] = 0;
  instrument->counter_AbsorbProp[1]= 0;
  return(0);
} /* _origin_setpos */

/* component source=Wiggler() SETTING, POSITION/ROTATION */
int _source_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_source_setpos] component source=Wiggler() SETTING [/usr/share/mcxtrace/3.4-20240304/sources/Wiggler.comp:106]");
  stracpy(_source_var._name, "source", 16384);
  stracpy(_source_var._type, "Wiggler", 16384);
  _source_var._index=2;
  int current_setpos_index = 2;
  _source_var._parameters.E0 = _instrument_var._parameters.E0;
  _source_var._parameters.dE = _instrument_var._parameters.dE;
  _source_var._parameters.lambda0 = 0;
  _source_var._parameters.dlambda = 0;
  _source_var._parameters.phase = 0;
  _source_var._parameters.randomphase = 1;
  _source_var._parameters.Ee = 2.4;
  _source_var._parameters.Ie = 0.5;
  _source_var._parameters.B = 2.1;
  _source_var._parameters.K = 10;
  _source_var._parameters.Nper = 41;
  _source_var._parameters.length = 38 * 50e-3;
  _source_var._parameters.sigey = 9.3e-6;
  _source_var._parameters.sigex = 215.7e-6;
  _source_var._parameters.focus_xw = 0;
  _source_var._parameters.focus_yh = 0;
  _source_var._parameters.dist = 1;
  _source_var._parameters.gauss_t = 0;
  _source_var._parameters.verbose = 1;
  _source_var._parameters.Br = 1.35;


  /* component source=Wiggler() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _origin_var._rotation_absolute, _source_var._rotation_absolute);
    rot_transpose(_origin_var._rotation_absolute, tr1);
    rot_mul(_source_var._rotation_absolute, tr1, _source_var._rotation_relative);
    _source_var._rotation_is_identity =  rot_test_identity(_source_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _source_var._position_absolute = coords_add(_origin_var._position_absolute, tc2);
    tc1 = coords_sub(_origin_var._position_absolute, _source_var._position_absolute);
    _source_var._position_relative = rot_apply(_source_var._rotation_absolute, tc1);
  } /* source=Wiggler() AT ROTATED */
  DEBUG_COMPONENT("source", _source_var._position_absolute, _source_var._rotation_absolute);
  instrument->_position_absolute[2] = _source_var._position_absolute;
  instrument->_position_relative[2] = _source_var._position_relative;
    _source_var._position_relative_is_zero =  coords_test_zero(_source_var._position_relative);
  instrument->counter_N[2]  = instrument->counter_P[2] = instrument->counter_P2[2] = 0;
  instrument->counter_AbsorbProp[2]= 0;
  return(0);
} /* _source_setpos */

/* component mon_src_e=Monitor_nD() SETTING, POSITION/ROTATION */
int _mon_src_e_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_mon_src_e_setpos] component mon_src_e=Monitor_nD() SETTING [/usr/share/mcxtrace/3.4-20240304/monitors/Monitor_nD.comp:242]");
  stracpy(_mon_src_e_var._name, "mon_src_e", 16384);
  stracpy(_mon_src_e_var._type, "Monitor_nD", 16384);
  _mon_src_e_var._index=3;
  int current_setpos_index = 3;
  if("" && strlen(""))
    stracpy(_mon_src_e_var._parameters.user1, "" ? "" : "", 16384);
  else 
  _mon_src_e_var._parameters.user1[0]='\0';
  if("" && strlen(""))
    stracpy(_mon_src_e_var._parameters.user2, "" ? "" : "", 16384);
  else 
  _mon_src_e_var._parameters.user2[0]='\0';
  if("" && strlen(""))
    stracpy(_mon_src_e_var._parameters.user3, "" ? "" : "", 16384);
  else 
  _mon_src_e_var._parameters.user3[0]='\0';
  _mon_src_e_var._parameters.xwidth = 1e-2;
  _mon_src_e_var._parameters.yheight = 1e-2;
  _mon_src_e_var._parameters.zdepth = 0;
  _mon_src_e_var._parameters.bins = 512;
  _mon_src_e_var._parameters.min = _instrument_var._parameters.E0 -1.1 * _instrument_var._parameters.dE;
  _mon_src_e_var._parameters.max = _instrument_var._parameters.E0 + 1.1 * _instrument_var._parameters.dE;
  _mon_src_e_var._parameters.restore_xray = 0;
  _mon_src_e_var._parameters.radius = 0;
  if("energy" && strlen("energy"))
    stracpy(_mon_src_e_var._parameters.options, "energy" ? "energy" : "", 16384);
  else 
  _mon_src_e_var._parameters.options[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_src_e_var._parameters.filename, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_src_e_var._parameters.filename[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_src_e_var._parameters.geometry, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_src_e_var._parameters.geometry[0]='\0';
  _mon_src_e_var._parameters.nowritefile = 0;
  if("NULL" && strlen("NULL"))
    stracpy(_mon_src_e_var._parameters.username1, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_src_e_var._parameters.username1[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_src_e_var._parameters.username2, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_src_e_var._parameters.username2[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_src_e_var._parameters.username3, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_src_e_var._parameters.username3[0]='\0';


  /* component mon_src_e=Monitor_nD() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _source_var._rotation_absolute, _mon_src_e_var._rotation_absolute);
    rot_transpose(_source_var._rotation_absolute, tr1);
    rot_mul(_mon_src_e_var._rotation_absolute, tr1, _mon_src_e_var._rotation_relative);
    _mon_src_e_var._rotation_is_identity =  rot_test_identity(_mon_src_e_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 17.5);
    rot_transpose(_source_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _mon_src_e_var._position_absolute = coords_add(_source_var._position_absolute, tc2);
    tc1 = coords_sub(_source_var._position_absolute, _mon_src_e_var._position_absolute);
    _mon_src_e_var._position_relative = rot_apply(_mon_src_e_var._rotation_absolute, tc1);
  } /* mon_src_e=Monitor_nD() AT ROTATED */
  DEBUG_COMPONENT("mon_src_e", _mon_src_e_var._position_absolute, _mon_src_e_var._rotation_absolute);
  instrument->_position_absolute[3] = _mon_src_e_var._position_absolute;
  instrument->_position_relative[3] = _mon_src_e_var._position_relative;
    _mon_src_e_var._position_relative_is_zero =  coords_test_zero(_mon_src_e_var._position_relative);
  instrument->counter_N[3]  = instrument->counter_P[3] = instrument->counter_P2[3] = 0;
  instrument->counter_AbsorbProp[3]= 0;
  return(0);
} /* _mon_src_e_setpos */

/* component mon_src_xy=Monitor_nD() SETTING, POSITION/ROTATION */
int _mon_src_xy_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_mon_src_xy_setpos] component mon_src_xy=Monitor_nD() SETTING [/usr/share/mcxtrace/3.4-20240304/monitors/Monitor_nD.comp:242]");
  stracpy(_mon_src_xy_var._name, "mon_src_xy", 16384);
  stracpy(_mon_src_xy_var._type, "Monitor_nD", 16384);
  _mon_src_xy_var._index=4;
  int current_setpos_index = 4;
  if("" && strlen(""))
    stracpy(_mon_src_xy_var._parameters.user1, "" ? "" : "", 16384);
  else 
  _mon_src_xy_var._parameters.user1[0]='\0';
  if("" && strlen(""))
    stracpy(_mon_src_xy_var._parameters.user2, "" ? "" : "", 16384);
  else 
  _mon_src_xy_var._parameters.user2[0]='\0';
  if("" && strlen(""))
    stracpy(_mon_src_xy_var._parameters.user3, "" ? "" : "", 16384);
  else 
  _mon_src_xy_var._parameters.user3[0]='\0';
  _mon_src_xy_var._parameters.xwidth = 1e-2;
  _mon_src_xy_var._parameters.yheight = 1e-2;
  _mon_src_xy_var._parameters.zdepth = 0;
  _mon_src_xy_var._parameters.bins = 128;
  _mon_src_xy_var._parameters.min = _instrument_var._parameters.E0 -1.1 * _instrument_var._parameters.dE;
  _mon_src_xy_var._parameters.max = _instrument_var._parameters.E0 + 1.1 * _instrument_var._parameters.dE;
  _mon_src_xy_var._parameters.restore_xray = 0;
  _mon_src_xy_var._parameters.radius = 0;
  if("x y, all auto" && strlen("x y, all auto"))
    stracpy(_mon_src_xy_var._parameters.options, "x y, all auto" ? "x y, all auto" : "", 16384);
  else 
  _mon_src_xy_var._parameters.options[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_src_xy_var._parameters.filename, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_src_xy_var._parameters.filename[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_src_xy_var._parameters.geometry, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_src_xy_var._parameters.geometry[0]='\0';
  _mon_src_xy_var._parameters.nowritefile = 0;
  if("NULL" && strlen("NULL"))
    stracpy(_mon_src_xy_var._parameters.username1, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_src_xy_var._parameters.username1[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_src_xy_var._parameters.username2, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_src_xy_var._parameters.username2[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_src_xy_var._parameters.username3, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_src_xy_var._parameters.username3[0]='\0';


  /* component mon_src_xy=Monitor_nD() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _mon_src_e_var._rotation_absolute, _mon_src_xy_var._rotation_absolute);
    rot_transpose(_mon_src_e_var._rotation_absolute, tr1);
    rot_mul(_mon_src_xy_var._rotation_absolute, tr1, _mon_src_xy_var._rotation_relative);
    _mon_src_xy_var._rotation_is_identity =  rot_test_identity(_mon_src_xy_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_mon_src_e_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _mon_src_xy_var._position_absolute = coords_add(_mon_src_e_var._position_absolute, tc2);
    tc1 = coords_sub(_mon_src_e_var._position_absolute, _mon_src_xy_var._position_absolute);
    _mon_src_xy_var._position_relative = rot_apply(_mon_src_xy_var._rotation_absolute, tc1);
  } /* mon_src_xy=Monitor_nD() AT ROTATED */
  DEBUG_COMPONENT("mon_src_xy", _mon_src_xy_var._position_absolute, _mon_src_xy_var._rotation_absolute);
  instrument->_position_absolute[4] = _mon_src_xy_var._position_absolute;
  instrument->_position_relative[4] = _mon_src_xy_var._position_relative;
    _mon_src_xy_var._position_relative_is_zero =  coords_test_zero(_mon_src_xy_var._position_relative);
  instrument->counter_N[4]  = instrument->counter_P[4] = instrument->counter_P2[4] = 0;
  instrument->counter_AbsorbProp[4]= 0;
  return(0);
} /* _mon_src_xy_setpos */

/* component DCM_location=Arm() SETTING, POSITION/ROTATION */
int _DCM_location_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_DCM_location_setpos] component DCM_location=Arm() SETTING [Arm:0]");
  stracpy(_DCM_location_var._name, "DCM_location", 16384);
  stracpy(_DCM_location_var._type, "Arm", 16384);
  _DCM_location_var._index=5;
  int current_setpos_index = 5;
  /* component DCM_location=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _source_var._rotation_absolute, _DCM_location_var._rotation_absolute);
    rot_transpose(_mon_src_xy_var._rotation_absolute, tr1);
    rot_mul(_DCM_location_var._rotation_absolute, tr1, _DCM_location_var._rotation_relative);
    _DCM_location_var._rotation_is_identity =  rot_test_identity(_DCM_location_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 20.5);
    rot_transpose(_source_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _DCM_location_var._position_absolute = coords_add(_source_var._position_absolute, tc2);
    tc1 = coords_sub(_mon_src_xy_var._position_absolute, _DCM_location_var._position_absolute);
    _DCM_location_var._position_relative = rot_apply(_DCM_location_var._rotation_absolute, tc1);
  } /* DCM_location=Arm() AT ROTATED */
  DEBUG_COMPONENT("DCM_location", _DCM_location_var._position_absolute, _DCM_location_var._rotation_absolute);
  instrument->_position_absolute[5] = _DCM_location_var._position_absolute;
  instrument->_position_relative[5] = _DCM_location_var._position_relative;
    _DCM_location_var._position_relative_is_zero =  coords_test_zero(_DCM_location_var._position_relative);
  instrument->counter_N[5]  = instrument->counter_P[5] = instrument->counter_P2[5] = 0;
  instrument->counter_AbsorbProp[5]= 0;
  return(0);
} /* _DCM_location_setpos */

/* component dcm_xtal0=Bragg_crystal() SETTING, POSITION/ROTATION */
int _dcm_xtal0_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_dcm_xtal0_setpos] component dcm_xtal0=Bragg_crystal() SETTING [/usr/share/mcxtrace/3.4-20240304/optics/Bragg_crystal.comp:105]");
  stracpy(_dcm_xtal0_var._name, "dcm_xtal0", 16384);
  stracpy(_dcm_xtal0_var._type, "Bragg_crystal", 16384);
  _dcm_xtal0_var._index=6;
  int current_setpos_index = 6;
  _dcm_xtal0_var._parameters.length = 0.04;
  _dcm_xtal0_var._parameters.width = 0.04;
  _dcm_xtal0_var._parameters.V = 160.1826;
  if("FormFactors.txt" && strlen("FormFactors.txt"))
    stracpy(_dcm_xtal0_var._parameters.form_factors, "FormFactors.txt" ? "FormFactors.txt" : "", 16384);
  else 
  _dcm_xtal0_var._parameters.form_factors[0]='\0';
  if("Si.txt" && strlen("Si.txt"))
    stracpy(_dcm_xtal0_var._parameters.material, "Si.txt" ? "Si.txt" : "", 16384);
  else 
  _dcm_xtal0_var._parameters.material[0]='\0';
  _dcm_xtal0_var._parameters.alpha = 0.0;
  _dcm_xtal0_var._parameters.R0 = 0;
  _dcm_xtal0_var._parameters.debye_waller_B = 0.4632;
  _dcm_xtal0_var._parameters.crystal_type = 1;
  _dcm_xtal0_var._parameters.h = 1;
  _dcm_xtal0_var._parameters.k = 1;
  _dcm_xtal0_var._parameters.l = 1;
  _dcm_xtal0_var._parameters.structure_factor_scale_r = 0.0;
  _dcm_xtal0_var._parameters.structure_factor_scale_i = 0.0;


  /* component dcm_xtal0=Bragg_crystal() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (- _instrument_var._parameters.dcm_theta)*DEG2RAD, (0)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _DCM_location_var._rotation_absolute, _dcm_xtal0_var._rotation_absolute);
    rot_transpose(_mon_src_xy_var._rotation_absolute, tr1);
    rot_mul(_dcm_xtal0_var._rotation_absolute, tr1, _dcm_xtal0_var._rotation_relative);
    _dcm_xtal0_var._rotation_is_identity =  rot_test_identity(_dcm_xtal0_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_DCM_location_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _dcm_xtal0_var._position_absolute = coords_add(_DCM_location_var._position_absolute, tc2);
    tc1 = coords_sub(_mon_src_xy_var._position_absolute, _dcm_xtal0_var._position_absolute);
    _dcm_xtal0_var._position_relative = rot_apply(_dcm_xtal0_var._rotation_absolute, tc1);
  } /* dcm_xtal0=Bragg_crystal() AT ROTATED */
  DEBUG_COMPONENT("dcm_xtal0", _dcm_xtal0_var._position_absolute, _dcm_xtal0_var._rotation_absolute);
  instrument->_position_absolute[6] = _dcm_xtal0_var._position_absolute;
  instrument->_position_relative[6] = _dcm_xtal0_var._position_relative;
    _dcm_xtal0_var._position_relative_is_zero =  coords_test_zero(_dcm_xtal0_var._position_relative);
  instrument->counter_N[6]  = instrument->counter_P[6] = instrument->counter_P2[6] = 0;
  instrument->counter_AbsorbProp[6]= 0;
  return(0);
} /* _dcm_xtal0_setpos */

/* component dcm0=Arm() SETTING, POSITION/ROTATION */
int _dcm0_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_dcm0_setpos] component dcm0=Arm() SETTING [Arm:0]");
  stracpy(_dcm0_var._name, "dcm0", 16384);
  stracpy(_dcm0_var._type, "Arm", 16384);
  _dcm0_var._index=7;
  int current_setpos_index = 7;
  /* component dcm0=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (- _instrument_var._parameters.dcm_theta)*DEG2RAD, (0)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _dcm_xtal0_var._rotation_absolute, _dcm0_var._rotation_absolute);
    rot_transpose(_dcm_xtal0_var._rotation_absolute, tr1);
    rot_mul(_dcm0_var._rotation_absolute, tr1, _dcm0_var._rotation_relative);
    _dcm0_var._rotation_is_identity =  rot_test_identity(_dcm0_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_dcm_xtal0_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _dcm0_var._position_absolute = coords_add(_dcm_xtal0_var._position_absolute, tc2);
    tc1 = coords_sub(_dcm_xtal0_var._position_absolute, _dcm0_var._position_absolute);
    _dcm0_var._position_relative = rot_apply(_dcm0_var._rotation_absolute, tc1);
  } /* dcm0=Arm() AT ROTATED */
  DEBUG_COMPONENT("dcm0", _dcm0_var._position_absolute, _dcm0_var._rotation_absolute);
  instrument->_position_absolute[7] = _dcm0_var._position_absolute;
  instrument->_position_relative[7] = _dcm0_var._position_relative;
    _dcm0_var._position_relative_is_zero =  coords_test_zero(_dcm0_var._position_relative);
  instrument->counter_N[7]  = instrument->counter_P[7] = instrument->counter_P2[7] = 0;
  instrument->counter_AbsorbProp[7]= 0;
  return(0);
} /* _dcm0_setpos */

/* component dcm_xtal1=Bragg_crystal() SETTING, POSITION/ROTATION */
int _dcm_xtal1_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_dcm_xtal1_setpos] component dcm_xtal1=Bragg_crystal() SETTING [/usr/share/mcxtrace/3.4-20240304/optics/Bragg_crystal.comp:105]");
  stracpy(_dcm_xtal1_var._name, "dcm_xtal1", 16384);
  stracpy(_dcm_xtal1_var._type, "Bragg_crystal", 16384);
  _dcm_xtal1_var._index=8;
  int current_setpos_index = 8;
  _dcm_xtal1_var._parameters.length = 0.04;
  _dcm_xtal1_var._parameters.width = 0.04;
  _dcm_xtal1_var._parameters.V = 160.1826;
  if("FormFactors.txt" && strlen("FormFactors.txt"))
    stracpy(_dcm_xtal1_var._parameters.form_factors, "FormFactors.txt" ? "FormFactors.txt" : "", 16384);
  else 
  _dcm_xtal1_var._parameters.form_factors[0]='\0';
  if("Si.txt" && strlen("Si.txt"))
    stracpy(_dcm_xtal1_var._parameters.material, "Si.txt" ? "Si.txt" : "", 16384);
  else 
  _dcm_xtal1_var._parameters.material[0]='\0';
  _dcm_xtal1_var._parameters.alpha = 0.0;
  _dcm_xtal1_var._parameters.R0 = 0;
  _dcm_xtal1_var._parameters.debye_waller_B = 0.4632;
  _dcm_xtal1_var._parameters.crystal_type = 1;
  _dcm_xtal1_var._parameters.h = 1;
  _dcm_xtal1_var._parameters.k = 1;
  _dcm_xtal1_var._parameters.l = 1;
  _dcm_xtal1_var._parameters.structure_factor_scale_r = 0.0;
  _dcm_xtal1_var._parameters.structure_factor_scale_i = 0.0;


  /* component dcm_xtal1=Bragg_crystal() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (_instrument_var._parameters.dcm_theta)*DEG2RAD, (0)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _dcm0_var._rotation_absolute, _dcm_xtal1_var._rotation_absolute);
    rot_transpose(_dcm_xtal0_var._rotation_absolute, tr1);
    rot_mul(_dcm_xtal1_var._rotation_absolute, tr1, _dcm_xtal1_var._rotation_relative);
    _dcm_xtal1_var._rotation_is_identity =  rot_test_identity(_dcm_xtal1_var._rotation_relative);
    tc1 = coords_set(
      0, dcm_gap, _instrument_var._parameters.dcm_theta ? dcm_gap / tan ( _instrument_var._parameters.dcm_theta * DEG2RAD ) : 0);
    rot_transpose(_dcm_xtal0_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _dcm_xtal1_var._position_absolute = coords_add(_dcm_xtal0_var._position_absolute, tc2);
    tc1 = coords_sub(_dcm_xtal0_var._position_absolute, _dcm_xtal1_var._position_absolute);
    _dcm_xtal1_var._position_relative = rot_apply(_dcm_xtal1_var._rotation_absolute, tc1);
  } /* dcm_xtal1=Bragg_crystal() AT ROTATED */
  DEBUG_COMPONENT("dcm_xtal1", _dcm_xtal1_var._position_absolute, _dcm_xtal1_var._rotation_absolute);
  instrument->_position_absolute[8] = _dcm_xtal1_var._position_absolute;
  instrument->_position_relative[8] = _dcm_xtal1_var._position_relative;
    _dcm_xtal1_var._position_relative_is_zero =  coords_test_zero(_dcm_xtal1_var._position_relative);
  instrument->counter_N[8]  = instrument->counter_P[8] = instrument->counter_P2[8] = 0;
  instrument->counter_AbsorbProp[8]= 0;
  return(0);
} /* _dcm_xtal1_setpos */

/* component dcm1=Arm() SETTING, POSITION/ROTATION */
int _dcm1_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_dcm1_setpos] component dcm1=Arm() SETTING [Arm:0]");
  stracpy(_dcm1_var._name, "dcm1", 16384);
  stracpy(_dcm1_var._type, "Arm", 16384);
  _dcm1_var._index=9;
  int current_setpos_index = 9;
  /* component dcm1=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (_instrument_var._parameters.dcm_theta)*DEG2RAD, (0)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _dcm_xtal1_var._rotation_absolute, _dcm1_var._rotation_absolute);
    rot_transpose(_dcm_xtal1_var._rotation_absolute, tr1);
    rot_mul(_dcm1_var._rotation_absolute, tr1, _dcm1_var._rotation_relative);
    _dcm1_var._rotation_is_identity =  rot_test_identity(_dcm1_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_dcm_xtal1_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _dcm1_var._position_absolute = coords_add(_dcm_xtal1_var._position_absolute, tc2);
    tc1 = coords_sub(_dcm_xtal1_var._position_absolute, _dcm1_var._position_absolute);
    _dcm1_var._position_relative = rot_apply(_dcm1_var._rotation_absolute, tc1);
  } /* dcm1=Arm() AT ROTATED */
  DEBUG_COMPONENT("dcm1", _dcm1_var._position_absolute, _dcm1_var._rotation_absolute);
  instrument->_position_absolute[9] = _dcm1_var._position_absolute;
  instrument->_position_relative[9] = _dcm1_var._position_relative;
    _dcm1_var._position_relative_is_zero =  coords_test_zero(_dcm1_var._position_relative);
  instrument->counter_N[9]  = instrument->counter_P[9] = instrument->counter_P2[9] = 0;
  instrument->counter_AbsorbProp[9]= 0;
  return(0);
} /* _dcm1_setpos */

/* component mon_dcm_e=Monitor_nD() SETTING, POSITION/ROTATION */
int _mon_dcm_e_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_mon_dcm_e_setpos] component mon_dcm_e=Monitor_nD() SETTING [/usr/share/mcxtrace/3.4-20240304/monitors/Monitor_nD.comp:242]");
  stracpy(_mon_dcm_e_var._name, "mon_dcm_e", 16384);
  stracpy(_mon_dcm_e_var._type, "Monitor_nD", 16384);
  _mon_dcm_e_var._index=10;
  int current_setpos_index = 10;
  if("" && strlen(""))
    stracpy(_mon_dcm_e_var._parameters.user1, "" ? "" : "", 16384);
  else 
  _mon_dcm_e_var._parameters.user1[0]='\0';
  if("" && strlen(""))
    stracpy(_mon_dcm_e_var._parameters.user2, "" ? "" : "", 16384);
  else 
  _mon_dcm_e_var._parameters.user2[0]='\0';
  if("" && strlen(""))
    stracpy(_mon_dcm_e_var._parameters.user3, "" ? "" : "", 16384);
  else 
  _mon_dcm_e_var._parameters.user3[0]='\0';
  _mon_dcm_e_var._parameters.xwidth = 1e-2;
  _mon_dcm_e_var._parameters.yheight = 1e-2;
  _mon_dcm_e_var._parameters.zdepth = 0;
  _mon_dcm_e_var._parameters.bins = 512;
  _mon_dcm_e_var._parameters.min = _instrument_var._parameters.E0 -1.1 * _instrument_var._parameters.dE;
  _mon_dcm_e_var._parameters.max = _instrument_var._parameters.E0 + 1.1 * _instrument_var._parameters.dE;
  _mon_dcm_e_var._parameters.restore_xray = 0;
  _mon_dcm_e_var._parameters.radius = 0;
  if("energy" && strlen("energy"))
    stracpy(_mon_dcm_e_var._parameters.options, "energy" ? "energy" : "", 16384);
  else 
  _mon_dcm_e_var._parameters.options[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_dcm_e_var._parameters.filename, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_dcm_e_var._parameters.filename[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_dcm_e_var._parameters.geometry, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_dcm_e_var._parameters.geometry[0]='\0';
  _mon_dcm_e_var._parameters.nowritefile = 0;
  if("NULL" && strlen("NULL"))
    stracpy(_mon_dcm_e_var._parameters.username1, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_dcm_e_var._parameters.username1[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_dcm_e_var._parameters.username2, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_dcm_e_var._parameters.username2[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_dcm_e_var._parameters.username3, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_dcm_e_var._parameters.username3[0]='\0';


  /* component mon_dcm_e=Monitor_nD() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _dcm1_var._rotation_absolute, _mon_dcm_e_var._rotation_absolute);
    rot_transpose(_dcm_xtal1_var._rotation_absolute, tr1);
    rot_mul(_mon_dcm_e_var._rotation_absolute, tr1, _mon_dcm_e_var._rotation_relative);
    _mon_dcm_e_var._rotation_is_identity =  rot_test_identity(_mon_dcm_e_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0.5);
    rot_transpose(_dcm1_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _mon_dcm_e_var._position_absolute = coords_add(_dcm1_var._position_absolute, tc2);
    tc1 = coords_sub(_dcm_xtal1_var._position_absolute, _mon_dcm_e_var._position_absolute);
    _mon_dcm_e_var._position_relative = rot_apply(_mon_dcm_e_var._rotation_absolute, tc1);
  } /* mon_dcm_e=Monitor_nD() AT ROTATED */
  DEBUG_COMPONENT("mon_dcm_e", _mon_dcm_e_var._position_absolute, _mon_dcm_e_var._rotation_absolute);
  instrument->_position_absolute[10] = _mon_dcm_e_var._position_absolute;
  instrument->_position_relative[10] = _mon_dcm_e_var._position_relative;
    _mon_dcm_e_var._position_relative_is_zero =  coords_test_zero(_mon_dcm_e_var._position_relative);
  instrument->counter_N[10]  = instrument->counter_P[10] = instrument->counter_P2[10] = 0;
  instrument->counter_AbsorbProp[10]= 0;
  return(0);
} /* _mon_dcm_e_setpos */

/* component mon_dcm_xy=Monitor_nD() SETTING, POSITION/ROTATION */
int _mon_dcm_xy_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_mon_dcm_xy_setpos] component mon_dcm_xy=Monitor_nD() SETTING [/usr/share/mcxtrace/3.4-20240304/monitors/Monitor_nD.comp:242]");
  stracpy(_mon_dcm_xy_var._name, "mon_dcm_xy", 16384);
  stracpy(_mon_dcm_xy_var._type, "Monitor_nD", 16384);
  _mon_dcm_xy_var._index=11;
  int current_setpos_index = 11;
  if("" && strlen(""))
    stracpy(_mon_dcm_xy_var._parameters.user1, "" ? "" : "", 16384);
  else 
  _mon_dcm_xy_var._parameters.user1[0]='\0';
  if("" && strlen(""))
    stracpy(_mon_dcm_xy_var._parameters.user2, "" ? "" : "", 16384);
  else 
  _mon_dcm_xy_var._parameters.user2[0]='\0';
  if("" && strlen(""))
    stracpy(_mon_dcm_xy_var._parameters.user3, "" ? "" : "", 16384);
  else 
  _mon_dcm_xy_var._parameters.user3[0]='\0';
  _mon_dcm_xy_var._parameters.xwidth = 1e-2;
  _mon_dcm_xy_var._parameters.yheight = 1e-2;
  _mon_dcm_xy_var._parameters.zdepth = 0;
  _mon_dcm_xy_var._parameters.bins = 128;
  _mon_dcm_xy_var._parameters.min = _instrument_var._parameters.E0 -1.1 * _instrument_var._parameters.dE;
  _mon_dcm_xy_var._parameters.max = _instrument_var._parameters.E0 + 1.1 * _instrument_var._parameters.dE;
  _mon_dcm_xy_var._parameters.restore_xray = 0;
  _mon_dcm_xy_var._parameters.radius = 0;
  if("x y, all auto" && strlen("x y, all auto"))
    stracpy(_mon_dcm_xy_var._parameters.options, "x y, all auto" ? "x y, all auto" : "", 16384);
  else 
  _mon_dcm_xy_var._parameters.options[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_dcm_xy_var._parameters.filename, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_dcm_xy_var._parameters.filename[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_dcm_xy_var._parameters.geometry, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_dcm_xy_var._parameters.geometry[0]='\0';
  _mon_dcm_xy_var._parameters.nowritefile = 0;
  if("NULL" && strlen("NULL"))
    stracpy(_mon_dcm_xy_var._parameters.username1, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_dcm_xy_var._parameters.username1[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_dcm_xy_var._parameters.username2, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_dcm_xy_var._parameters.username2[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_dcm_xy_var._parameters.username3, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_dcm_xy_var._parameters.username3[0]='\0';


  /* component mon_dcm_xy=Monitor_nD() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _mon_dcm_e_var._rotation_absolute, _mon_dcm_xy_var._rotation_absolute);
    rot_transpose(_mon_dcm_e_var._rotation_absolute, tr1);
    rot_mul(_mon_dcm_xy_var._rotation_absolute, tr1, _mon_dcm_xy_var._rotation_relative);
    _mon_dcm_xy_var._rotation_is_identity =  rot_test_identity(_mon_dcm_xy_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_mon_dcm_e_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _mon_dcm_xy_var._position_absolute = coords_add(_mon_dcm_e_var._position_absolute, tc2);
    tc1 = coords_sub(_mon_dcm_e_var._position_absolute, _mon_dcm_xy_var._position_absolute);
    _mon_dcm_xy_var._position_relative = rot_apply(_mon_dcm_xy_var._rotation_absolute, tc1);
  } /* mon_dcm_xy=Monitor_nD() AT ROTATED */
  DEBUG_COMPONENT("mon_dcm_xy", _mon_dcm_xy_var._position_absolute, _mon_dcm_xy_var._rotation_absolute);
  instrument->_position_absolute[11] = _mon_dcm_xy_var._position_absolute;
  instrument->_position_relative[11] = _mon_dcm_xy_var._position_relative;
    _mon_dcm_xy_var._position_relative_is_zero =  coords_test_zero(_mon_dcm_xy_var._position_relative);
  instrument->counter_N[11]  = instrument->counter_P[11] = instrument->counter_P2[11] = 0;
  instrument->counter_AbsorbProp[11]= 0;
  return(0);
} /* _mon_dcm_xy_setpos */

/* component slit=Slit() SETTING, POSITION/ROTATION */
int _slit_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_slit_setpos] component slit=Slit() SETTING [/usr/share/mcxtrace/3.4-20240304/optics/Slit.comp:59]");
  stracpy(_slit_var._name, "slit", 16384);
  stracpy(_slit_var._type, "Slit", 16384);
  _slit_var._index=12;
  int current_setpos_index = 12;
  _slit_var._parameters.xmin = 0;
  _slit_var._parameters.xmax = 0;
  _slit_var._parameters.ymin = 0;
  _slit_var._parameters.ymax = 0;
  _slit_var._parameters.radius = 0;
  _slit_var._parameters.xwidth = 17e-3;
  _slit_var._parameters.yheight = 6e-3;
  _slit_var._parameters.dist = 0;
  _slit_var._parameters.focus_xw = 0;
  _slit_var._parameters.focus_yh = 0;
  _slit_var._parameters.focus_x0 = 0;
  _slit_var._parameters.focus_y0 = 0;

  /* component slit=Slit() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _mon_dcm_xy_var._rotation_absolute, _slit_var._rotation_absolute);
    rot_transpose(_mon_dcm_xy_var._rotation_absolute, tr1);
    rot_mul(_slit_var._rotation_absolute, tr1, _slit_var._rotation_relative);
    _slit_var._rotation_is_identity =  rot_test_identity(_slit_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_mon_dcm_xy_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _slit_var._position_absolute = coords_add(_mon_dcm_xy_var._position_absolute, tc2);
    tc1 = coords_sub(_mon_dcm_xy_var._position_absolute, _slit_var._position_absolute);
    _slit_var._position_relative = rot_apply(_slit_var._rotation_absolute, tc1);
  } /* slit=Slit() AT ROTATED */
  DEBUG_COMPONENT("slit", _slit_var._position_absolute, _slit_var._rotation_absolute);
  instrument->_position_absolute[12] = _slit_var._position_absolute;
  instrument->_position_relative[12] = _slit_var._position_relative;
    _slit_var._position_relative_is_zero =  coords_test_zero(_slit_var._position_relative);
  instrument->counter_N[12]  = instrument->counter_P[12] = instrument->counter_P2[12] = 0;
  instrument->counter_AbsorbProp[12]= 0;
  return(0);
} /* _slit_setpos */

/* component sample_stage=Arm() SETTING, POSITION/ROTATION */
int _sample_stage_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_sample_stage_setpos] component sample_stage=Arm() SETTING [Arm:0]");
  stracpy(_sample_stage_var._name, "sample_stage", 16384);
  stracpy(_sample_stage_var._type, "Arm", 16384);
  _sample_stage_var._index=13;
  int current_setpos_index = 13;
  /* component sample_stage=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _slit_var._rotation_absolute, _sample_stage_var._rotation_absolute);
    rot_transpose(_slit_var._rotation_absolute, tr1);
    rot_mul(_sample_stage_var._rotation_absolute, tr1, _sample_stage_var._rotation_relative);
    _sample_stage_var._rotation_is_identity =  rot_test_identity(_sample_stage_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0.5);
    rot_transpose(_slit_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _sample_stage_var._position_absolute = coords_add(_slit_var._position_absolute, tc2);
    tc1 = coords_sub(_slit_var._position_absolute, _sample_stage_var._position_absolute);
    _sample_stage_var._position_relative = rot_apply(_sample_stage_var._rotation_absolute, tc1);
  } /* sample_stage=Arm() AT ROTATED */
  DEBUG_COMPONENT("sample_stage", _sample_stage_var._position_absolute, _sample_stage_var._rotation_absolute);
  instrument->_position_absolute[13] = _sample_stage_var._position_absolute;
  instrument->_position_relative[13] = _sample_stage_var._position_relative;
    _sample_stage_var._position_relative_is_zero =  coords_test_zero(_sample_stage_var._position_relative);
  instrument->counter_N[13]  = instrument->counter_P[13] = instrument->counter_P2[13] = 0;
  instrument->counter_AbsorbProp[13]= 0;
  return(0);
} /* _sample_stage_setpos */

/* component sample=Fluorescence() SETTING, POSITION/ROTATION */
int _sample_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_sample_setpos] component sample=Fluorescence() SETTING [/usr/share/mcxtrace/3.4-20240304/samples/Fluorescence.comp:401]");
  stracpy(_sample_var._name, "sample", 16384);
  stracpy(_sample_var._type, "Fluorescence", 16384);
  _sample_var._index=14;
  int current_setpos_index = 14;
  if(_instrument_var._parameters.sample_geometry && strlen(_instrument_var._parameters.sample_geometry))
    stracpy(_sample_var._parameters.geometry, _instrument_var._parameters.sample_geometry ? _instrument_var._parameters.sample_geometry : "", 16384);
  else 
  _sample_var._parameters.geometry[0]='\0';
  _sample_var._parameters.radius = 0;
  _sample_var._parameters.thickness = 0;
  _sample_var._parameters.xwidth = 20e-3;
  _sample_var._parameters.yheight = 10e-3;
  _sample_var._parameters.zdepth = 1e-3;
  _sample_var._parameters.concentric = 0;
  if(_instrument_var._parameters.sample_material && strlen(_instrument_var._parameters.sample_material))
    stracpy(_sample_var._parameters.material, _instrument_var._parameters.sample_material ? _instrument_var._parameters.sample_material : "", 16384);
  else 
  _sample_var._parameters.material[0]='\0';
  _sample_var._parameters.packing_factor = 0;
  _sample_var._parameters.rho = 0;
  _sample_var._parameters.density = 0;
  _sample_var._parameters.weight = 0;
  _sample_var._parameters.p_interact = 0.8;
  _sample_var._parameters.target_x = 0;
  _sample_var._parameters.target_y = 0;
  _sample_var._parameters.target_z = 0;
  _sample_var._parameters.focus_r = 0;
  _sample_var._parameters.focus_xw = 0;
  _sample_var._parameters.focus_yh = 0;
  _sample_var._parameters.focus_aw = 90;
  _sample_var._parameters.focus_ah = 5;
  _sample_var._parameters.target_index = 3;
  _sample_var._parameters.flag_compton = 1;
  _sample_var._parameters.flag_rayleigh = 1;
  _sample_var._parameters.flag_lorentzian = 1;
  _sample_var._parameters.order = 1;


  /* component sample=Fluorescence() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (_instrument_var._parameters.sample_theta)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _sample_stage_var._rotation_absolute, _sample_var._rotation_absolute);
    rot_transpose(_slit_var._rotation_absolute, tr1);
    rot_mul(_sample_var._rotation_absolute, tr1, _sample_var._rotation_relative);
    _sample_var._rotation_is_identity =  rot_test_identity(_sample_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_sample_stage_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _sample_var._position_absolute = coords_add(_sample_stage_var._position_absolute, tc2);
    tc1 = coords_sub(_slit_var._position_absolute, _sample_var._position_absolute);
    _sample_var._position_relative = rot_apply(_sample_var._rotation_absolute, tc1);
  } /* sample=Fluorescence() AT ROTATED */
  DEBUG_COMPONENT("sample", _sample_var._position_absolute, _sample_var._rotation_absolute);
  instrument->_position_absolute[14] = _sample_var._position_absolute;
  instrument->_position_relative[14] = _sample_var._position_relative;
    _sample_var._position_relative_is_zero =  coords_test_zero(_sample_var._position_relative);
  instrument->counter_N[14]  = instrument->counter_P[14] = instrument->counter_P2[14] = 0;
  instrument->counter_AbsorbProp[14]= 0;
  return(0);
} /* _sample_setpos */

/* component fluo_holder=Arm() SETTING, POSITION/ROTATION */
int _fluo_holder_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_fluo_holder_setpos] component fluo_holder=Arm() SETTING [Arm:0]");
  stracpy(_fluo_holder_var._name, "fluo_holder", 16384);
  stracpy(_fluo_holder_var._type, "Arm", 16384);
  _fluo_holder_var._index=15;
  int current_setpos_index = 15;
  /* component fluo_holder=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (30)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _sample_stage_var._rotation_absolute, _fluo_holder_var._rotation_absolute);
    rot_transpose(_sample_var._rotation_absolute, tr1);
    rot_mul(_fluo_holder_var._rotation_absolute, tr1, _fluo_holder_var._rotation_relative);
    _fluo_holder_var._rotation_is_identity =  rot_test_identity(_fluo_holder_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_sample_stage_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _fluo_holder_var._position_absolute = coords_add(_sample_stage_var._position_absolute, tc2);
    tc1 = coords_sub(_sample_var._position_absolute, _fluo_holder_var._position_absolute);
    _fluo_holder_var._position_relative = rot_apply(_fluo_holder_var._rotation_absolute, tc1);
  } /* fluo_holder=Arm() AT ROTATED */
  DEBUG_COMPONENT("fluo_holder", _fluo_holder_var._position_absolute, _fluo_holder_var._rotation_absolute);
  instrument->_position_absolute[15] = _fluo_holder_var._position_absolute;
  instrument->_position_relative[15] = _fluo_holder_var._position_relative;
    _fluo_holder_var._position_relative_is_zero =  coords_test_zero(_fluo_holder_var._position_relative);
  instrument->counter_N[15]  = instrument->counter_P[15] = instrument->counter_P2[15] = 0;
  instrument->counter_AbsorbProp[15]= 0;
  return(0);
} /* _fluo_holder_setpos */

/* component mon_spl_fluo=Monitor_nD() SETTING, POSITION/ROTATION */
int _mon_spl_fluo_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_mon_spl_fluo_setpos] component mon_spl_fluo=Monitor_nD() SETTING [/usr/share/mcxtrace/3.4-20240304/monitors/Monitor_nD.comp:242]");
  stracpy(_mon_spl_fluo_var._name, "mon_spl_fluo", 16384);
  stracpy(_mon_spl_fluo_var._type, "Monitor_nD", 16384);
  _mon_spl_fluo_var._index=16;
  int current_setpos_index = 16;
  if("" && strlen(""))
    stracpy(_mon_spl_fluo_var._parameters.user1, "" ? "" : "", 16384);
  else 
  _mon_spl_fluo_var._parameters.user1[0]='\0';
  if("" && strlen(""))
    stracpy(_mon_spl_fluo_var._parameters.user2, "" ? "" : "", 16384);
  else 
  _mon_spl_fluo_var._parameters.user2[0]='\0';
  if("" && strlen(""))
    stracpy(_mon_spl_fluo_var._parameters.user3, "" ? "" : "", 16384);
  else 
  _mon_spl_fluo_var._parameters.user3[0]='\0';
  _mon_spl_fluo_var._parameters.xwidth = 0.01;
  _mon_spl_fluo_var._parameters.yheight = 0.01;
  _mon_spl_fluo_var._parameters.zdepth = 0;
  _mon_spl_fluo_var._parameters.bins = 1000;
  _mon_spl_fluo_var._parameters.min = 0;
  _mon_spl_fluo_var._parameters.max = _instrument_var._parameters.E0 + _instrument_var._parameters.dE * 1.05;
  _mon_spl_fluo_var._parameters.restore_xray = 0;
  _mon_spl_fluo_var._parameters.radius = 0;
  if("energy" && strlen("energy"))
    stracpy(_mon_spl_fluo_var._parameters.options, "energy" ? "energy" : "", 16384);
  else 
  _mon_spl_fluo_var._parameters.options[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_fluo_var._parameters.filename, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_fluo_var._parameters.filename[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_fluo_var._parameters.geometry, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_fluo_var._parameters.geometry[0]='\0';
  _mon_spl_fluo_var._parameters.nowritefile = 0;
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_fluo_var._parameters.username1, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_fluo_var._parameters.username1[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_fluo_var._parameters.username2, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_fluo_var._parameters.username2[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_fluo_var._parameters.username3, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_fluo_var._parameters.username3[0]='\0';


  /* component mon_spl_fluo=Monitor_nD() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _fluo_holder_var._rotation_absolute, _mon_spl_fluo_var._rotation_absolute);
    rot_transpose(_sample_var._rotation_absolute, tr1);
    rot_mul(_mon_spl_fluo_var._rotation_absolute, tr1, _mon_spl_fluo_var._rotation_relative);
    _mon_spl_fluo_var._rotation_is_identity =  rot_test_identity(_mon_spl_fluo_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0.1);
    rot_transpose(_fluo_holder_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _mon_spl_fluo_var._position_absolute = coords_add(_fluo_holder_var._position_absolute, tc2);
    tc1 = coords_sub(_sample_var._position_absolute, _mon_spl_fluo_var._position_absolute);
    _mon_spl_fluo_var._position_relative = rot_apply(_mon_spl_fluo_var._rotation_absolute, tc1);
  } /* mon_spl_fluo=Monitor_nD() AT ROTATED */
  DEBUG_COMPONENT("mon_spl_fluo", _mon_spl_fluo_var._position_absolute, _mon_spl_fluo_var._rotation_absolute);
  instrument->_position_absolute[16] = _mon_spl_fluo_var._position_absolute;
  instrument->_position_relative[16] = _mon_spl_fluo_var._position_relative;
    _mon_spl_fluo_var._position_relative_is_zero =  coords_test_zero(_mon_spl_fluo_var._position_relative);
  instrument->counter_N[16]  = instrument->counter_P[16] = instrument->counter_P2[16] = 0;
  instrument->counter_AbsorbProp[16]= 0;
  return(0);
} /* _mon_spl_fluo_setpos */

/* component mon_spl_e=Monitor_nD() SETTING, POSITION/ROTATION */
int _mon_spl_e_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_mon_spl_e_setpos] component mon_spl_e=Monitor_nD() SETTING [/usr/share/mcxtrace/3.4-20240304/monitors/Monitor_nD.comp:242]");
  stracpy(_mon_spl_e_var._name, "mon_spl_e", 16384);
  stracpy(_mon_spl_e_var._type, "Monitor_nD", 16384);
  _mon_spl_e_var._index=17;
  int current_setpos_index = 17;
  if("" && strlen(""))
    stracpy(_mon_spl_e_var._parameters.user1, "" ? "" : "", 16384);
  else 
  _mon_spl_e_var._parameters.user1[0]='\0';
  if("" && strlen(""))
    stracpy(_mon_spl_e_var._parameters.user2, "" ? "" : "", 16384);
  else 
  _mon_spl_e_var._parameters.user2[0]='\0';
  if("" && strlen(""))
    stracpy(_mon_spl_e_var._parameters.user3, "" ? "" : "", 16384);
  else 
  _mon_spl_e_var._parameters.user3[0]='\0';
  _mon_spl_e_var._parameters.xwidth = 1e-2;
  _mon_spl_e_var._parameters.yheight = 1e-2;
  _mon_spl_e_var._parameters.zdepth = 0;
  _mon_spl_e_var._parameters.bins = 512;
  _mon_spl_e_var._parameters.min = _instrument_var._parameters.E0 -1.1 * _instrument_var._parameters.dE;
  _mon_spl_e_var._parameters.max = _instrument_var._parameters.E0 + 1.1 * _instrument_var._parameters.dE;
  _mon_spl_e_var._parameters.restore_xray = 0;
  _mon_spl_e_var._parameters.radius = 0;
  if("energy" && strlen("energy"))
    stracpy(_mon_spl_e_var._parameters.options, "energy" ? "energy" : "", 16384);
  else 
  _mon_spl_e_var._parameters.options[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_e_var._parameters.filename, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_e_var._parameters.filename[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_e_var._parameters.geometry, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_e_var._parameters.geometry[0]='\0';
  _mon_spl_e_var._parameters.nowritefile = 0;
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_e_var._parameters.username1, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_e_var._parameters.username1[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_e_var._parameters.username2, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_e_var._parameters.username2[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_e_var._parameters.username3, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_e_var._parameters.username3[0]='\0';


  /* component mon_spl_e=Monitor_nD() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _sample_stage_var._rotation_absolute, _mon_spl_e_var._rotation_absolute);
    rot_transpose(_mon_spl_fluo_var._rotation_absolute, tr1);
    rot_mul(_mon_spl_e_var._rotation_absolute, tr1, _mon_spl_e_var._rotation_relative);
    _mon_spl_e_var._rotation_is_identity =  rot_test_identity(_mon_spl_e_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0.2);
    rot_transpose(_sample_stage_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _mon_spl_e_var._position_absolute = coords_add(_sample_stage_var._position_absolute, tc2);
    tc1 = coords_sub(_mon_spl_fluo_var._position_absolute, _mon_spl_e_var._position_absolute);
    _mon_spl_e_var._position_relative = rot_apply(_mon_spl_e_var._rotation_absolute, tc1);
  } /* mon_spl_e=Monitor_nD() AT ROTATED */
  DEBUG_COMPONENT("mon_spl_e", _mon_spl_e_var._position_absolute, _mon_spl_e_var._rotation_absolute);
  instrument->_position_absolute[17] = _mon_spl_e_var._position_absolute;
  instrument->_position_relative[17] = _mon_spl_e_var._position_relative;
    _mon_spl_e_var._position_relative_is_zero =  coords_test_zero(_mon_spl_e_var._position_relative);
  instrument->counter_N[17]  = instrument->counter_P[17] = instrument->counter_P2[17] = 0;
  instrument->counter_AbsorbProp[17]= 0;
  return(0);
} /* _mon_spl_e_setpos */

/* component mon_spl_xy=Monitor_nD() SETTING, POSITION/ROTATION */
int _mon_spl_xy_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_mon_spl_xy_setpos] component mon_spl_xy=Monitor_nD() SETTING [/usr/share/mcxtrace/3.4-20240304/monitors/Monitor_nD.comp:242]");
  stracpy(_mon_spl_xy_var._name, "mon_spl_xy", 16384);
  stracpy(_mon_spl_xy_var._type, "Monitor_nD", 16384);
  _mon_spl_xy_var._index=18;
  int current_setpos_index = 18;
  if("" && strlen(""))
    stracpy(_mon_spl_xy_var._parameters.user1, "" ? "" : "", 16384);
  else 
  _mon_spl_xy_var._parameters.user1[0]='\0';
  if("" && strlen(""))
    stracpy(_mon_spl_xy_var._parameters.user2, "" ? "" : "", 16384);
  else 
  _mon_spl_xy_var._parameters.user2[0]='\0';
  if("" && strlen(""))
    stracpy(_mon_spl_xy_var._parameters.user3, "" ? "" : "", 16384);
  else 
  _mon_spl_xy_var._parameters.user3[0]='\0';
  _mon_spl_xy_var._parameters.xwidth = 1e-2;
  _mon_spl_xy_var._parameters.yheight = 1e-2;
  _mon_spl_xy_var._parameters.zdepth = 0;
  _mon_spl_xy_var._parameters.bins = 128;
  _mon_spl_xy_var._parameters.min = _instrument_var._parameters.E0 -1.1 * _instrument_var._parameters.dE;
  _mon_spl_xy_var._parameters.max = _instrument_var._parameters.E0 + 1.1 * _instrument_var._parameters.dE;
  _mon_spl_xy_var._parameters.restore_xray = 0;
  _mon_spl_xy_var._parameters.radius = 0;
  if("x y, all auto" && strlen("x y, all auto"))
    stracpy(_mon_spl_xy_var._parameters.options, "x y, all auto" ? "x y, all auto" : "", 16384);
  else 
  _mon_spl_xy_var._parameters.options[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_xy_var._parameters.filename, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_xy_var._parameters.filename[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_xy_var._parameters.geometry, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_xy_var._parameters.geometry[0]='\0';
  _mon_spl_xy_var._parameters.nowritefile = 0;
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_xy_var._parameters.username1, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_xy_var._parameters.username1[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_xy_var._parameters.username2, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_xy_var._parameters.username2[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_mon_spl_xy_var._parameters.username3, "NULL" ? "NULL" : "", 16384);
  else 
  _mon_spl_xy_var._parameters.username3[0]='\0';


  /* component mon_spl_xy=Monitor_nD() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _mon_spl_e_var._rotation_absolute, _mon_spl_xy_var._rotation_absolute);
    rot_transpose(_mon_spl_e_var._rotation_absolute, tr1);
    rot_mul(_mon_spl_xy_var._rotation_absolute, tr1, _mon_spl_xy_var._rotation_relative);
    _mon_spl_xy_var._rotation_is_identity =  rot_test_identity(_mon_spl_xy_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_mon_spl_e_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _mon_spl_xy_var._position_absolute = coords_add(_mon_spl_e_var._position_absolute, tc2);
    tc1 = coords_sub(_mon_spl_e_var._position_absolute, _mon_spl_xy_var._position_absolute);
    _mon_spl_xy_var._position_relative = rot_apply(_mon_spl_xy_var._rotation_absolute, tc1);
  } /* mon_spl_xy=Monitor_nD() AT ROTATED */
  DEBUG_COMPONENT("mon_spl_xy", _mon_spl_xy_var._position_absolute, _mon_spl_xy_var._rotation_absolute);
  instrument->_position_absolute[18] = _mon_spl_xy_var._position_absolute;
  instrument->_position_relative[18] = _mon_spl_xy_var._position_relative;
    _mon_spl_xy_var._position_relative_is_zero =  coords_test_zero(_mon_spl_xy_var._position_relative);
  instrument->counter_N[18]  = instrument->counter_P[18] = instrument->counter_P2[18] = 0;
  instrument->counter_AbsorbProp[18]= 0;
  return(0);
} /* _mon_spl_xy_setpos */

_class_Progress_bar *class_Progress_bar_init(_class_Progress_bar *_comp
) {
  #define profile (_comp->_parameters.profile)
  #define percent (_comp->_parameters.percent)
  #define flag_save (_comp->_parameters.flag_save)
  #define minutes (_comp->_parameters.minutes)
  #define IntermediateCnts (_comp->_parameters.IntermediateCnts)
  #define StartTime (_comp->_parameters.StartTime)
  #define EndTime (_comp->_parameters.EndTime)
  #define CurrentTime (_comp->_parameters.CurrentTime)
  SIG_MESSAGE("[_origin_init] component origin=Progress_bar() INITIALISE [/usr/share/mcxtrace/3.4-20240304/misc/Progress_bar.comp:60]");

  IntermediateCnts=0;
  StartTime=0;
  EndTime=0;
  CurrentTime=0;

  fprintf(stdout, "[%s] Initialize\n", instrument_name);
  if (percent*mcget_ncount()/100 < 1e5) {
    percent=1e5*100.0/mcget_ncount();
  }
  #ifdef OPENACC
  time(&StartTime);
  #endif
  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  return(_comp);
} /* class_Progress_bar_init */

_class_Wiggler *class_Wiggler_init(_class_Wiggler *_comp
) {
  #define E0 (_comp->_parameters.E0)
  #define dE (_comp->_parameters.dE)
  #define lambda0 (_comp->_parameters.lambda0)
  #define dlambda (_comp->_parameters.dlambda)
  #define phase (_comp->_parameters.phase)
  #define randomphase (_comp->_parameters.randomphase)
  #define Ee (_comp->_parameters.Ee)
  #define Ie (_comp->_parameters.Ie)
  #define B (_comp->_parameters.B)
  #define K (_comp->_parameters.K)
  #define Nper (_comp->_parameters.Nper)
  #define length (_comp->_parameters.length)
  #define sigey (_comp->_parameters.sigey)
  #define sigex (_comp->_parameters.sigex)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define dist (_comp->_parameters.dist)
  #define gauss_t (_comp->_parameters.gauss_t)
  #define verbose (_comp->_parameters.verbose)
  #define Br (_comp->_parameters.Br)
  #define gamma (_comp->_parameters.gamma)
  #define gamma2 (_comp->_parameters.gamma2)
  #define igamma (_comp->_parameters.igamma)
  #define kc (_comp->_parameters.kc)
  #define s1x (_comp->_parameters.s1x)
  #define s1y (_comp->_parameters.s1y)
  #define lu (_comp->_parameters.lu)
  #define gap (_comp->_parameters.gap)
  #define p0 (_comp->_parameters.p0)
  SIG_MESSAGE("[_source_init] component source=Wiggler() INITIALISE [/usr/share/mcxtrace/3.4-20240304/sources/Wiggler.comp:106]");

  // fprintf(stderr,"Warning (%s): Wiggler is an experimental component - testing is ongoing\n",NAME_CURRENT_COMP);
  
  lu=length/Nper;

  if( K<=0 || B<=0 || Ee<=0 || Ie<=0 || E0<=0 || length<=0 || Nper <=0){
    fprintf(stderr, "Wiggler Error (%s): (K, B, Ee, Ie, E0, length, Nper) do not have a sane set of values. Found (%g %g %g %g %g). Aborting.\n",
    NAME_CURRENT_COMP,K,B,Ee,Ie,E0);
    exit(1);
  }
  
  if(K){
    B=2*M_PI*MELECTRON*M_C*K/CELE/lu;
  }else if (B>0){
    K=CELE*B*lu/(2*M_PI*MELECTRON*M_C);
  }

  if (sigex <0 || sigey<0){
    fprintf(stderr, "Error (%s): sigex and sigey must be > 0. Negative beam size isn't meaningful. Aborting.\n",NAME_CURRENT_COMP);
    exit(1);
  }
  if (dist<=0){
    fprintf(stderr,"Error (%s): Target undefined.\n",NAME_CURRENT_COMP);
    exit(1);
  }

  /*compute gamma*/
  gamma=(Ee*1e9)/(MELECTRON/CELE*M_C*M_C);/*the extra CELE is to convert to eV*/
  gamma2=gamma*gamma;
  igamma=1.0/gamma;

  //printf("Wiggler (%s): gamma=%g, divergence is 1/gamma=%g rad.\n",NAME_CURRENT_COMP,gamma,igamma);
  /*compute characteristic energy in keV*/
  double Ec=0.665*Ee*Ee*B;
  //double Ec=1.5*gamma2*HBAR*CELE*B/MELE *1e-3; /*check units on this one. The 1e-3 factor is because energy is assumed to be in keV*/
  /*We normally do computations in k so use that for transfer*/
  kc=E2K*Ec;

   /* compute gap estimate */
  if (Br > B) {
    double a=0.55*Br +2.835;
    double b=-1.95*Br+7.22;
    double c=-1.3*Br +2.97;
    gap = -log(B/a)*lu/b;
  } else gap = 3e-3;

  if (verbose) 
    printf("Wiggler (%s): K=%g B=%g[T] lambda_u=%g[m] E0=%g[keV]\n",
      NAME_CURRENT_COMP, K,B,lu,E0);

  p0 = 1.0/mcget_ncount();
  #undef E0
  #undef dE
  #undef lambda0
  #undef dlambda
  #undef phase
  #undef randomphase
  #undef Ee
  #undef Ie
  #undef B
  #undef K
  #undef Nper
  #undef length
  #undef sigey
  #undef sigex
  #undef focus_xw
  #undef focus_yh
  #undef dist
  #undef gauss_t
  #undef verbose
  #undef Br
  #undef gamma
  #undef gamma2
  #undef igamma
  #undef kc
  #undef s1x
  #undef s1y
  #undef lu
  #undef gap
  #undef p0
  return(_comp);
} /* class_Wiggler_init */

_class_Monitor_nD *class_Monitor_nD_init(_class_Monitor_nD *_comp
) {
  #define user1 (_comp->_parameters.user1)
  #define user2 (_comp->_parameters.user2)
  #define user3 (_comp->_parameters.user3)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define bins (_comp->_parameters.bins)
  #define min (_comp->_parameters.min)
  #define max (_comp->_parameters.max)
  #define restore_xray (_comp->_parameters.restore_xray)
  #define radius (_comp->_parameters.radius)
  #define options (_comp->_parameters.options)
  #define filename (_comp->_parameters.filename)
  #define geometry (_comp->_parameters.geometry)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define username1 (_comp->_parameters.username1)
  #define username2 (_comp->_parameters.username2)
  #define username3 (_comp->_parameters.username3)
  #define DEFS (_comp->_parameters.DEFS)
  #define Vars (_comp->_parameters.Vars)
  #define detector (_comp->_parameters.detector)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_mon_src_e_init] component mon_src_e=Monitor_nD() INITIALISE [/usr/share/mcxtrace/3.4-20240304/monitors/Monitor_nD.comp:242]");

  char tmp[CHAR_BUF_LENGTH];
  strcpy(Vars.compcurname, NAME_CURRENT_COMP);
  if (options != NULL)
    strncpy(Vars.option, options, CHAR_BUF_LENGTH);
  else {
    strcpy(Vars.option, "x y");
    printf("Monitor_nD: %s has no option specified. Setting to PSD ('x y') monitor.\n", NAME_CURRENT_COMP);
  }
  Vars.compcurpos = POS_A_CURRENT_COMP;

  if (strstr(Vars.option, "source"))
    strcat(Vars.option, " list, x y z kx ky kz phi t Ex Ey Ez ");

  if (bins) { sprintf(tmp, " all bins=%ld ", (long)bins); strcat(Vars.option, tmp); }
  if (min > -FLT_MAX && max < FLT_MAX) { sprintf(tmp, " all limits=[%g %g]", min, max); strcat(Vars.option, tmp); }
  else if (min > -FLT_MAX) { sprintf(tmp, " all min=%g", min); strcat(Vars.option, tmp); }
  else if (max <  FLT_MAX) { sprintf(tmp, " all max=%g", max); strcat(Vars.option, tmp); }

  /* transfer, "zero", and check username- and user variable strings to Vars struct*/
  strncpy(Vars.UserName1,
    username1 && strlen(username1) && strcmp(username1, "0") && strcmp(username1, "NULL") ?
    username1 : "", 128);
  strncpy(Vars.UserName2,
    username2 && strlen(username2) && strcmp(username2, "0") && strcmp(username2, "NULL") ?
    username2 : "", 128);
  strncpy(Vars.UserName3,
    username3 && strlen(username3) && strcmp(username3, "0") && strcmp(username3, "NULL") ?
    username3 : "", 128);
  if(user1 && strlen(user1) && strcmp(user1, "0") && strcmp(user1, "NULL")){
    strncpy(Vars.UserVariable1,user1,128);
    int fail;_class_particle testparticle;
    particle_getvar(&testparticle,Vars.UserVariable1,&fail);
    if(fail){
      fprintf(stderr,"Warning (%s): user1=%s is unknown. The signal will not be resolved - this is likely not what you intended.\n",NAME_CURRENT_COMP,user1);
    }
  }
  if(user2 && strlen(user2) && strcmp(user2, "0") && strcmp(user2, "NULL")){
    strncpy(Vars.UserVariable2,user2,128);
    int fail;_class_particle testparticle;
    particle_getvar(&testparticle,Vars.UserVariable2,&fail);
    if(fail){
      fprintf(stderr,"Warning (%s): user2=%s is unknown. The signal will not be resolved - this is likely not what you intended.\n",NAME_CURRENT_COMP,user2);
    }
  }
  if(user3 && strlen(user3) && strcmp(user3, "0") && strcmp(user3, "NULL")){
    strncpy(Vars.UserVariable3,user3,128);
    int fail;_class_particle testparticle;
    particle_getvar(&testparticle,Vars.UserVariable3,&fail);
    if(fail){
      fprintf(stderr,"Warning (%s): user3=%s is unknown. The signal will not be resolved - this is likely not what you intended.\n",NAME_CURRENT_COMP,user3);
    }
  }
 
  /*sanitize parameters set for curved shapes*/
  if(strstr(Vars.option,"cylinder") || strstr(Vars.option,"banana") || strstr(Vars.option,"sphere")){
    /*this _is_ an explicit curved shape. Should have a radius. Inherit from xwidth or zdepth (diameters), x has precedence.*/
    if (!radius){
      if(xwidth){
	radius=xwidth/2.0;
      }else{
	radius=zdepth/2.0;
      }
    }else{
      /*radius is set - propagate to xwidth. It is used inside monitor_nd-lib*/
      xwidth=2*radius;
    }
    if(!yheight){
      /*if not set - use the diameter as height for the curved object. This will likely only happen for spheres*/
      yheight=2*radius;
    }
  }else if (radius) {
    /*radius is set - this must be curved shape then. Infer shape from yheight*/
    xwidth = zdepth = 2*radius;
    if (yheight){
      /*a height is given (and no shape explitly set - assume cylinder*/
      strcat(Vars.option, " banana");
    }else {
      strcat(Vars.option, " sphere");
      yheight=2*radius;
    }
  }

  int offflag=0;
  if (geometry && strlen(geometry) && strcmp(geometry,"0") && strcmp(geometry, "NULL")) {
    #ifndef USE_OFF
    fprintf(stderr,"Error: You are attempting to use an OFF geometry without -DUSE_OFF. You will need to recompile with that define set!\n");
    exit(-1);
    #else
    if (!off_init(  geometry, xwidth, yheight, zdepth, 1, &offdata )) {
      printf("Monitor_nD: %s could not initiate the OFF geometry %s. \n"
             "            Defaulting to normal Monitor dimensions.\n",
             NAME_CURRENT_COMP, geometry);
      strcpy(geometry, "");
    } else {
      offflag=1;
    }
    #endif
  }
  if (!radius && !xwidth && !yheight && !zdepth &&
    !strstr(Vars.option, "previous") && (!geometry || !strlen(geometry)))
    exit(printf("Monitor_nD: %s has no dimension specified. Aborting (radius, xwidth, yheight, zdepth, previous, geometry).\n", NAME_CURRENT_COMP));

  Monitor_nD_Init(&DEFS, &Vars, xwidth, yheight, zdepth, 0,0,0,0,0,0,offflag);


  if (filename && strlen(filename) && strcmp(filename,"NULL") && strcmp(filename,"0"))
    strncpy(Vars.Mon_File, filename, 128);

  /* check if user given filename with ext will be used more than once */
  if ( ((Vars.Flag_Multiple && Vars.Coord_Number > 1) || Vars.Flag_List) && strchr(Vars.Mon_File,'.') )
  { char *XY; XY = strrchr(Vars.Mon_File,'.'); *XY='_'; }

  if (restore_xray) Vars.Flag_parallel=1;
  detector.m = 0;

#ifdef USE_MPI
MPI_MASTER(
  if (strstr(Vars.option, "auto") && mpi_node_count > 1)
    printf("Monitor_nD: %s is using automatic limits option 'auto' together with MPI.\n"
           "WARNING     this may create incorrect distributions (but integrated flux will be right).\n", NAME_CURRENT_COMP);
);
#else
#ifdef OPENACC
  if (strstr(Vars.option, "auto"))
    printf("Monitor_nD: %s is requesting automatic limits option 'auto' together with OpenACC.\n"
           "WARNING     this feature is NOT supported using OpenACC and has been disabled!\n", NAME_CURRENT_COMP);
#endif
#endif

  #undef user1
  #undef user2
  #undef user3
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef bins
  #undef min
  #undef max
  #undef restore_xray
  #undef radius
  #undef options
  #undef filename
  #undef geometry
  #undef nowritefile
  #undef username1
  #undef username2
  #undef username3
  #undef DEFS
  #undef Vars
  #undef detector
  #undef offdata
  return(_comp);
} /* class_Monitor_nD_init */

_class_Bragg_crystal *class_Bragg_crystal_init(_class_Bragg_crystal *_comp
) {
  #define length (_comp->_parameters.length)
  #define width (_comp->_parameters.width)
  #define V (_comp->_parameters.V)
  #define form_factors (_comp->_parameters.form_factors)
  #define material (_comp->_parameters.material)
  #define alpha (_comp->_parameters.alpha)
  #define R0 (_comp->_parameters.R0)
  #define debye_waller_B (_comp->_parameters.debye_waller_B)
  #define crystal_type (_comp->_parameters.crystal_type)
  #define h (_comp->_parameters.h)
  #define k (_comp->_parameters.k)
  #define l (_comp->_parameters.l)
  #define structure_factor_scale_r (_comp->_parameters.structure_factor_scale_r)
  #define structure_factor_scale_i (_comp->_parameters.structure_factor_scale_i)
  #define Z (_comp->_parameters.Z)
  #define rho (_comp->_parameters.rho)
  #define At (_comp->_parameters.At)
  #define f_rel (_comp->_parameters.f_rel)
  #define f_nt (_comp->_parameters.f_nt)
  #define m_t (_comp->_parameters.m_t)
  #define f0_t (_comp->_parameters.f0_t)
  SIG_MESSAGE("[_dcm_xtal0_init] component dcm_xtal0=Bragg_crystal() INITIALISE [/usr/share/mcxtrace/3.4-20240304/optics/Bragg_crystal.comp:105]");

    int status;
    if (material){
        if ((status=Table_Read(&(m_t),material,0))==-1){
            fprintf(stderr,"Error(%s): Could not parse file \"%s\"\n",NAME_CURRENT_COMP,material);
            exit(-1);
        }
        char **header_parsed;
        header_parsed=Table_ParseHeader(m_t.header,"Z","A[r]","rho","Z/A","sigma[a]",NULL);
        if(header_parsed[2]){rho=strtod(header_parsed[2],NULL);}
        if(header_parsed[0]){Z=strtod(header_parsed[0],NULL);}
        if(header_parsed[1]){At=strtod(header_parsed[1],NULL);}
    }else{
        fprintf(stderr,"Error(%s): No material file specified\n",NAME_CURRENT_COMP);
    }
    if(form_factors){
        if ((status=Table_Read(&(f0_t),form_factors,0))==-1){
            fprintf(stderr,"Error(%s): Could not parse file \"%s\"\n",NAME_CURRENT_COMP,form_factors);
            exit(-1);
        }
    }
  #undef length
  #undef width
  #undef V
  #undef form_factors
  #undef material
  #undef alpha
  #undef R0
  #undef debye_waller_B
  #undef crystal_type
  #undef h
  #undef k
  #undef l
  #undef structure_factor_scale_r
  #undef structure_factor_scale_i
  #undef Z
  #undef rho
  #undef At
  #undef f_rel
  #undef f_nt
  #undef m_t
  #undef f0_t
  return(_comp);
} /* class_Bragg_crystal_init */

_class_Slit *class_Slit_init(_class_Slit *_comp
) {
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define radius (_comp->_parameters.radius)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define dist (_comp->_parameters.dist)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_x0 (_comp->_parameters.focus_x0)
  #define focus_y0 (_comp->_parameters.focus_y0)
  SIG_MESSAGE("[_slit_init] component slit=Slit() INITIALISE [/usr/share/mcxtrace/3.4-20240304/optics/Slit.comp:59]");

  if (xwidth > 0)  {
    if (!xmin && !xmax) {
      xmax=xwidth/2;  xmin=-xmax;
    } else {
      fprintf(stderr,"Slit: %s: Error: please specify EITHER xmin & xmax or xwidth\n", NAME_CURRENT_COMP); exit(-1);
    }
  }
  if (yheight > 0) {
    if (!ymin && !ymax) {
      ymax=yheight/2; ymin=-ymax;
    } else {
      fprintf(stderr,"Slit: %s: Error: please specify EITHER ymin & ymax or ywidth\n", NAME_CURRENT_COMP); exit(-1);
    }
  }
  if (xmin == 0 && xmax == 0 && ymin == 0 && ymax == 0 && radius == 0)
  { fprintf(stderr,"Slit: %s: Warning: Running with CLOSED slit - is this intentional?? \n", NAME_CURRENT_COMP); }

  if ( (focus_xw || focus_yh) && !( (focus_xw && dist) || (focus_yh && dist) ) ){
    fprintf(stderr,"Error (%s): Inconsistent target definition\n",NAME_CURRENT_COMP);
    exit(-1);
  }
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef radius
  #undef xwidth
  #undef yheight
  #undef dist
  #undef focus_xw
  #undef focus_yh
  #undef focus_x0
  #undef focus_y0
  return(_comp);
} /* class_Slit_init */

_class_Fluorescence *class_Fluorescence_init(_class_Fluorescence *_comp
) {
  #define geometry (_comp->_parameters.geometry)
  #define radius (_comp->_parameters.radius)
  #define thickness (_comp->_parameters.thickness)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define concentric (_comp->_parameters.concentric)
  #define material (_comp->_parameters.material)
  #define packing_factor (_comp->_parameters.packing_factor)
  #define rho (_comp->_parameters.rho)
  #define density (_comp->_parameters.density)
  #define weight (_comp->_parameters.weight)
  #define p_interact (_comp->_parameters.p_interact)
  #define target_x (_comp->_parameters.target_x)
  #define target_y (_comp->_parameters.target_y)
  #define target_z (_comp->_parameters.target_z)
  #define focus_r (_comp->_parameters.focus_r)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_aw (_comp->_parameters.focus_aw)
  #define focus_ah (_comp->_parameters.focus_ah)
  #define target_index (_comp->_parameters.target_index)
  #define flag_compton (_comp->_parameters.flag_compton)
  #define flag_rayleigh (_comp->_parameters.flag_rayleigh)
  #define flag_lorentzian (_comp->_parameters.flag_lorentzian)
  #define order (_comp->_parameters.order)
  #define compound (_comp->_parameters.compound)
  #define cum_massFractions (_comp->_parameters.cum_massFractions)
  #define cum_xs_fluo (_comp->_parameters.cum_xs_fluo)
  #define cum_xs_Compton (_comp->_parameters.cum_xs_Compton)
  #define cum_xs_Rayleigh (_comp->_parameters.cum_xs_Rayleigh)
  #define shape (_comp->_parameters.shape)
  #define offdata (_comp->_parameters.offdata)
  #define n_fluo (_comp->_parameters.n_fluo)
  #define n_Compton (_comp->_parameters.n_Compton)
  #define n_Rayleigh (_comp->_parameters.n_Rayleigh)
  #define p_fluo (_comp->_parameters.p_fluo)
  #define p_Compton (_comp->_parameters.p_Compton)
  #define p_Rayleigh (_comp->_parameters.p_Rayleigh)
  #define reuse_nb (_comp->_parameters.reuse_nb)
  #define reuse_intersect (_comp->_parameters.reuse_intersect)
  #define reuse_ki (_comp->_parameters.reuse_ki)
  #define reuse_l0 (_comp->_parameters.reuse_l0)
  #define reuse_l1 (_comp->_parameters.reuse_l1)
  #define reuse_l2 (_comp->_parameters.reuse_l2)
  #define reuse_l3 (_comp->_parameters.reuse_l3)
  #define reuse_sigma_barn (_comp->_parameters.reuse_sigma_barn)
  #define reuse_cum_xs_fluo (_comp->_parameters.reuse_cum_xs_fluo)
  #define reuse_cum_xs_Compton (_comp->_parameters.reuse_cum_xs_Compton)
  #define reuse_cum_xs_Rayleigh (_comp->_parameters.reuse_cum_xs_Rayleigh)
  #define filename (_comp->_parameters.filename)
  SIG_MESSAGE("[_sample_init] component sample=Fluorescence() INITIALISE [/usr/share/mcxtrace/3.4-20240304/samples/Fluorescence.comp:401]");


  /* energies en [keV], angles in [radians], XRL CSb cross sections are in [barn/atom] */
  double     E0, dE;
  xrl_error *error = NULL;
  int        i;
  
  XRayInit();
  
  shape=-1; /* -1:no shape, 0:cyl, 1:box, 2:sphere, 3:any-shape  */
  if (geometry && strlen(geometry) && strcmp(geometry, "NULL") && strcmp(geometry, "0")) {
    #ifndef USE_OFF
    fprintf(stderr,"Error: You are attempting to use an OFF geometry without -DUSE_OFF. You will need to recompile with that define set!\n");
    exit(-1);
    #else
    if (off_init(geometry, xwidth, yheight, zdepth, 0, &offdata)) {
      shape=3; thickness=0; concentric=0;
    }
    #endif
  }
  else if (xwidth && yheight && zdepth)  shape=1; /* box */
  else if (radius > 0 &&  yheight)       shape=0; /* cylinder */
  else if (radius > 0 && !yheight)       shape=2; /* sphere */

  if (shape < 0)
    exit(fprintf(stderr,"Fluorescence: %s: sample has invalid dimensions.\n"
                        "ERROR       Please check parameter values (xwidth, yheight, zdepth, radius).\n", NAME_CURRENT_COMP));
  
  if (!material || !strlen(material) || !strcmp(material, "NULL") || !strcmp(material, "0")) 
    exit(fprintf(stderr, "Fluorescence: ERROR: %s: Null material specification\n", NAME_CURRENT_COMP));
    
  // test if the material is given as a file
  char path[1024];
  char formula[65536];
  formula[0]='\0';
  FILE *file = Open_File(material, "r", path);
  if (file != NULL) {
    fclose(file);
    // open the material structure file (laz/lau/cif...)
    // search (case sensitive) along lines
    if (!fluo_get_material(material, formula))
      exit(fprintf(stderr, "ERROR: %s: file %s does not contain material formulae.\n", NAME_CURRENT_COMP, material));
    
    fprintf(stderr, "Fluorescence: INFO: %s: found material %s from file %s\n", NAME_CURRENT_COMP, formula, material);
    strcpy(material, formula);
    // CIF: _chemical_formula_structural 'chemical_formulae'
    // CIF: _chemical_formula_sum 'chemical_formulae'
    // LAZ/LAU: # ATOM <at> <trailing>
    // LAZ/LAU: # Atom <at> <trailing>
    // LAZ/LAU: # TITLE <at> <at> ... [ trailing...]
    // CFL: Title <chemical_formulae>
    // CFL: Atom <at> <trailing>
    
  } else filename = NULL;
    
  compound = CompoundParser(material, &error); /* XRayLib */
  if (error != NULL) {
    exit(fprintf(stderr, "ERROR: %s: Invalid material %s: %s\n",
      NAME_CURRENT_COMP, material, error->message));
  }
  xrl_error_free(error);
  
  /* compute total density for raw material and display information ========= */  
  if (weight <= 0) weight = compound->molarMass; /* g/mol */
  MPI_MASTER(
    printf("%s: Material %s mass fractions:\n", 
      NAME_CURRENT_COMP, material);
  )
  
  double mat_density       = 0; /* g/cm3 */
  double sum_massFractions = 0;
  cum_massFractions        = create_darr1d(compound->nElements+1);
  cum_xs_fluo              = create_darr1d(compound->nElements+1);
  cum_xs_Compton           = create_darr1d(compound->nElements+1);
  cum_xs_Rayleigh          = create_darr1d(compound->nElements+1);
  cum_massFractions[0]     = 0;
  
  /* print material information, and check for elements */
  for (i=0; i< compound->nElements; i++) {
    int    Z      = compound->Elements[i];
    error = NULL;
    double Z_dens = ElementDensity(Z, &error);
    if (error != NULL)
      exit(fprintf(stderr, "ERROR: %s: Z=%i %s\n", NAME_CURRENT_COMP, Z, error->message));
    mat_density           += compound->massFractions[i]*Z_dens;
    sum_massFractions     += compound->massFractions[i];
    cum_massFractions[i+1] = sum_massFractions;
    MPI_MASTER(
      printf("  | %6.2g %%: Z=%3i %3s %8.3g [g/mol] %8.3g [g/cm3]\n",
        compound->massFractions[i]*100, Z, AtomicNumberToSymbol(Z,NULL), AtomicWeight(Z, NULL),
        Z_dens);
    )
  }
  xrl_error_free(error);
  if (density <= 0)        density        = mat_density;   /* g/cm3 */
  if (packing_factor <= 0) packing_factor = density/mat_density;
  
  /* molar volume [cm^3/mol] = weight [g/mol] / density [g/cm^3] */
  /* atom density per Angs^3 = [mol/cm^3] * N_Avogadro *(1e-8)^3 */
  if (!rho) rho = density/weight/1e24*NA; // atom density [at/Angs-3]
  MPI_MASTER(
    printf("%s: Material %s M=%g [g/mol] density=%g [g/cm3] rho=%g [at/Angs-3]",
      NAME_CURRENT_COMP, material, weight, density, rho);
    if (fabs(packing_factor-1) > 1e-2)
      printf(" packing_factor=%g", packing_factor);
    printf("\n");
  )
  if (0 < packing_factor && packing_factor < 1) rho *= packing_factor;
  
  /* target for scattering ================================================== */
  if (!target_index && !target_x && !target_y && !target_z) target_index=1;
  if (target_index)
  {
    Coords ToTarget;
    ToTarget = coords_sub(POS_A_COMP_INDEX(INDEX_CURRENT_COMP+target_index),POS_A_CURRENT_COMP);
    ToTarget = rot_apply(ROT_A_CURRENT_COMP, ToTarget);
    coords_get(ToTarget, &target_x, &target_y, &target_z);
  }
  if (!(target_x || target_y || target_z)) {
    MPI_MASTER(
    printf("Fluorescence: %s: The target is not defined. Using 4PI.\n",
      NAME_CURRENT_COMP);
    );
  }
  
  n_fluo = n_Compton = n_Rayleigh = 0;
  p_fluo = p_Compton = p_Rayleigh = 0;
  
  // cached variables set to 0 (for SPLIT)
  reuse_nb=0;
  reuse_ki=reuse_l0=reuse_l3=0;
  reuse_cum_xs_fluo              = create_darr1d(compound->nElements+1);
  reuse_cum_xs_Compton           = create_darr1d(compound->nElements+1);
  reuse_cum_xs_Rayleigh          = create_darr1d(compound->nElements+1);
  #undef geometry
  #undef radius
  #undef thickness
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef concentric
  #undef material
  #undef packing_factor
  #undef rho
  #undef density
  #undef weight
  #undef p_interact
  #undef target_x
  #undef target_y
  #undef target_z
  #undef focus_r
  #undef focus_xw
  #undef focus_yh
  #undef focus_aw
  #undef focus_ah
  #undef target_index
  #undef flag_compton
  #undef flag_rayleigh
  #undef flag_lorentzian
  #undef order
  #undef compound
  #undef cum_massFractions
  #undef cum_xs_fluo
  #undef cum_xs_Compton
  #undef cum_xs_Rayleigh
  #undef shape
  #undef offdata
  #undef n_fluo
  #undef n_Compton
  #undef n_Rayleigh
  #undef p_fluo
  #undef p_Compton
  #undef p_Rayleigh
  #undef reuse_nb
  #undef reuse_intersect
  #undef reuse_ki
  #undef reuse_l0
  #undef reuse_l1
  #undef reuse_l2
  #undef reuse_l3
  #undef reuse_sigma_barn
  #undef reuse_cum_xs_fluo
  #undef reuse_cum_xs_Compton
  #undef reuse_cum_xs_Rayleigh
  #undef filename
  return(_comp);
} /* class_Fluorescence_init */



int init(void) { /* called by mccode_main for SOLEIL_PSICHE:INITIALISE */
  DEBUG_INSTR();

  /* code_main/parseoptions/readparams sets instrument parameters value */
  stracpy(instrument->_name, "SOLEIL_PSICHE", 256);

  /* Instrument 'SOLEIL_PSICHE' INITIALISE */
  SIG_MESSAGE("[SOLEIL_PSICHE] INITIALISE [SOLEIL_PSICHE.instr:54]");
  #define E0 (instrument->_parameters.E0)
  #define dE (instrument->_parameters.dE)
  #define DCM_present (instrument->_parameters.DCM_present)
  #define sample_theta (instrument->_parameters.sample_theta)
  #define sample_material (instrument->_parameters.sample_material)
  #define sample_geometry (instrument->_parameters.sample_geometry)
  #define dcm_theta (instrument->_parameters.dcm_theta)
{
   double DM= 5.4909;     // Si d-spacing
   double d = DM/sqrt(3); // <111> reflection |<111>|=3
   dcm_gap  = 0.02;       // gap between the 2 monochromator crystals
   dcm_scatter = DCM_present;
   #pragma acc update device(dcm_scatter)
   
   if (DCM_present) {
     if (!dcm_theta && E0) {
       // n.lambda = 2 d sin(dcm_theta) = 2*PI/E2K / E0 with n=ORDER=1
       double sin_theta = 2*PI/E2K/E0 / 2 / d;
       if (fabs(sin_theta) < 1)
         dcm_theta = asin(sin_theta)*RAD2DEG;
     } else if (dcm_theta && !E0)
       E0 = 2*PI/E2K / (2*d*sin(dcm_theta*DEG2RAD));
     if (!dcm_theta || !E0 || dE <=0)
       exit(fprintf(stderr, "%s: ERROR: Monochromator can not reflect E0=%g +/- %g [keV]. Aborting.\n", NAME_INSTRUMENT, E0, dE));
     printf("%s: E0=%g [keV] Monochromator dcm_theta=%g [deg] \n", NAME_INSTRUMENT, E0, dcm_theta);
     if (fabs(dE/E0)>0.1) dE = 3e-2*E0;
   } else {
     dcm_gap=dcm_theta=0;
     printf("%s: E0=%g [keV] Monochromator OFF\n", NAME_INSTRUMENT, E0);
   }
}
  #undef E0
  #undef dE
  #undef DCM_present
  #undef sample_theta
  #undef sample_material
  #undef sample_geometry
  #undef dcm_theta
  _origin_setpos(); /* type Progress_bar */
  _source_setpos(); /* type Wiggler */
  _mon_src_e_setpos(); /* type Monitor_nD */
  _mon_src_xy_setpos(); /* type Monitor_nD */
  _DCM_location_setpos(); /* type Arm */
  _dcm_xtal0_setpos(); /* type Bragg_crystal */
  _dcm0_setpos(); /* type Arm */
  _dcm_xtal1_setpos(); /* type Bragg_crystal */
  _dcm1_setpos(); /* type Arm */
  _mon_dcm_e_setpos(); /* type Monitor_nD */
  _mon_dcm_xy_setpos(); /* type Monitor_nD */
  _slit_setpos(); /* type Slit */
  _sample_stage_setpos(); /* type Arm */
  _sample_setpos(); /* type Fluorescence */
  _fluo_holder_setpos(); /* type Arm */
  _mon_spl_fluo_setpos(); /* type Monitor_nD */
  _mon_spl_e_setpos(); /* type Monitor_nD */
  _mon_spl_xy_setpos(); /* type Monitor_nD */

  /* call iteratively all components INITIALISE */
  class_Progress_bar_init(&_origin_var);

  class_Wiggler_init(&_source_var);

  class_Monitor_nD_init(&_mon_src_e_var);

  class_Monitor_nD_init(&_mon_src_xy_var);


  class_Bragg_crystal_init(&_dcm_xtal0_var);


  class_Bragg_crystal_init(&_dcm_xtal1_var);


  class_Monitor_nD_init(&_mon_dcm_e_var);

  class_Monitor_nD_init(&_mon_dcm_xy_var);

  class_Slit_init(&_slit_var);


  class_Fluorescence_init(&_sample_var);


  class_Monitor_nD_init(&_mon_spl_fluo_var);

  class_Monitor_nD_init(&_mon_spl_e_var);

  class_Monitor_nD_init(&_mon_spl_xy_var);

  if (mcdotrace) display();
  DEBUG_INSTR_END();

#ifdef OPENACC
#include <openacc.h>
#pragma acc update device(_origin_var)
#pragma acc update device(_source_var)
#pragma acc update device(_mon_src_e_var)
#pragma acc update device(_mon_src_xy_var)
#pragma acc update device(_DCM_location_var)
#pragma acc update device(_dcm_xtal0_var)
#pragma acc update device(_dcm0_var)
#pragma acc update device(_dcm_xtal1_var)
#pragma acc update device(_dcm1_var)
#pragma acc update device(_mon_dcm_e_var)
#pragma acc update device(_mon_dcm_xy_var)
#pragma acc update device(_slit_var)
#pragma acc update device(_sample_stage_var)
#pragma acc update device(_sample_var)
#pragma acc update device(_fluo_holder_var)
#pragma acc update device(_mon_spl_fluo_var)
#pragma acc update device(_mon_spl_e_var)
#pragma acc update device(_mon_spl_xy_var)
#pragma acc update device(_instrument_var)
#endif

  return(0);
} /* init */

/*******************************************************************************
* components TRACE
*******************************************************************************/

#define x (_particle->x)
#define y (_particle->y)
#define z (_particle->z)
#define kx (_particle->kx)
#define ky (_particle->ky)
#define kz (_particle->kz)
#define phi (_particle->phi)
#define t (_particle->t)
#define Ex (_particle->Ex)
#define Ey (_particle->Ey)
#define Ez (_particle->Ez)
#define p (_particle->p)
#define _mctmp_a (_particle->_mctmp_a)
#define _mctmp_b (_particle->_mctmp_b)
#define _mctmp_c (_particle->_mctmp_c)
/* if on GPU, globally nullify sprintf,fprintf,printfs   */
/* (Similar defines are available in each comp trace but */
/*  those are not enough to handle external libs etc. )  */
#ifdef OPENACC
#ifndef MULTICORE
#define fprintf(stderr,...) printf(__VA_ARGS__)
#define sprintf(string,...) printf(__VA_ARGS__)
#define exit(...) noprintf()
#define strcmp(a,b) str_comp(a,b)
#define strlen(a) str_len(a)
#endif
#endif
#define SCATTERED (_particle->_scattered)
#define RESTORE (_particle->_restore)
#define RESTORE_XRAY(_index, ...) _particle->_restore = _index;
#define ABSORBED (_particle->_absorbed)
#define mcget_run_num() _particle->_uid
#define ABSORB0 do { DEBUG_STATE(); DEBUG_ABSORB(); ABSORBED++; return(_comp); } while(0)
#define ABSORB ABSORB0
#pragma acc routine
_class_Progress_bar *class_Progress_bar_trace(_class_Progress_bar *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define profile (_comp->_parameters.profile)
  #define percent (_comp->_parameters.percent)
  #define flag_save (_comp->_parameters.flag_save)
  #define minutes (_comp->_parameters.minutes)
  #define IntermediateCnts (_comp->_parameters.IntermediateCnts)
  #define StartTime (_comp->_parameters.StartTime)
  #define EndTime (_comp->_parameters.EndTime)
  #define CurrentTime (_comp->_parameters.CurrentTime)
  SIG_MESSAGE("[_origin_trace] component origin=Progress_bar() TRACE [/usr/share/mcxtrace/3.4-20240304/misc/Progress_bar.comp:76]");

#ifndef OPENACC
  double ncount;
  ncount = mcget_run_num();
  if (!StartTime) {
    time(&StartTime); /* compute starting time */
    IntermediateCnts = 1e3;
  }
  time_t NowTime;
  time(&NowTime);
  /* compute initial estimate of computation duration */
  if (!EndTime && ncount >= IntermediateCnts) {
    CurrentTime = NowTime;
    if (difftime(NowTime,StartTime) > 10 && ncount) { /* wait 10 sec before writing ETA */
      EndTime = StartTime + (time_t)(difftime(NowTime,StartTime)
				     *(double)mcget_ncount()/ncount);
      IntermediateCnts = 0;
      fprintf(stdout, "\nTrace ETA ");
      if (difftime(EndTime,StartTime) < 60.0)
        fprintf(stdout, "%g [s] %% ", difftime(EndTime,StartTime));
      else if (difftime(EndTime,StartTime) > 3600.0)
        fprintf(stdout, "%g [h] %% ", difftime(EndTime,StartTime)/3600.0);
      else
        fprintf(stdout, "%g [min] %% ", difftime(EndTime,StartTime)/60.0);
    } else IntermediateCnts += 1e3;
    fflush(stdout);
  }

  /* display percentage when percent or minutes have reached step */
  if (EndTime && mcget_ncount() &&
    (    (minutes && difftime(NowTime,CurrentTime) > minutes*60)
      || (percent && !minutes && ncount >= IntermediateCnts))   )
  {
    fprintf(stdout, "%llu ", (unsigned long long)(ncount*100.0/mcget_ncount())); fflush(stdout);
    CurrentTime = NowTime;

    IntermediateCnts = ncount + percent*mcget_ncount()/100;
    /* check that next intermediate ncount check is a multiple of the desired percentage */
    IntermediateCnts = floor(IntermediateCnts*100/percent/mcget_ncount())*percent*mcget_ncount()/100;
    /* raise flag to indicate that we did something */
    SCATTER;
    if (flag_save) save(NULL);
  }
#endif
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p)  ||  isinf(p)) ABSORB;
  if(isnan(t)  ||  isinf(t)) ABSORB;
  if(isnan(phi)  ||  isinf(phi)) ABSORB;
  if(isnan(kx) || isinf(kx)) ABSORB;
  if(isnan(ky) || isinf(ky)) ABSORB;
  if(isnan(kz) || isinf(kz)) ABSORB;
  if(isnan(x)  ||  isinf(x)) ABSORB;
  if(isnan(y)  ||  isinf(y)) ABSORB;
  if(isnan(z)  ||  isinf(z)) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(phi)  ||  isinf(phi)) printf("NAN or INF found in phi, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(kx) || isinf(kx)) printf("NAN or INF found in kx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(ky) || isinf(ky)) printf("NAN or INF found in ky, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(kz) || isinf(kz)) printf("NAN or INF found in kz,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  return(_comp);
} /* class_Progress_bar_trace */

#pragma acc routine
_class_Wiggler *class_Wiggler_trace(_class_Wiggler *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define E0 (_comp->_parameters.E0)
  #define dE (_comp->_parameters.dE)
  #define lambda0 (_comp->_parameters.lambda0)
  #define dlambda (_comp->_parameters.dlambda)
  #define phase (_comp->_parameters.phase)
  #define randomphase (_comp->_parameters.randomphase)
  #define Ee (_comp->_parameters.Ee)
  #define Ie (_comp->_parameters.Ie)
  #define B (_comp->_parameters.B)
  #define K (_comp->_parameters.K)
  #define Nper (_comp->_parameters.Nper)
  #define length (_comp->_parameters.length)
  #define sigey (_comp->_parameters.sigey)
  #define sigex (_comp->_parameters.sigex)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define dist (_comp->_parameters.dist)
  #define gauss_t (_comp->_parameters.gauss_t)
  #define verbose (_comp->_parameters.verbose)
  #define Br (_comp->_parameters.Br)
  #define gamma (_comp->_parameters.gamma)
  #define gamma2 (_comp->_parameters.gamma2)
  #define igamma (_comp->_parameters.igamma)
  #define kc (_comp->_parameters.kc)
  #define s1x (_comp->_parameters.s1x)
  #define s1y (_comp->_parameters.s1y)
  #define lu (_comp->_parameters.lu)
  #define gap (_comp->_parameters.gap)
  #define p0 (_comp->_parameters.p0)
  SIG_MESSAGE("[_source_trace] component source=Wiggler() TRACE [/usr/share/mcxtrace/3.4-20240304/sources/Wiggler.comp:161]");


  double xx,yy,x1,y1,z1;
  double k,e,l;
  double F1=1.0;
  double dx,dy,dz;
  
  // initial source area
  xx=randnorm();
  yy=randnorm();
  x=xx*sigex;
  y=yy*sigey;
  z=(rand01()-0.5)*length;

  // Gaussian distribution at origin
  p=p0;/*initial weight is p0*/
  if (E0){
    if(!dE){
      e=E0;
    }else {
      e=randpm1()*dE + E0;
    }
    k=E2K*e;
  }else if (lambda0){
    if (!dlambda){
      l=lambda0;
    }else{
      l=randpm1()*dlambda + lambda0;
    }
    k=(2*M_PI/l);
  }

  // targeted area calculation
  s1x=sqrt(sigex*sigex + K*igamma*K*igamma*(dist-z)*(dist-z));
  s1y=sqrt(sigey*sigey + igamma*igamma*(dist-z)*(dist-z));
  if (focus_xw){
    if (!gauss_t){
      /*sample uniformly but adjust weight*/
      x1=randpm1()*focus_xw/2.0;
      p*=exp(-(x1*x1)/(2.0*s1x*s1x));
    }else {
      do {
        x1=randnorm()*s1x;
      }while (fabs(x1)>focus_xw/2.0);
      p*=erf(focus_xw*0.5*M_SQRT1_2/s1x);
    }
  }else{
    x1=randnorm()*igamma*K;
  }
  if (focus_yh){
    if (!gauss_t){
      /*sample uniformly but adjust weight*/
      y1=randpm1()*focus_yh/2.0;
      p*=exp(-(y1*y1)/(2.0*s1y*s1y));
    }else {
      do {
        y1=randnorm()*s1y;
      }while (fabs(y1)>focus_yh/2.0);
      p*=erf(focus_yh*0.5*M_SQRT1_2/s1y);
    }
  }else{
    y1=randnorm()*igamma;
  }
  z1=dist;
  dx=x1-x;
  dy=y1-y;
  dz=sqrt(dx*dx+dy*dy+(dist-z)*(dist-z));

  kx=(k*dx)/dz;
  ky=(k*dy)/dz;
  kz=(k*(dist-z))/dz;
  
  /*spectral strength of radiation is given by Patterson*/  
  double k_kc=k/kc;
  double K2_3=besselKnu(0.666666666666666666666666667,k_kc*0.5);
  p*=2*Nper*1.33e13*Ee*Ee*Ie* k_kc*k_kc*K2_3*K2_3;
  //p*=2*Nper*ALPHA/(M_PI*M_PI)*gamma2*Ie/CELE* 1e-4 * 0.75 *k_kc*k_kc*K2_3*K2_3; 

  /*randomly pick phase*/
  if (randomphase){
    phi=rand01()*2*M_PI;
  }else{
    phi=phase;
  }

  /*set polarization vector*/
  Ex=0;Ey=0;Ez=0;
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p)  ||  isinf(p)) ABSORB;
  if(isnan(t)  ||  isinf(t)) ABSORB;
  if(isnan(phi)  ||  isinf(phi)) ABSORB;
  if(isnan(kx) || isinf(kx)) ABSORB;
  if(isnan(ky) || isinf(ky)) ABSORB;
  if(isnan(kz) || isinf(kz)) ABSORB;
  if(isnan(x)  ||  isinf(x)) ABSORB;
  if(isnan(y)  ||  isinf(y)) ABSORB;
  if(isnan(z)  ||  isinf(z)) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(phi)  ||  isinf(phi)) printf("NAN or INF found in phi, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(kx) || isinf(kx)) printf("NAN or INF found in kx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(ky) || isinf(ky)) printf("NAN or INF found in ky, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(kz) || isinf(kz)) printf("NAN or INF found in kz,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef E0
  #undef dE
  #undef lambda0
  #undef dlambda
  #undef phase
  #undef randomphase
  #undef Ee
  #undef Ie
  #undef B
  #undef K
  #undef Nper
  #undef length
  #undef sigey
  #undef sigex
  #undef focus_xw
  #undef focus_yh
  #undef dist
  #undef gauss_t
  #undef verbose
  #undef Br
  #undef gamma
  #undef gamma2
  #undef igamma
  #undef kc
  #undef s1x
  #undef s1y
  #undef lu
  #undef gap
  #undef p0
  return(_comp);
} /* class_Wiggler_trace */

#pragma acc routine
_class_Monitor_nD *class_Monitor_nD_trace(_class_Monitor_nD *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define user1 (_comp->_parameters.user1)
  #define user2 (_comp->_parameters.user2)
  #define user3 (_comp->_parameters.user3)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define bins (_comp->_parameters.bins)
  #define min (_comp->_parameters.min)
  #define max (_comp->_parameters.max)
  #define restore_xray (_comp->_parameters.restore_xray)
  #define radius (_comp->_parameters.radius)
  #define options (_comp->_parameters.options)
  #define filename (_comp->_parameters.filename)
  #define geometry (_comp->_parameters.geometry)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define username1 (_comp->_parameters.username1)
  #define username2 (_comp->_parameters.username2)
  #define username3 (_comp->_parameters.username3)
  #define DEFS (_comp->_parameters.DEFS)
  #define Vars (_comp->_parameters.Vars)
  #define detector (_comp->_parameters.detector)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_mon_src_e_trace] component mon_src_e=Monitor_nD() TRACE [/usr/share/mcxtrace/3.4-20240304/monitors/Monitor_nD.comp:375]");

//  double  XY=0;
  double  l0 = 0;
  double  l1 = 0;
  int     pp;
  int     intersect   = 0;
  char    Flag_Restore = 0;

  #ifdef OPENACC
  #ifdef USE_OFF
  off_struct thread_offdata = offdata;
  #endif
  #else
  #define thread_offdata offdata
  #endif

  /* this is done automatically
    STORE_XRAY(INDEX_CURRENT_COMP, x, y, z, vx, vy, vz, t, sx, sy, sz, p);
  */
  #ifdef USE_OFF
  if (geometry && strlen(geometry) && strcmp(geometry,"0") && strcmp(geometry, "NULL"))
  {
    /* determine intersections with object */
    intersect = off_x_intersect(&l0, &l1, NULL, NULL,
       x,y,z, kx, ky, kz, offdata );
  }
  else 
  #endif
    if ( (abs(Vars.Flag_Shape) == DEFS.SHAPE_SQUARE)
            || (abs(Vars.Flag_Shape) == DEFS.SHAPE_DISK) ) /* square xy or disk xy */
  {
    // propagate to xy plane and find intersection
    // make sure the event is recoverable afterwards
    l0 = z;
    ALLOW_BACKPROP;
    PROP_Z0;
    if ( (z>=l0) && (z*copysign(z,1.0)<=DBL_EPSILON) ) // forward propagation to xy plane was successful
    {
      if (abs(Vars.Flag_Shape) == DEFS.SHAPE_SQUARE)
      {
        // square xy
        intersect = (x>=Vars.mxmin && x<=Vars.mxmax && y>=Vars.mymin && y<=Vars.mymax);
      }
      else
      {
        // disk xy
        intersect = (SQR(x) + SQR(y)) <= SQR(Vars.Sphere_Radius);
      }
    }
    else
    {
      intersect=0;
    }
  }
  else if (abs(Vars.Flag_Shape) == DEFS.SHAPE_SPHERE) /* sphere */
  {
    intersect = sphere_intersect(&l0, &l1, x, y, z, kx, ky, kz, Vars.Sphere_Radius);
  /*      intersect = (intersect && t0 > 0); */
  }
  else if ((abs(Vars.Flag_Shape) == DEFS.SHAPE_CYLIND) || (abs(Vars.Flag_Shape) == DEFS.SHAPE_BANANA)) /* cylinder */
  {
    intersect = cylinder_intersect(&l0, &l1, x, y, z, kx, ky, kz, Vars.Sphere_Radius, Vars.Cylinder_Height);
  }
  else if (abs(Vars.Flag_Shape) == DEFS.SHAPE_BOX) /* box */
  {
    intersect = box_intersect(&l0, &l1, x, y, z, kx, ky, kz, 
                              fabs(Vars.mxmax-Vars.mxmin), fabs(Vars.mymax-Vars.mymin), fabs(Vars.mzmax-Vars.mzmin));
  }
  else if (abs(Vars.Flag_Shape) == DEFS.SHAPE_PREVIOUS) /* previous comp */
  { intersect = 1; }

  if (intersect)
  {
    if ((abs(Vars.Flag_Shape) == DEFS.SHAPE_SPHERE) || (abs(Vars.Flag_Shape) == DEFS.SHAPE_CYLIND) 
     || (abs(Vars.Flag_Shape) == DEFS.SHAPE_BOX) || (abs(Vars.Flag_Shape) == DEFS.SHAPE_BANANA)
     || (geometry && strlen(geometry) && strcmp(geometry,"0") && strcmp(geometry, "NULL")) )
    {
      /* check if we have to remove the top/bottom with BANANA shape */
      if ((abs(Vars.Flag_Shape) == DEFS.SHAPE_BANANA) && (intersect != 1)) {
        double y0,y1;
        /* propagate to intersection point as temporary variable to check top/bottom */
        y0 = y+l0;
        y1 = y+l1;
        if (fabs(y0) >= Vars.Cylinder_Height/2*0.99) l0 = l1;
        if (fabs(y1) >= Vars.Cylinder_Height/2*0.99) l1 = l0;
      }
      if (l0 < 0 && l1 > 0)
        l0 = 0;  /* photon was already inside ! */
      if (l1 < 0 && l0 > 0) /* photon exit before entering !! */
        l1 = 0;
      /* t0 is now time of incoming intersection with the detection area */
      if ((Vars.Flag_Shape < 0) && (l1 > 0))
        PROP_DL(l1); /* l1 outgoing beam */
      else
        PROP_DL(l0); /* l0 incoming beam */
      /* Final test if we are on lid / bottom of banana/sphere */
      if (abs(Vars.Flag_Shape) == DEFS.SHAPE_BANANA || abs(Vars.Flag_Shape) == DEFS.SHAPE_SPHERE) {
        if (Vars.Cylinder_Height && fabs(y) >= Vars.Cylinder_Height/2 - FLT_EPSILON) {
          intersect=0;
          Flag_Restore=1;
        }
      }
    }
  }

  if (intersect)
  {
    /* Now get the data to monitor: current or keep from PreMonitor */
/*    if (Vars.Flag_UsePreMonitor != 1)*/
/*    {*/
/*      Vars.cp  = p;*/
/*      Vars.cx  = x;*/
/*      Vars.ckx = kx;*/
/*      Vars.cEx = Ex;*/
/*      Vars.cy  = y;*/
/*      Vars.cky = ky;*/
/*      Vars.cEy = Ey;*/
/*      Vars.cz  = z;*/
/*      Vars.ckz = kz;*/
/*      Vars.cEz = Ez;*/
/*      Vars.ct  = t;*/
/*      Vars.cphi = phi;*/
/*    }*/


    pp = Monitor_nD_Trace(&DEFS, &Vars, _particle);
    if (pp==0.0)
    {
      ABSORB;
    }
    else if(pp==1)
    {
      SCATTER;
    }

    if (Vars.Flag_parallel) /* back to photon state before detection */
      Flag_Restore = 1;
  } /* end if intersection */
  else {
    if (Vars.Flag_Absorb && !Vars.Flag_parallel)
    {
      // restore x-ray before absorbing for correct mcdisplay
      RESTORE_XRAY(INDEX_CURRENT_COMP, x, y, z, kx, ky, kz, phi, t, Ex, Ey, Ez, p);
      ABSORB;
    }
    else Flag_Restore = 1;  /* no intersection, back to previous state */
  }

  if (Flag_Restore)
  {
    RESTORE_XRAY(INDEX_CURRENT_COMP, x, y, z, kx, ky, kz, phi, t, Ex, Ey, Ez, p);
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p)  ||  isinf(p)) ABSORB;
  if(isnan(t)  ||  isinf(t)) ABSORB;
  if(isnan(phi)  ||  isinf(phi)) ABSORB;
  if(isnan(kx) || isinf(kx)) ABSORB;
  if(isnan(ky) || isinf(ky)) ABSORB;
  if(isnan(kz) || isinf(kz)) ABSORB;
  if(isnan(x)  ||  isinf(x)) ABSORB;
  if(isnan(y)  ||  isinf(y)) ABSORB;
  if(isnan(z)  ||  isinf(z)) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(phi)  ||  isinf(phi)) printf("NAN or INF found in phi, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(kx) || isinf(kx)) printf("NAN or INF found in kx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(ky) || isinf(ky)) printf("NAN or INF found in ky, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(kz) || isinf(kz)) printf("NAN or INF found in kz,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef user1
  #undef user2
  #undef user3
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef bins
  #undef min
  #undef max
  #undef restore_xray
  #undef radius
  #undef options
  #undef filename
  #undef geometry
  #undef nowritefile
  #undef username1
  #undef username2
  #undef username3
  #undef DEFS
  #undef Vars
  #undef detector
  #undef offdata
  return(_comp);
} /* class_Monitor_nD_trace */

#pragma acc routine
_class_Bragg_crystal *class_Bragg_crystal_trace(_class_Bragg_crystal *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define length (_comp->_parameters.length)
  #define width (_comp->_parameters.width)
  #define V (_comp->_parameters.V)
  #define form_factors (_comp->_parameters.form_factors)
  #define material (_comp->_parameters.material)
  #define alpha (_comp->_parameters.alpha)
  #define R0 (_comp->_parameters.R0)
  #define debye_waller_B (_comp->_parameters.debye_waller_B)
  #define crystal_type (_comp->_parameters.crystal_type)
  #define h (_comp->_parameters.h)
  #define k (_comp->_parameters.k)
  #define l (_comp->_parameters.l)
  #define structure_factor_scale_r (_comp->_parameters.structure_factor_scale_r)
  #define structure_factor_scale_i (_comp->_parameters.structure_factor_scale_i)
  #define Z (_comp->_parameters.Z)
  #define rho (_comp->_parameters.rho)
  #define At (_comp->_parameters.At)
  #define f_rel (_comp->_parameters.f_rel)
  #define f_nt (_comp->_parameters.f_nt)
  #define m_t (_comp->_parameters.m_t)
  #define f0_t (_comp->_parameters.f0_t)
  SIG_MESSAGE("[_dcm_xtal0_trace] component dcm_xtal0=Bragg_crystal() TRACE [/usr/share/mcxtrace/3.4-20240304/optics/Bragg_crystal.comp:129]");

    double E;				// (keV) x-ray energy
    double K; 				// length of k-vector
    double kxu,kyu,kzu;			// unit vector in the direction of k-vector.
    double tin;				// 'time' of intersection of ray with y=0 plane (which include the crystal surface)
    double x_int,y_int,z_int;		// intersection with the y=0 plane
    double dist;				// distance from position at t=0 to the y=0 plane
    double f00, f0h, fp, fpp;		// atomic form factors for Q=0 is (f00 + fp + i*fpp) and for Q= ha*+kb*+lc* it is (f0h + fp + i*fpp).
    double Thetain;			// (rad) angle between the crystal surface and the incident ray
    double Theta0;			// (rad) angle between the Bragg planes and the incident ray
    double Thetah;			// (rad) angle between the Bragg planes and the reflected ray
    double Thetaout;			// (rad) angle between the crystal surface and the reflected ray
    double DeltaTheta0;			// (rad) the center of the reflectivity curve is at asin(n*lambda/(2*d)) + DeltaTheta0
    double Rpi, Rsig, R;          // Reflectivity value calculated by DarwinReflectivity() function for each incoming photon
    double x0,y0,z0,kx0,ky0,kz0,phi0,t0,Ex0,Ey0,Ez0,p0;
    
    x0=x; y0=y; z0=z; kx0=kx; ky0=ky; kz0=kz; phi0=phi; t0=t; Ex0=Ex; Ey0=Ey; Ez0=Ez; p0=p;
    /* get the photon's kvector and energy */
    K=sqrt(kx*kx+ky*ky+kz*kz);
    E = K2E*K; /* use built-in constants for consistency */
    /* make unit vector in the direction of k :*/
    kxu = kx; kyu = ky; kzu = kz;
    NORM(kxu,kyu,kzu);
    /* printf("incoming kx,ky,kz, Ex, Ey, Ez, k.E: %f %f %f %g %g %g %g\n", kx,ky,kz,Ex,Ey,Ez, kxu*Ex+kyu*Ey+kzu*Ez); */
    
    /*intersection calculation*/
    tin = -y/kyu;
    if (tin>=0){
        /* check whether our intersection lies within the boundaries of the crystal*/
        x_int=x+kxu*tin;
        y_int=y+kyu*tin;
        z_int=z+kzu*tin;
        
        if (fabs(x_int)<=width/2 && fabs(z_int)<=length/2){
            dist=sqrt(SQR(x-x_int)+SQR(y-y_int)+SQR(z-z_int));
            PROP_DL(dist); 			/* now the photon is on the crystal surface, ready to be reflected... */
            SCATTER;
            Thetain=fabs(asin(kyu)); /* k(x,y,z)u is a unit vector, the y component is sin(theta) */
            double d=cbrt(V)/(sqrt(h*h+k*k+l*l));/*this is valid only for cubic structures*/
            f00 = Z;
            f0h = Table_Value(f0_t,1/(2*d),Z);
            fp  = Table_Value(m_t,E,1)-Z;
            fpp = Table_Value(m_t,E,2);

            double alpha1=alpha;
            /* check for 3rd & 1st quadrant hits, backward hit from above or forward hit from below and reverse sense of alpha */
            if( (ky<0 && kz<0) || (ky>0 && kz>0) ) alpha1=-alpha1;
            Mx_DarwinReflectivity(&Rpi , &Thetah, &Theta0, &DeltaTheta0, f00, f0h, fp, fpp, V, alpha1, h, k, l,
                debye_waller_B, E, Thetain,1, crystal_type, structure_factor_scale_r, structure_factor_scale_i
            );
            Mx_DarwinReflectivity(&Rsig, &Thetah, &Theta0, &DeltaTheta0, f00, f0h, fp, fpp, V, alpha1, h, k, l,
                debye_waller_B, E, Thetain,2, crystal_type, structure_factor_scale_r, structure_factor_scale_i
            );

            double pi_x, pi_y, pi_z, sig_x, sig_y, sig_z;
            double kx0=kx, ky0=ky, kz0=kz, Ex0=Ex, Ey0=Ey, Ez0=Ez;

            /* sig_x,y,z is k(in) x surface_normal i.e. the direction of sigma polarization */
            vec_prod_func(&sig_x , &sig_y , &sig_z , kx0, ky0, kz0, 0, -1, 0);
            NORM(sig_x, sig_y, sig_z);
            /* pi is a vector perpendicular to k_in and sig i.e. the direction of pi polarization incoming */
            vec_prod_func(&pi_x, &pi_y, &pi_z, kx0, ky0, kz0, sig_x, sig_y, sig_z);
            NORM(pi_x , pi_y , pi_z );

#ifdef MCDEBUG
            printf("%s: Thetain: %.3f sigma: (%g, %g, %g) pi: (%g, %g, %g) \n", NAME_CURRENT_COMP,
                   Thetain*180/PI, sig_x, sig_y, sig_z, pi_x, pi_y, pi_z);
#endif

            double sth=sin(Theta0+Thetah), cth=cos(Theta0+Thetah);
            if(sig_x*pi_y*pi_z > 0) { /* backwards hit, rotate the other way */
                sth=-sth;
            }
            double sx2=sig_x*sig_x, sy2=sig_y*sig_y, sz2=sig_z*sig_z, r2=sig_x*sig_x+sig_y*sig_y;

            /* initialize a rotation matrix by the appropriate angle around the sigma axis, this from Mathematica RotationMatrix[] */
            double m[3][3]={
                sx2 + (cth*(sy2 + sx2*sz2))/r2,sig_x*sig_y - sig_z*sth + (cth*sig_x*sig_y*(-1 + sz2))/r2,sig_x*sig_z - cth*sig_x*sig_z + sig_y*sth,
                sig_x*sig_y + sig_z*sth + (cth*sig_x*sig_y*(-1 + sz2))/r2,sy2 + (cth*(sx2 + sy2*sz2))/r2,sig_y*sig_z - cth*sig_y*sig_z - sig_x*sth,
                sig_x*sig_z - cth*sig_x*sig_z - sig_y*sth,sig_y*sig_z - cth*sig_y*sig_z + sig_x*sth,cth*r2 + sz2
            };

#ifdef MCDEBUG
            printf("%s matrix=\n%12.3f %12.3f %12.3f\n%12.3f %12.3f %12.3f\n%12.3f %12.3f %12.3f\n", NAME_CURRENT_COMP,
                m[0][0],m[0][1],m[0][2],m[1][0],m[1][1],m[1][2],m[2][0],m[2][1],m[2][2]
            );
#endif

            /* execute the rotation about the sigma vector */
            kx=m[0][0]*kx0+m[0][1]*ky0+m[0][2]*kz0;
            ky=m[1][0]*kx0+m[1][1]*ky0+m[1][2]*kz0;
            kz=m[2][0]*kx0+m[2][1]*ky0+m[2][2]*kz0;

            /* resolve incoming polarization into sig and pi bits, and scale by sqrt(reflectivity) which is amplitude scale */
            double Esig=(Ex*sig_x+Ey*sig_y+Ez*sig_z), Epi=(Ex*pi_x+Ey*pi_y+Ez*pi_z);
            if(Esig==0 && Epi==0) { /* someone didn't set the polarization direction; set it now to a random value and it will propagate */
                double psi=rand01()*PI/2;
                Esig=cos(psi); Epi=sin(psi);
            }
            Esig=Esig*sqrt(Rsig);
            Epi=Epi*sqrt(Rpi);
            R=Esig*Esig+Epi*Epi; /* projected reflectivity, squared back to intensity */

            /* pi is now a vector perpendicular to k_out and sig i.e. the direction of pi polarization outgoing */
            vec_prod_func(&pi_x, &pi_y, &pi_z, kx, ky, kz, sig_x, sig_y, sig_z);
            NORM(pi_x , pi_y , pi_z );

            /* a linear combination of these is still perpendicular to k, but has the correct polarization weighting */
            Ex=Epi*pi_x+Esig*sig_x;
            Ey=Epi*pi_y+Esig*sig_y;
            Ez=Epi*pi_z+Esig*sig_z;
            NORM(Ex, Ey, Ez);
#ifdef MCDEBUG
            printf("%s: Rsig, Rpi, R, k0, k1, e0, e1: %g %g %g (%g, %g, %g) (%g, %g, %g) (%g, %g, %g) (%g, %g, %g)\n", NAME_CURRENT_COMP,
                   Rsig,  Rpi, R,
                   kx0, ky0, kz0, kx, ky, kz, Ex0, Ey0, Ez0, Ex, Ey, Ez);
#endif
            /* apply Darwin reflectivity if not is supplied from outside*/
            if (!R0){
                p*=R;
            }else{
                p*=R0;
            }
            /*catch dead rays*/
            if (p==0) ABSORB;
        } else {
	  //RESTORE_XRAY(INDEX_CURRENT_COMP, x, y, z, kx, ky, kz, phi, t, Ex, Ey, Ez, p);//
	  x=x0; y=y0; z=z0; kx=kx0; ky=ky0; kz=kz0; phi=phi0; t=t0; Ex=Ex0; Ey=Ey0; Ez=Ez0; p=p0;
        }
    }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p)  ||  isinf(p)) ABSORB;
  if(isnan(t)  ||  isinf(t)) ABSORB;
  if(isnan(phi)  ||  isinf(phi)) ABSORB;
  if(isnan(kx) || isinf(kx)) ABSORB;
  if(isnan(ky) || isinf(ky)) ABSORB;
  if(isnan(kz) || isinf(kz)) ABSORB;
  if(isnan(x)  ||  isinf(x)) ABSORB;
  if(isnan(y)  ||  isinf(y)) ABSORB;
  if(isnan(z)  ||  isinf(z)) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(phi)  ||  isinf(phi)) printf("NAN or INF found in phi, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(kx) || isinf(kx)) printf("NAN or INF found in kx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(ky) || isinf(ky)) printf("NAN or INF found in ky, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(kz) || isinf(kz)) printf("NAN or INF found in kz,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif

if (_comp->_index == 6) { // EXTEND 'dcm_xtal0'
  if (dcm_scatter && !SCATTERED) ABSORB;
}
if (_comp->_index == 8) { // EXTEND 'dcm_xtal1'
  if (dcm_scatter && !SCATTERED) ABSORB;
}

  #undef length
  #undef width
  #undef V
  #undef form_factors
  #undef material
  #undef alpha
  #undef R0
  #undef debye_waller_B
  #undef crystal_type
  #undef h
  #undef k
  #undef l
  #undef structure_factor_scale_r
  #undef structure_factor_scale_i
  #undef Z
  #undef rho
  #undef At
  #undef f_rel
  #undef f_nt
  #undef m_t
  #undef f0_t
  return(_comp);
} /* class_Bragg_crystal_trace */

#pragma acc routine
_class_Slit *class_Slit_trace(_class_Slit *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define radius (_comp->_parameters.radius)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define dist (_comp->_parameters.dist)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_x0 (_comp->_parameters.focus_x0)
  #define focus_y0 (_comp->_parameters.focus_y0)
  SIG_MESSAGE("[_slit_trace] component slit=Slit() TRACE [/usr/share/mcxtrace/3.4-20240304/optics/Slit.comp:84]");

  PROP_Z0;
  if (((radius == 0) && (x<xmin || x>xmax || y<ymin || y>ymax))
      || ((radius != 0) && (x*x + y*y > radius*radius))){
    ABSORB;
  }else{
    SCATTER;
  }

  if ( focus_xw || focus_yh ){
    double posx,posy,posz,pdir,k;
    coords_get(POS_A_CURRENT_COMP,&posx,&posy,&posz);

    /*we have a target behind the slit - so we now consider the ray a Huygens wavelet.*/
    double xf,yf,zf;
    randvec_target_rect_real(&xf, &yf, &zf, &pdir,
        focus_x0-posx,focus_y0-posy,dist, focus_xw, focus_yh, ROT_A_CURRENT_COMP, x, y, z, 0);
    //p*=pdir;
    k=sqrt(scalar_prod(kx,ky,kz,kx,ky,kz));
    kx=(xf-x); ky=(yf-y); kz=(zf-z);
    NORM(kx,ky,kz);
    kx*=k;ky*=k;kz*=k;
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p)  ||  isinf(p)) ABSORB;
  if(isnan(t)  ||  isinf(t)) ABSORB;
  if(isnan(phi)  ||  isinf(phi)) ABSORB;
  if(isnan(kx) || isinf(kx)) ABSORB;
  if(isnan(ky) || isinf(ky)) ABSORB;
  if(isnan(kz) || isinf(kz)) ABSORB;
  if(isnan(x)  ||  isinf(x)) ABSORB;
  if(isnan(y)  ||  isinf(y)) ABSORB;
  if(isnan(z)  ||  isinf(z)) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(phi)  ||  isinf(phi)) printf("NAN or INF found in phi, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(kx) || isinf(kx)) printf("NAN or INF found in kx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(ky) || isinf(ky)) printf("NAN or INF found in ky, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(kz) || isinf(kz)) printf("NAN or INF found in kz,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef radius
  #undef xwidth
  #undef yheight
  #undef dist
  #undef focus_xw
  #undef focus_yh
  #undef focus_x0
  #undef focus_y0
  return(_comp);
} /* class_Slit_trace */

_class_Fluorescence *class_Fluorescence_trace(_class_Fluorescence *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define geometry (_comp->_parameters.geometry)
  #define radius (_comp->_parameters.radius)
  #define thickness (_comp->_parameters.thickness)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define concentric (_comp->_parameters.concentric)
  #define material (_comp->_parameters.material)
  #define packing_factor (_comp->_parameters.packing_factor)
  #define rho (_comp->_parameters.rho)
  #define density (_comp->_parameters.density)
  #define weight (_comp->_parameters.weight)
  #define p_interact (_comp->_parameters.p_interact)
  #define target_x (_comp->_parameters.target_x)
  #define target_y (_comp->_parameters.target_y)
  #define target_z (_comp->_parameters.target_z)
  #define focus_r (_comp->_parameters.focus_r)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_aw (_comp->_parameters.focus_aw)
  #define focus_ah (_comp->_parameters.focus_ah)
  #define target_index (_comp->_parameters.target_index)
  #define flag_compton (_comp->_parameters.flag_compton)
  #define flag_rayleigh (_comp->_parameters.flag_rayleigh)
  #define flag_lorentzian (_comp->_parameters.flag_lorentzian)
  #define order (_comp->_parameters.order)
  #define compound (_comp->_parameters.compound)
  #define cum_massFractions (_comp->_parameters.cum_massFractions)
  #define cum_xs_fluo (_comp->_parameters.cum_xs_fluo)
  #define cum_xs_Compton (_comp->_parameters.cum_xs_Compton)
  #define cum_xs_Rayleigh (_comp->_parameters.cum_xs_Rayleigh)
  #define shape (_comp->_parameters.shape)
  #define offdata (_comp->_parameters.offdata)
  #define n_fluo (_comp->_parameters.n_fluo)
  #define n_Compton (_comp->_parameters.n_Compton)
  #define n_Rayleigh (_comp->_parameters.n_Rayleigh)
  #define p_fluo (_comp->_parameters.p_fluo)
  #define p_Compton (_comp->_parameters.p_Compton)
  #define p_Rayleigh (_comp->_parameters.p_Rayleigh)
  #define reuse_nb (_comp->_parameters.reuse_nb)
  #define reuse_intersect (_comp->_parameters.reuse_intersect)
  #define reuse_ki (_comp->_parameters.reuse_ki)
  #define reuse_l0 (_comp->_parameters.reuse_l0)
  #define reuse_l1 (_comp->_parameters.reuse_l1)
  #define reuse_l2 (_comp->_parameters.reuse_l2)
  #define reuse_l3 (_comp->_parameters.reuse_l3)
  #define reuse_sigma_barn (_comp->_parameters.reuse_sigma_barn)
  #define reuse_cum_xs_fluo (_comp->_parameters.reuse_cum_xs_fluo)
  #define reuse_cum_xs_Compton (_comp->_parameters.reuse_cum_xs_Compton)
  #define reuse_cum_xs_Rayleigh (_comp->_parameters.reuse_cum_xs_Rayleigh)
  #define filename (_comp->_parameters.filename)
  SIG_MESSAGE("[_sample_trace] component sample=Fluorescence() TRACE [/usr/share/mcxtrace/3.4-20240304/samples/Fluorescence.comp:537]");


int    intersect=0;       /* flag to continue/stop */
int    reuse=0;
int    type=-1;
double l0,  l1,  l2,  l3; /* times for intersections */
double dl0, dl1, dl2, dl; /* time intervals */
int    flag_concentric = 0;
int    flag_ishollow   = 0;
double sigma_barn=0, xs[4]; /* cross sections [barn/atom] fluo/Compton/Rayleigh */
double aim_x=0, aim_y=0, aim_z=1;   /* Position of target relative to scattering point */
int    event_counter   = 0;         /* scattering event counter (multiple fluorescence) */
int    force_transmit  = 0;         /* Flag to handle cross-section weighting in case of finite order */

#ifdef OPENACC
#ifdef USE_OFF
off_struct thread_offdata = offdata;
#endif
#else
#define thread_offdata offdata
#endif

double ki_x,ki_y,ki_z,ki,Ei, pi;
double kf_x,kf_y,kf_z,kf,Ef;

/* Store Initial photon state */

ki_x = kx;
ki_y = ky;
ki_z = kz;
ki   = sqrt(kx*kx+ky*ky+kz*kz); //  Angs-1
kf   = ki;
Ei   = K2E*ki; // keV
pi   = p;      // used to test for multiple fluo weighting and order cutoff

do { /* while (intersect) Loop over multiple scattering events */

  // test for a SPLIT event (same particle comes in)
  if (!event_counter && fabs(reuse_ki - ki) < 1e-15) {
    reuse     = 1;
    reuse_nb++;
    // use cached values and skip actual computation
    intersect = reuse_intersect;
    l0        = reuse_l0;
    l1        = reuse_l1;
    l2        = reuse_l2;
    l3        = reuse_l3;
  } else {
    // we have a different event: compute intersection lengths
    
    /* ========================================================================== */
    /*                                   GEOMETRY                                 */
    /* ========================================================================== */

    /* Intersection photon trajectory / sample (sample surface) */
    if (thickness >= 0) {
      if (shape==0)
        intersect=cylinder_intersect(&l0,&l3, x,y,z,kx,ky,kz, radius,yheight);
      else if (shape==1)
        intersect=box_intersect     (&l0,&l3, x,y,z,kx,ky,kz, xwidth,yheight,zdepth);
      else if (shape==2)
        intersect=sphere_intersect  (&l0,&l3, x,y,z,kx,ky,kz, radius);
      #ifdef USE_OFF
      else if (shape == 3)
        intersect=off_x_intersect(&l0, &l3, NULL, NULL, x, y, z, kx,ky,kz, thread_offdata );
      #endif
    } else {
      if (shape==0)
        intersect=cylinder_intersect(&l0,&l3, x,y,z,kx,ky,kz, radius-thickness,
          yheight-2*thickness > 0 ? yheight-2*thickness : yheight);
      else if (shape==1)
        intersect=box_intersect     (&l0,&l3, x,y,z,kx,ky,kz,
          xwidth-2*thickness > 0 ?  xwidth-2*thickness : xwidth,
          yheight-2*thickness > 0 ? yheight-2*thickness : yheight,
          zdepth-2*thickness > 0 ?  zdepth-2*thickness : zdepth);
      else if (shape==2)
        intersect=sphere_intersect  (&l0,&l3, x,y,z,kx,ky,kz, radius-thickness);
      #ifdef USE_OFF
      else if (shape == 3)
        intersect=off_x_intersect(&l0, &l3, NULL, NULL, x, y, z, kx,ky,kz, thread_offdata );
      #endif
    }


    /* Computing the intermediate lengths */
    if (intersect && p_interact >= 0) {
      flag_ishollow = 0;
      if (thickness > 0) {
        if (shape==0 && cylinder_intersect(&l1,&l2, x,y,z,kx,ky,kz, radius-thickness,
          yheight-2*thickness > 0 ? yheight-2*thickness : yheight))
          flag_ishollow=1;
        else if (shape==2 && sphere_intersect   (&l1,&l2, x,y,z,kx,ky,kz, radius-thickness))
          flag_ishollow=1;
        else if (shape==1 && box_intersect(&l1,&l2, x,y,z,kx,ky,kz,
          xwidth-2*thickness > 0 ? xwidth-2*thickness : xwidth,
          yheight-2*thickness > 0 ? yheight-2*thickness : yheight,
          zdepth-2*thickness > 0 ? zdepth-2*thickness : zdepth))
          flag_ishollow=1;
      } else if (thickness<0) {
        if (shape==0 && cylinder_intersect(&l1,&l2, x,y,z,kx,ky,kz, radius,yheight))
          flag_ishollow=1;
        else if (shape==2 && sphere_intersect   (&l1,&l2, x,y,z,kx,ky,kz, radius))
          flag_ishollow=1;
        else if (shape==1 && box_intersect(&l1,&l2, x,y,z,kx,ky,kz, xwidth, yheight, zdepth))
          flag_ishollow=1;
      }
      if (!flag_ishollow) l1 = l2 = l3; /* no empty space inside */
    } /* if intersect */


    // store values for potential next SPLIT
    reuse           = 0;
    reuse_intersect = intersect;
    reuse_l0        = l0;
    reuse_l1        = l1;
    reuse_l2        = l2;
    reuse_l3        = l3;
    reuse_ki        = ki;
  } // if !reuse (SPLIT)

  if (intersect) { /* the photon hits the sample */

    if (l0 > 0) {  /* we are before the sample */
      PROP_DL(l0); /* propagates photon to the entry of the sample */
    } else if (l1 > 0 && l1 > l0) { /* we are inside first part of the sample */
      /* no propagation, stay inside */
    } else if (l2 > 0 && l2 > l1) { /* we are in the hole */
      PROP_DL(l2); /* propagate to inner surface of 2nd part of sample */
    } else if (l3 > 0 && l3 > l2) { /* we are in the 2nd part of sample */
      /* no propagation, stay inside */
    }

    dl0=l1-(l0 > 0 ? l0 : 0); /* Time in first part of hollow/cylinder/box */
    dl1=l2-(l1 > 0 ? l1 : 0); /* Time in hole */
    dl2=l3-(l2 > 0 ? l2 : 0); /* Time in 2nd part of hollow cylinder */

    if (dl0 < 0) dl0 = 0;
    if (dl1 < 0) dl1 = 0;
    if (dl2 < 0) dl2 = 0;

    /* initialize concentric mode */
    if (concentric && !flag_concentric && l0 >= 0
     && shape==0 && thickness) {
      flag_concentric=1;
    }

    if (flag_concentric == 1) {
      dl1=dl2=0; /* force exit when reaching hole/2nd part */
    }

    if (!dl0 && !dl2) {
      intersect = 0; /* the sample was passed entirely */
    }
  } // if intersect (geometry)
    
  /* ========================================================================== */
  /*                             INTERACTION PROCESS                            */
  /* ========================================================================== */

  if (intersect) {
    double my_s;
    int    i_Z,i;
    int    flag=0;
    double d_path, p_trans, p_scatt, mc_trans, mc_scatt;
    
    /* actual fluorescence calculation */
    
    /* compute total scattering cross section for incoming photon energy Ei */
    /* compute each contribution XS */
    xs[FLUORESCENCE]=xs[COMPTON]=xs[RAYLEIGH]=xs[TRANSMISSION]=sigma_barn=0;
    cum_xs_fluo[0] = cum_xs_Compton[0] = cum_xs_Rayleigh[0] = 0;
    if (!reuse) {
      for (i_Z=0; i_Z< compound->nElements; i_Z++) {
        int    Z   = compound->Elements[i_Z];
        double frac= compound->massFractions[i_Z];
        double xs_Z[3];

        // get Fluorescence xs
        XRMC_CrossSections(Z, Ei, xs_Z); // [barn/atom]
        sigma_barn            += frac*CSb_Total(Z, Ei, NULL); // Photo+Compton+Rayleigh
        cum_xs_fluo[i_Z+1]     = cum_xs_fluo[i_Z]    +frac*xs_Z[FLUORESCENCE];
        cum_xs_Compton[i_Z+1]  = cum_xs_Compton[i_Z] +frac*xs_Z[COMPTON];
        cum_xs_Rayleigh[i_Z+1] = cum_xs_Rayleigh[i_Z]+frac*xs_Z[RAYLEIGH];
        for (i=0; i<3; i++) { xs[i] += frac*xs_Z[i]; }
      } // for Z in compound
      
      // store values into cache for SPLIT
      for (i_Z=0; i_Z< compound->nElements; i_Z++) {
        reuse_cum_xs_fluo[i_Z+1]     = cum_xs_fluo[i_Z+1];
        reuse_cum_xs_Compton[i_Z+1]  = cum_xs_Compton[i_Z+1];
        reuse_cum_xs_Rayleigh[i_Z+1] = cum_xs_Rayleigh[i_Z+1];
      }
      reuse_sigma_barn = sigma_barn;
    } else {
      // reuse cached values (SPLIT)
      for (i_Z=0; i_Z< compound->nElements; i_Z++) {
        cum_xs_fluo[i_Z+1]     = reuse_cum_xs_fluo[i_Z+1];
        cum_xs_Compton[i_Z+1]  = reuse_cum_xs_Compton[i_Z+1];
        cum_xs_Rayleigh[i_Z+1] = reuse_cum_xs_Rayleigh[i_Z+1];
        xs[FLUORESCENCE]      += reuse_cum_xs_fluo[i_Z+1];
        xs[COMPTON]           += reuse_cum_xs_Compton[i_Z+1];
        xs[RAYLEIGH]          += reuse_cum_xs_Rayleigh[i_Z+1];
      }
      
      sigma_barn = reuse_sigma_barn;
    }
    
    /* probability to absorb/scatter */
    my_s   = rho*100*sigma_barn; /* mu, 100: convert from barns to fm^2. my_s in [1/m] */
    d_path = ( dl0 +dl2 );  /* total path lenght in sample */
    
    /* Proba of transmission/interaction along length d_path */    
    p_trans = exp(-my_s*d_path); /* probability to not-interact (transmit) */
    //printf("sigma_barn=%g p_trans=%g\n", sigma_barn, p_trans);
    p_scatt = 1 - p_trans;       /* portion of beam which scatters */
    
    /* force a given fraction of the beam to scatter */
    if (p_interact>0 && p_interact<=1) {
      /* we force a portion of the beam to interact */
      /* This is used to improve statistics */
      mc_trans = 1-p_interact;
    } else {
      mc_trans = p_trans; /* 1 - p_scatt */
    }
    mc_scatt = 1 - mc_trans; /* portion of beam to scatter (or force to) */
    if (mc_scatt <= 0) ABSORB;
    
    if (!force_transmit && mc_scatt > 0 && (mc_scatt >= 1 || rand01() < mc_scatt)) { 
      /* we "scatter" with one of the interaction processes */
        
      dl = -log(1 - rand0max((1 - exp(-my_s*d_path)))) / my_s; /* length */

      /* If t0 is in hole, propagate to next part of the hollow cylinder */
      if (dl1 > 0 && dl0 > 0 && dl > dl0) dl += dl1;

      /* photon propagation to the scattering point */
      PROP_DL(dl);
      p *= fabs(p_scatt/mc_scatt); /* account for p_interact, lower than 1 */
      
    } else { // force_transmit
      /* we go through the material without interaction, and exit */
      if (type <0) type = TRANSMISSION; // 3 transmission
      intersect = 0;
      PROP_DL(dl0+dl2);
      /* attenuate beam by portion which is scattered (and left along) */
      p *= p_trans;
      if (p_interact>0 && p_interact<=1) p /= mc_trans;
      break; // end while (intersect)
    }
    
  } /* if intersect (propagate) */

  if (intersect) { /* scattering event */
    int    i_Z, Z;
    double solid_angle;
    double theta, dsigma;
    double Ef, dE;
    
    /* correct for XS total(photo+Compton+Rayleigh) > sum(fluo+Compton+Rayleigh) */
    dsigma = (xs[FLUORESCENCE]+xs[RAYLEIGH]+xs[COMPTON])/sigma_barn;
    if (dsigma < 1) p *= dsigma; // < 1

    /* MC choose process from cross sections 'xs': fluo, Compton, Rayleigh */
    type = XRMC_SelectInteraction(xs);
    
    /* choose Z (element) on associated XS, taking into account mass-fractions */
    switch (type) {
      case FLUORESCENCE:
        i_Z = XRMC_SelectFromDistribution(cum_xs_fluo,     compound->nElements+1);
        break;
      case RAYLEIGH:
        if (!flag_rayleigh) ABSORB;
        i_Z = XRMC_SelectFromDistribution(cum_xs_Rayleigh, compound->nElements+1);
        break;
      case COMPTON:
        if (!flag_compton) ABSORB;
        i_Z = XRMC_SelectFromDistribution(cum_xs_Compton,  compound->nElements+1);
        break;
      default:
        printf("%s: WARNING: process %i unknown. Absorb.\n", NAME_CURRENT_COMP, type);
        ABSORB;
    }
    Z   = compound->Elements[i_Z];
    
    /* select outgoing vector */
    if ((target_x || target_y || target_z)) {
      aim_x = target_x-x;       /* Vector pointing at target (anal./det.) */
      aim_y = target_y-y;
      aim_z = target_z-z;
    }
    if(focus_aw && focus_ah) {
      randvec_target_rect_angular(&kf_x, &kf_y, &kf_z, &solid_angle,
        aim_x, aim_y, aim_z, focus_aw, focus_ah, ROT_A_CURRENT_COMP);
    } else if(focus_xw && focus_yh) {
      randvec_target_rect(&kf_x, &kf_y, &kf_z, &solid_angle,
        aim_x, aim_y, aim_z, focus_xw, focus_yh, ROT_A_CURRENT_COMP);
    } else {
      randvec_target_circle(&kf_x, &kf_y, &kf_z, &solid_angle, aim_x, aim_y, aim_z, focus_r);
    }
    p *= solid_angle/(4*PI); // correct for selected solid-angle
    NORM(kf_x, kf_y, kf_z);  // normalize the outout direction |kf|=1
    
    // determine final energy
    switch (type) {
      case FLUORESCENCE: /* 0 Fluo: choose line */
        n_fluo++;
        p_fluo += p;
        Ef      = XRMC_SelectFluorescenceEnergy(Z, Ei, &dE);      // dE in keV
        if (dE) {
          if (flag_lorentzian) dE  *= tan(PI/2*randpm1()); // Lorentzian distribution
          else                 dE  *= randnorm();          // Gaussian distribution
          Ef = Ef + dE;
        }
        kf      = Ef*E2K;
        break;
        
      case RAYLEIGH:     /* 1 Rayleigh: Coherent, elastic    */
        n_Rayleigh++;
        p_Rayleigh += p;
        theta      = acos(scalar_prod(kf_x,kf_y, kf_z,ki_x, ki_y,ki_z)/ki);
        dsigma     = DCSb_Rayl(Z,  Ei, theta, NULL); // [barn/at/st]
        p         *= 4*PI*dsigma/xs[RAYLEIGH];
        break;
      
      case COMPTON:      /* 2 Compton: Incoherent: choose final energy */
        n_Compton++;
        p_Compton += p;
        theta      = acos(scalar_prod(kf_x,kf_y, kf_z,ki_x, ki_y,ki_z)/ki);
        dsigma     = DCS_Compt(Z,  Ei, theta, NULL); // [barn/at/st]
        kf         = ComptonEnergy(Ei, theta, NULL)*E2K; /* XRayLib */
        p         *= 4*PI*dsigma/xs[COMPTON];
        break;
    }
    Ef = K2E*kf;
    
    kx = kf*kf_x;
    ky = kf*kf_y;
    kz = kf*kf_z;
    SCATTER;
    event_counter++;
    
    /* exit if multiple scattering order has been reached */
    if (!order) break; // skip final absorption
    // stop when order has been reached, or weighting is very low
    if (order && (event_counter >= order || p/pi < 1e-7)) { force_transmit=1; }
 
  } // if intersect (scatter)
} while(intersect); /* end do (intersect) (multiple scattering loop) */

#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p)  ||  isinf(p)) ABSORB;
  if(isnan(t)  ||  isinf(t)) ABSORB;
  if(isnan(phi)  ||  isinf(phi)) ABSORB;
  if(isnan(kx) || isinf(kx)) ABSORB;
  if(isnan(ky) || isinf(ky)) ABSORB;
  if(isnan(kz) || isinf(kz)) ABSORB;
  if(isnan(x)  ||  isinf(x)) ABSORB;
  if(isnan(y)  ||  isinf(y)) ABSORB;
  if(isnan(z)  ||  isinf(z)) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(phi)  ||  isinf(phi)) printf("NAN or INF found in phi, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(kx) || isinf(kx)) printf("NAN or INF found in kx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(ky) || isinf(ky)) printf("NAN or INF found in ky, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(kz) || isinf(kz)) printf("NAN or INF found in kz,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef geometry
  #undef radius
  #undef thickness
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef concentric
  #undef material
  #undef packing_factor
  #undef rho
  #undef density
  #undef weight
  #undef p_interact
  #undef target_x
  #undef target_y
  #undef target_z
  #undef focus_r
  #undef focus_xw
  #undef focus_yh
  #undef focus_aw
  #undef focus_ah
  #undef target_index
  #undef flag_compton
  #undef flag_rayleigh
  #undef flag_lorentzian
  #undef order
  #undef compound
  #undef cum_massFractions
  #undef cum_xs_fluo
  #undef cum_xs_Compton
  #undef cum_xs_Rayleigh
  #undef shape
  #undef offdata
  #undef n_fluo
  #undef n_Compton
  #undef n_Rayleigh
  #undef p_fluo
  #undef p_Compton
  #undef p_Rayleigh
  #undef reuse_nb
  #undef reuse_intersect
  #undef reuse_ki
  #undef reuse_l0
  #undef reuse_l1
  #undef reuse_l2
  #undef reuse_l3
  #undef reuse_sigma_barn
  #undef reuse_cum_xs_fluo
  #undef reuse_cum_xs_Compton
  #undef reuse_cum_xs_Rayleigh
  #undef filename
  return(_comp);
} /* class_Fluorescence_trace */

/* *****************************************************************************
* instrument 'SOLEIL_PSICHE' TRACE
***************************************************************************** */

#ifndef FUNNEL
#pragma acc routine
int raytrace(_class_particle* _particle) { /* single event propagation, called by mccode_main for SOLEIL_PSICHE:TRACE */

  /* init variables and counters for TRACE */
  #undef ABSORB0
  #undef ABSORB
  #define ABSORB0 do { DEBUG_ABSORB(); ABSORBED++; return(ABSORBED);} while(0)
  #define ABSORB ABSORB0
  DEBUG_ENTER();
  DEBUG_STATE();
  _particle->flag_nocoordschange=0; /* Init */
  _class_particle _particle_save;
  /* the main iteration loop for one incoming event */
  while (!ABSORBED) { /* iterate event until absorbed */
    /* send particle event to component instance, one after the other */
    /* begin component origin=Progress_bar() [1] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_origin_var._rotation_is_identity) {
        if(!_origin_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _origin_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_origin_var._position_relative, _origin_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 1) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_origin_var._name);
      DEBUG_STATE();
      class_Progress_bar_trace(&_origin_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component origin [1] */
    /* begin component source=Wiggler() [2] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_source_var._rotation_is_identity) {
        if(!_source_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _source_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_source_var._position_relative, _source_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 2) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_source_var._name);
      DEBUG_STATE();
      class_Wiggler_trace(&_source_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component source [2] */
    /* begin component mon_src_e=Monitor_nD() [3] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_mon_src_e_var._rotation_is_identity) {
        if(!_mon_src_e_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _mon_src_e_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_mon_src_e_var._position_relative, _mon_src_e_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 3) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_mon_src_e_var._name);
      DEBUG_STATE();
      class_Monitor_nD_trace(&_mon_src_e_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component mon_src_e [3] */
    /* begin component mon_src_xy=Monitor_nD() [4] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_mon_src_xy_var._rotation_is_identity) {
        if(!_mon_src_xy_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _mon_src_xy_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_mon_src_xy_var._position_relative, _mon_src_xy_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 4) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_mon_src_xy_var._name);
      DEBUG_STATE();
      class_Monitor_nD_trace(&_mon_src_xy_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component mon_src_xy [4] */
    /* begin component DCM_location=Arm() [5] */
    if (!ABSORBED && _particle->_index == 5) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component DCM_location [5] */
    /* begin component dcm_xtal0=Bragg_crystal() [6] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_dcm_xtal0_var._rotation_is_identity) {
        if(!_dcm_xtal0_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _dcm_xtal0_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_dcm_xtal0_var._position_relative, _dcm_xtal0_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 6) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_dcm_xtal0_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.DCM_present ))) // conditional WHEN execution
      class_Bragg_crystal_trace(&_dcm_xtal0_var, _particle); /* contains EXTEND code */
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component dcm_xtal0 [6] */
    /* begin component dcm0=Arm() [7] */
    if (!ABSORBED && _particle->_index == 7) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component dcm0 [7] */
    /* begin component dcm_xtal1=Bragg_crystal() [8] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_dcm_xtal1_var._rotation_is_identity) {
        if(!_dcm_xtal1_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _dcm_xtal1_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_dcm_xtal1_var._position_relative, _dcm_xtal1_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 8) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_dcm_xtal1_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.DCM_present ))) // conditional WHEN execution
      class_Bragg_crystal_trace(&_dcm_xtal1_var, _particle); /* contains EXTEND code */
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component dcm_xtal1 [8] */
    /* begin component dcm1=Arm() [9] */
    if (!ABSORBED && _particle->_index == 9) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component dcm1 [9] */
    /* begin component mon_dcm_e=Monitor_nD() [10] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_mon_dcm_e_var._rotation_is_identity) {
        if(!_mon_dcm_e_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _mon_dcm_e_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_mon_dcm_e_var._position_relative, _mon_dcm_e_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 10) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_mon_dcm_e_var._name);
      DEBUG_STATE();
      class_Monitor_nD_trace(&_mon_dcm_e_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component mon_dcm_e [10] */
    /* begin component mon_dcm_xy=Monitor_nD() [11] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_mon_dcm_xy_var._rotation_is_identity) {
        if(!_mon_dcm_xy_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _mon_dcm_xy_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_mon_dcm_xy_var._position_relative, _mon_dcm_xy_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 11) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_mon_dcm_xy_var._name);
      DEBUG_STATE();
      class_Monitor_nD_trace(&_mon_dcm_xy_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component mon_dcm_xy [11] */
    /* begin component slit=Slit() [12] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_slit_var._rotation_is_identity) {
        if(!_slit_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _slit_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_slit_var._position_relative, _slit_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 12) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_slit_var._name);
      DEBUG_STATE();
      class_Slit_trace(&_slit_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component slit [12] */
    /* begin component sample_stage=Arm() [13] */
    if (!ABSORBED && _particle->_index == 13) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component sample_stage [13] */
    /* begin component sample=Fluorescence() [14] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_sample_var._rotation_is_identity) {
        if(!_sample_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _sample_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_sample_var._position_relative, _sample_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 14) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_sample_var._name);
      DEBUG_STATE();
      class_Fluorescence_trace(&_sample_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component sample [14] */
    /* begin component fluo_holder=Arm() [15] */
    if (!ABSORBED && _particle->_index == 15) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component fluo_holder [15] */
    /* begin component mon_spl_fluo=Monitor_nD() [16] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_mon_spl_fluo_var._rotation_is_identity) {
        if(!_mon_spl_fluo_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _mon_spl_fluo_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_mon_spl_fluo_var._position_relative, _mon_spl_fluo_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 16) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_mon_spl_fluo_var._name);
      DEBUG_STATE();
      class_Monitor_nD_trace(&_mon_spl_fluo_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component mon_spl_fluo [16] */
    /* begin component mon_spl_e=Monitor_nD() [17] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_mon_spl_e_var._rotation_is_identity) {
        if(!_mon_spl_e_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _mon_spl_e_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_mon_spl_e_var._position_relative, _mon_spl_e_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 17) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_mon_spl_e_var._name);
      DEBUG_STATE();
      class_Monitor_nD_trace(&_mon_spl_e_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component mon_spl_e [17] */
    /* begin component mon_spl_xy=Monitor_nD() [18] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_mon_spl_xy_var._rotation_is_identity) {
        if(!_mon_spl_xy_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _mon_spl_xy_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_mon_spl_xy_var._position_relative, _mon_spl_xy_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 18) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_mon_spl_xy_var._name);
      DEBUG_STATE();
      class_Monitor_nD_trace(&_mon_spl_xy_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component mon_spl_xy [18] */
    if (_particle->_index > 18)
      ABSORBED++; /* absorbed when passed all components */
  } /* while !ABSORBED */

  DEBUG_LEAVE()
  particle_restore(_particle, &_particle_save);
  DEBUG_STATE()

  return(_particle->_index);
} /* raytrace */

/* loop to generate events and call raytrace() propagate them */
void raytrace_all(unsigned long long ncount, unsigned long seed) {

  /* CPU-loop */
  unsigned long long loops;
  loops = ceil((double)ncount/gpu_innerloop);
  /* if on GPU, printf has been globally nullified, re-enable here */
  #ifdef OPENACC
  #ifndef MULTICORE
  #undef printf
  #endif
  #endif

  #ifdef OPENACC
  if (ncount>gpu_innerloop) {
    printf("Defining %llu CPU loops around GPU kernel and adjusting ncount\n",loops);
    mcset_ncount(loops*gpu_innerloop);
  } else {
    #endif
    loops=1;
    gpu_innerloop = ncount;
    #ifdef OPENACC
  }
    #endif

  for (unsigned long long cloop=0; cloop<loops; cloop++) {
    #ifdef OPENACC
    if (loops>1) fprintf(stdout, "%d..", (int)cloop); fflush(stdout);
    #endif

    /* if on GPU, re-nullify printf */
    #ifdef OPENACC
    #ifndef MULTICORE
    #define printf(...) noprintf()
    #endif
    #endif

    #pragma acc parallel loop num_gangs(numgangs) vector_length(vecsize)
    for (unsigned long pidx=0 ; pidx < gpu_innerloop ; pidx++) {
      _class_particle particleN = mcgenstate(); // initial particle
      _class_particle* _particle = &particleN;
      particleN._uid = pidx;
      #ifdef USE_MPI
      particleN._uid += mpi_node_rank * ncount; 
      #endif

      srandom(_hash((pidx+1)*(seed+1)));
      particle_uservar_init(_particle);

      raytrace(_particle);
    } /* inner for */
    seed = seed+gpu_innerloop;
  } /* CPU for */
  /* if on GPU, printf has been globally nullified, re-enable here */
  #ifdef OPENACC
  #ifndef MULTICORE
  #undef printf
  #endif
  #endif
  MPI_MASTER(
  printf("*** TRACE end *** \n");
  );
} /* raytrace_all */

#endif //no-FUNNEL

#ifdef FUNNEL
// Alternative raytrace algorithm which iterates all particles through
// one component at the time, can remove absorbs from the next loop and
// switch between cpu/gpu.
void raytrace_all_funnel(unsigned long long ncount, unsigned long seed) {

  // set up outer (CPU) loop / particle batches
  unsigned long long loops;

  /* if on GPU, printf has been globally nullified, re-enable here */
  #ifdef OPENACC
  #ifndef MULTICORE
  #undef printf
  #endif
  #endif

  #ifdef OPENACC
  loops = ceil((double)ncount/gpu_innerloop);
  if (ncount>gpu_innerloop) {
    printf("Defining %llu CPU loops around kernel and adjusting ncount\n",loops);
    mcset_ncount(loops*gpu_innerloop);
  } else {
  #endif
    loops=1;
    gpu_innerloop = ncount;
  #ifdef OPENACC
  }
  #endif

  // create particles struct and pointer arrays (same memory used by all batches)
  _class_particle* particles = malloc(gpu_innerloop*sizeof(_class_particle));
  _class_particle* pbuffer = malloc(gpu_innerloop*sizeof(_class_particle));
  long livebatchsize = gpu_innerloop;

  #undef ABSORB0
  #undef ABSORB
  #define ABSORB0 do { DEBUG_ABSORB(); MAGNET_OFF; ABSORBED++; } while(0)
  #define ABSORB ABSORB0
  // outer loop / particle batches
  for (unsigned long long cloop=0; cloop<loops; cloop++) {
    if (loops>1) fprintf(stdout, "%d..", (int)cloop); fflush(stdout);

    // init particles
    #pragma acc parallel loop present(particles)
    for (unsigned long pidx=0 ; pidx < livebatchsize ; pidx++) {
      // generate particle state, set loop index and seed
      particles[pidx] = mcgenstate();
      _class_particle* _particle = particles + pidx;
      _particle->_uid = pidx;
      #ifdef USE_MPI
      _particle->_uid += mpi_node_rank * ncount; 
      #endif
      srandom(_hash((pidx+1)*(seed+1))); // _particle->state usage built into srandom macro
      particle_uservar_init(_particle);
    }

    // iterate components

    #pragma acc parallel loop present(particles)
    for (unsigned long pidx=0 ; pidx < livebatchsize ; pidx++) {
      _class_particle* _particle = &particles[pidx];
      _class_particle _particle_save;

      // origin
    if (!ABSORBED && _particle->_index == 1) {
        if (_origin_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _origin_var._position_relative),&x, &y, &z);
        else
          mccoordschange(_origin_var._position_relative, _origin_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Progress_bar_trace(&_origin_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // source
    if (!ABSORBED && _particle->_index == 2) {
        if (_source_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _source_var._position_relative),&x, &y, &z);
        else
          mccoordschange(_source_var._position_relative, _source_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Wiggler_trace(&_source_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // mon_src_e
    if (!ABSORBED && _particle->_index == 3) {
        if (_mon_src_e_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _mon_src_e_var._position_relative),&x, &y, &z);
        else
          mccoordschange(_mon_src_e_var._position_relative, _mon_src_e_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Monitor_nD_trace(&_mon_src_e_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // mon_src_xy
    if (!ABSORBED && _particle->_index == 4) {
        if (_mon_src_xy_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _mon_src_xy_var._position_relative),&x, &y, &z);
        else
          mccoordschange(_mon_src_xy_var._position_relative, _mon_src_xy_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Monitor_nD_trace(&_mon_src_xy_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // DCM_location
    if (!ABSORBED && _particle->_index == 5) {
        _particle->_index++;
      }

      // dcm_xtal0
    if (!ABSORBED && _particle->_index == 6) {
        if (_dcm_xtal0_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _dcm_xtal0_var._position_relative),&x, &y, &z);
        else
          mccoordschange(_dcm_xtal0_var._position_relative, _dcm_xtal0_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.DCM_present ))) // conditional WHEN
        class_Bragg_crystal_trace(&_dcm_xtal0_var, _particle); /* contains EXTEND code */
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // dcm0
    if (!ABSORBED && _particle->_index == 7) {
        _particle->_index++;
      }

      // dcm_xtal1
    if (!ABSORBED && _particle->_index == 8) {
        if (_dcm_xtal1_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _dcm_xtal1_var._position_relative),&x, &y, &z);
        else
          mccoordschange(_dcm_xtal1_var._position_relative, _dcm_xtal1_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.DCM_present ))) // conditional WHEN
        class_Bragg_crystal_trace(&_dcm_xtal1_var, _particle); /* contains EXTEND code */
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // dcm1
    if (!ABSORBED && _particle->_index == 9) {
        _particle->_index++;
      }

      // mon_dcm_e
    if (!ABSORBED && _particle->_index == 10) {
        if (_mon_dcm_e_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _mon_dcm_e_var._position_relative),&x, &y, &z);
        else
          mccoordschange(_mon_dcm_e_var._position_relative, _mon_dcm_e_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Monitor_nD_trace(&_mon_dcm_e_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // mon_dcm_xy
    if (!ABSORBED && _particle->_index == 11) {
        if (_mon_dcm_xy_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _mon_dcm_xy_var._position_relative),&x, &y, &z);
        else
          mccoordschange(_mon_dcm_xy_var._position_relative, _mon_dcm_xy_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Monitor_nD_trace(&_mon_dcm_xy_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // slit
    if (!ABSORBED && _particle->_index == 12) {
        if (_slit_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _slit_var._position_relative),&x, &y, &z);
        else
          mccoordschange(_slit_var._position_relative, _slit_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Slit_trace(&_slit_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // sample_stage
    if (!ABSORBED && _particle->_index == 13) {
        _particle->_index++;
      }
        #define JUMP_FUNNEL
    }

    for (unsigned long pidx=0 ; pidx < livebatchsize ; pidx++) {
      _class_particle* _particle = &particles[pidx];
      _class_particle _particle_save;

      // sample
    if (!ABSORBED && _particle->_index == 14) {
        if (_sample_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _sample_var._position_relative),&x, &y, &z);
        else
          mccoordschange(_sample_var._position_relative, _sample_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Fluorescence_trace(&_sample_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }
    }

    #pragma acc parallel loop present(particles)
    for (unsigned long pidx=0 ; pidx < livebatchsize ; pidx++) {
      _class_particle* _particle = &particles[pidx];
      _class_particle _particle_save;

      // fluo_holder
    if (!ABSORBED && _particle->_index == 15) {
        _particle->_index++;
      }

      // mon_spl_fluo
    if (!ABSORBED && _particle->_index == 16) {
        if (_mon_spl_fluo_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _mon_spl_fluo_var._position_relative),&x, &y, &z);
        else
          mccoordschange(_mon_spl_fluo_var._position_relative, _mon_spl_fluo_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Monitor_nD_trace(&_mon_spl_fluo_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // mon_spl_e
    if (!ABSORBED && _particle->_index == 17) {
        if (_mon_spl_e_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _mon_spl_e_var._position_relative),&x, &y, &z);
        else
          mccoordschange(_mon_spl_e_var._position_relative, _mon_spl_e_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Monitor_nD_trace(&_mon_spl_e_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // mon_spl_xy
    if (!ABSORBED && _particle->_index == 18) {
        if (_mon_spl_xy_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _mon_spl_xy_var._position_relative),&x, &y, &z);
        else
          mccoordschange(_mon_spl_xy_var._position_relative, _mon_spl_xy_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Monitor_nD_trace(&_mon_spl_xy_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

    }

    // jump to next viable seed
    seed = seed + gpu_innerloop;
  } // outer loop / particle batches

  free(particles);
  free(pbuffer);

  printf("\n");
} /* raytrace_all_funnel */
#endif // FUNNEL

#undef x
#undef y
#undef z
#undef kx
#undef ky
#undef kz
#undef phi
#undef t
#undef Ex
#undef Ey
#undef Ez
#undef p
#undef _mctmp_a
#undef _mctmp_b
#undef _mctmp_c
#ifdef OPENACC
#ifndef MULTICORE
#undef strlen
#undef strcmp
#undef exit
#undef printf
#undef sprintf
#undef fprintf
#endif
#endif
#undef SCATTERED
#undef RESTORE
#undef RESTORE_XRAY
#undef STORE_XRAY
#undef ABSORBED
#undef ABSORB
#undef ABSORB0
/* *****************************************************************************
* instrument 'SOLEIL_PSICHE' and components SAVE
***************************************************************************** */

_class_Progress_bar *class_Progress_bar_save(_class_Progress_bar *_comp
) {
  #define profile (_comp->_parameters.profile)
  #define percent (_comp->_parameters.percent)
  #define flag_save (_comp->_parameters.flag_save)
  #define minutes (_comp->_parameters.minutes)
  #define IntermediateCnts (_comp->_parameters.IntermediateCnts)
  #define StartTime (_comp->_parameters.StartTime)
  #define EndTime (_comp->_parameters.EndTime)
  #define CurrentTime (_comp->_parameters.CurrentTime)
  SIG_MESSAGE("[_origin_save] component origin=Progress_bar() SAVE [/usr/share/mcxtrace/3.4-20240304/misc/Progress_bar.comp:123]");

  MPI_MASTER(fprintf(stdout, "\nSave [%s]\n", instrument_name););
  if (profile && strlen(profile) && strcmp(profile,"NULL") && strcmp(profile,"0")) {
    char filename[256];
    if (!strlen(profile) || !strcmp(profile,"NULL") || !strcmp(profile,"0")) strcpy(filename, instrument_name);
    else strcpy(filename, profile);
    DETECTOR_OUT_1D(
        "Intensity profiler",
        "Component index [1]",
        "Intensity",
        "prof", 1, mcNUMCOMP, mcNUMCOMP-1,
        &(instrument->counter_N[1]),&(instrument->counter_P[1]),&(instrument->counter_P2[1]),
        filename);

  }
  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  return(_comp);
} /* class_Progress_bar_save */

_class_Monitor_nD *class_Monitor_nD_save(_class_Monitor_nD *_comp
) {
  #define user1 (_comp->_parameters.user1)
  #define user2 (_comp->_parameters.user2)
  #define user3 (_comp->_parameters.user3)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define bins (_comp->_parameters.bins)
  #define min (_comp->_parameters.min)
  #define max (_comp->_parameters.max)
  #define restore_xray (_comp->_parameters.restore_xray)
  #define radius (_comp->_parameters.radius)
  #define options (_comp->_parameters.options)
  #define filename (_comp->_parameters.filename)
  #define geometry (_comp->_parameters.geometry)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define username1 (_comp->_parameters.username1)
  #define username2 (_comp->_parameters.username2)
  #define username3 (_comp->_parameters.username3)
  #define DEFS (_comp->_parameters.DEFS)
  #define Vars (_comp->_parameters.Vars)
  #define detector (_comp->_parameters.detector)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_mon_src_e_save] component mon_src_e=Monitor_nD() SAVE [/usr/share/mcxtrace/3.4-20240304/monitors/Monitor_nD.comp:530]");

if (!nowritefile) {
  /* save results, but do not free pointers */
  detector = Monitor_nD_Save(&DEFS, &Vars);
}
  #undef user1
  #undef user2
  #undef user3
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef bins
  #undef min
  #undef max
  #undef restore_xray
  #undef radius
  #undef options
  #undef filename
  #undef geometry
  #undef nowritefile
  #undef username1
  #undef username2
  #undef username3
  #undef DEFS
  #undef Vars
  #undef detector
  #undef offdata
  return(_comp);
} /* class_Monitor_nD_save */



int save(FILE *handle) { /* called by mccode_main for SOLEIL_PSICHE:SAVE */
  if (!handle) siminfo_init(NULL);

  /* call iteratively all components SAVE */
  class_Progress_bar_save(&_origin_var);


  class_Monitor_nD_save(&_mon_src_e_var);

  class_Monitor_nD_save(&_mon_src_xy_var);






  class_Monitor_nD_save(&_mon_dcm_e_var);

  class_Monitor_nD_save(&_mon_dcm_xy_var);





  class_Monitor_nD_save(&_mon_spl_fluo_var);

  class_Monitor_nD_save(&_mon_spl_e_var);

  class_Monitor_nD_save(&_mon_spl_xy_var);

  if (!handle) siminfo_close(); 

  return(0);
} /* save */

/* *****************************************************************************
* instrument 'SOLEIL_PSICHE' and components FINALLY
***************************************************************************** */

_class_Progress_bar *class_Progress_bar_finally(_class_Progress_bar *_comp
) {
  #define profile (_comp->_parameters.profile)
  #define percent (_comp->_parameters.percent)
  #define flag_save (_comp->_parameters.flag_save)
  #define minutes (_comp->_parameters.minutes)
  #define IntermediateCnts (_comp->_parameters.IntermediateCnts)
  #define StartTime (_comp->_parameters.StartTime)
  #define EndTime (_comp->_parameters.EndTime)
  #define CurrentTime (_comp->_parameters.CurrentTime)
  SIG_MESSAGE("[_origin_finally] component origin=Progress_bar() FINALLY [/usr/share/mcxtrace/3.4-20240304/misc/Progress_bar.comp:141]");

  time_t NowTime;
  time(&NowTime);
  fprintf(stdout, "\nFinally [%s: %s]. Time: ", instrument_name, dirname ? dirname : ".");
  if (difftime(NowTime,StartTime) < 60.0)
    fprintf(stdout, "%g [s] ", difftime(NowTime,StartTime));
  else if (difftime(NowTime,StartTime) > 3600.0)
    fprintf(stdout, "%g [h] ", difftime(NowTime,StartTime)/3600.0);
  else
    fprintf(stdout, "%g [min] ", difftime(NowTime,StartTime)/60.0);
  fprintf(stdout, "\n");
  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  return(_comp);
} /* class_Progress_bar_finally */

_class_Monitor_nD *class_Monitor_nD_finally(_class_Monitor_nD *_comp
) {
  #define user1 (_comp->_parameters.user1)
  #define user2 (_comp->_parameters.user2)
  #define user3 (_comp->_parameters.user3)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define bins (_comp->_parameters.bins)
  #define min (_comp->_parameters.min)
  #define max (_comp->_parameters.max)
  #define restore_xray (_comp->_parameters.restore_xray)
  #define radius (_comp->_parameters.radius)
  #define options (_comp->_parameters.options)
  #define filename (_comp->_parameters.filename)
  #define geometry (_comp->_parameters.geometry)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define username1 (_comp->_parameters.username1)
  #define username2 (_comp->_parameters.username2)
  #define username3 (_comp->_parameters.username3)
  #define DEFS (_comp->_parameters.DEFS)
  #define Vars (_comp->_parameters.Vars)
  #define detector (_comp->_parameters.detector)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_mon_src_e_finally] component mon_src_e=Monitor_nD() FINALLY [/usr/share/mcxtrace/3.4-20240304/monitors/Monitor_nD.comp:538]");

  /* free pointers */
  Monitor_nD_Finally(&DEFS, &Vars);
  #undef user1
  #undef user2
  #undef user3
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef bins
  #undef min
  #undef max
  #undef restore_xray
  #undef radius
  #undef options
  #undef filename
  #undef geometry
  #undef nowritefile
  #undef username1
  #undef username2
  #undef username3
  #undef DEFS
  #undef Vars
  #undef detector
  #undef offdata
  return(_comp);
} /* class_Monitor_nD_finally */

_class_Fluorescence *class_Fluorescence_finally(_class_Fluorescence *_comp
) {
  #define geometry (_comp->_parameters.geometry)
  #define radius (_comp->_parameters.radius)
  #define thickness (_comp->_parameters.thickness)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define concentric (_comp->_parameters.concentric)
  #define material (_comp->_parameters.material)
  #define packing_factor (_comp->_parameters.packing_factor)
  #define rho (_comp->_parameters.rho)
  #define density (_comp->_parameters.density)
  #define weight (_comp->_parameters.weight)
  #define p_interact (_comp->_parameters.p_interact)
  #define target_x (_comp->_parameters.target_x)
  #define target_y (_comp->_parameters.target_y)
  #define target_z (_comp->_parameters.target_z)
  #define focus_r (_comp->_parameters.focus_r)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_aw (_comp->_parameters.focus_aw)
  #define focus_ah (_comp->_parameters.focus_ah)
  #define target_index (_comp->_parameters.target_index)
  #define flag_compton (_comp->_parameters.flag_compton)
  #define flag_rayleigh (_comp->_parameters.flag_rayleigh)
  #define flag_lorentzian (_comp->_parameters.flag_lorentzian)
  #define order (_comp->_parameters.order)
  #define compound (_comp->_parameters.compound)
  #define cum_massFractions (_comp->_parameters.cum_massFractions)
  #define cum_xs_fluo (_comp->_parameters.cum_xs_fluo)
  #define cum_xs_Compton (_comp->_parameters.cum_xs_Compton)
  #define cum_xs_Rayleigh (_comp->_parameters.cum_xs_Rayleigh)
  #define shape (_comp->_parameters.shape)
  #define offdata (_comp->_parameters.offdata)
  #define n_fluo (_comp->_parameters.n_fluo)
  #define n_Compton (_comp->_parameters.n_Compton)
  #define n_Rayleigh (_comp->_parameters.n_Rayleigh)
  #define p_fluo (_comp->_parameters.p_fluo)
  #define p_Compton (_comp->_parameters.p_Compton)
  #define p_Rayleigh (_comp->_parameters.p_Rayleigh)
  #define reuse_nb (_comp->_parameters.reuse_nb)
  #define reuse_intersect (_comp->_parameters.reuse_intersect)
  #define reuse_ki (_comp->_parameters.reuse_ki)
  #define reuse_l0 (_comp->_parameters.reuse_l0)
  #define reuse_l1 (_comp->_parameters.reuse_l1)
  #define reuse_l2 (_comp->_parameters.reuse_l2)
  #define reuse_l3 (_comp->_parameters.reuse_l3)
  #define reuse_sigma_barn (_comp->_parameters.reuse_sigma_barn)
  #define reuse_cum_xs_fluo (_comp->_parameters.reuse_cum_xs_fluo)
  #define reuse_cum_xs_Compton (_comp->_parameters.reuse_cum_xs_Compton)
  #define reuse_cum_xs_Rayleigh (_comp->_parameters.reuse_cum_xs_Rayleigh)
  #define filename (_comp->_parameters.filename)
  SIG_MESSAGE("[_sample_finally] component sample=Fluorescence() FINALLY [/usr/share/mcxtrace/3.4-20240304/samples/Fluorescence.comp:888]");

  FreeCompoundData(compound);
  if (filename && filename != material)
    unlink(filename);
  printf("%s: scattered intensity: fluo=%g Compton=%g Rayleigh=%g\n", 
    NAME_CURRENT_COMP, p_fluo, p_Compton, p_Rayleigh);
  #undef geometry
  #undef radius
  #undef thickness
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef concentric
  #undef material
  #undef packing_factor
  #undef rho
  #undef density
  #undef weight
  #undef p_interact
  #undef target_x
  #undef target_y
  #undef target_z
  #undef focus_r
  #undef focus_xw
  #undef focus_yh
  #undef focus_aw
  #undef focus_ah
  #undef target_index
  #undef flag_compton
  #undef flag_rayleigh
  #undef flag_lorentzian
  #undef order
  #undef compound
  #undef cum_massFractions
  #undef cum_xs_fluo
  #undef cum_xs_Compton
  #undef cum_xs_Rayleigh
  #undef shape
  #undef offdata
  #undef n_fluo
  #undef n_Compton
  #undef n_Rayleigh
  #undef p_fluo
  #undef p_Compton
  #undef p_Rayleigh
  #undef reuse_nb
  #undef reuse_intersect
  #undef reuse_ki
  #undef reuse_l0
  #undef reuse_l1
  #undef reuse_l2
  #undef reuse_l3
  #undef reuse_sigma_barn
  #undef reuse_cum_xs_fluo
  #undef reuse_cum_xs_Compton
  #undef reuse_cum_xs_Rayleigh
  #undef filename
  return(_comp);
} /* class_Fluorescence_finally */



int finally(void) { /* called by mccode_main for SOLEIL_PSICHE:FINALLY */
#pragma acc update host(_origin_var)
#pragma acc update host(_source_var)
#pragma acc update host(_mon_src_e_var)
#pragma acc update host(_mon_src_xy_var)
#pragma acc update host(_DCM_location_var)
#pragma acc update host(_dcm_xtal0_var)
#pragma acc update host(_dcm0_var)
#pragma acc update host(_dcm_xtal1_var)
#pragma acc update host(_dcm1_var)
#pragma acc update host(_mon_dcm_e_var)
#pragma acc update host(_mon_dcm_xy_var)
#pragma acc update host(_slit_var)
#pragma acc update host(_sample_stage_var)
#pragma acc update host(_sample_var)
#pragma acc update host(_fluo_holder_var)
#pragma acc update host(_mon_spl_fluo_var)
#pragma acc update host(_mon_spl_e_var)
#pragma acc update host(_mon_spl_xy_var)
#pragma acc update host(_instrument_var)

  siminfo_init(NULL);
  save(siminfo_file); /* save data when simulation ends */

  /* call iteratively all components FINALLY */
  class_Progress_bar_finally(&_origin_var);


  class_Monitor_nD_finally(&_mon_src_e_var);

  class_Monitor_nD_finally(&_mon_src_xy_var);






  class_Monitor_nD_finally(&_mon_dcm_e_var);

  class_Monitor_nD_finally(&_mon_dcm_xy_var);



  class_Fluorescence_finally(&_sample_var);


  class_Monitor_nD_finally(&_mon_spl_fluo_var);

  class_Monitor_nD_finally(&_mon_spl_e_var);

  class_Monitor_nD_finally(&_mon_spl_xy_var);

  siminfo_close(); 

  return(0);
} /* finally */

/* *****************************************************************************
* instrument 'SOLEIL_PSICHE' and components DISPLAY
***************************************************************************** */

  #define magnify     mcdis_magnify
  #define line        mcdis_line
  #define dashed_line mcdis_dashed_line
  #define multiline   mcdis_multiline
  #define rectangle   mcdis_rectangle
  #define box         mcdis_box
  #define circle      mcdis_circle
  #define cylinder    mcdis_cylinder
  #define sphere      mcdis_sphere
_class_Progress_bar *class_Progress_bar_display(_class_Progress_bar *_comp
) {
  #define profile (_comp->_parameters.profile)
  #define percent (_comp->_parameters.percent)
  #define flag_save (_comp->_parameters.flag_save)
  #define minutes (_comp->_parameters.minutes)
  #define IntermediateCnts (_comp->_parameters.IntermediateCnts)
  #define StartTime (_comp->_parameters.StartTime)
  #define EndTime (_comp->_parameters.EndTime)
  #define CurrentTime (_comp->_parameters.CurrentTime)
  SIG_MESSAGE("[_origin_display] component origin=Progress_bar() DISPLAY [/usr/share/mcxtrace/3.4-20240304/misc/Progress_bar.comp:155]");

  printf("MCDISPLAY: component %s\n", _comp->_name);

  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  return(_comp);
} /* class_Progress_bar_display */

_class_Wiggler *class_Wiggler_display(_class_Wiggler *_comp
) {
  #define E0 (_comp->_parameters.E0)
  #define dE (_comp->_parameters.dE)
  #define lambda0 (_comp->_parameters.lambda0)
  #define dlambda (_comp->_parameters.dlambda)
  #define phase (_comp->_parameters.phase)
  #define randomphase (_comp->_parameters.randomphase)
  #define Ee (_comp->_parameters.Ee)
  #define Ie (_comp->_parameters.Ie)
  #define B (_comp->_parameters.B)
  #define K (_comp->_parameters.K)
  #define Nper (_comp->_parameters.Nper)
  #define length (_comp->_parameters.length)
  #define sigey (_comp->_parameters.sigey)
  #define sigex (_comp->_parameters.sigex)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define dist (_comp->_parameters.dist)
  #define gauss_t (_comp->_parameters.gauss_t)
  #define verbose (_comp->_parameters.verbose)
  #define Br (_comp->_parameters.Br)
  #define gamma (_comp->_parameters.gamma)
  #define gamma2 (_comp->_parameters.gamma2)
  #define igamma (_comp->_parameters.igamma)
  #define kc (_comp->_parameters.kc)
  #define s1x (_comp->_parameters.s1x)
  #define s1y (_comp->_parameters.s1y)
  #define lu (_comp->_parameters.lu)
  #define gap (_comp->_parameters.gap)
  #define p0 (_comp->_parameters.p0)
  SIG_MESSAGE("[_source_display] component source=Wiggler() DISPLAY [/usr/share/mcxtrace/3.4-20240304/sources/Wiggler.comp:251]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  
  double zz,dz;
  const double xwidth=1e-2;
  const double D=dist;
  double x0,z0,x1,z1;
  zz=-(length+lu)/2.0;
  dz=lu/2.0;

  while (zz<=(length-lu)/2.0){
    box(0.0,gap/2.0+5e-4,zz,xwidth,1e-3,lu/2.0);
    box(0.0,-gap/2.0-5e-4,zz,xwidth,1e-3,lu/2.0);
    zz+=dz;
  }

  line(0.0,0.0,0.0, K*D*sin(igamma), 0.0, D);
  line(0.0,0.0,0.0,-K*D*sin(igamma), 0.0, D);
  line(0.0,0.0,0.0, 0.0, D*sin(igamma), D);
  line(0.0,0.0,0.0, 0.0,-D*sin(igamma), D);
  
  double psi,dpsi;  
  psi =-igamma;
  dpsi= 2.0*igamma/32;
  while(psi<igamma){
    x0=D*sin(psi);
    x1=D*sin(psi+dpsi);
    z0=D*cos(psi);
    z1=D*cos(psi+dpsi);
    line(K*x0,0.0,z0,K*x1,0.0,z1);
    line(0.0,x0,z0,0.0,x1,z1);
    psi+=dpsi;
  }
  #undef E0
  #undef dE
  #undef lambda0
  #undef dlambda
  #undef phase
  #undef randomphase
  #undef Ee
  #undef Ie
  #undef B
  #undef K
  #undef Nper
  #undef length
  #undef sigey
  #undef sigex
  #undef focus_xw
  #undef focus_yh
  #undef dist
  #undef gauss_t
  #undef verbose
  #undef Br
  #undef gamma
  #undef gamma2
  #undef igamma
  #undef kc
  #undef s1x
  #undef s1y
  #undef lu
  #undef gap
  #undef p0
  return(_comp);
} /* class_Wiggler_display */

_class_Monitor_nD *class_Monitor_nD_display(_class_Monitor_nD *_comp
) {
  #define user1 (_comp->_parameters.user1)
  #define user2 (_comp->_parameters.user2)
  #define user3 (_comp->_parameters.user3)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define bins (_comp->_parameters.bins)
  #define min (_comp->_parameters.min)
  #define max (_comp->_parameters.max)
  #define restore_xray (_comp->_parameters.restore_xray)
  #define radius (_comp->_parameters.radius)
  #define options (_comp->_parameters.options)
  #define filename (_comp->_parameters.filename)
  #define geometry (_comp->_parameters.geometry)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define username1 (_comp->_parameters.username1)
  #define username2 (_comp->_parameters.username2)
  #define username3 (_comp->_parameters.username3)
  #define DEFS (_comp->_parameters.DEFS)
  #define Vars (_comp->_parameters.Vars)
  #define detector (_comp->_parameters.detector)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_mon_src_e_display] component mon_src_e=Monitor_nD() DISPLAY [/usr/share/mcxtrace/3.4-20240304/monitors/Monitor_nD.comp:544]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  if (geometry && strlen(geometry) && strcmp(geometry,"0") && strcmp(geometry, "NULL"))
  {
    off_display(offdata);
  } else {
    Monitor_nD_McDisplay(&DEFS, &Vars);
  }
  #undef user1
  #undef user2
  #undef user3
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef bins
  #undef min
  #undef max
  #undef restore_xray
  #undef radius
  #undef options
  #undef filename
  #undef geometry
  #undef nowritefile
  #undef username1
  #undef username2
  #undef username3
  #undef DEFS
  #undef Vars
  #undef detector
  #undef offdata
  return(_comp);
} /* class_Monitor_nD_display */

_class_Arm *class_Arm_display(_class_Arm *_comp
) {
  SIG_MESSAGE("[_DCM_location_display] component DCM_location=Arm() DISPLAY [/usr/share/mcxtrace/3.4-20240304/optics/Arm.comp:46]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  /* A bit ugly; hard-coded dimensions. */
  
  line(0,0,0,0.2,0,0);
  line(0,0,0,0,0.2,0);
  line(0,0,0,0,0,0.2);
  return(_comp);
} /* class_Arm_display */

_class_Bragg_crystal *class_Bragg_crystal_display(_class_Bragg_crystal *_comp
) {
  #define length (_comp->_parameters.length)
  #define width (_comp->_parameters.width)
  #define V (_comp->_parameters.V)
  #define form_factors (_comp->_parameters.form_factors)
  #define material (_comp->_parameters.material)
  #define alpha (_comp->_parameters.alpha)
  #define R0 (_comp->_parameters.R0)
  #define debye_waller_B (_comp->_parameters.debye_waller_B)
  #define crystal_type (_comp->_parameters.crystal_type)
  #define h (_comp->_parameters.h)
  #define k (_comp->_parameters.k)
  #define l (_comp->_parameters.l)
  #define structure_factor_scale_r (_comp->_parameters.structure_factor_scale_r)
  #define structure_factor_scale_i (_comp->_parameters.structure_factor_scale_i)
  #define Z (_comp->_parameters.Z)
  #define rho (_comp->_parameters.rho)
  #define At (_comp->_parameters.At)
  #define f_rel (_comp->_parameters.f_rel)
  #define f_nt (_comp->_parameters.f_nt)
  #define m_t (_comp->_parameters.m_t)
  #define f0_t (_comp->_parameters.f0_t)
  SIG_MESSAGE("[_dcm_xtal0_display] component dcm_xtal0=Bragg_crystal() DISPLAY [/usr/share/mcxtrace/3.4-20240304/optics/Bragg_crystal.comp:262]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
    
    rectangle("xz",0,0,0,width,length);
  #undef length
  #undef width
  #undef V
  #undef form_factors
  #undef material
  #undef alpha
  #undef R0
  #undef debye_waller_B
  #undef crystal_type
  #undef h
  #undef k
  #undef l
  #undef structure_factor_scale_r
  #undef structure_factor_scale_i
  #undef Z
  #undef rho
  #undef At
  #undef f_rel
  #undef f_nt
  #undef m_t
  #undef f0_t
  return(_comp);
} /* class_Bragg_crystal_display */

_class_Slit *class_Slit_display(_class_Slit *_comp
) {
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define radius (_comp->_parameters.radius)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define dist (_comp->_parameters.dist)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_x0 (_comp->_parameters.focus_x0)
  #define focus_y0 (_comp->_parameters.focus_y0)
  SIG_MESSAGE("[_slit_display] component slit=Slit() DISPLAY [/usr/share/mcxtrace/3.4-20240304/optics/Slit.comp:110]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  
  if (radius == 0) {
    double xw, yh;
    xw = (xmax - xmin)/2.0;
    yh = (ymax - ymin)/2.0;
    multiline(3, xmin-xw, (double)ymax, 0.0,
              (double)xmin, (double)ymax, 0.0,
              (double)xmin, ymax+yh, 0.0);
    multiline(3, xmax+xw, (double)ymax, 0.0,
              (double)xmax, (double)ymax, 0.0,
              (double)xmax, ymax+yh, 0.0);
    multiline(3, xmin-xw, (double)ymin, 0.0,
              (double)xmin, (double)ymin, 0.0,
              (double)xmin, ymin-yh, 0.0);
    multiline(3, xmax+xw, (double)ymin, 0.0,
              (double)xmax, (double)ymin, 0.0,
              (double)xmax, ymin-yh, 0.0);
  } else {
    circle("xy",0,0,0,radius);
  }
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef radius
  #undef xwidth
  #undef yheight
  #undef dist
  #undef focus_xw
  #undef focus_yh
  #undef focus_x0
  #undef focus_y0
  return(_comp);
} /* class_Slit_display */


  #undef magnify
  #undef line
  #undef dashed_line
  #undef multiline
  #undef rectangle
  #undef box
  #undef circle
  #undef cylinder
  #undef sphere

int display(void) { /* called by mccode_main for SOLEIL_PSICHE:DISPLAY */
  printf("MCDISPLAY: start\n");

  /* call iteratively all components DISPLAY */
  class_Progress_bar_display(&_origin_var);

  class_Wiggler_display(&_source_var);

  class_Monitor_nD_display(&_mon_src_e_var);

  class_Monitor_nD_display(&_mon_src_xy_var);

  class_Arm_display(&_DCM_location_var);

  class_Bragg_crystal_display(&_dcm_xtal0_var);

  class_Arm_display(&_dcm0_var);

  class_Bragg_crystal_display(&_dcm_xtal1_var);

  class_Arm_display(&_dcm1_var);

  class_Monitor_nD_display(&_mon_dcm_e_var);

  class_Monitor_nD_display(&_mon_dcm_xy_var);

  class_Slit_display(&_slit_var);

  class_Arm_display(&_sample_stage_var);


  class_Arm_display(&_fluo_holder_var);

  class_Monitor_nD_display(&_mon_spl_fluo_var);

  class_Monitor_nD_display(&_mon_spl_e_var);

  class_Monitor_nD_display(&_mon_spl_xy_var);

  printf("MCDISPLAY: end\n");

  return(0);
} /* display */

void* _getvar_parameters(char* compname)
/* enables settings parameters based use of the GETPAR macro */
{
  #ifdef OPENACC
    #define strcmp(a,b) str_comp(a,b)
  #endif
  if (!strcmp(compname, "origin")) return (void *) &(_origin_var._parameters);
  if (!strcmp(compname, "source")) return (void *) &(_source_var._parameters);
  if (!strcmp(compname, "mon_src_e")) return (void *) &(_mon_src_e_var._parameters);
  if (!strcmp(compname, "mon_src_xy")) return (void *) &(_mon_src_xy_var._parameters);
  if (!strcmp(compname, "DCM_location")) return (void *) &(_DCM_location_var._parameters);
  if (!strcmp(compname, "dcm_xtal0")) return (void *) &(_dcm_xtal0_var._parameters);
  if (!strcmp(compname, "dcm0")) return (void *) &(_dcm0_var._parameters);
  if (!strcmp(compname, "dcm_xtal1")) return (void *) &(_dcm_xtal1_var._parameters);
  if (!strcmp(compname, "dcm1")) return (void *) &(_dcm1_var._parameters);
  if (!strcmp(compname, "mon_dcm_e")) return (void *) &(_mon_dcm_e_var._parameters);
  if (!strcmp(compname, "mon_dcm_xy")) return (void *) &(_mon_dcm_xy_var._parameters);
  if (!strcmp(compname, "slit")) return (void *) &(_slit_var._parameters);
  if (!strcmp(compname, "sample_stage")) return (void *) &(_sample_stage_var._parameters);
  if (!strcmp(compname, "sample")) return (void *) &(_sample_var._parameters);
  if (!strcmp(compname, "fluo_holder")) return (void *) &(_fluo_holder_var._parameters);
  if (!strcmp(compname, "mon_spl_fluo")) return (void *) &(_mon_spl_fluo_var._parameters);
  if (!strcmp(compname, "mon_spl_e")) return (void *) &(_mon_spl_e_var._parameters);
  if (!strcmp(compname, "mon_spl_xy")) return (void *) &(_mon_spl_xy_var._parameters);
  return 0;
}

void* _get_particle_var(char *token, _class_particle *p)
/* enables setpars based use of GET_PARTICLE_DVAR macro and similar */
{
  return 0;
}

int _getcomp_index(char* compname)
/* Enables retrieving the component position & rotation when the index is not known.
 * Component indexing into MACROS, e.g., POS_A_COMP_INDEX, are 1-based! */
{
  if (!strcmp(compname, "origin")) return 1;
  if (!strcmp(compname, "source")) return 2;
  if (!strcmp(compname, "mon_src_e")) return 3;
  if (!strcmp(compname, "mon_src_xy")) return 4;
  if (!strcmp(compname, "DCM_location")) return 5;
  if (!strcmp(compname, "dcm_xtal0")) return 6;
  if (!strcmp(compname, "dcm0")) return 7;
  if (!strcmp(compname, "dcm_xtal1")) return 8;
  if (!strcmp(compname, "dcm1")) return 9;
  if (!strcmp(compname, "mon_dcm_e")) return 10;
  if (!strcmp(compname, "mon_dcm_xy")) return 11;
  if (!strcmp(compname, "slit")) return 12;
  if (!strcmp(compname, "sample_stage")) return 13;
  if (!strcmp(compname, "sample")) return 14;
  if (!strcmp(compname, "fluo_holder")) return 15;
  if (!strcmp(compname, "mon_spl_fluo")) return 16;
  if (!strcmp(compname, "mon_spl_e")) return 17;
  if (!strcmp(compname, "mon_spl_xy")) return 18;
  return -1;
}

/* embedding file "metadata-r.c" */

/** --- Contents of  metadata-r.c ---------------------------------------------------------------------------------- */
// Created by Gregory Tucker, Data Management Software Centre, European Spallation Source ERIC on 07/07/23.
#ifndef MCCODE_NAME
#include "metadata-r.h"
#endif

char * metadata_table_key_component(char* key){
  if (strlen(key) == 0) return NULL;
  char sep[2] = ":\0"; // matches any number of repeated colons
  // look for the separator in the provided key; strtok is allowed to modify the string, so copy it
  char * tok = malloc((strlen(key) + 1) * sizeof(char));
  strcpy(tok, key);
  char * pch = strtok(tok, sep); // this *is* the component name (if provided) -- but we need to move the pointer
  char * comp = malloc((1 + strlen(pch)) * sizeof(char));
  strcpy(comp, pch);
  if (tok) free(tok);
  return comp;
}
char * metadata_table_key_literal(char * key){
  if (strlen(key) == 0) return NULL;
  char sep[3] = ":\0";
  char * tok = malloc((strlen(key) + 1 ) * sizeof(char));
  strcpy(tok, key);
  char * pch = strtok(tok, sep); // this *is* the component name (if provided)
  if (pch) pch = strtok(NULL, sep); // either NULL or the literal name
  char * name = NULL;
  if (pch) {
    name = malloc((1 + strlen(pch)) * sizeof(char));
    strcpy(name, pch);
  }
  if (tok) free(tok);
  return name;
}
int metadata_table_defined(int no, metadata_table_t * tab, char * key){
  if (strlen(key) == 0){
    return no;
  }
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  // look through the table for the matching component and literal names
  int number = 0;
  for (int i=0; i<no; ++i){
    if (!strcmp(comp, tab[i].source)){
      if (name == NULL || !strcmp(name, tab[i].name)) ++number;
    }
  }
  if (comp) free(comp);
  if (name) free(name);
  return number;
}
char * metadata_table_type(int no, metadata_table_t * tab, char * key){
  if (strlen(key) == 0) {
    fprintf(stderr, "Unable to check type of non-existent key\n");
    exit(1);
  }
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  if (name == NULL){
    fprintf(stderr, "Unable to check type of literal for component %s without its name\n", comp);
    free(comp);
    exit(1);
  }
  char * type = NULL;
  for (int i=0; i<no; ++i){
    if (!strcmp(comp, tab[i].source) && !strcmp(name, tab[i].name)) type = tab[i].type;
  }
  if (comp) free(comp);
  if (name) free(name);
  return type;
}

char * metadata_table_literal(int no, metadata_table_t * tab, char * key){
  if (strlen(key) == 0) {
    fprintf(stderr, "Unable to retrieve literal for non-existent key\n");
    exit(1);
  }
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  if (name == NULL){
    fprintf(stderr, "Unable to retrieve literal for component %s without its name\n", comp);
    free(comp);
    exit(1);
  }
  char * type = NULL;
  for (int i=0; i<no; ++i){
    if (!strcmp(comp, tab[i].source) && !strcmp(name, tab[i].name)) type = tab[i].value;
  }
  if (comp) free(comp);
  if (name) free(name);
  return type;
}
void metadata_table_print_all_keys(int no, metadata_table_t * tab){
  for (int i=0; i<no; ++i){
    printf("%s::%s ", tab[i].source, tab[i].name);
  }
  printf("\n");
}
int metadata_table_print_all_components(int no, metadata_table_t * tab){
  int count = 0;
  char ** known = malloc(no * sizeof(char*));
  for (int i=0; i<no; ++i){
    int unknown = 1;
    for (int j=0; j<count; ++j) if (!strcmp(tab[i].source, known[j])) unknown = 0;
    if (unknown) known[count++] = tab[i].source;
  }
  size_t nchar = 0;
  for (int i=0; i<count; ++i) nchar += strlen(known[i]) + 1;
  char * line = malloc((nchar + 1) * sizeof(char));
  line[0] = '\0';
  for (int i=0; i<count; ++i) sprintf(line, "%s%s ", line, known[i]);
  line[strlen(line)] = '\0'; // eat the trailing space
  printf("%s\n", line);
  free(line);
  free(known);
  return count;
}
int metadata_table_print_component_keys(int no, metadata_table_t * tab, char * key){
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  int count = 0;
  for (int i=0; i<no; ++i) if (!strcmp(tab[i].source, comp) && (name == NULL || !strcmp(tab[i].name, name))) {
    if (name == NULL) printf("%s ", tab[i].name);
    ++count;
  }
  if (name != NULL) printf("%d", count); // replace count by strlen(tab[i].value)?
  printf("\n");
  return count;
}
/* -------------------------------------------------------------------------------------Contents of  metadata-r.c --- */
/* End of file "metadata-r.c". */

/* embedding file "mccode_main.c" */

/*******************************************************************************
* mccode_main: McCode main() function.
*******************************************************************************/
int mccode_main(int argc, char *argv[])
{
  /*  double run_num = 0; */
  time_t  t;
  clock_t ct;

#ifdef USE_MPI
  char mpi_node_name[MPI_MAX_PROCESSOR_NAME];
  int  mpi_node_name_len;
#endif /* USE_MPI */

#ifdef MAC
  argc = ccommand(&argv);
#endif

#ifdef USE_MPI
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &mpi_node_count); /* get number of nodes */
  MPI_Comm_rank(MPI_COMM_WORLD, &mpi_node_rank);
  MPI_Comm_set_name(MPI_COMM_WORLD, instrument_name);
  MPI_Get_processor_name(mpi_node_name, &mpi_node_name_len);
#endif /* USE_MPI */

  ct = clock();

  // device and host functional RNG seed
  struct timeval tm;
  gettimeofday(&tm, NULL);
  mcseed = (long) tm.tv_sec*1000000 + tm.tv_usec;
  mcstartdate = (long)tm.tv_sec;  /* set start date before parsing options and creating sim file */
  // init global _particle.randstate for random number use
  // during init(), finally() and display(). NOTE: during trace, a local
  // "_particle" variable is present and thus used instead.
  srandom(_hash(mcseed-1));

#ifdef USE_MPI
  /* *** print number of nodes *********************************************** */
  if (mpi_node_count > 1) {
    MPI_MASTER(
    printf("Simulation '%s' (%s): running on %i nodes (master is '%s', MPI version %i.%i).\n",
      instrument_name, instrument_source, mpi_node_count, mpi_node_name, MPI_VERSION, MPI_SUBVERSION);
    );
    /* share the same seed, then adapt random seed for each node */
    MPI_Bcast(&mcseed, 1, MPI_LONG, 0, MPI_COMM_WORLD); /* root sends its seed to slaves */
    mcseed += mpi_node_rank; /* make sure we use different seeds per noe */
  }
#endif /* USE_MPI */

#ifdef OPENACC
#ifdef USE_MPI
  int num_devices = acc_get_num_devices(acc_device_nvidia);
  if(num_devices>0){
    int my_device = mpi_node_rank % num_devices;
    acc_set_device_num( my_device, acc_device_nvidia );
    printf("Have found %d GPU devices on rank %d. Will use device %d.\n", num_devices, mpi_node_rank, my_device);
  }else{
    printf("There was an issue probing acc_get_num_devices, fallback to host\n");
    acc_set_device_type( acc_device_host );
  }
#endif
#endif

  /* *** parse options ******************************************************* */
  SIG_MESSAGE("[" __FILE__ "] main START");
  mcformat = getenv(FLAVOR_UPPER "_FORMAT") ?
             getenv(FLAVOR_UPPER "_FORMAT") : FLAVOR_UPPER;
  instrument_exe = argv[0]; /* store the executable path */
  /* read simulation parameters and options */
  mcparseoptions(argc, argv); /* sets output dir and format */


#ifdef USE_MPI
  if (mpi_node_count > 1) {
    /* share the same seed, then adapt random seed for each node */
    MPI_Bcast(&mcseed, 1, MPI_LONG, 0, MPI_COMM_WORLD); /* root sends its seed to slaves */
    mcseed += mpi_node_rank; /* make sure we use different seeds per node */
  }
#endif


/* *** install sig handler, but only once !! after parameters parsing ******* */
#ifndef NOSIGNALS
#ifdef SIGQUIT
  if (signal( SIGQUIT ,sighandler) == SIG_IGN)
    signal( SIGQUIT,SIG_IGN);   /* quit (ASCII FS) */
#endif
#ifdef SIGABRT
  if (signal( SIGABRT ,sighandler) == SIG_IGN)
    signal( SIGABRT,SIG_IGN);   /* used by abort, replace SIGIOT in the future */
#endif
#ifdef SIGTERM
  if (signal( SIGTERM ,sighandler) == SIG_IGN)
    signal( SIGTERM,SIG_IGN);   /* software termination signal from kill */
#endif
#ifdef SIGUSR1
  if (signal( SIGUSR1 ,sighandler) == SIG_IGN)
    signal( SIGUSR1,SIG_IGN);   /* display simulation status */
#endif
#ifdef SIGUSR2
  if (signal( SIGUSR2 ,sighandler) == SIG_IGN)
    signal( SIGUSR2,SIG_IGN);
#endif
#ifdef SIGHUP
  if (signal( SIGHUP ,sighandler) == SIG_IGN)
    signal( SIGHUP,SIG_IGN);
#endif
#ifdef SIGILL
  if (signal( SIGILL ,sighandler) == SIG_IGN)
    signal( SIGILL,SIG_IGN);    /* illegal instruction (not reset when caught) */
#endif
#ifdef SIGFPE
  if (signal( SIGFPE ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);    /* floating point exception */
#endif
#ifdef SIGBUS
  if (signal( SIGBUS ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);    /* bus error */
#endif
#ifdef SIGSEGV
  if (signal( SIGSEGV ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);   /* segmentation violation */
#endif
#endif /* !NOSIGNALS */


  // init executed by master/host
  siminfo_init(NULL); /* open SIM */
  SIG_MESSAGE("[" __FILE__ "] main INITIALISE");
  init();


#ifndef NOSIGNALS
#ifdef SIGINT
  if (signal( SIGINT ,sighandler) == SIG_IGN)
    signal( SIGINT,SIG_IGN);    /* interrupt (rubout) only after INIT */
#endif
#endif /* !NOSIGNALS */

/* ================ main particle generation/propagation loop ================ */
#ifdef USE_MPI
  /* sliced Ncount on each MPI node */
  mcncount = mpi_node_count > 1 ?
    floor(mcncount / mpi_node_count) :
    mcncount; /* number of rays per node */
#endif

// MT specific init, note that per-ray init is empty
#if RNG_ALG == 2
  mt_srandom(mcseed);
#endif


// main raytrace work loop
#ifndef FUNNEL
  // legacy version
  raytrace_all(mcncount, mcseed);
#else
  MPI_MASTER(
  // "funneled" version in which propagation is more parallelizable
  printf("\nNOTE: CPU COMPONENT grammar activated:\n 1) \"FUNNEL\" raytrace algorithm enabled.\n 2) Any SPLIT's are dynamically allocated based on available buffer size. \n");
	     );
  raytrace_all_funnel(mcncount, mcseed);
#endif


#ifdef USE_MPI
 /* merge run_num from MPI nodes */
  if (mpi_node_count > 1) {
  double mcrun_num_double = (double)mcrun_num;
  mc_MPI_Sum(&mcrun_num_double, 1);
  mcrun_num = (unsigned long long)mcrun_num_double;
  }
#endif


  // save/finally executed by master node/thread/host
  finally();


#ifdef USE_MPI
  MPI_Finalize();
#endif /* USE_MPI */


  return 0;
} /* mccode_main */
/* End of file "mccode_main.c". */

/* end of generated C code ./SOLEIL_PSICHE.c */
