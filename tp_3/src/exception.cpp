#include "exception.hpp"
#include <iostream>

using namespace std;

ExceptionChaine::ExceptionChaine(string t) : description("Conversion en chaine impossible pour '" + t + "'") { }

const char * ExceptionChaine::what() const noexcept {
    return description.c_str();
}