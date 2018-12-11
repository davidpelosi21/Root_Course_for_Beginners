

void prepareData(int n) {
  gRandom = new TRandom3(n);
  float tau = 2.2e-6;
  auto cc = new TCanvas();
  cc->Draw();

    
  auto fun = new TF1("exp", "[0] * exp(-x/[1])", 0, 1e-4);
  fun->SetParameters(1 / tau, tau);
  fun->SetNpx(10000);

  auto hist = new TH1F("hist", ";t (s);Counts", 1000, 0, 1e-4);
  auto tree = new TTree("Triggers", "Triggers");

  float t = 0, dt = 0;
  tree->Branch("time", &t);

  //numero di eventi è Poissoniano
  long int nEv = gRandom->Poisson(500);
  cout << "Generating " << nEv << " events" << endl;

  for (long int iEv = 0; iEv < nEv; iEv++) {
    t = fun->GetRandom();
    hist->Fill(t);
    tree->Fill();
  }

    
  cout << "...Eseguito" << endl;

  hist->SetStats(0);
  hist->SetMarkerStyle(20);
  hist->SetLineColor(kBlack);
  hist->GetXaxis()->SetRangeUser(0, 1.1e-5);
  fun->SetLineColor(4);

  hist->Draw();


  auto outfile = new TFile("/users/David/root/macros/dataDavid.root", "recreate");
  outfile->WriteTObject(tree);
  outfile->Close();
}
