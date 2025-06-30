#include <iostream>
#include <string>
using namespace std;

// Define the Item struct
struct Item {
    string name;
    int id;
};

// Binary Search Function
int binarySearch(Item* items, int size, int targetId) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (items[mid].id == targetId) {
            return mid;
        } else if (items[mid].id < targetId) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Not found
}

int main() {
    int size = 5;
    Item* items = new Item[size] {
        {"Apple", 1001},
        {"Banana", 1003},
        {"Carrot", 1005},
        {"Donut", 1007},
        {"Eggplant", 1010}
    };

    int searchId;
    cout << "Enter an Item ID to search: ";
    cin >> searchId;

    i
