# OOP Final Project
## FundWise-Scholarship Program

## Project Description
FundWise is a console based scholarship management system built in C++. It is designed to help a financial aid office manage student scholarship applications from start to finish. An admin can register students, update their records, search through applicants, and release scholarship funds. Students can log in separately to check their profile and pay back their scholarship in installments. All data is saved automatically so nothing is lost when the program is closed.

---

## Group Members

| Name | Student ID |
|---|---|
| Fatima Javed | 25k-0594 |
| Osailah Atif | 25k-0789 |
| Maham Mustafa | 25k-0764 |

---

## Use Cases

### UC1: Register a New Applicant

The actor in this use case is the **Admin**. For this to happen, the admin must already be logged in using the username `admin` and password `123`. The admin selects Add Applicant from the menu and enters the student's ID, name, age, CGPA, family income, field of study, and creates a username and password for them. The system then validates the CGPA to make sure it falls between 0.0 and 4.0, automatically calculates an eligibility score, and saves the record. Once this is done, the new applicant is successfully added to the system with their status set to **Pending**.

### UC2: Update an Applicant's Details

The actor in this use case is the **Admin**. The admin must be logged in and the applicant must already exist in the system. The admin selects Update Applicant, enters the student's ID, and types in the new CGPA and family income values. The system locates the record, updates the values, and automatically recalculates the eligibility score based on the new information. The applicant's record is then saved with the updated details.

### UC3: Delete an Applicant

The actor in this use case is the **Admin**. The admin must be logged in and the applicant must exist in the system. The admin selects Delete Applicant and enters the student's ID. The system finds the record and removes it permanently from the list. If the ID does not exist, the system displays "Applicant not found." Once completed, the applicant's record is fully removed from the system.

### UC4: Search for Applicants

The actor in this use case is the **Admin**. The admin must be logged in and at least one applicant must exist in the system. The admin selects Search Applicants and chooses one of four filters which are minimum CGPA, maximum family income, current status (**Pending**, **Approved**, or **Completed**), or eligibility score above 80. The system checks all records against the chosen filter and prints the matching applicant IDs on the screen. If no records match, no results are shown.

### UC5: Disburse a Scholarship

The actor in this use case is the **Admin**. The admin must be logged in and the applicant's current status must be **Pending**. The admin selects Disburse Scholarship, enters the student's ID, and types in the scholarship amount. The system updates the applicant's status from **Pending** to **Approved** and records the total funds against their name. If the ID does not exist, an error message is displayed. Once done, the scholarship amount is stored and the applicant's status is officially changed to **Approved**.

### UC6: Applicant Logs In and Pays an Installment

The actor in this use case is the **Applicant**. The applicant must have already been registered by the admin and must have a valid username and password. The applicant selects Applicant Login, enters their credentials, and reaches their personal dashboard where they can view their full profile including CGPA, family income, eligibility score, and current status. They can also select Pay Installment to make a payment. The system records the payment and increases the installment count by one. If the wrong credentials are entered, access is denied. After 4 successful payments the system automatically changes the applicant's status to **Completed**.

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

Select option 1 for Admin Login. Use username `admin` and password `123`. Once logged in you will see a menu where you can add, update, delete, search applicants and disburse scholarships.

**Logging in as Applicant**

Select option 2 for Applicant Login. Enter the username and password that the admin created for you during registration. Once logged in you can view your profile and pay your monthly installment.

---

## Assumptions and Limitations

CGPA must be between 0.0 and 4.0 and the system will reject any value outside this range. Each applicant is allowed exactly 4 installment payments and after the 4th payment the status is automatically set to **Completed**. Admin login credentials are fixed at username `admin` and password `123` and cannot be changed from within the program. The system runs entirely in the console and there is no graphical interface. All data is stored in a plain text file called `applicants.txt` which is created automatically on the first save. Passwords are stored as plain text and there is no encryption applied.
