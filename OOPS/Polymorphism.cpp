// POLYMORPHISM

// Polymorphism is the ability to call the same function on different objects and get different results. It allows objects of different classes to be treated as objects of a common base class, enabling dynamic binding and runtime polymorphism.

// Polymorphism is a key concept in object-oriented programming (OOP) that allows objects of different classes to be treated as objects of a common base class. It enables the same function to be called on different objects and get different results based on the actual object type.

// There are two main types of polymorphism in C++:

// Compile-time polymorphism: This type of polymorphism is achieved using function overloading and operator overloading. It allows different functions or operators to be defined with the same name but different parameters or behaviors.

// Example of Compile-time Polymorphism in C++

class Math {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};



// Run-time polymorphism: This type of polymorphism is achieved using virtual functions and inheritance. It allows a function to be defined in a base class and overridden in derived classes, enabling dynamic binding and runtime polymorphism.

// Example of Polymorphism in C++

#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

// Derived class Circle
class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a circle" << endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    void draw() {
        cout << "Drawing a rectangle" << endl;
    }
};

int main() {
    // Creating objects of Circle and Rectangle
    Circle circle;
    Rectangle rectangle;

    // Calling the draw function on different objects
    circle.draw();
    rectangle.draw();

    return 0;
}


// In this example, the Shape class is a base class with a virtual function draw(). The Circle and Rectangle classes are derived classes that override the draw() function with their own implementations. The main function creates objects of the Circle and Rectangle classes and calls the draw() function on them, resulting in different outputs based on the actual object type.