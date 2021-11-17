#ifndef VALEUR
#define VALEUR

#include <string>
using namespace std;

class Valeur {
    private:
        double note;
        string etudiant;
    public:
        Valeur();
        Valeur(double);
        Valeur(double, string);
        double getNombre() const;
        double getNote() const;
        string getEtudiant() const;
        void setNombre(double);
        void setNote(double);
        void setEtudiant(string);

};






#endif