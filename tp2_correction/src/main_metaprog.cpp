// Entetes //---------------------------------------------------------------------------------------
#include <iostream>
#include <cosinus.hpp>
#include <exponentielle.hpp>

// Pour regler la profondeur de recursion des templates: -ftemplate-depth-N
// ou N est la profondeur voulue.

// Fonction principale //---------------------------------------------------------------------------
int main(void) {
 std::cout << "5! = " << Factorielle<5>::valeur << std::endl;
 std::cout << "20! = " << Factorielle<25>::valeur << std::endl;

 std::cout << std::endl;
 std::cout << "5! = " << factorielle<5>() << std::endl;
 std::cout << "20! = " << factorielle<25>() << std::endl;

 // Test de vitesse
 // unsigned long n = 0;
 //
 // for (long i=0; i<1e8; ++i) n+=Factorielle<5>::valeur;
 // std::cout << "n = " << n << std::endl;
 //
 // n=0;
 // for (long i=0; i<1e8; ++i) n+=factorielle<5>(); // Plus long, meme avec inline...
 // std::cout << "n = " << n << std::endl;

 std::cout << std::endl;
 std::cout << "3^4 = " << Puissance<4>::valeur(3) << std::endl;
 std::cout << "2^8 = " << Puissance<8>::valeur(2) << std::endl;

 std::cout << std::endl;
 std::cout << "exp<5>(1) = " << Exponentielle<5>::valeur(1) << std::endl;
 std::cout << "exp<6>(1) = " << Exponentielle<6>::valeur(1) << std::endl;
 std::cout << "exp<7>(1) = " << Exponentielle<7>::valeur(1) << std::endl;
 std::cout << "exp<8>(1) = " << Exponentielle<8>::valeur(1) << std::endl;

 std::cout << std::endl;
 std::cout << "cos<3>(1) = " << Cosinus<3>::valeur(1) << std::endl;
 std::cout << "cos<4>(1) = " << Cosinus<4>::valeur(1) << std::endl;
 std::cout << "cos<5>(1) = " << Cosinus<5>::valeur(1) << std::endl;
 std::cout << "cos<6>(1) = " << Cosinus<6>::valeur(1) << std::endl;

 std::cout << std::endl;
 std::cout << "sin<3>(1) = " << Sinus<3>::valeur(1) << std::endl;
 std::cout << "sin<4>(1) = " << Sinus<4>::valeur(1) << std::endl;
 std::cout << "sin<5>(1) = " << Sinus<5>::valeur(1) << std::endl;
 std::cout << "sin<6>(1) = " << Sinus<6>::valeur(1) << std::endl;

 return 0;
}

// Fin //-------------------------------------------------------------------------------------------
