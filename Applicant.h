#ifndef APPLICANT_H
#define APPLICANT_H
#include "User.h"
#include <string>
using namespace std;

class Applicant : public User {
private:
    int id;
    string name;
    int age;
    float cgpa;
    float income;
    string field;
    string status;
    float score;
    float totalFunds;
    int installmentsPaid;

public:
    Applicant(int, string, int, float, float, string, string, string);

    void calculateScore();
    void updateAcademic(float, float);
    void disburseFunds(float);
    void payInstallment();

    int getId();
    float getCGPA();
    float getIncome();
    string getStatus();
    float getScore();

    string serialize();
    void menu() override;
    
    bool login(string, string);
	void applicantMenu();
	void display();
	int getInstallments();
	float getFunds();
};

#endif