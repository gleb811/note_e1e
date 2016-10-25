void pi2pi3() {

Double_t W;

gStyle->SetOptStat(0);

TH1F *h2pi = new TH1F("h2pi","h2pi",12,1.525,1.825);
TH1F *h3pi = new TH1F("h3pi","h3pi",12,1.525,1.825);

for (Int_t i=10; i<22; i++) {

W = 1.2875 + i*0.025; 
cout << W << " sig2pi = " << sig2pi(W) << " sig3pi = " << sig3pi(W) << " ratio = " << sig3pi(W)/sig2pi(W)*100. <<   endl;
h2pi->SetBinContent(i-9,sig2pi(W));
h3pi->SetBinContent(i-9,sig3pi(W));
};

TCanvas *c = new TCanvas("c","c",500.,500.);
c->cd();
h2pi->SetTitle("");
h2pi->SetMinimum(0.);
h2pi->SetMarkerStyle(20);
h2pi->Draw("P");

h3pi->SetTitle("");
h3pi->SetMinimum(0.);
h3pi->SetMarkerStyle(20);
h3pi->SetMarkerColor(2);
h3pi->Draw("P same");

};


TH1F *GetSaphir2Hist(const char* hName)
{
const double mp = 0.93827;
const int np = 16;
double e1[np] = 
  { 1.00, 1.10, 1.20, 1.30, 1.40, 1.50, 1.60, 1.70, 1.80, 1.90, 
    2.00, 2.10, 2.20, 2.30, 2.40, 2.50 
  };
double e2[np] = 
  { 1.10, 1.20, 1.30, 1.40, 1.50, 1.60, 1.70, 1.80, 1.90, 2.00, 
    2.10, 2.20, 2.30, 2.40, 2.50, 2.60
  };
double sig[np] = 
  { 74.23, 62.24, 57.09, 54.00, 52.56, 50.06, 47.27, 45.08, 
    42.33, 39.41, 36.63, 32.98, 31.62, 30.14, 29.08, 28.90
  };
double err[np] = 
  { 3.24, 2.17, 2.54, 1.50, 1.52, 2.03, 2.12, 1.92, 1.90, 
    2.01, 1.54, 2.98, 1.74, 1.83, 1.49, 0.29
  };

double wlow[np+1];
for(int i=0; i<np; i++)
  wlow[i]  = sqrt( mp*(mp+2.*e1[i]) );
  wlow[np] = sqrt( mp*(mp+2.*e2[np-1]) );

TH1F *hist = new TH1F(hName, "saphir2 tot", np, wlow);
for(int i=1; i<=np; i++) {
  hist->SetBinContent(i, sig[i]);
  hist->SetBinError(i, err[i]);
}

return hist;
}; // end GetSaphir2Hist()





TH1F *GetSaphir1Hist_3pi(const char* hName)
{
const double mp = 0.93827;
const int np = 20;
double eg[np] = 
  {  0.75, 0.85, 0.93, 1.05, 1.15, 1.24, 1.35, 1.45, 1.54, 
     1.65, 1.74, 1.85, 1.94, 2.24, 2.75, 3.23, 3.74, 4.23, 
     4.74, 5.29 
  };
double sig[np] = 
  { 3.60, 4.62, 6.06, 9.85, 15.0, 21.1, 23.0, 26.8, 27.6, 
    32.5, 39.1, 37.7, 42.4, 42.4, 44.9, 41.2, 35.8, 32.3, 
    22.4, 17.8 
  };
double err[np] = 
  { 1.1, 1.3, 1.35, 1.35, 1.4, 1.42, 1.5, 
    1.6, 1.6, 1.8,   1.9, 2.0, 2.2, 2.4, 
    2.44, 2.5, 2.5, 2.5, 2.5, 2.5, 
  };


double wlow[np+1];
double elow;
for(int i=1; i<np; i++) {
  elow = eg[i] - (eg[i]-eg[i-1])/2.;
  wlow[i]  = sqrt( mp*(mp+2.*elow) ); }
  elow = eg[0] - (eg[1]-eg[0])/2.;
  wlow[0]  = sqrt( mp*(mp+2.*elow) );
  elow = eg[np-1] + (eg[np-1]-eg[np-2])/2.;
  wlow[np] = sqrt( mp*(mp+2.*elow) );


TH1F *hist = new TH1F(hName, "saphir3 tot", np, wlow);
for(int i=1; i<=np; i++) {
  hist->SetBinContent(i, sig[i-1]);
  hist->SetBinError(i, err[i-1]);
}

return hist;
}; // end GetSaphir2Hist()



double sig2pi(double W) {
  if(W<1.23) return 0.;
  if(W<1.6)  return 71.4;
  if(W<2.9)  return 256.215 - 157.082*W + 26.2192*W*W; 
  return 21.2 * (1./2.3)*(34.361 - 21.8304*W + 4.7182*W*W - 0.343667*W*W*W) ; 
}
TGraph* getGr2pi() {
  TGraph* gr;
  double x[30], y[30];
  for(int i=0; i<30; i++) {
    x[i] = 1. +  (5.-1.)*i/29.;
    y[i] = sig2pi(x[i]);
  }
  TGraph *gMod = new TGraph(30, x, y);
  return gMod;
}
double sig3pi(double W) {
  if(W<1.52) return 0.;
  if(W<3.1)  return -237.036 + 224.503*W - 44.9681*W*W;
  return 16.2 * (1./1.5)*(34.361 - 21.8304*W + 4.7182*W*W - 0.343667*W*W*W); 
}
TGraph* getGr3pi() {
  TGraph* gr;
  double x[30], y[30];
  for(int i=0; i<30; i++) {
    x[i] = 1. +  (5.-1.)*i/29.;
    y[i] = sig3pi(x[i]);
  }
  TGraph *gMod = new TGraph(30, x, y);
  return gMod;
}




