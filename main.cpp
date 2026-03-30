/*
Tema 26: AirLine (companii, rezervari, rute)

In cadrul proiectului am implementat 3 clase (Companie, Ruta, Rezervare):
1) Clasa Companie retine numele companiei si anul infiintarii;
2) Clasa Ruta retine orasul de plecare, orasul de sosire si distanta dintre acestea;
3) Clasa Rezervare retine numele clientului, numarul de bilete pe care le are si preturile acestora.

In cadrul claselor se regasesc constructori de initializare si copiere, destructori, operatori= de copiere
si cate o functie membru publica pentru functionalitate netriviala, dintre care una complexa la clasa Rezervare.

In main am declarat obiecte specifice pentru clasele din proiect,
afisand obiectul in formatul specificat in clasa sa prin functia friend cu operatorul de afisare <<.


1. Descrierea datelor de intrare:
Datele de intrare sunt reprezentate de seturi de date:

- Companie: primeste numele companiei (char*) si anul infiintarii (int).
- Ruta: primeste orasul de plecare (char*), destinatia (char*) si distanta in km (float).
- Rezervare: primeste numele clientului (char*), numarul de bilete (int) si un vector
  alocat dinamic cu preturile fiecarui bilet in parte (float*).


2. Descrierea operatiilor posibile:
Pe langa operatiile standard, sistemul permite urmatoarele operatii specifice domeniului (functionalitati netriviale):

- Calcularea numarului de ani de existenta a unei companii aeriene in raport cu un an dat;
- Estimarea duratei de zbor pentru o anumita ruta;
- Calcularea costului unei rezervari (suma tuturor biletelor);
- Aplicarea automata a unei promotii ("reducere_grup"): daca o rezervare contine 3
  sau mai multe bilete, cel mai ieftin bilet primeste o reducere de 50%.
*/

#include <iostream>
#include <cstring>

class Companie{

private:
    char* nume;
    int an_infiintare;

public:
    Companie(const char* nume = "", int an_infiintare = 0) //Constructor de initializare
    {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->an_infiintare = an_infiintare;
        std::cout << "constructor finalizat: " << this->nume << "\n";
    }

    Companie(const Companie& c) //Constructor de copiere
    {
        this->nume = new char[strlen(c.nume) + 1];
        strcpy(this->nume, c.nume);
        this->an_infiintare = c.an_infiintare;
        std::cout << "Am copiat compania " << this->nume << "\n";
    }

    //setteri:
    void setNume(const char* nouNume)
    {
        if (this->nume != nullptr) {
            delete[] this->nume;
        }
        this->nume = new char[strlen(nouNume) + 1];
        strcpy(this->nume, nouNume);
    }

    inline void setAnInfiintare(int nouAn)
    {
        this->an_infiintare = nouAn;
    }

    ~Companie() //Destructor
    {
        std::cout << "Destructor pentru " << this->nume <<"\n";
        delete[] this->nume;
    }

    Companie& operator=(const Companie& c) //operator= de copiere
    {
        if (this != &c)
        {
            delete[] this->nume;
            this->nume = new char[strlen(c.nume) + 1];
            strcpy(this->nume, c.nume);
            this->an_infiintare = c.an_infiintare;
        }
        return *this;
    }

    //getteri:
    inline const char* getNume() const
    {
        return this->nume;
    }
    inline int getAnInfiintare() const
    {
        return this->an_infiintare;
    }

    inline int existenta(int an_curent) const //functie membru publica pentru functionalitate netriviala
    {
        if (an_curent < this->an_infiintare)
            return 0;
        return an_curent - this->an_infiintare;
    }

    friend std::ostream& operator << (std::ostream& out, const Companie& c) //operator << pentru afisare
    {
        out << "Compania " << c.nume << " a fost infiintata in anul " << c.an_infiintare;
        return out;
    }
};




class Ruta{

private:
    char* plecare;
    char* destinatie;
    float distanta;

public:
    Ruta(const char* plecare = "", const char* destinatie = "", float distanta = 0.0) //Constructor de initializare
    {
        this->plecare = new char[strlen(plecare) + 1];
        strcpy(this->plecare, plecare);

        this->destinatie = new char[strlen(destinatie) + 1];
        strcpy(this->destinatie, destinatie);

        this->distanta = distanta;

        std::cout << "Ruta: plecare din " << this->plecare << " cu sosire in " << this->destinatie <<"\n";
    }

    Ruta(const Ruta& r) //Constructor de copiere
    {
        this->plecare = new char[strlen(r.plecare) + 1];
        strcpy(this->plecare, r.plecare);

        this->destinatie = new char[strlen(r.destinatie) + 1];
        strcpy(this->destinatie, r.destinatie);

        this->distanta = r.distanta;

        std::cout << "Ruta copiata: plecare din " << this->plecare << " cu sosire in " << this->destinatie <<"\n";
    }

    //setteri:
    void setPlecare(const char* nouaPlecare)
    {
        if (this->plecare != nullptr) {
            delete[] this->plecare;
        }
        this->plecare = new char[strlen(nouaPlecare) + 1];
        strcpy(this->plecare, nouaPlecare);
    }

    void setDestinatie(const char* nouaDestinatie)
    {
        if (this->destinatie != nullptr) {
            delete[] this->destinatie;
        }
        this->destinatie = new char[strlen(nouaDestinatie) + 1];
        strcpy(this->destinatie, nouaDestinatie);
    }

    inline void setDistanta(float nouaDistanta)
    {
        this->distanta = nouaDistanta;
    }

    ~Ruta() //Destructor
    {
        std::cout << "Destructor pentru ruta cu plecare din " << this->plecare << " si sosire in "  << this->destinatie <<"\n";
        delete[] this->plecare;
        delete[] this->destinatie;
    }

    Ruta& operator=(const Ruta& r) //operator= de copiere
    {
        if (this != &r)
        {
            delete[] this->plecare;
            delete[] this->destinatie;

            this->plecare = new char[strlen(r.plecare) + 1];
            strcpy(this->plecare, r.plecare);

            this->destinatie = new char[strlen(r.destinatie) + 1];
            strcpy(this->destinatie, r.destinatie);

            this->distanta = r.distanta;
        }
        return* this;
    }

    //getteri
    inline const char* getPlecare() const
    {
        return this->plecare;
    }
    inline const char* getDestinatie() const
    {
        return this->destinatie;
    }
    inline float getDistanta() const
    {
        return this->distanta;
    }

    float durata(float viteza) const //functie membru publica pentru functionalitate netriviala
    {
        return this->distanta/viteza;
    }

    friend std::ostream& operator << (std::ostream& out, const Ruta& r) //operator << pentru afisare
    {
        out << "Ruta: plecare din " << r.plecare << " cu sosire in " << r.destinatie << " (" << r.distanta << " km)" <<"\n";
        return out;
    }
};




class Rezervare{

private:
    char* client;
    int nr_bilete;
    float* preturi;

    Companie companie;
    Ruta ruta;

    static int nr_total_rezervari;

public:

    //constructor de initializare
    Rezervare(const char* client = "", int nr_bilete = 0, const float* preturi = nullptr, const Companie& comp = Companie(), const Ruta& rut = Ruta())
              : companie(comp), ruta(rut)
    {
        this->client = new char[strlen(client) + 1];
        strcpy(this->client, client);

        this->nr_bilete = nr_bilete;

        if (this->nr_bilete > 0 && preturi != nullptr)
        {
            this->preturi = new float[this->nr_bilete];
            for (int i=0; i<this->nr_bilete; i++)
                this->preturi[i] = preturi[i];
        }
        else
        {
            this->preturi = nullptr;
        }

        std::cout << "Rezervare pentru: " << this->client <<"\n";
        nr_total_rezervari++;
    }

    Rezervare(const Rezervare& r) : companie(r.companie), ruta(r.ruta)
    {
        this->client = new char[strlen(r.client) + 1];
        strcpy(this->client, r.client);

        this->nr_bilete = r.nr_bilete;
        if (this->nr_bilete > 0 && r.preturi != nullptr)
        {
            this->preturi = new float[this->nr_bilete];
            for (int i=0; i<this->nr_bilete; i++)
                this->preturi[i] = r.preturi[i];
        }
        else
        {
            this->preturi = nullptr;
            this->nr_bilete = 0;
        }

        std::cout << "Rezervare copiata pentru: " << this->client <<"\n";
        nr_total_rezervari++;
    }

    //setteri
    void setClient(const char* nouClient)
    {
        if (this->client != nullptr) {
            delete[] this->client;
        }
        this->client = new char[strlen(nouClient) + 1];
        strcpy(this->client, nouClient);
    }

    //setam biletele si preturile impreuna pentru a evita desincronizarea
    void setBilete(int nouNrBilete, const float* noiPreturi)
    {
        //stergem preturile vechi
        if (this->preturi != nullptr) {
            delete[] this->preturi;
        }

        //actualizam numarul
        this->nr_bilete = nouNrBilete;

        //alocam din nou daca e cazul
        if (this->nr_bilete > 0 && noiPreturi != nullptr)
        {
            this->preturi = new float[this->nr_bilete];
            for (int i = 0; i < this->nr_bilete; i++)
                this->preturi[i] = noiPreturi[i];
        }
        else
        {
            this->preturi = nullptr;
            this->nr_bilete = 0;
        }
    }

    //setterii pentru clasele compuse
    inline void setCompanie(const Companie& nouaCompanie)
    {
        this->companie = nouaCompanie;
    }

    inline void setRuta(const Ruta& nouaRuta)
    {
        this->ruta = nouaRuta;
    }

    ~Rezervare() //Destructor
    {
        std::cout << "Destructor pentru " << this->client <<"\n";
        delete[] this->client;
        delete[] this->preturi;
        nr_total_rezervari--;
    }

    Rezervare& operator=(const Rezervare& r) //operator=
    {
        if (this != &r)
        {
            delete[] this->client;
            delete[] this->preturi;

            this->client = new char[strlen(r.client) + 1];
            strcpy(this->client, r.client);

            this->nr_bilete = r.nr_bilete;
            if (this->nr_bilete > 0 && r.preturi != nullptr)
            {
                this->preturi = new float[this->nr_bilete];
                for (int i=0; i<this->nr_bilete; i++)
                    this->preturi[i] = r.preturi[i];
            }
            else
            {
                this->preturi = nullptr;
                this->nr_bilete = 0;
            }

            //copierea obiectelor compuse
            this->companie = r.companie;
            this->ruta = r.ruta;
        }
        return *this;
    }

    inline const char* getClient() const
    {
        return this->client;
    }
    inline int getNrBilete() const
    {
        return this->nr_bilete;
    }
    inline const float* getPreturi() const
    {
        return this->preturi;
    }
    static int getNrTotalRezervari()
    {
        return nr_total_rezervari;
    }

    Companie getCompanie() const
    {
        return this->companie;
    }
    Ruta getRuta() const
    {
        return this->ruta;
    }

    float cost_total() const //functie membru publica pentru functionalitate netriviala
    {
        float suma = 0;
        for (int i=0; i<this->nr_bilete; i++)
            suma += this->preturi[i];
        return suma;
    }

    bool reducere_grup() //functie complexa membru publica pentru functionalitate netriviala (la 3 sau mai multe bilete/client, se aplica reducere)
    {
        if (this->nr_bilete >= 3 && this->preturi != nullptr)
        {
            //Cautam pozitia indexul celui mai ieftin bilet
            int index_min = 0;
            for (int i=1; i<this->nr_bilete; i++)
                if (this->preturi[i] < this->preturi[index_min])
                    index_min = i;

            this->preturi[index_min] = this->preturi[index_min] / 2.0;
            return true;
        }
        return false;
    }

    friend std::ostream& operator << (std::ostream& out, const Rezervare& r)
    {
        //afisam compania si ruta folosind getterii si operatorii << deja definiti in celelalte clase
        out << "Clientul " << r.client << " zboara cu compania " << r.companie.getNume() << "\n";
        out << r.ruta; //aici se apeleaza automat operatorul << din clasa Ruta
        out << "Are " << r.nr_bilete << " bilete";

        if (r.nr_bilete > 0 && r.preturi != nullptr)
        {
            out << " cu preturile ";
            for (int i=0; i<r.nr_bilete; i++)
            {
                out << r.preturi[i] << " RON";
                if (i < r.nr_bilete - 1)
                    out << ", ";
            }
        }
        out <<"\n";
        return out;
    }
};

int Rezervare::nr_total_rezervari = 0;




int main()
{
    Companie c1("Turkish Airlines", 1954);
    Companie c2("KLM", 1953);

    Ruta r1("Istanbul", "Paris", 2270.5);
    Ruta r2("Amsterdam", "Boston", 4000.0);

    float preturiGrup[4] = {1000.0, 1200.0, 1000.0, 800.0};
    Rezervare rez1("Familia Popescu", 4, preturiGrup, c1, r1);

    std::cout << rez1;
    std::cout << "Cost initial: " << rez1.cost_total() << " RON\n";

    if (rez1.reducere_grup()) {
        std::cout << "-> S-a aplicat reducerea de grup!\n";
        std::cout << "Cost dupa reducere: " << rez1.cost_total() << " RON\n";
    }

    std::cout << "--- Se apeleaza constructorul de copiere ---\n";
    Rezervare rez2 = rez1;

    rez2.setClient("Familia Ionescu");
    rez2.setCompanie(c2);
    rez2.setRuta(r2);

    std::cout << "\nDetalii Rezervare 2 (dupa modificari independente):\n";
    std::cout << rez2;

    Rezervare rez3;

    std::cout << "\n--- Se apeleaza operatorul = ---\n";
    rez3 = rez2; // Copiem rezervarea Ionescu in rez3

    float preturiSingle[1] = {2500.0};
    rez3.setClient("Client Business");
    rez3.setBilete(1, preturiSingle);

    std::cout << "\nDetalii Rezervare 3:\n";
    std::cout << rez3;
    return 0;
}
