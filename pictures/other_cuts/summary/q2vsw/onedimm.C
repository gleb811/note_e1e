 void onedimm(){
 gROOT->SetStyle("Plain"); 
 gStyle->SetTitleY(50.);
 gStyle->SetTitleAlign(23);
 gStyle->SetTitleBorderSize(50.);
 gStyle->SetPadBottomMargin(0.14);
 gStyle->SetPadTopMargin(0.0); 
 gStyle->SetPadLeftMargin(0.2);
 gStyle->SetPadRightMargin(0.02);

  float wmax;
  short nbinmass,nbintheta,nbinpsi;
  wmax=1.3875;
  nbinmass=10;
  nbintheta=8;
  nbinpsi=6;
 
  TCanvas *can = new TCanvas("can","PLqOT",0,0,1000,1050); //
  can->SetWindowSize(1000,1000);
  can->SetWindowPosition(0,100);
  can->SetCanvasSize(950,950);
  can->SetBorderMode(0);
  

  

 can->Divide(3,4,0.001,0.01,0);
 

    can->cd(2);
  TLatex t; 
  t.SetTextSize(0.2);
  t.DrawLatex(0.,0.2,"#font[12]{Q}^{#font[42]{2}} #font[42]{= 0.425 GeV^{2}}");


std::ostringstream wtitle;

wtitle << "#font[12]{W = }" << "#font[42]{" <<  wmax << " GeV}";
  TLatex tw; 
  tw.SetTextSize(0.2);
  tw.DrawLatex(0.,0.6,wtitle.str().c_str());


std::ostringstream title;

 
  can->cd(4);
  can->cd(4)->SetBorderMode(0);
  
  
int j,i;


std::ostringstream wtitle;

wtitle << wmax;




 

  TMarker *mark = new TMarker();
   



std::ostringstream file3;   

file3 << "/home/gleb/e1e/e1e/2picross-sect/q204045/w_1375_14/xsec1d_mpippim_float.dat";
 cout << file3.str() << "\n";



int i;
 double sigma4[30],error4[30],theta4[30],errorx4[30];
 
 

std::ifstream sect4(file3.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i <= nbinmass-1; i++)
{
  sect4 >> theta4[i] >> sigma4[i] >> error4[i] >> errorx4[i];
  
  cout << theta4[i] << "  " << sigma4[i] << "  " << error4[i] << "  " << errorx4[i] << "\n";

};
   sect4.close();   
 
   TGraphErrors *Tg3 = new TGraphErrors(nbinmass,theta4,sigma4,errorx4,error4);
   
   Tg3->SetMarkerStyle(kFullCircle);
   Tg3->SetMarkerColor(1);
   Tg3->SetLineColor(1); 
//   Tg3->SetMaximum(33.);
   Tg3->GetXaxis()->SetLimits(0.25,wmax-0.938+0.04);

   Tg3->GetXaxis()->SetTitle("#font[12]{M}_{#pi^{+} #pi^{-}} #font[42]{(GeV)}");
   Tg3->GetXaxis()->SetTitleSize(0.07);
   Tg3->GetXaxis()->SetTitleOffset(0.85);
   Tg3->GetYaxis()->SetTitle("#frac{#font[42]{d}#Omega}{#font[42]{d}#font[12]{M}_{#pi^{+}#pi^{-}}} #font[42]{(#mubn/GeV)}");
   Tg3->GetYaxis()->SetTitleSize(0.06);
   Tg3->GetYaxis()->SetTitleOffset(1.4);   
   Tg3->SetMinimum(0.);
   
   Tg3->SetTitle(title.str().c_str());
   Tg3->Draw("AP");






























  can->cd(5);
  can->cd(5)->SetBorderMode(0);
  
  
std::ostringstream file4;  
file4 << "/home/gleb/e1e/e1e/2picross-sect/q204045/w_1375_14/xsec1d_mpippr_float.dat";
 cout << file4.str() << "\n";



 double sigma5[30],error5[30],theta5[30],errorx5[30];
 
 

std::ifstream sect5(file4.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i <= nbinmass-1; i++)
{
  sect5 >> theta5[i] >> sigma5[i] >> error5[i] >> errorx5[i];
  
  cout << theta5[i] << "  " << sigma5[i] << "  " << error5[i] << "  " << errorx5[i] << "\n";

};
   sect5.close();   
 
   TGraphErrors *Tg4 = new TGraphErrors(nbinmass,theta5,sigma5,errorx5,error5);
   
   Tg4->SetMarkerStyle(kFullCircle);
   Tg4->SetMarkerColor(1);
   Tg4->SetLineColor(1); 
//   Tg3->SetMaximum(33.);
   Tg4->GetXaxis()->SetLimits(1.04,wmax-0.138+0.04);
   Tg4->SetMinimum(0.);
 
   Tg4->GetXaxis()->SetTitle("#font[12]{M}_{#pi^{+} p} #font[42]{(GeV)}");
   Tg4->GetXaxis()->SetTitleSize(0.07);
   Tg4->GetXaxis()->SetTitleOffset(0.85);
   Tg4->GetYaxis()->SetTitle("#frac{#font[42]{d}#Omega}{#font[42]{d}#font[12]{M}_{#pi^{+}p}} #font[42]{(#mubn/GeV)}");
   Tg4->GetYaxis()->SetTitleSize(0.06);
   Tg4->GetYaxis()->SetTitleOffset(1.4);   
   Tg4->SetMinimum(0.);
 
   
   Tg4->SetTitle(title.str().c_str());
   Tg4->Draw("AP");







































































  can->cd(6);
  can->cd(6)->SetBorderMode(0);
std::ostringstream file4;  
file4 << "/home/gleb/e1e/e1e/2picross-sect/q204045/w_1375_14/xsec1d_mpimpr_float.dat";
 cout << file4.str() << "\n";



 double sigma5[30],error5[30],theta5[30],errorx5[30];
 
 

std::ifstream sect5(file4.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i <= nbinmass-1; i++)
{
  sect5 >> theta5[i] >> sigma5[i] >> error5[i] >> errorx5[i];
  
  cout << theta5[i] << "  " << sigma5[i] << "  " << error5[i] << "  " << errorx5[i] << "\n";

};
   sect5.close();   
 
   TGraphErrors *Tg5 = new TGraphErrors(nbinmass,theta5,sigma5,errorx5,error5);
   
   Tg5->SetMarkerStyle(kFullCircle);
   Tg5->SetMarkerColor(1);
   Tg5->SetLineColor(1); 
//   Tg3->SetMaximum(33.);
   Tg5->GetXaxis()->SetLimits(1.04,wmax-0.138+0.04);
   Tg5->SetMinimum(0.);
   Tg5->GetXaxis()->SetTitle("#font[12]{M}_{#pi^{-} p} #font[42]{(GeV)}");
   Tg5->GetXaxis()->SetTitleSize(0.07);
   Tg5->GetXaxis()->SetTitleOffset(0.85);
   Tg5->GetYaxis()->SetTitle("#frac{#font[42]{d}#Omega}{#font[42]{d}#font[12]{M}_{#pi^{-}p}} #font[42]{(#mubn/GeV)}");
   Tg5->GetYaxis()->SetTitleSize(0.06);
   Tg5->GetYaxis()->SetTitleOffset(1.4);      
   Tg5->SetTitle(title.str().c_str());
   Tg5->Draw("AP");




























  can->cd(7);
  can->cd(7)->SetBorderMode(0);
std::ostringstream file4;  
file4 << "/home/gleb/e1e/e1e/2picross-sect/q204045/w_1375_14/xsec1d_theta_pim_float.dat";
 cout << file4.str() << "\n";



 double sigma5[30],error5[30],theta5[30],errorx5[30];
 
 

std::ifstream sect5(file4.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i <= nbintheta-1; i++)
{
  sect5 >> theta5[i] >> sigma5[i] >> error5[i] >> errorx5[i];
  
  cout << theta5[i] << "  " << sigma5[i] << "  " << error5[i] << "  " << errorx5[i] << "\n";

};
   sect5.close();   
 
   TGraphErrors *Tg6 = new TGraphErrors(nbintheta,theta5,sigma5,errorx5,error5);
   
   Tg6->SetMarkerStyle(kFullCircle);
   Tg6->SetMarkerColor(1);
   Tg6->SetLineColor(1); 
//   Tg3->SetMaximum(33.);
   Tg6->GetXaxis()->SetLimits(0.,180.);
   Tg6->SetMinimum(0.);
   Tg6->GetXaxis()->SetTitle("#theta_{#pi^{-}} #font[42]{(deg)}");
   Tg6->GetXaxis()->SetTitleSize(0.07);
   Tg6->GetXaxis()->SetTitleOffset(0.85);
   Tg6->GetYaxis()->SetTitle("#frac{#font[42]{d}#Omega}{#font[42]{d(-cos}(#theta_{#pi^{-}}))} #font[42]{(#mubn/rad)}");
   Tg6->GetYaxis()->SetTitleSize(0.06);
   Tg6->GetYaxis()->SetTitleOffset(1.4);      
   Tg6->SetTitle(title.str().c_str());
   Tg6->Draw("AP");




























































  can->cd(8);
  can->cd(8)->SetBorderMode(0);
std::ostringstream file4;  
file4 << "/home/gleb/e1e/e1e/2picross-sect/q204045/w_1375_14/xsec1d_theta_pip_float.dat";
 cout << file4.str() << "\n";



 double sigma5[30],error5[30],theta5[30],errorx5[30];
 
 

std::ifstream sect5(file4.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i <= nbintheta-1; i++)
{
  sect5 >> theta5[i] >> sigma5[i] >> error5[i] >> errorx5[i];
  
  cout << theta5[i] << "  " << sigma5[i] << "  " << error5[i] << "  " << errorx5[i] << "\n";

};
   sect5.close();   
 
   TGraphErrors *Tg7 = new TGraphErrors(nbintheta,theta5,sigma5,errorx5,error5);
   
   Tg7->SetMarkerStyle(kFullCircle);
   Tg7->SetMarkerColor(1);
   Tg7->SetLineColor(1); 
//   Tg3->SetMaximum(33.);
   Tg7->GetXaxis()->SetLimits(0.,180.);
   Tg7->SetMinimum(0.);
   Tg7->GetXaxis()->SetTitle("#theta_{#pi^{+}} #font[42]{(deg)}");
   Tg7->GetXaxis()->SetTitleSize(0.07);
   Tg7->GetXaxis()->SetTitleOffset(0.85);
   Tg7->GetYaxis()->SetTitle("#frac{#font[42]{d}#Omega}{#font[42]{d(-cos}(#theta_{#pi^{+}}))} #font[42]{(#mubn/rad)}");
   Tg7->GetYaxis()->SetTitleSize(0.06);
   Tg7->GetYaxis()->SetTitleOffset(1.4);      
   Tg7->SetTitle(title.str().c_str());
   Tg7->Draw("AP");




























  can->cd(9);
  can->cd(9)->SetBorderMode(0);
std::ostringstream file4;  
file4 << "/home/gleb/e1e/e1e/2picross-sect/q204045/w_1375_14/xsec1d_theta_pr_float.dat";
 cout << file4.str() << "\n";



 double sigma5[30],error5[30],theta5[30],errorx5[30];
 
 

std::ifstream sect5(file4.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i <= nbintheta-1; i++)
{
  sect5 >> theta5[i] >> sigma5[i] >> error5[i] >> errorx5[i];
  
  cout << theta5[i] << "  " << sigma5[i] << "  " << error5[i] << "  " << errorx5[i] << "\n";

};
   sect5.close();   
 
   TGraphErrors *Tg8 = new TGraphErrors(nbintheta,theta5,sigma5,errorx5,error5);
   
   Tg8->SetMarkerStyle(kFullCircle);
   Tg8->SetMarkerColor(1);
   Tg8->SetLineColor(1); 
//   Tg3->SetMaximum(33.);
   Tg8->GetXaxis()->SetLimits(0.,180.);
   Tg8->SetMinimum(0.);
   Tg8->GetXaxis()->SetTitle("#theta_{p} #font[42]{(deg)}");
   Tg8->GetXaxis()->SetTitleSize(0.07);
   Tg8->GetXaxis()->SetTitleOffset(0.85);
   Tg8->GetYaxis()->SetTitle("#frac{#font[42]{d}#Omega}{#font[42]{d(-cos}(#theta_{p}))} #font[42]{(#mubn/rad)}");
   Tg8->GetYaxis()->SetTitleSize(0.06);
   Tg8->GetYaxis()->SetTitleOffset(1.4);      
   Tg8->SetTitle(title.str().c_str());
   Tg8->Draw("AP");














































  can->cd(10);
  can->cd(10)->SetBorderMode(0);
std::ostringstream file4;  
file4 << "/home/gleb/e1e/e1e/2picross-sect/q204045/w_1375_14/xsec1d_psi_pim_float.dat";
 cout << file4.str() << "\n";



 double sigma5[30],error5[30],theta5[30],errorx5[30],sigmaavr;
 
 

std::ifstream sect5(file4.str().c_str());
//  std::ifstream sect1("sect1.dat");
sigmaavr=0.;
for (i= 0; i <= nbinpsi-1; i++)
{
  sect5 >> theta5[i] >> sigma5[i] >> error5[i] >> errorx5[i];
  
  cout << theta5[i] << "  " << sigma5[i] << "  " << error5[i] << "  " << errorx5[i] << "\n";
  sigmaavr = sigmaavr + sigma5[i];
};
   sect5.close();   
   
   
   sigmaavr = sigmaavr/nbinpsi;
 
 
   TGraphErrors *Tg9 = new TGraphErrors(nbinpsi,theta5,sigma5,errorx5,error5);
   
   Tg9->SetMarkerStyle(kFullCircle);
   Tg9->SetMarkerColor(1);
   Tg9->SetLineColor(1); 
//   Tg3->SetMaximum(33.);
   Tg9->GetXaxis()->SetLimits(0.,360.);
   Tg9->SetMinimum(0.);
   Tg9->GetXaxis()->SetTitle("#alpha_{([#pi^{-}p][#pi^{+}p_{f}])} #font[42]{(deg)}");
   Tg9->GetXaxis()->SetTitleSize(0.07);
   Tg9->GetXaxis()->SetTitleOffset(0.85);
   Tg9->GetYaxis()->SetTitle("#frac{#font[42]{d}#Omega}{#font[42]{d}#alpha_{([#pi^{-}p][#pi^{+}p_{f}])}} #font[42]{(#mubn/rad)}");
   Tg9->GetYaxis()->SetTitleSize(0.06);
   Tg9->GetYaxis()->SetTitleOffset(1.4);      
   Tg9->SetTitle(title.str().c_str());
   Tg9->Draw("AP");





















































  can->cd(11);
  can->cd(11)->SetBorderMode(0);
std::ostringstream file4;  
file4 << "/home/gleb/e1e/e1e/2picross-sect/q204045/w_1375_14/xsec1d_psi_pip_float.dat";
 cout << file4.str() << "\n";



 double sigma5[30],error5[30],theta5[30],errorx5[30],sigmaavr;
 
 

std::ifstream sect5(file4.str().c_str());
//  std::ifstream sect1("sect1.dat");
sigmaavr=0.;
for (i= 0; i <= nbinpsi-1; i++)
{
  sect5 >> theta5[i] >> sigma5[i] >> error5[i] >> errorx5[i];
  
  cout << theta5[i] << "  " << sigma5[i] << "  " << error5[i] << "  " << errorx5[i] << "\n";
  sigmaavr = sigmaavr + sigma5[i];
};
   sect5.close();   
   
   
   sigmaavr = sigmaavr/nbinpsi;
 
 
   TGraphErrors *Tg10 = new TGraphErrors(nbinpsi,theta5,sigma5,errorx5,error5);
   
   Tg10->SetMarkerStyle(kFullCircle);
   Tg10->SetMarkerColor(1);
   Tg10->SetLineColor(1); 
//   Tg3->SetMaximum(33.);
   Tg10->GetXaxis()->SetLimits(0.,360.);
   Tg10->SetMinimum(0.);
   Tg10->GetXaxis()->SetTitle("#alpha_{([#pi^{+}p][#pi^{-}p_{f}])} #font[42]{(deg)}");
   Tg10->GetXaxis()->SetTitleSize(0.07);
   Tg10->GetXaxis()->SetTitleOffset(0.85);
   Tg10->GetYaxis()->SetTitle("#frac{#font[42]{d}#Omega}{#font[42]{d}#alpha_{([#pi^{+}p][#pi^{-}p_{f}])}} #font[42]{(#mubn/rad)}");
   Tg10->GetYaxis()->SetTitleSize(0.06);
   Tg10->GetYaxis()->SetTitleOffset(1.4);      
   Tg10->SetTitle(title.str().c_str());
   Tg10->Draw("AP");
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
     can->cd(12);
  can->cd(12)->SetBorderMode(0);
std::ostringstream file4;  
file4 << "/home/gleb/e1e/e1e/2picross-sect/q204045/w_1375_14/xsec1d_psi_pr_float.dat";
 cout << file4.str() << "\n";



 double sigma5[30],error5[30],theta5[30],errorx5[30],sigmaavr;
 
 

std::ifstream sect5(file4.str().c_str());
//  std::ifstream sect1("sect1.dat");
sigmaavr=0.;
for (i= 0; i <= nbinpsi-1; i++)
{
  sect5 >> theta5[i] >> sigma5[i] >> error5[i] >> errorx5[i];
  
  cout << theta5[i] << "  " << sigma5[i] << "  " << error5[i] << "  " << errorx5[i] << "\n";
  sigmaavr = sigmaavr + sigma5[i];
};
   sect5.close();   
   
   
   sigmaavr = sigmaavr/nbinpsi;
 
 
   TGraphErrors *Tg11 = new TGraphErrors(nbinpsi,theta5,sigma5,errorx5,error5);
   
   Tg11->SetMarkerStyle(kFullCircle);
   Tg11->SetMarkerColor(1);
   Tg11->SetLineColor(1); 
//   Tg3->SetMaximum(33.);
   Tg11->GetXaxis()->SetLimits(0.,360.);
   Tg11->SetMinimum(0.);
   Tg11->GetXaxis()->SetTitle("#alpha_{([p_{f}p][#pi^{+}#pi^{-}])} #font[42]{(deg)}");
   Tg11->GetXaxis()->SetTitleSize(0.07);
   Tg11->GetXaxis()->SetTitleOffset(0.85);
   Tg11->GetYaxis()->SetTitle("#frac{#font[42]{d}#Omega}{#font[42]{d}#alpha_{([p_{f}p][#pi^{+}#pi^{-}])}} #font[42]{(#mubn/rad)}");
   Tg11->GetYaxis()->SetTitleSize(0.06);
   Tg11->GetYaxis()->SetTitleOffset(1.4);      
   Tg11->SetTitle(title.str().c_str());
   Tg11->Draw("AP");

 std::ostringstream filename;

filename << "q20425w" <<  wmax*10000 << ".eps";

can->Print(filename.str().c_str());

 return;
}
