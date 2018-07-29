#include <iostream>
#include <cstdlib>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

/**
 * 
 * pierwszy input:  ilosc planet w uniwersum
 * drugi input:     ilosc specjalnych teleportow
 * trzeci input:    ilosc zapytan
 * 
 * 
 * czwarty input:   sposob polaczenia, ktore sa polaczone 
 *          np. 1 2 (czyli 1 planeta z druga planeta
 *          kazde uniwersum ma takie samo polaczenie
 * 
 * piaty input:     ktora planeta ktorego uniwersum ma tepeka z
 *                  ktora planeta ktorego uniwersum
 * 
 * szosty input:    ktora planeta z ktorego uniwersum z
 *                  ktora planeta z ktorego uniwersum: jaka jest najkrotsza
 *                  droga (ilosc ruchow) miedzy nimi
 * 
 * 
 */


/**
 * 
 * @return tablica polaczen plan z 1 uniwersum
 */

int** wczytaj_tablice_polaczenia_planet(int ilosc_planet)
{
    // czytanie ktora planeta z ktora ma polaczenie
    int** tablica_polaczenia_planet = new int*[ilosc_planet-1];
    for(int i=0; i<ilosc_planet; i++)
    {
        tablica_polaczenia_planet[i] = new int[2];
    }
    
    for(int i=0; i<ilosc_planet; i++)
    {
        for(int j=0; j<2; j++)
        {
            cin >> tablica_polaczenia_planet[i][j];
        }
    }
    
    return tablica_polaczenia_planet;
}


/**
 * 
 * @param ilosc_teleportow
 * @return tablice teleportow kto z kad z kim
 */
int** wczytaj_tablice_teleportow(int ilosc_teleportow)
{
    // czytanie ktora planeta z uniwersum ma tepeka z ktora planeta z jakiego uniwersum
    int** tablica_teleportow = new int*[ilosc_teleportow];
    for(int i=0; i<ilosc_teleportow; i++)
    {
        tablica_teleportow[i] = new int[4];
    }
    
    for(int i=0; i<ilosc_teleportow; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin >> tablica_teleportow[i][j];
        }
    }

    return tablica_teleportow;    
}

/**
 * 
 * @param ilosc_zapytan
 * @return tablica zapytan z kad dokad
 */

int** wczytaj_tablice_zapytan(int ilosc_zapytan)
{
    // czytanie jakie zapytania
    int** tablica_zapytan = new int*[ilosc_zapytan];
    for(int i=0; i<ilosc_zapytan; i++)
    {
        tablica_zapytan[i] = new int[4];
    }
    
    for(int i=0; i<ilosc_zapytan; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin >> tablica_zapytan[i][j];
        }
    }

    return tablica_zapytan;
}

bool sprawdz_czy_juz_jest_taka_planeta(list<int>lista_planet, int planeta)
{
    list<int>::iterator lista_planet_iter;
    
    for(lista_planet_iter = lista_planet.begin();
        lista_planet_iter != lista_planet.end();
            lista_planet_iter++)
    {
        if(*lista_planet_iter == planeta)
            return true;
    }
    return false;
}

list<int>::iterator pozycja_planety(list<int>lista_planet, int planeta)
{
    list<int>::iterator pozycja;
    
    for(pozycja = lista_planet.begin();
        pozycja != lista_planet.end();
            ++pozycja)
    {
        if(*pozycja == planeta)
            return pozycja;
    }
    return;
}

list<int> posortuj_planety_uniwersum(int** tablica_polaczenia_planet, int ilosc_planet)
{
    // stworz vector ktory zachowa kolejnosc planet w uniwersum

    list<int> kolejnosc_planet_uniwersum;
    list<int>::iterator iter;
    
    for(int i=0; i<ilosc_planet; i++)
    {
        if(not kolejnosc_planet_uniwersum.size()) //jezeli w vectorze nie ma nic
        {
            kolejnosc_planet_uniwersum.push_back(tablica_polaczenia_planet[i][0]);
            kolejnosc_planet_uniwersum.push_back(tablica_polaczenia_planet[i][1]);
        }   
        else if(sprawdz_czy_juz_jest_taka_planeta(kolejnosc_planet_uniwersum, tablica_polaczenia_planet[i][0]))
        {
            iter = pozycja_planety(kolejnosc_planet_uniwersum, tablica_polaczenia_planet[i][0]);
            kolejnosc_planet_uniwersum.insert(iter, 1, tablica_polaczenia_planet[i][1]);
        }            
    }    
    
    return kolejnosc_planet_uniwersum;
}

int main() {
    
    int ilosc_planet,
        ilosc_teleportow,
        ilosc_zapytan;
    
    cin >> ilosc_planet >> ilosc_teleportow >> ilosc_zapytan;
    
    int** tablica_polaczenia_planet_ = 
            wczytaj_tablice_polaczenia_planet(ilosc_planet);
    

    int** tablica_teleportow_ = 
            wczytaj_tablice_teleportow(ilosc_teleportow);
    
    
    int** tablica_zapytan_ = 
            wczytaj_tablice_zapytan(ilosc_zapytan);
    
    
    list<int> kolejnosc_planet_uniwersum = 
            posortuj_planety_uniwersum(tablica_polaczenia_planet_, ilosc_planet);    
    
    
    list<int>::iterator wypisz_kolejnosc_planet;
    
    for(wypisz_kolejnosc_planet = kolejnosc_planet_uniwersum.begin();
        wypisz_kolejnosc_planet != kolejnosc_planet_uniwersum.end();
        wypisz_kolejnosc_planet++)
    {
        cout << *wypisz_kolejnosc_planet << endl;
    }
    
    
    // wez jako poczatek pozycje 1 planety
    // wez jako koniec pozycje 2 planety
    // oblicz odleglosc (roznica pozycji iteratorow) 
    

    for(int i=0; i<ilosc_zapytan; i++)
    {
        if(tablica_zapytan_[i][1] != tablica_zapytan_[i][3])
        {
            
        }
        else
        {
            list<int>::iterator begin_;
            list<int>::iterator end_;
            
            begin_ = pozycja_planety(kolejnosc_planet_uniwersum, tablica_zapytan_[i][0]);
            end_ = pozycja_planety(kolejnosc_planet_uniwersum, tablica_zapytan_[i][2]);
            
            distance(begin_, end_);
        }
    }
    

    return 0;
}

