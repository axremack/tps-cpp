#ifndef CONSOMMATEUR
#define CONSOMMATEUR

using namespace std;

#include <vector>
#include "ressource.hpp"

class Consommateur {
    private :
        int besoin;
        shared_ptr<Ressource> ressource;
    public :
        Consommateur(int, shared_ptr<Ressource>);
        void puiser();
        
};


using ressources_t = vector<weak_ptr<Ressource> >;

ostream & operator<< (ostream & os, const ressources_t & r) {
    for(auto & res : r) {
        if(!res.expired()) {
            os << res.lock()->getStock() << " ";
        }
        else {
            os << "- ";
        }
    }

    return os;
}


#endif