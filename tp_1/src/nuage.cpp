#include <iostream>
#include <vector>
#include "nuage.hpp"

using namespace std;

//Point * Nuage::const_iterator = 0; // Attribut de classe

// Constructeurs
Nuage::Nuage() { }

// Méthodes
int Nuage::size() const {
    return tabPoint.size();
}

void Nuage::ajouter(Point & p) {
    tabPoint.push_back(&p);
}

Nuage::const_iterator Nuage::begin() const {
    return tabPoint.cbegin();
}

Nuage::const_iterator Nuage::end() const {
    return tabPoint.cend();
}


// Hors classe Nuage
Cartesien barycentre(Nuage n) {
    Cartesien tmp;
    float sumX = 0;
    float sumY = 0;
    for(auto it = n.begin(); it < n.end(); it++) {
        (*it)->convertir(tmp); // On prend le contenu de l'itérateur qui est un Point * puis on lui applique sa méthode "convertir"
        sumX += tmp.getX();
        sumY += tmp.getY();
    }

    Cartesien barycentre(sumX / n.size(), sumY / n.size());
    return barycentre;
}