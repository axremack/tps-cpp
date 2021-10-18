// Gardien //---------------------------------------------------------------------------------------
#ifndef _NUAGE_HPP_
#define _NUAGE_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <vector>
#include <cartesien.hpp>
#include <polaire.hpp>

// Declarations anticipees //-----------------------------------------------------------------------
template <typename T> class Nuage;

// Declarations fonctions //------------------------------------------------------------------------
template <typename T> T                      barycentre_v1(const Nuage<T> &);
template <typename C> typename C::value_type barycentre_v2(const C &);

// Classe  N u a g e //-----------------------------------------------------------------------------
template <typename T> class Nuage {
 //--------------------------------------------------------------------------------------------Types
 public: typedef typename std::vector<T>::iterator       iterator;
 public: typedef typename std::vector<T>::const_iterator const_iterator;
 public: typedef typename std::vector<T>::value_type     value_type;
 //----------------------------------------------------------------------------------------Attributs
 protected: std::vector<T> points_;
 //---------------------------------------------------------------------------------------Accesseurs
 public: unsigned size(void) const { return points_.size(); }

 public: typename std::vector<T>::const_iterator begin(void) const { return points_.begin(); }
 public: typename std::vector<T>::const_iterator end(void) const { return points_.end(); }

 public: typename std::vector<T>::iterator begin(void) { return points_.begin(); }
 public: typename std::vector<T>::iterator end(void) { return points_.end(); }
 //-------------------------------------------------------------------------------Methodes publiques
 public: void ajouter(const T & point) { points_.push_back(point); }
};

// Implementation fonctions //----------------------------------------------------------------------

//----------------------------------------------------------------------------------Barycentre_v1<T>
template <typename T> T barycentre_v1(const Nuage<T> & nuage) {
 Cartesien c;
 double x = 0.0;
 double y = 0.0;
 int n = 0;

 for (typename Nuage<T>::const_iterator i = nuage.begin(); i!=nuage.end(); ++i) {
  //i->convertir(c); // Methode virtuelle
  c=(Cartesien)(*i); // Methode concrete
  x+=c.getX();
  y+=c.getY();
  ++n;
 }

 return (n==0 ? T() : T(Cartesien(x/n,y/n)));
}

//----------------------------------------------------------------------------Barycentre_v1<Polaire>
template <> Polaire barycentre_v1<Polaire>(const Nuage<Polaire> & nuage) {
 double a = 0.0;
 double d = 0.0;
 int n = 0;

 for (Nuage<Polaire>::const_iterator i = nuage.begin(); i!=nuage.end(); ++i) {
  a+=i->getAngle();
  d+=i->getDistance();
  ++n;
 }

 return (n==0 ? Polaire() : Polaire(a/n,d/n)); // Formule fausse bien entendu !
}

//----------------------------------------------------------------------------------Barycentre_v2<T>
template <typename C> typename C::value_type barycentre_v2(const C & container) {
 Cartesien c;
 double x = 0.0;
 double y = 0.0;
 int n = 0;

 for (typename C::const_iterator i = container.begin(); i!=container.end(); ++i) {
  c=(Cartesien)(*i);
  x+=c.getX();
  y+=c.getY();
  ++n;
 }

 typedef typename C::value_type point_t;

 return (n==0 ? point_t() : point_t(Cartesien(x/n,y/n)));
}

// Fin //-------------------------------------------------------------------------------------------
#endif
