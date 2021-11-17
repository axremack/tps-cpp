#include <exception>
#include <string>

using namespace std;

class ExceptionChaine : public exception {
    private : 
        string description;
    public :
        ExceptionChaine(string); // Constructeur normal
        virtual const char * what() const noexcept;
};