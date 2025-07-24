#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "midterm_inventory.h"
using namespace std;

void displayMenu() {
    cout << "\n--- Inventory Menu ---" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. View Items" << endl;
    cout << "3. Search Item by ID" << endl;
    cout << "4. Save to File" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

int binarySearch(const vector<Item>& items, int id) {
    int left = 0, right = items.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (items[mid].getId() == id)
            return mid;
        else if (items[mid].getId() < id)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    vector<Item> items;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            int id, qty;
            string name;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter name: "; cin.ignore(); getline(cin, name);
            cout << "Enter quantity: "; cin >> qty;
            items.push_back(Item(id, name, qty));
            sort(items.begin(), items.end(), [](Item a, Item b) { return a.getId() < b.getId(); });
        }
        else if (choice == 2) {
            for (const auto& item : items)
                item.display();
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: "; cin >> id;
            int index = binarySearch(items, id);
            if (index != -1)
                items[index].display();
            else
                cout << "Item not found.\n";
        }
        else if (choice == 4) {
            ofstream out("items.txt");
            for (const auto& item : items)
                out << item.getId() << "," << item.getName() << "," << item.getQuantity() << endl;
            out.close();
            cout << "Saved to items.txt\n";
        }
        else if (choice == 5) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
