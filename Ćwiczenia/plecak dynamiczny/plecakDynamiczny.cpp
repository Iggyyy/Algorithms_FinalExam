#include <bits/stdc++.h>
using namespace std;
vector<int> waga(6), wartosc(6);
 vector<int> mem(25, -100); //TABLICA ZAPAMI�TUJ�CA WARTO�CI PLECAK�W O POJEMNO�CIACH i-tych

int plecakDlaWieluP(int pojemnosc) //Niesko�czona ilo�� przedmiot�w
{

    mem[0] = 0;

    for(int w = 0; w<= pojemnosc; w++)  //PRZECHODZIMY PRZEZ KA�DY PLECAK POKOLEI
    {
        for(int i = 0; i< waga.size(); i++) //PRZECHODZIMY PRZEZ WSZYSTKIE PRZEDMIOTY
        {
            if(w >= waga[i]) //WARUNEK ZABEZPIECZAJ�CY - JE�ELI POJEMNO�� JEST MNIEJSZA OD WAGI PRZEDMIOTUNIE WYKONUJEMY POR�WNANIA
                mem[w] = max( mem[w], mem[w - waga[i]] + wartosc[i]); //ZAPAMI�TUJEMY MAX WARTO�� DLA DANEJ POJEMNO�CI PLECAKA
                                                                        // - WYBIERAMY ALBO AKTUALN� WATO��, ALBO WARTO�� Z 'POPRZEDNIEGO PLECAKA' + AKTUALN� WARTO��
        }
    }
    int maxW = 0;
    for(int  w = 0; w<= pojemnosc; w++)
        maxW = max(maxW, mem[w]);       //WYB�R MAX WARTO�CI PLECAKA

    return maxW;

}
int plecakDlaUnikatowych(int pojemnosc) //Po jednym przedmiocie
{

    mem[0] = 0;

    for(int w = 0; w<= pojemnosc; w++)  //PRZECHODZIMY PRZEZ KA�DY PLECAK POKOLEI
    {
        for(int i = 0; i< waga.size(); i++) //PRZECHODZIMY PRZEZ WSZYSTKIE PRZEDMIOTY
        {
            if(w >= waga[i]) //WARUNEK ZABEZPIECZAJ�CY - JE�ELI POJEMNO�� JEST MNIEJSZA OD WAGI PRZEDMIOTUNIE WYKONUJEMY POR�WNANIA
                mem[w] = max( mem[w], mem[w - waga[i]] + wartosc[i]); //ZAPAMI�TUJEMY MAX WARTO�� DLA DANEJ POJEMNO�CI PLECAKA
                                                                        // - WYBIERAMY ALBO AKTUALN� WATO��, ALBO WARTO�� Z 'POPRZEDNIEGO PLECAKA' + AKTUALN� WARTO��
        }
    }
    int maxW = 0;
    for(int  w = 0; w<= pojemnosc; w++)
        maxW = max(maxW, mem[w]);       //WYB�R MAX WARTO�CI PLECAKA

    return maxW;

}



int main()
{
    waga = {4, 13 , 8, 5, 6, 7};
    wartosc = { 5, 25, 14, 6, 2, 11};

    cout<<"Dla plecaka o poj = 24 wart: "<<plecakDlaWieluP(24)<<endl;    //WYNIK

    for(int i = 0 ; i< mem.size(); i++) //SPRAWDZENIE CZY PLECAKI DOBRZE ZADZIA�A�Y
        cout<<"Poj: "<<i << " Wart: " << mem[i]<<endl;
}
