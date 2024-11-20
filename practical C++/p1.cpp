#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    int publishedYear;

    Book(const std::string& t, const std::string& a, int year)
        : title(t), author(a), publishedYear(year) {}

    void display() const {
        std::cout << "Title: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "Published Year: " << publishedYear << "\n";
    }
};

int main() {

    Book books[] = {
        Book("The Great Gatsby", "F. Scott Fitzgerald", 1925),
        Book("1984", "George Orwell", 1949),
        Book("To Kill a Mockingbird", "Harper Lee", 1960)
    };

    int numBooks = sizeof(books) / sizeof(books[0]);

    for (int i = 0; i < numBooks; ++i) {
        std::cout << "Book " << i + 1 << ":\n";
        books[i].display();
        std::cout << "--------------------------\n";
    }

    return 0;
}
