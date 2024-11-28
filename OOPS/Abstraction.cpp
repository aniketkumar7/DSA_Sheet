// ABSTRACTION

// Abstraction is the concept of hiding the internal implementation of an object and showing only the necessary features of an object.
// Abstraction is used to hide the complexity of a system and only show the necessary details to the user.

// It can be achieved by using various techniques such as abstract classes, interfaces, and virtual functions in C++.
/**
 * ABSTRACTION
 *
 * Abstraction is the concept of hiding the internal implementation details
 * of an object and exposing only the necessary features to the outside world.
 *
 * Key benefits:
 * - Reduces complexity by hiding unnecessary details
 * - Shows only essential features to the user
 * - Simplifies system interaction and usage
 *
 * Implementation techniques in C++:
 * - Abstract classes
 * - Interfaces
 * - Virtual functions
 */


#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;
};

// Concrete class Circle
class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a circle" << endl;
    }
};

int main() {
    // Creating an object of Circle
    Circle circle;
    circle.draw();

    return 0;
}

// In this example, the Shape class is an abstract class with a pure virtual function draw(). The Circle class is a concrete class that inherits from the Shape class and implements the draw() function. The main function creates an object of the Circle class and calls the draw() function to draw a circle.


// Pure virtual functions in C++
// A pure virtual function is a virtual function that has no implementation in the base class and must be overridden in the derived classes. It is declared using the syntax virtual void functionName() = 0;.
// A class containing one or more pure virtual functions is called an abstract class, and it cannot be instantiated. Derived classes must provide implementations for all the pure virtual functions to be considered concrete classes.
// Pure virtual functions are used to achieve abstraction in C++ by defining an interface that must be implemented by the derived classes. They allow the base class to define a common interface for a group of related classes without specifying the exact implementation details.

//Virtual functions in C++
// Virtual functions are member functions that are declared as virtual in the base class and can be overridden in the derived classes. They allow the derived classes to provide their own implementation of the function, which is called at runtime based on the actual object type.
// Virtual functions are used to achieve polymorphism in C++ by allowing objects of different classes to be treated as objects of a common base class. They enable dynamic binding, where the function call is resolved at runtime based on the actual object type rather than the reference or pointer type.