

void G(double tau){
    TCanvas* c1 = new TCanvas("c1","c1");
    c1->cd();
    //double tau;
    //tau = 2;
     //pdf da generare
    TF1 * fun = new TF1("exp", "[0] * exp(-x/[1])", 0, 20);
    fun->SetParameters(1/tau, tau);
    
    TH1F* hist = new TH1F("hist", ";t(s);Counts", 100, 0, 20);

    
    double t;
    
    for (int i = 0; i < 10000; i++) {
        t = fun->GetRandom();
        hist->Fill(t);
    }


    hist->Draw();
    c1->Draw();
//per disegnare la funzione sopra l'istogramma, posso normalizzare oppure scalare la funzione con un trmone moltiplicativo pari a larghezza del bin * numero eventi totali

    fun->SetParameters(10000 * hist->GetBinWidth(0) / tau, tau);
    fun->Draw("same");
    
    TCanvas* c2 = new TCanvas("c2","c2");
    TH1F *hist2 = new TH1F("hist2", ";t(s);Counts", 100, 0, 20);
    for (int i = 0; i < 10000; i++) {
        t = fun->GetRandom();
        hist2->Fill(t);
    }
    c2->cd();
    hist2->Draw();
    fun->SetParameters(10000 * hist->GetBinWidth(0) / tau, tau);
    fun->Draw("same");
    c2->Draw();
    TCanvas* c3 = new TCanvas("c3","c3");
    TH1F* hist3 = new TH1F("hist3", ";t(s);Counts", 100, 0, 20);
    for (int i = 0; i < 10000; i++) {
        t = fun->GetRandom();
        hist3->Fill(t);
    }
    c3->cd();
    hist3->Draw();
    fun->SetParameters(10000 * hist->GetBinWidth(0) / tau, tau);
    fun->Draw("same");
    c3->Draw();
    
    
    
    TCanvas* c4 = new TCanvas("c4","c4");
    TH1F* hist4 = new TH1F("hist4", ";t(s);Counts", 100, 0, 20);
    for (int i = 0; i < 10000; i++) {
        t = fun->GetRandom();
        hist4->Fill(t);
    }
    c4->cd();
    hist4->Draw();
    fun->SetParameters(10000 * hist->GetBinWidth(0) / tau, tau);
    fun->Draw("same");
    c4->Draw();
}
    

