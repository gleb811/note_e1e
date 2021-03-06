void b_vs_p_no_time_corr_new() {

gStyle->SetOptStat(0);
gStyle ->SetOptFit(0);
gStyle->SetStatY(0.9);                
gStyle->SetStatX(0.795);
gStyle->SetStatW(0.4);                
gStyle->SetStatH(0.01);
gStyle->SetStatFontSize(0.01);
gStyle->SetStatFont(610);
gStyle->SetStatBorderSize(1.);
gStyle->SetStatStyle(0);
gROOT->ForceStyle();
gStyle ->SetOptLogz(1);
gStyle->SetTitleSize(0.1,"t");

gStyle->SetStatFontSize(0.15);
gStyle->SetTitleAlign(33); 
gStyle->SetTitleX(.75);
gStyle->SetTitleY(1.02);


TFile *MyFile = new TFile("data_new.root","READ");
TH1 *hist1;
TH1 *hist2;
ostringstream qqq;
TCanvas *c = new TCanvas ("b_vs_p","b_vs_p",0,0,600,800);
c->Divide(2,4,0,0);

for (Int_t i=40; i<=47; i++) {

c->cd(i-39);

c->cd(i)->SetBottomMargin(0.25);
c->cd(i)->SetTopMargin(0.1);
c->cd(i)->SetLeftMargin(0.2);
c->cd(i)->SetRightMargin(0.2);
c->cd(i)->SetBorderMode(0);
c->cd(i)->SetFrameBorderMode(0);

//TPaveStats *s = (TPaveStats*) gPad->GetPrimitive("stats");
//s->SetTextSize(0.1); 
//s->SetX1NDC(0.5);
//s->SetY1NDC(0.5);

qqq.str("");
qqq << "s1_beta_vs_pip/beta_vs_p_pip_1_" << i;
MyFile->GetObject(qqq.str().c_str(),hist1); 

//hist1->SetMinimum((hist1->Integral())/100000.);
//hist1->Draw("colz");

qqq.str("");
qqq << "paddle " << i;
hist1->SetTitle(qqq.str().c_str());



qqq.str("");
qqq << "s1_beta_vs_p/beta_vs_p_p_1_" << i;
MyFile->GetObject(qqq.str().c_str(),hist2); 


//hist2->SetMinimum((hist1->Integral())/100000.);


hist2->SetTitle("");
//hist2->Draw("same colz");

//hist1->Add(hist2);

hist1->SetMinimum((hist1->Integral())/500000.);
hist1->SetMaximum((hist1->Integral())/5000.);






//hist1->Draw("colz");

hist1->GetYaxis()->SetLabelSize(0.1);
hist1->GetYaxis()->SetNdivisions(4);
hist1->GetXaxis()->SetNdivisions(6);
hist1->GetXaxis()->SetLabelSize(0.1);
//hist->GetXaxis()->SetTitle("#theta, deg");
hist1->GetXaxis()->SetTitle("P (GeV)");
hist1->GetXaxis()->SetTitleSize(0.1);
hist1->GetYaxis()->SetTitle("#beta (no units)");
hist1->GetYaxis()->SetTitleSize(0.1);
hist1->GetYaxis()->SetTitleOffset(1.);
hist1->GetXaxis()->SetTitleOffset(0.9);

hist1->GetZaxis()->SetLabelSize(0.07);
//hist1->UseCurrentStyle();


hist1->Draw("colz");

qqq.str("");
qqq << hist1->GetEntries();
 TText *t = new TText();
//   t->SetTextAlign(22);
//   t->SetTextColor(kRed+2);
//   t->SetTextFont(43);
   t->SetTextSize(0.1);
//   t->SetTextAngle(45);
//   t->AddBox(0.5,0.8,1.0,1.3);
//   t->DrawText(0.8,1.3,qqq.str().c_str());
TPaveText *text1 = new TPaveText(0.8, 1.3, 0.8+1.2, 1.3+0.2);
text1->SetBorderSize(1);
text1->SetFillColor(kWhite);
text1->SetFillStyle(0);

//text1->UseCurrentStyle();
text1->SetLineColor(1);
text1->AddText(qqq.str().c_str());
text1->SetTextSizePixels(30); 
text1->Draw();

//TPaveStats *s = (TPaveStats*)(c->cd(i))->GetPrimitive("stats");
//s->SetTextSize(0.1); 
//s->SetX1NDC(0.5);
//s->SetY1NDC(0.5);


TF1 *f1 = new TF1("f1",beta_p,0.,2.,1);
  f1->SetLineColor(kBlack);
 f1->SetLineWidth(1.2);
  f1->SetLineStyle(2);
//  f1->Draw("same");

if (i < 49) {  
TF1 *f3 = new TF1("f3",beta_p_high,0.,2.,1);
  f3->SetLineColor(kRed);
 f3->SetLineWidth(1.2);
  f3->SetLineStyle(2);
//  f3->Draw("same"); 
  
TF1 *f4 = new TF1("f4",beta_p_low,0.,2.,1);
  f4->SetLineColor(kRed);
 f4->SetLineWidth(1.2);
  f4->SetLineStyle(2);
//  f4->Draw("same");    

};
  
TF1 *f2 = new TF1("f2",beta_pip,0.,2.,1);
  f2->SetLineColor(kBlack);
 f2->SetLineWidth(1.2);
 f2->SetLineStyle(2);
  f2->Draw("same");  

//if (i < 40) {
TF1 *f5 = new TF1("f5",beta_pip_high,0.,2.,1);
  f5->SetLineColor(6);
 f5->SetLineWidth(1.2);
 f5->SetLineStyle(2);
  f5->Draw("same"); 
//cout << hist2->Integral() << endl;

TF1 *f6 = new TF1("f6",beta_pip_low,0.,2.,1);
  f6->SetLineColor(6);
 f6->SetLineWidth(1.2);
 f6->SetLineStyle(2);
  f6->Draw("same"); 
//  } else {

  
TF1 *f7 = new TF1("f7",beta_high_paddles,0.,2.,1);
  f7->SetLineColor(kOrange-3);
 f7->SetLineWidth(1.2);
 f7->SetLineStyle(2);
//  f7->Draw("same"); 
//  };

};





c->SaveAs("b_vs_p_positiv_no_time_corr_new.pdf");

}


double beta_p(double *x, double *par) {
   double s,mp;
  mp=0.938272;
 //  mp=1.875612793;
  // mp=0.;
    s = x[0]/sqrt(mp*mp+x[0]*x[0]);
       return s;
};

double beta_p_high(double *x, double *par) {
   double s,mp;
  mp=0.938272;
 //  mp=1.875612793;
  // mp=0.;
  s = ((x[0]/(sqrt(x[0]*x[0]+0.938*0.938))+0.02)*(1.2+0.92*x[0])/(1.+x[0]));
//cout << s << endl;
       return s;
};

double beta_p_low(double *x, double *par) {
   double s,mp;
  mp=0.938272;
 //  mp=1.875612793;
  // mp=0.;
  s = ((x[0]/(sqrt(x[0]*x[0]+0.938*0.938))-0.05)/((1.+x[0])/(0.9+1.06*x[0])));
//cout << s << endl;
       return s;
};

double beta_pip(double *x, double *par) {
   double s,mp;
  mp=0.139;
 //  mp=1.875612793;
  // mp=0.;
    s = x[0]/sqrt(mp*mp+x[0]*x[0]);
       return s;
};

double beta_pip_high(double *x, double *par) {
   double s,mp;
  mp=0.139;
 //  mp=1.875612793;
  // mp=0.;
    s =(206.- x[0]- 0.02);
    s = s*(pow(((200.-x[0])/(200.+x[0])),0.7)*(x[0]+0.05));
    s = s/sqrt((x[0]+0.05)*(x[0]+0.05)+0.019);
    s = s/(200.+x[0]+0.02) + 0.02; 
       return s;
};
       
double beta_pip_low(double *x, double *par) {
   double s,mp;
  mp=0.139;
 //  mp=1.875612793;
  // mp=0.;
  s =  ((((1.+5.*1.07*(x[0]-0.07))*(x[0]-0.07))))/sqrt((x[0]-0.07)*(x[0]-0.07)+0.138*0.138)/(1+5.*(x[0]-0.07))-0.1;
//    s =(206.- x[0]- 0.02);
//    s = s*(pow(((200.-x[0])/(200.+x[0])),0.7)*(x[0]+0.05));
//    s = s/sqrt((x[0]+0.05)*(x[0]+0.05)+0.019);
//    s = s/(200.+x[0]+0.02) + 0.02; 
       return s;       
       
};

double beta_high_paddles(double *x, double *par) {
   double s;
    s = x[0]/sqrt(x[0]*x[0]+0.938*0.938) + 0.03;
    s = s*(1.2+0.92*x[0])/(1+x[0]);
//    s = (1+5*1.4*(x[0]-0.07))/(1+5*(x[0]-0.07));
//    s = s*(x[0]-0.07)/sqrt((x[0]-0.07)*(x[0]-0.07)+0.138*0.138);
//    s = s - 0.4;
       return s;       
       
};

