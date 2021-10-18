// Entetes //---------------------------------------------------------------------------------------
#include <vecteur.hpp>

// Implementation  V e c t e u r //-----------------------------------------------------------------

//--------------------------------------------------------------------------------------------Copier
void Vecteur::copier(const Vecteur & v) {
 if (capacite_<v.taille_) {
  if (elements_) delete [] elements_;
  capacite_=v.taille_;
  elements_=new int[capacite_];
 }

 taille_=v.taille_;
 for (int i=0; i<taille_; ++i) elements_[i]=v.elements_[i];
}

//-------------------------------------------------------------------------------------------Ajouter
void Vecteur::ajouter(int e) {
 if (taille_==capacite_) {
  int * tab = new int[2*capacite_];
  for (int i=0; i<capacite_; ++i) tab[i]=elements_[i];
  capacite_*=2;
  if (elements_) delete [] elements_;
  elements_=tab;
 }

 elements_[taille_++]=e;
}

// Implementation fonctions //----------------------------------------------------------------------

//---------------------------------------------------------------------------------------Operator <<
std::ostream & operator << (std::ostream & flux,const Vecteur & v) {
 for (Iterateur i = v.begin(); i!=v.end(); ++i) flux << *i << " ";
 return flux;
}

//--------------------------------------------------------------------------------------- Operator +
Vecteur operator + (const Vecteur & v1,const Vecteur & v2) {
 Vecteur v3 = v1;

 for (int i=0; i<v2.getTaille(); ++i) v3.ajouter(v2[i]);

 return v3;
}

//----------------------------------------------------------------------------------------Operator *
int operator * (const Vecteur & v1,const Vecteur & v2) {
 int r = 0;

 if (v1.getTaille()!=v2.getTaille()) throw std::string("Erreur produit scalaire");
 for (int i=0; i<v1.getTaille(); ++i) r+=v1[i]*v2[i];

 return r;
}

// Fin //-------------------------------------------------------------------------------------------
