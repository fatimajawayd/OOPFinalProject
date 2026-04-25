#include "System.h"
#include <fstream>
#include <iostream>
using namespace std;

void System::addApplicant() {
    int id, age;
    float cgpa, income;
    string name, field, user, pass;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter CGPA (0-4): ";
    cin >> cgpa;

    cout << "Enter Family Income: ";
    cin >> income;

    cout << "Enter Field of Study: ";
    cin >> field;

    cout << "Create Username: ";
    cin >> user;

    cout << "Create Password: ";
    cin >> pass;

    if (cgpa < 0 || cgpa > 4)
        throw "Invalid CGPA";

    Applicant* a = new Applicant(id,name,age,cgpa,income,field,user,pass);
    applicants.push_back(a);

    cout << "Applicant added successfully\n";
}

void System::updateApplicant() {
    int id;
    cout << "Enter Applicant ID to update: ";
    cin >> id;

    for (int i = 0; i < applicants.size(); i++) {
        Applicant* a = applicants[i];

        if (a->getId() == id) {
            float c, income;

            cout << "Enter new CGPA: ";
            cin >> c;

            cout << "Enter new Income: ";
            cin >> income;

            a->updateAcademic(c, income);
            cout << "Updated successfully\n";
            return;
        }
    }
    cout << "Applicant not found\n";
}

void System::deleteApplicant() {
    int id;
    cout << "Enter Applicant ID to delete: ";
    cin >> id;

    for (int i = 0; i < applicants.size(); i++) {
        if (applicants[i]->getId() == id) {
            delete applicants[i];
            applicants.erase(applicants.begin() + i);
            cout << "Deleted successfully\n";
            return;
        }
    }
    cout << "Applicant not found\n";
}

void System::searchByCGPA() {
    float c;
    cout << "Enter minimum CGPA: ";
    cin >> c;

    for (int i = 0; i < applicants.size(); i++) {
        if (applicants[i]->getCGPA() >= c)
            cout << "ID: " << applicants[i]->getId() << endl;
    }
}

void System::searchByIncome() {
    float inc;
    cout << "Enter maximum income: ";
    cin >> inc;

    for (int i = 0; i < applicants.size(); i++) {
        if (applicants[i]->getIncome() <= inc)
            cout << "ID: " << applicants[i]->getId() << endl;
    }
}

void System::searchByStatus() {
    string s;
    cout << "Enter status (Pending/Approved/Completed): ";
    cin >> s;

    for (int i = 0; i < applicants.size(); i++) {
        if (applicants[i]->getStatus() == s)
            cout << "ID: " << applicants[i]->getId() << endl;
    }
}

void System::searchByEligibility() {
    cout << "Eligible Applicants:\n";

    for (int i = 0; i < applicants.size(); i++) {
        if (applicants[i]->getScore() > 80)
            cout << "ID: " << applicants[i]->getId() << endl;
    }
}

void System::disburse() {
    int id;
    float amount;

    cout << "Enter Applicant ID: ";
    cin >> id;

    cout << "Enter total scholarship amount: ";
    cin >> amount;

    for (int i = 0; i < applicants.size(); i++) {
        if (applicants[i]->getId() == id) {
            applicants[i]->disburseFunds(amount);
            cout << "Funds disbursed successfully\n";
            return;
        }
    }
    cout << "Applicant not found\n";
}

void System::menu() {
    int choice;
    do {
        cout << "\n===== FundWise Menu =====\n";
        cout << "1. Add Applicant\n";
        cout << "2. Update Applicant\n";
        cout << "3. Delete Applicant\n";
        cout << "4. Search by CGPA\n";
        cout << "5. Search by Income\n";
        cout << "6. Search by Status\n";
        cout << "7. Search by Eligibility\n";
        cout << "8. Disburse Scholarship\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addApplicant(); break;
            case 2: updateApplicant(); break;
            case 3: deleteApplicant(); break;
            case 4: searchByCGPA(); break;
            case 5: searchByIncome(); break;
            case 6: searchByStatus(); break;
            case 7: searchByEligibility(); break;
            case 8: disburse(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while(choice != 0);
}

void System::load() {
    ifstream file("applicants.txt");
    if (!file) return;

    applicants.clear();

    while (!file.eof()) {
        int id, age, inst;
        float cgpa, income, score, funds;
        string name, field, status, user, pass;
        char comma;

        file >> id >> comma
             >> name >> comma
             >> age >> comma
             >> cgpa >> comma
             >> income >> comma
             >> field >> comma
             >> status >> comma
             >> score >> comma
             >> funds >> comma
             >> inst >> comma
             >> user >> comma
             >> pass;

        if (file.fail()) break;

        Applicant* a = new Applicant(id,name,age,cgpa,income,field,user,pass);
        a->disburseFunds(funds);

        for (int i = 0; i < inst; i++)
            a->payInstallment();

        applicants.push_back(a);
    }

    file.close();
}

void System::save() {
    ofstream file("applicants.txt");
    for (int i = 0; i < applicants.size(); i++)
        file << applicants[i]->serialize() << endl;
    file.close();
}

void System::login() {
    int choice;
    cout << "\n1. Admin Login\n2. Applicant Login\nEnter: ";
    cin >> choice;

    if (choice == 1) {
        string u, p;
        cout << "Enter Admin Username: ";
        cin >> u;
        cout << "Enter Password: ";
        cin >> p;

        if (u == "admin" && p == "123") {
            menu();
        } else {
            cout << "Invalid admin login\n";
        }
    }
    else if (choice == 2) {
        string u, p;
        cout << "Enter Username: ";
        cin >> u;
        cout << "Enter Password: ";
        cin >> p;

        for (int i = 0; i < applicants.size(); i++) {
            if (applicants[i]->login(u,p)) {
                applicants[i]->applicantMenu();
                return;
            }
        }
        cout << "Invalid applicant login\n";
    }
}

System::~System() {
    for (int i = 0; i < applicants.size(); i++)
        delete applicants[i];
}