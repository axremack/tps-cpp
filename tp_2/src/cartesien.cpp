#include <iostream>
#include <sstream>
#include <cmath>
#include "cartesien.hpp"
#include "polaire.hpp"

using namespace std;

// -----------------------------------------------
// CARTESIEN
// -----------------------------------------------

// Constructeurs
Cartesien::Cartesien() : Point(), x(0), y(0) { }

Cartesien::Cartesien(double abs, double ord) : Point(), x(abs), y(ord) { }

Cartesien::Cartesien(Polaire pol) : Point(), x(pol.getDistance() * cos(M_PI * pol.getAngle() / 180)), y(pol.getDistance() * sin(M_PI * pol.getAngle() / 180)) { }

// Getters et setters
double Cartesien::getX() const {
    return x;
}

void Cartesien::setX(double num) {
    x = num;
}

double Cartesien::getY() const{
    return y;
}

void Cartesien::setY(double num) {
    y = num;
}

// Méthodes
stringstream & Cartesien::afficher(stringstream & flux) const {
    flux << "(x=" << getX() << ";y=" << getY() << ")";
    return flux;
}

void Cartesien::convertir(Polaire & pol) const {
    double distance = sqrt(this->getX()*this->getX() + this->getY()*this->getY());
    double angle = (2 * atan2(this->getY(), this->getX() + distance)) * 180 / M_PI; // Transformation en degré puis calcul
    
    pol.setAngle(angle);
    pol.setDistance(distance);
}

void Cartesien::convertir(Cartesien & cart) const {
    cart.setX(this->getX());
    cart.setY(this->getY());
}