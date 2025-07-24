// midterm_inventory.h
#ifndef MIDTERM_INVENTORY_H
#define MIDTERM_INVENTORY_H

#include <string>
#include <vector>
#include <fstream>

class Item {
private:
    int id;
    std::string name;
    int quantity;
    double price;

public:
    Item();
    Item(int, const std::string&, int, double);

    int getId() const;
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;

    void setQuantity(int);
    void display() const;
    void writeToFile(std::ofstream&) const;
    static Item readFromLine(const std::string&);
};

class Inventory {
private:
    std::vector<Item> items;

public:
    void addItem(const Item&);
    void displayItems() const;
    void saveToFile(const std::string&) const;
    void loadFromFile(const std::string&);
    int binarySearch(int id) const;
    void searchItemById(int id) const;
};

#endif // MIDTERM_INVENTORY_H
