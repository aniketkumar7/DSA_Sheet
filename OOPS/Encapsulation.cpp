// ENCAPSULATION

// Encapsulation is the process of wrapping up of data and functions into a single unit called class. It is a way to restrict access to the data in a class and prevent it from being modified by external code. Encapsulation is used to hide the values or state of a structured data object inside a class, preventing direct access to them by clients in a way that could expose hidden implementation details or violate the integrity of the data.

// Encapsulation is a fundamental concept in object-oriented programming (OOP). It is the technique of making the fields in a class private and providing access to the fields via public methods. It is a protective barrier that keeps the data safe within the class and prevents the data from being modified by external code.

// Access Specifiers in C++
// Access specifiers are used to define the access control for the members of a class. There are three types of access specifiers in C++:

// Public: Members of a class that are declared as public can be accessed from anywhere in the program. The data members and member functions that are declared as public can be accessed by other classes and functions.

// Private: Members of a class that are declared as private can only be accessed within the class. The data members and member functions that are declared as private cannot be accessed by other classes and functions.

// Protected: Members of a class that are declared as protected can be accessed within the class and by its derived classes. The data members and member functions that are declared as protected can be accessed by the derived classes but not by other classes.

// Example of Encapsulation in C++

#include <iostream>
using namespace std;

class Employee
{
    private:
        // Private attribute
        int salary;

    public:
        // Setter
        void setSalary(int s)
        {
            salary = s;
        }

        // Getter
        int getSalary()
        {
            return salary;
        }
};

int main()
{
    Employee emp;
    emp.setSalary(50000);
    cout << "Salary: " << emp.getSalary() << endl;
}