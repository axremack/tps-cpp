#ifndef HISTOGRAMME
#define HISTOGRAMME

using namespace std;

#include <vector>
#include <set>
#include <map>
#include "classe.hpp"
#include "echantillon.hpp"


// VERSION VECTEUR
/*class Histo {
    private:
        vector<Classe> vect;
    public:
        Histo(double, double, unsigned int);
        vector<Classe> getClasses();
        void ajouter(Echantillon);
};*/


// VERSION ENSEMBLE
/*class Histo {
    private:
        set<Classe> vect;
    public:
        Histo(double, double, unsigned int);
        set<Classe> getClasses();
        void ajouter(Echantillon);
};*/

/*bool operator< (const Classe & x, const Classe & y) {
    return x.getBorneInf() < y.getBorneInf();
}*/

template <typename T>
class ComparateurQuantite {
    public : 
        bool operator() (const T & c1, const T & c2) const { 
            return (c1.getQuantite() == c2.getQuantite()) ? c1.getBorneInf() < c2.getBorneInf() : c1.getQuantite() > c2.getQuantite();
        }
};

// VERSION GENERIQUE
template <typename COMP = less<Classe>>
class Histogramme {
    private:
        set<Classe, COMP> vect;
        multimap<Classe, Valeur> vals;
    public:
        Histogramme(double, double, unsigned int);
        template <typename COMP2>
        Histogramme(const Histogramme<COMP2> &);
        const set<Classe, COMP> & getClasses() const;
        void ajouter(double);
        const multimap<Classe, Valeur> & getValeurs() const;
        auto getValeurs(const Classe &) const;
};

bool operator< (const Classe & x, const Classe & y) {
    return x.getBorneInf() < y.getBorneInf();
}

bool operator> (const Classe & x, const Classe & y) {
    return x.getBorneInf() > y.getBorneInf();
}

template <typename COMP>
Histogramme<COMP>::Histogramme (double min, double max, unsigned int quantite) {
    double pas = (max - min) / quantite;
    for(double i = min; i < max; i+=pas) {
        Classe c(i, i + pas);
        vect.insert(c);
    }
}


template <typename COMP>
template <typename COMP2> 
Histogramme<COMP>::Histogramme (const Histogramme<COMP2> & h) {
    copy(h.getClasses().begin(), h.getClasses().end(), inserter(vect, vect.end()));
}

template <typename COMP>
const set<Classe, COMP> & Histogramme<COMP>::getClasses() const {
    return vect;
}

template <typename COMP>
void Histogramme<COMP>::ajouter(double val) {
    for(const Classe & c : vect) {
        if(val >= c.getBorneInf() && val < c.getBorneSup()) {
            auto c_temp = vect.find(c);
            vect.erase(c);
            Classe c_copy = *(c_temp);
            c_copy.ajouter();
            vect.insert(c_copy);
            vals.insert({c, val});
        }
    }
}

template <typename COMP>
const multimap<Classe, Valeur> & Histogramme<COMP>::getValeurs() const {
    return vals;
}

template <typename COMP>
auto Histogramme<COMP>::getValeurs(const Classe & c) const {
    return vals.equal_range(c);
}

template <typename COMP>
ostream & operator<<(ostream & os, const Histogramme<COMP> & h) {
    for (auto c : h.getClasses()) {
        os << "[" << c.getBorneInf() << ":" << c.getBorneSup() << "] = " << c.getQuantite() << " ";

        auto range = h.getValeurs(c);
        for (auto i = range.first; i != range.second; ++i) {
            os << "{" << i->second.getEtudiant() << ";" << i->second.getNote() << "} ";
        }

        os << endl;
    }
    return os;
}



#endif