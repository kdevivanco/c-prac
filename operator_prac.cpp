#include <iostream>
using namespace std;

class Puntos{
    public:
        int x;
        int y;
        Puntos(int b, int a){
            x = b;
            y = a;
        }

        int x_val(){
            return x;
        }

};

int main(){

    Puntos p(3,4); 

    cout << p.x;

    int b = p.x + p.y;
    cout << "b es" << b << endl;
    // int x = p.x_val();

    // cout << x << endl;


}

// class Car {        // The class
//   public:          // Access specifier
//     string brand;  // Attribute
//     string model;  // Attribute
//     int year;      // Attribute
//     Car(string x, string y, int z) { // Constructor with parameters
//       brand = x;
//       model = y;
//       year = z;
//     }
// };