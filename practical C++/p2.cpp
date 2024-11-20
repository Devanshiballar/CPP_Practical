#include <iostream>
#include <string>
#include <vector>

class Person {
private:
    std::string name;
    int age;
    std::string address;

public:

    Person(const std::string& name, int age, const std::string& address)
        : name(name), age(age), address(address) {}

    void setName(const std::string& name) {
        this->name = name;
    }

    std::string getName() const {
        return name;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getAge() const {
        return age;
    }

    void setAddress(const std::string& address) {
        this->address = address;
    }

    std::string getAddress() const {
        return address;
    }

    void display() const {
        std::cout << "Name: " << name << "\n"
                  << "Age: " << age << "\n"
                  << "Address: " << address << "\n";
    }
};

int main() {
    int n;

    std::cout << "Enter the number of persons: ";
    std::cin >> n;

    std::vector<Person> persons;

    for (int i = 0; i < n; ++i) {
        std::cin.ignore(); 
        std::string name, address;
        int age;

        std::cout << "Enter details for person " << i + 1 << ":\n";

        std::cout << "Name: ";
        std::getline(std::cin, name);

        std::cout << "Age: ";
        std::cin >> age;

        std::cin.ignore();
        std::cout << "Address: ";
        std::getline(std::cin, address);

   
        persons.emplace_back(name, age, address);
    }

    std::cout << "\nDetails of all persons:\n";
    for (size_t i = 0; i < persons.size(); ++i) {
        std::cout << "Person " << i + 1 << ":\n";
        persons[i].display();
        std::cout << "--------------------------\n";
    }

    return 0;
}
