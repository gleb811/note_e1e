void data_sim () {
TFile *MyFile = new TFile("sim_data.root","READ");
MyFile->ls();
gStyle->SetOptLogz(1);
gStyle->SetPalette(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(1); 
gStyle->SetOptTitle(0);
gStyle->SetTitleBorderSize(0);
gStyle->SetCanvasColor(0);
  gStyle->SetTitleFillColor(0);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetStatColor(0);
  gStyle->SetHistLineWidth(0);


TCanvas *c1 = new TCanvas("data/Monte Carlo", "data/Monte Carlo", 1000, 800);
c1->SetFillColor(0);
c1->Divide(2,3);
int ii;
c1->SetBorderMode(0);
c1->SetFrameBorderMode(0);


THStack hs("hs","test stacked histograms"); // Define the histogram stack object

std::string histName;
std::stringstream out;
out << "h" << 100+2;
histName = out.str();
cout << histName << "\n";
TH1F *h1 = (TH1F*)MyFile->Get(histName.c_str());
c1->cd(1);
c1->cd(1)->SetBorderMode(0);
c1->cd(1)->SetTopMargin(0.01);
c1->cd(1)->SetBottomMargin(0.2);
c1->cd(1)->SetFillColor(0);
c1->cd(1)->SetFrameBorderMode(0);

std::stringstream out1;
out1 << "Sector " << ii;
h1->SetTitle(" ");
float a;
a = h1->Integral();
h1->Scale(1000/a);
h1->SetLineWidth(1);
h1->SetLineStyle(1);
;
h1->Draw("");
h1->GetXaxis()->SetTitle("W (GeV)");
h1->GetYaxis()->SetTitle("Counts");
h1->GetXaxis()->SetTitleSize(0.09);
h1->GetXaxis()->SetTitleOffset(1.1);
h1->GetYaxis()->SetTitleSize(0.09);
h1->GetYaxis()->SetTitleOffset(0.4);
h1->GetYaxis()->SetLabelSize(0.07);
h1->GetXaxis()->SetLabelSize(0.07);


TH1F *h2 = (TH1F*)MyFile->Get("h100"));
a = h2->Integral();
h2->Scale(1000/a);
h2->SetLineColor(1);
h2->SetLineWidth(1);
h2->SetLineStyle(3);
h2->Draw("same");


TH1F *h3 = (TH1F*)MyFile->Get("h101"));
a = h3->Integral();
h3->Scale(1000/a);
h3->SetLineColor(1);
h3->SetLineWidth(1);
h3->SetLineStyle(2);
h3->Draw("same");



TH1F *h1 = (TH1F*)MyFile->Get("h201"));
c1->cd(2);
c1->cd(2)->SetBorderMode(0);
c1->cd(2)->SetTopMargin(0.01);
c1->cd(2)->SetBottomMargin(0.2);
c1->cd(2)->SetFillColor(0);
c1->cd(2)->SetFrameBorderMode(0);

h1->SetTitle(" ");
h1->SetLineColor(1);
float a;
h1->SetLineWidth(1);
//h1->GetXaxis()->SetLimits(.3,.8);
a = h1->Integral();
h1->Scale(1000/a);
h1->SetLineStyle(2);
h1->Draw();
//h1->GetXaxis()->SetRange(.3,.8);
h1->GetXaxis()->SetTitleOffset(0.7);
h1->GetYaxis()->SetTitleSize(0.06);
h1->GetYaxis()->SetTitleOffset(0.5);
h1->GetXaxis()->SetTitle("Q^{2} (GeV^{2})");
h1->GetYaxis()->SetTitle("Counts");
h1->GetXaxis()->SetTitleSize(0.09);
h1->GetXaxis()->SetTitleOffset(1.1);
h1->GetYaxis()->SetTitleSize(0.09);
h1->GetYaxis()->SetTitleOffset(0.4);
h1->GetYaxis()->SetLabelSize(0.07);
h1->GetXaxis()->SetLabelSize(0.07);

TH1F *h2 = (TH1F*)MyFile->Get("h200"));
a = h2->Integral();
h2->Scale(1000/a);
h2->SetLineColor(1);
h2->SetLineWidth(1);
h2->SetLineStyle(3);
h2->Draw("same");


TH1F *h3 = (TH1F*)MyFile->Get("h202"));
a = h3->Integral();
h3->Scale(1000/a);
h3->SetLineColor(1);
h3->SetLineWidth(1);
h3->Draw("same");


TH1F *h1 = (TH1F*)MyFile->Get("h302"));
c1->cd(3);
c1->cd(3)->SetBorderMode(0);
c1->cd(3)->SetTopMargin(0.01);
c1->cd(3)->SetBottomMargin(0.2);
c1->cd(3)->SetFillColor(0);
c1->cd(3)->SetFrameBorderMode(0);


h1->SetTitle(" ");
float a;
h1->SetLineWidth(1);
//h1->GetXaxis()->SetLimits(.3,.8);
a = h1->Integral();
h1->Scale(1000/a);
h1->Draw("");
//h1->GetXaxis()->SetRange(.3,.8);
h1->GetXaxis()->SetTitle("M_{#pi^{+}#pi^{-}} (GeV)");
h1->GetXaxis()->SetTitleSize(0.06);
h1->GetXaxis()->SetTitleOffset(0.6);
h1->GetYaxis()->SetTitleSize(0.06);
h1->GetYaxis()->SetTitleOffset(0.7);
h1->GetYaxis()->SetTitle("Counts");
h1->GetXaxis()->SetTitleSize(0.09);
h1->GetXaxis()->SetTitleOffset(1.1);
h1->GetYaxis()->SetTitleSize(0.09);
h1->GetYaxis()->SetTitleOffset(0.4);
h1->GetYaxis()->SetLabelSize(0.07);
h1->GetXaxis()->SetLabelSize(0.07);


TH1F *h2 = (TH1F*)MyFile->Get("h300"));
a = h2->Integral();
h2->Scale(1000/a);
h2->SetLineColor(1);
h2->SetLineWidth(1);
h2->SetLineStyle(3);
h2->Draw("same");


TH1F *h3 = (TH1F*)MyFile->Get("h301"));
a = h3->Integral();
h3->Scale(1000/a);
h3->SetLineColor(1);
h3->SetLineWidth(1);
h3->SetLineStyle(2);
h3->Draw("same");




TH1F *h1 = (TH1F*)MyFile->Get("h402"));
c1->cd(4);
c1->cd(4)->SetBorderMode(0);
c1->cd(4)->SetTopMargin(0.01);
c1->cd(4)->SetBottomMargin(0.2);
c1->cd(4)->SetFillColor(0);
c1->cd(4)->SetFrameBorderMode(0);


h1->SetTitle(" ");
float a;
h1->SetLineWidth(1);
//h1->GetXaxis()->SetLimits(1.,3.);
a = h1->Integral();
h1->Scale(1000/a);
h1->Draw("");
//h1->GetXaxis()->SetRange(.3,.8);
h1->GetXaxis()->SetTitle("M_{#pi^{+}p} (GeV)");
h1->GetYaxis()->SetTitleSize(0.06);
h1->GetYaxis()->SetTitleOffset(0.7);
h1->GetXaxis()->SetTitleSize(0.06);
h1->GetXaxis()->SetTitleOffset(0.6);
h1->GetYaxis()->SetTitleSize(0.06);
h1->GetYaxis()->SetTitleOffset(0.7);
h1->GetYaxis()->SetTitle("Counts");
h1->GetXaxis()->SetTitleSize(0.09);
h1->GetXaxis()->SetTitleOffset(1.1);
h1->GetYaxis()->SetTitleSize(0.09);
h1->GetYaxis()->SetTitleOffset(0.4);
h1->GetYaxis()->SetLabelSize(0.07);
h1->GetXaxis()->SetLabelSize(0.07);

TH1F *h2 = (TH1F*)MyFile->Get("h400"));
a = h2->Integral();
h2->Scale(1000/a);
h2->SetLineColor(1);
h2->SetLineWidth(1);
h2->SetLineStyle(3);
h2->Draw("same");


TH1F *h3 = (TH1F*)MyFile->Get("h401"));
a = h3->Integral();
h3->Scale(1000/a);
h3->SetLineColor(1);
h3->SetLineWidth(1);
h3->SetLineStyle(2);
h3->Draw("same");

c1->cd(5);
c1->cd(5)->SetBorderMode(0);
c1->cd(5)->SetTopMargin(0.01);
c1->cd(5)->SetBottomMargin(0.2);
c1->cd(5)->SetFillColor(0);
c1->cd(5)->SetFrameBorderMode(0);

TH1F *h1 = (TH1F*)MyFile->Get("h502"));

a = h1->Integral();
h1->SetTitle(" ");
h1->Scale(1000/a);
h1->SetLineColor(1);
h1->SetLineWidth(1);
h1->Draw("");
h1->GetXaxis()->SetTitle("M_{#pi^{-}p} (GeV)");
h1->GetYaxis()->SetTitleSize(0.06);
h1->GetYaxis()->SetTitleOffset(0.7);
h1->GetXaxis()->SetTitleSize(0.06);
h1->GetXaxis()->SetTitleOffset(0.6);
h1->GetYaxis()->SetTitleSize(0.06);
h1->GetYaxis()->SetTitleOffset(0.7);
h1->GetYaxis()->SetTitle("Counts");
h1->GetXaxis()->SetTitleSize(0.09);
h1->GetXaxis()->SetTitleOffset(1.1);
h1->GetYaxis()->SetTitleSize(0.09);
h1->GetYaxis()->SetTitleOffset(0.4);
h1->GetYaxis()->SetLabelSize(0.07);
h1->GetXaxis()->SetLabelSize(0.07);




TH1F *h2 = (TH1F*)MyFile->Get("h500"));
a = h2->Integral();

h2->Scale(1000/a);
h2->SetLineColor(1);
h2->SetLineWidth(1);
h2->SetLineStyle(3);
h2->Draw("same");


TH1F *h3 = (TH1F*)MyFile->Get("h501"));
a = h3->Integral();
h3->Scale(1000/a);
h3->SetLineColor(1);
h3->SetLineWidth(1);
h3->SetLineStyle(2);
h3->Draw("same");
















c1->cd(6);
c1->cd(6)->SetBorderMode(0);
c1->cd(6)->SetTopMargin(0.01);
c1->cd(6)->SetBottomMargin(0.2);
c1->cd(6)->SetFillColor(0);
c1->cd(6)->SetFrameBorderMode(0);

TH1F *h1 = (TH1F*)MyFile->Get("h602"));
a = h1->Integral();
h1->Scale(1000/a);
h1->SetTitle(" ");
h1->SetLineColor(1);
h1->SetLineWidth(1);
h1->Draw("");
h1->GetXaxis()->SetTitle("Z_{electron} (cm)");
h1->GetYaxis()->SetTitleSize(0.06);
h1->GetYaxis()->SetTitleOffset(0.7);
h1->GetXaxis()->SetTitleSize(0.06);
h1->GetXaxis()->SetTitleOffset(0.6);
h1->GetYaxis()->SetTitleSize(0.06);
h1->GetYaxis()->SetTitleOffset(0.7);
h1->GetYaxis()->SetTitle("Counts");
h1->GetXaxis()->SetTitleSize(0.09);
h1->GetXaxis()->SetTitleOffset(1.1);
h1->GetYaxis()->SetTitleSize(0.09);
h1->GetYaxis()->SetTitleOffset(0.4);
h1->GetYaxis()->SetLabelSize(0.07);
h1->GetXaxis()->SetLabelSize(0.07);




TH1F *h2 = (TH1F*)MyFile->Get("h600"));
a = h2->Integral();
h2->Scale(1000/a);
h2->SetLineColor(1);
h2->SetLineWidth(1);
h2->SetLineStyle(3);
h2->Draw("same");


TH1F *h3 = (TH1F*)MyFile->Get("h601"));
a = h3->Integral();
h3->Scale(1000/a);
h3->SetLineColor(1);
h3->SetLineWidth(1);
h3->SetLineStyle(2);
h3->Draw("same");




}
