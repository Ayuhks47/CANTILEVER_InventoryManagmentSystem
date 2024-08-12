#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    int id;
    std::string name;
    double price;
    int quantity;

public:
    Product(int id = 0, const std::string& name = "", double price = 0.0, int quantity = 0);

    int getId() const;
    const std::string& getName() const;
    double getPrice() const;
    int getQuantity() const;
};

#endif // PRODUCT_H
