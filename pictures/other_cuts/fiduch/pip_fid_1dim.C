void pip_fid_1dim () {
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
TFile *MyFile = new TFile("../../event_selection/b_vs_p/test3.root","READ");

TCanvas *c_arr[6];
TH1D *h_odn[20];
TH2 *ph;
Short_t i;
Short_t j;
double theta, ap, bp;
ostringstream qqq;
ostringstream qqq1;
ostringstream qqq2;
ostringstream qqq3;
ostringstream qqq4;
ostringstream qqq6;
ostringstream qqq7;






for (j=2; j<3; j++){
qqq.str("");
qqq << "c_arr" << j+1;
c_arr[j] = new TCanvas (qqq.str().c_str(),qqq.str().c_str(),0,0,600,600);
c_arr[j]->Divide(5,4,0,0);//0.01,0.02
qqq1 << "sector1_pip_fid/ph_th_pip_1[" << j << "]";
cout << qqq1.str().c_str() <<"\n";
MyFile->GetObject(qqq1.str().c_str(),ph);
qqq1.str("");
for (i=0; i<20; i++){
c_arr[j]->cd(i+1);
c_arr[j]->cd(i+1)->SetBottomMargin(0.2);
c_arr[j]->cd(i+1)->SetTopMargin(0.18);
c_arr[j]->cd(i+1)->SetLeftMargin(0.3);
c_arr[j]->cd(i+1)->SetRightMargin(0.01);
qqq2.str("");
qqq2 << "hist" << "n" << i << "q" << j+1;
h_odn[i] = ph->ProjectionY(qqq2.str().c_str(),20+8*i, 20+8*(i+1));
qqq4.str("");
qqq4 << 10+4*i << " < #theta < " << 10+4*(i+1) << ", deg";
//qqq3 << 0.3*(60+6.666666*i)<< "< theta < " << 0.3*(60+6.66666*(i+1));
h_odn[i]->SetTitle(qqq4.str().c_str());
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
theta =12+4*i;
ap =  24.*(1-exp(-1.*0.08*(theta-9.)));
 bp = -1.*25.*(1-exp(-1.*0.1*(theta-10.)));
 TLine *line_l = new TLine(ap,0,ap,h_odn[i]->GetMaximum());
line_l->SetLineColor(kRed);
line_l->SetLineWidth(2);
line_l->Draw("same");

TLine *line_r = new TLine(bp,0,bp,h_odn[i]->GetMaximum());
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
qqq6 << 200*j << " < P_{#pi^{+}}< " << 200*(j+1) << " MeV" << "  sector 1" ;
 tex.SetTextSize(0.029);
// tex.DrawLatex(0.3,0.97,qqq6.str().c_str());
 
// qqq7 << "pictures/pip_fid/pip_fid_1dim_sector1_" << j << ".png"; 
//c_arr[j]->SaveAs(qqq7.str().c_str());
//qqq7.str("");

qqq7 << "pip_fid_1dim_sector1_" << j << ".pdf"; 
c_arr[j]->SaveAs(qqq7.str().c_str());
qqq7.str("");
};
};
