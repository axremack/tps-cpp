#ifndef NUAGE
#define NUAGE
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"
#include <vector>
using namespace std;


class Nuage {
    private:
        vector<Point *> tabPoint;
    public:
        using const_iterator = vector<Point *>::const_iterator;
        Nuage();
        int size() const; 
        void ajouter(Point &);
        const_iterator begin() const;
        const_iterator end() const;
};
// Pas de getter car c'est moche mais par le tab en public non plus parce que c'est pire, on l'appelle seulement depuis les méthodes et il y a pas de soucis puisqu'il y a pas d'héritage

Cartesien barycentre(Nuage);

// Calcul du barycentre en version foncteur
// Les foncteurs sont juste des classes servant de fonction grace à la surcharge de l'opérateur ()
class BarycentreCartesien {
public:
    Cartesien operator()(Nuage n) {
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
};

class BarycentrePolaire {
public:
    Polaire operator()(Nuage n) {
        Cartesien b = BarycentreCartesien()(n);

        Polaire barycentreP;
        b.convertir(barycentreP);

        return barycentreP;
    }
};


#endif