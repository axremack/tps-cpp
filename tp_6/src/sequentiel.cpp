// Entetes //---------------------------------------------------------------------------------------
#include "nombre.hpp"
#include "sequentiel.hpp"
#include <mutex>

// Variables globales //----------------------------------------------------------------------------
unsigned compteur = 0;
mutex m;

void setCompteur(unsigned i) {
    m.lock();
    compteur += i;
    m.unlock();
}


// Fonction principale //---------------------------------------------------------------------------
int main() {
 const unsigned taille = 12;

 std::vector<Nombre> a(taille);
 std::vector<Nombre> b(taille);
 std::vector<Nombre> c(taille);

 //for (unsigned i = 0; i<taille; ++i) a[i] = ++compteur;
 for_parallele<2>(0, taille, [&](int i) { a[i] = ++compteur; });
 //for (unsigned i = 0; i<taille; ++i) b[i] = ++compteur;
 for_parallele<1>(0, taille, [&](int i) { b[i] = ++compteur; });


 std::cout << "a = " << a << std::endl;
 std::cout << "b = " << b << std::endl;
 std::cout << "compteur = " << compteur << std::endl;

 //for (unsigned i = 0; i<taille; ++i) c[i] = a[i]*b[i];
 for_parallele<1>(0, taille, [&](int i) { c[i] = a[i]*b[i]; });


 std::cout << "c = " << c << std::endl;

 return 0;
}

// Fin //-------------------------------------------------------------------------------------------
