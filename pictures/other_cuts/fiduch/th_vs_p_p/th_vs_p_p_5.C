void th_vs_p_p_5(){
gStyle ->SetPalette(1);
gStyle ->SetOptLogz(1);
gStyle->SetOptStat(0);
gStyle ->SetOptFit(1111);
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

Double_t M_MEAN [29];
Double_t M_MEAN_2 [90];
TCanvas *c = new TCanvas("c","c",0,0,500,500);
//c -> Divide (2,3);
//TCanvas *c3= new TCanvas ("c3","c3",0,0,1000,1000);
//c3->Divide(3,10);
//TCanvas *c4= new TCanvas ("c4","c4",0,0,1000,1000);
//c4->Divide(10,9);
TH1D *h_odn[29];
Double_t P[29];
TH1D *h_odn_2[90];
Double_t P_2[90];
TH2 *h;
TH1 *h1;
TH1 *h2;
c->cd();
MyFile->GetObject("th_vs_p/th_vs_p_p_2_5",h);
h->Draw("colz");

for (k=0; k<29; k++){
//c3->cd(k+1);
//c3->cd(k+1)->SetBottomMargin(0.18);
//c3->cd(k+1)->SetLeftMargin(0.2);

qqq << "hist" << "n" << k;
h_odn[k] = h->ProjectionY(qqq.str().c_str(),63+4*k, 63+4*(k+1));
qqq.str("");

qqq<< 10*(63+4*k) << " " << " < P_{p} < " << 10*(63+4*(k+1))<< " " ;
h_odn[k]->SetTitle(qqq.str().c_str());


qqq.str(" ");
//if (k<14) h_odn[k]->SetAxisRange(0.6,1.1,"X");
//if (k>14) 
if (k==0) h_odn[k]->SetAxisRange(10.,25,"X");
if ((k>0)&&(k<6)) h_odn[k]->SetAxisRange(11.,25,"X");
if ((k>=6)) h_odn[k]->SetAxisRange(18.,30.,"X");

//h_odn[k]->Draw();
Int_t t;
t=h_odn[k]->GetMinimumBin();

M_MEAN[k]=t*0.9;
cout <<M_MEAN[k] << "\n";
//cout << t*0.01<< "\n";
h_odn[k]->GetXaxis()->SetLabelSize(0.04);
h_odn[k]->GetXaxis()->SetNdivisions(5);
h_odn[k]->GetYaxis()->SetLabelSize(0.04);
h_odn[k]->GetYaxis()->SetNdivisions(4);
h_odn[k]->GetXaxis()->SetTitle("p");
h_odn[k]->GetYaxis()->SetTitle("counts");
h_odn[k]->GetXaxis()->SetTitleSize(0.09);
h_odn[k]->GetYaxis()->SetTitleSize(0.09);

};


for (t=0; t<29; t++){

P[t]=0.001*(650+40*t);
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
h->SetTitle("sector 5");
TGraph*gr1 = new TGraph (29, P, M_MEAN);
//gr1->Draw("P*");

//TF1 *func = new TF1("fit",fitf,0.69,2,4);
//func->SetParLimits(0,-130.,130.);

//func->SetParLimits(1,-300.,300.);
//func->SetParLimits(2,-300.,300.);
//func->SetParLimits(3,-150.,150.);

//gr1->Fit("fit");

//func->SetLineColor(kBlack);
//func->SetLineWidth(1);
//func->Draw("same");

TF1 *f1 = new TF1("f1",funct, 0.55,2.,2);
 f1->SetParameter(0,1.8);
 f1->SetParameter(1,-0.045);
  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
   f1->Draw("same");
   
TF1 *f2 = new TF1("f2",funct, 0.55,2.,2);
 f2->SetParameter(0,-2.5);
 f2->SetParameter(1,0.01);
  f2->SetLineColor(kBlack);
  f2->SetLineWidth(2);
   f2->Draw("same");   
   
   
for (k=0; k<90; k++){
//c4->cd(k+1);
//c4->cd(k+1)->SetBottomMargin(0.18);
//c4->cd(k+1)->SetLeftMargin(0.2);

qqq << "hist34" << "n" << k;
h_odn_2[k] = h->ProjectionY(qqq.str().c_str(),66+2*k, 66+2*(k+1));
qqq.str("");

qqq<< 5*(66+2*k) << " " << " < P_{p} < " << 5*(66+2*(k+1))<< " " ;
h_odn_2[k]->SetTitle(qqq.str().c_str());


qqq.str(" ");
//if (k<14) h_odn[k]->SetAxisRange(0.6,1.1,"X");
//if (k>14) 
if (k<=4+3) h_odn_2[k]->SetAxisRange(20.,23,"X");
//if ((k==4)) h_odn[k]->SetAxisRange(10.,40.,"X");
if ((k==0)) h_odn_2[k]->SetAxisRange(11.,11.,"X");
if ((k==1)) h_odn_2[k]->SetAxisRange(13.,13.,"X");
if ((k==2)) h_odn_2[k]->SetAxisRange(15.,18.,"X");
if ((k==3)) h_odn_2[k]->SetAxisRange(15.,18.,"X");
if ((k==4)) h_odn_2[k]->SetAxisRange(19.,23.,"X");
if ((k==5)) h_odn_2[k]->SetAxisRange(17.,26.,"X");
if ((k==6)) h_odn_2[k]->SetAxisRange(22.,26.,"X");
if ((k==7)) h_odn_2[k]->SetAxisRange(22.,29.,"X");
if ((k>=5+3)&&(k<11)) h_odn_2[k]->SetAxisRange(20.,29.,"X");
if ((k>=11)&&(k<13)) h_odn_2[k]->SetAxisRange(25.,29.,"X");

if ((k>=10+3)&&(k<22+3)) h_odn_2[k]->SetAxisRange(26.,35.,"X");
if ((k>=22+3)) h_odn_2[k]->SetAxisRange(30.,40.,"X");
if ((k==29)) h_odn_2[k]->SetAxisRange(32.,40.,"X");

//h_odn_2[k]->Draw();
Int_t t;
t=h_odn_2[k]->GetMinimumBin();

M_MEAN_2[k]=t*0.5-1.8;
//-4;
cout <<M_MEAN_2[k] << "\n";
//cout << t*0.01<< "\n";
h_odn_2[k]->GetXaxis()->SetLabelSize(0.08);
h_odn_2[k]->GetXaxis()->SetNdivisions(5);
h_odn_2[k]->GetYaxis()->SetLabelSize(0.06);
h_odn_2[k]->GetYaxis()->SetNdivisions(4);
h_odn_2[k]->GetXaxis()->SetTitle("p");
h_odn_2[k]->GetYaxis()->SetTitle("counts");
h_odn_2[k]->GetXaxis()->SetTitleSize(0.09);
h_odn_2[k]->GetYaxis()->SetTitleSize(0.09);

};

//M_MEAN[k]=
//M_MEAN[k]=

P_2[0] = 0.34+0.035;
//+0.045;
P_2[1] = 0.35+0.03;
//+0.04;

for (t=2; t<90; t++){

P_2[t]=0.001*(335+10*t)+0.02;
//+0.034;
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
TGraph*gr2 = new TGraph (90, P_2, M_MEAN_2);
//gr2->Draw("P*");

TF1 *func11 = new TF1("fit3",funct_new,0.365,1.9,4);
func11->SetParLimits(0,-2.,2.);
func11->SetParLimits(1,-1.,1.);
func11->SetParLimits(2,-10000.,1000000000.);
func11->SetParLimits(3,-50.,130.);
//func->SetParLimits(0,-400.,1000.);
//func->SetParLimits(1,-1600.,500.);
//func->SetParLimits(2,-200.,1600.);
//func->SetParLimits(3,-500.,100.);

gr2->Fit("fit3");


//func11->Draw("same");   
TF1 *f1 = new TF1("f1",funct_new2, 0.315,1.8,2);
 f1->SetParameter(0,0.);
 f1->SetParameter(1,0.0);
  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
// f1->Draw("same");

TF1 *f2 = new TF1("f2",funct_new3, 0.365,1.8,2);
 f2->SetParameter(0,-1.);
 f2->SetParameter(1,0.);
  f2->SetLineColor(kBlack);
  f2->SetLineWidth(2);
//   f2->Draw("same"); 







TF1 *f6 = new TF1("f6",funct_new7, 0.3+0.11,1.8,2);
 f6->SetParameter(0,0.5);
 f6->SetParameter(1,0.04);
  f6->SetLineColor(kBlack);
  f6->SetLineWidth(2);
  f6->Draw("same"); 
  
TF1 *f9 = new TF1("f9",funct_new9, 0.3+0.146,1.8,2);
 f9->SetParameter(0,0.5);
 f9->SetParameter(1,0.04);
  f9->SetLineColor(kBlack);
  f9->SetLineWidth(2);
  f9->Draw("same"); 
  
TF1 *f9 = new TF1("f9",funct_new2, 0.3+0.06,1.8,2);
 f9->SetParameter(0,1);
 f9->SetParameter(1,0.07);
  f9->SetLineColor(kBlack);
  f9->SetLineWidth(2);
  f9->Draw("same");

TF1 *f7 = new TF1("f7",funct_new2, 0.3+0.03,1.8,2);
 f7->SetParameter(0,3.5);
 f7->SetParameter(1,0.04);
  f7->SetLineColor(kBlack);
  f7->SetLineWidth(2);
  f7->Draw("same"); 

   
c->SaveAs("p_th_vs_p_sector5.pdf");    
     
};


double fitf( double*x, double*par){
 double s;
 //mpip=0.139570;
double s = par[0]*x[0]*x[0]*x[0]+par[1]*x[0]*x[0]+par[2]*x[0]+par[3];
//double s = sqrt(par[0]*x[0]+par[1])+par[2];

// double s =par[0]*x[0]*x[0]+par[1]*x[0]+par[2];
//double s = par[0]*x[0]/sqrt(par[1]*x[0]*x[0]+par[2]) + par[3];
return s;
} ;

double funct(double *x, double *par) {
   double s;
  
     s = 31.2482*(x[0]-par[1])*(x[0]-par[1])*(x[0]-par[1]) -135.817*(x[0]-par[1])*(x[0]-par[1])+ 198.038*(x[0]-par[1])-66.968+par[0];
   return s;
};

double funct_new(double *x, double *par) {
   double s;
  
     s = pow((x[0]+par[0]),(par[1]))*par[2] + par[3];
   return s;
};

double funct_new2(double *x, double *par) {
   double s;
  
     s = pow((x[0]-par[1]-0.294992),(0.0758186))*91.5643-48.2057 + par[0];
   return s;
};

double funct_new3(double *x, double *par) {
   double s;
  
     s = pow((x[0] -par[1]-0.371051),(  0.0649747))*87.0943  -49.9895+ par[0];
   return s;
};
double funct_new7(double *x, double *par) {
   double s;
  
     s = pow((x[0]-par[1]-0.374992),(0.0758186))*91.5643-48.2057 + par[0];
   return s;
};

double funct_new9(double *x, double *par) {
   double s;
  
     s = pow((x[0]-par[1]-0.410992),(0.0758186))*91.5643-48.2057 + par[0];
   return s;
};
