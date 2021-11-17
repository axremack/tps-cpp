#ifndef CLASSE
#define CLASSE

using namespace std;

class Classe {
    private:
        double min;
        double max; 
        unsigned int quantite;
    public:
        Classe();
        Classe(double, double);
        double getBorneInf() const;
        void setBorneInf(double);
        double getBorneSup() const;
        void setBorneSup(double);
        unsigned int getQuantite () const;
        void setQuantite(unsigned int);
        void ajouter();
};


#endif