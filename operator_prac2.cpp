#include <iostream>


class Person {
public:
    Person(std::string name, int age) : name_(name), age_(age) {}
    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << "Name: " << person.name_ << ", Age: " << person.age_;
        return os;
    }
private:
    std::string name_;
    int age_;
};

int main() {
    Person p("Alice", 25);
    std::cout << p << std::endl; // calls operator<< overload
    return 0;
}
