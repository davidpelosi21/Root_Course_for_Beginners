
void  T(){
    cout<<"Root Cern tree a simple exercise "<<endl;
    //creazione di un tree
    TFile *ff =  new TFile("/Users/David/root/macros/esTree.root","RECREATE");
    //creo un file esTree.root nel path indicato
    TTree *t1 = new TTree ("t1","example tree");
    //creo un tree t1 dal titolo "example tree"
    struct dato {
        float  x;
        float errx;
    };
    
    dato dx;
    dato dy;
    
    t1->Branch("xx",&dx,"valore/F:errore");
    //2 leaf uguali conta l'ordine il primo valore che assume dx va su valore
    t1->Branch("yy",&dy,"valore/F:errore");
    
    
    //salvare tutti i dati
    fstream g;
    g.open("/Users/David/Desktop/ROOT_AISF/tree/datay.txt",ios::in);
    fstream f;
    f.open("/Users/David/Desktop/ROOT_AISF/tree/datax.txt",ios::in);
    if (f.bad()) {
        cout<<"errore"<<endl;
    }
    while (!f.eof() && !g.eof() ) {
        f>>dx.x>>dx.errx>>ws;
        g>>dy.y>>dy.erry>>ws;
        t1->Fill();               }
    
    f.close(); g.close();
    
    t1->Print();
    ff->Write();
    ff->Close();
    cout<<"Root Cern tree created"<<endl;
    //chiusura automatica del file root
}
