#include <iostream>
#include <cmath>
#include <vector>

class Shape {
public:

    virtual double area() const = 0;

    virtual void draw() const = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:

    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    void draw() const override {
        std::cout << "Drawing a Circle with radius " << radius << "\n";
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
 
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }

    void draw() const override {
        std::cout << "Drawing a Rectangle with length " << length << " and width " << width << "\n";
    }
};

int main() {

    std::vector<Shape*> shapes;

    shapes.push_back(new Circle(5.0));         
    shapes.push_back(new Rectangle(4.0, 6.0)); 

    for (const auto& shape : shapes) {
        shape->draw();
        std::cout << "Area: " << shape->area() << "\n";
        std::cout << "-----------------------\n";
    }

    for (auto& shape : shapes) {
        delete shape;
    }

    return 0;
}
