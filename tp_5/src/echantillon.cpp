#include <vector>
#include "echantillon.hpp"

using namespace std;

unsigned int Echantillon::getTaille() {
    return vals.size();
}

vector<Valeur> Echantillon::getVals() const {
    return vals;
}

void Echantillon::ajouter(double val) {
    vals.push_back(val);
}

Valeur Echantillon::getMinimum() {
    if (vals.begin() != vals.end()) {
        return *(min_element(vals.begin(), vals.end(), [] (Valeur x, Valeur y) { return x.getNombre() < y.getNombre();}));
    } else {
        throw domain_error("Machin");
    }
}

Valeur Echantillon::getMaximum() {
if (vals.begin() != vals.end()) {
        return *(max_element(vals.begin(), vals.end(), [] (Valeur x, Valeur y) { return x.getNombre() < y.getNombre();}));
    } else {
        throw domain_error("Machin");
    }
}

Valeur Echantillon::getValeur(unsigned int indice) {
    if(indice < vals.size()) {
        return vals[indice];
    } else {
        throw out_of_range("Index out of bound");
    }
}