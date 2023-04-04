#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(){

    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
}
void KsiazkaAdresowa::rejestracjaUzytkownika(){

    uzytkownikMenedzer.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){

    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
int KsiazkaAdresowa::logowanieUzytkownika(){

    uzytkownikMenedzer.logowanieUzytkownika();
}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){

    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}
