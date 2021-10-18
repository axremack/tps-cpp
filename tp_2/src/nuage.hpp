#ifndef NUAGE
#define NUAGE
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"
#include <vector>
using namespace std;

template <typename TYPE_POINT>
class Nuage {
    private:
        vector<TYPE_POINT> tabPoint;
    public:
        using const_iterator = typename vector<TYPE_POINT>::const_iterator; // dire au compilo qu'on parle de type, c'est pour enlever des ambiguités
        Nuage();
        int size() const; 
        void ajouter(const TYPE_POINT &); // il faut bien mettre le paramètre en const pour passer les tests
        const_iterator begin() const;
        const_iterator end() const;
};

// Constructeurs
template <typename TYPE_POINT>
Nuage<TYPE_POINT>::Nuage() { }

// Méthodes
template <typename TYPE_POINT>
int Nuage<TYPE_POINT>::size() const {
    return tabPoint.size();
}

template <typename TYPE_POINT>
void Nuage<TYPE_POINT>::ajouter(const TYPE_POINT & p) {
    tabPoint.push_back(p);
}

template <typename TYPE_POINT>
typename Nuage<TYPE_POINT>::const_iterator Nuage<TYPE_POINT>::begin() const {
    return tabPoint.cbegin();
}

template <typename TYPE_POINT>
typename Nuage<TYPE_POINT>::const_iterator Nuage<TYPE_POINT>::end() const {
    return tabPoint.cend();
}




// Fonctions
template <typename TYPE_POINT>
TYPE_POINT barycentre_v1(Nuage<TYPE_POINT> n) {
    double moyX = 0, moyY = 0;

    Cartesien tmp;
    float sumX = 0;
    float sumY = 0;
    for(auto it = n.begin(); it < n.end(); it++) {
        (*it).convertir(tmp); // On prend le contenu de l'itérateur qui est un Point * puis on lui applique sa méthode "convertir"
        sumX += tmp.getX();
        sumY += tmp.getY();
    }

    moyX = sumX / n.size();
    moyY = sumY / n.size();

    return (n.size() == 0 ? TYPE_POINT() : TYPE_POINT(Cartesien(moyX, moyY)));
    // on utilise le constructeur qui agit comme une conversion pour le cas des polaires
}

Polaire barycentre_v1(Nuage<Polaire> n) {
    double moyAngle = 0, moyDist = 0;

    if(n.size() > 0) {
        float sumAngle = 0;
        float sumDist = 0;
        for(auto it = n.begin(); it < n.end(); it++) {
            sumAngle += (*it).getAngle(); // on prends le contenu des itérateurs
            sumDist += (*it).getDistance();
        }

        moyAngle = sumAngle / n.size();
        moyDist = sumDist / n.size();
    }

    return Polaire(moyAngle, moyDist);
}

template <typename TYPE_POINT, template <typename> class CONTAINER>
TYPE_POINT barycentre_v2(CONTAINER<TYPE_POINT> & n) {
   double moyX = 0, moyY = 0;
    
    Cartesien tmp;
    float sumX = 0;
    float sumY = 0;
    for(auto it = n.begin(); it < n.end(); it++) {
        (*it).convertir(tmp); // On prend le contenu de l'itérateur qui est un Point * puis on lui applique sa méthode "convertir"
        sumX += tmp.getX();
        sumY += tmp.getY();
    }

    moyX = sumX / n.size();
    moyY = sumY / n.size();

    return (n.size() == 0 ? TYPE_POINT() : TYPE_POINT(Cartesien(moyX, moyY)));
}



#endif