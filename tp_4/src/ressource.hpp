#ifndef RESSOURCE
#define RESSOURCE

using namespace std;

class Ressource {
    private :
        int stock;
    public :
        Ressource(int);
        int getStock() const;
        void setStock(int);
        void consommer(int);
        
};


#endif