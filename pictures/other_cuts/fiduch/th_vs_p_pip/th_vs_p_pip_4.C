void th_vs_p_pip_4(){
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
Double_t M_MEAN [45];
Double_t M_MEAN_2 [40];

TFile *MyFile = new TFile("../test_proton_fiduch.root","READ");

TCanvas *c = new TCanvas("c","c",0,0,500,500);
//c -> Divide (2,3);
TCanvas *c3= new TCanvas ("c3","c3",0,0,1000,1000);
c3->Divide(5,9);
TCanvas *c4= new TCanvas ("c4","c4",0,0,1000,1000);
c4->Divide(5,8);
TH1D *h_odn[45];
Double_t P[45];
TH1D *h_odn_2[40];
Double_t P_2[40];
TH2 *h;
TH1 *h1;
TH1 *h2;
c->cd();
MyFile->GetObject("th_vs_p/th_vs_p_pip_1_4",h);
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
if (k<=4+3) h_odn[k]->SetAxisRange(19.,26,"X");
//if ((k==4)) h_odn[k]->SetAxisRange(10.,40.,"X");
if ((k==0)) h_odn[k]->SetAxisRange(9.,9.,"X");
if ((k==1)) h_odn[k]->SetAxisRange(12.,12.,"X");
if ((k==2)) h_odn[k]->SetAxisRange(17.,19.,"X");
if ((k==7)) h_odn[k]->SetAxisRange(23.,29.,"X");
if ((k>=5+3)&&(k<11)) h_odn[k]->SetAxisRange(23.,29.,"X");
if ((k>=11)&&(k<13)) h_odn[k]->SetAxisRange(25.,29.,"X");
if ((k>=10+3)&&(k<22+3)) h_odn[k]->SetAxisRange(28.,35.,"X");
if ((k>=22+3)) h_odn[k]->SetAxisRange(30.,40.,"X");
if ((k==29)) h_odn[k]->SetAxisRange(32.,40.,"X");

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

P[0] = 0.44+0.024;
P[1] = 0.44+0.024;

for (t=2; t<45; t++){

P[t]=0.001*(425+10*t)+0.015;
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

TF1 *func = new TF1("fit",funct_new,0.452,1.9,4);
func->SetParLimits(0,-2.,2.);
func->SetParLimits(1,-1.,1.);
func->SetParLimits(2,-10000.,1000000000.);
func->SetParLimits(3,-50.,130.);
//func->SetParLimits(0,-400.,1000.);
//func->SetParLimits(1,-1600.,500.);
//func->SetParLimits(2,-200.,1600.);
//func->SetParLimits(3,-500.,100.);

gr1->Fit("fit");

//func->SetLineColor(kBlack);
//func->SetLineWidth(1);
func->Draw("same");*/

TF1 *f1 = new TF1("f1",funct_new2, 0.406,1.8,1);
 f1->SetParameter(0,-2.3);
// f1->SetParameter(1,1.);
  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
   f1->Draw("same");

TF1 *f2 = new TF1("f2",funct_new3, 0.452,1.8,1);
 f2->SetParameter(0,1.5);
// f1->SetParameter(1,1.);
  f2->SetLineColor(kBlack);
  f2->SetLineWidth(2);
   f2->Draw("same");
   
   
   
for (k=0; k<40; k++){
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
h_odn[k]->Draw();
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
c->cd()->SetRightMargin(0.12);
h->GetXaxis()->SetLabelSize(0.04);
h->GetXaxis()->SetNdivisions(5);
h->GetYaxis()->SetLabelSize(0.04);
h->GetYaxis()->SetNdivisions(4);
h->GetXaxis()->SetTitle("P (GeV)");
h->GetYaxis()->SetTitle("#theta (deg)");
h->GetXaxis()->SetTitleSize(0.04);
h->GetYaxis()->SetTitleSize(0.05);
h->SetTitle("sector 4");
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


TF1 *f3 = new TF1("f1",funct4, 0.05,0.8,3);
 f3->SetParameter(0,0.);
 f3->SetParameter(1,0.03);
 f3->SetParameter(2,2.75);
  f3->SetLineColor(kBlack);
  f3->SetLineWidth(2);
   f3->Draw("same");
   
TF1 *f4 = new TF1("f2",funct_f_3, 0.1,1.,2);
 f4->SetParameter(0,-7.);
//f4->SetParameter(1,-0.0);
//f4->SetParameter(2,2.8);
  f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
   f4->Draw("same"); 
   
   
TF1 *f5 = new TF1("f5",funct22, 0.05,0.8,2);
  f5->SetParameter(0,-11.+9);
 f5->SetParameter(1,-0.18);
  f5->SetLineColor(kBlack);
  f5->SetLineWidth(2);
//   f5->Draw("same"); 
   
     
TF1 *f6 = new TF1("f6",funct22, 0.05,0.8,2);
  f6->SetParameter(0,-11.+16);
 f6->SetParameter(1,-0.18);
  f6->SetLineColor(kBlack);
  f6->SetLineWidth(2);
//   f6->Draw("same"); 
c->SaveAs("pip_th_vs_p_sector4.pdf");   
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
  
     s = (881.493*x[0]*x[0]*x[0] -1600.*x[0]*x[0]+ 1349.46*x[0]-316.815+par[0])*exp(-2.*x[0]);
   return s;
};
double funct2(double *x, double *par) {
   double s;
  
     s = (5900*(x[0]+0.0219)*(x[0]+0.0219)*(x[0]+0.0219) -2878.53*(x[0]+0.0219)*(x[0]+0.0219)+ 1618.48*(x[0]+0.0219)-38.1497+par[0])*exp(-3.9*(x[0]+0.0219));
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
  
     s = pow((x[0]-0.412699),(0.214407))*52.0544 -0.0995427+ par[0];
   return s;
};

double funct_new3(double *x, double *par) {
   double s;
  
     s = pow((x[0]-0.452908),(0.102883))*84.0374  -40.301+ par[0];
   return s;
};

double funct_f_3(double *x, double *par) {
   double s;
  
     s = (pow((x[0]-0.103718),(0.0703664))*252.822-133.024)*exp(-0.45*x[0])+par[0];
   return s;
};

double funct22(double *x, double *par) {
   double s;
  
     s = (304.23*(x[0]-par[1])*(x[0]-par[1])*(x[0]-par[1]) -255.798*(x[0]-par[1])*(x[0]-par[1])+497.462*(x[0]-par[1]) +38.0385)*exp(-1.85*(x[0]-par[1])) +par[0];
   return s;
};
