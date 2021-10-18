#ifndef POINT
#define POINT
using namespace std;

// Promesses que les classes Cartésien et Polaire existent (sinon on a un cycle au niveau de l'inclusion)
class Cartesien;
class Polaire;

class Point {
    private:
        static int cpt;
    public:
        Point();
        static int getCpt();
        virtual stringstream & afficher(stringstream &) const = 0;
        virtual void convertir(Polaire &) const = 0;
        virtual void convertir(Cartesien &) const = 0;
};

stringstream & operator<< (stringstream & flux, const Point & x);

#endif