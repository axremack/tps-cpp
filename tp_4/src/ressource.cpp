#include "ressource.hpp"

Ressource::Ressource(int val) : stock(val) { }

int Ressource::getStock() const {
    return stock;
}

void Ressource::setStock(int val) {
    stock = val;
}

void Ressource::consommer(int val) {
    stock -= val;
}