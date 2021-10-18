#ifndef POLAIRE
#define POLAIRE
#include <sstream>
#include <point.hpp>
using namespace std;

class Polaire : public Point {
    private:
        double angle;
        double dist;
    public:
        Polaire();
        Polaire(double, double);
        Polaire(Cartesien);
        double getAngle() const;
        void setAngle(double);
        double getDistance() const;
        void setDistance(double);
        stringstream & afficher(stringstream &) const override;
        void convertir(Cartesien &) const override; 
        void convertir(Polaire &) const override;
};

#endif