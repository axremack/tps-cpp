// Gardien //---------------------------------------------------------------------------------------
#ifndef _CARTESIEN_HPP_
#define _CARTESIEN_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <point.hpp>

// Classe  C a r t e s i e n //---------------------------------------------------------------------
class Cartesien : public Point {
 //----------------------------------------------------------------------------------------Attributs
 protected: double x_;
 protected: double y_;
 //---------------------------------------------------------------------------------------Accesseurs
 public: double getX() const { return x_; }
 public: double getY() const { return y_; }

 public: void setX(double x) { x_=x; }
 public: void setY(double y) { y_=y; }
 //------------------------------------------------------------------------------------Constructeurs
 public: Cartesien(void) : x_(0.0),y_(0.0) {}
 public: Cartesien(double x,double y) : x_(x),y_(y) {}
 public: Cartesien(const Polaire &);
 //-------------------------------------------------------------------------------Methodes publiques
 public: void afficher(std::ostream &) const;
 public: void charger(std::istream &);
 public: void convertir(Cartesien &) const;
 public: void convertir(Polaire &) const;
};

// Fin //-------------------------------------------------------------------------------------------
#endif
