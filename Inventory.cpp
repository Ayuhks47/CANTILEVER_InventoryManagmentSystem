#include "Inventory.h"
#include <algorithm> // Include this header for std::remove_if

void Inventory::addProduct(const Product& product) {
    products.push_back(product);
}

bool Inventory::removeProduct(int id) {
    auto it = std::remove_if(products.begin(), products.end(),
                             [id](const Product& p) { return p.getId() == id; });
    if (it != products.end()) {
        products.erase(it, products.end());
        return true;
    }
    return false;
}

bool Inventory::updateProduct(const Product& product) {
    for (auto& p : products) {
        if (p.getId() == product.getId()) {
            p = product;
            return true;
        }
    }
    return false;
}

Product Inventory::findProduct(int id) const {
    for (const auto& p : products) {
        if (p.getId() == id) {
            return p;
        }
    }
    return Product(-1, "", 0.0, 0); // Return an invalid product if not found
}

const std::vector<Product>& Inventory::getProducts() const {
    return products;
}
