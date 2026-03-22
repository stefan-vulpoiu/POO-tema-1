# POO-tema-1
Repository dedicat temei 1 pentru POO, Informatica, anul I, semestrul II, FMI, UNIBUC

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
