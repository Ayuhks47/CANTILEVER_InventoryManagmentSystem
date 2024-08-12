#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Inventory.h"
#include <string>

class FileHandler {
public:
    static void loadInventory(Inventory& inventory, const std::string& filename);
    static void saveInventory(const Inventory& inventory, const std::string& filename);
};

#endif // FILEHANDLER_H
