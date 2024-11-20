#include <iostream>
using namespace std;

class Complex {
private:
    double real; 
    double imag; 

public:
  
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

  
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

  
    void display() const {
        cout << real << " + " << imag << "j";
    }
};

int main() {
    // Creating two Complex objects
    Complex c1(4, 7); // 4 + 7j
    Complex c2(1, 3); // 1 + 3j


    Complex result = c1 - c2;


    cout << "First complex number: ";
    c1.display();
    cout << "\nSecond complex number: ";
    c2.display();
    cout << "\nResult of subtraction: ";
    result.display();
    cout << endl;

    return 0;
}
