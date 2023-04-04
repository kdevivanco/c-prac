#include<iostream>
using namespace std;
//Ejemplo objetos constantes
class Point{
	int x = 0;
	int y = 0;

    Point() default;
    Point(int x, int y): x(x), y(y){}

    int get_x() const {return x;}
    int get_y()  const {return y;} //habilita const

    void set_x(int value){ x = value; }
    void set_y(int value){ y = value; }

};

void ejemplo_objetos_constantes(){
    Point p1;
    p1.set_x(10);
    p1.set_y(20);

    cout << p1.get_x() << " " << p1.get_y() << endl;

    const Point p2(100,200);
    cout << p2.get_x() << " " << p2.get_y() << endl;
}

