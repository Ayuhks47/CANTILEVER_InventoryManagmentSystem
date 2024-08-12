#ifndef MENU_H
#define MENU_H

#include "Inventory.h"
#include <string>

class Menu {
public:
    Menu(const std::string& filename);
    void displayMenu();

private:
    Inventory inventory;
    std::string filename;

    void load();
    void save();
    void addProduct();
    void removeProduct();
    void updateProduct();
    void findProduct();
};

#endif // MENU_H
