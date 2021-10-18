#include <iostream>
#include <sstream>
#include <cmath>
#include "polaire.hpp"
#include "cartesien.hpp"

using namespace std;


// -----------------------------------------------
// POLAIRE
// -----------------------------------------------

// Constructeurs
Polaire::Polaire() : Point(), angle(0), dist(0) { }

Polaire::Polaire(double a, double d) : Point(), angle(a), dist(d) { }

Polaire::Polaire(Cartesien cart) : Point(), 
                                    angle((2 * atan2(cart.getY(), cart.getX() + sqrt(cart.getX()*cart.getX() + cart.getY()*cart.getY()))) * 180 / M_PI), 
                                    dist(sqrt(cart.getX()*cart.getX() + cart.getY()*cart.getY())) 
{ }

// Getters et setters
double Polaire::getAngle() const {
    return angle;
}

void Polaire::setAngle(double a) {
    angle = a;
}

double Polaire::getDistance() const{
    return dist;
}

void Polaire::setDistance(double d) {
    dist = d;
}

// Méthodes
stringstream & Polaire::afficher(stringstream & flux) const {
    flux << "(a=" <<  getAngle() << ";d=" << getDistance() << ")";
    return flux;
}

void Polaire::convertir(Cartesien & cart) const {
    double x = this->getDistance() * cos(M_PI * this->getAngle() / 180); // Transformation en radian avant calcul
    double y = this->getDistance() * sin(M_PI * this->getAngle() / 180); // Transformation en radian avant calcul

    cart.setX(x);
    cart.setY(y);
}

void Polaire::convertir(Polaire & pol) const {
    pol.setAngle(this->getAngle());
    pol.setDistance(this->getDistance());
}
