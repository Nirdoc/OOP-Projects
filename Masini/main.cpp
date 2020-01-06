#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Masina
{
protected:
    int id;
    int anFabricatie;
    string tip;//coupe, hot-hatch,cabrio,supersport
    string model; //hatchback, decapotabile

public:
    static int id_generator;
    Masina()
    {
        anFabricatie=0;
        tip="tip";
        model="model";
        id=id_generator;
    }

    Masina(int anFabricatie, string tip, string model)
    {
        this->anFabricatie=anFabricatie;
        this->tip=tip;
        this->model=model;
        id=id_generator;
        id_generator++;
    }

    Masina(const Masina &M)
    {
        this->anFabricatie=M.anFabricatie;
        this->tip=M.tip;
        this->model=M.model;
    }

    friend istream &operator>>(istream &in, Masina &M)
    {
        cout<<"\nAnFabricatie:";
        in>>M.anFabricatie;
        cout<<"\nTip:";
        in>>M.tip;
        cout<<"\nModel:";
        in>>M.model;
    }

    friend istream &operator>>(istream &in, Masina *M)
    {
        cout<<"\nAnFabricatie:";
        in>>(*M).anFabricatie;
        cout<<"\nTip:";
        in>>(*M).tip;
        cout<<"\nModel:";
        in>>(*M).model;
    }

    friend ostream &operator<<(ostream &out, Masina &M)
    {
        cout<<"\nAnFabricatie:";
        out<<M.anFabricatie;
        cout<<"\nTip:";
        out<<M.tip;
        cout<<"\nModel:";
        out<<  M.model;
    }



    virtual void afis()
    {

        cout<<"An fabriacatie: "<<anFabricatie<<endl;
        cout<<"Tip: "<<tip<<endl;
        cout<<"Model: "<<model<<endl;

    }

    Masina &operator=(const Masina &m)
    {
        if(this!=&m)
        {
            this->anFabricatie=m.anFabricatie;
            this->tip=m.tip;
            this->model=m.model;
        }
        return *this;
    }
    int getId()
    {
        return this->id;
    }
    string getTip()
    {
        return this->tip;
    }

    void setTip(string t)
    {
        this->tip=t;
    }


    ~Masina()=default;


};

Masina *M[100];
void citireNmasini(int n)
{
    for(int i=0; i<n; i++)
    {
        Masina *m = new Masina();
        cin >> *m;
        M[i] = (Masina*)m;
    }
}

void afisareNmasini(int n)
{
    for(int i=0; i<n; i++)
    {
        cout<< *M[i];
    }
}

class Coupe:public Masina
{
    int nrUsi;//am pus nrUsi ca sa aiba si Coupe cv special

public:
    int getNrUsi()
    {
        return this->nrUsi;
    }

    void setNrUsi(int nr)
    {
        this->nrUsi=nr;
    }

    Coupe()
    {
        anFabricatie=0;
        tip="COUPE";
        model="model";
        nrUsi=2;
    }

    Coupe(int anFabricatie, string tip, string model, int nrUsi):Masina(anFabricatie,tip,model)
    {
        this->nrUsi=nrUsi;
    }

    ~Coupe()=default;

    friend istream &operator>>(istream &in, Coupe &C)
    {
        cout<<"\nAnFabricatie:";
        in>>C.anFabricatie;
        cout<<"\nTip:";
        in>>C.tip;
        cout<<"\nModel:";
        in>>C.model;
        cout<<"\nNrUsi:";
        in>>C.nrUsi;
    }

    friend istream &operator>>(istream &in, Coupe *C)
    {
        cout<<"\nAnFabricatie:";
        in>>(*C).anFabricatie;
        cout<<"\nTip:";
        in>>(*C).tip;
        cout<<"\nModel:";
        in>>(*C).model;
        cout<<"\nNrUsi:";
        in>>(*C).nrUsi;
    }

    friend ostream &operator<<(ostream &out, Coupe &C)
    {
        cout<<"\nAnFabricatie:";
        out<<C.anFabricatie;
        cout<<"\nTip:";
        out<<C.tip;
        cout<<"\nModel:";
        out<<C.model;
        cout<<"\nNrUsi:";
        out<<C.nrUsi;
    }

    void afis()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"An fabriacatie: "<<anFabricatie<<endl;
        cout<<"Tip: "<<tip<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Nr usi: "<<nrUsi<<endl<<endl;
    }

};

class HotHatch:public Masina
{
    string calitateMotor;
    string clasa;

public:
    string getCalitateMotor()
    {
        return this->calitateMotor;
    }
    void setCalitateMotor(string calitate)
    {
        this->calitateMotor=calitate;
    }

    string getClasa()
    {
        return this->clasa;
    }
    void setClasa(string clasa)
    {
        this->clasa=clasa;
    }
    HotHatch()
    {
        anFabricatie=0;
        tip="HotHatch";
        model="Hatchback";
        calitateMotor="performanta";
        clasa="clasa";
    }

    HotHatch(int anFabricatie, string tip, string model, string calitateMotor, string clasa):Masina(anFabricatie,tip,model)
    {
        this->calitateMotor=calitateMotor;
        this->clasa=clasa;
    }

    friend istream &operator>>(istream &in, HotHatch *H)
    {
        cout<<"\nAnFabricatie:";
        in>>(*H).anFabricatie;
        cout<<"\nTip:";
        in>>(*H).tip;
        cout<<"\nModel:";
        in>>(*H).model;
        cout<<"\nCalitateMotor:";
        in>>(*H).calitateMotor;
        cout<<"\nClasa:";
        in>>(*H).clasa;
    }

    friend istream &operator>>(istream &in, HotHatch &H)
    {
        cout<<"\nAnFabricatie:";
        in>>H.anFabricatie;
        cout<<"\nTip:";
        in>>H.tip;
        cout<<"\nModel:";
        in>>H.model;
        cout<<"\nCalitateMotor:";
        in>>H.calitateMotor;
        cout<<"\nClasa:";
        in>>H.clasa;
    }
    friend ostream &operator<<(ostream &out, HotHatch &H)
    {
        cout<<"\nAnFabricatie:";
        out<<H.anFabricatie;
        cout<<"\nTip:";
        out<<H.tip;
        cout<<"\nModel:";
        out<<H.model;
        cout<<"\nCalitateMotor:";
        out<<H.calitateMotor;
        cout<<"\nClasa:";
        out<<H.clasa;
    }

    void afis()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"An fabriacatie: "<<anFabricatie<<endl;
        cout<<"Tip: "<<tip<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Calitate motor: "<<calitateMotor<<endl;
        cout<<"Clasa: "<<clasa<<endl<<endl;
    }


    ~HotHatch()=default;


};

class Cabrio: public Masina
{
    string materialAcoperis;
public:
    string getMaterialAcoperis()
    {
        return this->materialAcoperis;
    }

    void setMaterialAcoperis(string material)
    {
        this->materialAcoperis=material;
    }

    Cabrio()
    {
        anFabricatie=0;
        tip="Cabrio";
        model="decapotabila";
        materialAcoperis="material";
    }

    Cabrio(int anFabricatie, string tip, string model, string matetialAcoperis):Masina(anFabricatie,tip,model)
    {
        this->materialAcoperis=materialAcoperis;
    }

    friend istream &operator>>(istream &in, Cabrio &C)
    {
        cout<<"\nAnFabricatie:";
        in>>C.anFabricatie;
        cout<<"\nTip:";
        in>>C.tip;
        cout<<"\nModel:";
        in>>C.model;
        cout<<"\nMaterialAcoperis:";
        in>>C.materialAcoperis;
    }

    friend istream &operator>>(istream &in, Cabrio *C)
    {
        cout<<"\nAnFabricatie:";
        in>>(*C).anFabricatie;
        cout<<"\nTip:";
        in>>(*C).tip;
        cout<<"\nModel:";
        in>>(*C).model;
        cout<<"\nMaterialAcoperis:";
        in>>(*C).materialAcoperis;
    }
    friend ostream &operator<<(ostream &out, Cabrio &C)
    {
        cout<<"\nAnFabricatie:";
        out<<C.anFabricatie;
        cout<<"\nTip:";
        out<<C.tip;
        cout<<"\nModel:";
        out<<C.model;
        cout<<"\nMaterialAcoperis:";
        out<<C.materialAcoperis;
    }

    void afis()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"An fabriacatie: "<<anFabricatie<<endl;
        cout<<"Tip: "<<tip<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Material acoperis: "<<materialAcoperis<<endl<<endl;
    }

};

class Supersport:public Masina
{
public:
    Supersport()
    {
        anFabricatie=0;
        tip="SUPERSPORT";
        model="model";
    }

    Supersport(int anFabricatie, string tip, string model):Masina(anFabricatie, tip, model) {}

    ~Supersport()=default;

    friend istream &operator>>(istream &in, Supersport &S)
    {
        cout<<"\nAnFabricatie:";
        in>>S.anFabricatie;
        cout<<"\nTip:";
        in>>S.tip;
        cout<<"\nModel:";
        in>>S.model;

    }

    friend istream &operator>>(istream &in, Supersport *S)
    {
        cout<<"\nAnFabricatie:";
        in>>(*S).anFabricatie;
        cout<<"\nTip:";
        in>>(*S).tip;
        cout<<"\nModel:";
        in>>(*S).model;

    }

    friend ostream &operator<<(ostream &out, Supersport &S)
    {
        cout<<"\nAnFabricatie:";
        out<<S.anFabricatie;
        cout<<"\nTip:";
        out<<S.tip;
        cout<<"\nModel:";
        out<<S.model;
    }

    Supersport &operator=(Supersport &S)
    {
        this->anFabricatie=S.anFabricatie;
        this->tip=S.tip;
        this->model=S.model;
    }

    void afis()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"An fabriacatie: "<<anFabricatie<<endl;
        cout<<"Tip: "<<tip<<endl;
        cout<<"Model: "<<model<<endl<<endl;

    }
};

template <class T>class Expozitie
{
    int masini_stoc;
    int masini_vandute;
    vector <T*> Vandute;
    vector <Masina*>Stoc;
public:
    Masina* find_pret(int idm)
    {
        for(auto i: Stoc)
            if(idm==i->getId())
                return i;
    }

    void add_stoc(Masina *A)
    {
        masini_stoc++;
        Stoc.push_back(A);
    }
    void add_vandute(Masina *A)
    {
        masini_vandute++;
        masini_stoc--;
        Vandute.push_back(A);

    }

    friend ostream &operator <<(ostream &out, Expozitie &E)
    {
        cout<<"\nNumarul de masini din stoc este: ";
        cout<<E.masini_stoc<<"\n";
        for(auto i : E.Stoc)
        {
            if(i->getTip()=="Coupe")
            {
                Coupe *t = dynamic_cast<Coupe*>(i);
                i->afis();
            }

            else if(i->getTip()=="Hot-Hatch")
            {
                HotHatch *t = dynamic_cast<HotHatch*>(i);
                i->afis();
            }

            else if(i->getTip()=="Cabrio")
            {
                Cabrio *t = dynamic_cast<Cabrio*>(i);
                i->afis();
            }

            else if(i->getTip()=="Supersport")
            {
                Supersport *t = dynamic_cast<Supersport*>(i);
                i->afis();
            }

        }


        cout<<"Numarul de masini vandute este: ";
        cout<<E.masini_vandute<<"\n";
        for(auto i: E.Vandute)
        {
            cout<<*i<<endl<<endl;
        }
    }
    Expozitie()
    {
        masini_stoc=0;
        masini_vandute=0;
        Stoc.clear();
        Vandute.clear();

    }
    bool id_exist(int id)
    {
        for(auto i: Stoc)
        {
            if(i->getId()==id)
                return 1;
        }
        return 0;
    }


    T &operator -= (int id_vandut)
    {
        cout<<"\n---ACTUALIZARE GENERALA---\n";
        int ok=0;
        int i=0;
        for(i=0; i<masini_stoc && ok==0; i++)
        {
            if((Stoc[i])->getId()==id_vandut)
            {
                ok=1;
                break;

            }
        }
        if(ok==0)
            cout<<"Masina nu exista in stoc \n";
        if(ok==1)
        {
            cout<<"Masina cu id-ul "<<id_vandut<<" a fost vanduta \n";
            add_vandute(Stoc[i]);
        }

        cout<<"Stocul a fost actualizat \n";
        Stoc.erase(Stoc.begin()+i);
    }

    void afisare()
    {
        for(auto i: Stoc)
        {
            cout<<*i<<endl;
        }
    }
};
template <>class Expozitie<unsigned>
{
    int nr_supersport_stoc;
    int nr_supersport_vandute;
    vector<Supersport *> Supersport_Stoc;
    vector<Supersport *> Supersport_Vandute;
public:
    void set_Supersport_stoc(int n)
    {
        nr_supersport_stoc=n;
    }
    Expozitie()
    {
        nr_supersport_stoc=0;
        nr_supersport_vandute=0;
        Supersport_Stoc.erase(Supersport_Stoc.begin(),Supersport_Stoc.end());
        Supersport_Vandute.erase(Supersport_Vandute.begin(),Supersport_Vandute.end());
    }
    void operator -= (int id_vandut)
    {
        cout<<"\n---Actualizare Supersport---\n";
        Supersport *A=new Supersport();
        int ok=0;
        for(int i=0; i<nr_supersport_stoc && ok==0; i++)
        {
            if(Supersport_Stoc[i]->getId()==id_vandut)
            {
                A=Supersport_Stoc[i];
                Supersport_Stoc.erase(Supersport_Stoc.begin()+i);
                ok=1;
                Supersport_Vandute.push_back(A);
                nr_supersport_vandute++;
                nr_supersport_stoc--;
            }
        }
        if(ok==0)
            cout<<"Supersportul cautat nu exista in stoc \n";

    }
    friend ofstream &operator <<(ofstream &out, Expozitie &A)
    {
        cout<<"Numarul de supersporturi din stoc este: "<<A.nr_supersport_stoc<<"\n";
        for(int i=0; i<A.nr_supersport_stoc; i++)
        {
            A.Supersport_Stoc[i]->afis();
        }
        cout<<"Numarul de supersport vandute este: ";
        cout<<A.nr_supersport_vandute<<"\n";
        for(int i=0; i<A.nr_supersport_vandute; i++)
        {
            A.Supersport_Vandute[i]->afis();
        }
    }
    void add_stoc(Supersport *A)
    {
        Supersport_Stoc.push_back(A);
        nr_supersport_stoc++;
    }

};

int Masina::id_generator=1;
int main()
{
    Expozitie <Masina> E;
    Expozitie <Supersport> S; // specializarea de supersport

    Coupe *c1 = new Coupe(1999,"Coupe","Volvo",2);
    HotHatch *h1 = new HotHatch(2004,"Hot-Hatch","hatchback","performant","compacta");
    Cabrio *cabrio1 = new Cabrio(2010,"Cabrio","decapotabila","metalic");
    Supersport *s1 = new Supersport(2018,"Supersport","Audi R8");
    cout<<"Bine ai venit la targul masinilor sport!"<<endl;
    cout<<"Acestea sunt masinile noastre:"<<endl;

    E.add_stoc(c1);
    E.add_stoc(h1);
    E.add_stoc(cabrio1);
    E.add_stoc(s1);
    cout<<E;
    E.id_exist(2);


    // Supersport C;
    //cout<<C;

    //Masina M(22,"dss","fdsesd");
    //citireNmasini(3);
    //afisareNmasini(3);

    // cout<<M;



    //aici se citesc N obiecte
      int n;
       cout<<"N:";
       cin>>n;
       for(int i=0; i<n; i++)
       {
           string tip;
           cout<<"TIP:";
           cin>>tip;
           if(tip=="COUPE")
           {

               Coupe *C=new Coupe();
               C->setTip(tip);

               cin>>C;
               C->id_generator++;

               C->afis();
               E.add_stoc(C);


           }

           else if(tip=="HOT-HATCH")
           {
               HotHatch *H=new HotHatch();
               H->setTip(tip);

               cin>>H;
               H->id_generator++;

               H->afis();
               E.add_stoc(H);
           }

           else if(tip=="CABRIO")
           {
               Cabrio *CA=new Cabrio();
               cin>>CA;
               CA->setTip(tip);
               CA->id_generator++;

               CA->afis();
               E.add_stoc(CA);


           }
           else if(tip=="SUPERSPORT")
           {
               Supersport *SU=new Supersport();
               cin>>SU;
               SU->setTip(tip);
               SU->id_generator++;


               SU->afis();
               E.add_stoc(SU);
               S.add_stoc(SU);


           }
       }


    int op=0;
    while(op!=5)
    {
        cout<<"\nAlegeti una dintre variantele.\n";
        cout<<"1.Introduceti o masina in stoc.\n";
        cout<<"2.Vindeti o masina.\n";
        cout<<"3.Afisati stocul.\n";
        cout<<"4.Afisati stocul Supersport-urilor.\n";
        cout<<"5.Stop\n";
        cout<<"Introduceti numarul operatiunii dorite:";
        cin>>op;
        switch(op)
        {
        case 1:
        {
            string tip;
            cout<<"TIP:";
            cin>>tip;
            if(tip=="Coupe")
            {

                Coupe *C=new Coupe();
                C->setTip(tip);

                cin>>C;
                C->id_generator++;

                E.add_stoc(C);

                cout<<"S-a adaugat in stoc masina:\n";
                C->afis();

            }

            else if(tip=="Hot-hatch")
            {
                HotHatch *H=new HotHatch();
                H->setTip(tip);

                cin>>H;
                H->id_generator++;

                H->afis();
                E.add_stoc(H);
            }

            else if(tip=="Cabrio")
            {
                Cabrio *CA=new Cabrio();
                cin>>CA;
                CA->setTip(tip);
                CA->id_generator++;

                CA->afis();
                E.add_stoc(CA);


            }
            else if(tip=="Supersport")
            {
                Supersport *SU=new Supersport();
                cin>>SU;
                SU->setTip(tip);
                SU->id_generator++;


                SU->afis();
                E.add_stoc(SU);
                S.add_stoc(SU);

            }
        }

        break;
        case 2:
        {
            int idm;
            string tipm;
            cout<<"Introduceti tipul si id-ul masinii:";
            cin>>tipm>>idm;
            if(E.id_exist(idm))
            {
                Masina *A=new Masina();
                A=E.find_pret(idm);
                if(A->getTip()==tipm)
                {
                    if(tipm=="Supersport")
                    {
                        cout<<"BOSS P'ASTA POTI SA O CUMPERI CHIAR ACM DAR CU PLATA PE LOC. VREI?";
                        string raspunsClient;
                        cin>>raspunsClient;
                        if (raspunsClient=="da")
                        {
                            E-=idm;
                            cout<<"Felicitari";

                        }
                        else
                            cout<<"Mai strange bani";

                    }

                }
                else
                    cout<<"Masina nu exista";
            }
            else
                cout<<"Masina nu exista";
            break;
        }
        case 3:
        {
            cout<<E;
            break;
        }
        case 4:
        {
            cout<<S;
            break;
        }
        case 5:
            break;
        }
    }

    return 0;

}




















