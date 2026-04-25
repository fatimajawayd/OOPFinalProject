#include "System.h"
#include <iostream>
using namespace std;

int main() {
    System s;
    s.load();

    try {
        int choice;
        do {
            cout << "\n===== FundWise System =====\n";
            cout << "1. Login\n";
            cout << "0. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 1)
                s.login();

        } while(choice != 0);

    } catch (const char* msg) {
        cout << msg << endl;
    }

    s.save();
}