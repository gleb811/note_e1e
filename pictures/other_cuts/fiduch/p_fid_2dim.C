double ap(double *x, double *par) {
   double s;
   s =  24.*(1-exp(-1.*0.08*(x[0]-9.)));
       return s;
};

double bp(double *x, double *par) {
   double w; 
   w = -1.*25.*(1-exp(-1.*0.1*(x[0]-10.)));
          return w;
};





void p_fid_2dim () {

gStyle ->SetOptLogz(1);
gStyle->SetOptStat("e");
gStyle->SetTitleSize(0.1,"t");
gStyle->SetStatY(1.);                
gStyle->SetStatX(0.9);                
gStyle->SetStatW(0.26);                
gStyle->SetStatH(0.11);
gStyle->SetStatFontSize(0.15);
TCanvas *c_arr[5];
TH2 *hist;
Short_t i, j;
ostringstream qqq;
ostringstream qqq1;
ostringstream qqq2;
ostringstream qqq3;
ostringstream qqq7;

TFile *MyFile = new TFile("test_proton_fiduch.root","READ");

for (i=2; i<3; i++) {
qqq1.str("");
qqq1 << "c_arr" << i+1;
c_arr[i] = new TCanvas (qqq1.str().c_str(),qqq1.str().c_str(),0,0,600,400);
c_arr[i]->Divide(2,3);//0.048,0.

for (j=0; j<6; j++) {
c_arr[i]->cd(j+1);
c_arr[i]->cd(j+1)->SetBottomMargin(0.2);
c_arr[i]->cd(j+1)->SetTopMargin(0.15);
c_arr[i]->cd(j+1)->SetLeftMargin(0.1);
c_arr[i]->cd(j+1)->SetRightMargin(0.14);
//c->cd(j+1);
qqq.str("");
//qqq << "sector1_p_fid/ph_vs_th_p_1_w";
qqq << "sector" << j+1 << "_p_fid/ph_th_p_" << j+1 << "["  << i << "]";
cout << qqq.str().c_str() << "\n";
MyFile->GetObject(qqq.str().c_str(),hist); 
gStyle->SetTitleFont(32);
hist->SetMinimum(1.);
hist->SetMaximum(30.);
hist->Draw("colz");
hist->GetYaxis()->SetLabelSize(0.1);
hist->GetZaxis()->SetLabelSize(0.1);
hist->GetYaxis()->SetNdivisions(4);
hist->GetXaxis()->SetLabelSize(0.1);
hist->GetXaxis()->SetTitle("#theta (deg)");
hist->GetYaxis()->SetTitle("#varphi (deg)");
hist->GetYaxis()->SetTitleOffset(0.6);
hist->GetZaxis()->SetLabelOffset(-0.005);
hist->GetXaxis()->SetTitleSize(0.09);
hist->GetYaxis()->SetTitleSize(0.09);
qqq3.str("");
qqq3 <<"sector_" << j+1;
//qqq3 << 0.3*(60+6.666666*i)<< "< theta < " << 0.3*(60+6.66666*(i+1));
hist->SetTitle(qqq3.str().c_str());
TF1 *f1 = new TF1("f1",ap,9.,100.,1);
 //f1->SetParameter(0,p);
//f1->SetParameter(1,1.);
  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
   f1->Draw("same");
   
TF1 *f2 = new TF1("f2",bp,9.,100.,1);
 //f1->SetParameter(0,p);
//f1->SetParameter(1,1.);
  f2->SetLineColor(kBlack);
  f2->SetLineWidth(2);
   f2->Draw("same");   
   
   
   
 }; 
  c_arr[i]->cd();
newpad = new TPad("newpad","a transparent pad",0.,0.,1.,1.);
 newpad->SetFillStyle(4000);
 newpad->Draw();
  newpad->cd();
 TLatex tex;
 qqq2.str("");
qqq2 << 200+200*i << " < P_{p}< " << 200+200*(i+1) << " MeV";
 tex.SetTextSize(0.04);
// tex.DrawLatex(0.45,0.96,qqq2.str().c_str());
 
 qqq7 << "p_fid_2dim_" << i << ".pdf"; 
c_arr[i]->SaveAs(qqq7.str().c_str());
qqq7.str("");

/*
qqq7 << "p_fid_2dim_" << i << ".eps"; 
c_arr[i]->SaveAs(qqq7.str().c_str());
qqq7.str("");
*/
};
};

