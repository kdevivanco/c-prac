#include <iostream>
#include <string> 
using namespace std;


class GradeBook{

    public: 

    void setCourseName(string name){
        courseName = name;
    }

    string getCourseName() const{
        return courseName;
    }

    void displayMessage() const{
        cout << "Welcome to the gradebook for \n" << getCourseName() << "!" << endl;

    }

    private:
    string courseName;

};

int main(){

    //Declare variables
    string nameOfCourse;
    GradeBook gradebook;

    cout << "Initial value of coursename is: " << gradebook.getCourseName() << endl;


    nameOfCourse = "Computer Science 50";
    cout << "Inventing without using cin" << nameOfCourse << endl;

    gradebook.setCourseName(nameOfCourse);

    gradebook.displayMessage();


}