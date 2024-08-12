#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"
#include <vector>

class Inventory {
public:
    void addProduct(const Product& product);
    bool removeProduct(int id);
    bool updateProduct(const Product& product);
    Product findProduct(int id) const;
    const std::vector<Product>& getProducts() const;

private:
    std::vector<Product> products;
};

#endif // INVENTORY_H
