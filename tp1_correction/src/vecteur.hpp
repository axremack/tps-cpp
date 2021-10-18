// Gardien //---------------------------------------------------------------------------------------
#ifndef _VECTEUR_HPP_
#define _VECTEUR_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <iostream>

// Declarations anticipees //-----------------------------------------------------------------------
class Iterateur;
class Vecteur;

// Declarations fonctions //------------------------------------------------------------------------
std::ostream & operator << (std::ostream &,const Vecteur &);
Vecteur        operator + (const Vecteur &,const Vecteur &);
int            operator * (const Vecteur &,const Vecteur &);

// Classe  I t e r a t e u r //---------------------------------------------------------------------
class Iterateur {
 //----------------------------------------------------------------------------------------Attributs
 protected: int * position_;
 //------------------------------------------------------------------------------------Constructeurs
 public: Iterateur(int * p) : position_(p) {}
 //-------------------------------------------------------------------------------Methodes publiques
 public: Iterateur & operator ++ (void) { ++position_; return (*this); }
 public: Iterateur   operator ++ (int) { Iterateur i(position_); ++position_; return i; }

 public: bool operator == (const Iterateur & i) const { return position_==i.position_; }
 public: bool operator != (const Iterateur & i) const { return position_!=i.position_; }

 public: int operator * (void) const { return *position_;}
};

// Classe  V e c t e u r //-------------------------------------------------------------------------
class Vecteur {
 //----------------------------------------------------------------------------------------Attributs
 protected: int * elements_;
 protected: int taille_;
 protected: int capacite_;
 //---------------------------------------------------------------------------------------Accesseurs
 public: Iterateur begin(void) const { return Iterateur(elements_); }
 public: Iterateur end(void) const { return Iterateur(elements_+taille_); }

 public: int getTaille(void) const { return taille_; }
 public: int getCapacite(void) const { return capacite_; }

 public: int operator [] (int i) const { return elements_[i]; }
 public: int & operator [] (int i) { return elements_[i]; }
 //------------------------------------------------------------------------------------Constructeurs
 public: explicit Vecteur(int c = 100) : elements_(new int[c]),taille_(0),capacite_(c) {}
 public: Vecteur(const Vecteur & v) : elements_(0),taille_(0),capacite_(0) { copier(v); }
 //---------------------------------------------------------------------------------Methodes privees
 protected: void copier(const Vecteur & v);
 //-------------------------------------------------------------------------------Methodes publiques
 public: Vecteur & operator = (const Vecteur & v) { copier(v); return (*this); }

 public: void ajouter(int);
 public: void retirer(void) { if (taille_>0) --taille_; }

 public: ~Vecteur(void) { if (elements_) delete [] elements_; }
};

// Fin //-------------------------------------------------------------------------------------------
#endif
