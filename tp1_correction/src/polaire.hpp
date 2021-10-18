// Gardien //---------------------------------------------------------------------------------------
#ifndef _POLAIRE_HPP_
#define _POLAIRE_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <point.hpp>

// Constantes //------------------------------------------------------------------------------------
const double PI = 3.14159265359;

// Classe  P o l a i r e //-------------------------------------------------------------------------
class Polaire : public Point {
 //----------------------------------------------------------------------------------------Attributs
 protected: double angle_; // en degres
 protected: double distance_;
 //---------------------------------------------------------------------------------------Accesseurs
 public: double getAngle(void) const { return angle_; }
 public: double getDistance(void) const { return distance_; }

 public: void setAngle(double angle) { angle_=angle; }
 public: void setDistance(double distance) { distance_=distance; }
 //------------------------------------------------------------------------------------Constructeurs
 public: Polaire(void) : angle_(0.0),distance_(0.0) {}
 public: Polaire(double angle,double distance) : angle_(angle),distance_(distance) {}
 public: Polaire(const Cartesien &);
 //-------------------------------------------------------------------------------Methodes publiques
 public: void afficher(std::ostream &) const;
 public: void charger(std::istream &);
 public: void convertir(Cartesien &) const;
 public: void convertir(Polaire &) const;
};

// Fin //-------------------------------------------------------------------------------------------
#endif
