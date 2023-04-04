#include <iostream>
#include <cstring>
#include<string>
#include <typeinfo>
#include <algorithm>    // std::swap

#include "text.h"

using namespace std;
//construct
// Constructor por parametros
Text::Text(const char* text) {
    _sz = strlen(text);
    _text = new char[_sz+1];
    strcpy(_text,text);
}

//constructor copia
Text::Text(const Text& other){
    if(&other == this){
        return;
    }
    _sz = other._sz;
    _text = new char[_sz +1];
    strcpy(_text,other._text);
}

//asignacion copia: 
Text &Text::operator = (const Text& other){
    if(&other == this){
        return *this;
    }

    _sz = other._sz;
    delete[]_text;
    char* _text = new char[_sz+1];
    strcpy(_text,other._text);
    return *this;
}


ostream& operator<<(ostream& out, const Text& text) {
    out << text._text << endl;
    return out;
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
    text._sz = strlen(buffer);
    delete[] text._text;
    text._text = new char[text._sz+1];
    strcpy(text._text, buffer);
    return in;

    // string input;
    // getline(in, input);
    // text = input;
    // return in;
}

int main(){
    Text t1("Hello, world!");
    cout << t1 << endl;
    

    Text t2;
    t2 = t1;
    cout<<t1;
    // return 0;

    Text text_2;
    cout << "ingresa tu texto: ";
    std::cin >> text_2;
    //std::cout << typeid(text_2).name() << '\n';
    cout << text_2 << endl;
}

