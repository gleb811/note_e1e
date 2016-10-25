void  miss_pim() {

gStyle->SetOptStat(0);
gStyle->SetTitleSize(0.12,"t");
gStyle->SetTitleY(1.02);
gStyle->SetTitleX(0.65);
//gStyle->SetTitleAlign(33); 
TGaxis::SetMaxDigits(2);

ostringstream qqq;

TFile *MyFile_data = new TFile("out_ind4_miss_data.root","READ");

//pim_miss_radcorr_i

TFile *MyFile_sim = new TFile("out_ind4_sim_low_w.root","READ");


TFile *MyFile_ind4 = new TFile("out_ind4_miss_high_w.root","READ");

TCanvas *c = new TCanvas ("c","c",0,0,1000,600);
//pim_miss_radcorr_sim_i




TH1 *h_data[20];
TH1 *h_data_pip[20];
TH1 *h_data_pr[20];
TH1 *h_data_0[20];
TH1 *h_sim[20];
TH1 *h_sim_pip[20];
TH1 *h_sim_pr[20];
TH1 *h_sim_0[20];
TH1 *h_bckgr[20];
TH1 *h_bckgr_pip[20];
TH1 *h_bckgr_pr[20];
TH1 *h_bckgr_0[20];

c->Divide(5,4);

Int_t i;

for (Int_t j=0; j<5; j++){

i = j*5;

cout << i << endl;

qqq.str("");

qqq << "q2_0.475/" << "w_1." << 3125+250*i << "/" << "pim_mis_radcorr_" << i;

//cout << qqq.str() << endl;
MyFile_data->GetObject(qqq.str().c_str(),h_data[j]);

qqq.str("");

qqq << "q2_0.475/" << "w_1." << 3125+250*i << "/" << "pip_mis_radcorr_" << i;

//cout << qqq.str() << endl;
MyFile_data->GetObject(qqq.str().c_str(),h_data_pip[j]);

qqq.str("");

qqq << "q2_0.475/" << "w_1." << 3125+250*i << "/" << "pr_mis_radcorr_" << i;

//cout << qqq.str() << endl;
MyFile_data->GetObject(qqq.str().c_str(),h_data_pr[j]);


qqq.str("");

qqq << "q2_0.475/" << "w_1." << 3125+250*i << "/" << "0_mis_radcorr_" << i;

//cout << qqq.str() << endl;
MyFile_data->GetObject(qqq.str().c_str(),h_data_0[j]);



qqq.str("");

qqq << "q2_0.475/" << "w_1." << 3125+250*i << "/" << "pim_mis_radcorr_sim_" << i;

//cout << qqq.str() << endl;
if(j<4)MyFile_sim->GetObject(qqq.str().c_str(),h_sim[j]);
if(j>=3) {
MyFile_ind4->GetObject(qqq.str().c_str(),h_sim[j]);

qqq.str("");

qqq << "q2_0.475/" << "w_1." << 3125+250*i << "/" << "pim_mis_radcorr_sim_bckg_" << i;
MyFile_ind4->GetObject(qqq.str().c_str(),h_bckgr[j]);
};


qqq.str("");

qqq << "q2_0.475/" << "w_1." << 3125+250*i << "/" << "pip_mis_radcorr_sim_" << i;

//cout << qqq.str() << endl;
if(j<4)MyFile_sim->GetObject(qqq.str().c_str(),h_sim_pip[j]);
if(j>=3) {
MyFile_ind4->GetObject(qqq.str().c_str(),h_sim_pip[j]);

qqq.str("");

qqq << "q2_0.475/" << "w_1." << 3125+250*i << "/" << "pip_mis_radcorr_sim_bckg_" << i;
MyFile_ind4->GetObject(qqq.str().c_str(),h_bckgr_pip[j]);
};


qqq.str("");

qqq << "q2_0.475/" << "w_1." << 3125+250*i << "/" << "pr_mis_radcorr_sim_" << i;

//cout << qqq.str() << endl;
if(j<4)MyFile_sim->GetObject(qqq.str().c_str(),h_sim_pr[j]);
if(j>=3) {
MyFile_ind4->GetObject(qqq.str().c_str(),h_sim_pr[j]);

qqq.str("");

qqq << "q2_0.475/" << "w_1." << 3125+250*i << "/" << "pr_mis_radcorr_sim_bckg_" << i;
MyFile_ind4->GetObject(qqq.str().c_str(),h_bckgr_pr[j]);
};


qqq.str("");

qqq << "q2_0.475/" << "w_1." << 3125+250*i << "/" << "0_mis_radcorr_sim_" << i;

//cout << qqq.str() << endl;
if(j<4)MyFile_sim->GetObject(qqq.str().c_str(),h_sim_0[j]);
if(j>=3) {
MyFile_ind4->GetObject(qqq.str().c_str(),h_sim_0[j]);

qqq.str("");

qqq << "q2_0.475/" << "w_1." << 3125+250*i << "/" << "0_mis_radcorr_sim_bckg_" << i;
MyFile_ind4->GetObject(qqq.str().c_str(),h_bckgr_0[j]);
};

//MyFile_sim->GetObject(qqq.str().c_str(),h_sim[j]);

c->cd(j+1);
c->cd(j+1)->SetBottomMargin(0.18);
c->cd(j+1)->SetRightMargin(0.01);
c->cd(j+1)->SetLeftMargin(0.19);

//h_data->Draw();
h_sim[j]->SetLineColor(kRed);
h_data[j]->Rebin(4);
h_sim[j]->Rebin(4);
if(j>=3) {
h_bckgr[j]->Rebin(4);
if(j==4)h_bckgr[j]->Scale(7.2);
if(j==3)h_bckgr[j]->Scale(10.5);
h_sim[j]->Add(h_bckgr[j]);
};
h_sim[j]->Scale(h_data[j]->GetMaximum()/(h_sim[j]->GetMaximum()));
//h_sim[j]->Scale(h_data[j]->Integral(1,200)/(h_sim[j]->Integral(1,200)));
h_sim[j]->SetLineWidth(2);
h_data[j]->SetLineWidth(2);

qqq.str("");

qqq << "1." << 300+25*i << " < W < 1." << 325+25*i << " GeV";

h_sim[j]->SetTitle(qqq.str().c_str());

h_sim[j]->GetXaxis()->SetTitle("M_{#pi^{-}}^{2} (GeV^{2})");
h_sim[j]->GetXaxis()->SetLabelSize(0.07);
h_sim[j]->GetXaxis()->SetNdivisions(5);
h_sim[j]->GetXaxis()->SetTitleSize(0.075);
h_sim[j]->GetXaxis()->SetNoExponent(1);

h_sim[j]->GetYaxis()->SetTitle("counts");
h_sim[j]->GetYaxis()->SetLabelSize(0.07);
h_sim[j]->GetYaxis()->SetNdivisions(5);
h_sim[j]->GetYaxis()->SetTitleSize(0.075);
h_sim[j]->GetYaxis()->SetTitleOffset(1.35);





h_sim[j]->Draw();
h_data[j]->Draw("same");
TArrow *ar1 = new TArrow(0.06,(h_sim[j]->GetMaximum())/2.,0.06,0.,0.02,"|>");
ar1->SetLineWidth(2);
ar1->SetLineColor(kGreen+2);
ar1->SetFillColor(kGreen);
ar1->Draw();

TArrow *ar2 = new TArrow(-0.04,(h_sim[j]->GetMaximum())/2.,-0.04,0.,0.02,"|>");
ar2->SetLineWidth(2);
ar2->SetLineColor(kGreen+2);
ar2->SetFillColor(kGreen);
ar2->Draw();
//cout << h_data->GetNbinsX() << endl;


// pip


c->cd(j+1+5);
c->cd(j+1+5)->SetBottomMargin(0.18);
c->cd(j+1+5)->SetRightMargin(0.01);
c->cd(j+1+5)->SetLeftMargin(0.19);

h_data_pip[j]->Rebin(4);

h_sim_pip[j]->SetLineColor(kRed);
h_sim_pip[j]->Rebin(4);
if(j>=3) {
h_bckgr_pip[j]->Rebin(4);
if(j==4)h_bckgr_pip[j]->Scale(7.2);
if(j==3)h_bckgr_pip[j]->Scale(10.5);
h_sim_pip[j]->Add(h_bckgr_pip[j]);
};
h_sim_pip[j]->Scale(h_data_pip[j]->GetMaximum()/(h_sim_pip[j]->GetMaximum()));
//h_sim[j]->Scale(h_data[j]->Integral(1,200)/(h_sim[j]->Integral(1,200)));
h_sim_pip[j]->SetLineWidth(2);
h_data_pip[j]->SetLineWidth(2);

qqq.str("");

qqq << "1." << 300+25*i << " < W < 1." << 325+25*i << " GeV";

h_sim_pip[j]->SetTitle(qqq.str().c_str());

h_sim_pip[j]->GetXaxis()->SetTitle("M_{#pi^{+}}^{2} (GeV^{2})");
h_sim_pip[j]->GetXaxis()->SetLabelSize(0.07);
h_sim_pip[j]->GetXaxis()->SetNdivisions(5);
h_sim_pip[j]->GetXaxis()->SetTitleSize(0.075);
h_sim_pip[j]->GetXaxis()->SetNoExponent(1);

h_sim_pip[j]->GetYaxis()->SetTitle("counts");
h_sim_pip[j]->GetYaxis()->SetLabelSize(0.07);
h_sim_pip[j]->GetYaxis()->SetNdivisions(5);
h_sim_pip[j]->GetYaxis()->SetTitleSize(0.075);
h_sim_pip[j]->GetYaxis()->SetTitleOffset(1.35);





h_sim_pip[j]->Draw();

h_data_pip[j]->Draw("same");
qqq.str("");


TArrow *ar3 = new TArrow(0.06,(h_data_pip[j]->GetMaximum())/2.,0.06,0.,0.02,"|>");
ar3->SetLineWidth(2);
ar3->SetLineColor(kGreen+2);
ar3->SetFillColor(kGreen);
ar3->Draw();

TArrow *ar4 = new TArrow(-0.04,(h_data_pip[j]->GetMaximum())/2.,-0.04,0.,0.02,"|>");
ar4->SetLineWidth(2);
ar4->SetLineColor(kGreen+2);
ar4->SetFillColor(kGreen);
ar4->Draw();



// proton

c->cd(j+1+5+5);
c->cd(j+1+5+5)->SetBottomMargin(0.18);
c->cd(j+1+5+5)->SetRightMargin(0.01);
c->cd(j+1+5+5)->SetLeftMargin(0.19);

h_data_pr[j]->Rebin(4);

h_sim_pr[j]->SetLineColor(kRed);
h_sim_pr[j]->Rebin(4);
if(j>=3) {
h_bckgr_pr[j]->Rebin(4);
if(j==4)h_bckgr_pr[j]->Scale(7.2);
if(j==3)h_bckgr_pr[j]->Scale(10.5);
h_sim_pr[j]->Add(h_bckgr_pr[j]);
};
h_sim_pr[j]->Scale(h_data_pr[j]->GetMaximum()/(h_sim_pr[j]->GetMaximum()));
//h_sim[j]->Scale(h_data[j]->Integral(1,200)/(h_sim[j]->Integral(1,200)));
h_sim_pr[j]->SetLineWidth(2);
h_data_pr[j]->SetLineWidth(2);

qqq.str("");

qqq << "1." << 300+25*i << " < W < 1." << 325+25*i << " GeV";

h_sim_pr[j]->SetTitle(qqq.str().c_str());

h_sim_pr[j]->GetXaxis()->SetTitle("M_{p'}^{2} (GeV^{2})");
h_sim_pr[j]->GetXaxis()->SetLabelSize(0.07);
h_sim_pr[j]->GetXaxis()->SetNdivisions(5);
h_sim_pr[j]->GetXaxis()->SetTitleSize(0.075);
h_sim_pr[j]->GetXaxis()->SetNoExponent(1);

h_sim_pr[j]->GetYaxis()->SetTitle("counts");
h_sim_pr[j]->GetYaxis()->SetLabelSize(0.07);
h_sim_pr[j]->GetYaxis()->SetNdivisions(5);
h_sim_pr[j]->GetYaxis()->SetTitleSize(0.075);
h_sim_pr[j]->GetYaxis()->SetTitleOffset(1.35);





h_sim_pr[j]->Draw();


h_data_pr[j]->Draw("same");


TArrow *ar5 = new TArrow(0.882-0.04,(h_data_pr[j]->GetMaximum())/2.,0.882-0.04,0.,0.02,"|>");
ar5->SetLineWidth(2);
ar5->SetLineColor(kGreen+2);
ar5->SetFillColor(kGreen);
ar5->Draw();

TArrow *ar6 = new TArrow(0.882+0.04,(h_data_pr[j]->GetMaximum())/2.,0.882+0.04,0.,0.02,"|>");
ar6->SetLineWidth(2);
ar6->SetLineColor(kGreen+2);
ar6->SetFillColor(kGreen);
ar6->Draw();




// 0


c->cd(j+1+5+5+5);
c->cd(j+1+5+5+5)->SetBottomMargin(0.18);
c->cd(j+1+5+5+5)->SetRightMargin(0.01);
c->cd(j+1+5+5+5)->SetLeftMargin(0.19);

h_data_0[j]->Rebin(4);

h_sim_0[j]->SetLineColor(kRed);
h_sim_0[j]->Rebin(4);
if(j>=3) {
h_bckgr_0[j]->Rebin(4);
if(j==4)h_bckgr_0[j]->Scale(7.2);
if(j==3)h_bckgr_0[j]->Scale(10.5);
h_sim_0[j]->Add(h_bckgr_0[j]);
};
h_sim_0[j]->Scale(h_data_0[j]->GetMaximum()/(h_sim_0[j]->GetMaximum()));
//h_sim[j]->Scale(h_data[j]->Integral(1,200)/(h_sim[j]->Integral(1,200)));
h_sim_0[j]->SetLineWidth(2);
h_data_0[j]->SetLineWidth(2);

qqq.str("");

qqq << "1." << 300+25*i << " < W < 1." << 325+25*i << " GeV";

h_sim_0[j]->SetTitle(qqq.str().c_str());

h_sim_0[j]->GetXaxis()->SetTitle("M_{0}^{2} (GeV^{2})");
h_sim_0[j]->GetXaxis()->SetLabelSize(0.07);
h_sim_0[j]->GetXaxis()->SetNdivisions(5);
h_sim_0[j]->GetXaxis()->SetTitleSize(0.075);
h_sim_0[j]->GetXaxis()->SetNoExponent(1);
h_sim_0[j]->GetXaxis()->SetRangeUser(-0.03,0.03);
h_data_0[j]->GetXaxis()->SetRangeUser(-0.03,0.03);


h_sim_0[j]->GetYaxis()->SetTitle("counts");
h_sim_0[j]->GetYaxis()->SetLabelSize(0.07);
h_sim_0[j]->GetYaxis()->SetNdivisions(5);
h_sim_0[j]->GetYaxis()->SetTitleSize(0.075);
h_sim_0[j]->GetYaxis()->SetTitleOffset(1.35);





h_sim_0[j]->Draw();


h_data_0[j]->Draw("same");


TArrow *ar7 = new TArrow(-0.01,(h_data_0[j]->GetMaximum())/2.,-0.01,0.,0.02,"|>");
ar7->SetLineWidth(2);
ar7->SetLineColor(kGreen+2);
ar7->SetFillColor(kGreen);
ar7->Draw();

TArrow *ar8 = new TArrow(0.01,(h_data_0[j]->GetMaximum())/2.,0.01,0.,0.02,"|>");
ar8->SetLineWidth(2);
ar8->SetLineColor(kGreen+2);
ar8->SetFillColor(kGreen);
ar8->Draw();



};


c->Print("miss_mass.pdf");

}
