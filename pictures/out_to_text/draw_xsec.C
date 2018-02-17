

TH1D *m_pip_p,*m_pip_pim,*m_pim_p;
TH1D *theta_p,*theta_pim,*theta_pip;
TH1D *alpha_p,*alpha_pim,*alpha_pip;
TH1D *phi_p,*phi_pim,*phi_pip;

TH1D *m_pip_p_bin_corr,*m_pip_pim_bin_corr,*m_pim_p_bin_corr;
TH1D *theta_p_bin_corr,*theta_pim_bin_corr,*theta_pip_bin_corr;
TH1D *phi_p_bin_corr,*phi_pim_bin_corr,*phi_pip_bin_corr;

TCanvas *c;

Float_t Q2_bin,W_bin[30];

TLegend *leg;

TSpline5 *spline;
ostringstream qqq;
 
Double_t f_fit(Double_t *x, Double_t *par) {

return spline->Eval(x[0]);

}



TH1D *h_bin_corr_theta(TH1D *h) {

TH1D *h_out;

Double_t *x = new double[(h->GetNbinsX())-1];
Double_t *y = new double[(h->GetNbinsX())-1];

for (Int_t aa = 1; aa <=((h->GetNbinsX())-1); aa++) {
x[aa-1] = (h->GetBinCenter(aa)+ h->GetBinCenter(aa+1))/2.;
y[aa-1] = (h->GetBinContent(aa) + h->GetBinContent(aa+1))/2.;
};


TGraph *gr = new TGraphErrors(((h->GetNbinsX())-1),x,y);
spline = new TSpline5("spline",gr);
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


f = new TF1("func",f_fit,h->GetBinLowEdge(1),h->GetBinLowEdge(h->GetNbinsX())+h->GetBinWidth(1),0);

tmp = new TH1D("tmp","tmp",100,h->GetBinLowEdge(0),h->GetBinLowEdge(h->GetNbinsX())+h->GetBinWidth(1));
for (Int_t subbin=1; subbin<101;subbin++) {


tmp->SetBinContent(subbin,f->Eval(tmp->GetBinCenter(subbin)));
};
tmp->SetLineWidth(2);
//tmp->Draw("same c");

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





TH1D *h_alpha_sym(TH1D *h) {

TH1D *h_out;




Float_t left;
Float_t width;
Float_t position;
Float_t avrg;

qqq.str("");
qqq << h->GetName();
h_out = (TH1D*)h->Clone(qqq.str().c_str());
qqq.str("");

h_out->SetLineColor(kRed);
h_out->SetMarkerColor(kRed);


qqq.str("");
qqq << h->GetName();
h_out->SetName(qqq.str().c_str());
qqq.str("");




for (Int_t bin=1; bin<=Int_t((h_out->GetNbinsX())/2.);bin++) {

left = h->GetBinLowEdge(bin);
width = h->GetBinWidth(bin);
avrg = 0;

h_out->SetBinContent(bin,((h->GetBinContent(bin))+(h->GetBinContent((h->GetNbinsX())-bin+1)))/2.);

h_out->SetBinContent(((h->GetNbinsX())-bin+1),((h->GetBinContent(bin))+(h->GetBinContent((h->GetNbinsX())-bin+1)))/2.);


h_out->SetBinError(bin,sqrt((h->GetBinError(bin))*(h->GetBinError(bin))+(h->GetBinError((h->GetNbinsX())-bin+1))*(h->GetBinError((h->GetNbinsX())-bin+1)))/2.);

h_out->SetBinError(((h->GetNbinsX())-bin+1),sqrt((h->GetBinError(bin))*(h->GetBinError(bin))+(h->GetBinError((h->GetNbinsX())-bin+1))*(h->GetBinError((h->GetNbinsX())-bin+1)))/2.);


};

return h_out;


}; 



TH1D *h_bin_corr(TH1D *h) {

TH1D *h_out;


TGraph *gr = new TGraph(h);
spline = new TSpline5("spline",gr);
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




for (Int_t bin=1; bin<=(h_out->GetNbinsX());bin++) {

left = h->GetBinLowEdge(bin);
width = h->GetBinWidth(bin);
avrg = 0;

for (Int_t subbin=0; subbin<100;subbin++) {

position = left + width*subbin/99.;
avrg = avrg + spline->Eval(position);

};
avrg = avrg/100.;

if ((h->GetBinContent(bin)) == 0.) avrg = 0;

//cout << m_pip_p->GetBinContent(bin) << "  " << avrg << endl;

if ((h->GetBinContent(bin)) != 0.) {
h_out->SetBinContent(bin,(h->GetBinContent(bin))*(spline->Eval(h->GetBinCenter(bin)))/avrg);
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



qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/phi_protonbin_corr";
gDirectory->GetObject(qqq.str().c_str(),phi_p);
qqq.str("");





qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/phi_pimbin_corr";
gDirectory->GetObject(qqq.str().c_str(),phi_pim);
qqq.str("");




qqq.str("");
qqq << "q2_" << Q2_bin << "/w_" << W_bin[i] << "/phi_pipbin_corr";
gDirectory->GetObject(qqq.str().c_str(),phi_pip);
qqq.str("");

};



void draw_1d_canvas( Int_t i, Int_t qq2 ) {

c = new TCanvas("c","c",700,700);

c->Divide(3,3);

qqq << "Q^{2} = " << Q2_bin << " GeV^{2}" <<"; W = " << W_bin[i] <<" GeV" ;

Float_t max;

max = m_pip_p->GetMaximum();

if ((m_pip_pim->GetMaximum()) > max) max = m_pip_pim->GetMaximum();

if ((m_pim_p->GetMaximum()) > max) max = m_pim_p->GetMaximum();


for (Int_t kk=1; kk<4; kk++) { 
c->cd(kk)->SetBottomMargin(0.2);
c->cd(kk)->SetTopMargin(0.15);
c->cd(kk)->SetLeftMargin(0.23);
c->cd(kk)->SetRightMargin(0.01);
c->cd(kk)->SetFillStyle(4000);
};

for (Int_t kk=4; kk<10; kk++) { 
c->cd(kk)->SetBottomMargin(0.2);
c->cd(kk)->SetTopMargin(0.005);
c->cd(kk)->SetLeftMargin(0.23);
c->cd(kk)->SetRightMargin(0.01);
c->cd(kk)->SetFillStyle(4000);
};
gPad->SetFillStyle(4000);

c->cd(1);
m_pip_p->SetLineColor(1);
m_pip_p->SetMarkerColor(1);
m_pip_p->SetMinimum(0);
m_pip_p->SetMaximum(1.2*max);

qqq.str("");
if (qq2 == 11) {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_"  << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000 << "/xsec1d_mpippr.dat"; 
} else {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_" << "0" << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000<< "/xsec1d_mpippr.dat";
}; 
//cout << qqq.str() << endl;
ofstream outputFile;
outputFile.open(qqq.str().c_str());
for (Int_t zzz = 1; zzz <= m_pip_p->GetNbinsX(); zzz++) {
if (m_pip_p->GetBinContent(zzz) > 0.) {

outputFile << std::fixed << std::setprecision(4);
outputFile << m_pip_p->GetBinCenter(zzz) << " ";
outputFile << std::fixed << std::setprecision(8);

Float_t temp_err = 0.;
outputFile << m_pip_p->GetBinContent(zzz) << " " << m_pip_p->GetBinError(zzz) << " " << temp_err << endl;
}
};
outputFile.close();
qqq.str("");

//m_pip_p->Draw("e1");
//m_pip_p->Draw("e0 same");


c->cd(2);
m_pip_pim->SetLineColor(1);
m_pip_pim->SetMarkerColor(1);
m_pip_pim->SetMinimum(0);
m_pip_pim->SetMaximum(1.2*max);
//m_pip_pim->Draw("e1");
//m_pip_pim->Draw("e0 same");

qqq.str("");
if (qq2 == 11) {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_"  << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000 << "/xsec1d_mpippim.dat"; 
} else {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_" << "0" << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000<< "/xsec1d_mpippim.dat";
}; 
//cout << qqq.str() << endl;
//ofstream outputFile;
outputFile.open(qqq.str().c_str());
for (Int_t zzz = 1; zzz <= m_pip_pim->GetNbinsX(); zzz++) {
if (m_pip_pim->GetBinContent(zzz) > 0.) {

outputFile << std::fixed << std::setprecision(4);
outputFile << m_pip_pim->GetBinCenter(zzz) << " ";
outputFile << std::fixed << std::setprecision(8);

Float_t temp_err = 0.;
outputFile << m_pip_pim->GetBinContent(zzz) << " " << m_pip_pim->GetBinError(zzz) << " " << temp_err << endl;
}
};
outputFile.close();
qqq.str("");









c->cd(3);
m_pim_p->SetLineColor(1);
m_pim_p->SetMarkerColor(1);
m_pim_p->SetMinimum(0);
m_pim_p->SetMaximum(1.2*max);
//m_pim_p->Draw("e1");
//m_pim_p->Draw("e0 same");


qqq.str("");
if (qq2 == 11) {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_"  << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000 << "/xsec1d_mpimpr.dat"; 
} else {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_" << "0" << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000<< "/xsec1d_mpimpr.dat";
}; 
//cout << qqq.str() << endl;
//ofstream outputFile;
outputFile.open(qqq.str().c_str());
for (Int_t zzz = 1; zzz <= m_pim_p->GetNbinsX(); zzz++) {
if (m_pim_p->GetBinContent(zzz) > 0.) {

outputFile << std::fixed << std::setprecision(4);
outputFile << m_pim_p->GetBinCenter(zzz) << " ";
outputFile << std::fixed << std::setprecision(8);

Float_t temp_err = 0.;
outputFile << m_pim_p->GetBinContent(zzz) << " " << m_pim_p->GetBinError(zzz) << " " << temp_err << endl;
}
};
outputFile.close();
qqq.str("");


max = theta_p->GetMaximum();

if ((theta_pip->GetMaximum()) > max) max = theta_pip->GetMaximum();

if ((theta_pim->GetMaximum()) > max) max = theta_pim->GetMaximum();

c->cd(4);
theta_p->SetLineColor(1);
theta_p->SetMarkerColor(1);
theta_p->SetMinimum(0);
theta_p->SetMaximum(1.2*max);
theta_p->GetXaxis()->SetTitle("#theta_{p'} (deg)");
//theta_p->Draw("e1");

qqq.str("");
if (qq2 == 11) {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_"  << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000 << "/xsec1d_theta_pr.dat"; 
} else {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_" << "0" << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000<< "/xsec1d_theta_pr.dat";
}; 
//cout << qqq.str() << endl;
//ofstream outputFile;
outputFile.open(qqq.str().c_str());
for (Int_t zzz = 1; zzz <= theta_p->GetNbinsX(); zzz++) {
if (theta_p->GetBinContent(zzz) > 0.) {

outputFile << std::fixed << std::setprecision(4);
outputFile << theta_p->GetBinCenter(zzz) << " ";
outputFile << std::fixed << std::setprecision(8);

Float_t temp_err = 0.;
outputFile << theta_p->GetBinContent(zzz) << " " << theta_p->GetBinError(zzz) << " " << temp_err << endl;
}
};
outputFile.close();
qqq.str("");




c->cd(5);
theta_pim->SetLineColor(1);
theta_pim->SetMarkerColor(1);
theta_pim->SetMinimum(0);
theta_pim->SetMaximum(1.2*max);
theta_pim->GetXaxis()->SetTitle("#theta_{#pi^{-}} (deg)");
//theta_pim->Draw("e1");

qqq.str("");
if (qq2 == 11) {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_"  << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000 << "/xsec1d_theta_pim.dat"; 
} else {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_" << "0" << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000<< "/xsec1d_theta_pim.dat";
}; 
//cout << qqq.str() << endl;
//ofstream outputFile;
outputFile.open(qqq.str().c_str());
for (Int_t zzz = 1; zzz <= theta_pim->GetNbinsX(); zzz++) {
if (theta_pim->GetBinContent(zzz) > 0.) {

outputFile << std::fixed << std::setprecision(4);
outputFile << theta_pim->GetBinCenter(zzz) << " ";
outputFile << std::fixed << std::setprecision(8);

Float_t temp_err = 0.;
outputFile << theta_pim->GetBinContent(zzz) << " " << theta_pim->GetBinError(zzz) << " " << temp_err << endl;
}
};
outputFile.close();
qqq.str("");





c->cd(6);
theta_pip->SetLineColor(1);
theta_pip->SetMarkerColor(1);
theta_pip->SetMinimum(0);
theta_pip->SetMaximum(1.2*max);
theta_pip->GetXaxis()->SetTitle("#theta_{#pi^{+}} (deg)");
//theta_pip->Draw("e1");

qqq.str("");
if (qq2 == 11) {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_"  << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000 << "/xsec1d_theta_pip.dat"; 
} else {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_" << "0" << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000<< "/xsec1d_theta_pip.dat";
}; 
//cout << qqq.str() << endl;
//ofstream outputFile;
outputFile.open(qqq.str().c_str());
for (Int_t zzz = 1; zzz <= theta_pip->GetNbinsX(); zzz++) {
if (theta_pip->GetBinContent(zzz) > 0.) {

outputFile << std::fixed << std::setprecision(4);
outputFile << theta_pip->GetBinCenter(zzz) << " ";
outputFile << std::fixed << std::setprecision(8);

Float_t temp_err = 0.;
outputFile << theta_pip->GetBinContent(zzz) << " " << theta_pip->GetBinError(zzz) << " " << temp_err << endl;
}
};
outputFile.close();
qqq.str("");




max = alpha_p->GetMaximum();

if ((alpha_pip->GetMaximum()) > max) max = alpha_pip->GetMaximum();

if ((alpha_pim->GetMaximum()) > max) max = alpha_pim->GetMaximum();


c->cd(7);
alpha_p->SetLineColor(1);
alpha_p->SetMarkerColor(1);
alpha_p->SetMinimum(0);
alpha_p->SetMaximum(1.2*max);
//alpha_p->Draw("e1");

qqq.str("");
if (qq2 == 11) {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_"  << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000 << "/xsec1d_alpha_pr.dat"; 
} else {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_" << "0" << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000<< "/xsec1d_alpha_pr.dat";
}; 
//cout << qqq.str() << endl;
//ofstream outputFile;
outputFile.open(qqq.str().c_str());
for (Int_t zzz = 1; zzz <= alpha_p->GetNbinsX(); zzz++) {
if (alpha_p->GetBinContent(zzz) > 0.) {

outputFile << std::fixed << std::setprecision(4);
outputFile << alpha_p->GetBinCenter(zzz) << " ";
outputFile << std::fixed << std::setprecision(8);

Float_t temp_err = 0.;
outputFile << alpha_p->GetBinContent(zzz) << " " << alpha_p->GetBinError(zzz) << " " << temp_err << endl;
}
};
outputFile.close();
qqq.str("");







c->cd(8);
alpha_pim->SetLineColor(1);
alpha_pim->SetMarkerColor(1);
alpha_pim->SetMinimum(0);
alpha_pim->SetMaximum(1.2*max);
alpha_pim->GetXaxis()->SetTitle("#alpha_{#pi^{-}} (deg)");
//alpha_pim->Draw("e1");


qqq.str("");
if (qq2 == 11) {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_"  << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000 << "/xsec1d_alpha_pim.dat"; 
} else {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_" << "0" << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000<< "/xsec1d_alpha_pim.dat";
}; 
//cout << qqq.str() << endl;
//ofstream outputFile;
outputFile.open(qqq.str().c_str());
for (Int_t zzz = 1; zzz <= alpha_pim->GetNbinsX(); zzz++) {
if (alpha_pim->GetBinContent(zzz) > 0.) {

outputFile << std::fixed << std::setprecision(4);
outputFile << alpha_pim->GetBinCenter(zzz) << " ";
outputFile << std::fixed << std::setprecision(8);

Float_t temp_err = 0.;
outputFile << alpha_pim->GetBinContent(zzz) << " " << alpha_pim->GetBinError(zzz) << " " << temp_err << endl;
}
};
outputFile.close();
qqq.str("");





c->cd(9);
alpha_pip->SetLineColor(1);
alpha_pip->SetMarkerColor(1);
alpha_pip->SetMinimum(0);
alpha_pip->SetMaximum(1.2*max);
//alpha_pip->Draw("e1");


qqq.str("");
if (qq2 == 11) {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_"  << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000 << "/xsec1d_alpha_pip.dat"; 
} else {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_" << "0" << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000<< "/xsec1d_alpha_pip.dat";
}; 
//cout << qqq.str() << endl;
//ofstream outputFile;
outputFile.open(qqq.str().c_str());
for (Int_t zzz = 1; zzz <= alpha_pip->GetNbinsX(); zzz++) {
if (alpha_pip->GetBinContent(zzz) > 0.) {

outputFile << std::fixed << std::setprecision(4);
outputFile << alpha_pip->GetBinCenter(zzz) << " ";
outputFile << std::fixed << std::setprecision(8);

Float_t temp_err = 0.;
outputFile << alpha_pip->GetBinContent(zzz) << " " << alpha_pip->GetBinError(zzz) << " " << temp_err << endl;
}
};
outputFile.close();
qqq.str("");









qqq.str("");
if (qq2 == 11) {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_"  << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000 << "/xsec1d_phi_pr.dat"; 
} else {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_" << "0" << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000<< "/xsec1d_phi_pr.dat";
}; 
outputFile.open(qqq.str().c_str());
for (Int_t zzz = 1; zzz <= phi_p->GetNbinsX(); zzz++) {
if (phi_p->GetBinContent(zzz) > 0.) {

outputFile << std::fixed << std::setprecision(4);
outputFile << phi_p->GetBinCenter(zzz) << " ";
outputFile << std::fixed << std::setprecision(8);

Float_t temp_err = 0.;
outputFile << phi_p->GetBinContent(zzz) << " " << phi_p->GetBinError(zzz) << " " << temp_err << endl;
}
};
outputFile.close();
qqq.str("");




qqq.str("");
if (qq2 == 11) {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_"  << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000 << "/xsec1d_phi_pim.dat"; 
} else {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_" << "0" << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000<< "/xsec1d_phi_pim.dat";
}; 
outputFile.open(qqq.str().c_str());
for (Int_t zzz = 1; zzz <= phi_pim->GetNbinsX(); zzz++) {
if (phi_pim->GetBinContent(zzz) > 0.) {

outputFile << std::fixed << std::setprecision(4);
outputFile << phi_pim->GetBinCenter(zzz) << " ";
outputFile << std::fixed << std::setprecision(8);

Float_t temp_err = 0.;
outputFile << phi_pim->GetBinContent(zzz) << " " << phi_pim->GetBinError(zzz) << " " << temp_err << endl;
}
};
outputFile.close();
qqq.str("");


qqq.str("");
if (qq2 == 11) {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_"  << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000 << "/xsec1d_phi_pip.dat"; 
} else {
qqq << "Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_" << "0" << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000<< "/xsec1d_phi_pip.dat";
}; 

outputFile.open(qqq.str().c_str());
for (Int_t zzz = 1; zzz <= phi_pip->GetNbinsX(); zzz++) {
if (phi_pip->GetBinContent(zzz) > 0.) {

outputFile << std::fixed << std::setprecision(4);
outputFile << phi_pip->GetBinCenter(zzz) << " ";
outputFile << std::fixed << std::setprecision(8);

Float_t temp_err = 0.;
outputFile << phi_pip->GetBinContent(zzz) << " " << phi_pip->GetBinError(zzz) << " " << temp_err << endl;
}
};
outputFile.close();
qqq.str("");




















c->cd();
//TLatex latex;
//latex.SetTextAlign(12);  //centered
//latex.DrawLatex(.2,.9745,qqq.str().c_str());
qqq.str("");
//c->Update();

//qqq << "Q_" << Q2_bin << "_W_" << W_bin[i] <<".pdf";
//c->Print(qqq.str().c_str());
//qqq.str("");




//c->Delete();

};

void draw_xsec() {
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

TFile *file_cr_sec_pim = new TFile("out_cr_sec_all_top_final_bin_corr_phi.root","READ");


 for (Int_t qq2=0; qq2<12;qq2++) {
 Q2_bin = 0.425 + 0.05*qq2;

qqq.str(""); 
if (qq2 == 11) {
qqq << "rm -rf  Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_"  << (((4.5 + 0.5*qq2)))*100; 
} else {
qqq << "rm -rf Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_" << "0" << (((4.5 + 0.5*qq2)))*100;
}; 

system(qqq.str().c_str());
qqq.str("");

//for (Int_t i=13; i<14;i++) {
for (Int_t i=get_min_w(Q2_bin); i<get_max_w(Q2_bin);i++) {
 W_bin[i] = 1.3125+0.025*i; 


qqq.str("");

if (qq2 == 11) {
qqq << "mkdir -p Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_"  << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000; 
} else {
qqq << "mkdir -p Q2_" << "0" << (((4 + 0.5*qq2)))*100 << "_" << "0" << (((4.5 + 0.5*qq2)))*100 << "/w_" << (1.3+0.025*i)*1000 << "_" << (1.3+0.025*(i+1))*1000;
}; 
 
system(qqq.str().c_str());
qqq.str("");

read_data_rec(file_cr_sec_pim,i);

draw_1d_canvas(i,qq2);

//m_pip_p->Draw();







};
};



//file_out->Close();

}; //end of main program
