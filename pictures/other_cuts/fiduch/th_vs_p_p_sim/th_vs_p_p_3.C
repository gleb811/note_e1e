void th_vs_p_p_3(){
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

TFile *MyFile = new TFile("out.root","READ");

Double_t M_MEAN [28];
TCanvas *c = new TCanvas("c","c",0,0,500,500);
//c -> Divide (2,3);
//TCanvas *c3= new TCanvas ("c3","c3",0,0,1000,1000);
//c3->Divide(4,7);
TH1D *h_odn[28];
Double_t P[28];
TH2 *h;
TH1 *h1;
TH1 *h2;
c->cd();
MyFile->GetObject("th_vs_p_sim/th_vs_p_p_1_sim_3",h);
h->Draw("colz");

for (k=0; k<28; k++){
//c3->cd(k+1);
//c3->cd(k+1)->SetBottomMargin(0.18);
//c3->cd(k+1)->SetLeftMargin(0.2);

qqq << "hist" << "n" << k;
h_odn[k] = h->ProjectionY(qqq.str().c_str(),67+4*k, 67+4*(k+1));
qqq.str("");

qqq<< 10*(67+4*k) << " " << " < P_{p} < " << 10*(67+4*(k+1))<< " " ;
h_odn[k]->SetTitle(qqq.str().c_str());


qqq.str(" ");
//if (k<14) h_odn[k]->SetAxisRange(0.6,1.1,"X");
//if (k>14) 
if (k<6) h_odn[k]->SetAxisRange(11.,25,"X");
if ((k>=6)) h_odn[k]->SetAxisRange(18.,30.,"X");

//h_odn[k]->Draw();
Int_t t;
t=h_odn[k]->GetMinimumBin();

M_MEAN[k]=t*0.9;
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


for (t=0; t<28; t++){

P[t]=0.001*(690+40*t);
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
h->SetTitle("sector 3");
TGraph*gr1 = new TGraph (28, P, M_MEAN);
//gr1->Draw("P*");

//TF1 *func = new TF1("fit",fitf,0.69,2,4);
//func->SetParLimits(0,-30.,30.);

//func->SetParLimits(1,-300.,300.);
//func->SetParLimits(2,-300.,300.);
//func->SetParLimits(3,-150.,150.);

//gr1->Fit("fit");

//func->SetLineColor(kBlack);
//func->SetLineWidth(1);
//func->Draw("same");

TF1 *f1 = new TF1("f1",funct, 0.6,2.,1);
 f1->SetParameter(0,2.);
// f1->SetParameter(1,1.);
  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
//   f1->Draw("same");
   
TF1 *f2 = new TF1("f2",funct, 0.6,2.,1);
 f2->SetParameter(0,-3.);
// f1->SetParameter(1,1.);
  f2->SetLineColor(kBlack);
  f2->SetLineWidth(2);
 //  f2->Draw("same");   
 
 
 TF1 *f3 = new TF1("f1",funct22, 0.1,1.,2);
 f3->SetParameter(0,-1.5-6);
 f3->SetParameter(1,-0.122);
  f3->SetLineColor(kBlack);
  f3->SetLineWidth(2);
//   f3->Draw("same");
   
TF1 *f4 = new TF1("f2",funct22, 0.1,1.,2);
 f4->SetParameter(0,-1.5-16);
 f4->SetParameter(1,-0.2);
  f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
//  f4->Draw("same");
  
      
  TF1 *f3 = new TF1("f1",funct22, 0.1,1.,2);
 f3->SetParameter(0,-23);
 f3->SetParameter(1,-0.122);
  f3->SetLineColor(kBlack);
  f3->SetLineWidth(2);
//   f3->Draw("same");
   
TF1 *f4 = new TF1("f2",funct22, 0.1,1.,2);
 f4->SetParameter(0,-30);
 f4->SetParameter(1,-0.04);
  f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
//  f4->Draw("same"); 
  
  
TF1 *f1 = new TF1("f1",funct_new2, 0.3+0.04,1.8,2);
 f1->SetParameter(0,3.5);
 f1->SetParameter(1,0.04);
  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
  // f1->Draw("same");


  
TF1 *f1 = new TF1("f1",funct_new2, 0.3+0.07,1.8,2);
 f1->SetParameter(0,1);
 f1->SetParameter(1,0.07);
  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
 //  f1->Draw("same");

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


TF1 *f2 = new TF1("f2",funct_new3, 0.365+0.05,1.8,1);
 f2->SetParameter(0,6);
 f2->SetParameter(1,0.05);
  f2->SetLineColor(kBlack);
  f2->SetLineWidth(2);
  // f2->Draw("same");  
  
c->SaveAs("p_th_vs_p_sim_sector3.pdf");   
    
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
  
     s = 26.5087*x[0]*x[0]*x[0] -116.557*x[0]*x[0]+ 175.167*x[0]-61.7717+par[0];
   return s;
};

double funct22(double *x, double *par) {
   double s;
  
     s = (304.23*(x[0]-par[1])*(x[0]-par[1])*(x[0]-par[1]) -255.798*(x[0]-par[1])*(x[0]-par[1])+497.462*(x[0]-par[1]) +38.0385)*exp(-1.6*(x[0]-par[1])) +par[0];
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

double funct_new2(double *x, double *par) {
   double s;
  
     s = pow((x[0]-par[1]-0.294992),(0.0758186))*91.5643-48.2057 + par[0];
   return s;
};

double funct_new3(double *x, double *par) {
   double s;
  
     s = pow((x[0]-par[1] -0.36848),( 0.0864219))*70.4769  -34.9998+ par[0];
   return s;
};
