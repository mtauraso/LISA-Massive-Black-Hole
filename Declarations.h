
struct MBH_Data
{
    int N;
    int Nch;
    double dt;
    double Tobs;
    double sqrtTobs;
    double Tstart;
    double Tend;
    double **SN;
    double **SM;
    double **data;
};

struct Het
{
    int M;
    int MM;
    int MN;
    int J;
    int NR;
    int Nch;
    int *fgrid;
    double SNR;
    double *freq;
    double *logLR;
    double *DD;
    double ***IP;
    double ***SL;
    double **amp;
    double **phase;
    double **rc;
    double **rs;
    double **dc;
    double **ds;
    double **aa;
    double ***lc;
    double ***ls;
    double ***ldc;
    double ***lds;
    double *pref;
};

void freehet(struct Het *het);
void lisaskyloc(double t, double *params, double *thetaL, double *phiL);
double SNRFast(struct MBH_Data *dat, int ll, double *params);
void SetUp(struct MBH_Data *dat, int ll, double *params, int NFmax, int *NFS, double *FF);
void StartStop(int ll, double *params, double Tstart, double Tend, double dt, double *fstart, double *fstop, double *frg);
void Intrinsic(int ll, double *params, double Tobs, int NF, double *FF, double *TF, double *PF, double *AF);
void ResponseFast(struct MBH_Data *dat, int ll, double *params, double *AS, double *ES);
double Likelihood(struct MBH_Data *dat, int ll, double *params);
double Likelihood_check(struct MBH_Data *dat, struct Het *het, int ll, double *params);
double Likelihood_Slow(struct MBH_Data *dat, int ll, double *params);
void ResponseFreq(struct MBH_Data *dat, int ll, double *params, double *AS, double *ES);
double chisq(struct MBH_Data *dat, int ll, double *params, double *AR, double *ER);
void heterodyne(struct MBH_Data *dat, struct Het *het, int ll, double *params);
void legendre_maker(int J, int U, double **P);
void fullphaseamp(struct MBH_Data *dat, int ll, int K, double *params, double *freq, double *Aamp, double *Eamp, double *Aphase, double *Ephase);
double log_likelihood_het(struct MBH_Data *dat, struct Het *het, int ll, double *params, double *sx);
double Fstat_het(struct MBH_Data *dat, struct Het *het, int ll, double *params, double *sx, double tm);
double SNRstart(struct MBH_Data *dat, int ll, double *params);
void FisherHet(struct MBH_Data *dat, struct Het *het, int ll, double *params, double **Fisher);
void FisherSubHet(struct MBH_Data *dat, struct Het *het, int ll, int *pmap, double *params, double **Fisher);

void FisherPlot(struct MBH_Data *dat, int ll, double *params);
void pbt_shift(double *corr, double *corrf, double *data1, double *data2, double *Sn, int n);
double log_likelihood_max_dual(struct MBH_Data *dat, int ll, double *params);
void InChl(int ll, double *params, double **Fisher, double **iChl);
void Ext_In(int ll, double *params, double **Fisher, double **eChl, double **iChl);
void map_params(int ll, double *params);
double tvol(double *params);
void cholesky(double **A, double **C, int N);
void ang2pix_ring( const long nside, double theta, double phi, long *ipix);
void pix2ang_ring( long nside, long ipix, double *theta, double *phi);
int *int_vector(int N);
void free_int_vector(int *v);
double **double_matrix(int N, int M);
void free_double_matrix(double **m, int N);
int **int_matrix(int N, int M);
void free_int_matrix(int **m, int N);
double *double_vector(int N);
void free_double_vector(double *v);
void FisherFastPE(double *params);
double ***double_tensor(int N, int M, int L);
void free_double_tensor(double ***t, int N, int M);
void Inverse(double **M, double **IM, int d);
void spacecraft(double t,  double *x, double *y, double *z);
void RAantenna(double *params, int NF, double *TF, double *FF, double *xi, double *FpAR, double *FpAI, double *FcAR, double *FcAI,
               double *FpER, double *FpEI, double *FcER, double *FcEI);
void RAfilters(double *params, int NF, double *TF, double *FF, double *xi, double *FpAR, double *FpAI, double *FcAR, double *FcAI,
               double *FpER, double *FpEI, double *FcER, double *FcEI);
void timearray(double *params, RealVector *freq, long N, double *TF, AmpPhaseFDWaveform *ap);
double fourier_nwip(double *a, double *b, double *Sn, int n);
double FofT(int ll, double Tobs, double *params, double *frg, double dt, double tref);
void Extrinsic(double *params, double Tstart, double Tend, int NF, double *FF, double *TF, double *PF, double *AF, double *AAmp, double *EAmp, double *APhase, double *EPhase, double *kxm);
void efix(struct MBH_Data *dat, int ll, double *params, double *min, double *max, double *eval, double **evec, double zs);
void het_space(struct MBH_Data *dat, struct Het *het, int ll, double *params, double *min, double *max);

void getfreq(double Tend, double *fnew, double *tf, double *Amp, double *Phase, double t, double fguess, double phic, double fRef_in, double m1_SI, double m2_SI, double chi1, double chi2, double distance, double tc);
void update(struct MBH_Data *dat, struct Het *het, int typ, int k, int ll, double *logLx, double **paramx, double **paramy, double **sx, double **sy, double *min, double *max, int *who, double *heat, double ***history, int NH, double **ejump, double ***evec, int **cv, int **av, gsl_rng *r);
double Likelihood(struct MBH_Data *dat, int ll, double *params);
double LikelihoodDeltaMaxT(struct MBH_Data *dat, int ll, double *params, int NF, double *FF, double *AA, double *EA, double *AP, double *EP);
double LikelihoodDeltaMax(struct MBH_Data *dat, int ll, double *params, int NF, double *FF, double *AA, double *EA, double *AP, double *EP);
double LikelihoodDelta(struct MBH_Data *dat, int ll, double *params, int NF, double *FF, double *AA, double *EA, double *AP, double *EP);
double LikelihoodFstat(struct MBH_Data *dat, int ll, double *params, double tm, int NF, double *FF, double *AA, double *EA, double *AP, double *EP);
void FisherEvec(double **fish, double *ej, double **ev, int d);
void FisherEvecSVD(double **fish, double *ej, double **ev, int d);
void FisherEvecSplit(double **fish, double *ej, double **ev, int d);
double fourier_nwip2(double *a, double *b, double *Sn, int imin, int imax, int N);
void fourier_nwip_time(double *abt, double *a, double *b, double *Sn, double Tobs, int n);
void fourier_nwip_dual_time(double *abt, double *aA, double *bA, double *aE, double *bE, double *Sn, double Tobs, int n);
void FstatRA(struct MBH_Data *dat, int ll, double *params, double *pnew, int NF, double *FF, double *TF, double *PF, double *AF, double *AAmp, double *EAmp, double *APhase, double *EPhase);
void FisherDirect(struct MBH_Data *dat, int ll, double *params, double **Fisher);
void FisherDirectShift(struct MBH_Data *dat, int ll, double *params, double **Fisher);
void FstatFull(struct MBH_Data *dat, int ll, double *params, double *pnew);
void FisherSub(struct MBH_Data *dat, int ll, int *pmap, double *params, double **Fisher);
void FisherFast(struct MBH_Data *dat, int ll, double *params, double **Fisher);
double f_start(double m1, double m2, double chi1, double chi2, double tc);
double f_at_t(double m1, double m2, double chi1, double chi2, double tc, double dt, double t);
void de_jump(double *paramsx, double *paramsy, double **history, int m, int d, gsl_rng *r);
double det(double **A, int N);
double Tmerger(double *params, double t);

