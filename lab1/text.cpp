#include <iostream>
#include <cstring>
#include <string>
//#include <typeinfo>
//#include <algorithm>    // std::swap

#include "text.h"

using namespace std;
//construct
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
    // if(&other == this){
    //     return *this;
    // }

    // _sz = other._sz;
    // delete[]_text;
    // char* _text = new char[_sz+1];
    // strcpy(_text,other._text);
    // return *this;
        if (&other == this) {
        return *this;
    }

    _sz = other._sz;
    delete[] _text;
    _text = new char[_sz + 1];
    strcpy(_text, other._text);
    return *this;
}

Text Text::operator^(const Text& other){
    Text result;
    result._sz = _sz + other._sz;
    result._text = new char[result._sz + 1];
    strcpy(result._text, _text);
    strcat(result._text, other._text);
    return result;
}

Text &Text::operator ^=(const Text& other){
    strcat(this->_text,other._text);
    return *this;
}

istream& getline(istream& in, Text& text) {
    char buffer[text.getSize()];
    char c;
    int i = 0;
    while (in.get(c)) {
        if (c == '\n' || i == text.getSize() - 1) break;
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    // use the public getter method to access the size and text values
    int size = text.getSize();
    char *str = text.getText();
    delete[] str;
    str = new char[size + 1];
    strcpy(str, buffer);
    // use the public setter method to set the new values
    text.setText(str, size);
    return in;
}

ostream& operator<<(ostream& out, const Text& text) {
    out << text._text << endl;
    return out;
}
//Set text:
void Text::setText(const char* text, int size) {
        _sz = size;
        delete[] _text;
        _text = new char[_sz+1];
        strcpy(_text, text);
    }

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

// int main(){
//     Text text_1;
//     Text text_2;
//     Text text_3;
//     Text text_4;

//     getline(cin, text_1);
//     getline(cin, text_2);

//     text_3 = text_1 ^ text_2;
//     text_4 = text_1;
//     text_4 ^= "/CUARTO";

//     std::cout << "Texto 1: " << text_1 << std::endl;
//     std::cout << "Texto 2: " << text_2 << std::endl;
//     std::cout << "Texto 3: " << text_3 << std::endl;
//     std::cout << "Texto 4: " << text_4 << std::endl;
    
// }
