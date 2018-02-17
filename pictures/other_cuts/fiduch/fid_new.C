TH1D*  Smooth_fun(TH1D *h, Double_t bin_num) {
Int_t i,j,a;
a = h->GetNbinsX();



TH1D* h1 = new TH1D("qqq","qqq",a,h->GetBinLowEdge(1),h->GetBinLowEdge(a)+	h->GetBinWidth(a));
Double_t y,width;
width=h->GetBinWidth(a);


for (i=1; i<=a-bin_num; i++)
{
y=0;
for (j=0; j<=bin_num-1; j++)
{
y=y+h->GetBinContent(i+j)/bin_num;

};
h1->Fill(h->GetBinLowEdge(1)+(i-1)*width+width*bin_num/2.,y);
 
};
return h1;
}; 

Double_t GetTDCleftcut(TH1D *h, Double_t par) {
   Int_t i,j,a,ib;
   a = h->GetNbinsX();
   Double_t b,bmax,ymax;
   ymax = h->GetMaximumBin();
   ymax = h->GetBinContent(ymax);
   TH1D *hmin = new TH1D("min","min",h->GetMaximumBin(),h->GetBinLowEdge(0),h->GetBinLowEdge(h->GetMaximumBin()));

   for (i=0; i<=h->GetMaximumBin(); i++)
{
hmin->Fill(h->GetBinCenter(i), Double_t(fabs(h->GetBinContent(i)-ymax/par)));

}

    b=hmin->GetBinCenter(hmin->GetMinimumBin());
//    bmax=h->GetBinCenter(h->GetMaximumBin());
    hmin->Delete();
//    hmin->Draw();
//    pause();
    return b;
 };    


Double_t GetTDCrightcut(TH1D *h) {
   Int_t i,j,a,ib;
   a = h->GetNbinsX();
   Double_t b,bmax,ymax;
   ymax = h->GetMaximumBin();
   ymax = h->GetBinContent(ymax);
   TH1D *hmin = new TH1D("min","min",a-h->GetMaximumBin(),h->GetBinLowEdge(h->GetMaximumBin()),h->GetBinLowEdge(a));

   for (i=h->GetMaximumBin(); i<=a; i++)
{
hmin->Fill(h->GetBinCenter(i),Double_t(fabs(h->GetBinContent(i)-ymax/2.)));

}

    b=hmin->GetBinCenter(hmin->GetMinimumBin());
//    bmax=h->GetBinCenter(h->GetMaximumBin());
    hmin->Delete();
//    hmin->Draw();
//    pause();
    return b;
 };   



void fid_new() {
gStyle->SetCanvasBorderSize(50);
gStyle->SetCanvasBorderMode(2);
gStyle->SetOptStat("e");
gStyle->SetOptFit(0);
gStyle->SetTitleSize(0.12,"t");
gStyle->SetTitleAlign(33); 
gStyle->SetTitleY(1.02);
gStyle->SetTitleX(1.);
gStyle->SetStatY(0.9);                
gStyle->SetStatX(0.95);                
gStyle->SetStatW(0.65);                
gStyle->SetStatH(0.1);
gStyle->SetStatFontSize(0.07);
//gDirectory->cd("sector1");
Short_t i;
Short_t j;
ostringstream qqq;
ostringstream qqq1;
ostringstream qqq2;
ostringstream qqq3;
ostringstream qqq4;
ostringstream qqq5;
ostringstream qqq6;
ostringstream qqq7;

TFile *MyFile = new TFile("../../event_selection/b_vs_p/test3.root","READ");

TH2 *ph;
TH2 *ph_fid;
TH1D *h_odn[20];
TH1D *h_odn_fid[16];
Double_t p[17];
TCanvas *c_arr[17];
double theta, th_min, par1, par2, fida,fidb;
for (j=1; j<2; j++){
qqq2.str("");
qqq2 << "c_arr" << j+1;
c_arr[j] = new TCanvas (qqq2.str().c_str(),qqq2.str().c_str(),0,0,600,600);
c_arr[j]->Divide(5,4);//0.01,0.02

qqq4 << "sector6/ph_vs_th_6pe[" << j << "]";
cout << qqq4.str().c_str() <<"\n";
MyFile->GetObject(qqq4.str().c_str(),ph);
qqq4.str("");

qqq5 << "sector6/ph_vs_th_6pe_fid[" << j << "]";
cout << qqq5.str().c_str() <<"\n";
gDirectory->GetObject(qqq5.str().c_str(),ph_fid);
qqq5.str("");

p[j] = 0.4+0.08*j + 0.04;
th_min=9.5+17./(p[j]+0.2);
par1=0.85+1.1*p[j];
par2=-62.8-30.*p[j];

//cout << "p=" << p[j] << "/n";
for (i=0; i<20; i++){
c_arr[j]->cd(i+1);
c_arr[j]->cd(i+1)->SetBottomMargin(0.2);
c_arr[j]->cd(i+1)->SetTopMargin(0.18);
c_arr[j]->cd(i+1)->SetLeftMargin(0.3);
c_arr[j]->cd(i+1)->SetRightMargin(0.01);
qqq.str("");
qqq << "hist" << "n" << i << "q" << j+1;
//qqq1.str("");
//qqq1 << "hist_fid" << i << j+1;
h_odn[i] = ph->ProjectionY(qqq.str().c_str(),(int(th_min)+i+1)/0.3, (int(th_min)+i+2)/0.3);
cout << ph->GetNbinsX() << "\n";
//60+6.666666*i,60+6.66666*(i+1)
qqq.str("");
//h_odn_fid[i] = ph_fid->ProjectionY(qqq1.str().c_str(),60+6.666666*i,60+6.66666*(i+1));
qqq3.str("");
qqq3 <<int(th_min)+i+1 << "< #theta < " << int(th_min)+i+2 << " (deg)";
//qqq3 << 0.3*(60+6.666666*i)<< "< theta < " << 0.3*(60+6.66666*(i+1));
h_odn[i]->SetTitle(qqq3.str().c_str());
//h_odn[i][j]->SetTitleSize(0.2);
h_odn[i]->SetTitle(qqq3.str().c_str());
h_odn[i]->GetXaxis()->SetLabelSize(0.09);
h_odn[i]->GetXaxis()->SetNdivisions(5);
h_odn[i]->GetYaxis()->SetLabelSize(0.09);
h_odn[i]->GetYaxis()->SetNdivisions(3);
h_odn[i]->GetXaxis()->SetTitle("#varphi (deg)");
h_odn[i]->GetXaxis()->SetTitleSize(0.11);
h_odn[i]->GetXaxis()->SetTitleOffset(0.7);
h_odn[i]->GetYaxis()->SetTitleOffset(1.15);
h_odn[i]->GetYaxis()->SetTitle("counts");
h_odn[i]->GetYaxis()->SetTitleSize(0.11);

h_odn[i]->Draw();
h_odn[i] = Smooth_fun(h_odn[i],21);
//h_odn[i]->Draw();
//h_odn_fid[i]->SetLineColor(2);
//h_odn_fid[i]->Draw("same");
theta =int(th_min)+i+1.5 ;
//theta = 0.3*(60+6.666666*i)+1; 
cout << "theta=" << theta << "\n";
//cout << "p=" << p[j] << "\n";
//cout << "par1" << par1 << "\n";
//cout << "th_min" << th_min << "\n";
cout << "fida" << fida << "\n";
fida = 37.3*pow((sin((theta-th_min)*0.01745)),(par1+par2/theta+1525./theta/theta))-1.6;
fidb = -37.3*pow((sin((theta-th_min)*0.01745)),(par1+par2/theta+1525./theta/theta))+1.6;

TLine *line_l = new TLine(fida,0,fida,h_odn[i]->GetMaximum());
line_l->SetLineColor(kRed);
line_l->SetLineWidth(2);
line_l->Draw("same");

TLine *line_r = new TLine(3.*GetTDCleftcut(h_odn[i],2.)-2.*GetTDCleftcut(h_odn[i],4.),0,3.*GetTDCleftcut(h_odn[i],2.)-2.*GetTDCleftcut(h_odn[i],4.),h_odn[i]->GetMaximum());
line_r->SetLineColor(kRed);
line_r->SetLineWidth(2);
line_r->Draw("same");
};
c_arr[j]->cd();
newpad = new TPad("newpad","a transparent pad",0.,0.,1.,1.);
 newpad->SetFillStyle(4000);
 newpad->Draw();
  newpad->cd();
 TLatex tex;
 qqq6.str("");
qqq6 << 400+80*j << " < P_{el}< " << 400+80*(j+1) << " MeV" << "  sector 6" ;
 tex.SetTextSize(0.029);
// tex.DrawLatex(0.32,0.97,qqq6.str().c_str());
 
qqq7 << "el_fid_1dim_s6_" << j+1 << ".pdf"; 
c_arr[j]->SaveAs(qqq7.str().c_str());
qqq7.str("");

};
}

