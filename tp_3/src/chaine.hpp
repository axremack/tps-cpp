#ifndef CHAINE
#define CHAINE

#include "exception.hpp"
#include "demangle.hpp"
#include <string>
#include <sstream>

using namespace std;

// Exception et templates
template <typename T>
string chaine (T x) {
    throw ExceptionChaine(demangle(typeid(x).name()));
}

template <>
string chaine<string> (string x) {
    return x;
}

template <>
string chaine<int> (int x) {
    stringstream ss;
    string res;

    ss << x;
    ss >> res;

    if (ss.fail()) {
        throw ExceptionChaine(demangle(typeid(x).name()));
    }

    return res;
}

template <>
string chaine<double> (double x) {
    stringstream ss;
    string res;

    ss << x;
    ss >> res;

    if (ss.fail()) {
        throw ExceptionChaine(demangle(typeid(x).name()));
    }

    return res;
}


// Variadic template
template <typename... T>
string chaine (T... x) {
    string res;

    res = (chaine(x), ...); // Appel de la fonction chaine pour chacun des paramètres donnés
    
    return res;
}


template <typename T, size_t... Is>
string chaine_bis(const T & t, index_sequence<Is...>) {
    return chaine(get<Is>(t)...);
}

template <typename... Ts>
string chaine (const tuple<Ts ...> & t) { // permet de contraindre aux tuples
    string res;
    res = chaine_bis(t, make_index_sequence< sizeof...(Ts) >());
    
    return res;
}
// permet le traitement à la compilation




#endif