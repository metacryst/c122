#include <iostream>
using namespace std;

class Complex {
private:
    double real; 
    double imaginary;

public:
    Complex() {
        real = 1;
        imaginary = 1;
    }

    double getReal const() {
        return this->real;
    }

    double getImaginary const() {
        return this->imaginary;
    }

};

ostream & operator<< (ostream &lhs, const Complex &rhs) {
    lhs << rhs.getReal() << " + " << rhs.getImaginary() << "i" << endl;
    return lhs;
};