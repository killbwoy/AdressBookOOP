#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika() {

    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    //uzytkownik.id = pobierzIdNowegoUzytkownika();
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    do {
        cout << "Podaj login: ";
        //uzytkownik.login = wczytajLinie();
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    //uzytkownik.haslo = wczytajLinie();
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}
int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}
bool UzytkownikMenedzer::czyIstniejeLogin(string login) {
    for(unsigned int i = 0; i < uzytkownicy.size(); i++) {
        if(uzytkownicy[i].pobierzLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie" << endl;
            return true;
        }
    }
    return false;
}
void UzytkownikMenedzer::wypiszWszystkichUzytkownikow() {

    for(unsigned int i = 0; i < uzytkownicy.size(); i++) {

            cout <<  uzytkownicy[i].pobierzId() << endl;
            cout <<  uzytkownicy[i].pobierzLogin() << endl;
            cout <<  uzytkownicy[i].pobierzHaslo() << endl;
        }
}
void UzytkownikMenedzer::wczytajUzytkownikowZPliku(){

    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}
int UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";
    cout << endl << "Podaj login: ";
    //login = wczytajLinie();
    cin >> login;

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                //haslo = wczytajLinie();
                cin >> haslo;

                if (itr -> pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return itr -> pobierzId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}
void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    Uzytkownik uzytkownik;

    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    //noweHaslo = wczytajLinie();
    cin >> noweHaslo;

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        cout << itr->pobierzId() << endl;
        cout << idZalogowanegoUzytkownika << endl;
        if (itr -> pobierzId() == idZalogowanegoUzytkownika)
        {
            itr -> pobierzHaslo() = uzytkownik.zmienHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    //zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
