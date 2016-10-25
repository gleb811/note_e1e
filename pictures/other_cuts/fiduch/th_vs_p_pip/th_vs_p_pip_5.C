void th_vs_p_pip_5(){
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
Double_t M_MEAN_2 [45];
Double_t M_MEAN_3 [20];
TCanvas *c = new TCanvas("c","c",0,0,500,500);
//c -> Divide (2,3);
TCanvas *c3= new TCanvas ("c3","c3",0,0,1000,1000);
c3->Divide(5,9);
TCanvas *c4= new TCanvas ("c4","c4",0,0,1000,1000);
c4->Divide(5,9);
TCanvas *c5= new TCanvas ("c5","c5",0,0,1000,1000);
c5->Divide(4,5);
TH1D *h_odn[45];
Double_t P[45];
TH1D *h_odn_2[45];
Double_t P_2[45];
TH1D *h_odn_3[20];
Double_t P_3[20];

TH2 *h;
TH1 *h1;
TH1 *h2;
c->cd();
MyFile->GetObject("th_vs_p/th_vs_p_pip_1_5",h);
h->Draw("colz");

for (k=0; k<45; k++){
c3->cd(k+1);
c3->cd(k+1)->SetBottomMargin(0.18);
c3->cd(k+1)->SetLeftMargin(0.2);

qqq << "hist" << "n" << k;
h_odn[k] = h->ProjectionY(qqq.str().c_str(),64+2*k, 64+2*(k+1));
qqq.str("");

qqq<< 5*(64+2*k) << " " << " < P_{p} < " << 5*(64+2*(k+1))<< " " ;
h_odn[k]->SetTitle(qqq.str().c_str());


qqq.str(" ");
//if (k<14) h_odn[k]->SetAxisRange(0.6,1.1,"X");
//if (k>14) 
if (k<=4+3) h_odn[k]->SetAxisRange(20.,23,"X");
//if ((k==4)) h_odn[k]->SetAxisRange(10.,40.,"X");
if ((k==0)) h_odn[k]->SetAxisRange(9.,9.,"X");
if ((k==1)) h_odn[k]->SetAxisRange(12.,12.,"X");
if ((k==2)) h_odn[k]->SetAxisRange(17.,18.,"X");
if ((k==4)) h_odn[k]->SetAxisRange(21.,23.,"X");
if ((k==5)) h_odn[k]->SetAxisRange(22.,26.,"X");
if ((k==6)) h_odn[k]->SetAxisRange(24.,26.,"X");
if ((k==7)) h_odn[k]->SetAxisRange(24.,29.,"X");
if ((k>=5+3)&&(k<11)) h_odn[k]->SetAxisRange(23.,29.,"X");
if ((k>=11)&&(k<13)) h_odn[k]->SetAxisRange(25.,29.,"X");

if ((k>=10+3)&&(k<22+3)) h_odn[k]->SetAxisRange(26.,35.,"X");
if ((k>=22+3)) h_odn[k]->SetAxisRange(30.,40.,"X");
if ((k==29)) h_odn[k]->SetAxisRange(32.,40.,"X");

h_odn[k]->Draw();
Int_t t;
t=h_odn[k]->GetMinimumBin();

M_MEAN[k]=t*0.5-4;
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

P[0] = 0.325+0.045;
P[1] = 0.335+0.04;

for (t=2; t<45; t++){

P[t]=0.001*(325+10*t)+0.034;
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
//gr1->Draw("P*");

TF1 *func = new TF1("fit",funct_new,0.365,1.9,4);
func->SetParLimits(0,-2.,2.);
func->SetParLimits(1,-1.,1.);
func->SetParLimits(2,-10000.,1000000000.);
func->SetParLimits(3,-50.,130.);
//func->SetParLimits(0,-400.,1000.);
//func->SetParLimits(1,-1600.,500.);
//func->SetParLimits(2,-200.,1600.);
//func->SetParLimits(3,-500.,100.);

gr1->Fit("fit");


//func->Draw("same");

TF1 *f1 = new TF1("f1",funct_new2, 0.3,1.8,1);
 f1->SetParameter(0,-1.);
// f1->SetParameter(1,1.);
  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
   f1->Draw("same");

TF1 *f2 = new TF1("f2",funct_new3, 0.365,1.8,1);
 f2->SetParameter(0,1.5);
// f1->SetParameter(1,1.);
  f2->SetLineColor(kBlack);
  f2->SetLineWidth(2);
  f2->Draw("same");
  
   
   
/*for (k=0; k<40; k++){
c4->cd(k+1);
c4->cd(k+1)->SetBottomMargin(0.18);
c4->cd(k+1)->SetLeftMargin(0.2);

qqq << "hist" << "n" << k;
h_odn[k] = h->ProjectionY(qqq.str().c_str(),18+2*k, 18+2*(k+1));
qqq.str("");

qqq<< 5*(18+2*k) << " " << " < P_{p} < " << 5*(18+2*(k+1))<< " " ;
h_odn[k]->SetTitle(qqq.str().c_str());


qqq.str(" ");
//if (k<14) h_odn[k]->SetAxisRange(0.6,1.1,"X");
//if (k>14) 
if ((k==0)) h_odn[k]->SetAxisRange(44.,70.,"X");
if ((k==1)) h_odn[k]->SetAxisRange(50.,70.,"X");

if ((k>=2)&&(k<4+2)) h_odn[k]->SetAxisRange(55.,75,"X");
if ((k==4+2)) h_odn[k]->SetAxisRange(60.,75.,"X");
if ((k>=5+2)) h_odn[k]->SetAxisRange(60.,80.,"X");
if ((k==11+2)) h_odn[k]->SetAxisRange(60.,74.,"X");
if ((k==19+2)) h_odn[k]->SetAxisRange(75.,80.,"X");
//h_odn[k]->Draw();
Int_t t;
t=h_odn[k]->GetMinimumBin();

M_MEAN[k]=t*0.5;
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


for (t=0; t<40; t++){

P[t]=0.001*(95+10*t);
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
TGraph*gr2 = new TGraph (40, P, M_MEAN);   


/*gr2->Draw("P*");



TF1 *func1 = new TF1("fit1",fitf,0.05,1.,4);
func1->SetParLimits(0,-400.,1600.);

func1->SetParLimits(1,-1700.,500.);
func1->SetParLimits(2,-200.,1450.);
func1->SetParLimits(3,-100.,100.);

gr2->Fit("fit1");

//func->SetLineColor(kBlack);
//func->SetLineWidth(1);
func1->Draw("same");*/


/*TF1 *f3 = new TF1("f1",funct4, 0.05,0.7,3);
 f3->SetParameter(0,0.);
 f3->SetParameter(1,0.025);
 f3->SetParameter(2,2.7);
  f3->SetLineColor(kBlack);
  f3->SetLineWidth(2);
   f3->Draw("same");
   
TF1 *f4 = new TF1("f2",funct4, 0.05,0.7,3);
 f4->SetParameter(0,-7.);
f4->SetParameter(1,-0.0);
f4->SetParameter(2,2.8);
  f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
   f4->Draw("same"); */
   
   
for (k=0; k<45; k++){
c4->cd(k+1);
c4->cd(k+1)->SetBottomMargin(0.18);
c4->cd(k+1)->SetLeftMargin(0.2);

qqq << "hist1" << "n" << k;
h_odn_2[k] = h->ProjectionY(qqq.str().c_str(),124+4*k, 124+4*(k+1));
qqq.str("");

qqq<< 5*(124+4*k) << " " << " < P_{p} < " << 5*(124+4*(k+1))<< " " ;
h_odn_2[k]->SetTitle(qqq.str().c_str());


qqq.str(" ");
//if (k<14) h_odn[k]->SetAxisRange(0.6,1.1,"X");
//if (k>14) 
//if (k<=4+3) 
if (k<6) h_odn_2[k]->SetAxisRange(13.,30,"X");
if ((k==3)) h_odn_2[k]->SetAxisRange(10.,15.,"X");
if ((k==4)) h_odn_2[k]->SetAxisRange(16.,18.,"X");
if ((k==6)) h_odn_2[k]->SetAxisRange(16.,18.,"X");
if ((k>6)&&(k<17)) h_odn_2[k]->SetAxisRange(13.,25.,"X");
if ((k>=17)&&(k<26)) h_odn_2[k]->SetAxisRange(20.,27.,"X");
if ((k>=26)&&(k<36)) h_odn_2[k]->SetAxisRange(19.,27.,"X");
if ((k>=36)) h_odn_2[k]->SetAxisRange(28.,28.,"X");


h_odn_2[k]->Draw();
Int_t t;
t=h_odn_2[k]->GetMinimumBin();

M_MEAN_2[k]=t*0.5;
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
for (t=0; t<45; t++){

P_2[t]=0.001*(630+15*t);
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
h->SetTitle("sector 5");
TGraph*gr2 = new TGraph (45, P_2, M_MEAN_2);
//gr2->Draw("P*");

TF1 *func1 = new TF1("fit",fitf,0.55,1.9,4);
func->SetParLimits(0,-400.,600.);

func1->SetParLimits(1,-1700.,500.);
func1->SetParLimits(2,-200.,1650.);
func1->SetParLimits(3,-500.,100.);

gr2->Fit("fit");

//func->SetLineColor(kBlack);
//func->SetLineWidth(1);
//func1->Draw("same");

TF1 *f3 = new TF1("f1",funct2, 0.35,1.8,2);
 f3->SetParameter(0,0);
 f3->SetParameter(1,-0.03);
  f3->SetLineColor(kBlack);
  f3->SetLineWidth(2);
   f3->Draw("same");
   
TF1 *f4 = new TF1("f2",funct2, 0.35,1.8,2);
 f4->SetParameter(0,-4.7);
 f4->SetParameter(1,0.02);
  f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
   f4->Draw("same"); 
      



   
for (k=0; k<20; k++){
c5->cd(k+1);
c5->cd(k+1)->SetBottomMargin(0.18);
c5->cd(k+1)->SetLeftMargin(0.2);

qqq << "hist3" << "y" << k;
h_odn_3[k] = h->ProjectionY(qqq.str().c_str(),30+4*k, 30+4*(k+1));
qqq.str("");

qqq<< 5*(30+4*k) << " " << " < P_{p} < " << 5*(30+4*(k+1))<< " " ;
h_odn_3[k]->SetTitle(qqq.str().c_str());


qqq.str(" ");

h_odn_3[k]->SetAxisRange(50,97,"X");
//if (k<14) h_odn[k]->SetAxisRange(0.6,1.1,"X");
//if (k>14) 
//if (k<=4+3) 
/*if (k<6) h_odn_2[k]->SetAxisRange(13.,30,"X");
if ((k==3)) h_odn_2[k]->SetAxisRange(10.,15.,"X");
if ((k==4)) h_odn_2[k]->SetAxisRange(16.,18.,"X");
if ((k==6)) h_odn_2[k]->SetAxisRange(16.,18.,"X");
if ((k>6)&&(k<17)) h_odn_2[k]->SetAxisRange(13.,25.,"X");
if ((k>=17)&&(k<26)) h_odn_2[k]->SetAxisRange(20.,27.,"X");
if ((k>=26)&&(k<36)) h_odn_2[k]->SetAxisRange(19.,27.,"X");
if ((k>=36)) h_odn_2[k]->SetAxisRange(28.,28.,"X");
*/

h_odn_3[k]->Draw();
Int_t t;
t=h_odn_3[k]->GetMinimumBin();

M_MEAN_3[k]=t*0.5;
//cout <<M_MEAN_2[k] << "\n";
//cout << t*0.01<< "\n";
h_odn_3[k]->GetXaxis()->SetLabelSize(0.08);
h_odn_3[k]->GetXaxis()->SetNdivisions(5);
h_odn_3[k]->GetYaxis()->SetLabelSize(0.06);
h_odn_3[k]->GetYaxis()->SetNdivisions(4);
h_odn_3[k]->GetXaxis()->SetTitle("p");
h_odn_3[k]->GetYaxis()->SetTitle("counts");
h_odn_3[k]->GetXaxis()->SetTitleSize(0.09);
h_odn_3[k]->GetXaxis()->SetTitleSize(0.09);
h_odn_3[k]->GetYaxis()->SetTitleSize(0.09);

};
for (t=0; t<20; t++){

P_3[t]=0.001*(160+15*t);
//angle[t]=11.25+0.9*t;
//cout << P_2[t] << "\n";
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
h->SetTitle("Sector 5");
TGraph*gr3 = new TGraph (20, P_3, M_MEAN_3);
//gr3->Draw("P*");

TF1 *func3 = new TF1("fit3",fitf,0.,1.,4);
func3->SetParLimits(0,-400.,600.);

func3->SetParLimits(1,-1700.,500.);
func3->SetParLimits(2,-200.,1650.);
func3->SetParLimits(3,-1500.,100.);

gr3->Fit("fit3");

//func->SetLineColor(kBlack);
//func->SetLineWidth(1);
//func3->Draw("same");

TF1 *f3 = new TF1("f1",funct22, 0.,1.,2);
 f3->SetParameter(0,0.);
 f3->SetParameter(1,-0.0);
  f3->SetLineColor(kBlack);
  f3->SetLineWidth(2);
   f3->Draw("same");
   
TF1 *f4 = new TF1("f2",funct22, 0.,1.,2);
 f4->SetParameter(0,-11.);
 f4->SetParameter(1,-0.03);
  f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
  f4->Draw("same"); 

c->SaveAs("pip_th_vs_p_sector5.pdf");
   
};


double fitf( double*x, double*par){
 double s;
 //mpip=0.139570;
double s = (par[0]*x[0]*x[0]*x[0]+par[1]*x[0]*x[0]+par[2]*x[0]+par[3])*exp(-2.*x[0]);
//double s = par[0]*sqrt(x[0]+par[2])+par[1];

 //double s =par[0]*x[0]*x[0]+par[1]*x[0]+par[2];
//double s = par[0]*x[0]/sqrt(par[1]*x[0]*x[0]+par[2]) + par[3];
return s;
} ;

double funct(double *x, double *par) {
   double s;
  
     s = (881.493*x[0]*x[0]*x[0] -1600.*x[0]*x[0]+ 1349.46*x[0]-316.815+par[0])*exp(-2.*x[0]);
   return s;
};

double funct2(double *x, double *par) {
   double s;
  
     s = (525.498*(x[0]-par[1])*(x[0]-par[1])*(x[0]-par[1]) -1284.98*(x[0]-par[1])*(x[0]-par[1])+1460.67*(x[0]-par[1])-499.999)*exp(-1.94*(x[0]-par[1])) +par[0];
   return s;
};


double funct22(double *x, double *par) {
   double s;
  
     s = (304.23*(x[0]-par[1])*(x[0]-par[1])*(x[0]-par[1]) -255.798*(x[0]-par[1])*(x[0]-par[1])+497.462*(x[0]-par[1]) +38.0385)*exp(-1.85*(x[0]-par[1])) +par[0];
   return s;
};



double funct3(double *x, double *par) {
   double s;
  
     s = (5900*(x[0]+0.01)*(x[0]+0.01)*(x[0]+0.01) -2878.53*(x[0]+0.01)*(x[0]+0.015)+ 1618.48*(x[0]+0.01)-38.1497+par[0])*exp(-4.1*(x[0]+0.01));
   return s;
};

double funct4(double *x, double *par) {
   double s;
  
     s = (1600*(x[0]+par[1])*(x[0]+par[1])*(x[0]+par[1]) -1068.36*(x[0]+par[1])*(x[0]+par[1])+ 775.016*(x[0]+par[1])-1.13034+par[0])*exp(-par[2]*(x[0]+par[1]));
   return s;

};

double funct_new(double *x, double *par) {
   double s;
  
     s = pow((x[0]+par[0]),(par[1]))*par[2] + par[3];
   return s;
};

double funct_new2(double *x, double *par) {
   double s;
  
     s = pow((x[0]-0.304992),(0.0758186))*91.5643-48.2057 + par[0];
   return s;
};

double funct_new3(double *x, double *par) {
   double s;
  
     s = pow((x[0] -0.36848),( 0.0864219))*70.4769  -34.9998+ par[0];
   return s;
};


