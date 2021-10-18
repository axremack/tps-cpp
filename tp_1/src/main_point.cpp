#include <cstdlib>
#include <iostream>
#include <vector>


#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"
#include "nuage.hpp"

using namespace std;



// -----------------------------------------------
// MAIN
// -----------------------------------------------
int main() {

    Cartesien p1(12.0,24.0);
    Polaire p2(13.0,25.0);
    Polaire p3(p1);
    Cartesien p4(p2);

    vector<Point *> v;

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    for(Point * elt : v) {
        cout << elt << endl; // Utilisation de l'opérateur de flux surchargé
    }
    // Il faut des pointeurs sinon on ne peut pas afficher


    return EXIT_SUCCESS;
}
