void pim_fid_2dim() {

gStyle ->SetOptLogz(1);
gStyle->SetOptStat("e");
gStyle->SetTitleSize(0.1,"t");
gStyle->SetStatY(1.);                
gStyle->SetStatX(0.9);                
gStyle->SetStatW(0.26);                
gStyle->SetStatH(0.11);
gStyle->SetStatFontSize(0.15);
//TFile *MyFile = new TFile("../../event_selection/b_vs_p/test3.root","READ");
TFile *MyFile = new TFile("test_proton_fiduch.root","READ");
//TCanvas *c1 = new TCanvas("Y vs X", "Y vs X", 1000, 800);
//c1->Divide(2,3);

int ii, j;
TCanvas *c_arr[10];
ostringstream qqq2;
ostringstream qqq3;
ostringstream qqq4;
double p;

for (j=2; j<3; j++){
qqq2.str("");
qqq2 << "c_arr" << j+1;
c_arr[j] = new TCanvas (qqq2.str().c_str(),qqq2.str().c_str(),0,0,600,400);
c_arr[j]->Divide(2,3,0,0);//0.048,0.
  

 
 for (ii=1; ii<7; ii++) {
 c_arr[j]->cd(ii);
c_arr[j]->cd(ii)->SetBottomMargin(0.2);
c_arr[j]->cd(ii)->SetTopMargin(0.15);
c_arr[j]->cd(ii)->SetLeftMargin(0.1);
c_arr[j]->cd(ii)->SetRightMargin(0.14);

std::string histName;
std::stringstream out;
out << "sector" << ii << "_pim_fid" << "/ph_vs_th_pim[" << ii << "][" << j+1 << "]";

histName = out.str();
cout << histName << "\n";
TH2F *h1 = (TH2F*)MyFile->Get(histName.c_str());
gStyle->SetTitleFont(32);
h1->SetMinimum(1.);
h1->SetMaximum(300.);
h1->Draw("colz"); 
h1->GetYaxis()->SetLabelSize(0.1);
h1->GetZaxis()->SetLabelSize(0.1);
h1->GetYaxis()->SetNdivisions(4);
h1->GetXaxis()->SetLabelSize(0.1);
h1->GetXaxis()->SetTitle("#theta (deg)");
h1->GetYaxis()->SetTitle("#varphi (deg)");
h1->GetYaxis()->SetTitleOffset(0.6);
h1->GetZaxis()->SetLabelOffset(-0.005);
h1->GetXaxis()->SetTitleSize(0.09);
h1->GetYaxis()->SetTitleSize(0.09);
qqq3.str("");
qqq3 << "sector " << ii ;
h1->SetTitle(qqq3.str().c_str());
p = 0.2*(j+1) - 0.1;
th_min=(10.6+8./(0.472*p+0.117));
 TF1 *f1 = new TF1("f1",fida,th_min,120.,2);
 f1->SetParameter(0,p);
// f1->SetParameter(1,1.);
  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
   f1->Draw("same");
   
 TF1 *f2 = new TF1("f2",fidb,th_min,120.,2);
 f2->SetParameter(0,p);
// f2->SetParameter(1,-1.); 
 f2->SetLineColor(kBlack);
 f2->SetLineWidth(2);

  f2->Draw("same");
      
TLine *line_l = new TLine(th_min,-30,th_min,30);
line_l->SetLineColor(kBlack);
line_l->SetLineWidth(2);
line_l->Draw("same");

TLine *line_r = new TLine(50,-30,50,30);
line_r->SetLineColor(kBlack);
line_r->SetLineWidth(2);
//line_r->Draw("same");
 
};
c_arr[j]->cd();
newpad = new TPad("newpad","a transparent pad",0.,0.,1.,1.);
 newpad->SetFillStyle(4000);
 newpad->Draw();
  newpad->cd();
 TLatex tex;
 qqq4.str("");
qqq4 << 200*j << " < P_{#pi^{-}}< " << 200*(j+1) << " MeV";
 tex.SetTextSize(0.03);
// tex.DrawLatex(0.4,0.95,qqq4.str().c_str());
 qqq4.str("");
qqq4 << "pim_fid_2dim_" << j << ".pdf"; 
c_arr[j]->SaveAs(qqq4.str().c_str());
qqq4.str("");

}; 
};

double fida(double *x, double *par) {
   double s;
   double th_min;
     th_min=(11.+8./(0.472*par[0]+0.117));
     double par1,par2;
      par1=0.705+1.1*par[0];
     par2=-63.2-33.3*par[0]; 
     s = 30.5*pow((sin((x[0]-th_min)*0.01745)),(par1+par2/x[0]+1530./x[0]/x[0]))-1.;
     if ((!(s>0))&&(!(s<0)))s=0;
   return s;
}

double fidb(double *x, double *par) {
   double s;
   double th_min;
     th_min=(11.+8./(0.472*par[0]+0.117));
     double par1,par2;
      par1=0.705+1.1*par[0];
     par2=-63.2-33.3*par[0]; 
     s = -30.5*pow((sin((x[0]-th_min)*0.01745)),(par1+par2/x[0]+1530./x[0]/x[0]))+1.;
     if ((!(s>0))&&(!(s<0)))s=0;
   return s;
}
