#include <valeur.hpp>

using namespace std;

Valeur::Valeur() : note(0.0), etudiant("inconnu") {}

Valeur::Valeur(double nb) : note(nb), etudiant("inconnu") {}

Valeur::Valeur(double nb, string e) : note(nb), etudiant(e) {}


double Valeur::getNombre() const {
    return note;
}

double Valeur::getNote() const {
    return note;
}

string Valeur::getEtudiant() const {
    return etudiant;
}

void Valeur::setNombre(double nb) {
    note = nb;
}

void Valeur::setNote(double nb) {
    note = nb;
}

void Valeur::setEtudiant(string nom) {
    etudiant = nom;
}