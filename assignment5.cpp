#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    int id;
};

int binarySearch(Item* items, int size, int targetId) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (items[mid].id == targetId)
            return mid;
        else if (items[mid].id < targetId)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int size = 3;
    Item* items = new Item[size] {
        {"Screwdriver", 101},
        {"Hammer", 102},
        {"Wrench", 103}
    };

    int searchId;
    cout << "Enter ID to search: ";
    cin >> searchId;

    int result = binarySearch(items, size, searchId);
    if (result != -1) {
        cout << "Found: " << items[result].name << ", ID: " << items[result].id << endl;
    } else {
        cout << "Item not found." << endl;
    }

    delete[] items;
    return 0;
}
