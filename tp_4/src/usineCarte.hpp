#ifndef USINE_CARTE
#define USINE_CARTE

#include <carte.hpp>
#include <memory>
#include <vector>

using namespace std;

class UsineCarte {
    private :
        int nbCarte;
        static int cpt;
    public :
        UsineCarte();
        UsineCarte(int);
        unique_ptr<Carte> getCarte();
        UsineCarte(const UsineCarte &) = delete;
        UsineCarte & operator= (const UsineCarte &) = delete;
};


#endif