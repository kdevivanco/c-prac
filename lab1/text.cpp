#include <iostream>
#include <cstring>
#include <string>

#include "text.h"

using namespace std;
// Constructor por parametros
Text::Text(const char* text) {
    _sz = strlen(text);
    _text = new char[_sz+1];
    strcpy(_text,text);
}

// Constructor that takes a std::string parameter
Text::Text(const std::string& str) {
    _sz = str.size();
    _text = new char[_sz+1];
    strcpy(_text, str.c_str());
}

//constructor copia
Text::Text(const Text& other){
    if(&other == this){
        return;
    }
    _sz = other._sz;
    _text = new char[_sz +1];
    strcpy(_text,other._text);
    this->setText(_text, _sz);
}

//Constructor por parametro string: 
Text& Text::operator=(const std::string& text) {
    setText(text.c_str(), text.length());
    return *this;
}

//asignacion copia: 
Text &Text::operator= (const Text& other){
        if (&other == this) {
        return *this;
    }

    _sz = other._sz;
    delete[] _text;
    _text = new char[_sz + 1];
    strcpy(_text, other._text);
    return *this;
}

//Sobre carga del operador ^
Text Text::operator^(const Text& other){
    Text result;
    result._sz = _sz + other._sz;
    result._text = new char[result._sz + 1];
    strcpy(result._text, _text);
    strcat(result._text, other._text);
    return result;
}

//Sobre carga del operador ^=
Text &Text::operator ^=(const Text& other){
    strcat(this->_text,other._text);
    return *this;
}

//Sobre carga de getline
istream& getline(istream& in, Text& text) {
    char buffer[text.getSize()];
    char c;
    int i = 0;
    while (in.get(c)) {
        if (c == '\n' || i == text.getSize() - 1) break;
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    int size = text.getSize();
    char *str = text.getText();
    delete[] str;
    str = new char[size + 1];
    strcpy(str, buffer);
    text.setText(str, size);
    return in;
}

//Sobre carga cout
ostream& operator<<(ostream& out, const Text& text) {
    out << text._text << endl;
    return out;
}

//Set text func
void Text::setText(const char* text, int size) {
        _sz = size;
        delete[] _text;
        _text = new char[_sz+1];
        strcpy(_text, text);
    }

//Sobre carga cin >>
istream &operator>>(istream& in, Text& text) {
    char buffer[text.getSize()];
    char c;
    int i = 0;
    while (in.get(c)) {
        if (c == '\n' || i == text.getSize() - 1) break;
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    // llamamos a los metodos publicos para poder acceder a las variables privadas y crear nuevo size y text
    int size = text.getSize();
    char* str = text.getText();
    // destruye para poder ocupar ese nuevo sitio en memoria
    delete[] str;
    //creas espacio en memoria
    str = new char[size+1];
    //copias al nuevo objeto
    strcpy(str, buffer);
    //llamamos al metodo publico setText y le pasamos los datos obtenidos
    text.setText(str, size);
    return in;
}


