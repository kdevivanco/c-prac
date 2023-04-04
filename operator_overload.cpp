#include <iostream>
using namespace std;

class Point { // define a class named Point
public:
    Point(int x, int y) : x_(x), y_(y) {} // constructor that initializes the x and y coordinates
    Point operator+(const Point& other) const { // overload the + operator as a member function of the Point class
        cout<< x_ << "+" << y_ << endl;
        return Point(x_ + other.x_, y_ + other.y_); // add the x and y coordinates of the two points and return a new Point object
    }
public:
    int x_, y_; // private member variables representing the x and y coordinates of the point
};

int main() {
    Point p1(1, 2); // create a Point object with x=1 and y=2
    Point p2(3, 4); // create another Point object with x=3 and y=4
    Point p3 = p1 + p2; // add the two Point objects together using the overloaded + operator and store the result in a new Point object named p3
    //cout << p3 << endl;
    //cout << p1 << endl;
    return 0; // end the program
}

