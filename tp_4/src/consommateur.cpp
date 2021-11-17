#include "consommateur.hpp"

Consommateur::Consommateur(int val, shared_ptr<Ressource> ress) : besoin(val), ressource(ress) { }

void Consommateur::puiser() {
    if(ressource != nullptr) {
        if(ressource->getStock() - besoin < 0) {
            ressource->setStock(0);
            ressource = nullptr;
        }
        else {
            ressource->setStock(ressource->getStock() - besoin);
        }
    }
}