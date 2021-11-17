#include <iostream>
#include <histogramme.hpp>

using namespace std;

// VERSION VECTEUR
/*Histo::Histo (double min, double max, unsigned int quantite) {
    double pas = (max - min) / quantite;
    for(double i = min; i < max; i+=pas) {
        Classe c(i, i + pas);
        vect.push_back(c);
    }
}

vector<Classe> Histo::getClasses() {
    return vect;
}

void Histo::ajouter(Echantillon e) {
    for(Classe & c : vect) {
        for(Valeur v : e.getVals()) {
            if(v.getNombre() >= c.getBorneInf() && v.getNombre() < c.getBorneSup()) {
                c.ajouter();
            }
        }
    }
}
*/


// VERSION ENSEMBLE
/*Histo::Histo (double min, double max, unsigned int quantite) {
    double pas = (max - min) / quantite;
    for(double i = min; i < max; i+=pas) {
        Classe c(i, i + pas);
        vect.insert(c);
    }
}

set<Classe> Histo::getClasses() {
    return vect;
}

void Histo::ajouter(Echantillon e) {
    for(const Classe & c : vect) {
        for(Valeur v : e.getVals()) {
            if(v.getNombre() >= c.getBorneInf() && v.getNombre() < c.getBorneSup()) {
                auto c_temp = vect.find(c);
                vect.erase(c);
                Classe c_copy = *(c_temp);
                c_copy.ajouter();
                vect.insert(c_copy);
            }
        }
    }
}
*/


