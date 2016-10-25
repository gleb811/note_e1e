void delta_T_corr() {

gStyle->SetOptStat(0);
gStyle ->SetOptFit(0);
gStyle->SetStatY(0.9);                
gStyle->SetStatX(0.795);
gStyle->SetStatW(0.4);                
gStyle->SetStatH(0.01);
gStyle->SetStatFontSize(0.01);
gStyle->SetStatFont(610);
gStyle->SetStatBorderSize(1.);
gStyle->SetStatStyle(0);
gROOT->ForceStyle();
gStyle ->SetOptLogz(1);
gStyle->SetTitleSize(0.07,"t");

gStyle->SetStatFontSize(0.15);
gStyle->SetTitleAlign(33); 
gStyle->SetTitleX(.65);
gStyle->SetTitleY(1.);


TFile *MyFile = new TFile("data_new_time_corr.root","READ");
TH2 *hist1;
TH1 *hist2;
ostringstream qqq;
TCanvas *c = new TCanvas ("b_vs_p","b_vs_p",0,0,500,500);


qqq.str("");
qqq << "s1_time_pip/time_pip_1_42";
MyFile->GetObject(qqq.str().c_str(),hist1); 

//hist1->SetMinimum((hist1->Integral())/100000.);
//hist1->Draw("colz");

qqq.str("");
qqq << "paddle 42";
hist1->SetTitle(qqq.str().c_str());

c->cd()->SetRightMargin(0.14);

hist1->GetYaxis()->SetLabelSize(0.05);
hist1->GetYaxis()->SetNdivisions(4);
hist1->GetXaxis()->SetRangeUser(0.,1.);
hist1->GetYaxis()->SetRangeUser(-4.,4.);
hist1->GetXaxis()->SetNdivisions(4);
hist1->GetXaxis()->SetLabelSize(0.05);
//hist->GetXaxis()->SetTitle("#theta, deg");
hist1->GetXaxis()->SetTitle("P (GeV)");
hist1->GetXaxis()->SetTitleSize(0.05);
hist1->GetYaxis()->SetTitle("#Delta T (ns)");
hist1->GetYaxis()->SetTitleSize(0.05);
hist1->GetYaxis()->SetTitleOffset(0.9);
hist1->GetXaxis()->SetTitleOffset(0.9);

hist1->GetZaxis()->SetLabelSize(0.05);
//hist1->UseCurrentStyle();


hist1->Draw("colz");





c->SaveAs("delta_t_time_corr.pdf");

}


