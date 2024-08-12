#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

void FileHandler::loadInventory(Inventory& inventory, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for reading: " << filename << std::endl;
        return;
    }

    int id;
    std::string name;
    double price;
    int quantity;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        if (ss >> id >> std::ws && std::getline(ss, name, ',') &&
            ss >> price >> quantity) {
            Product product(id, name, price, quantity);
            inventory.addProduct(product);
        } else {
            std::cerr << "Error reading line: " << line << std::endl;
        }
    }

    file.close();
    std::cout << "Inventory loaded from file." << std::endl;
}

void FileHandler::saveInventory(const Inventory& inventory, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& product : inventory.getProducts()) {
        file << product.getId() << ',' 
             << product.getName() << ',' 
             << product.getPrice() << ',' 
             << product.getQuantity() << '\n';
    }

    file.close();
    std::cout << "Inventory saved to file." << std::endl;
}
