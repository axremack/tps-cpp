#ifndef CARTE
#define CARTE

#include <memory>

using namespace std;

class Carte {
    friend class UsineCarte;

    private :
        static int cpt;
        int num;
        Carte(int);
    public :
        ~Carte();
        int getValeur();
        Carte(const Carte &) = delete;
        Carte & operator= (const Carte &) = delete;
        static int getCompteur() { return cpt; };

};



#endif