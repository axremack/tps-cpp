#ifndef PAQUET
#define PAQUET

#include <memory>
#include "usineCarte.hpp"

using namespace std;

using paquet_t = vector<unique_ptr<Carte>>;

void remplir (paquet_t & p, UsineCarte & u) {
    unique_ptr<Carte> c(u.getCarte());
    while (c != nullptr) {
        p.push_back(move(c));
        c = u.getCarte();
    }
}

ostream & operator<<(ostream & os, const paquet_t & paquet) {
    for(auto & carte : paquet) {
        os << carte->getValeur() << " ";
    }
    return os;
}


#endif