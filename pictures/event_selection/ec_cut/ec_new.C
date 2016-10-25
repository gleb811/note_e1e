Int_t www;

void ec_new() {
TFile *MyFile = new TFile("ec_data.root","READ");
int ii;
std::ostringstream title_2d;

for (ii=1; ii<7; ii++)
{
std::string histName;
std::stringstream out;
out << "h" << ii*100+ii*10+ii;
histName = out.str();
cout << histName << "\n";
TH2F *h1 = (TH2F*)MyFile->Get(histName.c_str());
title_2d.str("");
title_2d << "sectror " << ii;
TH2F *h2;
//h2 = eprst(h1);
www = qqq(3);
};
};

Int_t qqq(Int_t qqq1) {

return qqq1;
};

TH2F *eprst(TH2F *h) {
//  TH2F *h2 = (TH2F*)h->Clone();
/*  Int_t nby = h2->GetYaxis()->GetNbins();
  for (Int_t bx = 1; bx < h2->GetXaxis()->GetNbins(); bx++) {
    h2->GetXaxis()->SetRange(bx,bx);
    TH1 *h1 = h2->ProjectionY();
    Double_t max = h1->GetMaximum();
    for (Int_t by = 1; by < nby; by++) {
      Double_t bc = h2->GetBinContent(bx,by);
      if (bc > 0) {
        Int_t global_bin = h2->GetBin(bx,by);
        h2->SetBinContent(global_bin,bc/max);
      };
    };
  };*/
//  h2->GetXaxis()->SetRange(0,h2->GetXaxis()->GetNbins()+1);
  return h;
};
