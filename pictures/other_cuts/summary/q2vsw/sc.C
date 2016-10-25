void sc () {
gROOT->LoadMacro("DynamicExec.C");
TFile *MyFile = new TFile("sc.root","READ");
MyFile->ls();
gStyle->SetOptLogz(1);
gStyle->SetPalette(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(1); 
TCanvas *c1 = new TCanvas("Y vs X", "Y vs X", 1000, 800);
c1->Divide(2,3);
int ii;
for (ii=1; ii<7; ii++)
{
std::string histName;
std::stringstream out;
out << "h" << ii*100+1;
histName = out.str();
cout << histName << "\n";
TH2F *h1 = (TH2F*)MyFile->Get(histName.c_str());
c1->cd(ii);
std::stringstream out1;
out1 << "Sector " << ii;
h1->SetTitle(out1.str().c_str());
h1->Draw("colz");
h1->GetXaxis()->SetTitle("X");
h1->GetYaxis()->SetTitle("Y");
h1->GetXaxis()->SetTitleSize(0.06);
h1->GetXaxis()->SetTitleOffset(0.7);
h1->GetYaxis()->SetTitleSize(0.06);
h1->GetYaxis()->SetTitleOffset(0.7);

};















TCanvas *c2 = new TCanvas("Y vs Z", "Y vs Z", 1000, 800);
c2->Divide(2,3);
int ii;
for (ii=1; ii<7; ii++)
{
std::string histName;
std::stringstream out;
out << "h" << ii*100+10;
histName = out.str();
cout << histName << "\n";
TH2F *h1 = (TH2F*)MyFile->Get(histName.c_str());
c2->cd(ii);
std::stringstream out1;
out1 << "Sector " << ii;
h1->SetTitle(out1.str().c_str());
h1->Draw("colz");
h1->GetXaxis()->SetTitle("Z");
h1->GetYaxis()->SetTitle("Y");
h1->GetXaxis()->SetTitleSize(0.06);
h1->GetXaxis()->SetTitleOffset(0.7);
h1->GetYaxis()->SetTitleSize(0.06);
h1->GetYaxis()->SetTitleOffset(0.7);

};














TCanvas *c3 = new TCanvas("X vs Z", "X vs Z", 1000, 800);
c3->Divide(2,3);
int ii;
for (ii=1; ii<7; ii++)
{
std::string histName;
std::stringstream out;
out << "h" << ii*100+11;
histName = out.str();
cout << histName << "\n";
TH2F *h1 = (TH2F*)MyFile->Get(histName.c_str());
c3->cd(ii);
std::stringstream out1;
out1 << "Sector " << ii;
h1->SetTitle(out1.str().c_str());
h1->Draw("colz");
h1->GetXaxis()->SetTitle("Z");
h1->GetYaxis()->SetTitle("X");
h1->GetXaxis()->SetTitleSize(0.06);
h1->GetXaxis()->SetTitleOffset(0.7);
h1->GetYaxis()->SetTitleSize(0.06);
h1->GetYaxis()->SetTitleOffset(0.7);

};




}
