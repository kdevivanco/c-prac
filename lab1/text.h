#ifndef PROG3_UNIT1_TEXT_V2023_1_TEXT_H
#define PROG3_UNIT1_TEXT_V2023_1_TEXT_H
#include <iosfwd>
#include <string>
using namespace std;

class Text {
public:
    //Constructor por defecto, tambien puede ser Text(){}
    Text() = default;
    // Constructor por parametros
    Text(const char* text);
    //Constructor copia 
    Text(const Text& other);
    //Asignacion copia: 
    Text& operator= (const Text& other);

    //Sobre carga COUT
    friend ostream& operator<<(ostream& out, const Text& text);

    //Sobre carga CIN 
    friend istream& operator>>(istream&& in, Text& text); //no lleva const, por que?

    int getSize() const { return _sz; }
    char* getText() const {return _text; }

private:
    char* _text = nullptr; //iniciacion in class. Como es puntero = nullptr
    int _sz = 0; //iniciacion in class (porque se le asigna un valor)
    // void setString(const char* str) {
    //     _sz = strlen(str);
    // }
};
// istream &operator>> (istream &in, const Text &text);

#endif