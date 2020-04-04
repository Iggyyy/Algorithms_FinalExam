#include <bits/stdc++.h>
using namespace std;
vector<int> waga(6), wartosc(6);
 vector<int> mem(25, -100); //TABLICA ZAPAMIÊTUJ¥CA WARTOŒCI PLECAKÓW O POJEMNOŒCIACH i-tych

int plecakDlaWieluP(int pojemnosc) //Nieskoñczona iloœæ przedmiotów
{

    mem[0] = 0;

    for(int w = 0; w<= pojemnosc; w++)  //PRZECHODZIMY PRZEZ KA¯DY PLECAK POKOLEI
    {
        for(int i = 0; i< waga.size(); i++) //PRZECHODZIMY PRZEZ WSZYSTKIE PRZEDMIOTY
        {
            if(w >= waga[i]) //WARUNEK ZABEZPIECZAJ¥CY - JE¯ELI POJEMNOŒÆ JEST MNIEJSZA OD WAGI PRZEDMIOTUNIE WYKONUJEMY PORÓWNANIA
                mem[w] = max( mem[w], mem[w - waga[i]] + wartosc[i]); //ZAPAMIÊTUJEMY MAX WARTOŒÆ DLA DANEJ POJEMNOŒCI PLECAKA
                                                                        // - WYBIERAMY ALBO AKTUALN¥ WATOŒÆ, ALBO WARTOŒÆ Z 'POPRZEDNIEGO PLECAKA' + AKTUALN¥ WARTOŒÆ
        }
    }
    int maxW = 0;
    for(int  w = 0; w<= pojemnosc; w++)
        maxW = max(maxW, mem[w]);       //WYBÓR MAX WARTOŒCI PLECAKA

    return maxW;

}
int plecakDlaUnikatowych(int pojemnosc) //Po jednym przedmiocie
{

    mem[0] = 0;

    for(int w = 0; w<= pojemnosc; w++)  //PRZECHODZIMY PRZEZ KA¯DY PLECAK POKOLEI
    {
        for(int i = 0; i< waga.size(); i++) //PRZECHODZIMY PRZEZ WSZYSTKIE PRZEDMIOTY
        {
            if(w >= waga[i]) //WARUNEK ZABEZPIECZAJ¥CY - JE¯ELI POJEMNOŒÆ JEST MNIEJSZA OD WAGI PRZEDMIOTUNIE WYKONUJEMY PORÓWNANIA
                mem[w] = max( mem[w], mem[w - waga[i]] + wartosc[i]); //ZAPAMIÊTUJEMY MAX WARTOŒÆ DLA DANEJ POJEMNOŒCI PLECAKA
                                                                        // - WYBIERAMY ALBO AKTUALN¥ WATOŒÆ, ALBO WARTOŒÆ Z 'POPRZEDNIEGO PLECAKA' + AKTUALN¥ WARTOŒÆ
        }
    }
    int maxW = 0;
    for(int  w = 0; w<= pojemnosc; w++)
        maxW = max(maxW, mem[w]);       //WYBÓR MAX WARTOŒCI PLECAKA

    return maxW;

}



int main()
{
    waga = {4, 13 , 8, 5, 6, 7};
    wartosc = { 5, 25, 14, 6, 2, 11};

    cout<<"Dla plecaka o poj = 24 wart: "<<plecakDlaWieluP(24)<<endl;    //WYNIK

    for(int i = 0 ; i< mem.size(); i++) //SPRAWDZENIE CZY PLECAKI DOBRZE ZADZIA£A£Y
        cout<<"Poj: "<<i << " Wart: " << mem[i]<<endl;
}
