void th_vs_p_pip_6(){
gStyle ->SetPalette(1);
gStyle ->SetOptLogz(1);
gStyle->SetOptStat(0);
gStyle ->SetOptFit(0011);
gStyle ->SetStatW(0.1);
gStyle ->SetStatH(0.05);
gStyle ->SetStatY(0.99);
gStyle ->SetStatX(0.9);
gStyle ->SetStatFontSize(0.1);
gStyle->SetTitleY(1);
gStyle->SetTitleX(0.56);
gStyle->SetTitleSize(0.1,"t");
Short_t j,k;
ostringstream qqq;
ostringstream qqq1;
ostringstream qqq2;

TFile *MyFile = new TFile("../test_proton_fiduch.root","READ");

Double_t M_MEAN [45];
Double_t M_MEAN_2 [60];
TCanvas *c = new TCanvas("c","c",0,0,500,500);
//c -> Divide (2,3);
TCanvas *c3= new TCanvas ("c3","c3",0,0,1000,1000);
c3->Divide(5,9);
TCanvas *c4= new TCanvas ("c4","c4",0,0,1000,1000);
c4->Divide(6,12);
TH1D *h_odn[45];
Double_t P[45];
TH1D *h_odn_2[60];
Double_t P_2[60];
TH2 *h;
TH1 *h1;
TH1 *h2;
c->cd();
MyFile->GetObject("th_vs_p/th_vs_p_pip_1_6",h);
h->Draw("colz");

for (k=0; k<45; k++){
c3->cd(k+1);
c3->cd(k+1)->SetBottomMargin(0.18);
c3->cd(k+1)->SetLeftMargin(0.2);

qqq << "hist" << "n" << k;
h_odn[k] = h->ProjectionY(qqq.str().c_str(),84+2*k, 84+2*(k+1));
qqq.str("");

qqq<< 5*(84+2*k) << " " << " < P_{p} < " << 5*(84+2*(k+1))<< " " ;
h_odn[k]->SetTitle(qqq.str().c_str());


qqq.str(" ");
//if (k<14) h_odn[k]->SetAxisRange(0.6,1.1,"X");
//if (k>14) 
if (k<=4+3) h_odn[k]->SetAxisRange(21.,26,"X");
//if ((k==4)) h_odn[k]->SetAxisRange(10.,40.,"X");
if ((k==0)) h_odn[k]->SetAxisRange(10.,12.,"X");
if ((k==1)) h_odn[k]->SetAxisRange(15.,16.,"X");
if ((k==2)) h_odn[k]->SetAxisRange(17.,19.,"X");
//if ((k>=0)&&(k<=3)) h_odn[k]->SetAxisRange(23.,29.,"X");
if ((k>=5+3)&&(k<10+3)) h_odn[k]->SetAxisRange(24.,29.,"X");
if ((k>=10+3)&&(k<22+3)) h_odn[k]->SetAxisRange(28.,35.,"X");
if ((k>=22+3)) h_odn[k]->SetAxisRange(33.,35.,"X");

h_odn[k]->Draw();
Int_t t;
t=h_odn[k]->GetMinimumBin();

M_MEAN[k]=t*0.5-3;
cout <<M_MEAN[k] << "\n";
//cout << t*0.01<< "\n";
h_odn[k]->GetXaxis()->SetLabelSize(0.08);
h_odn[k]->GetXaxis()->SetNdivisions(5);
h_odn[k]->GetYaxis()->SetLabelSize(0.06);
h_odn[k]->GetYaxis()->SetNdivisions(4);
h_odn[k]->GetXaxis()->SetTitle("p");
h_odn[k]->GetYaxis()->SetTitle("counts");
h_odn[k]->GetXaxis()->SetTitleSize(0.09);
h_odn[k]->GetYaxis()->SetTitleSize(0.09);

};

//M_MEAN[k]=
//M_MEAN[k]=

P[0] = 0.44+0.015;
P[1] = 0.44+0.015;

for (t=2; t<45; t++){

P[t]=0.001*(425+10*t)+0.012;
//angle[t]=11.25+0.9*t;
cout << P[t] << "\n";
};

c->cd();
c->cd()->SetBottomMargin(0.1);
c->cd()->SetLeftMargin(0.1);
h->GetXaxis()->SetLabelSize(0.04);
h->GetXaxis()->SetNdivisions(5);
h->GetYaxis()->SetLabelSize(0.04);
h->GetYaxis()->SetNdivisions(4);
h->GetXaxis()->SetTitle("P,GeV");
h->GetYaxis()->SetTitle("#theta, deg");
h->GetXaxis()->SetTitleSize(0.04);
h->GetYaxis()->SetTitleSize(0.04);
TGraph*gr1 = new TGraph (45, P, M_MEAN);
/*gr1->Draw("P*");

TF1 *func = new TF1("fit",funct4,0.447,1.9,4);

func->SetParLimits(0,-2.,2.);
func->SetParLimits(1,-1.,1.);
func->SetParLimits(2,-10000.,1000000000.);
func->SetParLimits(3,-50.,10.);
//func->SetParameter(0,5.);
//func->SetParameter(1,4.5);
//func->SetParameter(2,11000000.);
//func->SetParameter(3,0.03);
gr1->Fit("fit");

//func->SetLineColor(kBlack);
//func->SetLineWidth(1);
func->Draw("same");*/

TF1 *f1 = new TF1("f1",funct5, 0.41,1.8,1);
 f1->SetParameter(0,-1.);
// f1->SetParameter(1,1.);
  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
   f1->Draw("same");
   
TF1 *f2 = new TF1("f2",funct6, 0.448,1.8,1);
 f2->SetParameter(0,1.5);
// f1->SetParameter(1,1.);
  f2->SetLineColor(kBlack);
  f2->SetLineWidth(2);
 f2->Draw("same"); 
   
   
   
for (k=0; k<60; k++){
c4->cd(k+1);
c4->cd(k+1)->SetBottomMargin(0.18);
c4->cd(k+1)->SetLeftMargin(0.2);

qqq << "hist1" << "n" << k;
h_odn_2[k] = h->ProjectionY(qqq.str().c_str(),28+2*k, 28+2*(k+1));
qqq.str("");

qqq<< 5*(28+2*k) << " " << " < P_{p} < " << 5*(28+2*(k+1))<< " " ;
h_odn_2[k]->SetTitle(qqq.str().c_str());


qqq.str(" ");

//h_odn_2[k]->SetAxisRange(10.,56.,"X");




if ((k>=4)) h_odn_2[k]->SetAxisRange(35.,55.,"X");
if (k==3) h_odn_2[k]->SetAxisRange(31.,34,"X");
if (k==2) h_odn_2[k]->SetAxisRange(29.,32,"X");
if (k==1) h_odn_2[k]->SetAxisRange(23.,23,"X");
if (k==0) h_odn_2[k]->SetAxisRange(21.,22,"X");
//if (k>14) 
//if (k<=4+3) 
/*if (k==0) h_odn_2[k]->SetAxisRange(45.,60,"X");
if (k==1) h_odn_2[k]->SetAxisRange(55.,70,"X");
if ((k>1)&&(k<6)) h_odn_2[k]->SetAxisRange(70.,95,"X");
//if ((k==4)) h_odn[k]->SetAxisRange(10.,40.,"X");
if ((k>=6)&&(k<17)) h_odn_2[k]->SetAxisRange(89.,105.,"X");
if ((k>=17)&&(k<23)) h_odn_2[k]->SetAxisRange(95.,110.,"X");
if ((k>=23)&&(k<26)) h_odn_2[k]->SetAxisRange(105.,110.,"X");
if ((k>=26)&&(k<28)) h_odn_2[k]->SetAxisRange(95.,110.,"X");
if ((k>=28)&&(k<32)) h_odn_2[k]->SetAxisRange(107.,109.,"X");
if ((k>=32)) h_odn_2[k]->SetAxisRange(109.,109.,"X");
if ((k==34)) h_odn_2[k]->SetAxisRange(110.,110.,"X");
*/

h_odn_2[k]->Draw();
Int_t t;
t=h_odn_2[k]->GetMinimumBin();

M_MEAN_2[k]=t*0.5-2.5;
cout <<M_MEAN_2[k] << "\n";
//cout << t*0.01<< "\n";
h_odn_2[k]->GetXaxis()->SetLabelSize(0.08);
h_odn_2[k]->GetXaxis()->SetNdivisions(5);
h_odn_2[k]->GetYaxis()->SetLabelSize(0.06);
h_odn_2[k]->GetYaxis()->SetNdivisions(4);
h_odn_2[k]->GetXaxis()->SetTitle("p");
h_odn_2[k]->GetYaxis()->SetTitle("counts");
h_odn_2[k]->GetXaxis()->SetTitleSize(0.09);
h_odn_2[k]->GetXaxis()->SetTitleSize(0.09);
h_odn_2[k]->GetYaxis()->SetTitleSize(0.09);

};


P_2[0]=0.17+0.023;
P_2[1]=0.17+0.025;
for (t=2; t<60; t++){

P_2[t]=0.001*(145+10*t)+0.015;
//angle[t]=11.25+0.9*t;
cout << P_2[t] << "\n";
};
c->cd();
c->cd()->SetBottomMargin(0.1);
c->cd()->SetLeftMargin(0.1);
c->cd()->SetRightMargin(0.12);
h->GetXaxis()->SetLabelSize(0.04);
h->GetXaxis()->SetNdivisions(5);
h->GetYaxis()->SetLabelSize(0.04);
h->GetYaxis()->SetNdivisions(4);
h->GetXaxis()->SetTitle("P (GeV)");
h->GetYaxis()->SetTitle("#theta (deg)");
h->GetXaxis()->SetTitleSize(0.04);
h->GetYaxis()->SetTitleSize(0.05);
h->SetTitle("sector 6");
TGraph*gr2 = new TGraph (60, P_2, M_MEAN_2);
//gr2->Draw("P*");

TF1 *func6 = new TF1("fit6",funct4,0.173,1.,4);

func6->SetParLimits(0,-2.,2.);
func6->SetParLimits(1,-1.,1.);
func6->SetParLimits(2,-10000.,1000000000.);
func6->SetParLimits(3,-50.,100.);

//func->SetParLimits(0,-400.,10000.);
//func->SetParLimits(1,-4900.,1500.);
//func->SetParLimits(2,-500.,2900.);
//func->SetParLimits(3,-300.,100.);

gr2->Fit("fit6");

//func->SetLineColor(kBlack);
//func->SetLineWidth(1);
//func6->Draw("same");

TF1 *f3 = new TF1("f1",funct7, 0.139,1.2,1);
 f3->SetParameter(0,-0.5);
// f1->SetParameter(1,1.);
  f3->SetLineColor(kBlack);
  f3->SetLineWidth(2);
//   f3->Draw("same");
  
TF1 *f4 = new TF1("f2",funct8, 0.172,1.2,1);
 f4->SetParameter(0,2.);
// f1->SetParameter(1,1.);
  f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
//  f4->Draw("same"); 

TF1 *f7 = new TF1("f7",funct51, 0.089,1.8,2);
 f7->SetParameter(0,260.5);
 f7->SetParameter(1,-210.);
  f7->SetLineColor(kBlack);
  f7->SetLineWidth(2);
   f7->Draw("same"); 
   
TF1 *f9 = new TF1("f9",funct52, 0.138,1.8,2);
 f9->SetParameter(0,260.5);
 f9->SetParameter(1,-214.);
  f9->SetLineColor(kBlack);
  f9->SetLineWidth(2);
   f9->Draw("same");   
   
c->SaveAs("pip_th_vs_p_sector6.pdf"); 
   
};


double fitf( double*x, double*par){
 double s;
 //mpip=0.139570;
double s = (par[0]*x[0]*x[0]*x[0]+par[1]*x[0]*x[0]+par[2]*x[0]+par[3])*exp(-2.8*x[0]);
//double s = par[0]*sqrt(x[0]+par[2])+par[1];

 //double s =par[0]*x[0]*x[0]+par[1]*x[0]+par[2];
//double s = par[0]*x[0]/sqrt(par[1]*x[0]*x[0]+par[2]) + par[3];
return s;
} ;

double funct(double *x, double *par) {
   double s;
  
     s = (837.071*x[0]*x[0]*x[0] -1600.*x[0]*x[0]+ 1417.9*x[0]-341.348+par[0])*exp(-2.*x[0]);
   return s;
};
/*double funct2(double *x, double *par) {
   double s;
  
     s = (5900*(x[0]+0.0219)*(x[0]+0.0219)*(x[0]+0.0219) -2878.53*(x[0]+0.0219)*(x[0]+0.0219)+ 1618.48*(x[0]+0.0219)-38.1497+par[0])*exp(-3.9*(x[0]+0.0219));
   return s;
};*/

double funct2(double *x, double *par) {
   double s;
  
     s = (1721.81*x[0]*x[0]*x[0]-1638.67*x[0]*x[0]+991.53*x[0]-71.2496 +par[0])*exp(-2.8*x[0]);
   return s;
};


double funct3(double *x, double *par) {
   double s;
  
     s = (10000*x[0]*x[0]*x[0]-4505.62*x[0]*x[0]+  2056.24  *x[0] -77.4077 +par[0])*exp(-4.7*x[0]);
   return s;
};

/*double funct3(double *x, double *par) {
   double s;
  
     s = (5900*(x[0]+0.01)*(x[0]+0.01)*(x[0]+0.01) -2878.53*(x[0]+0.01)*(x[0]+0.015)+ 1618.48*(x[0]+0.01)-38.1497+par[0])*exp(-4.1*(x[0]+0.01));
   return s;
};*/


double funct4(double *x, double *par) {
   double s;
  
     s = pow((x[0]-0.05+par[0]),(par[1]))*par[2] + par[3];
   return s;
};


double funct5(double *x, double *par) {
   double s;
  
     s = pow((x[0]-0.416536),(0.108376))*67.4593-21.4374+par[0];
   return s;
};
double funct6(double *x, double *par) {
   double s;
  
     s = pow((x[0] -0.454098),(0.0912936))*58.2946-20.4843+par[0];
   return s;
};

double funct7(double *x, double *par) {
   double s;
  
     s = pow((x[0]-0.05-0.0942469),( 0.0582707))*114.358-50+par[0];
   return s;
};

double funct8(double *x, double *par) {
   double s;
  
     s = pow((x[0]-0.05-0.126994),( 0.0706829))* 110.073-50+par[0];
   return s;
};

double funct51(double *x, double *par) {
   double s;
  
     s = pow((x[0]-0.097536),(0.188376))*67.4593-21.4374+par[0]+par[1];
   return s;
};

double funct52(double *x, double *par) {
   double s;
  
     s = pow((x[0]-0.14),(0.188373))*67.4593-21.4374+par[0]+par[1];
   return s;
};
