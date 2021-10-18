// Entetes //---------------------------------------------------------------------------------------
#include "catch.hpp"

#include <iostream>
#include <demangle.hpp>
//#include <chaine.hpp>

// Tests //-----------------------------------------------------------------------------------------

template <typename T> std::string type_name(T && x) { return demangle(typeid(x).name()); }

//------------------------------------------------------------------------------------------------ 1
/*TEST_CASE ( "TP3_Chaine::Exception" ) {
 int erreur = 0;

 long i{};
 std::pair<short,long> p{};

 try { std::cout << "i = " << chaine(i) << std::endl; }

 catch (const ExceptionChaine & e) {
  std::string message1 = e.what();
  std::string message2 = "Conversion en chaine impossible pour '"+type_name(i)+"'";

  std::cout << "<null>" << std::endl;
  REQUIRE ( message1 == message2 );
  erreur=1;
 }

 REQUIRE ( erreur == 1 );

 try { std::cout << "p = " << chaine(p) << std::endl; }

 catch (const ExceptionChaine & e) {
  std::string message1 = e.what();
  std::string message2 = "Conversion en chaine impossible pour '"+type_name(p)+"'";

  std::cout << "<null>" << std::endl;
  REQUIRE ( message1 == message2 );
  erreur=2;
 }

 REQUIRE ( erreur == 2 );
}*/

//------------------------------------------------------------------------------------------------ 2
/*TEST_CASE ( "TP3_Chaine::ConversionSimple" ) {
 std::string n = "Smith";
 int i = 10;
 double d = 13.27;
 long j = 100;

 int erreur = 0;

 try { std::cout << "n = " << chaine(n) << std::endl; }
 catch (const ExceptionChaine & e) { erreur=1; }

 REQUIRE ( erreur == 0 );

 try { std::cout << "i = " << chaine(i) << std::endl; }
 catch (const ExceptionChaine & e) { erreur=2; }

 REQUIRE ( erreur == 0 );

 try { std::cout << "d = " << chaine(d) << std::endl; }
 catch (const ExceptionChaine & e) { erreur=3; }

 REQUIRE ( erreur == 0 );

 try { std::cout << "j = " << chaine(j) << std::endl; }

 catch (const ExceptionChaine & e) {
  std::string message1 = e.what();
  std::string message2 = "Conversion en chaine impossible pour '"+type_name(j)+"'";

  std::cout << "<null>" << std::endl;
  REQUIRE ( message1 == message2 );
  erreur=4;
 }

 REQUIRE ( erreur == 4 );
}*/

//------------------------------------------------------------------------------------------------ 3
/*TEST_CASE ( "TP3_Chaine::ConversionVariadic" ) {
 std::string n = "Smith";
 int i = 10;
 double d = 13.27;
 long j = 100;

 int erreur = 0;

 try { std::cout << "n,i,d = " << chaine(n,i,d) << std::endl; }
 catch (const ExceptionChaine & e) { erreur=1; }

 REQUIRE ( erreur == 0 );

 try { std::cout << "n,i,d,j = " << chaine(n,i,d,j) << std::endl; }

 catch (const ExceptionChaine & e) {
  std::string message1 = e.what();
  std::string message2 = "Conversion en chaine impossible pour '"+type_name(j)+"'";

  std::cout << "<null>" << std::endl;
  REQUIRE ( message1 == message2 );
  erreur=2;
 }

 REQUIRE ( erreur == 2 );
}*/

//------------------------------------------------------------------------------------------------ 4
/*TEST_CASE ( "TP3_Chaine::ConversionTuple1" ) {
 std::tuple<std::string,int,double>      t1{"Smith",10,13.27};
 std::tuple<std::string,int,double,long> t2{"Smith",10,13.27,100};

 int erreur = 0;

 try { std::cout << "t1 = " << chaine(t1) << std::endl; }
 catch (const ExceptionChaine & e) { erreur=1; }

 REQUIRE ( erreur == 0 );

 try { std::cout << "t2 = " << chaine(t2) << std::endl; }

 catch (const ExceptionChaine & e) {
  std::string message1 = e.what();
  std::string message2 = "Conversion en chaine impossible pour '"+type_name(std::get<3>(t2))+"'";

  std::cout << "<null>" << std::endl;
  REQUIRE ( message1 == message2 );
  erreur=2;
 }

 REQUIRE ( erreur == 2 );
}*/

//------------------------------------------------------------------------------------------------ 5
using Identite = std::tuple<std::string,std::string>; // {nom,prenom}
using Date = std::tuple<int,int,int>; // {jour,mois,annee}
using Coordonnees = std::tuple<double,double>; // {x,y}

/*TEST_CASE ( "TP3_Chaine::ConversionTuple2" ) {
 Identite    i = { "Smith", "John" };
 Date        d = { 13, 07, 2003 };
 Coordonnees c = { 1.234, 6.789 };

 int erreur = 0;

 try {
  std::cout << "i = " << chaine(i) << std::endl;
  std::cout << "d = " << chaine(d) << std::endl;
  std::cout << "c = " << chaine(c) << std::endl;
 }
 catch (const ExceptionChaine & e) { erreur=1; }

 REQUIRE ( erreur == 0 );
}*/

//------------------------------------------------------------------------------------------------ 6
using Personne = std::tuple<Identite,Date>;

/*TEST_CASE ( "TP3_Chaine::ConversionCompositionTuples" ) {
 Identite i = { "Smith", "John" };
 Date     d = { 13, 07, 2003 };
 Personne p = { i,d };

 int erreur = 0;

 try { std::cout << "p = " << chaine(p) << std::endl; }
 catch (const ExceptionChaine & e) { erreur=1; }

 REQUIRE ( erreur == 0 );
}*/

// Fin //-------------------------------------------------------------------------------------------
