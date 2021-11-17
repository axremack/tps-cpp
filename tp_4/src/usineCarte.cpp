#include <iostream>
#include <usineCarte.hpp>

using namespace std;

int UsineCarte::cpt = 0;

UsineCarte::UsineCarte () {
    cpt = 0;
}

UsineCarte::UsineCarte (int n) : nbCarte(n) {
    cpt = 0;
}

unique_ptr<Carte> UsineCarte::getCarte() {
    cpt ++;
    return (cpt <= nbCarte) ? unique_ptr<Carte> (new Carte(cpt - 1)) : nullptr;
}
