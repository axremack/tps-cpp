#include <iostream>
#include "point.hpp"

using namespace std;

// Surcharge d'opérateur
stringstream & operator<< (stringstream & flux, const Point & x) {
    x.afficher(flux);
    return flux;
}


// -----------------------------------------------
// POINT
// -----------------------------------------------
int Point::cpt = 0; // Attribut de classe

// Constructeurs
Point::Point() {
    cpt++;
}

// Getters et setters
int Point::getCpt() {
    return cpt;
}

