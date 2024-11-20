#include <iostream>
#include <string>
#include <vector>

// Base class
class Animal {
private:
    std::string name;
    std::string sound;

public:

    void setName(const std::string& name) {
        this->name = name;
    }

    std::string getName() const {
        return name;
    }

    void setSound(const std::string& sound) {
        this->sound = sound;
    }

    std::string getSound() const {
        return sound;
    }

    virtual void makeSound() const = 0; 
    virtual void displayDetails() const = 0; 

    virtual ~Animal() {}
};


class Dog : public Animal {
public:
    Dog(const std::string& name) {
        setName(name);
        setSound("Woof!");
    }

    void makeSound() const override {
        std::cout << getName() << " says: " << getSound() << "\n";
    }

    void displayDetails() const override {
        std::cout << "Dog Details:\n";
        std::cout << "Name: " << getName() << "\n";
        std::cout << "Sound: " << getSound() << "\n";
    }
};

// Derived class: Cat
class Cat : public Animal {
public:
    Cat(const std::string& name) {
        setName(name);
        setSound("Meow!");
    }

    void makeSound() const override {
        std::cout << getName() << " says: " << getSound() << "\n";
    }

    void displayDetails() const override {
        std::cout << "Cat Details:\n";
        std::cout << "Name: " << getName() << "\n";
        std::cout << "Sound: " << getSound() << "\n";
    }
};

int main() {
    // Create an array of Animal pointers
    std::vector<Animal*> animals;

    // Add Dog and Cat objects to the array
    animals.push_back(new Dog("Buddy"));
    animals.push_back(new Cat("Whiskers"));

    // Demonstrate polymorphism
    std::cout << "Animal Details:\n";
    for (const auto& animal : animals) {
        animal->displayDetails();
        std::cout << "--------------------------\n";
    }

    // Free allocated memory
    for (auto& animal : animals) {
        delete animal;
    }

    return 0;
}
