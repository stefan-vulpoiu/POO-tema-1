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

    int existenta(int an_curent) const //functie membru publica pentru functionalitate netriviala
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

public:
    Rezervare(const char* client = "", int nr_bilete = 0, const float* preturi = nullptr) //Constructor de initializare
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
            this->preturi = nullptr;

        std::cout << "Rezervare pentru: " << this->client <<"\n";
    }

    Rezervare(const Rezervare& r) //Constructor de copiere
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
            this->preturi = nullptr;

        std::cout << "Rezervare copiata pentru: " << this->client <<"\n";
    }

    ~Rezervare() //Destructor
    {
        std::cout << "Destructor pentru " << this->client <<"\n";
        delete[] this->client;
        delete[] this->preturi;
    }

    Rezervare& operator=(const Rezervare& r) //operator= de copiere
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
                this->preturi = nullptr;
        }
        return *this;
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

    friend std::ostream& operator << (std::ostream& out, const Rezervare& r) //operator << pentru afisare
    {
        out << "Clientul " << r.client << " are " << r.nr_bilete << " bilete";
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



int main()
{

    //COMPANIE
    Companie c1("British Airways", 1936);
    Companie c2 = c1; //copiere
    c2 = Companie("Emirates", 1985); //atribuire

    std::cout << c1 << "\n";
    std::cout << c2 << "\n";
    std::cout << "British Airways are o vechime de " << c1.existenta(2026) << " ani\n\n\n";



    //RUTA
    Ruta r1("Bucuresti", "Londra", 2090.5);
    Ruta r2; //ruta goala initial
    r2 = r1; //atribuire

    std::cout << r1;
    std::cout << "Durata estimata a zborului (la 800 km/h): " << r1.durata(800.0) << " ore\n\n\n";


    //REZERVARE
    float preturiTest[3] = {1200.50, 1200.50, 600.00};
    Rezervare rez1("Ioan Popa", 3, preturiTest);

    if (rez1.reducere_grup() == true)
        std::cout << "S-a aplicat reducerea de grup (50% la cel mai ieftin bilet)\n";
    else
        std::cout << "Clientul nu beneficiaza de reducere (necesita minim 3 bilete)\n";

    std::cout << rez1;
    std::cout << "Cost final: " << rez1.cost_total() << " RON\n\n\n";

    return 0;
}
