#include <classe.hpp>

using namespace std;

Classe::Classe() : min(0), max(0), quantite(0) {}

Classe::Classe(double a, double b) : min(a), max(b), quantite(0) {}

double Classe::getBorneInf() const {
    return min;
}

void Classe::setBorneInf(double val) {
    min = val;
}

double Classe::getBorneSup() const {
    return max;
}

void Classe::setBorneSup(double val) {
    max = val;
}

unsigned int Classe::getQuantite() const {
    return quantite;
}

void Classe::setQuantite(unsigned int val) {
    quantite = val;
}

void Classe::ajouter() {
    quantite++;
}