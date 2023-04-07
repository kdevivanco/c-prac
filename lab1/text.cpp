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

Text &Text::operator^(const Text& other){
    // Use strcat() to concat two specified string
    
    Text text_temp(this->_text);

    strcat(text_temp._text,other._text);

    return text_temp;
    
    // strcat(this->_text, other._text);
    

    // _sz = strlen(this->_text);
    // this->_text = new char[_sz+1];
    // strcpy(_text,text);

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

int main(){
    cout<<"Constructor basico:\n";
    Text t1("Hello, world!");
    cout << t1 << endl;
    
    cout<<"Constructor copia:\n";
    Text t3 = Text(t1);
    cout << t3 <<endl;

    cout<<"Asignacion copia:\n";
    Text t2 = t1;
    cout<<t2 <<endl;
    // return 0;

    cout<<"Concatenacion uno:\n";
    Text text_3;
    text_3= t1^t2;
    cout << text_3 << endl;

    cout<<"Text 1 deberia ser Hello, world!\n:";
    cout << t1;
    // t1 ^ t2;
    // cout << t1;


    // Text text_2;
    // cout << "ingresa tu texto: ";
    // std::cin >> text_2;
    // //std::cout << typeid(text_2).name() << '\n';
    // cout << text_2 << endl;

    
}




 