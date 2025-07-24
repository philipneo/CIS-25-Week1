// midterm_inventory.cpp
#include "midterm_inventory.h"
#include <iostream>
#include <sstream>
using namespace std;

Item::Item() : id(0), name(""), quantity(0), price(0.0) {}

Item::Item(int i, const string& n, int q, double p)
    : id(i), name(n), quantity(q), price(p) {}

int Item::getId() const { return id; }
string Item::getName() const { return name; }
int Item::getQuantity() const { return quantity; }
double Item::getPrice() const { return price; }

void Item::setQuantity(int q) { quantity = q; }

void Item::display() const {
    cout << "ID: " << id
         << ", Name: " << name
         << ", Quantity: " << quantity
         << ", Price: $" << price << endl;
}

void Item::writeToFile(ofstream& ofs) const {
    ofs << id << "," << name << "," << quantity << "," << price << endl;
}

Item Item::readFromLine(const string& line) {
    stringstream ss(line);
    string part;
    int id, quantity;
    string name;
    double price;

    getline(ss, part, ',');
    id = stoi(part);
    getline(ss, name, ',');
    getline(ss, part, ',');
    quantity = stoi(part);
    getline(ss, part);
    price = stod(part);

    return Item(id, name, quantity, price);
}

void Inventory::addItem(const Item& item) {
    items.push_back(item);
}

void Inventory::displayItems() const {
    for (const auto& item : items) {
        item.display();
    }
}

void Inventory::saveToFile(const string& filename) const {
    ofstream ofs(filename);
    for (const auto& item : items) {
        item.writeToFile(ofs);
    }
    ofs.close();
}

void Inventory::loadFromFile(const string& filename) {
    ifstream ifs(filename);
    string line;
    items.clear();
    while (getline(ifs, line)) {
        items.push_back(Item::readFromLine(line));
    }
    ifs.close();
}

int Inventory::binarySearch(int id) const {
    int left = 0, right = items.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (items[mid].getId() == id) return mid;
        else if (items[mid].getId() < id) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void Inventory::searchItemById(int id) const {
    int index = binarySearch(id);
    if (index != -1) {
        cout << "Item Found:\n";
        items[index].display();
    } else {
        cout << "Item with ID " << id << " not found.\n";
    }
}
