#ifndef SYSTEM_H
#define SYSTEM_H
#include "Applicant.h"
#include <vector>
using namespace std;

class System {
private:
    vector<Applicant*> applicants;

public:
    void load();
    void save();

    void addApplicant();
    void updateApplicant();
    void deleteApplicant();

    void searchByCGPA();
    void searchByIncome();
    void searchByStatus();
    void searchByEligibility();

    void disburse();
    void menu();
	void login();
	
    ~System();
};

#endif