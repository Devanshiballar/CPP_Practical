#include <iostream>
#include <fstream>
#include <string>

class FileManager {
public:

    void readFile(const std::string& filename) {
        std::ifstream file;

        file.open(filename);
        if (!file) {
            throw std::ios_base::failure("Error: Unable to open file " + filename);
        }

        std::cout << "File Contents:\n";
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << "\n";
        }

        file.close();
    }
};

int main() {
    FileManager fileManager;
    std::string filename;

    std::cout << "Enter the name of the file to read: ";
    std::cin >> filename;

    try {
        fileManager.readFile(filename);
    } catch (const std::ios_base::failure& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
