void pim_fid_1dim() {
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

TFile *MyFile = new TFile("../../event_selection/b_vs_p/test3.root","READ");

ostringstream qqq;
ostringstream qqq1;
ostringstream qqq2;
ostringstream qqq3;
ostringstream qqq4;
ostringstream qqq5;
ostringstream qqq6;
ostringstream qqq7;
TH2 *ph;
TH2 *ph_fid;
TH1D *h_odn[20];
TH1D *h_odn_fid[16];
Double_t p[17];
TCanvas *c_arr[17];
double theta, th_min, par1, par2, fida,fidb;
for (j=2; j<3; j++){
qqq2.str("");
qqq2 << "c_arr" << j+1;
c_arr[j] = new TCanvas (qqq2.str().c_str(),qqq2.str().c_str(),0,0,600,600);
c_arr[j]->Divide(5,4,0,0);//0.01,0.02

qqq4 << "sector1_pim_fid/ph_vs_th_pim[1][" << j+1 << "]";
cout << qqq4.str().c_str() <<"\n";
MyFile->GetObject(qqq4.str().c_str(),ph);
qqq4.str("");

p[j] = 0.2*(j+1) - 0.1;
th_min=(11.09+8./(0.472*p[j]+0.117));
par1=0.705+1.1*p[j];
par2=-63.2-33.3*p[j];

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

qqq3.str("");
qqq3 <<int(th_min)+i+1 << "< #theta < " << int(th_min)+i+2 << " deg";

h_odn[i]->SetTitle(qqq3.str().c_str());

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
theta =int(th_min)+i+1.5 ;
//theta = 0.3*(60+6.666666*i)+1; 
cout << "theta=" << theta << "\n";
//cout << "p=" << p[j] << "\n";
//cout << "par1" << par1 << "\n";
//cout << "th_min" << th_min << "\n";
cout << "fida" << fida << "\n";
fida = 30.5*pow((sin((theta-th_min)*0.01745)),(par1+par2/theta+1530./theta/theta))-1;
fidb = -30.5*pow((sin((theta-th_min)*0.01745)),(par1+par2/theta+1530./theta/theta))+1;

TLine *line_l = new TLine(fida,0,fida,h_odn[i]->GetMaximum());
line_l->SetLineColor(kRed);
line_l->SetLineWidth(2);
line_l->Draw("same");

TLine *line_r = new TLine(fidb,0,fidb,h_odn[i]->GetMaximum());
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
qqq6 << 200*j << " < P_{#pi^{-}}< " << 200*(j+1) << " MeV"<< "  sector 6" ;
 tex.SetTextSize(0.029);
// tex.DrawLatex(0.32,0.97,qqq6.str().c_str());
 
qqq7 << "pim_fid_1dim_s1_" << j+1 << ".pdf"; 
c_arr[j]->SaveAs(qqq7.str().c_str());
qqq7.str("");

/*qqq7 << "pictures/pim_fid/pim_fid_1dim_s6_" << j+1 << ".eps"; 
c_arr[j]->SaveAs(qqq7.str().c_str());
qqq7.str("");
*/
};
}
