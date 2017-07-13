/* Created by Language version: 6.2.0 */
/* NOT VECTORIZED */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define _threadargscomma_ /**/
#define _threadargs_ /**/
 
#define _threadargsprotocomma_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_fran(void);
 static void _hoc_fseed(void);
 static void _hoc_norm(void);
 static void _hoc_n_rand(void);
 static void _hoc_poisint(void);
 static void _hoc_pois(void);
 static void _hoc_u_rand(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_rand", _hoc_setdata,
 "fran", _hoc_fran,
 "fseed", _hoc_fseed,
 "norm", _hoc_norm,
 "n_rand", _hoc_n_rand,
 "poisint", _hoc_poisint,
 "pois", _hoc_pois,
 "u_rand", _hoc_u_rand,
 0, 0
};
 extern double fran( double , double );
 extern double fseed( double );
 extern double norm( );
 extern double n_rand( );
 extern double poisint( double );
 extern double pois( double );
 extern double u_rand( );
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 0,0
};
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "6.2.0",
"rand",
 0,
 0,
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 0, _prop);
 	/*initialize range parameters*/
 	_prop->param = _p;
 	_prop->param_size = 0;
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*f)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _rand_reg() {
	int _vectorized = 0;
  _initlists();
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 rand /Users/tom/Traub-BG/x86_64/rand.mod\n");
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
/*VERBATIM*/
#include <stdlib.h>
#include <math.h>

#if 0
#include <values.h> /* contains MAXLONG */
#endif

/* Michael Hines fix for cygwin on mswin */
#if !defined(MAXLONG)
#include <limits.h>
#define MAXLONG LONG_MAX
#endif
/* some machines do not have drand48 and srand48 so use the implementation
at the end of this file */
extern double my_drand48();
extern void my_srand48();
#undef drand48
#undef srand48
#define drand48 my_drand48
#define srand48 my_srand48

extern double drand48();
#define random()                drand48()*MAXLONG
#define initstate(c1,c2,c3)     srand48(c1)

static long state2[32] = {
	470594912, 650447616, 310934240, 695012864, 850358912,
61088076, 481306752, 786902080, 224042800, 805177664, 938284096,
145937936, 622867968, 160207584, 977329216, 716234240, 127727624,
415316352, 870137472, 18664444, 330872224, 93728752, 914779200,
736261248, 643647616, 755802688, 213052336, 410240448, 218974736,
109419280, 178026128, 689569664
};
 
double fseed (  double _lseed ) {
   double _lfseed;
 
/*VERBATIM*/
    initstate((unsigned)_lseed,(char *)state2,32);
	_lfseed = _lseed;
 
return _lfseed;
 }
 
static void _hoc_fseed(void) {
  double _r;
   _r =  fseed (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double n_rand (  ) {
   double _ln_rand;
 
/*VERBATIM*/
    _ln_rand = ((double)random()) / (((double)MAXLONG) + 1.);
 
return _ln_rand;
 }
 
static void _hoc_n_rand(void) {
  double _r;
   _r =  n_rand (  );
 hoc_retpushx(_r);
}
 
double fran (  double _ll , double _lh ) {
   double _lfran;
 
/*VERBATIM*/
{
	int low, high;
    double num, imax, *getarg();
    
	low = (int)_ll;
	high = (int)_lh;
    imax = high-low+1; /* the total number of numbers being used */
    _lfran = (double)(low + (int) (imax*n_rand()));  
}
 
return _lfran;
 }
 
static void _hoc_fran(void) {
  double _r;
   _r =  fran (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
double u_rand (  ) {
   double _lu_rand;
 
/*VERBATIM*/
    _lu_rand = (((double)random()) / ((double)MAXLONG));
 
return _lu_rand;
 }
 
static void _hoc_u_rand(void) {
  double _r;
   _r =  u_rand (  );
 hoc_retpushx(_r);
}
 
double norm (  ) {
   double _lnorm;
 
/*VERBATIM*/
{
    static int iset = 0;
    static float gset;
    float fac, r , v1, v2;
    double sqrt();

    if (iset == 0) {
        do {
	    	v1 = 2.0 * n_rand() - 1.0;
		    v2 = 2.0 * n_rand() - 1.0;
		    r = v1 * v1 + v2 * v2;
	    } while (r >= 1.0);

        fac = (float)sqrt(-2.0 * log(r) / r);
        gset = v1 * fac;
        iset = 1;
        _lnorm = v2 * fac;

    } else {
        iset = 0;
        _lnorm = (double)gset;
    }
}
 
return _lnorm;
 }
 
static void _hoc_norm(void) {
  double _r;
   _r =  norm (  );
 hoc_retpushx(_r);
}
 
double pois (  double _lmean ) {
   double _lpois;
 
/*VERBATIM*/
    _lpois = - _lmean * log(((double)random()+1.) / ((double)MAXLONG+1.));
 
return _lpois;
 }
 
static void _hoc_pois(void) {
  double _r;
   _r =  pois (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double poisint (  double _lmean ) {
   double _lpoisint;
 _lpoisint = poisrand ( _lmean ) ;
   
return _lpoisint;
 }
 
static void _hoc_poisint(void) {
  double _r;
   _r =  poisint (  *getarg(1) );
 hoc_retpushx(_r);
}
 
/*VERBATIM*/
/* http://www.mit.edu/afs/athena/activity/c/cgs/src/math/drand48/ */
/*
 Michael Hines removed  all code not used by srand48 and drand48,
 the code handling non-floating point processor machines, and the
 pdp-11 fragment. Global names have my_ prefix added.
*/


/*	@(#)drand48.c	2.2	*/
/*LINTLIBRARY*/
/*
 *	drand48, etc. pseudo-random number generator
 *	This implementation assumes unsigned short integers of at least
 *	16 bits, long integers of at least 32 bits, and ignores
 *	overflows on adding or multiplying two unsigned integers.
 *	Two's-complement representation is assumed in a few places.
 *	Some extra masking is done if unsigneds are exactly 16 bits
 *	or longs are exactly 32 bits, but so what?
 *	An assembly-language implementation would run significantly faster.
 */
#define N	16
#define MASK	((unsigned)(1 << (N - 1)) + (1 << (N - 1)) - 1)
#define LOW(x)	((unsigned)(x) & MASK)
#define HIGH(x)	LOW((x) >> N)
#define MUL(x, y, z)	{ long l = (long)(x) * (long)(y); \
		(z)[0] = LOW(l); (z)[1] = HIGH(l); }
#define CARRY(x, y)	((long)(x) + (long)(y) > MASK)
#define ADDEQU(x, y, z)	(z = CARRY(x, (y)), x = LOW(x + (y)))
#define X0	0x330E
#define X1	0xABCD
#define X2	0x1234
#define A0	0xE66D
#define A1	0xDEEC
#define A2	0x5
#define C	0xB
#define SET3(x, x0, x1, x2)	((x)[0] = (x0), (x)[1] = (x1), (x)[2] = (x2))
#define SEED(x0, x1, x2) (SET3(x, x0, x1, x2), SET3(a, A0, A1, A2), c = C)

static unsigned x[3] = { X0, X1, X2 }, a[3] = { A0, A1, A2 }, c = C;
static unsigned short lastx[3];
static void next();

double
my_drand48()
{
	static double two16m = 1.0 / (1L << N);

	next();
	return (two16m * (two16m * (two16m * x[0] + x[1]) + x[2]));
}

static void
next()
{
	unsigned p[2], q[2], r[2], carry0, carry1;

	MUL(a[0], x[0], p);
	ADDEQU(p[0], c, carry0);
	ADDEQU(p[1], carry0, carry1);
	MUL(a[0], x[1], q);
	ADDEQU(p[1], q[0], carry0);
	MUL(a[1], x[0], r);
	x[2] = LOW(carry0 + carry1 + CARRY(p[1], r[0]) + q[1] + r[1] +
		a[0] * x[2] + a[1] * x[1] + a[2] * x[0]);
	x[1] = LOW(p[1] + r[0]);
	x[0] = LOW(p[0]);
}

void
my_srand48(seedval)
long seedval;
{
	SEED(X0, LOW(seedval), HIGH(seedval));
}

#if 0
#ifdef DRIVER
/*
	This should print the sequences of integers in Tables 2
		and 1 of the TM:
	1623, 3442, 1447, 1829, 1305, ...
	657EB7255101, D72A0C966378, 5A743C062A23, ...
 */
#include <stdio.h>

main()
{
	int i;

	for (i = 0; i < 80; i++) {
		printf("%4d ", (int)(4096 * my_drand48()));
		printf("%.4X%.4X%.4X\n", x[2], x[1], x[0]);
	}
}
#endif
#endif

static void initmodel() {
  int _i; double _save;_ninits++;
{

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
 double _break, _save;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _break = t + .5*dt; _save = t;
 v=_v;
{
}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}
