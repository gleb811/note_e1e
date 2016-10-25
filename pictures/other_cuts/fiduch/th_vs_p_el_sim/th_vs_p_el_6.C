void th_vs_p_el_6(){
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

TFile *MyFile = new TFile("../th_vs_p_p_sim/out.root","READ");

Double_t M_MEAN [45];
Double_t M_MEAN_2 [60];
TCanvas *c = new TCanvas("c","c",0,0,500,500);
//c -> Divide (2,3);
//TCanvas *c3= new TCanvas ("c3","c3",0,0,1000,1000);
//c3->Divide(5,9);
//TCanvas *c4= new TCanvas ("c4","c4",0,0,1000,1000);
//c4->Divide(6,12);
TH1D *h_odn[45];
Double_t P[45];
TH1D *h_odn_2[60];
Double_t P_2[60];
TH2 *h;
TH1 *h1;
TH1 *h2;
c->cd();
MyFile->GetObject("th_vs_p_sim/th_vs_p_e_1_sim_6",h);
c->cd()->SetBottomMargin(0.1);
c->cd()->SetLeftMargin(0.1);

h->SetMaximum(100.);

h->SetAxisRange(0.4,2.,"X");
h->SetAxisRange(10.,60.,"Y");
h->Draw("colz");
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


TF1 *f3 = new TF1("f1",thmin, 0.1,2.,2);
f3->SetParameter(0,2.1);
f3->SetParameter(1,-0.04);
// f1->SetParameter(1,1.);
  f3->SetLineColor(kBlack);
  f3->SetLineWidth(2);
  f3->Draw("same");
  
TF1 *f4 = new TF1("f2",thmin, 0.05,2.2,2);
 f4->SetParameter(0,25.);
 f4->SetParameter(1,-0.32);
  f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
// f4->Draw("same"); 
 
 
TF1 *f5 = new TF1("f3",thmin, 0.05,2.2,2);
 f5->SetParameter(0,21.8);
 f5->SetParameter(1,-0.3);
  f5->SetLineColor(kBlack);
  f5->SetLineWidth(2);
// f5->Draw("same");    

c->SaveAs("el_th_vs_p_sim_sector6.pdf");   
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


double thmin(double *x, double *par) {
   double s;
   
    
   s=(9.5+17./((x[0]-par[1])+0.2))+par[0];
   return s;
}
