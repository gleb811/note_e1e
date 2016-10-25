void newdata(){
 gStyle->SetTitleX(0.5);
 gStyle->SetTitleY(0.87);
 gStyle->SetTitleAlign(23);
 gStyle->SetTitleBorderSize(0);
  
 cout << "\nPlotXsec started.\n";
 
  TCanvas *can = new TCanvas("can","PLqOT",50,50,400,300); //
  can->SetFillColor(0);
 // can->SetWindowSize(500,350);
//  can->SetCanvasSize(500,350);

  can->SetBorderMode(0);
  can->cd(1)->SetFrameBorderMode(0);
can->cd(1)->SetBottomMargin(0.17);
can->cd(1)->SetTopMargin(0.03);
can->cd(1)->SetLeftMargin(0.15);
can->cd(1)->SetRightMargin(0.05);
can->cd(1)->SetFrameBorderMode(0);
  
  
int j,i;

std::ostringstream file;
std::ostringstream title;





std::ostringstream file2;   
file2 << "ripani.dat";
 cout << file2.str() << "\n";




 float sigma3[30],error3[30],theta3[30],errorx3[30];
 
 

std::ifstream sect3(file2.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i <= 19; i++)
{
  sect3 >> theta3[i] >> sigma3[i] >> error3[i] >> errorx3[i];
  
//  sigma[i-20]=sigma[i-20]*2.0;

 cout << theta3[i] << "  " << sigma3[i] << "  " << error3[i] << "\n";

}
 sect3.close();   
 
   TGraphErrors *Tg2 = new TGraphErrors(20,theta3,sigma3,errorx3,error3);
   
   Tg2->SetMarkerStyle(29);
   Tg2->SetMarkerColor(1);
   Tg2->SetLineColor(1);
   Tg2->SetMarkerSize(2.);    
   Tg2->SetMaximum(65.);
   Tg2->GetXaxis()->SetLimits(1.3,1.9);   
   Tg2->SetMinimum(0.);
   
   Tg2->SetTitle(title.str().c_str());
   Tg2->GetXaxis()->SetTitle("W (GeV)");
Tg2->GetYaxis()->SetTitle("#sigma (#mubn)");
Tg2->GetXaxis()->SetLabelSize(0.07);
Tg2->GetYaxis()->SetLabelSize(0.07);
Tg2->GetXaxis()->SetTitleSize(0.07);
Tg2->GetXaxis()->SetTitleOffset(1.1);
Tg2->GetYaxis()->SetTitleSize(0.07);
Tg2->GetYaxis()->SetTitleOffset(1.);
   Tg2->Draw("AP");
  


  TMarker *mark = new TMarker();
   
   mark->SetMarkerStyle(29);
   mark->SetMarkerColor(1);
   mark->SetMarkerSize(2);   
   mark->DrawMarker(1.65,3.);

   TLatex t;
//   t.SetTextAlign(33);
   t.SetTextSize(0.04);
   t.DrawLatex(1.675,2.,"M. Ripani Q^{2} = 0.65 GeV^{2}");
   
   
  TMarker *mark1 = new TMarker();
   
   mark1->SetMarkerStyle(26);
   mark1->SetMarkerColor(1);
   mark1->DrawMarker(1.65,7.);
   mark1->SetMarkerSize(2); 

   TLatex t;
//   t.SetTextAlign(33);
   t.SetTextSize(0.04);
   t.DrawLatex(1.68,5.5,"e1e Q^{2} = 0.625 GeV^{2}");  
   
    
   
  TMarker *mark2 = new TMarker();
   
   mark2->SetMarkerStyle(25);
   mark2->SetMarkerColor(1);
//   mark2->DrawMarker(1.65,3.);
   mark2->SetMarkerSize(2); 
   TLatex t;
//   t.SetTextAlign(33);
   t.SetTextSize(0.04);
//   t.DrawLatex(1.68,2.5,"e1e Q^{2} = 0.675 GeV^{2}");   
   
   
   
   
  TMarker *mark3 = new TMarker();
   
   mark3->SetMarkerStyle(24);
   mark3->SetMarkerColor(1);
//   mark3->DrawMarker(1.42,5.);
   mark3->SetMarkerSize(2);
   TLatex t;
//   t.SetTextAlign(33);
   t.SetTextSize(0.04);
//   t.DrawLatex(1.45,4.5,"e1e Q^{2} = 0.725 GeV^{2}");  
   
   
   
  TMarker *mark4 = new TMarker();
   
   mark4->SetMarkerStyle(32);
   mark4->SetMarkerColor(1);
//   mark4->DrawMarker(1.42,3.);
   mark4->SetMarkerSize(2);
   TLatex t;
//   t.SetTextAlign(33);
   t.SetTextSize(0.04);
//   t.DrawLatex(1.45,2.5,"e1e Q^{2} = 0.775 GeV^{2}"); 
   
   
   
  TMarker *mark5 = new TMarker();
   
   mark5->SetMarkerStyle(27);
   mark5->SetMarkerColor(1);
   mark5->DrawMarker(1.65,10.);
   mark5->SetMarkerSize(2); 
   TLatex t;
//   t.SetTextAlign(33);
   t.SetTextSize(0.04);
   t.DrawLatex(1.68,8.5,"e1e Q^{2} = 0.575 GeV^{2}");   
   
   
  TMarker *mark6 = new TMarker();
   
   mark6->SetMarkerStyle(kFullCircle);
   mark6->SetMarkerColor(1);
   mark6->DrawMarker(1.65,12.2);
   mark6->SetMarkerSize(2); 
   TLatex t;
//   t.SetTextAlign(33);
   t.SetTextSize(0.04);
   t.DrawLatex(1.68,11.5,"e1e Q^{2} = 0.525 GeV^{2}");   
   
   
   
  TMarker *mark7 = new TMarker();
   
   mark7->SetMarkerStyle(28);
   mark7->SetMarkerSize(1);   
   mark7->SetMarkerColor(1);
   mark7->DrawMarker(1.65,15.5);
   mark7->SetMarkerSize(2);
   TLatex t;
//   t.SetTextAlign(33);
   t.SetTextSize(0.04);
   t.DrawLatex(1.68,14.5,"e1e Q^{2} = 0.475 GeV^{2}");       
    
           
  TMarker *mark8 = new TMarker();
   
   mark8->SetMarkerStyle(31);
   mark8->SetMarkerSize(2);   
   mark8->SetMarkerColor(1);
//   mark8->DrawMarker(1.65,16.);

   TLatex t;
//   t.SetTextAlign(33);
   t.SetTextSize(0.04);
//   t.DrawLatex(1.68,15.5,"e1e Q^{2} = 0.425 GeV^{2}");  
 

std::ostringstream file3;   

file3 << "total_0625.txt";
 cout << file3.str() << "\n";



int i;
 float sigma4[30],error4[30],theta4[30],errorx4[30];
 
 

std::ifstream sect4(file3.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i < 9; i++)
{
  sect4 >> theta4[i] >> sigma4[i] >> error4[i];
  
//  sigma[i-20]=sigma[i-20]*2.0;

 cout << theta4[i] << "  " << sigma4[i] << "  " << error4[i] << "\n";

}
 sect4.close();   
 
   TGraphErrors *Tg3 = new TGraphErrors(20,theta4,sigma4,errorx4,error4);
   
   Tg3->SetMarkerStyle(26);
   Tg3->SetMarkerColor(1);
   Tg3->SetLineColor(1); 
   Tg3->SetMaximum(33.);
   Tg3->GetXaxis()->SetLimits(1.3,1.9);
   Tg3->SetMinimum(0.);
   
   Tg3->SetTitle(title.str().c_str());
   Tg3->Draw("PS");



std::ostringstream file4;

file4 << "/home/gleb/e1e/e1e/2picross-sect/q206507/jopa";
 cout << file4.str() << "\n";



int i;
 float sigma5[30],error5[30],theta5[30],errorx5[30];
 
 

std::ifstream sect5(file4.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i <= 19; i++)
{
  sect5 >> theta5[i] >> sigma5[i] >> error5[i];
  
//  sigma[i-20]=sigma[i-20]*2.0;

 cout << theta5[i] << "  " << sigma5[i] << "  " << error5[i] << "\n";
 errorx5[i]=0.;
}
 sect5.close();   
 
   TGraphErrors *Tg4 = new TGraphErrors(20,theta5,sigma5,errorx5,error5);
   
   Tg4->SetMarkerStyle(25);
   Tg4->SetMarkerColor(1);
   Tg4->SetLineColor(1); 
   Tg4->SetMaximum(33.);
   Tg4->GetXaxis()->SetLimits(1.3,1.9);
   Tg4->SetMinimum(0.);
   
   Tg4->SetTitle(title.str().c_str());
//   Tg4->Draw("PS");



























































std::ostringstream file5;

file5 << "/home/gleb/e1e/e1e/2picross-sect/q207075/jopa";
 cout << file5.str() << "\n";



int i;
 float sigma6[30],error6[30],theta6[30],errorx6[30];
 
 

std::ifstream sect6(file5.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i <= 19; i++)
{
  sect6 >> theta6[i] >> sigma6[i] >> error6[i];
  
//  sigma[i-20]=sigma[i-20]*2.0;

 cout << theta6[i] << "  " << sigma6[i] << "  " << error6[i] << "\n";
 errorx6[i]=0.;
}
 sect6.close();   
 
   TGraphErrors *Tg5 = new TGraphErrors(20,theta6,sigma6,errorx6,error6);
   
   Tg5->SetMarkerStyle(24);
   Tg5->SetMarkerColor(1);
   Tg5->SetLineColor(1); 
   Tg5->SetMaximum(33.);
   Tg5->GetXaxis()->SetLimits(1.3,1.9);
   Tg5->SetMinimum(0.);
   
   Tg5->SetTitle(title.str().c_str());
//   Tg5->Draw("PS");
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
std::ostringstream file6;

file6 << "/home/gleb/e1e/e1e/2picross-sect/q207508/jopa";
 cout << file6.str() << "\n";



int i;
 float sigma7[30],error7[30],theta7[30],errorx7[30];
 
 

std::ifstream sect7(file6.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i <= 19; i++)
{
  sect7 >> theta7[i] >> sigma7[i] >> error7[i];
  
//  sigma[i-20]=sigma[i-20]*2.0;

 cout << theta7[i] << "  " << sigma7[i] << "  " << error7[i] << "\n";
 errorx7[i]=0.;
}
 sect7.close();   
 
   TGraphErrors *Tg6 = new TGraphErrors(20,theta7,sigma7,errorx7,error7);
   
   Tg6->SetMarkerStyle(32);
   Tg6->SetMarkerColor(1);
   Tg6->SetLineColor(1); 
   Tg6->SetMaximum(33.);
   Tg6->GetXaxis()->SetLimits(1.3,1.9);
   Tg6->SetMinimum(0.);
   
   Tg6->SetTitle(title.str().c_str());
//   Tg6->Draw("PS");   












































std::ostringstream file7;

file7 << "total_0575.txt";
 cout << file7.str() << "\n";



int i;
 float sigma8[30],error8[30],theta8[30],errorx8[30];
 
 

std::ifstream sect8(file7.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i < 9; i++)
{
  sect8 >> theta8[i] >> sigma8[i] >> error8[i];
  
//  sigma[i-20]=sigma[i-20]*2.0;

 cout << theta8[i] << "  " << sigma8[i] << "  " << error8[i] << "\n";
 errorx8[i]=0.;
}
 sect8.close();   
 
   TGraphErrors *Tg7 = new TGraphErrors(20,theta8,sigma8,errorx8,error8);
   
   Tg7->SetMarkerStyle(27);
   Tg7->SetMarkerColor(1);
   Tg7->SetLineColor(1); 
   Tg7->SetMaximum(33.);
   Tg7->GetXaxis()->SetLimits(1.3,1.9);
   Tg7->SetMinimum(0.);
   
   Tg7->SetTitle(title.str().c_str());
   Tg7->Draw("PS"); 
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
     








std::ostringstream file9;

file9 << "total_0525.txt";
 cout << file9.str() << "\n";



int i;
 float sigma10[30],error10[30],theta10[30],errorx10[30];
 
 

std::ifstream sect10(file9.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i <9; i++)
{
  sect10 >> theta10[i] >> sigma10[i] >> error10[i];
  
//  sigma[i-20]=sigma[i-20]*2.0;

 cout << theta10[i] << "  " << sigma10[i] << "  " << error10[i] << "\n";
 errorx10[i]=0.;
}
 sect10.close();   
 
   TGraphErrors *Tg9 = new TGraphErrors(20,theta10,sigma10,errorx10,error10);
   
   Tg9->SetMarkerStyle(kFullCircle);
   Tg9->SetMarkerColor(1);
   Tg9->SetLineColor(1); 
   Tg9->SetMaximum(33.);
   Tg9->GetXaxis()->SetLimits(1.3,1.9);
   Tg9->SetMinimum(0.);
   
   Tg9->SetTitle(title.str().c_str());
   Tg9->Draw("PS"); 







































std::ostringstream file8;

file8 << "total_0475.txt";
 cout << file8.str() << "\n";



int i;
 float sigma9[30],error9[30],theta9[30],errorx9[30];
 
 

std::ifstream sect9(file8.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i < 9; i++)
{
  sect9 >> theta9[i] >> sigma9[i] >> error9[i];
  
//  sigma[i-20]=sigma[i-20]*2.0;

 cout << theta9[i] << "  " << sigma9[i] << "  " << error9[i] << "\n";
 errorx9[i]=0.;
}
 sect9.close();   
 
   TGraphErrors *Tg8 = new TGraphErrors(20,theta9,sigma9,errorx9,error9);
   
   Tg8->SetMarkerStyle(28);
   Tg8->SetMarkerSize(1);
   Tg8->SetMarkerColor(1);
   Tg8->SetLineColor(1); 
   Tg8->SetMaximum(33.);
   Tg8->GetXaxis()->SetLimits(1.3,1.9);
   Tg8->SetMinimum(0.);
   
   Tg8->SetTitle(title.str().c_str());
   Tg8->Draw("PS"); 























std::ostringstream file10;

file10 << "/home/gleb/e1e/e1e/2picross-sect/q204045/jopa";
 cout << file10.str() << "\n";



int i;
 float sigma11[30],error11[30],theta11[30],errorx11[30];
 
 

std::ifstream sect11(file10.str().c_str());
//  std::ifstream sect1("sect1.dat");

for (i= 0; i <= 19; i++)
{
  sect11 >> theta11[i] >> sigma11[i] >> error11[i];
  
//  sigma[i-20]=sigma[i-20]*2.0;

 cout << theta11[i] << "  " << sigma11[i] << "  " << error11[i] << "\n";
 errorx11[i]=0.;
}
 sect11.close();   
 
   TGraphErrors *Tg10 = new TGraphErrors(20,theta11,sigma11,errorx11,error11);
   
   Tg10->SetMarkerStyle(31);
   Tg10->SetMarkerSize(1);
   Tg10->SetMarkerColor(1);
   Tg10->SetLineColor(1); 
   Tg10->SetMaximum(33.);
   Tg10->GetXaxis()->SetLimits(1.3,1.9);
   Tg10->SetMinimum(0.);
   
   Tg10->SetTitle(title.str().c_str());
//   Tg10->Draw("PS"); 





 return;
}
