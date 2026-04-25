#include "Applicant.h"
#include <sstream>
#include <iostream>

Applicant::Applicant(int i, string n, int a, float c, float inc, string f, string u, string p)
: User(u,p) {
    id = i;
    name = n;
    age = a;
    cgpa = c;
    income = inc;
    field = f;
    status = "Pending";
    totalFunds = 0;
    installmentsPaid = 0;
    calculateScore();
}

void Applicant::calculateScore() {
    score = (cgpa * 20) + ((100000 - income) / 1000);
}

void Applicant::updateAcademic(float c, float inc) {
    cgpa = c;
    income = inc;
    calculateScore();
}

void Applicant::disburseFunds(float amount) {
    totalFunds = amount;
    status = "Approved";
}

void Applicant::payInstallment() {
    if (installmentsPaid < 4)
        installmentsPaid++;
    if (installmentsPaid == 4)
        status = "Completed";
}

int Applicant::getId() { return id; }
float Applicant::getCGPA() { return cgpa; }
float Applicant::getIncome() { return income; }
string Applicant::getStatus() { return status; }
float Applicant::getScore() { return score; }

string Applicant::serialize() {
    stringstream ss;
    ss << id << "," << name << "," << age << "," << cgpa << "," << income << "," << field << "," << status << "," << score << "," << totalFunds << "," << installmentsPaid << "," << username << "," << password;
    return ss.str();
}

void Applicant::menu() {
    cout << "Applicant Dashboard\n";
}

bool Applicant::login(string u, string p) {
    return (username == u && password == p);
}

void Applicant::display() {
    cout << "ID: " << id
         << " Name: " << name
         << " CGPA: " << cgpa
         << " Income: " << income
         << " Status: " << status
         << " Score: " << score
         << endl;
}

int Applicant::getInstallments() {
    return installmentsPaid;
}

float Applicant::getFunds() {
    return totalFunds;
}

void Applicant::applicantMenu() {
    int choice;
    do {
        cout << "\n--- Applicant Dashboard ---\n";
        cout << "1. View Profile\n";
        cout << "2. Pay Installment\n";
        cout << "0. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                display();
                break;
            case 2:
                payInstallment();
                cout << "Installment paid\n";
                break;
        }

    } while(choice != 0);
}