TH1D *m_pip_p,*m_pip_pim,*m_pim_p;
TH1D *theta_p,*theta_pim,*theta_pip;
TH1D *alpha_p,*alpha_pim,*alpha_pip;


TH1D *m_pip_p_bin_corr,*m_pip_pim_bin_corr,*m_pim_p_bin_corr;
TH1D *theta_p_bin_corr,*theta_pim_bin_corr,*theta_pip_bin_corr;
TH1D *alpha_p_bin_corr,*alpha_pim_bin_corr,*alpha_pip_bin_corr;

//TFile *file_out = new TFile("out_cr_sec_all_top_bin_corr.root","RECREATE");

TH2D *q2vsw = new TH2D("q2vsw","q2vsw",22,1.3,1.85,12,0.4,1.);
TH2D *q2vsw_q2_corr = new TH2D("q2vsw_q2_corr","q2vsw_q2_corr",22,1.3,1.85,12,0.4,1.);

TCanvas *c = new TCanvas("c","c",600,500);

TH1D *h_q2;

TH1D *h_w;

TH1D *tmp;

Double_t err;

Float_t Q2_bin,W_bin[30];

TLegend *leg;

TSpline5 *spline;
ostringstream qqq;

TF1 *f_q2 = new TF1("f_q2","pol2",0.4,1.);
 
void bin_corr_2d() {
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

TFile *file_cr_sec_pim = new TFile("out_cr_sec_all_top_bin_corr.root","READ");


 for (Int_t qq2=0; qq2<12;qq2++) {
 Q2_bin = 0.425 + 0.05*qq2;


//for (Int_t i=13; i<14;i++) {
 for (Int_t i=get_min_w(Q2_bin); i<get_max_w(Q2_bin);i++) {
 W_bin[i] = 1.3125+0.025*i; 

read_data_rec(file_cr_sec_pim,i);

//draw_1d_canvas(i,qq2);

/*
h_prj_crs->Scale(1/(0.025*0.05));
 Int[i]= h_prj_crs->Integral();
 h_prj_crs->IntegralAndError(1,h_prj_crs->GetNbinsX(),w_err);
 h_w_int[qq2]->Fill(W_bin[i],Int[i]); 
h_w_int[qq2]->SetBinError(h_w_int[qq2]->FindBin(W_bin[i]),w_err);
*/

q2vsw->SetBinContent(i+1,qq2+1,(m_pip_pim->Integral())*(m_pip_pim->GetBinWidth(1)));

m_pip_pim->IntegralAndError(1,m_pip_pim->GetNbinsX(),err);
q2vsw->SetBinError(i+1,qq2+1,err*(m_pip_pim->GetBinWidth(1)));




};
};
 for (Int_t i=0; i<22;i++) {
 W_bin[i] = 1.3125+0.025*i; 

h_q2 = q2vsw->ProjectionY("bin1",i+1,i+1);
h_q2->SetMarkerStyle(20);

c->cd();
c->SetTopMargin(0.01);
c->SetRightMargin(0.01);
h_q2->SetTitle("");
h_q2->GetXaxis()->SetTitle("Q^{2} (GeV^{2})");
h_q2->GetXaxis()->SetTitleSize(0.07);
h_q2->GetXaxis()->SetTitleOffset(0.6);
h_q2->GetYaxis()->SetTitleOffset(0.6);
h_q2->GetYaxis()->SetTitleSize(0.07);
h_q2->GetYaxis()->SetTitle("#sigma (#mubn)");

/*
h_q2->SetMinimum(0.00001);
h_q2->Draw("e1"); 
h_q2->Fit("f_q2","E");
(h_bin_corr(h_q2))->Draw("APe1 same");
c->Print("q2_fit.pdf");
*/
 for (Int_t qq2=0; qq2<12;qq2++) {
 Q2_bin = 0.425 + 0.05*qq2;


if ((i >= get_min_w(Q2_bin))&&(i<get_max_w(Q2_bin))) {
q2vsw_q2_corr->SetBinContent(i+1,qq2+1,(h_bin_corr(h_q2))->GetBinContent(qq2+1));

q2vsw_q2_corr->SetBinError(i+1,qq2+1,(h_bin_corr(h_q2))->GetBinError(qq2+1));
} else {

q2vsw_q2_corr->SetBinContent(i+1,qq2+1,0.);

q2vsw_q2_corr->SetBinError(i+1,qq2+1,0.);

};



};
};

Int_t qbin = 2;

switch ( qbin ) {

case 1:
Int_t aa_min = 13;
Int_t aa_max = 20;
const Int_t nbins = 8;
break;

case 2:
Int_t aa_min = 1;
Int_t aa_max = 20;
const Int_t nbins = 20;
break;

case 3:
Int_t aa_min = 1;
Int_t aa_max = 19;
const Int_t nbins = 19;
break;

case 4:
Int_t aa_min = 1;
Int_t aa_max = 19;
const Int_t nbins = 19;
break;

case 5:
Int_t aa_min = 1;
Int_t aa_max = 18;
const Int_t nbins = 18;
break;

case 6:
Int_t aa_min = 1;
Int_t aa_max = 17;
const Int_t nbins = 17;
break;

case 7:
Int_t aa_min = 1;
Int_t aa_max = 16;
const Int_t nbins = 16;
break;

case 8:
Int_t aa_min = 1;
Int_t aa_max = 15;
const Int_t nbins = 15;
break;

case 9:
Int_t aa_min = 1;
Int_t aa_max = 13;
const Int_t nbins = 13;
break;

case 10:
Int_t aa_min = 1;
Int_t aa_max = 12;
const Int_t nbins = 12;
break;

case 11:
Int_t aa_min = 1;
Int_t aa_max = 11;
const Int_t nbins = 11;
break;

case 12:
Int_t aa_min = 1;
Int_t aa_max = 9;
const Int_t nbins = 9;
break;


};
cout << "nbins = " << nbins << endl;
h_w = q2vsw_q2_corr->ProjectionX("bin1",qbin,qbin);
Float_t Q2_cur = 0.425 + 0.05*(qbin-1);
cout << Q2_cur << endl;
Float_t W_max = 1.3125+0.025*(get_max_w(Q2_cur)-1);
cout << get_max_w(Q2_cur) << endl;
h_w->SetMarkerStyle(20);
h_w->SetMarkerColor(1);

//Int_t nbins = (h_w->GetNbinsX())-2;

if ( aa_min == 13 ){
Double_t x[nbins], y[nbins];
} else {
Double_t x[nbins+1], y[nbins+1];
x[0] = 1.23;
y[0] = 0.;
};
for (Int_t aa = aa_min; aa <=aa_max; aa++) {
if ( aa_min == 13 ) {
x[aa-aa_min] = (h_w->GetBinCenter(aa)+ h_w->GetBinCenter(aa+1))/2.;
y[aa-aa_min] = (h_w->GetBinContent(aa) + h_w->GetBinContent(aa+1))/2.;
cout << aa << "  " << x[aa-aa_min] << "  " << y[aa-aa_min] << endl;
} else {
x[aa-aa_min+1] = (h_w->GetBinCenter(aa)+ h_w->GetBinCenter(aa+1))/2.;
y[aa-aa_min+1] = (h_w->GetBinContent(aa) + h_w->GetBinContent(aa+1))/2.;
};
};
if ( aa_min == 13 ){
TGraph *gr233 = new TGraph(nbins,x,y);
} else {
TGraph *gr233 = new TGraph(nbins+1,x,y);
};

spline = new TSpline5("spline",gr233);
//TH1F *w_tmp = new TH1F("w_tmp","w_tmp",get_max_w(Q2_cur)-1,1.3,W_max+0.025);
/*
c->cd();
c->SetTopMargin(0.01);
c->SetRightMargin(0.01);
h_w->SetTitle("");
h_w->GetXaxis()->SetTitle("W (GeV)");
h_w->GetXaxis()->SetTitleSize(0.07);
h_w->GetXaxis()->SetTitleOffset(0.6);
h_w->GetYaxis()->SetTitleOffset(0.6);
h_w->GetYaxis()->SetTitleSize(0.07);
h_w->GetYaxis()->SetTitle("#sigma (#mubn)");
h_w->Draw("e1");
*/


//spline->Draw("same");

//(h_corr_w(h_w,aa_max+1,aa_min))->Draw("same");




//(h_corr_w(h_w))->Draw("same e1");

TF1 *w_fit = new TF1("w_fit",fit_w,1.3,1.8,19); 

//w_fit->SetParameters(-389.,122.,343.,-160.,-1.91153e+06,5.81872e+06,-7.07552e+06,4.29614e+06,-1.30249e+06,157736.);

/*w_fit->SetParLimits(0,-500.,500.);
w_fit->SetParLimits(1,-500.,500.);
w_fit->SetParLimits(2,-500.,500.);
w_fit->SetParLimits(3,-500.,500.);
w_fit->SetParameter(11,h_w->GetBinContent(9));
w_fit->SetParLimits(4,-500.,500.);
w_fit->SetParLimits(5,-500.,500.);
w_fit->SetParLimits(6,-500.,500.);
w_fit->SetParLimits(7,-500.,500.);
w_fit->SetParLimits(8,-500.,500.);
*/

w_fit->FixParameter(15,(h_w->GetBinContent(6)+h_w->GetBinContent(7))/2.);
w_fit->FixParameter(16,(h_w->GetBinContent(10)+h_w->GetBinContent(11))/2.);
w_fit->FixParameter(17,(h_w->GetBinContent(14)+h_w->GetBinContent(15))/2.);
w_fit->FixParameter(18,(h_w->GetBinContent(18)+h_w->GetBinContent(19))/2.);
//w_fit->FixParameter(3,0.);
//h_w->Fit(w_fit,"","WLE",1.31,W_max);



//h_w->Fit("pol3","","E",1.6375,1.8125);
//spline->Draw("same");

//file_out->Close();
//c->Print("w_spline.pdf");
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
