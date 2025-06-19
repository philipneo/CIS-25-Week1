#include <iostream>
using namespace std;

void showMenu() {
    cout << "1. Add\n2. View\n3. Exit\n";
}

int main() {
    int option;
    do {
        showMenu();
        cin >> option;
        if (option == 1) cout << "Item added!\n";
        else if (option == 2) cout << "Viewing items...\n";
        else if (option != 3) cout << "Invalid option.\n";
    } while (option != 3);

    return 0;
}
