void th_vs_p_pip_2(){
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
Double_t M_MEAN [39];
Double_t M_MEAN_2 [28];

TFile *MyFile = new TFile("../test_proton_fiduch.root","READ");

TCanvas *c = new TCanvas("c","c",0,0,500,500);
//c -> Divide (2,3);
TCanvas *c3= new TCanvas ("c3","c3",0,0,1000,1000);
c3->Divide(6,6);
TCanvas *c4= new TCanvas ("c4","c4",0,0,1000,1000);
c4->Divide(6,5);
TH1D *h_odn[39];
Double_t P[39];
TH1D *h_odn_2[28];
Double_t P_2[28];
TH2 *h;
TH1 *h1;
TH1 *h2;
c->cd();
MyFile->GetObject("th_vs_p/th_vs_p_pip_1_2",h);
h->Draw("colz");

for (k=0; k<39; k++){
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
if (k<=4+3) h_odn[k]->SetAxisRange(19.,26,"X");
//if ((k==4)) h_odn[k]->SetAxisRange(10.,40.,"X");
if ((k==0)) h_odn[k]->SetAxisRange(8.,8.,"X");
if ((k==1)) h_odn[k]->SetAxisRange(12.,12.,"X");
if ((k==2)) h_odn[k]->SetAxisRange(17.,19.,"X");
//if ((k>=0)&&(k<=3)) h_odn[k]->SetAxisRange(23.,29.,"X");
if ((k>=5+3)&&(k<10+3)) h_odn[k]->SetAxisRange(23.,29.,"X");
if ((k>=10+3)&&(k<22+3)) h_odn[k]->SetAxisRange(25.,35.,"X");
if ((k>=22+3)) h_odn[k]->SetAxisRange(31.,35.,"X");

h_odn[k]->Draw();
Int_t t;
t=h_odn[k]->GetMinimumBin();

M_MEAN[k]=t*0.5-2;
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

P[0] = 0.44+0.01;
P[1] = 0.44+0.01;

for (t=2; t<39; t++){

P[t]=0.001*(425+10*t)+0.015;
//angle[t]=11.25+0.9*t;
cout << P[t] << "\n";
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
h->SetTitle("sector 2");
TGraph*gr1 = new TGraph (39, P, M_MEAN);
/*gr1->Draw("P*");

TF1 *func = new TF1("fit",funct3,0.4429,1.9,4);
func->SetParLimits(0,-2.,2.);
func->SetParLimits(1,-1.,1.);
func->SetParLimits(2,-10000.,1000000000.);
func->SetParLimits(3,-50.,130.);
//func->SetParLimits(0,-400.,1000.);
//func->SetParLimits(1,-2700.,500.);
//func->SetParLimits(2,-200.,1650.);
//func->SetParLimits(3,-500.,100.);

gr1->Fit("fit");

//func->SetLineColor(kBlack);
//func->SetLineWidth(1);
func->Draw("same");*/

TF1 *f1 = new TF1("f1",funct4, 0.4083,1.8,1);
 f1->SetParameter(0,-1.);
// f1->SetParameter(1,1.);
  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
   f1->Draw("same");
   
TF1 *f2 = new TF1("f2",funct5, 0.4432,1.8,1);
 f2->SetParameter(0,-1.);
// f1->SetParameter(1,1.);
  f2->SetLineColor(kBlack);
  f2->SetLineWidth(2);
   f2->Draw("same"); 
   
   
   
for (k=0; k<28; k++){
c4->cd(k+1);
c4->cd(k+1)->SetBottomMargin(0.18);
c4->cd(k+1)->SetLeftMargin(0.2);

qqq << "hist1" << "n" << k;
h_odn_2[k] = h->ProjectionY(qqq.str().c_str(),67+3*k, 67+3*(k+1));
qqq.str("");

qqq<< 10*(67+3*k) << " " << " < P_{p} < " << 10*(67+3*(k+1))<< " " ;
h_odn_2[k]->SetTitle(qqq.str().c_str());


qqq.str(" ");
//if (k<14) h_odn[k]->SetAxisRange(0.6,1.1,"X");
//if (k>14) 
//if (k<=4+3) 
if (k<6) h_odn_2[k]->SetAxisRange(11.,30,"X");
//if ((k==4)) h_odn[k]->SetAxisRange(10.,40.,"X");
if ((k>=6)&&(k<17)) h_odn_2[k]->SetAxisRange(13.,25.,"X");
if ((k>=17)&&(k<26)) h_odn_2[k]->SetAxisRange(20.,27.,"X");
if ((k>=26)) h_odn_2[k]->SetAxisRange(17.,27.,"X");
if ((k==1)) h_odn[k]->SetAxisRange(13.,15.,"X");
if ((k==2)) h_odn[k]->SetAxisRange(17.,19.,"X");
//if ((k>=0)&&(k<=3)) h_odn[k]->SetAxisRange(23.,29.,"X");
if ((k>=5+3)&&(k<10+3)) h_odn[k]->SetAxisRange(23.,29.,"X");
if ((k>=10+3)&&(k<22+3)) h_odn[k]->SetAxisRange(25.,35.,"X");
if ((k>=22+3)) h_odn[k]->SetAxisRange(30.,40.,"X");

h_odn_2[k]->Draw();
Int_t t;
t=h_odn_2[k]->GetMinimumBin();

M_MEAN_2[k]=t*0.9;
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
for (t=0; t<28; t++){

P_2[t]=0.001*(685+30*t);
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
h->SetTitle("sector 2");
TGraph*gr2 = new TGraph (28, P_2, M_MEAN_2);
//gr2->Draw("P*");

TF1 *func = new TF1("fit",fitf,0.05,1.9,4);
func->SetParLimits(0,-400.,600.);

func->SetParLimits(1,-1700.,500.);
func->SetParLimits(2,-200.,1650.);
func->SetParLimits(3,-300.,100.);

//gr2->Fit("fit");

//func->SetLineColor(kBlack);
//func->SetLineWidth(1);
//func->Draw("same");
TF1 *f3 = new TF1("f1",funct2, 0.35,1.8,1);
 f3->SetParameter(0,15.);
// f1->SetParameter(1,1.);
  f3->SetLineColor(kBlack);
  f3->SetLineWidth(2);
   f3->Draw("same");
   
TF1 *f4 = new TF1("f2",funct2, 0.35,1.8,1);
 f4->SetParameter(0,-15.);
// f1->SetParameter(1,1.);
  f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
   f4->Draw("same"); 
   

 TF1 *f3 = new TF1("f1",funct_f_2, 0.056,1.5,2);
 f3->SetParameter(0,0);
 f3->SetParameter(1,-0.0);
  f3->SetLineColor(kBlack);
  f3->SetLineWidth(2);
//   f3->Draw("same");
   
TF1 *f4 = new TF1("f2",funct_f_3, 0.098+0.019,1.5,2);
 f4->SetParameter(0,-5.5);
 f4->SetParameter(1,0.02);
  f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
// f4->Draw("same"); 

c->SaveAs("pip_th_vs_p_sector2.pdf"); 
  
};


double fitf( double*x, double*par){
 double s;
 //mpip=0.139570;
double s = (par[0]*x[0]*x[0]*x[0]+par[1]*x[0]*x[0]+par[2]*x[0]+par[3])*exp(-2*x[0]);
//double s = par[0]*sqrt(x[0]+par[2])+par[1];

 //double s =par[0]*x[0]*x[0]+par[1]*x[0]+par[2];
//double s = par[0]*x[0]/sqrt(par[1]*x[0]*x[0]+par[2]) + par[3];
return s;
} ;

double funct(double *x, double *par) {
   double s;
  
     s = (600*x[0]*x[0]*x[0] -1217.04*x[0]*x[0]+ 1196.08*x[0]-300+par[0])*exp(-2*x[0]);
   return s;
};
double funct2(double *x, double *par) {
   double s;
  
     s = (387.289*x[0]*x[0]*x[0] -758.466*x[0]*x[0]+ 842.881*x[0]-299.953+par[0])*exp(-2*x[0]);
   return s;
};
double funct3(double *x, double *par) {
   double s;
  
     s = pow((x[0]+par[0]),(par[1]))*par[2] + par[3];
   return s;
};

double funct4(double *x, double *par) {
   double s;
  
     s = pow((x[0]-0.415068),(0.226449))*48.7564 + 2.79478+par[0];
   return s;
};

double funct5(double *x, double *par) {
   double s;
  
     s = pow((x[0]-0.449975),( 0.315164 ))*36.608 +  9.74262+par[0];
   return s;
};
double funct22(double *x, double *par) {
   double s;
  
     s = (304.23*(x[0]-par[1])*(x[0]-par[1])*(x[0]-par[1]) -255.798*(x[0]-par[1])*(x[0]-par[1])+497.462*(x[0]-par[1]) +38.0385)*exp(-1.85*(x[0]-par[1])) +par[0];
   return s;
};
double funct_f_2(double *x, double *par) {
   double s;
  
     s = (pow((x[0]-0.0575818),( 0.075643))*238.248-115.039)*exp(-0.5*x[0])+par[0];
   return s;
};


double funct_f_3(double *x, double *par) {
   double s;
  
     s = (pow((x[0]-par[1]-0.103718),(0.0703664))*252.822-133.024)*exp(-0.5*x[0])+par[0];
   return s;
};
