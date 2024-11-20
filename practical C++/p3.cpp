#include <iostream>
#include <string>

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
};

class Cat : public Animal {
public:

    Cat(const std::string& name) {
        setName(name);
        setSound("Meow!");
    }

    void makeSound() const override {
        std::cout << getName() << " says: " << getSound() << "\n";
    }
};

int main() {

    Dog dog("Buddy");
    Cat cat("Whiskers");

    std::cout << "Animal Sounds:\n";
    dog.makeSound();
    cat.makeSound();

    return 0;
}
