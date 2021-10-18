#ifndef CARTESIEN
#define CARTESIEN
#include <sstream>
#include <point.hpp>
using namespace std;


class Cartesien : public Point {
    private:
        double x;
        double y;
    public:
        Cartesien();
        Cartesien(double, double);
        Cartesien(Polaire);
        double getX() const;
        void setX(double);
        double getY() const;
        void setY(double);
        stringstream & afficher(stringstream &) const override;
        void convertir(Polaire &) const override;
        void convertir(Cartesien &) const override;
};

#endif