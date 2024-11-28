// INHERITANCE

// Inheritance is the process by which one class acquires the properties and functionalities of another class. The class that inherits the properties of another class is called the derived class, and the class whose properties are inherited is called the base class. Inheritance is also known as generalization or specialization.

// Inheritance allows the derived class to reuse the properties and functionalities of the base class, reducing code duplication and promoting code reusability. It enables the creation of a hierarchy of classes with increasing levels of specialization, where each derived class inherits the properties of its base class and adds new features or modifies existing ones.

// There are different types of inheritance in C++:

// Single inheritance: A derived class inherits from a single base class.
// Multiple inheritance: A derived class inherits from multiple base classes.
// Multilevel inheritance: A derived class inherits from another derived class.
// Hierarchical inheritance: Multiple derived classes inherit from a single base class.
// Hybrid inheritance: Combination of multiple and multilevel inheritance.

// Example of Inheritance in C++

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking" << endl;
    }
};

int main() {
    // Creating an object of the derived class
    Dog dog;

    // Calling functions from the base and derived classes
    dog.eat(); // Output: Animal is eating
    dog.bark(); // Output: Dog is barking

    return 0;
}