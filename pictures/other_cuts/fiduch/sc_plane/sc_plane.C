void sc_plane() {
gStyle ->SetOptLogz(1);

TFile *MyFile = new TFile("test_proton_fiduch.root","READ");
TH2F *h;

h = (TH2F*)MyFile->Get("sc_sector5");
TCanvas *c = new TCanvas ("c","c",0,0,500,500);
c->cd();
h->SetMinimum(100.);
h->SetMaximum(1000.);
h->Draw("colz");
}
