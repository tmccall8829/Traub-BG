#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _alphasyndiffeq_reg(void);
extern void _alphasynkin_reg(void);
extern void _alphasynkint_reg(void);
extern void _ampa_reg(void);
extern void _ampap_reg(void);
extern void _ar_reg(void);
extern void _cad_reg(void);
extern void _cal_reg(void);
extern void _cat_reg(void);
extern void _cat_a_reg(void);
extern void _dbsStim_reg(void);
extern void _gabaa_reg(void);
extern void _gabaap_reg(void);
extern void _iclamp_const_reg(void);
extern void _k2_reg(void);
extern void _ka_reg(void);
extern void _ka_ib_reg(void);
extern void _kahp_reg(void);
extern void _kahp_deeppyr_reg(void);
extern void _kahp_slower_reg(void);
extern void _kc_reg(void);
extern void _kc_fast_reg(void);
extern void _kdr_reg(void);
extern void _kdr_fs_reg(void);
extern void _km_reg(void);
extern void _myions_reg(void);
extern void _naf_reg(void);
extern void _naf2_reg(void);
extern void _naf_tcr_reg(void);
extern void _nap_reg(void);
extern void _napf_reg(void);
extern void _napf_spinstell_reg(void);
extern void _napf_tcr_reg(void);
extern void _pGPeA_reg(void);
extern void _pSTN_reg(void);
extern void _par_ggap_reg(void);
extern void _pulsesyn_reg(void);
extern void _rampsyn_reg(void);
extern void _rand_reg(void);
extern void _ri_reg(void);
extern void _scopRandom_reg(void);
extern void _traub_nmda_reg(void);
extern void _twoStateGen_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," mod/alphasyndiffeq.mod");
    fprintf(stderr," mod/alphasynkin.mod");
    fprintf(stderr," mod/alphasynkint.mod");
    fprintf(stderr," mod/ampa.mod");
    fprintf(stderr," mod/ampap.mod");
    fprintf(stderr," mod/ar.mod");
    fprintf(stderr," mod/cad.mod");
    fprintf(stderr," mod/cal.mod");
    fprintf(stderr," mod/cat.mod");
    fprintf(stderr," mod/cat_a.mod");
    fprintf(stderr," mod/dbsStim.mod");
    fprintf(stderr," mod/gabaa.mod");
    fprintf(stderr," mod/gabaap.mod");
    fprintf(stderr," mod/iclamp_const.mod");
    fprintf(stderr," mod/k2.mod");
    fprintf(stderr," mod/ka.mod");
    fprintf(stderr," mod/ka_ib.mod");
    fprintf(stderr," mod/kahp.mod");
    fprintf(stderr," mod/kahp_deeppyr.mod");
    fprintf(stderr," mod/kahp_slower.mod");
    fprintf(stderr," mod/kc.mod");
    fprintf(stderr," mod/kc_fast.mod");
    fprintf(stderr," mod/kdr.mod");
    fprintf(stderr," mod/kdr_fs.mod");
    fprintf(stderr," mod/km.mod");
    fprintf(stderr," mod/myions.mod");
    fprintf(stderr," mod/naf.mod");
    fprintf(stderr," mod/naf2.mod");
    fprintf(stderr," mod/naf_tcr.mod");
    fprintf(stderr," mod/nap.mod");
    fprintf(stderr," mod/napf.mod");
    fprintf(stderr," mod/napf_spinstell.mod");
    fprintf(stderr," mod/napf_tcr.mod");
    fprintf(stderr," mod/pGPeA.mod");
    fprintf(stderr," mod/pSTN.mod");
    fprintf(stderr," mod/par_ggap.mod");
    fprintf(stderr," mod/pulsesyn.mod");
    fprintf(stderr," mod/rampsyn.mod");
    fprintf(stderr," mod/rand.mod");
    fprintf(stderr," mod/ri.mod");
    fprintf(stderr," mod/scopRandom.mod");
    fprintf(stderr," mod/traub_nmda.mod");
    fprintf(stderr," mod/twoStateGen.mod");
    fprintf(stderr, "\n");
  }
  _alphasyndiffeq_reg();
  _alphasynkin_reg();
  _alphasynkint_reg();
  _ampa_reg();
  _ampap_reg();
  _ar_reg();
  _cad_reg();
  _cal_reg();
  _cat_reg();
  _cat_a_reg();
  _dbsStim_reg();
  _gabaa_reg();
  _gabaap_reg();
  _iclamp_const_reg();
  _k2_reg();
  _ka_reg();
  _ka_ib_reg();
  _kahp_reg();
  _kahp_deeppyr_reg();
  _kahp_slower_reg();
  _kc_reg();
  _kc_fast_reg();
  _kdr_reg();
  _kdr_fs_reg();
  _km_reg();
  _myions_reg();
  _naf_reg();
  _naf2_reg();
  _naf_tcr_reg();
  _nap_reg();
  _napf_reg();
  _napf_spinstell_reg();
  _napf_tcr_reg();
  _pGPeA_reg();
  _pSTN_reg();
  _par_ggap_reg();
  _pulsesyn_reg();
  _rampsyn_reg();
  _rand_reg();
  _ri_reg();
  _scopRandom_reg();
  _traub_nmda_reg();
  _twoStateGen_reg();
}
