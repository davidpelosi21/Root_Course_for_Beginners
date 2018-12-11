
//funzione interna alla macros
void g(){
    TString nomefile = "/Users/David/Desktop/punticurva.txt"; //percorso
    TGraphErrors *g = new TGraphErrors(nomefile);
   
    
    g->SetMarkerColor(1); //Markers...
    g->SetMarkerStyle(21);
    //g->SetTitle("titolo");
    g->SetLineColor(1);
    cout<<"****************************"<<endl;
    cout<<"FIT funzione G-->  "<<endl;
    g->Fit("pol1");
    g->GetFunction("pol1")->SetLineColor(1);


    TString nomefile2 = "/Users/David/Desktop/punticurva2.txt"; //percorso
    TGraphErrors *f = new TGraphErrors(nomefile2);
   
    //f->GetXaxis()->SetTitle("x");
    //f->GetYaxis()->SetTitle("f(x)");
    //f->GetXaxis()->CenterTitle();
    //f->GetYaxis()->CenterTitle();
    
    f->SetMarkerColor(2); //Markers...
    f->SetMarkerStyle(21);
    f->SetLineColor(2);
    cout<<"****************************"<<endl;
    cout<<"FIT funzione F-->  "<<endl;
    
    f->Fit("gaus");
    f->GetFunction("pol1")->SetLineColor(2);
    
    
    
    TMultiGraph* mg = new TMultiGraph();
    mg->Add(f);
    mg->Add(g);
    mg->SetTitle("Multigraph (Fit) Example");
    mg->GetXaxis()->SetTitle("x");
    mg->GetYaxis()->SetTitle("f(x)");
    
    mg->Draw("ap");
    
    auto legend = new TLegend(0.1,0.2,0.28,0.3);
    legend->SetHeader("Legend","C"); // option "C" allows to center the header
    legend->AddEntry(f,"funzione f ","l");
    legend->AddEntry(g,"funzione g","l");
    legend->Draw();
} 
