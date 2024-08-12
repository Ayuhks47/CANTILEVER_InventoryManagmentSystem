#include "Menu.h"
#include "FileHandler.h"
#include <iostream>
#include <cstdlib> // for exit()

Menu::Menu(const std::string& filename) : filename(filename) {
    load();
}

void Menu::displayMenu() {
    int choice;

    std::cout << "Inventory Management System\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. Remove Product\n";
    std::cout << "3. Update Product\n";
    std::cout << "4. Find Product\n";
    std::cout << "5. Save and Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            removeProduct();
            break;
        case 3:
            updateProduct();
            break;
        case 4:
            findProduct();
            break;
        case 5:
            save();
            exit(0); // Exit the program
        default:
            std::cout << "Invalid choice, try again.\n";
    }
}

void Menu::load() {
    FileHandler::loadInventory(inventory, filename);
}

void Menu::save() {
    FileHandler::saveInventory(inventory, filename);
}

void Menu::addProduct() {
    int id;
    std::string name;
    double price;
    int quantity;

    std::cout << "Enter Product ID: ";
    std::cin >> id;
    std::cout << "Enter Product Name: ";
    std::cin >> name;
    std::cout << "Enter Product Price: ";
    std::cin >> price;
    std::cout << "Enter Product Quantity: ";
    std::cin >> quantity;

    Product product(id, name, price, quantity);
    inventory.addProduct(product);
    std::cout << "Product added successfully.\n";
}

void Menu::removeProduct() {
    int id;
    std::cout << "Enter Product ID to remove: ";
    std::cin >> id;

    if (inventory.removeProduct(id)) {
        std::cout << "Product removed successfully.\n";
    } else {
        std::cout << "Product not found.\n";
    }
}

void Menu::updateProduct() {
    int id;
    std::string name;
    double price;
    int quantity;

    std::cout << "Enter Product ID to update: ";
    std::cin >> id;
    std::cout << "Enter new Product Name: ";
    std::cin >> name;
    std::cout << "Enter new Product Price: ";
    std::cin >> price;
    std::cout << "Enter new Product Quantity: ";
    std::cin >> quantity;

    Product product(id, name, price, quantity);
    if (inventory.updateProduct(product)) {
        std::cout << "Product updated successfully.\n";
    } else {
        std::cout << "Product not found.\n";
    }
}

void Menu::findProduct() {
    int id;
    std::cout << "Enter Product ID to find: ";
    std::cin >> id;

    Product product = inventory.findProduct(id);
    if (product.getId() != -1) { // Assuming -1 is an invalid ID
        std::cout << "Product found:\n";
        std::cout << "ID: " << product.getId() << '\n';
        std::cout << "Name: " << product.getName() << '\n';
        std::cout << "Price: " << product.getPrice() << '\n';
        std::cout << "Quantity: " << product.getQuantity() << '\n';
    } else {
        std::cout << "Product not found.\n";
    }
}
