
void ratio_qqq() {

TFile *MyFile = new TFile("new_ratio.root","READ");
MyFile->ls();

TCanvas *c1 = new TCanvas("rose512", "DATA", 750, 500);

gStyle->SetOptLogz(0);
 Int_t palette[1];
   palette[0] = 1;
/*   palette[1] = 20;
   palette[2] = 23;
   palette[3] = 30;
   palette[4] = 32;
   */
//   gStyle->SetPalette(5,palette);
gStyle->SetPalette(1,palette);
//gStyle->SetPalette(0);
gStyle->SetOptStat(0);
gStyle->SetOptFit(1);
gStyle->SetTitleSize(0.09,"t");
c1->Divide(2,3);

std::stringstream out;
std::ostringstream title_2d;


for (Int_t ii=1; ii<7; ii++)
{
out.str("");
out << "h30" << ii;

TH2F *h1 = (TH2F*)MyFile->Get(out.str().c_str());

h1->SetMinimum(0.8);
//h1->SetMaximum(0.99);

c1->cd(ii);
c1->cd(ii)->SetBottomMargin(0.14);
c1->cd(ii)->SetTopMargin(0.1);
title_2d.str("");
title_2d << "sectror " << ii;
h1->SetTitle(title_2d.str().c_str());
//h1->SetTitleSize(0.5);
h1->GetYaxis()->SetTitle("#varphi_{cc} (deg)");
h1->GetYaxis()->SetTitleSize(0.08); 
h1->GetYaxis()->SetTitleOffset(0.65);
h1->GetYaxis()->SetLabelSize(0.07);
h1->GetXaxis()->SetTitleSize(0.08); 
h1->GetXaxis()->SetLabelSize(0.07); 
h1->GetZaxis()->SetLabelSize(0.07);
h1->GetXaxis()->SetTitleOffset(0.8);
h1->GetXaxis()->SetTitle("#theta_{cc} (deg)"); 
h1->GetXaxis()->SetRange(50,180);
h1->Draw("col");
};


}
