#include "Menu.h"

int main() {
    std::string filename = "inventory.txt";
    Menu menu(filename);

    while (true) {
        menu.displayMenu();
    }

    return 0;
}

