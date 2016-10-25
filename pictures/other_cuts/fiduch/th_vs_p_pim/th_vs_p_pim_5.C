void th_vs_p_pim_5(){
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
TCanvas *c = new TCanvas("c","c",0,0,500,500);
//c -> Divide (2,3);
TCanvas *c3= new TCanvas ("c3","c3",0,0,1000,1000);
c3->Divide(5,9);
TCanvas *c4= new TCanvas ("c4","c4",0,0,1000,1000);
c4->Divide(9,5);
TH1D *h_odn[45];
Double_t P[45];
TH1D *h_odn_2[45];
Double_t P_2[45];
TH2 *h;
TH1 *h1;
TH1 *h2;
c->cd();
MyFile->GetObject("th_vs_p/th_vs_p_pim_1_5",h);
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
h->Draw("colz");


TF1 *f3 = new TF1("f1",thmin, 0.1,2.,2);
f3->SetParameter(0,0.);
f3->SetParameter(1,0.);
// f1->SetParameter(1,1.);
  f3->SetLineColor(kBlack);
  f3->SetLineWidth(2);
  f3->Draw("same");
for (k=0; k<45; k++){
c4->cd(k+1);
c4->cd(k+1)->SetBottomMargin(0.18);
c4->cd(k+1)->SetLeftMargin(0.2);

qqq << "hist1" << "n" << k;
h_odn_2[k] = h->ProjectionY(qqq.str().c_str(),30+4*k, 30+4*(k+1));
qqq.str("");

qqq<< 5*(30+4*k) << " " << " < P_{p} < " << 5*(30+4*(k+1))<< " " ;
h_odn_2[k]->SetTitle(qqq.str().c_str());


qqq.str(" ");
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

h_odn_2[k]->SetAxisRange(38.,80,"X");
if (k==0) h_odn_2[k]->SetAxisRange(70.,80,"X");
if (k==1) h_odn_2[k]->SetAxisRange(67.,80,"X");
if ((k>1)&&(k<=4)) h_odn_2[k]->SetAxisRange(60.,70,"X");
if ((k>4)&&(k<=9)) h_odn_2[k]->SetAxisRange(50.,70,"X");
if ((k>9)&&(k<=12)) h_odn_2[k]->SetAxisRange(45.,60.,"X");
if ((k>12)&&(k<=16)) h_odn_2[k]->SetAxisRange(45.,55.,"X");
if ((k>16)&&(k<=26)) h_odn_2[k]->SetAxisRange(45.,49.,"X");
if ((k>26)) h_odn_2[k]->SetAxisRange(40.,44.,"X");
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

P_2[t]=0.001*(160+20*t);
//angle[t]=11.25+0.9*t;
cout << P_2[t] << "\n";
};
c->cd();

TGraph*gr2 = new TGraph (45, P_2, M_MEAN_2);
//gr2->Draw("P*");

TF1 *func1 = new TF1("fit2",funct,0.05,2.,4);
func1->SetParLimits(0,-20.,200.);

func1->SetParLimits(1,-20.,200.);
func1->SetParLimits(2,0.,1.);
func1->SetParLimits(3,0.,1.);

//gr2->Fit("fit2");
//func1->Draw("same"); 
 
TF1 *f4 = new TF1("f4",funct2, 0.05,2.,2);
 f4->SetParameter(0,4.);
 f4->SetParameter(1,0.);
  f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
 f4->Draw("same"); 
 
 
TF1 *f5 = new TF1("f5",funct2, 0.05,2.,2);
 f5->SetParameter(0,-1.5);
 f5->SetParameter(1,0.);
  f5->SetLineColor(kBlack);
  f5->SetLineWidth(2);
 f5->Draw("same");   

   
TF1 *f4 = new TF1("f4",funct2, 0.15,0.5,2);
 f4->SetParameter(0,72.);
 f4->SetParameter(1,-0.2);
  f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
// f4->Draw("same"); 
 
 
TF1 *f5 = new TF1("f5",funct2, 0.15,0.5,2);
 f5->SetParameter(0,60);
 f5->SetParameter(1,-0.03);
  f5->SetLineColor(kBlack);
  f5->SetLineWidth(2);
// f5->Draw("same");     


TF1 *f4 = new TF1("f4",funct2, 0.,0.5,2);
 f4->SetParameter(0,85.);
 f4->SetParameter(1,-0.1);
  f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
// f4->Draw("same"); 
 
 
TF1 *f5 = new TF1("f5",funct2, 0.,0.5,2);
 f5->SetParameter(0,82);
 f5->SetParameter(1,-0.2);
  f5->SetLineColor(kBlack);
  f5->SetLineWidth(2);
// f5->Draw("same"); 

c->SaveAs("pim_th_vs_p_sector5.pdf");    
};


double fitf( double*x, double*par){
 double s;
double s = (par[0]*x[0]*x[0]*x[0]+par[1]*x[0]*x[0]+par[2]*x[0]+par[3])*exp(-2.8*x[0]);

return s;
} ;


double funct4(double *x, double *par) {
   double s;
  
     s = pow((x[0]-0.05+par[0]),(par[1]))*par[2] + par[3];
   return s;
};

double thmin(double *x, double *par) {
   double s;
   
     s=11.09+8./(0.472*(x[0]-par[1])+0.117)+par[0];
   
   return s;
}


double funct(double *x, double *par) {
   double s;
   
     s=par[0]+par[1]/(par[2]*x[0]+par[3]);
   
   return s;
   }
   
double funct2(double *x, double *par) {
   double s;
   
     s=36.152+3.69909e-05/(5.40783e-06*(x[0]-par[1])+1.81169e-07)+par[0];
   
   return s;
   }
