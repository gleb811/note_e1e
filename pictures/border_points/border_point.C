gROOT->Reset();
TH1D *m_pip_p,*m_pip_pim,*m_pim_p;
TH1D *theta_p,*theta_pim,*theta_pip;
TH1D *alpha_p,*alpha_pim,*alpha_pip;


TH1D *m_pip_p_bin_corr,*m_pip_pim_bin_corr,*m_pim_p_bin_corr;
TH1D *theta_p_bin_corr,*theta_pim_bin_corr,*theta_pip_bin_corr;
TH1D *alpha_p_bin_corr,*alpha_pim_bin_corr,*alpha_pip_bin_corr;

TFile *file_out = new TFile("out_cr_sec_all_top_final_border_point.root","RECREATE");

TH2D *q2vsw = new TH2D("q2vsw","q2vsw",22,1.3,1.85,12,0.4,1.);
TH2D *q2vsw_q2_corr = new TH2D("q2vsw_q2_corr","q2vsw_q2_corr",22,1.3,1.85,12,0.4,1.);

TCanvas *c = new TCanvas("c","c",900,300);
c->Divide(3,1);

TH1D *h_q2;

TH1D *h_w;

TH1D *tmp;

Double_t err;

Float_t Q2_bin,W_bin[30];

TLegend *leg;

TSpline5 *spline;
ostringstream qqq;

TF1 *f_q2 = new TF1("f_q2","pol2",0.4,1.);
 
void border_point() {
#include <TH2.h>
#include <TH1.h>
#include <TH3.h>
#include <THnSparse.h>
gStyle->SetTitleSize(0.07,"t");
gStyle->SetTitleY(1.01);
gStyle->SetOptStat(0);
gStyle->SetErrorX(0);
gErrorIgnoreLevel = kError;
gStyle->SetStatY(0.88); 







//Define input files

TFile *file_cr_sec_pim = new TFile("out_cr_sec_all_top_final_bin_corr.root","READ");


 for (Int_t qq2=10; qq2<11;qq2++) {
 Q2_bin = 0.425 + 0.05*qq2;


for (Int_t i=10; i<11;i++) {
// for (Int_t i=get_min_w(Q2_bin); i<get_max_w(Q2_bin);i++) {
 W_bin[i] = 1.3125+0.025*i; 

read_data_rec(file_cr_sec_pim,i);
c->Divide(3,1);



c->cd(1);
m_pip_p->Draw();
gPad->Update();
TLine *line1 = new TLine(0.938272+0.13957,0.,0.938272+0.13957,gPad->GetUymax());
line1->SetLineWidth(3);
line1->Draw();
TLine *line2 = new TLine(W_bin[i]-0.13957,0.,W_bin[i]-0.13957,gPad->GetUymax());
line2->SetLineWidth(3);
line2->Draw();


c->cd(2);
m_pip_pim->Draw();
gPad->Update();
TLine *line3 = new TLine(2.*0.13957,0.,2.*0.13957,gPad->GetUymax());
line3->SetLineWidth(3);
line3->Draw();
TLine *line4 = new TLine(W_bin[i]-0.938272,0.,W_bin[i]-0.938272,gPad->GetUymax());
line4->SetLineWidth(3);
line4->Draw();



c->cd(3);
m_pim_p->Draw();
gPad->Update();
TLine *line4 = new TLine(0.938272+0.13957,0.,0.938272+0.13957,gPad->GetUymax());
line4->SetLineWidth(3);
line4->Draw();
TLine *line5 = new TLine(W_bin[i]-0.13957,0.,W_bin[i]-0.13957,gPad->GetUymax());
line5->SetLineWidth(3);
line5->Draw();




};
};

file_out->Close();

}; //end of main program


TH1D *h_corr_w(TH1D *h, Int_t aa_max, Int_t aa_min) {

TH1D *h_out;



Float_t left;
Float_t width;
Float_t position;
Float_t avrg;

qqq.str("");
qqq << h->GetName() << "bin_corr" << endl;
h_out = (TH1D*)h->Clone(qqq.str().c_str());
qqq.str("");

h_out->SetLineColor(kRed);
h_out->SetMarkerColor(kRed);


qqq.str("");
qqq << h->GetName() << "bin_corr" << endl;
h_out->SetName(qqq.str().c_str());
qqq.str("");


f = new TF1("func",f_fit,h->GetBinLowEdge(aa_min),h->GetBinLowEdge(aa_max)+h->GetBinWidth(aa_min),0);

tmp = new TH1D("tmp","tmp",100,h->GetBinLowEdge(aa_min),h->GetBinLowEdge(aa_max)+h->GetBinWidth(aa_min));
for (Int_t subbin=1; subbin<101;subbin++) {

tmp->SetBinContent(subbin,f->Eval(tmp->GetBinCenter(subbin)));
};
tmp->SetLineWidth(2);
tmp->Draw("same c");

for (Int_t bin=aa_min; bin<=aa_max;bin++) {

left = h->GetBinLowEdge(bin);
width = h->GetBinWidth(bin);
avrg = 0;


avrg = (f->Integral(left,left+width))/width;



if ((h->GetBinContent(bin)) == 0.) avrg = 0;

//cout << m_pip_p->GetBinContent(bin) << "  " << avrg << endl;

if ((h->GetBinContent(bin)) != 0.) {
h_out->SetBinContent(bin,(h->GetBinContent(bin))*(f->Eval(h->GetBinCenter(bin)))/avrg);
h_out->SetBinError(bin,(h->GetBinError(bin))/(h->GetBinContent(bin))*(h_out->GetBinContent(bin)));
} else {
h_out->SetBinContent(bin,0.);
h_out->SetBinError(bin,0.000001);
};

};




return h_out;


}; 




Double_t fit_w(Double_t *x, Double_t *par) {

Double_t func;



if (x[0] <= 1.45) {

par[0] = par[15] - 1.45*par[1] - 1.45*1.45*par[2];
func = par[0]+x[0]*par[1]+x[0]*x[0]*par[2];
};

if ((x[0] > 1.45) && (x[0] <= 1.55)) {

par[3] = par[15] - 1.45*par[4] - 1.45*1.45*par[5];
par[4] = (par[16] - par[3]-1.55*1.55*par[5])/1.55;
func = par[3]+x[0]*par[4]+x[0]*x[0]*par[5];
};

if ((x[0] > 1.55) && (x[0] <= 1.65)) {
par[6] = par[16] - 1.55*par[7]-1.55*1.55*par[8];
par[7] = (par[17]-par[6]-1.65*1.65*par[8])/1.65;
func = par[6]+x[0]*par[7]+x[0]*x[0]*par[8];
};

if ((x[0] > 1.65) && (x[0] <= 1.75)) {

par[9] = par[17] - 1.65*par[10]-1.65*1.65*par[11];
par[10] = (par[18] - par[9] - 1.75*1.75*par[11])/1.75;
func = par[9]+x[0]*par[10]+x[0]*x[0]*par[11];
};

if ((x[0] > 1.75) && (x[0] <= 1.85)) {

par[12] = par[18] - 1.75*par[13]+1.75*1.75*par[14];
func = par[12]+x[0]*par[13]+x[0]*x[0]*par[14];
};


return func;

};


Double_t fit_w_old(Double_t *x, Double_t *par) {

Double_t func;



if (x[0] <= 1.55) {

par[0] = par[10] - 1.55*par[1]-1.55*1.55*par[2]-1.55*1.55*1.55*par[3];
func = par[0]+x[0]*par[1]+x[0]*x[0]*par[2]+x[0]*x[0]*x[0]*par[3];
};

if (x[0] > 1.55) {

par[4] = par[10] - 1.55*par[5]-1.55*1.55*par[6]-1.55*1.55*1.55*par[7]-1.55*1.55*1.55*1.55*par[8]-1.55*1.55*1.55*1.55*1.55*par[9];
func = par[4]+x[0]*par[5]+x[0]*x[0]*par[6]+x[0]*x[0]*x[0]*par[7]+x[0]*x[0]*x[0]*x[0]*par[8]+x[0]*x[0]*x[0]*x[0]*x[0]*par[9];
};

return func;

};



TH1D *h_corr_w(TH1D *h) {

TH1D *h_out;


TGraph *gr = new TGraphErrors(h);
spline = new TSpline5("spline",gr);
spline->SetLineWidth(2);

Float_t left;
Float_t width;
Float_t position;
Float_t avrg;

qqq.str("");
qqq << h->GetName() << "bin_corr" << endl;
h_out = (TH1D*)h->Clone(qqq.str().c_str());
qqq.str("");

h_out->SetLineColor(kRed);
h_out->SetMarkerColor(kRed);


qqq.str("");
qqq << h->GetName() << "bin_corr" << endl;
h_out->SetName(qqq.str().c_str());
qqq.str("");


f = new TF1("func",f_fit,h->GetBinLowEdge(1),h->GetBinLowEdge(h->GetNbinsX())+h->GetBinWidth(1),0);

tmp = new TH1D("tmp","tmp",100,h->GetBinLowEdge(0),h->GetBinLowEdge(h->GetNbinsX())+h->GetBinWidth(1));
for (Int_t subbin=1; subbin<101;subbin++) {

tmp->SetBinContent(subbin,f->Eval(tmp->GetBinCenter(subbin)));
};
tmp->SetLineWidth(2);
tmp->Draw("same c");

for (Int_t bin=1; bin<=(h_out->GetNbinsX());bin++) {

left = h->GetBinLowEdge(bin);
width = h->GetBinWidth(bin);
avrg = 0;

/*
for (Int_t subbin=0; subbin<100;subbin++) {

position = left + width*subbin/99.;
avrg = avrg + spline->Eval(position);

};
avrg = avrg/100.;
*/

avrg = (f->Integral(left,left+width))/width;



if ((h->GetBinContent(bin)) == 0.) avrg = 0;

//cout << m_pip_p->GetBinContent(bin) << "  " << avrg << endl;

if ((h->GetBinContent(bin)) != 0.) {
h_out->SetBinContent(bin,(h->GetBinContent(bin))*(f->Eval(h->GetBinCenter(bin)))/avrg);
h_out->SetBinError(bin,(h->GetBinError(bin))/(h->GetBinContent(bin))*(h_out->GetBinContent(bin)));
} else {
h_out->SetBinContent(bin,0.);
h_out->SetBinError(bin,0.000001);
};

};




return h_out;


}; 


Double_t f_fit(Double_t *x, Double_t *par) {

return spline->Eval(x[0]);

}


TH1D *h_bin_corr(TH1D *h) {

TH1D *h_out;


TGraph *gr = new TGraph(h);
spline = new TSpline3("spline",gr);
spline->SetLineWidth(2);

Float_t left;
Float_t width;
Float_t position;
Float_t avrg;

qqq.str("");
qqq << h->GetName() << "bin_corr";
h_out = (TH1D*)h->Clone(qqq.str().c_str());
qqq.str("");

h_out->SetLineColor(kRed);
h_out->SetMarkerColor(kRed);


qqq.str("");
qqq << h->GetName() << "bin_corr";
h_out->SetName(qqq.str().c_str());
qqq.str("");

h->Fit("f_q2","EQN");


for (Int_t bin=1; bin<=(h->GetNbinsX());bin++) {

left = h->GetBinLowEdge(bin);
width = h->GetBinWidth(bin);
avrg = 0;

/*
for (Int_t subbin=0; subbin<100;subbin++) {

position = left + width*subbin/99.;
avrg = avrg + spline->Eval(position);

};
avrg = avrg/100.;
*/

avrg = (f_q2->Integral(left,left+width))/width;

if ((h->GetBinContent(bin)) == 0.) avrg = 0;

//cout << m_pip_p->GetBinContent(bin) << "  " << avrg << endl;

if ((h->GetBinContent(bin)) != 0.) {
h_out->SetBinContent(bin,(h->GetBinContent(bin))*(f_q2->Eval(h->GetBinCenter(bin)))/avrg);
h_out->SetBinError(bin,(h->GetBinError(bin))/(h->GetBinContent(bin))*(h_out->GetBinContent(bin)));
} else {
h_out->SetBinContent(bin,0.);
h_out->SetBinError(bin,0.000001);
};

};

return h_out;


}; 


void draw_1d_hist (Int_t canvas, TH1D *h, string title, string name, string ytitle, string xtitle, Int_t color, string draw_options, string distr_flag,Int_t i) {

c->cd(canvas);
c->cd(canvas)->SetBottomMargin(0.2);
c->cd(canvas)->SetTopMargin(0.1);
c->cd(canvas)->SetLeftMargin(0.23);
c->cd(canvas)->SetRightMargin(0.01);
gPad->SetFillStyle(0);

h->SetMarkerStyle(20);
h->SetMarkerColor(color);
h->SetLineColor(color);
h->SetOption("pX0");
h->SetTitle(title.c_str());
h->SetTitleSize(0.1);


h->SetName(name.c_str());


 h->GetYaxis()->SetTitle(ytitle.c_str());
 h ->GetXaxis()->SetTitle(xtitle.c_str());
 h ->GetXaxis()->SetTitleSize(0.08);
 h->GetYaxis()->SetTitleSize(0.08);
 h->GetYaxis()->SetTitleOffset(1.3);
 h->GetXaxis()->SetLabelSize(0.08);
 h->GetXaxis()->SetNdivisions(6);
 h->GetYaxis()->SetLabelSize(0.07);
 h->GetYaxis()->SetNdivisions(5);


h->SetAxisRange(0, h-> GetMaximum()+(h-> GetMaximum())/2., "Y");
if ((name == "model_thetaP_")&&(W_bin[i]>1.65))h->SetAxisRange(0, h-> GetMaximum()+(h-> GetMaximum()), "Y");


};



Int_t get_max_w (Float_t Q2_bin) {
Int_t get_max_w = 0;
if ((Q2_bin> 0.4)&&(Q2_bin< 0.5))get_max_w = 21;
if ((Q2_bin> 0.5)&&(Q2_bin< 0.6))get_max_w = 20;
if ((Q2_bin> 0.6)&&(Q2_bin< 0.65))get_max_w = 19;
if ((Q2_bin> 0.65)&&(Q2_bin< 0.7))get_max_w = 18;
if ((Q2_bin> 0.7)&&(Q2_bin< 0.75))get_max_w = 17;
if ((Q2_bin> 0.75)&&(Q2_bin< 0.8))get_max_w = 16;
if ((Q2_bin> 0.8)&&(Q2_bin< 0.85))get_max_w = 14;
if ((Q2_bin> 0.85)&&(Q2_bin< 0.9))get_max_w = 13;
if ((Q2_bin> 0.9)&&(Q2_bin< 0.95))get_max_w = 12;
if ((Q2_bin> 0.95)&&(Q2_bin< 1.0))get_max_w = 10;
if ((Q2_bin> 1.0)&&(Q2_bin< 1.05))get_max_w = 9;
if ((Q2_bin> 1.05)&&(Q2_bin< 1.1))get_max_w = 7;
if ((Q2_bin> 1.1)&&(Q2_bin< 1.15))get_max_w = 6;
if ((Q2_bin> 1.15)&&(Q2_bin< 1.2))get_max_w = 4;
if ((Q2_bin> 1.2)&&(Q2_bin< 1.25))get_max_w = 2;
if ((Q2_bin> 1.25)&&(Q2_bin< 1.3))get_max_w = 1;
return get_max_w;
};

Int_t get_min_w (Float_t Q2_bin) {
Int_t get_min_w = 0;
if ((Q2_bin> 0.4)&&(Q2_bin< 0.45))get_min_w = 12;
return get_min_w;
};



void read_data_rec(TFile *file_eff,Int_t i) {

file_eff->cd();

qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h1prj_inv_m_pip_p_1_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),m_pip_p);
qqq.str("");




qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h1prj_inv_m_pip_pim_1_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),m_pip_pim);
qqq.str("");



qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h3prj_inv_m_pim_p_1_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),m_pim_p);
qqq.str("");





qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h1prj_th_P_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),theta_p);
qqq.str("");



qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h1prj_th_PIm_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),theta_pim);
qqq.str("");



qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h1prj_th_PIp_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),theta_pip);
qqq.str("");






qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h1prj_alpha_PIpPIm_pipf_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),alpha_p);
qqq.str("");





qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h2prj_alpha_PPIp_piPIm_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),alpha_pim);
qqq.str("");




qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h3prj_alpha_PPIm_piPIp_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),alpha_pip);
qqq.str("");



};

void read_data_rec_corr(TFile *file_eff,Int_t i) {

file_eff->cd();

qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h1prj_inv_m_pip_p_1_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),m_pip_p_bin_corr);
qqq.str("");




qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h1prj_inv_m_pip_pim_1_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),m_pip_pim_bin_corr);
qqq.str("");



qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h3prj_inv_m_pim_p_1_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),m_pim_p_bin_corr);
qqq.str("");





qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h1prj_th_P_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),theta_p_bin_corr);
qqq.str("");



qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h1prj_th_PIm_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),theta_pim_bin_corr);
qqq.str("");



qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h1prj_th_PIp_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),theta_pip_bin_corr);
qqq.str("");






qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h1prj_alpha_PIpPIm_pipf_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),alpha_p_bin_corr);
qqq.str("");





qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h2prj_alpha_PPIp_piPIm_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),alpha_pim_bin_corr);
qqq.str("");




qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/h3prj_alpha_PPIm_piPIp_bin_corr";
gDirectory->GetObject(qqq.str().c_str(),alpha_pip_bin_corr);
qqq.str("");



};



void draw_1d_canvas( Int_t i, Int_t qq2 ) {







/*

m_pip_p_bin_corr = h_bin_corr(m_pip_p);

m_pip_pim_bin_corr = h_bin_corr(m_pip_pim);

m_pim_p_bin_corr = h_bin_corr(m_pim_p);

theta_p_bin_corr = h_bin_corr(theta_p);

theta_pim_bin_corr = h_bin_corr(theta_pim);

theta_pip_bin_corr = h_bin_corr(theta_pip);

alpha_p_bin_corr = h_bin_corr(alpha_p);

alpha_pim_bin_corr = h_bin_corr(alpha_pim);

alpha_pip_bin_corr = h_bin_corr(alpha_pip);

qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i];
file_out->mkdir(qqq.str().c_str());
file_out->cd(qqq.str().c_str());
qqq.str("");

m_pip_p_bin_corr->Write();
m_pip_pim_bin_corr->Write();
m_pim_p_bin_corr->Write();
theta_p_bin_corr->Write();
theta_pim_bin_corr->Write();
theta_pip_bin_corr->Write();
alpha_p_bin_corr->Write();
alpha_pim_bin_corr->Write();
alpha_pip_bin_corr->Write();

file_out->cd();
*/

};
