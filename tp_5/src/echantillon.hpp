#ifndef ECHANTILLON
#define ECHANTILLON

#include <vector>
#include "valeur.cpp"

using namespace std;

class Echantillon {
    private:
        vector<Valeur> vals;
    public:
        unsigned int getTaille();
        vector<Valeur> getVals() const;
        void ajouter(double);
        Valeur getMinimum();
        Valeur getMaximum();
        Valeur getValeur(unsigned int);
};






#endif