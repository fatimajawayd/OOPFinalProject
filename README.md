# OOP Final Project

## Project Title: FundWise-Scholarship Program

## Project Description
FundWise is a console based scholarship management system built in C++. It is designed to help a financial aid office manage student scholarship applications from start to finish. An admin can register students, update their records, search through applicants, and release scholarship funds. Students can log in separately to check their profile and pay back their scholarship in installments. All data is saved automatically so nothing is lost when the program is closed.

---

## Group Members

- Fatima Javed | 25k-0594
- Osailah Atif | 25k-0789
- Maham Mustafa | 25k-0764
---

## Use Cases

### UC1: Register a New Applicant
**Actor:** Admin
The admin selects Add Applicant and enters the student's details including ID, name, CGPA, family income, and field of study. The system validates the CGPA, calculates an eligibility score, and saves the record with status set to **Pending**.

### UC2: Update an Applicant's Details
**Actor:** Admin
The admin selects Update Applicant, enters the student's ID, and provides the new CGPA and income values. The system updates the record and recalculates the eligibility score automatically.

### UC3: Delete an Applicant
**Actor:** Admin
The admin selects Delete Applicant and enters the student's ID. The system permanently removes the record. If the ID is not found, it displays "Applicant not found."

### UC4: Search for Applicants
**Actor:** Admin
The admin searches for students using one of four filters: minimum CGPA, maximum family income, status (**Pending**, **Approved**, or **Completed**), or eligibility score above 80. The system prints all matching results on the screen.

### UC5: Disburse a Scholarship
**Actor:** Admin
The admin selects Disburse Scholarship, enters the student's ID and the amount. The system updates the applicant's status from **Pending** to **Approved** and records the funds against their name.

### UC6: Applicant Logs In and Pays an Installment
**Actor:** Applicant
The applicant logs in using their credentials and reaches their personal dashboard. They can view their profile and pay an installment. After 4 successful payments the system automatically changes their status to **Completed**.

---

## How to Compile the Project

1. Open **Visual Studio**
2. Create a new **Empty C++ Project**
3. Add all the provided source files to the project: `Main.cpp`, `System.cpp`, `System.h`, `Applicant.cpp`, `Applicant.h`, `Admin.cpp`, `Admin.h` and `User.cpp`
4. Make sure all files are placed under the same project folder
5. Press `Ctrl + Shift + B` to build the solution

---

## How to Run the Project

1. After a successful build, press `Ctrl + F5` to run the program without debugging
2. The program will open in a console window
3. On the very first run there will be no existing data. Once you add applicants and exit, the system will automatically create a file called `applicants.txt` in your project folder and save everything there
4. Every time you run the program after that, it will load the saved data from that file automatically
---

## How to Use the System

When the program starts you will see two login options.

**Logging in as Admin**
- Select option 1 for Admin Login
- Username: `admin`
- Password: `123`
- Once logged in you will see a menu with the following options:
  - Add Applicant
  - Update Applicant
  - Delete Applicant
  - Search Applicants
  - Disburse Scholarship
  - Display All Applicants
  - Exit

**Logging in as Applicant**
- Select option 2 for Applicant Login
- Enter the username and password that the admin created for you during registration
- Once logged in you can:
  - View your full profile including CGPA, income, eligibility score and status
  - Pay an installment toward your scholarship repayment

---

## Assumptions and Limitations

- CGPA must be between 0.0 and 4.0 and the system will reject any value outside this range
- Each applicant is allowed exactly 4 installment payments and after the 4th payment the status is automatically set to **Completed**
- Admin login credentials are fixed at username `admin` and password `123` and cannot be changed from within the program
- The system runs entirely in the console and there is no graphical interface
- All data is stored in a plain text file called `applicants.txt` which is created automatically on the first save
- Passwords are stored as plain text and there is no encryption applied
