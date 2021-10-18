// Gardien //---------------------------------------------------------------------------------------
#ifndef _NUAGE_HPP_
#define _NUAGE_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <vector>
#include <cartesien.hpp>
#include <polaire.hpp>

// Declarations anticipees //-----------------------------------------------------------------------
class Nuage;

// Declarations fonctions //------------------------------------------------------------------------
Cartesien barycentre(const Nuage &);

// Classe  N u a g e //-----------------------------------------------------------------------------
class Nuage {
 //---------------------------------------------------------------------------------------------Type
 public: typedef std::vector<Point *>::iterator       iterator;
 public: typedef std::vector<Point *>::const_iterator const_iterator;
 //----------------------------------------------------------------------------------------Attributs
 protected: std::vector<Point *> points_;
 //---------------------------------------------------------------------------------------Accesseurs
 public: unsigned size(void) const { return points_.size(); }

 public: std::vector<Point *>::const_iterator begin() const { return points_.begin(); }
 public: std::vector<Point *>::const_iterator end() const { return points_.end(); }

 public: std::vector<Point *>::iterator begin() { return points_.begin(); }
 public: std::vector<Point *>::iterator end() { return points_.end(); }
 //-------------------------------------------------------------------------------Methodes publiques
 public: void ajouter(Point * point) { points_.push_back(point); }
 public: void ajouter(Point & point) { points_.push_back(&point); }
};

// Classe  B a r y c e n t r e C a r t e s i e n //-------------------------------------------------
class BarycentreCartesien {
 public: Cartesien operator () (const Nuage & nuage) { return barycentre(nuage); }
};

// Classe  B a r y c e n t r e P o l a i r e //-----------------------------------------------------
class BarycentrePolaire {
 public: Polaire operator () (const Nuage & nuage) { return Polaire(barycentre(nuage)); }
};

// Fin //-------------------------------------------------------------------------------------------
#endif
