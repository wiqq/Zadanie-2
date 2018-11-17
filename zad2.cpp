#include "zad2.hpp"

//******************************** kosz
int kosz::operator==(kosz &p)
{
    if(jablka == p.jablka) return true;
    else return false;
}
kosz& kosz::operator=(kosz const&p)
{
    jablka =  p.jablka;
}
int kosz::operator!=(kosz&p)
{
    if(jablka == p.jablka) return false;
    else return true;
}
ostream& operator<<(ostream& output, kosz&p)
{
    return output << "Jablka w koszu : " << p.jablka << endl;
}

//******************************** testy1
bool testy1::testZamiesc()
{
    test.zamiesc(1);
    test.zamiesc(2);
    if(test.zwroc() == 2) return true;
    else return false;
}
bool testy1::testUsun()
{
    test.usun();
    if(test.zwroc() == 1) return true;
    else return false;
}
bool testy1::testZwroc()
{
    if(test.zwroc() == test.stosik[test.pozycja]) return true;
    else return false;
}
bool testy1::testCzyPusty()
{
    if((test.czyPusty() == true) && (test.pozycja >= 0)) return false;
    else if((test.czyPusty() == false) && (test.pozycja < 0)) return false;
    else return true;
}
bool testy1::testRozmiar()
{
    if(test.rozmiar() == test.pozycja + 1) return true;
    else return false;
}
bool testy1::testPorownaj()
{
    test.stosikDoPorow = new int[0];
    test.stosikDoPorow[0] = 1;
    
    cout << dlugosc(test.stosikDoPorow) << endl;
    cout << dlugosc(test.stosikDoPorow) << endl;
    bool a = test.porownaj();
    if((a == false) && (dlugosc(test.stosikDoPorow) != test.pozycja + 1)) return true;
    for(int i = 0; i <= test.pozycja; i++)
    {
        if(test.stosikDoPorow[i] != test.stosik[i]) return false;
    }
    return true;
}
void testy1::testDrukuj()
{
    test.drukuj();
}

//******************************** testy2
bool testy2::testZamiesc()
{
    kosz kosz1(1); kosz kosz2(2);
    test.zamiesc(kosz1);
    test.zamiesc(kosz2);
    if(test.zwroc() == kosz2) return true;
    else return false;
}
bool testy2::testUsun()
{
    kosz kosz1(1);
    test.usun();
    if(test.zwroc() == kosz1) return true;
    else return false;
}
bool testy2::testZwroc()
{
    if(test.zwroc() == test.stosik[test.pozycja]) return true;
    else return false;
}
bool testy2::testCzyPusty()
{
    if((test.czyPusty() == true) && (test.pozycja >= 0)) return false;
    else if((test.czyPusty() == false) && (test.pozycja < 0)) return false;
    else return true;
}
bool testy2::testRozmiar()
{
    if(test.rozmiar() == test.pozycja + 1) return true;
    else return false;
}
bool testy2::testPorownaj()
{
    kosz kosz1(1);
    test.stosikDoPorow = new kosz[0];
    test.stosikDoPorow[0] = kosz1;
    
    bool a = test.porownaj();
    if((a == false) && (sizeof(test.stosikDoPorow)/sizeof(kosz) != test.pozycja + 1)) return true;
    for(int i = 0; i <= test.pozycja; i++)
    {
        if(test.stosikDoPorow[i] != test.stosik[i]) return false;
    }
    return true;
}
void testy2::testDrukuj()
{
    test.drukuj();
}

//******************************* testy do maina
void testujemyInt()
{
    testy1 typInt;

    cout << "Testy szablonu dla typu int : " << endl;
    if(typInt.testZamiesc() == true) 
        cout << "Prawidłowy wynik testu zamieszczania" << endl;
    else cout << "Zły wynik testu zamieszczania" << endl;
    if(typInt.testUsun() == true)
        cout << "Prawidłowy wynik testu usuwania" << endl;
    else cout << "Zły wynik testu usuwania" << endl;
    if(typInt.testZwroc() == true)
        cout << "Prawidłowy wynik testu zwracania" << endl;
    else cout << "Zły wynik testu zwracania" << endl;
    if(typInt.testCzyPusty() == true)
        cout << "Prawidłowy wynik testu sprawdzenia, czy stos jest pusty" << endl;
    else cout << "Zły wynik testu sprawdzania, czy stos jest pusty" << endl;
    if(typInt.testRozmiar() == true)
        cout << "Prawidłowy wynik testu sprawdzania rozmiaru" << endl;
    else cout << "Zły wynik testu sprawdzania rozmiaru" << endl;
    if(typInt.testPorownaj() == true)
        cout << "Prawidłowy wynik testu porównywania stosów" << endl;
    else cout << "Zły wynik testu porównywania stosów" << endl;
    typInt.testDrukuj();
}

void testujemyKosz()
{
    testy2 mojTyp;

    cout << "Testy szablonu dla typu 'kosz' : " << endl;
    if(mojTyp.testZamiesc() == true) 
        cout << "Prawidłowy wynik testu zamieszczania" << endl;
    else cout << "Zły wynik testu zamieszczania" << endl;
    if(mojTyp.testUsun() == true)
        cout << "Prawidłowy wynik testu usuwania" << endl;
    else cout << "Zły wynik testu usuwania" << endl;
    if(mojTyp.testZwroc() == true)
        cout << "Prawidłowy wynik testu zwracania" << endl;
    else cout << "Zły wynik testu zwracania" << endl;
    if(mojTyp.testCzyPusty() == true)
        cout << "Prawidłowy wynik testu sprawdzenia, czy stos jest pusty" << endl;
    else cout << "Zły wynik testu sprawdzania, czy stos jest pusty" << endl;
    if(mojTyp.testRozmiar() == true)
        cout << "Prawidłowy wynik testu sprawdzania rozmiaru" << endl;
    else cout << "Zły wynik testu sprawdzania rozmiaru" << endl;
    if(mojTyp.testPorownaj() == true)
        cout << "Prawidłowy wynik testu porównywania stosów" << endl;
    else cout << "Zły wynik testu porównywania stosów" << endl;
    mojTyp.testDrukuj();
}