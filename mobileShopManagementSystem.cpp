#include <iostream>
#include <windows.h>
#include<stdio.h>
#include <iomanip>
#include <conio.h> //used to use _getch() in masked pass
#include <fstream>
using namespace std;
// max order of each customer
const int MaxOrder = 15;

// employee data
struct Employee
{
    string username = "nv";
    string pwd = "nv";
    bool isExist = false;
    string name = "nv";
    string fatherName = "nv";
    string cellNo = "nv";
    string address = "nv";
    string cnic = "nv";
    string dob = "nv";
    string gender = "nv";
};

// customer data
struct Customer
{
    string username = "nv";
    string pwd = "nv";
    bool isExist = false;
    string name = "nv";
    string cellNo = "nv";
    string address = "nv";
    string dob = "nv";
    string gender = "nv";
};

// mobile inventry
struct Mobile
{
    int itemId = 0;
    string brand = "nv";
    string model = "nv";
    string specs = "nv";
    string supplierName = "nv";
    string color = "nv";
    int qty = 0;
    string storage = "nv";
    int purchasePrice = 0;
    int salePrice = 0;
    int minStockLevel = 0;
    bool isExist = false;
};

struct Order
{
    int itemId = 0;
    int price = 0;
    int qty = 0;
    string status = "Pending";
    bool isExist = false;
};

struct CustomerOrder
{
    Order orders[MaxOrder];
    int orderCount = 0;
};

struct DeliveredOrder
{
    string cusUsername = "nv"; // Customer's username
    int itemId = 0;           
    int qty = 0;     
};

//<-----------------------------------Interfaces--------------------------------------->
// main interface of App
void mainInterface(); // enables to select type of user

// 1. Manager Portal
// Shows interfaces
void managerLoginHeader();        // manager login page
void managerMainMenu();           // manager portal options
void inventryManagementHeader();  // shows inventry management header
void managerInventryManagement(); // shows features of manager inventry
void employeeManagementHeader();  // show only header
void managerEmployeeManagement(); // manager user management windows like add,edit,delete
void customerManagementHeader();  // shows customer managment header
void managerCustomerManagement(); // customer managment options
void managerOrderManagement();    // order of customer management

// 2. Employee Portal
// Shows interfaces
void employeeLoginHeader();        // employee login page
void employeeMainMenu();           // employee portal options
void employeeInventryManagement(); // shows features of employee inventry
void employeeCustomerManagement(); // customer managment options under employee
void employeeOrderManagement();    // order of customer management under employee

// 3. customer portal
// Shows interfaces
void customerLoginHeader();
void customerPortalHeader();
void customerPortal();           // customer portal with options
void customerProfileMenu();      // customer within profile options
void customerWithoutLoginMenu(); ////customer without having a profile

//<-------------------------------login checker--------------------------------->
bool ManagerLoginChecker(string realUsername, string realPass);
bool EmployeeloginChecker(Employee emp[], int EmpSize);

//<---------------employee and customer validations----------------------->
bool isCusUsernameUnique(const string &username, Customer cus[], int CusSize); //ensure username is unique in system
bool isEmpUsernameUnique(const string &username, Employee emp[], int EmpSize); 
void invalidErrorMessage();   // invalid option error
int getValidDigitInput();     // make sure input is 0 - 9 single digit
string maskedInputPass();     // input masked password from user
void setTextColor(int color); // changes the color of specific text
void loadingBar();
string validDate();           // date validator
string validPhoneNo();
string validName(int minLen, int maxLen, string errorMsg);
string validAddress();
string validUsername();
string validPwd(); // check user enter valid pwd at time of creating account
string validGender();

//<---------------------mobile validations-------------------->
string validModelName();
string validStorage();
string validSpecs();
int validIntInput(const string &fieldName, int minValue, int maxValue);

//<-------------smart functions---------------------->
int stringToInt(string str); // change string to int
string intToString(int number);
string tokenizer(string str, int field);                 // seperate by comma help in file handling
int convertToInt(const string &str, int start, int end); // for date manuplation used
int LengthOf(const string &str);
string toLowerCase(string str);

//<------------------employee management-------------------------->
void addEmployee(Employee emp[], int EmpSize, int &empCount);

void updateEmployee(Employee emp[], int EmpSize, int &empCount); // Uemp :

void viewEmployee(Employee emp[], int EmpSize, int &empCount);

void deleteEmployee(Employee emp[], int EmpSize, int &empCount);

//<------------------------profit report----------------------------------->
void profitReport(int &total_Cost, int &total_Revenue, int &total_Profit, int &mobSold);

//<----------------------inventry management------------------->
void addMobiles(Mobile mob[], int MaxMobile, int &mobileCount);

void updateMobiles(Mobile mob[], int MaxMobile, int &mobileCount);

void deleteMobiles(Mobile mob[], int MaxMobile, int &mobileCount);

// here bool isAdmin determine wether to show full detailed list or ristricted (1 for admin, 0 for others)
void viewMobiles(Mobile mob[], int MaxMobile, int &mobileCount, bool isAdmin);

void lowStock(Mobile mob[], int MaxMobile, int &mobileCount);

//<-----------------------customer order management---------------------------------------->
void ShowPendingOrders(Mobile mob[], int MaxMobile, int &mobileCount, string username, string pwd, Customer cus[], int CusSize, CustomerOrder cust[]);

void managePendingOrders(Mobile mob[], int MaxMobile, int &mobileCount, string username, string pwd, Customer cus[], int CusSize, CustomerOrder cust[],DeliveredOrder order[], int &total_Cost, int &total_Revenue, int &total_Profit, int &mobSold);

//<------------------Customer profiles-------------------------->
void addCustomer(Customer cus[], int CusSize, int &customerCount);

void updateCustomer(Customer cus[], int CusSize, int &customerCount);

void deleteCustomer(Customer cus[], int CusSize, int &customerCount);

void viewAllCustomer(Customer cus[], int CusSize, int &customerCount);

//<-------------------------place an order--------------------------->
// find user index to specfic logined customer
int findCustomerIndex(string username, string pwd, Customer cus[], int CusSize);

void placeOrder(Mobile mob[], int MaxMobile, int &mobileCount, string username, string pwd, Customer cus[], int CusSize, CustomerOrder cust[]);

void orderTracking(Mobile mob[], int MaxMobile, int &mobileCount, string username, string pwd, Customer cus[], int CusSize, CustomerOrder cust[]);

//<------------------------file handling--------------------------------->
//<----------------------Employee data save & laod-------------------------------->
void saveEmployeeData(Employee emp[], int EmpSize, int &empCount);

void loadEmployeeData(Employee emp[], int EmpSize, int &empCount);

//<-------------------------------customer data save & load--------------------------------->
void SaveCustomerData(Customer cus[], int CusSize, int &customerCount);

void loadCustomerData(Customer cus[], int CusSize, int &customerCount);

//<-------------------------------inventry data save & load--------------------------------->
void saveInventryData(Mobile mob[], int MaxMobile, int &mobileCount);

void loadInventryData(Mobile mob[], int MaxMobile, int &mobileCount);
//<----------------------------profit save data---------------------------------->
void saveProfitReport(int &total_Cost, int &total_Revenue, int &total_Profit, int &mobSold);

void loadProfitReport(int &total_Cost, int &total_Revenue, int &total_Profit, int &mobSold);
//<-------------------------------order data save & load--------------------------------->
void saveOrders(Customer cus[], int CusSize, CustomerOrder cust[]);

void loadOrders(Customer cus[], int CusSize, CustomerOrder cust[]);

int main()
{
    // provides Unicode Support for Console
    system("chcp 65001");
    //<--------------for authentication--------------->
    int choice;
    string username, pwd;
    int loggedInUserType = -1; // 1 for manager, 2 for employee, 3 customer , 4 customer without profile

    //<------------manager attributes--------------->
    string managerPWD, managerUsername;
    managerUsername = "z"; // admin username
    managerPWD = "z";      // admin password
    int managerChoice = -1;

    //<------------employee attributes------------------->
    const int EmpSize = 10; // max no. of employes size
    Employee emp[EmpSize];
    int empCount = 0;         // counts no of employee added
    bool isUserFound = false; // used in searching
    int employeeChoice = -1;

    //<-------------------customer attributes---------------------->
    const int CusSize = 100; // max no. of customers size
    Customer cus[CusSize];
    CustomerOrder cust[CusSize];
    int customerCount = 0; // counts no of customer added
    int customerChoice = -1;
    //order history
    DeliveredOrder order[150];
    //<------------------inventry attributes------------------>
    const int MaxMobile = 30; // max no. of items
    Mobile mob[MaxMobile];
    int mobileCount = 0;
    int inventryChoice = -1;

    //<-----------------Profit report--------------------->
    int total_Cost = 0;
    int total_Revenue = 0;
    int total_Profit = 0;
    int mobSold = 0;

    //<------------------Load data------------------------>
    loadEmployeeData(emp, EmpSize, empCount);

    loadCustomerData(cus, CusSize, customerCount);

    loadInventryData(mob, MaxMobile, mobileCount);

    loadOrders(cus, CusSize, cust);

    loadProfitReport(total_Cost, total_Revenue, total_Profit, mobSold);

    do
    {
        mainInterface();
        choice = getValidDigitInput(); // assures valid input digit 0-9

        // Main menu options handling
        switch (choice)
        {
        case 1:
        { // after getting correct premeter it checks whether credentials are correct or not
            if (ManagerLoginChecker(managerUsername, managerPWD)){
                loggedInUserType = 1;
                loadingBar();
            }
            else
            {
                managerLoginHeader();
                loggedInUserType = -1;
                setTextColor(12);
                cout << "\nInvalid Manager Credentials!\n";
                setTextColor(8);
                system("pause");
            }
            break;
        }
        case 2:
        {
            employeeLoginHeader();
            // it checks credentials if correct return true and move next
            if (EmployeeloginChecker(emp, EmpSize)){
                loggedInUserType = 2;
                loadingBar();
            }
            else
            {
                managerLoginHeader();
                loggedInUserType = -1;
                setTextColor(12);
                cout << "\nInvalid Employee Credentials!\n";
                setTextColor(8);
                system("pause");
            }
            break;
        }
        case 3:
        {
            int cusPortalChoice;
            do
            {
                customerPortal();
                cusPortalChoice = getValidDigitInput();
                switch (cusPortalChoice)
                {
                case 1:
                { // create profile
                    addCustomer(cus, CusSize, customerCount);
                    break;
                }
                case 2:
                {
                    customerLoginHeader();
                    setTextColor(14);
                    cout << " Enter Username: ";
                    setTextColor(11);
                    cin >> username;
                    setTextColor(14);
                    cout << " Enter Password: ";
                    setTextColor(11);
                    isUserFound = false;
                    pwd = maskedInputPass(); // calls the function to take input and save in pwd
                    for (int i = 0; i < CusSize; i++)
                    {
                        if (username == cus[i].username && pwd == cus[i].pwd)
                        {
                            loggedInUserType = 3;
                            loadingBar();
                            isUserFound = true;
                            cusPortalChoice = 0; // to break the loop so control goes to portal after successfully login
                            break;
                        }
                    }
                    if (!isUserFound)
                    { // if no user found
                        loggedInUserType = -1;
                        setTextColor(12);
                        cout << "Invalid Customer Credentials!\n";
                        setTextColor(8);
                        system("pause");
                    }
                    break;
                }
                case 3:
                {
                    loggedInUserType = 4; // customer without profile
                    break;
                }
                case 0:
                {
                    break;
                }
                default:
                {
                    invalidErrorMessage(); // shows invalid error message
                }
                }
                if (cusPortalChoice == 3)
                    break;
            } while (cusPortalChoice != 0);

            break;
        }
        case 0:
        {
            cout << "\n\t\t\t\t\t\t\tThank you for using the Mobile Shop Management System. Goodbye!" << endl;
            return 0;
        }
        default:
        {
            invalidErrorMessage(); // shows invalid error message
        }
        }

        // Show respective menu based on user type
        if (loggedInUserType == 1)
        { // Manager portal
            do
            {
                managerMainMenu();
                managerChoice = getValidDigitInput(); // assures valid input digit 0-9
                switch (managerChoice)
                {
                case 1:
                { // inventry management
                    do
                    {
                        managerInventryManagement();          // shows inventry management menu
                        managerChoice = getValidDigitInput(); // gets valid input
                        switch (managerChoice)
                        {
                        case 1:
                        { // add inventry
                            addMobiles(mob, MaxMobile, mobileCount);
                            break;
                        }
                        case 2:
                        { // update inventry
                            updateMobiles(mob, MaxMobile, mobileCount);
                            break;
                        }
                        case 3:
                        {
                            deleteMobiles(mob, MaxMobile, mobileCount);
                            break;
                        }
                        case 4:
                        {
                            viewMobiles(mob, MaxMobile, mobileCount, 1);
                            break;
                        }
                        case 0:
                        {
                            break;
                        }
                        default:
                        {
                            invalidErrorMessage(); // shows invalid error message
                        }
                        }

                    } while (managerChoice != 0);
                    managerChoice = -1;
                    break;
                }
                case 2:
                { // user (emp) management
                    do
                    {
                        managerEmployeeManagement();          // shows employee management menu
                        managerChoice = getValidDigitInput(); // assures valid input digit 0-9
                        switch (managerChoice)
                        {
                        case 1:
                        { // add employee
                            addEmployee(emp, EmpSize, empCount);

                            break;
                        }
                        case 2:
                        { // update employee
                            updateEmployee(emp, EmpSize, empCount);
                            break;
                        }
                        case 3:
                        { // delete employee
                            deleteEmployee(emp, EmpSize, empCount);
                            break;
                        }
                        case 4:
                        { // view all employees
                            viewEmployee(emp, EmpSize, empCount);
                            break;
                        }
                        case 0:
                        {
                            break;
                        }
                        default:
                        {
                            invalidErrorMessage(); // shows invalid error message
                        }
                        }

                    } while (managerChoice != 0);
                    managerChoice = -1;
                    break;
                }
                case 3:
                { // customer management
                    do
                    {
                        managerCustomerManagement();          // shows customer management menu
                        managerChoice = getValidDigitInput(); // assures valid input digit 0-9
                        switch (managerChoice)
                        { // view all customers
                        case 1:
                        { // view all customers
                            viewAllCustomer(cus, CusSize, customerCount);
                            break;
                        }
                        case 2:
                        { // add customer
                            addCustomer(cus, CusSize, customerCount);
                            break;
                        }
                        case 3:
                        { // update customer data
                            updateCustomer(cus, CusSize, customerCount);
                            break;
                        }
                        case 4:
                        { // delete customer
                            deleteCustomer(cus, CusSize, customerCount);
                            break;
                        }
                        case 0:
                        {
                            break;
                        }
                        default:
                        {
                            invalidErrorMessage(); // shows invalid error message
                        }
                        }

                    } while (managerChoice != 0);
                    managerChoice = -1;
                    break;
                }
                case 4:
                { // order management
                    managePendingOrders(mob, MaxMobile, mobileCount, username, pwd, cus, CusSize, cust,order, total_Cost, total_Revenue, total_Profit, mobSold);
                    break;
                }
                case 5:
                { // low stock alert
                    lowStock(mob, MaxMobile, mobileCount);
                    break;
                }
                case 6:
                { // profit report
                    profitReport(total_Cost, total_Revenue, total_Profit, mobSold);
                    break;
                }
                case 0:
                {
                    loggedInUserType = -1;
                    break;
                }

                default:
                {
                    invalidErrorMessage(); // shows invalid error message
                }
                }
            } while (managerChoice != 0);
            managerChoice = -1;
        }
        else if (loggedInUserType == 2)
        { // Employee portal
            do
            {
                employeeMainMenu();
                employeeChoice = getValidDigitInput(); // assures valid input digit 0-9
                switch (employeeChoice)
                {
                case 1:
                { // Inventry management
                    do
                    {
                        employeeInventryManagement();          // Inventry management menu of employee
                        employeeChoice = getValidDigitInput(); // assures valid input digit 0-9
                        switch (employeeChoice)
                        {
                        case 1:
                        { // add items
                            addMobiles(mob, MaxMobile, mobileCount);
                            break;
                        }
                        case 2:
                        { // update items
                            updateMobiles(mob, MaxMobile, mobileCount);
                            break;
                        }
                        case 3:
                        { // view all items
                            viewMobiles(mob, MaxMobile, mobileCount, 0);
                            break;
                        }
                        case 0:
                        {
                            break;
                        }
                        default:
                        {
                            invalidErrorMessage(); // shows invalid error message
                        }
                        }

                    } while (employeeChoice != 0);
                    employeeChoice = -1; // resets the value so to remain in employee portal
                    break;
                }
                case 2:
                { // customer managment
                    do
                    {
                        employeeCustomerManagement();          // shows customer managment menu of Emp
                        employeeChoice = getValidDigitInput(); // assures valid input digit 0-9
                        switch (employeeChoice)
                        {
                        case 1:
                        { // view all customers
                            viewAllCustomer(cus, CusSize, customerCount);
                            break;
                        }
                        case 2:
                        {
                            updateCustomer(cus, CusSize, customerCount);
                            break;
                        }
                        case 0:
                        {
                            break;
                        }
                        default:
                        {
                            invalidErrorMessage(); // shows invalid error message
                        }
                        }

                    } while (employeeChoice != 0);
                    employeeChoice = -1; // resets the value so to remain in employee portal
                    break;
                }
                case 3:
                {
                    managePendingOrders(mob, MaxMobile, mobileCount, username, pwd, cus, CusSize, cust,order,total_Cost, total_Revenue, total_Profit, mobSold);
                    break;
                }
                case 4:
                { // low stock alert
                    lowStock(mob, MaxMobile, mobileCount);
                    break;
                }
                case 0:
                {
                    loggedInUserType = -1;
                    break;
                }

                default:
                {
                    invalidErrorMessage(); // shows invalid error message
                }
                }
            } while (employeeChoice != 0);
            employeeChoice = -1; // resets to make sure emp exit
        }
        else if (loggedInUserType == 3)
        { // Customer portal logined
            int customerChoice = -1;
            do
            {
                customerProfileMenu();
                customerChoice = getValidDigitInput(); // assures valid input digit 0-9
                switch (customerChoice)
                {
                case 1:
                { // view items
                    viewMobiles(mob, MaxMobile, mobileCount, 0);
                    break;
                }
                case 2:
                { // place an order
                    placeOrder(mob, MaxMobile, mobileCount, username, pwd, cus, CusSize, cust);
                    break;
                }
                case 3:
                { // update profile
                    orderTracking(mob, MaxMobile, mobileCount, username, pwd, cus, CusSize, cust);
                    break;
                }
                case 4:
                { // update profile
                    updateCustomer(cus, CusSize, customerCount);
                    break;
                }
                case 0:
                {
                    break;
                }
                default:
                {
                    invalidErrorMessage(); // shows invalid error message
                }
                }
            } while (customerChoice != 0);
            customerChoice = -1;
        }
        else if (loggedInUserType == 4)
        { // Customer without profile
            int customerChoice;
            do
            {
                customerWithoutLoginMenu();
                customerChoice = getValidDigitInput(); // assures valid input digit 0-9
                switch (customerChoice)
                {
                case 1:
                { // view items
                    viewMobiles(mob, MaxMobile, mobileCount, 0);
                    break;
                }
                case 2:
                {
                    setTextColor(12); // red color
                    cout << "\nPlease create a profile to access this feature." << endl
                         << endl;
                    setTextColor(8); // grey color
                    system("pause");
                    break;
                }
                case 3:
                {
                    setTextColor(12); // red color
                    cout << "\nPlease create a profile to access this feature." << endl
                         << endl;
                    setTextColor(8); // grey color
                    system("pause");
                    break;
                }
                case 0:
                {
                    break;
                }
                default:
                {
                    invalidErrorMessage();
                }
                }
            } while (customerChoice != 0);
            customerChoice = -1;
        }

    } while (choice != 0);

    return 0;
}
//<---------------------------------------Manager Login checker------------------------------------>
bool ManagerLoginChecker(string realUsername, string realPass)
{
    string username, pass;
    managerLoginHeader();
    for (int j = 2; j >= 0; j--)
    {
        // Prompt for username and password
        setTextColor(14); // yellow
        cout << " Enter Username: ";
        setTextColor(11); // aqua
        cin >> username;
        cin.ignore(100, '\n');
        setTextColor(14);
        cout << " Enter Password: ";
        setTextColor(11);
        pass = maskedInputPass();

        // Check if both username and password match
        if (username == realUsername && pass == realPass)
        {
            return true; // Successful login
        }
        else
        {
            setTextColor(12); // red
            cout << " " << j << " tries left" << endl;
        }

        // If no attempts are left, trigger cooldown
        Sleep(500);
        if (j == 0)
        {
            for (int i = 9; i >= 1; i--)
            {
                managerLoginHeader();
                setTextColor(12); // red
                cout << "\n Try again after seconds: 0" << i << endl;
                Sleep(1000);
                system("cls");
            }
            return false;
        }
    }
    return false; // Return false if all attempts are used up
}
//<-------------------------employee login checker----------------------------------------------->
bool EmployeeloginChecker(Employee emp[], int EmpSize)
{
    string username, pwd;
    employeeLoginHeader();
    for (int j = 2; j >= 0; j--)
    {
        setTextColor(14);
        cout << " Enter Username: ";
        setTextColor(11);
        cin >> username;
        setTextColor(14);
        cout << " Enter Password: ";
        setTextColor(11);
        pwd = maskedInputPass();
        // Check if both username and password match
        for (int i = 0; i < EmpSize; i++)
        {
            if (username == emp[i].username && pwd == emp[i].pwd)
            {
                return true;
                break; // LOOP break and tells that employee is authorized
            }
        }
        // if this not happened then these statement will execute
        setTextColor(12);
        cout << " " << j << " tries left" << endl;
        // If no attempts are left, trigger cooldown
        if (j == 0)
        {
            for (int i = 9; i >= 1; i--)
            {
                employeeLoginHeader();
                setTextColor(12); // red
                cout << "\n Try again after seconds: 0" << i << endl;
                Sleep(1000);
                system("cls");
            }
            return false;
        }
    }
    return false;
}
//check unique username
bool isEmpUsernameUnique(const string &username, Employee emp[], int EmpSize)
{
    for (int i = 0; i < EmpSize; i++)
    {
        if (emp[i].username == username)
        {
            return false; // Username exists in employee dataset
        }
    }
    return true; // Username is unique
}
bool isCusUsernameUnique(const string &username, Customer cus[], int CusSize)
{
    for (int i = 0; i < CusSize; i++)
    {
        if (cus[i].username == username)
        {
            return false; // Username exists
        }
    }
    return true; // Username is unique
}
//<-------------------------------Functionalities functions & validations---------------------------------->
// this chacks whether input from 0 to 9
int getValidDigitInput()
{
    int input = -1;
    bool isValid = false;
    do
    {
        setTextColor(14);
        cout << "\t\t\t\t\t\t\t\tSelect desired option: ";
        setTextColor(15);
        cin >> input;

        // Check if the input is within the valid range (0-9)
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            setTextColor(12);
            cout << "\t\t\t\t\t\t\t\tInvalid Choice!\n";
        }
        else
        {
            // Check if extra input in buffer
            char extra;
            if (cin.get(extra))
            {
                // If found shows error msj
                if (extra != '\n')
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    setTextColor(12);
                    cout << "\t\t\t\t\t\t\t\tInvalid Choice!\n";
                    continue;
                }
            }
            isValid = true; // Valid input
        }
    } while (!isValid);

    return input;
}

// convert to int to manuplate dob
int convertToInt(const string &str, int start, int end)
{
    int result = 0;
    for (int i = start; i <= end; i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
            return -1;
        }
        result = result * 10 + (str[i] - '0');
    }
    return result;
}

string validDate()
{
    string date;
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (true)
    {
        cin >> date;
        if (LengthOf(date) != 10 || date[2] != '-' || date[5] != '-')
        {
            cout << "Invalid date! Enter according to  dd-mm-yyyy : ";
            continue; // skips this and ask again
        }
        int day = convertToInt(date, 0, 1);   // check day valid dd 0 to 1 included
        int month = convertToInt(date, 3, 4); // check nomth valid mm
        int year = convertToInt(date, 6, 9);  // check year valid yyyy
        // check day not -ve
        if (day == -1 || month == -1 || year == -1)
        {
            cout << "Invalid Date! Please enter again :";
            continue;
        }
        // check correct year
        if (year > 2024 || year < 1950)
        {
            cout << "INvalid year! Enter again : ";
            continue; // asks again and check
        }
        if (month < 1 || month > 12)
        {
            cout << "Invalid month! Please enter again : ";
            continue;
        }
        monthDays[1] = 28; // Feb
        // check leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            monthDays[1] = 29;
        }
        // check days
        if (day < 1 || day > monthDays[month - 1])
        {
            cout << "Invalid Day! Please Enter again : ";
            continue;
        }
        return date;
    }
}
// used in default case of switch to show invalid choice
void invalidErrorMessage()
{
    setTextColor(12); // change color to red
    cout << "\n\t\t\t\t\t\t\t\tInvalid choice! Please try again." << endl;
    setTextColor(8); // change color to grey
    system("pause"); // waits the user to press any key
}
// changes the color to specfic text only
void setTextColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

//loading bar
void loadingBar() {

    setTextColor(3);
    cout << "\n\n\n\t\t\tLoading....";
    cout << "\n\t\t\t";
    printf("\e[?25l");
    for (int i = 1; i <= 25; i++) {
        cout <<"▒";
    }
    setTextColor(2);
    cout << "\r\t\t\t";
    for (int i = 1; i <= 25; i++) {
        cout <<"█";
        Sleep(50);
    }
}
// use to input masked password
string maskedInputPass()
{
    char input;
    string inputPass;
    // cout<<"Enter the password : "; //bcz there already have this line
    input = _getch();
    while (input != 13) // Enter = 13 ascii
    {
        if (input == 8) // backslash
        {
            if (!inputPass.empty())
            {                         // checks if password not empty
                inputPass.pop_back(); // removes the last character
                cout << "\b \b";      // moves curser back, print space to overwrite and move back
            }
        }
        else
        {
            inputPass.push_back(input); // adds character to this
            cout << "●";                // print star to mask password
        }
        input = _getch();
    }
    cout << endl;
    return inputPass;
}

string validPhoneNo()
{
    string cellNo;
    while (true)
    {

        getline(cin, cellNo);
        // Check if length is exactly 11
        bool lengthValid = true;
        int length = LengthOf(cellNo);
        if (length != 11)
        {
            lengthValid = false;
        }

        // Check if start with 03
        bool startingNo = (cellNo[0] == '0' && cellNo[1] == '3');

        // Check if all characters are digits
        bool isDigits = true;
        for (int i = 0; i < length; i++)
        {
            if (cellNo[i] < '0' || cellNo[i] > '9')
            {
                isDigits = false;
                break;
            }
        }

        // Validate all conditions
        if (lengthValid && startingNo && isDigits)
        {
            return cellNo; // Valid phone number
        }

        // If any condition fails, print error and prompt again
        cout << "Incorrect phone number!\nPlease enter a valid 11-digit phone number : ";
    }
}

string validCNIC()
{
    char cnic[250]; // Temporary C-string to hold the input

    while (true)
    {
        cin.getline(cnic, 250);
        bool isValid = true;

        // Check length be 15 digit with dashes
        if (LengthOf(cnic) != 15)
        {
            isValid = false;
        }

        // Check dashes correct positions
        if (cnic[5] != '-' || cnic[13] != '-')
        {
            isValid = false;
        }
        // check can't start with zero
        bool isStartZero = false;
        if (cnic[0] == '0')
        {
            isValid = false;
            isStartZero = true;
        }
        // Check if all characters except dashes are digits
        for (int i = 0; i < LengthOf(cnic); i++)
        {
            if (i == 5 || i == 13)
                continue; // Skip dashes
            if (cnic[i] < '0' || cnic[i] > '9')
            {
                isValid = false;
                break;
            }
        }

        if (isValid)
        {
            return string(cnic);
        }
        else
        {
            if (isStartZero)
            {
                cout << "Cnic can't be start with 0 !!!\n";
            }
            cout << "Invalid CNIC!\nPlease enter  valid CNIC in the format XXXXX-YYYYYYYY-Y : ";
        }
    }
}

// valid name
string validName(int minLen, int maxLen, string errorMsg)
{
    char name[300]; // large size for monkey tests
    while (true)
    {
        cin.getline(name, 300); // Read with spaces

        int len = LengthOf(name);
        bool isValid = true;

        // Check valid length
        if (len < minLen || len > maxLen)
        {
            isValid = false;
        }

        // Check if the name contains only alphabets and spaces
        for (int i = 0; i < len; i++)
        {
            if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == ' '))
            {
                isValid = false;
                break;
            }
        }

        // Check if the name starts or ends with a space
        if (name[0] == ' ' || name[len - 1] == ' ')
        {
            isValid = false;
        }

        // Check for multiple consecutive Spaces
        for (int i = 0; i < len - 1; i++)
        {
            if (name[i] == ' ' && name[i + 1] == ' ')
            {
                isValid = false;
                break;
            }
        }

        if (isValid)
        {
            return string(name);
        }
        else
        {
            cout << errorMsg << endl;
        }
    }
}

// valid address
string validAddress()
{
    char address[600];

    while (true)
    {
        cin.getline(address, 600); // Read address including spaces

        int len = LengthOf(address);
        bool isValid = true;

        // Check length constraints
        if (len < 3 || len > 100)
        {
            isValid = false;
        }

        // Check if address contain only valid chars
        for (int i = 0; i < len; i++)
        {
            if (!((address[i] >= 'A' && address[i] <= 'Z') ||
                  (address[i] >= 'a' && address[i] <= 'z') ||
                  (address[i] >= '0' && address[i] <= '9') ||
                  address[i] == ' ' || address[i] == ',' ||
                  address[i] == '.' ||
                  address[i] == '/' ||
                  address[i] == '-' ||
                  address[i] == '#'))
            {
                isValid = false;
                break;
            }
        }

        // can't start or end with space
        if (address[0] == ' ' || address[len - 1] == ' ')
        {
            isValid = false;
        }

        // no two spaces consectively
        for (int i = 0; i < len - 1; i++)
        {
            if (address[i] == ' ' && address[i + 1] == ' ')
            {
                isValid = false;
                break;
            }
        }
        if (isValid)
        {
            return string(address);
        }
        else
        {
            cout << "Invalid address! Please enter again : ";
        }
    }
}

string validUsername()
{
    char username[600]; // Max length of username is 15 characters + null terminator

    while (true)
    {

        cin.getline(username, 600);

        int len = LengthOf(username);
        bool isValid = true;

        // Check length
        if (len < 3 || len > 15)
        {
            isValid = false;
        }
        // check if both not exist at start
        if (!(username[0] >= 'A' && username[0] <= 'Z') &&
            !(username[0] >= 'a' && username[0] <= 'z'))
        {
            isValid = false;
        }
        // check valid chars
        for (int i = 0; i < len; i++)
        {
            if (!((username[i] >= 'A' && username[i] <= 'Z') ||
                  (username[i] >= 'a' && username[i] <= 'z') ||
                  (username[i] >= '0' && username[i] <= '9') ||
                  username[i] == '_'))
            {
                isValid = false;
                break;
            }

            if ((i > 0 && username[i] == '_' && username[i - 1] == '_') ||
                (i == len - 1 && username[i] == '_'))
            { // check last char not be underscore
                isValid = false;
                break;
            }
        }

        if (isValid)
        {
            return string(username);
        }
        else
        {
            cout << "Invalid username! Please try again : ";
        }
    }
}

string validPwd()
{
    string pwd;

    while (true)
    {
        getline(cin, pwd); // used to check if user enter space which is invalid
        bool containSpaces = false;
        for (int i = 0; i < LengthOf(pwd); i++)
        {
            if (pwd[i] == ' ')
            {
                containSpaces = true; // found space
                break;
            }
        }
        if (containSpaces)
        {
            cout << "Password can't contain spaces! Enter valid Password: ";
            continue; // ask again untill enter correct
        }
        else
        {
            return pwd;
        }
    }
}

// valid gender
string validGender()
{
    string gender;
    while (true)
    {
        getline(cin, gender);
        // convert to lower case
        gender = toLowerCase(gender);
        if (gender == "male" || gender == "female" || gender == "other")
        {

            return gender;
        }
        else
        {
            cout << "Invalid gender! please enter correct gender (male, female, other) : ";
        }
    }
}
//<----------------------------------mobile validations-------------------------------------->
string validModelName()
{
    char modelName[600];
    while (true)
    {
        cin.getline(modelName, 600); // read with spaces

        int len = LengthOf(modelName);
        bool isValid = true;

        // Check valid length 2 to 25
        if (len < 2 || len > 25)
        {
            isValid = false;
        }

        // Check only contain alphabet, digit, and spaces....
        for (int i = 0; i < len; i++)
        {
            if (!((modelName[i] >= 'A' && modelName[i] <= 'Z') ||
                  (modelName[i] >= 'a' && modelName[i] <= 'z') ||
                  (modelName[i] >= '0' && modelName[i] <= '9') ||
                  modelName[i] == ' '))
            {
                isValid = false;
                break;
            }
        }

        // Check if name start or ends with a space
        if (modelName[0] == ' ' || modelName[len - 1] == ' ')
        {
            isValid = false;
        }

        // Check for multiple consecutive spaces
        for (int i = 0; i < len - 1; i++)
        {
            if (modelName[i] == ' ' && modelName[i + 1] == ' ')
            {
                isValid = false;
                break;
            }
        }

        if (isValid)
        {
            return string(modelName); // Return valid model name
        }
        else
        {
            cout << "Invalid model name! Please enter a valid model name:\n";
        }
    }
}

string validStorage()
{
    char storage[600];    // large size so array hold large
    int storageValue = 0; // for int type manuplation to check right storage
    bool isValid = false;
    bool isTB = false;

    while (!isValid)
    {

        cin.getline(storage, 600);

        int length = LengthOf(storage);
        isValid = true; // valid until proved invalid

        // Check if gb or tb at last
        if (length >= 2 &&
            ((storage[length - 2] == 'G' || storage[length - 2] == 'g') &&
             (storage[length - 1] == 'B' || storage[length - 1] == 'b')))
        {
            length -= 2; // Ignore last 2 bcz to check int value that left
        }
        else if (length >= 2 &&
                 ((storage[length - 2] == 'T' || storage[length - 2] == 't') &&
                  (storage[length - 1] == 'B' || storage[length - 1] == 'b')))
        {
            length -= 2; // Ignore the last 2 validate tb
            isTB = true;
        }
        else
        {
            isValid = false;
        }

        // Check if remaining input  numeric
        storageValue = 0; // Reset storageValue before start..
        for (int i = 0; i < length; i++)
        {
            if (storage[i] < '0' || storage[i] > '9')
            {
                isValid = false;
                break;
            }
            storageValue = storageValue * 10 + (storage[i] - '0'); // Convert char to int
        }

        // Convert TB to GB to check valid range
        if (isTB)
        {
            storageValue *= 1024; // now in GB is
        }

        // Check valid range (1 GB to 2048 gb)
        if (isValid && (storageValue < 1 || storageValue > 2048))
        {
            isValid = false;
        }

        // If the input is valid then return
        if (isValid)
        {
            string result = intToString(storageValue);
            if (isTB)
            {
                result += " TB";
            }
            else
            {
                result += " GB";
            }
            return result;
        }
        else
        {
            cout << "Invalid storage! Enter a valid storage capacity (1 GB to 2048 GB or 1 TB): ";
            storageValue = 0; // Reset for next iteration
            isTB = false;
        }
    }
    return ""; // This should never be reached
}

string validSpecs()
{
    string specs;
    while (true)
    {

        getline(cin, specs);

        bool isValid = true;
        int len = LengthOf(specs);

        if (len < 4 || len > 200)
        {
            isValid = false;
        }

        // Check if contain only valid characters (. + - )
        for (int i = 0; i < len; i++)
        {
            if (!(isalnum(specs[i]) || specs[i] == ' ' || specs[i] == '-' || specs[i] == '.' || specs[i] == '+'))
            {
                isValid = false;
                break;
            }
        }

        // Check if snot empty or last char not space
        if (len == 0 || specs[0] == ' ' || specs[len - 1] == ' ')
        {
            isValid = false;
        }

        // If specs contain multiple consecutive spaces, mark as invalid
        for (int i = 0; i < len - 1; i++)
        {
            if (specs[i] == ' ' && specs[i + 1] == ' ')
            {
                isValid = false;
                break;
            }
        }

        if (isValid)
        {
            return specs;
        }
        else
        {
            cout << "Invalid specs! Please enter valid mobile specifications:";
        }
    }
}

int validIntInput(const string &fieldName, int minValue, int maxValue)
{
    int num;
    while (true)
    {

        cin >> num;
        // Check if the input is a valid integer
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error! Please enter a valid integer for " << fieldName << ": ";
        }
        else if (num >= minValue && num <= maxValue)
        {
            return num;
        }
        else
        {
            // If the number is out of range, ask the user to enter again
            cout << "Invalid number! " << fieldName << " must be between " << minValue << " and " << maxValue << ". Please try again: ";
        }
    }
}
//<-----------------------------------smart functions------------------------------------->
int LengthOf(const string &str)
{
    int length = 0;
    // iterate untill null char found
    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}
// convert string to lower case
string toLowerCase(string str)
{
    for (int i = 0; i < LengthOf(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return str;
}

string tokenizer(string str, int field)
{
    int commaCount = 0;
    string res = "";
    for (int i = 0; i < LengthOf(str); i++)
    {
        if (str[i] == ',')
            commaCount++;
        else if (commaCount == field - 1)
            res += str[i];
        else if (commaCount >= field)
            break;
    }
    return res;
}
string intToString(int number)
{
    string result = "";
    // Check if the number is zero
    if (number == 0)
    {
        result = "0";
        return result;
    }

    bool isNegative = false;
    if (number < 0)
    {
        isNegative = true;
        number = -number; // change to +ve for temporarily
    }

    while (number > 0)
    {
        char digit = (number % 10) + '0'; // Get last digit & convert to char
        result = digit + result;
        number /= 10; // Remove the last digit
    }

    if (isNegative)
    {
        result = "-" + result;
    }

    return result; // Return the final string
}

int stringToInt(string str)
{
    int result = 0;
    bool isNegative = false;
    int i = 0;
    if (str[0] == '-')
    {
        isNegative = true;
        i = 1;
    }
    for (i; i < LengthOf(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i] - '0'); // change into int by - '0'
        }
        else
        {
            cout << "Invalid string";
            return 0;
        }
    }
    return isNegative ? -result : result;
}

//<-------------------------------Manager functionalities------------------------------->
// employee adding function
void addEmployee(Employee emp[], int EmpSize, int &empCount)
{
    string username = "";
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "        --- Add a Employee ---      " << endl;
    setTextColor(14);
    cout << " ===================================" << endl;

    if (empCount < EmpSize)
    {
        for (int i = 0; i < EmpSize; i++)
        {
            if (!emp[i].isExist)
            {
                cout << "Enter Username : ";
                username = validUsername();
                while (!isEmpUsernameUnique(username, emp, EmpSize))
                {
                    setTextColor(12); // red
                    cout << "Username already exists!!!\n";
                    setTextColor(14);
                    cout<<"Please enter a different username: ";
                    username = validUsername();
                }
                emp[i].username = username;
                cout << "Enter Password : ";
                cin.ignore();
                emp[i].pwd = validPwd();
                cout << "Enter employee full name : ";
                emp[i].name = validName(3, 21, "Invalid name! Please enter valid name :");
                cout << "Enter employee father's name : ";
                emp[i].fatherName = validName(3, 21, "Invalid name! Please enter valid name :");
                cout << "Enter employee 11-degit phone number : ";
                emp[i].cellNo = validPhoneNo();
                cout << "Enter employee cnic in format XXXXX-YYYYYYYY-Y : ";
                emp[i].cnic = validCNIC();
                cout << "Enter employee address : ";
                emp[i].address = validAddress();
                cout << "Enter employee date of birth (DD-MM-YYYY): ";
                emp[i].dob = validDate();
                cin.ignore();
                cout << "Enter gender (M for male or F for Female): ";
                emp[i].gender = validGender();
                empCount++;
                emp[i].isExist = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tEmployee added successfully......." << endl;
                cin.get();
                break;
            }
        }
    }
    else
    {
        setTextColor(12); // red
        cout << "\n\tMaximum number of employees reached. Cannot add more employees!" << endl;
        cin.get();
    }
    saveEmployeeData(emp, EmpSize, empCount);
}

// Uemp :
void updateEmployee(Employee emp[], int EmpSize, int &empCount)
{
    string username;          // for searching by username
    bool isUserFound = false; // checks if user found & data updated
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "     --- Update Employee Data ---   " << endl;
    setTextColor(14);
    cout << " ===================================" << endl;
    if (empCount != 0)
    {
        cout << " Enter username of employee : ";
        username = validUsername();
        for (int i = 0; i < EmpSize; i++)
        {
            if (username == emp[i].username)
            {
                cout << "Enter updated Username : ";
                // cin.ignore();
                emp[i].username = validUsername();
                cout << "Enter new Password : ";
                emp[i].pwd = validPwd();
                cout << "Enter employee full name : ";
                emp[i].name = validName(3, 21, "Invalid name! Please enter valid name :");
                cout << "Enter employee father's name : ";
                emp[i].fatherName = validName(3, 21, "Invalid name! Please enter valid name :");
                cout << "Enter employee 11-degit phone number : ";
                emp[i].cellNo = validPhoneNo();
                cout << "Enter employee cnic in format XXXXX-YYYYYYYY-Y : ";
                emp[i].cnic = validCNIC();
                cout << "Enter employee address : ";
                emp[i].address = validAddress();
                cout << "Enter employee date of birth (DD-MM-YYYY): ";
                emp[i].dob = validDate();
                cin.ignore();
                cout << "Enter gender (M for male or F for Female): ";
                emp[i].gender = validGender();
                isUserFound = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tEmployee data updated successfully......." << endl;
                break;
            }
        }
        if (!isUserFound)
        {
            setTextColor(12); // Red
            cout << "\n  No user found!";
        }
    }
    else
    {
        setTextColor(12); // Red
        cout << "\nNo employee added yet!" << endl;
    }
    saveEmployeeData(emp, EmpSize, empCount);
    cin.get();
}

void deleteEmployee(Employee emp[], int EmpSize, int &empCount)
{
    string username;          // for searching by username
    bool isUserFound = false; // checks if user found & data deleted
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "     --- Delete Employee Data ---   " << endl;
    setTextColor(14);
    cout << " ===================================" << endl;
    if (empCount != 0)
    {
        cout << " Enter username of employee : ";
        username = validUsername();
        for (int i = 0; i < EmpSize; i++)
        {
            if (username == emp[i].username)
            {
                emp[i].name = "nv";
                emp[i].fatherName = "nv";
                emp[i].cellNo = "nv";
                emp[i].address = "nv";
                emp[i].cnic = "nv";
                emp[i].dob = "nv";
                emp[i].gender = 'u';
                emp[i].isExist = false;
                emp[i].username = "nv";
                emp[i].pwd = "nv";
                empCount--;
                emp[i].isExist = false;
                isUserFound = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tEmployee data deleted successfully......." << endl;
                break;
            }
        }
        if (!isUserFound)
        {
            setTextColor(12); // Red
            cout << "\n No user found!";
        }
    }
    else
    {
        setTextColor(12); // Red
        cout << "\nNo employee added yet!" << endl;
    }
    cin.get();
    saveEmployeeData(emp, EmpSize, empCount);
}

// view employees
void viewEmployee(Employee emp[], int EmpSize, int &empCount)
{
    system("cls");
    cout << endl
         << endl;
    setTextColor(14);
    cout << "\t\t\t\t\t\t\t\t===================================" << endl;
    setTextColor(11);
    cout << "\t\t\t\t\t\t\t\t     --- View all Employees ---    " << endl;
    setTextColor(14);
    cout << "\t\t\t\t\t\t\t\t===================================" << endl
         << endl;
    cout << left;
    cout << " -----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(7) << " | No. " << setw(13) << "| Username" << setw(13) << "| Password" << setw(16) << "| Full Name" << setw(16) << "| Father Name" << setw(15) << "| Cell No" << setw(19) << "| CNIC" << setw(15) << "| DOB" << setw(9) << "| Gender" << setw(44) << "| Address" << "|" << endl;
    cout << " -----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    if (empCount != 0)
    {
        int counter = 1;
        for (int i = 0; i < EmpSize; i++)
        {
            if (emp[i].isExist)
            {
                cout << " | " << setw(4) << counter << "| "
                     << setw(11) << emp[i].username << "| "
                     << setw(11) << emp[i].pwd << "| "
                     << setw(14) << emp[i].name << "| "
                     << setw(14) << emp[i].fatherName << "| "
                     << setw(13) << emp[i].cellNo << "| "
                     << setw(17) << emp[i].cnic << "| "
                     << setw(13) << emp[i].dob << "| "
                     << setw(7) << emp[i].gender << "| "
                     << setw(42) << emp[i].address << "| " << endl;
                counter++;
            }
        }
        cout << " -----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    else
    {
        setTextColor(12); // Red
        cout << "\n\tNo employee added yet!" << endl;
    }
    cin.get();
}

//<-------------------------------inventry management---------------------------------->
// add mobiles
void addMobiles(Mobile mob[], int MaxMobile, int &mobileCount)
{
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "        --- Add Mobiles ---       " << endl;
    setTextColor(14);
    cout << " ===================================" << endl
         << endl;
    if (mobileCount <= MaxMobile)
    {
        for (int i = 0; i < MaxMobile; i++)
        {
            if (!mob[i].isExist)
            {
                cout << "Enter mobile Brand : ";
                mob[i].brand = validName(2, 15, "Invalid Brand name! Please enter valid Brand :");
                cout << "Enter model: ";
                mob[i].model = validModelName();
                cout << "Enter storage in (GB or TB): ";
                mob[i].storage = validStorage();
                cout << "Enter specs: ";
                mob[i].specs = validSpecs();
                cout << "Enter mobile color: ";
                mob[i].color = validName(3, 10, "Invalid Color name! Please enter valid color :");
                cout << "Enter supplier name: ";
                mob[i].supplierName = validName(3, 21, "Invalid name! Please enter valid name :");
                cout << "Enter quantity: ";
                mob[i].qty = validIntInput("Quantity", 1, 1000);
                cout << "Enter purchase Price: ";
                mob[i].purchasePrice = validIntInput("Purchase Price", 1, 1000000);
                cout << "Enter sale Price: ";
                mob[i].salePrice = validIntInput("Sale Price", 1, 1000000);
                cout << "Enter minimum Stock Level: ";
                mob[i].minStockLevel = validIntInput("Minimum Stock Level", 1, 500);
                mobileCount++;
                mob[i].itemId = i + 1;
                mob[i].isExist = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tMobile added successfully......." << endl;
                saveInventryData(mob, MaxMobile, mobileCount);
                cin.ignore();
                cin.get();
                break;
            }
        }
    }
    else
    {
        setTextColor(12); // red
        cout << "\n\tMaximum number of mobiles reached. Cannot add more mobiles!" << endl;
        cin.get();
    }
}

// update mobiles
void updateMobiles(Mobile mob[], int MaxMobile, int &mobileCount)
{
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "        --- Update Mobiles ---      " << endl;
    setTextColor(14);
    cout << " ===================================" << endl
         << endl;
    if (mobileCount != 0)
    {
        string searchMob;
        bool Found = false;
        cout << "Enter the mobile name : ";
        searchMob = validModelName();
        for (int i = 0; i < MaxMobile; i++)
        {
            if (mob[i].model == searchMob)
            {
                cout << "Enter mobile Brand : ";
                mob[i].brand = validName(2, 15, "Invalid Brand name! Please enter valid Brand :");
                cout << "Enter model: ";
                mob[i].model = validModelName();
                cout << "Enter storage in (GB or TB): ";
                mob[i].storage = validStorage();
                cout << "Enter specs: ";
                mob[i].specs = validSpecs();
                cout << "Enter mobile color: ";
                mob[i].color = validName(3, 10, "Invalid Color name! Please enter valid name :");
                cout << "Enter supplier name: ";
                mob[i].supplierName = validName(3, 21, "Invalid name! Please enter valid name :");
                cout << "Enter quantity: ";
                mob[i].qty = validIntInput("Quantity", 1, 1000);
                cout << "Enter purchase Price: ";
                mob[i].purchasePrice = validIntInput("Purchase Price", 1, 1000000);
                cout << "Enter sale Price: ";
                mob[i].salePrice = validIntInput("Sale Price", 1, 1000000);
                cout << "Enter minimum Stock Level: ";
                mob[i].minStockLevel = validIntInput("Minimum Stock Level", 1, 500);
                Found = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tMobile updated successfully......." << endl;
                saveInventryData(mob, MaxMobile, mobileCount);
                cin.get();
                break;
            }
        }
        if (!Found)
        {
            setTextColor(12); // Red
            cout << "No mobile exist in list!" << endl;
        }
    }
    else
    {
        setTextColor(12); // Red
        cout << "No Mobile added Yet!" << endl;
    }
    cin.get();
}

void deleteMobiles(Mobile mob[], int MaxMobile, int &mobileCount)
{
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "        --- Delete Mobiles ---      " << endl;
    setTextColor(14);
    cout << " ===================================" << endl
         << endl;
    if (mobileCount != 0)
    {
        string searchMob;
        bool Found = false;
        cout << "Enter the mobile name : ";
        searchMob = validModelName();
        for (int i = 0; i < MaxMobile; i++)
        {
            if (mob[i].model == searchMob)
            {
                mob[i].brand = "nv";
                mob[i].model = "nv";
                mob[i].storage = "nv";
                mob[i].specs = "nv";
                mob[i].color = "nv";
                mob[i].supplierName = "nv";
                mob[i].qty = -1;
                mob[i].purchasePrice = -1;
                mob[i].salePrice = -1;
                mob[i].minStockLevel = -1;
                mobileCount--;
                mob[i].itemId = -1;
                mob[i].isExist = false;
                Found = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tMobile deleted successfully......." << endl;
                saveInventryData(mob, MaxMobile, mobileCount);
            }
        }
        if (!Found)
        {
            setTextColor(12); // Red
            cout << "No mobile exist in list!" << endl;
        }
    }
    else
    {
        setTextColor(12); // Red
        cout << "No Mobile added Yet!" << endl;
    }
    cin.get();
}

void viewMobiles(Mobile mob[], int MaxMobile, int &mobileCount, bool isAdmin)
{
    system("cls");
    cout << endl
         << endl;
    setTextColor(14);
    cout << "\t\t\t\t\t\t\t\t===================================" << endl;
    setTextColor(11);
    cout << "\t\t\t\t\t\t\t\t     --- View all Mobiles ---      " << endl;
    setTextColor(14);
    cout << "\t\t\t\t\t\t\t\t===================================" << endl
         << endl;
    cout << left;
    if (isAdmin)
    {
        cout << "\t ------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "\t ------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    cout << "\t";
    cout << setw(10) << " | Item Id" << setw(11) << " | Brand " << setw(19) << "| Model" << setw(17) << "| Storage" << setw(38) << "| Specs" << setw(10) << "| Color";
    if (isAdmin)
    {
        cout << setw(17) << "| Supplier Name" << setw(10) << "| Qty" << setw(17) << "| Purchase Price" << setw(13) << "| Sale Price" << "|" << endl;
        cout << "\t ------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    else
    {
        cout << setw(15) << "|   Price" << "|" << endl;
        cout << "\t ------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    if (mobileCount != 0)
    {
        for (int i = 0; i < MaxMobile; i++)
        {
            if (mob[i].isExist)
            {
                (mob[i].qty > 0) ? setTextColor(14) : setTextColor(12);
                cout << "\t";
                cout << " | " << setw(8) << mob[i].itemId << "| "
                     << setw(8) << mob[i].brand << "| "
                     << setw(17) << mob[i].model << "| "
                     << setw(15) << mob[i].storage << "| "
                     << setw(36) << mob[i].specs << "| "
                     << setw(8) << mob[i].color << "| ";
                if (isAdmin)
                {
                    cout << setw(15) << mob[i].supplierName << "| "
                         << setw(8) << mob[i].qty << "| "
                         << setw(15) << mob[i].purchasePrice << "| "
                         << setw(11) << mob[i].salePrice << "| "
                         << endl;
                }
                else
                {
                    cout << setw(13) << mob[i].salePrice << "| " << endl;
                }
            }
        }
        if (isAdmin)
        {
            cout << "\t ------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
        else
        {
            cout << "\t ------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
    else
    {
        setTextColor(12); // Red
        cout << "\n\tNo Mobile added Yet!" << endl;
    }
    cin.get();
}

void lowStock(Mobile mob[], int MaxMobile, int &mobileCount)
{
    system("cls");
    bool foundOrder = false;
    cout << endl
         << endl;
    setTextColor(14);
    cout << "\t\t\t\t\t\t===================================" << endl;
    setTextColor(11);
    cout << "\t\t\t\t\t\t     --- Low Stock Alert  ---      " << endl;
    setTextColor(14);
    cout << "\t\t\t\t\t\t===================================" << endl
         << endl;
    cout << left;
    setTextColor(11);
    cout << "\t\t\t ------------------------------------------------------------------------" << endl;
    cout << "\t\t\t";
    cout << setw(10) << " | Item Id" << setw(13) << " | Brand " << setw(20) << "| Model" << setw(18) << "| Supplier Name" << setw(11) << "| Qty" << "|" << endl;
    cout << "\t\t\t ------------------------------------------------------------------------" << endl;
    bool foundItems = false;
    if (mobileCount != 0)
    {
        for (int i = 0; i < MaxMobile; i++)
        {
            if (mob[i].isExist && mob[i].qty < mob[i].minStockLevel)
            {
                foundItems = true;
                setTextColor(7);
                cout << "\t\t\t";
                cout << " | " << setw(7) << mob[i].itemId << "| "
                     << setw(11) << mob[i].brand << "| "
                     << setw(18) << mob[i].model << "| "
                     << setw(16) << mob[i].supplierName << "| ";

                setTextColor(12); // Red for low quantity
                cout << setw(9) << mob[i].qty << "| " << endl;
            }
        }
        if (!foundItems)
        {
            setTextColor(10); // Green
            cout << "\t\t\t All items are sufficiently stocked!" << endl;
        }
        setTextColor(11);
        cout << "\t\t\t ------------------------------------------------------------------------" << endl;
    }
    else
    {
        setTextColor(12);
        cout << "\n\t\t\tNo mobile added yet!" << endl;
    }
    cin.get();
}

//<----------------------------profit report------------------------------------->
void profitReport(int &total_Cost, int &total_Revenue, int &total_Profit, int &mobSold)
{
    system("cls");
    bool foundOrder = false;
    cout << endl
         << endl;
    setTextColor(14);
    cout << "\t\t\t\t\t\t===================================" << endl;
    setTextColor(11);
    cout << "\t\t\t\t\t\t     --- Profit Report  ---      " << endl;
    setTextColor(14);
    cout << "\t\t\t\t\t\t===================================" << endl
         << endl;
    cout << left;
    cout << left;
    if (total_Profit != 0 && total_Revenue != 0 && total_Cost != 0)
    {
        setTextColor(10); // Light Green=
        cout << setw(20) << "\t\t\t\t\t\tMobiles Sold" << ": " << setw(10) << mobSold << endl;
        cout << setw(20) << "\t\t\t\t\t\tTotal Revenue" << ": " << setw(10) << total_Revenue << endl;
        cout << setw(20) << "\t\t\t\t\t\tTotal Cost" << ": " << setw(10) << total_Cost << endl;
        cout << setw(20) << "\t\t\t\t\t\tTotal Profit" << ": " << setw(10) << total_Profit << endl;
        setTextColor(14);
        cout << "\t\t\t\t\t\t===================================" << endl;
    }
    else
    {
        setTextColor(12); // Red
        cout << "\nProfit report unavailable. No mobile phones have been sold so far!";
    }
    cin.get();
}

//<-----------------------customer order management------------------------------------->
void ShowPendingOrders(Mobile mob[], int MaxMobile, int &mobileCount, string username, string pwd, Customer cus[], int CusSize, CustomerOrder cust[])
{
    system("cls");
    bool foundOrder = false;
    cout << endl
         << endl;
    setTextColor(14);
    cout << "\t\t\t\t\t\t\t\t===================================" << endl;
    setTextColor(11);
    cout << "\t\t\t\t\t\t\t\t     --- PENDING ORDERS  ---      " << endl;
    setTextColor(14);
    cout << "\t\t\t\t\t\t\t\t===================================" << endl
         << endl;
    cout << left;
    cout << "\t ---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << "\t | Customer Name" << setw(16) << " | Username " << setw(10) << " | Item Id" << setw(11) << " | Brand " << setw(19) << "| Model" << setw(17) << "| Storage" << setw(10) << "| Color" << setw(13) << "| Price" << setw(7) << "| Qty " << setw(15) << "| Total Price " << setw(16) << "| Status" << "|" << endl;
    cout << "\t ---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int cusIndex = 0; cusIndex < CusSize; cusIndex++)
    {
        if (cus[cusIndex].isExist)
        { // is customer exist
            for (int cusField = 0; cusField < MaxOrder; cusField++)
            {
                // if (isOrderExist[cus][cusField])
                if (cust[cusIndex].orders[cusField].isExist)
                {
                    for (int k = 0; k < MaxMobile; k++) // this loop just to show mobile details by retrive item id
                    {                                   // extrcting the data of mobile by itemId stores at field i
                        if (cust[cusIndex].orders[cusField].itemId == mob[k].itemId)
                        {
                            cout << "\t";
                            cout << " | " << setw(17) << cus[cusIndex].name << "| "
                                 << setw(14) << cus[cusIndex].username << "| "
                                 << setw(8) << mob[k].itemId << "| "
                                 << setw(8) << mob[k].brand << "| "
                                 << setw(17) << mob[k].model << "| "
                                 << setw(15) << mob[k].storage << "| "
                                 << setw(8) << mob[k].color << "| "
                                 << setw(11) << mob[k].salePrice << "| "
                                 << setw(5) << cust[cusIndex].orders[cusField].qty << "| "
                                 << setw(13) << cust[cusIndex].orders[cusField].qty * mob[k].salePrice << "| "
                                 << setw(14) << cust[cusIndex].orders[cusField].status << "|" << endl;
                            foundOrder = true;
                        }
                    }
                }
            }
        }
    }
    if (foundOrder)
    {
        cout << "\t ---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    else
    {
        setTextColor(12); // Red
        cout << "\n\t\tNo pending orders found :)" << endl;
    }
}

void managePendingOrders(Mobile mob[], int MaxMobile, int &mobileCount, string username, string pwd, Customer cus[], int CusSize, CustomerOrder cust[],DeliveredOrder order[], int &total_Cost, int &total_Revenue, int &total_Profit, int &mobSold)
{
    int choice;
    int stChoice;
    string inputUsername = "";
    int itemId = 0;
    bool isUserFound = false;
    bool isItemIdCorrect = false;
    string updateStatus = "";

    do
    {
        ShowPendingOrders(mob, MaxMobile, mobileCount, username, pwd, cus, CusSize, cust);

        cout << endl;
        setTextColor(14);
        cout << "\t 1. ";
        setTextColor(11);
        cout << "Update Order Status" << endl;
        setTextColor(14);
        cout << "\t 0. ";
        setTextColor(11);
        cout << "Exit" << endl;
        setTextColor(14);
        cout << "\t ------------------------" << endl;
        choice = getValidDigitInput(); // assures valid input digit 0-9

        switch (choice)
        {
        case 1:
        {
            cout << "\tEnter username of customer: ";
            inputUsername = validUsername();
            cout << "\tEnter item ID: ";
            itemId = validIntInput("Item ID", 0, 1000);

            cout << "\tSelect new status:" << endl;
            cout << "\t1. Shipped" << endl;
            cout << "\t2. Delivered" << endl;
            cout << "\t3. Out of Stock" << endl;

            do
            {
                stChoice = -1;
                stChoice = getValidDigitInput();
                if (stChoice != 1 && stChoice != 2 && stChoice != 3)
                { //if user enter invalid choice
                   invalidErrorMessage(); // shows invalid error message
                }
            } while (stChoice != 1 && stChoice != 2 && stChoice != 3);

            for (int cusIndex = 0; cusIndex < CusSize; cusIndex++)
            {
                if (inputUsername == cus[cusIndex].username)
                {
                    isUserFound = true;
                    for (int cusField = 0; cusField < MaxOrder; cusField++)
                    {
                        if (cust[cusIndex].orders[cusField].isExist && cust[cusIndex].orders[cusField].itemId == itemId)
                        {
                            isItemIdCorrect = true;
                            //this is used if mistakely status updated to delivered 
                            if (stChoice == 1 && cust[cusIndex].orders[cusField].status == "Delivered")
                            {
                                setTextColor(10); // Green
                                cust[cusIndex].orders[cusField].status = "Shipped";
                                cout << "\n\t\t\tOrder status updated back to Shipped successfully.\n";
                                saveOrders(cus, CusSize, cust);
                                cin.get();
                            }
                            else if (cust[cusIndex].orders[cusField].status == "Delivered")
                            {
                                setTextColor(12); // Red
                                cout << "\tThis order is already Delivered. Status cannot be changed further.\n";
                                cin.get();
                            }
                            else if (cust[cusIndex].orders[cusField].status == "Shipped" && stChoice == 1)
                            {
                                setTextColor(12); // Red
                                cout << "\tThis order is already Shipped. Please select a different option.\n";
                                cin.get();
                            }
                            else if (cust[cusIndex].orders[cusField].status == "Shipped" && stChoice == 3)
                            {
                                setTextColor(12); // Red
                                cout << "\torder's status cannot be updated to 'Out of Stock' once it has been shipped.\n";
                                cin.get();
                            }
                            else if (cust[cusIndex].orders[cusField].status == "Pending" && stChoice == 2)
                            {
                                setTextColor(12); // Red
                                cout << "\tThe order's status cannot be updated directly to 'Delivered'.\n";
                                cin.get();
                            }
                            else if (cust[cusIndex].orders[cusField].status == "Out of Stock" && stChoice == 2)
                            {
                                setTextColor(12); // Red
                                cout << "\tThe order's status cannot be updated directly to 'Delivered'.\n";
                                cin.get();
                            }
                            else
                            {
                                if (stChoice == 1 && cust[cusIndex].orders[cusField].status != "Shipped")
                                {
                                    // Update status to Shipped & decrease inventory
                                    cust[cusIndex].orders[cusField].status = "Shipped";
                                    for (int k = 0; k < MaxMobile; k++)
                                    {
                                        if (mob[k].itemId == itemId)
                                        {
                                            mob[k].qty -= cust[cusIndex].orders[cusField].qty;
                                            total_Profit += (mob[k].salePrice - mob[k].purchasePrice) * cust[cusIndex].orders[cusField].qty;
                                            total_Revenue += mob[k].salePrice * cust[cusIndex].orders[cusField].qty;
                                            total_Cost += mob[k].purchasePrice * cust[cusIndex].orders[cusField].qty;
                                            mobSold += cust[cusIndex].orders[cusField].qty;
                                            if (cust[cusIndex].orderCount > 1)
                                                cust[cusIndex].orderCount--;
                                            saveProfitReport(total_Cost, total_Revenue, total_Profit, mobSold);
                                            saveInventryData(mob, MaxMobile, mobileCount);
                                            saveOrders(cus, CusSize, cust);
                                            break;
                                        }
                                    }
                                    setTextColor(10); // Green
                                    cout << "\n\t\t\tOrder status updated to Shipped successfully.\n";
                                    cin.get();
                                }
                                else if (stChoice == 2 && cust[cusIndex].orders[cusField].status == "Shipped")
                                {
                                    // Update status to Delivered without modifying inventory
                                    for(int i=0; i<150; i++){
                                    if(order[i].cusUsername=="nv"){
                                        order[i].cusUsername = cus[cusIndex].username;
                                        order[i].itemId = itemId;
                                        order[i].qty = cust[cusIndex].orders[cusField].qty;
                                        break;
                                    }
                                    }
                                    cust[cusIndex].orders[cusField].status = "Delivered";
                                    setTextColor(10); // Green
                                    saveOrders(cus, CusSize, cust);
                                    cout << "\n\t\t\tOrder status updated to Delivered successfully.\n";
                                    cin.get();
                                }
                                else if (stChoice == 3)
                                {
                                    // Update status to Out of Stock
                                    cust[cusIndex].orders[cusField].status = "Out of Stock";
                                    setTextColor(10); // Green
                                    saveOrders(cus, CusSize, cust);
                                    cout << "\n\t\t\tOrder status updated to Out of Stock successfully.\n";
                                    cin.get();
                                }
                                else
                                {
                                    setTextColor(12); // Red
                                    cout << "\tInvalid status update request.\n";
                                    cin.get();
                                }
                            }
                            break;
                        }
                    }
                }
            }
            if (!isUserFound)
            {
                setTextColor(12); // Red
                cout << "\tNo customer found with the provided username.\n";
                cin.ignore();
            }
            if (isUserFound && !isItemIdCorrect)
            {
                setTextColor(12); // Red
                cout << "\tIncorrect item ID!\n";
                cin.ignore();
            }
            break;
        }
        case 0:
            break; // Exit case
        default:
            invalidErrorMessage();
            break;
        }
    } while (choice != 0);
    choice = -1;
    saveOrders(cus, CusSize, cust);
}

//----------------------------------------------Customer related functions------------------------------------------------>
void addCustomer(Customer cus[], int CusSize, int &customerCount)
{
    string username = ""; //temp input
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "        --- Create Profile ---      " << endl;
    setTextColor(14);
    cout << " ===================================" << endl;
    ;
    if (customerCount < CusSize)
    {
        for (int i = 0; i < CusSize; i++)
        {
            if (!cus[i].isExist)
            {
                cout << "Enter Username : ";
                username = validUsername();
                while (!isCusUsernameUnique(username, cus, CusSize))
                {
                    setTextColor(12); // red
                    cout << "Username already exists!!!\n";
                    setTextColor(14);
                    cout<<"Please enter a different username: ";
                    username = validUsername();
                }
                cus[i].username = username;
                cout << "Enter Password : ";
                cus[i].pwd = validPwd();
                cout << "Enter your name :";
                cus[i].name = validName(3, 21, "Invalid name! Please enter valid name :");
                cout << "Enter your phone number : ";
                cus[i].cellNo = validPhoneNo();
                cout << "Enter your date of birth : ";
                cus[i].dob = validDate();
                cout << "Enter your gender : ";
                cin.ignore();
                cus[i].gender = validGender();
                cout << "Enter your Address : ";
                cus[i].address = validAddress();
                customerCount++;
                cus[i].isExist = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tProfile Created Successfully......." << endl;
                SaveCustomerData(cus, CusSize, customerCount);
                cin.get();
                break;
            }
        }
    }
    else
    {
        setTextColor(12); // red
        cout << "\n\tNo more Space to create profile, Please contact with manager!" << endl;
        cin.get();
    }
}

void updateCustomer(Customer cus[], int CusSize, int &customerCount)
{
    string username;          // for searching by username
    bool isUserFound = false; // checks if user found & data updated
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "     --- Update Customer Data ---   " << endl;
    setTextColor(14);
    cout << " ===================================" << endl;
    if (customerCount != 0)
    {
        string username;
        bool isUserFound = false;
        cout << " Enter existing username of Customer : ";
        username = validUsername();
        for (int i = 0; i < CusSize; i++)
        {
            if (username == cus[i].username)
            {
                cout << " Enter Username : ";
                cus[i].username = validUsername();
                cout << " Enter Password : ";
                cus[i].pwd = validPwd();
                cout << " Enter your name :";
                cus[i].name = validName(3, 21, " Invalid name! Please enter valid name :");
                cout << " Enter your phone number : ";
                cus[i].cellNo = validPhoneNo();
                cout << " Enter your date of birth : ";
                cus[i].dob = validDate();
                cout << " Enter your gender : ";
                cin.ignore();
                cus[i].gender = validGender();
                cout << " Enter your Address : ";
                cus[i].address = validAddress();
                isUserFound = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tCustomer data updated successfully......." << endl;
                SaveCustomerData(cus, CusSize, customerCount);
                cin.get();
                break;
            }
        }
        if (!isUserFound)
        {
            setTextColor(12); // Red
            cout << "\n  No user found!";
            cin.get();
        }
    }
    else
    {
        setTextColor(12); // Red
        cout << "\nNo employee added yet!" << endl;
    }
}

void deleteCustomer(Customer cus[], int CusSize, int &customerCount)
{
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "   --- Delete Customer account ---  " << endl;
    setTextColor(14);
    cout << " ===================================" << endl;
    if (customerCount != 0)
    {
        string username;
        bool isUserFound = false;
        cout << " Enter username of Customer : ";
        username = validUsername();
        for (int i = 0; i < CusSize; i++)
        {
            if (username == cus[i].username)
            {
                cus[i].username = "nv";
                cus[i].pwd = "nv";
                cus[i].name = "nv";
                cus[i].cellNo = "nv";
                cus[i].address = "nv";
                cus[i].dob = "nv";
                cus[i].gender = "nv";
                cus[i].isExist = false;
                customerCount--;
                isUserFound = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tCustomer data deleted successfully......." << endl;
                SaveCustomerData(cus, CusSize, customerCount);
                cin.get();
                break;
            }
        }
        if (!isUserFound)
        {
            setTextColor(12); // Red
            cout << "\n No user found!";
            cin.get();
        }
    }
    else
    {
        setTextColor(12); // Red
        cout << "\nNo customer created his/her account yet!" << endl;
    }
}

void viewAllCustomer(Customer cus[], int CusSize, int &customerCount)
{
    system("cls");
    cout << endl
         << endl;

    setTextColor(14); // Yellow
    cout << "\t\t\t\t\t\t\t===================================" << endl;
    setTextColor(11); // Cyan
    cout << "\t\t\t\t\t\t\t     --- Customers Details ---     " << endl;
    setTextColor(14); // Yellow
    cout << "\t\t\t\t\t\t\t===================================" << endl
         << endl;

    cout << left;
    cout << " ----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(16) << " | Username " << setw(16) << "| Password" << setw(20) << "| Customer Name"
         << setw(16) << "| Phone No" << setw(15) << "| DOB" << setw(10) << "| Gender"
         << setw(55) << "| Address" << "|" << endl;
    cout << " ----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    bool customerFound = false; // To track if any customer is found
    for (int i = 0; i < CusSize; i++)
    {
        if (cus[i].isExist) // Check if the customer exists
        {
            customerFound = true;
            cout << " | " << setw(13) << cus[i].username << "| "
                 << setw(14) << cus[i].pwd << "| "
                 << setw(18) << cus[i].name << "| "
                 << setw(14) << cus[i].cellNo << "| "
                 << setw(13) << cus[i].dob << "| "
                 << setw(8) << cus[i].gender << "| "
                 << setw(53) << cus[i].address << "| "
                 << endl;
        }
    }
    cout << " ----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    if (!customerFound)
    {
        setTextColor(12); // Red
        cout << "\n\tNo Customer Found!" << endl;
    }

    cin.ignore(); // Clear buffer for input pause
    // cin.get();
}

//<-----------------------------------Place an order---------------------------------->
int findCustomerIndex(string username, string pwd, Customer cus[], int CusSize)
{
    int customerIndex = 0;
    for (int i = 0; i < CusSize; i++)
    {
        if (username == cus[i].username && pwd == cus[i].pwd)
        {
            customerIndex = i;
        }
    }
    return customerIndex;
}

void placeOrder(Mobile mob[], int MaxMobile, int &mobileCount, string username, string pwd, Customer cus[], int CusSize, CustomerOrder cust[])
{

    viewMobiles(mob, MaxMobile, mobileCount, 0);
    /*Here used i for customer order fields, k used for mobile details*/
    int itemId = 0, qty = 0; // these are temp variables
    bool isItemFound = false;
    int cusIndex = 0; // stores currenly logened customer index
    bool alreadyPlaced = false;
    cusIndex = findCustomerIndex(username, pwd, cus, CusSize);
    cout << endl;
    setTextColor(14);
    cout << "\t ===================================" << endl;
    setTextColor(11);
    cout << "\t        --- Place an order ---      " << endl;
    setTextColor(14);
    cout << "\t ===================================" << endl;
    if (mobileCount == 0)
    {
        setTextColor(12); // Red
        cout << "\n\tNo Mobile added Yet!" << endl;
        return;
    }

    if (cust[cusIndex].orderCount >= MaxOrder)
    {
        setTextColor(12); // Red
        cout << "\nError: You have reached the maximum order limit!\n";
        return;
    }
    for (int i = 0; i < MaxOrder; i++)
    {
        if (!cust[cusIndex].orders[i].isExist)
        { // where to store item id for order (at i index) related to order
            cout << "\tEnter item id of product you wanna buy : ";
            itemId = validIntInput("Item Id", 0, 1000);
            cout << "\tEnter the quantity : ";
            qty = validIntInput("Quantity", 1, 500);
            //check if already placed same order
            for (int z = 0; z < MaxOrder; z++){
                if (cust[cusIndex].orders[z].isExist){
                    if(cust[cusIndex].orders[z].itemId = itemId){
                        alreadyPlaced = true;
                        setTextColor(12); // Red
                        cout<<"You cannot place an order for the same product more than once!";
                        cin.get();
                        break;
                    } 
                }
            }
            if(alreadyPlaced){
                break; //break this loop
            }

            for (int k = 0; k < MaxMobile; k++)
            { /*search mobile for qty check all mobile details exist at k related to mobiles*/
                if (mob[k].itemId == itemId)
                {
                    isItemFound = true;
                    if (qty <= mob[k].qty)
                    {
                        // successfull order
                        cust[cusIndex].orders[i].itemId = itemId;
                        cust[cusIndex].orders[i].qty = qty;
                        cust[cusIndex].orderCount++; /*counts orders of this particuler customer*/
                        cust[cusIndex].orders[i].isExist = true;
                        setTextColor(10); // green
                        cout << "\n\tMobile model : " << mob[k].model << endl;
                        cout << "\tPrice        : " << mob[k].salePrice << endl;
                        cout << "\tQuantity     : " << qty << endl;
                        cout << "\tTotal Price  : " << mob[k].salePrice * qty << endl;
                        cout << "\tOrder placed successfully." << endl;
                        cin.get();
                        break;
                    }
                    else
                    {
                        setTextColor(12); // Red
                        if (mob[k].qty != 0)
                        {
                            cout << "\n Only " << mob[k].qty << " items are available. Please select a lower quantity!";
                        }
                        else
                        {
                            cout << mob[k].model << " is OUT OF Stock!";
                        }
                        cin.ignore();
                        break;
                    }
                }
            }
            if (!isItemFound)
            {
                setTextColor(12); // Red
                cout << "\n No Mobile Found, incorrect item id!";
                cin.get();
            }
            break;
        }
    }

    saveOrders(cus, CusSize, cust);

    cin.get();
}
// order tracking
void orderTracking(Mobile mob[], int MaxMobile, int &mobileCount, string username, string pwd, Customer cus[], int CusSize, CustomerOrder cust[])
{
    system("cls");
    // k used for mobile details
    //  i used for order fields of particuler customer
    int cusIndex = 0; // stores currenly logened customer index
    cusIndex = findCustomerIndex(username, pwd, cus, CusSize);
    int grandTotal = 0;
    cout << endl
         << endl;
    setTextColor(14);
    cout << "\t\t\t\t\t\t\t===================================" << endl;
    setTextColor(11);
    cout << "\t\t\t\t\t\t\t       --- Order Tracking ---      " << endl;
    setTextColor(14);
    cout << "\t\t\t\t\t\t\t===================================" << endl
         << endl;
    cout << left;
    cout << "\t\t ------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t" << setw(7) << " | No. " << setw(11) << " | Brand " << setw(19) << "| Model" << setw(17) << "| Storage" << setw(10) << "| Color" << setw(13) << "| Price" << setw(7) << "| Qty " << setw(15) << "| Total Price " << setw(15) << "| Status" << "|" << endl;
    cout << "\t\t ------------------------------------------------------------------------------------------------------------------" << endl;
    if (cust[cusIndex].orderCount != 0)
    { // is there any order placed by customer
        int counter = 1;
        for (int i = 0; i < MaxOrder; i++)
        { /*for order findind at which index order exist means field*/
            if (cust[cusIndex].orders[i].isExist)
            {
                for (int k = 0; k < MaxMobile; k++)
                { // extrcting the data of mobile by itemId stores at field i
                    if (cust[cusIndex].orders[i].itemId == mob[k].itemId)
                    { // if itemId stored in order 2d array matches with itemId of mobile
                        cout << "\t\t";
                        cout << " | " << setw(4) << counter << "| "
                             << setw(9) << mob[k].brand << "| "
                             << setw(17) << mob[k].model << "| "
                             << setw(15) << mob[k].storage << "| "
                             << setw(8) << mob[k].color << "| "
                             << setw(11) << mob[k].salePrice << "| "
                             << setw(5) << cust[cusIndex].orders[i].qty << "| "
                             << setw(13) << cust[cusIndex].orders[i].qty * mob[k].salePrice << "| " << setw(13) << cust[cusIndex].orders[i].status << "|" << endl;
                        grandTotal += cust[cusIndex].orders[i].qty * mob[k].salePrice;
                        counter++;
                        break;
                    }
                }
            }
        }
        cout << "\t\t ------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t   Grand Total :      " << grandTotal << " rupees" << endl;
        cout << "\t\t ------------------------------------------------------------------------------------------------------------------" << endl;
    }
    else
    {
        setTextColor(12); // Red
        cout << "\n\t\tNo order placed Yet!" << endl;
    }
    cin.get();
}

//<------------------------------------interfaces functions---------------------------------->
void mainInterface()
{
    system("cls");    // clears the screen
    setTextColor(11); // for color changing to aqua
    cout << endl;
    // show the header and menu options
    cout << "  __  __       _     _ _        ____  _                   __  __                                                   _      ____            _                   " << endl;
    cout << " |  \\/  | ___ | |__ (_) | ___  / ___|| |__   ___  _ __   |  \\/  | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_   / ___| _   _ ___| |_ ___ _ __ ___    " << endl;
    cout << " | |\\/| |/ _ \\| '_ \\| | |/ _ \\ \\___ \\| '_ \\ / _ \\| '_ \\  | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\   " << endl;
    cout << " | |  | | (_) | |_) | | |  __/  ___) | | | | (_) | |_) | | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_    ___) | |_| \\__ \\ ||  __/ | | | | |  " << endl;
    cout << " |_|  |_|\\___/|_.__/|_|_|\\___| |____/|_| |_|\\___/| .__/  |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__|  |____/ \\__, |___/\\__\\___|_| |_| |_|  " << endl;
    cout << "                                                 |_|                               |___/                                        |___/                         " << endl;
    cout << "\n *************************************************************************************************************************************************************" << endl;
    cout << endl
         << endl;
    setTextColor(10); // light green
    cout << "\t\t\t\t\t\t\t\tChoose the desired option" << endl
         << endl;
    cout << "\t\t\t\t\t\t\t\t1. Manager Login" << endl;
    cout << "\t\t\t\t\t\t\t\t2. Employee Login" << endl;
    cout << "\t\t\t\t\t\t\t\t3. Customer Portal" << endl;
    cout << "\t\t\t\t\t\t\t\t0. Exit" << endl;
    cout << "\t\t\t\t\t\t\t\t*****************************" << endl;
}

//<-------------------------------MAnager interfaces functions---------------------------------->
void managerLoginHeader()
{
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "        --- Manager Login ---       " << endl;
    setTextColor(14);
    cout << " ===================================" << endl;
}

void managerMainMenu()
{
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "        --- Manager Portal ---      " << endl;
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(14);
    cout << " 1. ";
    setTextColor(11);
    cout << "Inventory Management" << endl;

    setTextColor(14);
    cout << " 2. ";
    setTextColor(11);
    cout << "Employee Management" << endl;

    setTextColor(14);
    cout << " 3. ";
    setTextColor(11);
    cout << "Customer Management" << endl;

    setTextColor(14);
    cout << " 4. ";
    setTextColor(11);
    cout << "Order Management" << endl;

    setTextColor(14);
    cout << " 5. ";
    setTextColor(11);
    cout << "Low Stock Alert" << endl;

    setTextColor(14);
    cout << " 6. ";
    setTextColor(11);
    cout << "Profit Report" << endl;

    setTextColor(14);
    cout << " 0. ";
    setTextColor(11);
    cout << "Logout" << endl;

    setTextColor(14); // Light Yellow for border
    cout << " ===================================" << endl;
}

// Manager Inventory Management Interface
void inventryManagementHeader()
{
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "     --- Inventory Management ---   " << endl;
    setTextColor(14);
    cout << " ===================================" << endl;
}
void managerInventryManagement()
{
    inventryManagementHeader();
    setTextColor(14);
    cout << " 1. ";
    setTextColor(11);
    cout << "Add Products" << endl;
    setTextColor(14);
    cout << " 2. ";
    setTextColor(11);
    cout << "Update Products" << endl;
    setTextColor(14);
    cout << " 3. ";
    setTextColor(11);
    cout << "Delete Products" << endl;
    setTextColor(14);
    cout << " 4. ";
    setTextColor(11);
    cout << "View All Products" << endl;
    setTextColor(14);
    cout << " 0. ";
    setTextColor(11);
    cout << "Exit" << endl;

    setTextColor(14);
    cout << " ===================================" << endl;
}

// Manager Employee Management Interface

void employeeManagementHeader()
{
    system("cls");
    setTextColor(14);
    cout << " ====================================" << endl;
    setTextColor(11);
    cout << "     --- Employee Management ---     " << endl;
    setTextColor(14);
    cout << " ====================================" << endl;
}
void managerEmployeeManagement()
{
    employeeManagementHeader();
    setTextColor(14);
    cout << " 1. ";
    setTextColor(11);
    cout << "Add Employee" << endl;
    setTextColor(14);
    cout << " 2. ";
    setTextColor(11);
    cout << "Update Employee Data" << endl;
    setTextColor(14);
    cout << " 3. ";
    setTextColor(11);
    cout << "Delete Employee" << endl;
    setTextColor(14);
    cout << " 4. ";
    setTextColor(11);
    cout << "View All Employees" << endl;
    setTextColor(14);
    cout << " 0. ";
    setTextColor(11);
    cout << "Exit" << endl;

    setTextColor(14);
    cout << " ====================================" << endl;
}

// Manager Customer Management Interface
void customerManagementHeader()
{
    system("cls");
    setTextColor(14);
    cout << " ====================================" << endl;
    setTextColor(11);
    cout << "     --- Customer Management ---     " << endl;
    setTextColor(14);
    cout << " ====================================" << endl;
}
void managerCustomerManagement()
{
    customerManagementHeader();
    setTextColor(14);
    cout << " 1. ";
    setTextColor(11);
    cout << "View All Customers" << endl;
    setTextColor(14);
    cout << " 2. ";
    setTextColor(11);
    cout << "Add customer" << endl;
    setTextColor(14);
    cout << " 3. ";
    setTextColor(11);
    cout << "Update customer data" << endl;
    setTextColor(14);
    cout << " 4. ";
    setTextColor(11);
    cout << "Delete Customer Account" << endl;
    setTextColor(14);
    cout << " 0. ";
    setTextColor(11);
    cout << "Exit" << endl;

    setTextColor(14);
    cout << " ====================================" << endl;
}
//<-------------------------------Employee interfaces functions---------------------------------->
// Employee Login Header
void employeeLoginHeader()
{
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "       --- Employee Login ---       " << endl;
    setTextColor(14);
    cout << " ===================================" << endl;
}

// Employee Main Menu
void employeeMainMenu()
{
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "       --- Employee Portal ---      " << endl;
    setTextColor(14);
    cout << " ===================================" << endl;

    setTextColor(14);
    cout << " 1. ";
    setTextColor(11);
    cout << "Inventory Management" << endl;
    setTextColor(14);
    cout << " 2. ";
    setTextColor(11);
    cout << "Customer Management" << endl;
    setTextColor(14);
    cout << " 3. ";
    setTextColor(11);
    cout << "Order Management" << endl;
    setTextColor(14);
    cout << " 4. ";
    setTextColor(11);
    cout << "Low Stock Alert" << endl;
    setTextColor(14);
    cout << " 0. ";
    setTextColor(11);
    cout << "Logout" << endl;

    setTextColor(14);
    cout << " ===================================" << endl;
}
void employeeInventryManagement()
{
    inventryManagementHeader();
    setTextColor(14);
    cout << " 1. ";
    setTextColor(11);
    cout << "Add Products" << endl;
    setTextColor(14);
    cout << " 2. ";
    setTextColor(11);
    cout << "Update Products" << endl;
    setTextColor(14);
    cout << " 3. ";
    setTextColor(11);
    cout << "View All Products" << endl;
    setTextColor(14);
    cout << " 0. ";
    setTextColor(11);
    cout << "Exit" << endl;

    setTextColor(14);
    cout << " ===================================" << endl;
}

void employeeCustomerManagement()
{
    customerManagementHeader();
    setTextColor(14);
    cout << " 1. ";
    setTextColor(11);
    cout << "View All Customers" << endl;
    setTextColor(14);
    cout << " 2. ";
    setTextColor(11);
    cout << "Update Customer data" << endl;
    setTextColor(14);
    cout << " 0. ";
    setTextColor(11);
    cout << "Exit" << endl;

    setTextColor(14);
    cout << " ====================================" << endl;
}

//<-------------------------------Customer interfaces functions---------------------------------->
void customerLoginHeader()
{
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "        --- Customer Login ---       " << endl;
    setTextColor(14);
    cout << " ===================================" << endl;
}
// Customer Portal
void customerPortalHeader()
{
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "       --- Customer Portal ---      " << endl;
    setTextColor(14);
    cout << " ===================================" << endl;
}

void customerPortal()
{
    customerPortalHeader(); // shows customer portal header
    setTextColor(14);
    cout << " 1. ";
    setTextColor(11);
    cout << "Create Profile" << endl;

    setTextColor(14);
    cout << " 2. ";
    setTextColor(11);
    cout << "Login Profile" << endl;

    setTextColor(14);
    cout << " 3. ";
    setTextColor(11);
    cout << "Continue without creating profile" << endl;

    setTextColor(14);
    cout << " 0. ";
    setTextColor(11);
    cout << "Exit" << endl;

    setTextColor(14);
    cout << " ===================================" << endl;
}

void customerProfileMenu()
{
    customerPortalHeader(); // shows customer portal header

    setTextColor(14);
    cout << " 1. ";
    setTextColor(11);
    cout << "View Available Items" << endl;

    setTextColor(14);
    cout << " 2. ";
    setTextColor(11);
    cout << "Place an Order" << endl;

    setTextColor(14);
    cout << " 3. ";
    setTextColor(11);
    cout << "Order Tracking" << endl;

    setTextColor(14);
    cout << " 4. ";
    setTextColor(11);
    cout << "Update profile" << endl;

    setTextColor(14);
    cout << " 0. ";
    setTextColor(11);
    cout << "Exit" << endl;

    setTextColor(14);
    cout << " ===================================" << endl;
}

void customerWithoutLoginMenu()
{
    customerPortalHeader(); // shows customer portal header

    setTextColor(14);
    cout << " 1. ";
    setTextColor(11);
    cout << "View Available Items" << endl;

    setTextColor(14);
    cout << " 2. ";
    setTextColor(11);
    cout << "Place an Order" << endl;

    setTextColor(14);
    cout << " 3. ";
    setTextColor(11);
    cout << "Order Tracking" << endl;

    setTextColor(14);
    cout << " 0. ";
    setTextColor(11);
    cout << "Exit" << endl;

    setTextColor(14);
    cout << " ===================================" << endl;
}
//<--------------------------------------------file handling------------------------------------>
//<----------------------------Employee data----------------------------------------->
void saveEmployeeData(Employee emp[], int EmpSize, int &empCount)
{
    ofstream fout;
    fout.open("employeeData.txt");
    // fout.open("employeeData.csv");
    if (!fout)
    {
        cout << "Error: Could not open employees.txt for reading!" << endl;
        return;
    }
    for (int i = 0; i < EmpSize; i++)
    {
        if (emp[i].isExist)
        { // Check if the employee exists
            fout << emp[i].username << "," << emp[i].pwd << "," << emp[i].name << ","
                 << emp[i].fatherName << "," << emp[i].cellNo << "," << emp[i].address << ","
                 << emp[i].cnic << "," << emp[i].dob << "," << emp[i].gender << endl;
        }
    }
    fout.close();
}

// laod employee data
void loadEmployeeData(Employee emp[], int EmpSize, int &empCount)
{
    ifstream fin("employeeData.txt");
    // ifstream fin("employeeData.csv");
    if (!fin)
    {
        cout << "Error: Could not open employeeData.txt for reading!" << endl;
        return;
    }

    int i = 0;
    while (i < EmpSize)
    {
        // Read all line by line
        if (!getline(fin, emp[i].username, ','))
            break;
        getline(fin, emp[i].pwd, ',');
        getline(fin, emp[i].name, ',');
        getline(fin, emp[i].fatherName, ',');
        getline(fin, emp[i].cellNo, ',');
        getline(fin, emp[i].address, ',');
        getline(fin, emp[i].cnic, ',');
        getline(fin, emp[i].dob, ',');
        fin >> emp[i].gender;
        fin.ignore();

        // Check if any field is empty or invalid
        if (emp[i].username.empty() || emp[i].pwd.empty() || emp[i].name.empty() ||
            emp[i].fatherName.empty() || emp[i].cellNo.empty() || emp[i].address.empty() ||
            emp[i].cnic.empty() || emp[i].dob.empty())
        {
            cout << "Warning: Incomplete or invalid data on line." << endl;
            continue; // Skip if invalid
        }
        empCount++; // Increment employee count
        emp[i].isExist = true;
        i++;
    }

    fin.close();

    if (empCount == 0)
    {
        cout << "Warning: The file is empty or contains no valid data." << endl;
    }
}

//<----------------------------customer data save & load---------------------------------->
void SaveCustomerData(Customer cus[], int CusSize, int &customerCount)
{
    ofstream fout;
    fout.open("customerData.txt");
    // fout.open("customerData.csv");
    if (!fout)
    {
        cout << "Error: Could not open customer.txt for reading!" << endl;
        return;
    }
    for (int i = 0; i < CusSize; i++)
    {
        if (cus[i].isExist)
        {
            fout << cus[i].username << ","
                 << cus[i].pwd << ","
                 << cus[i].name << ","
                 << cus[i].cellNo << ","
                 << cus[i].dob << ","
                 << cus[i].gender << ","
                 << cus[i].address << endl;
        }
    }
    fout.close();
}

void loadCustomerData(Customer cus[], int CusSize, int &customerCount)
{
    ifstream fin("customerData.txt");
    if (!fin)
    {
        cout << "Error: Could not open customerData.txt for reading!" << endl;
        return;
    }
    customerCount = 0;
    int i = 0;
    while (i < CusSize)
    {
        if (!getline(fin, cus[i].username, ','))
            break;
        if (!getline(fin, cus[i].pwd, ',') || !getline(fin, cus[i].name, ',') ||
            !getline(fin, cus[i].cellNo, ',') || !getline(fin, cus[i].dob, ',') ||
            !getline(fin, cus[i].gender, ',') || !getline(fin, cus[i].address))
        {
            cout << "Warning: Incomplete data for customer at record " << i + 1 << endl;
            // Clear incomplete data for current record
            cus[i].username.clear();
            cus[i].pwd.clear();
            cus[i].name.clear();
            cus[i].cellNo.clear();
            cus[i].dob.clear();
            cus[i].gender.clear();
            cus[i].address.clear();
            continue; // Skip to next record
        }
        // Validate non-empty data
        if (cus[i].username.empty() || cus[i].pwd.empty() || cus[i].name.empty() ||
            cus[i].cellNo.empty() || cus[i].dob.empty() || cus[i].gender.empty() || cus[i].address.empty())
        {
            cout << "Warning: Incomplete data for customer at record " << i + 1 << endl;
            continue;
        }
        cus[i].isExist = true; // Mark customer as existing
        customerCount++;
        i++; // Increment index only for valid records
    }
    fin.close();
    if (customerCount == 0)
    {
        cout << "Warning: The file is empty or contains no valid data." << endl;
    }
}

//<----------------------------inventry data save & load---------------------------------->
void saveInventryData(Mobile mob[], int MaxMobile, int &mobileCount)
{
    ofstream fout;
    fout.open("inventryData.txt");
    // fout.open("inventryData.csv");
    if (!fout)
    {
        cout << "Error: Could not open employees.txt for reading!" << endl;
        return;
    }

    for (int i = 0; i < MaxMobile; i++)
    {
        if (mob[i].isExist)
        { // Check if the mobile exists
            fout << mob[i].brand << ","
                 << mob[i].model << ","
                 << mob[i].storage << ","
                 << mob[i].specs << ","
                 << mob[i].color << ","
                 << mob[i].supplierName << ","
                 << mob[i].qty << ","
                 << mob[i].purchasePrice << ","
                 << mob[i].salePrice << ","
                 << mob[i].minStockLevel << ","
                 << mob[i].itemId << endl;
        }
    }
    fout.close();
}
void loadInventryData(Mobile mob[], int MaxMobile, int &mobileCount)
{
    ifstream fin("inventryData.txt"); // Use the correct file name
    // ifstream fin("inventryData.csv");  // Use the correct file name
    if (!fin)
    {
        cout << "Error: Could not open inventryData.txt for reading!" << endl;
        return;
    }

    int i = 0;
    while (i < MaxMobile)
    {
        if (!getline(fin, mob[i].brand, ',')) // Read brand
            break;
        getline(fin, mob[i].model, ',');        // Read model
        getline(fin, mob[i].storage, ',');      // Read storage
        getline(fin, mob[i].specs, ',');        // Read specs
        getline(fin, mob[i].color, ',');        // Read color
        getline(fin, mob[i].supplierName, ','); // Read supplier name
        fin >> mob[i].qty;                      // Read quantity
        fin.ignore();
        fin >> mob[i].purchasePrice; // Read purchase price
        fin.ignore();
        fin >> mob[i].salePrice; // Read sale price
        fin.ignore();
        fin >> mob[i].minStockLevel; // Read minimum stock level
        fin.ignore();
        fin >> mob[i].itemId; // Read item ID
        fin.ignore();

        // Check if required fields are empty
        if (mob[i].brand.empty() || mob[i].model.empty() || mob[i].storage.empty() ||
            mob[i].specs.empty() || mob[i].color.empty() || mob[i].supplierName.empty())
        {
            cout << "Warning: Incomplete data for mobile item at record " << i + 1 << endl;
            continue; // Skip to next record
        }

        mob[i].isExist = true; // Mark mobile as existing
        mobileCount++;
        i++;
    }

    fin.close();

    if (mobileCount == 0)
    {
        cout << "Warning: The file is empty or contains no valid data." << endl;
    }
}

//<----------------------------save pending order------------------------------->

void saveOrders(Customer cus[], int CusSize, CustomerOrder cust[])
{
    ofstream fout("orders.txt"); // Open the file for writing
    if (!fout)
    {
        cout << "Error: Could not open orders.txt for writing!" << endl;
        return;
    }

    for (int cusIndex = 0; cusIndex < CusSize; cusIndex++)
    {
        if (cus[cusIndex].isExist)
        {
            // Write Orders (Line 1)
            bool firstOrder = true;
            for (int order = 0; order < MaxOrder; order++)
            {
                if (cust[cusIndex].orders[order].isExist)
                {
                    if (!firstOrder)
                        fout << ","; // Add comma separator
                    fout << cust[cusIndex].orders[order].itemId;
                    firstOrder = false;
                }
            }
            fout << endl; // End of the orders line

            // Write Quantities (Line 2)
            firstOrder = true;
            for (int order = 0; order < MaxOrder; order++)
            {
                if (cust[cusIndex].orders[order].isExist)
                {
                    if (!firstOrder)
                        fout << ",";
                    fout << cust[cusIndex].orders[order].qty;
                    firstOrder = false;
                }
            }
            fout << endl; // End of the quantities line

            // Write Statuses (Line 3)
            firstOrder = true;
            for (int order = 0; order < MaxOrder; order++)
            {
                if (cust[cusIndex].orders[order].isExist)
                {
                    if (!firstOrder)
                        fout << ",";
                    fout << cust[cusIndex].orders[order].status;
                    firstOrder = false;
                }
            }
            fout << endl; // End of the statuses line
        }
    }

    fout.close(); // Close the file
}

void loadOrders(Customer cus[], int CusSize, CustomerOrder cust[])
{
    ifstream fin("orders.txt"); // Open the file for reading
    if (!fin)
    {
        cout << "Error: Could not open orders.txt for reading!" << endl;
        return;
    }

    string line;
    int rows = 0; // Track the number of customers read
    while (getline(fin, line) && rows < CusSize)
    {
        int cols = 0;

        // Line 1: Item IDs
        for (int k = 1;; k++)
        {
            string temp = tokenizer(line, k);
            if (temp.empty())
                break;
            cust[rows].orders[cols].itemId = stringToInt(temp); // Store in orders array
            cust[rows].orders[cols].isExist = true;
            cols++; // Increment column
            if (cols >= MaxOrder)
                break; // Ensure we don't exceed MaxCols
        }

        // Read the next line for quantities
        getline(fin, line);
        cols = 0;
        for (int k = 1;; k++)
        {
            string temp = tokenizer(line, k);
            if (temp.empty())
                break;
            cust[rows].orders[cols].qty = stringToInt(temp);
            cust[rows].orderCount++; // Increment order count
            cols++;                  // Increment column
            if (cols >= MaxOrder)
                break;
        }

        // Read the next line for statuses
        getline(fin, line);
        cols = 0;
        for (int k = 1;; k++)
        {
            string temp = tokenizer(line, k);
            if (temp.empty())
                break;
            cust[rows].orders[cols].status = temp; // Store in orderStatus array
            cols++;                                // Increment column
            if (cols >= MaxOrder)
                break;
        }

        rows++; // Move to the next customer
    }

    fin.close(); // Close the file
}

//<----------------------------profit save report----------------------------------->
void saveProfitReport(int &total_Cost, int &total_Revenue, int &total_Profit, int &mobSold)
{
    ofstream fout;
    fout.open("profit.txt"); // Open the file for writing
    if (!fout)
    {
        cout << "Error: Could not open profit.txt for writing!" << endl;
        return;
    }
    fout << mobSold << endl;
    fout << total_Revenue << endl;
    fout << total_Cost << endl;
    fout << total_Profit << endl;

    fout.close();
}

// load profit report
void loadProfitReport(int &total_Cost, int &total_Revenue, int &total_Profit, int &mobSold)
{
    ifstream fin;
    fin.open("profit.txt");
    if (!fin)
    {
        cout << "Error: Could not open profit.txt for reading!" << endl;
    }
    fin >> mobSold;
    fin >> total_Revenue;
    fin >> total_Cost;
    fin >> total_Profit;

    fin.close();
}
