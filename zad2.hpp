#include<stdlib.h>
#include<iostream>
#ifndef zad2_hpp
#define zad2_hpp
#define dlugosc(x) sizeof(x)/sizeof(x[0])

#include <iostream>
#include <stdio.h>

using namespace std;

//******************************** klasa jako tym danych
class kosz
{
    public:
        int jablka;
        kosz(int a = 0)
        {
            jablka = a;
        }
        int operator==(kosz &p);
        kosz& operator=(kosz const&p);
        int operator!=(kosz &p);
        friend ostream& operator<<(ostream& output, kosz &p);   
};  

//******************************** szablon klasy reprezentujący stos
template <typename T>
class stos
{
    T *stosik, *stosikTymcz, *stosikDoPorow;
    int pozycja;
    void rozmiaroj()
    {
        if(pozycja == 0) stosik = new T[pozycja];
        else
        {
            stosikTymcz = new T[pozycja];
            for(int i = 0; i <= pozycja; i++) stosikTymcz[i] = stosik[i];
            delete[] stosik;
            stosik = new T[pozycja];
            for(int i = 0; i <= pozycja; i++) stosik[i] = stosikTymcz[i];
            delete[] stosikTymcz;
        }
    }
    void zamiesc(T wartosc)
    {
        pozycja++;
        rozmiaroj();
        stosik[pozycja] = wartosc;
    }
    void usun()
    {
        if(pozycja < 0) 
        {
            cout << "Nie ma czego usunąć" <<endl;
            return;
        }
        pozycja--;
        if(pozycja == -1) delete[] stosik;
        else if(pozycja == 0)
        {
            stosikTymcz = new T[pozycja];
            stosikTymcz[0] = stosik[0];
            delete[] stosik;
            stosik = new T[pozycja];
            stosik[0] = stosikTymcz[0];
            delete[] stosikTymcz;
        }
        else rozmiaroj();
        return;
    }
    T zwroc()
    {
        if(pozycja < 0) cout << "Stos jest pusty" << endl;
        return stosik[pozycja];
    }
    bool czyPusty()
    {
        if(pozycja < 0) return true;
        else return false;
    }
    int rozmiar()
    {
        if(pozycja < 0) 
        {
            cout << "Stos jest pusty" << endl;
            return 0;
        }
        else return pozycja + 1;
    }
    template <typename M, size_t N>
inline
size_t rozmiar( const M(&)[ N ] )
{
  return N;
}
    bool porownaj()
    {
        int x = rozmiar(stosik);
        cout << x << endl;
        if(dlugosc(stosikDoPorow) != dlugosc(stosik))
        {
            cout << "Stosy mają różne wielkości" << endl;
            return false;
        }
        for(int i = 0; i <= pozycja; i++) 
        {
            if(stosik[i] != stosikDoPorow[i]) return false;
        }
        cout << "Stosy są takie same" << endl;
        return true;
    }
    void drukuj()
    {
        if(pozycja < 0) 
        {
            cout << "Stos jest pusty" << endl;
            return;
        }
        for(int i = 0; i <= pozycja; i++) cout << stosik[i];
    }

    public:
        stos()
        {
            pozycja = -1;
        }
        ~stos()
        {
            delete[] stosik;
            delete[] stosikDoPorow;
        }
        friend class testy1;
        friend class testy2;
        
};

//*********************************** testy dla typu int
class testy1
{
    private:
        stos<int> test;
    public:
        bool testZamiesc();
        bool testUsun();
        bool testZwroc();
        bool testCzyPusty();
        bool testRozmiar();
        bool testPorownaj();
        void testDrukuj();
};

//*********************************** testy dla typu kosz
class testy2
{
    private:
        stos<kosz> test;
    public:
        bool testZamiesc();
        bool testUsun();
        bool testZwroc();
        bool testCzyPusty();
        bool testRozmiar();
        bool testPorownaj();
        void testDrukuj();
};

//************************************ funkcje pomocnicze
void testujemyInt();
void testujemyKosz();

#endif