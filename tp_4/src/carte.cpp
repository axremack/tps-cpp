#include <carte.hpp>

using namespace std;


int Carte::cpt = 0;

Carte::Carte (int n) : num(n) { cpt++; }

Carte::~Carte() { cpt--; }

int Carte::getValeur() {
    return num;
}
