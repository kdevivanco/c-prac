#ifndef PROG3_UNIT1_TEXT_V2023_1_TEXT_H
#define PROG3_UNIT1_TEXT_V2023_1_TEXT_H
#include <iosfwd>
#include <string>
#include <cstring>
using namespace std;

class Text {
public:
    //Constructor por defecto, tambien puede ser Text(){}
    Text() = default;
    // Constructor por parametros
    Text(const char* text);
    //Constructor copia 
    Text(const Text& other);
    //Constructor string:
    Text(const std::string& str);
    //Asignacion copia: 
    Text& operator= (const Text& other);
    Text& operator=(const std::string& text);
    //Text& operator^=(const Text& other);

    //Set text
    void setText(const char* text, int size);


    int getSize() const { return _sz; }
    char* getText() const {return _text; }
    

    //Asignacion copia para string: 
    // Text& operator=(const string& text);

    Text& operator^(const Text& other);
    Text& operator ^=(const Text& other);
    operator string() const{
        return std::string(_text);
    };

    //Sobre carga COUT
    friend ostream& operator<<(ostream& out, const Text& text);

    //Sobre carga CIN 
    friend istream& operator>>(istream&& in, Text& text); //no lleva const, por que?
    friend istream& getline(istream& in, Text& text);
    

private:
    char* _text = nullptr; //iniciacion in class. Como es puntero = nullptr
    int _sz = 0; //iniciacion in class (porque se le asigna un valor)
    // void setString(const char* str) {
    //     _sz = strlen(str);
    // }
};
//ostream operator<<(ostream& out, const Text& text);
istream &operator>> (istream &in, Text& text);
istream& getline(istream& in, Text& text);
#endif