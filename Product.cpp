#include "Product.h"

Product::Product(int id, const std::string& name, double price, int quantity)
    : id(id), name(name), price(price), quantity(quantity) {}

int Product::getId() const {
    return id;
}

const std::string& Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

