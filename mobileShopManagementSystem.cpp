#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <conio.h> //used to use _getch() in masked pass
#include <fstream>
using namespace std;
//<-------------constants of 2D array----------------------->
const int MaxOrder = 10; // 10 orders per person

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
bool EmployeeloginChecker(string empUsername[], string empPwd[],int EmpSize);
// other functionalities
//<---------------employee and customer validations----------------------->
void invalidErrorMessage();   // invalid option error
int getValidDigitInput();     // make sure input is 0 - 9 single digit
string maskedInputPass();     // input masked password from user
void setTextColor(int color); // changes the color of specific text
string validDate();           // date validator
string validPhoneNo();
string validName(int minLen, int maxLen, string errorMsg);
string validAddress();
string validUsername();
string validPwd(); // check user enter valid pwd at time of creating account
//<---------------------mobile validations-------------------->
string validModelName();
string validStorage();
string validSpecs();
int validIntInput(const string& fieldName, int minValue, int maxValue);
//<-------------smart functions---------------------->
int stringToInt(string str);          // change string to int
string intToString(int number);
string tokenizer(string str, int field);                 // seperate by comma help in file handling
int convertToInt(const string &str, int start, int end); // for date manuplation used
int LengthOf(const string &str);
string toLowerCase(string str);
string validGender();
//<------------------employee management-------------------------->
// add employee
void addEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], string empGender[], bool isEmpExist[], int EmpSize, int &empCount);
// update employee
void updateEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], string empGender[], bool isEmpExist[], int EmpSize, int &empCount); // Uemp :
// view all employees
void viewEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], string empGender[], bool isEmpExist[], int EmpSize, int &empCount);
// delete employee
void deleteEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], string empGender[], bool isEmpExist[], int EmpSize, int &empCount);
//<------------------------profit report----------------------------------->
void profitReport(int &tCost, int &tRevenue, int &tProfit, int &mobSold);
//<----------------------inventry management------------------->
// add mobiles
void addMobiles(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount);
void updateMobiles(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount);
void deleteMobiles(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount);
void viewMobiles(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, bool isAdmin); // here bool isAdmin determine wether to show full detailed list or ristricted (1 for admin, 0 for others)
void lowStock(string mobileBrand[], string mobileModel[], string mobileSupplierName[], int mobileQty[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, int mobMinStockLevel[]);
//<-----------------------customer order management---------------------------------------->
void cusOrderManagment(string mobileBrand[], string mobileModel[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, int orderQty[][MaxOrder], int orders[][MaxOrder], int orderPrices[][MaxOrder], int orderCounts[], bool isOrderExist[][MaxOrder], string orderStatus[][MaxOrder], int MaxOrder, int CusSize, bool isCustomerExit[], string cusUsername[], string cusName[]);
void managePendingOrders(string mobileBrand[], string mobileModel[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, int mobProfit[], int orderQty[][MaxOrder], int orders[][MaxOrder], int orderPrices[][MaxOrder], int orderCounts[], bool isOrderExist[][MaxOrder], string orderStatus[][MaxOrder], int MaxOrder, int CusSize, bool isCustomerExit[], string cusUsername[], string cusName[], bool isProfitExist[], int totalRevenue[], int totalCost[], int &tCost, int &tRevenue, int &tProfit, int &mobSold);
//<------------------Customer profiles-------------------------->
void addCustomer(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount);
void viewAllCustomer(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount);
void deleteCustomer(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount);
void updateCustomer(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount);

//<-------------------------place an order--------------------------->
// find user index to specfic logined customer
int findCustomerIndex(string username, string pwd, string cusUsername[], string cusPwd[], int CusSize);
void placeOrder(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, bool isAdmin, int orderQty[][MaxOrder], int orders[][MaxOrder], int orderPrices[][MaxOrder], int orderCounts[], bool isOrderExist[][MaxOrder], string orderStatus[][MaxOrder], int MaxOrder, int CusSize, string username, string pwd, string cusUsername[], string cusPwd[], string cusName[], bool isCustomerExit[], string typeofSave, string fileName);
void orderTracking(string mobileBrand[], string mobileModel[], string mobileColor[], string mobileStorage[], int mobSalePrice[], double discount[], bool isMobileExist[], int MaxMobile, int mobItemId[], int orderQty[][MaxOrder], int orders[][MaxOrder], int orderPrices[][MaxOrder], int orderCounts[], bool isOrderExist[][MaxOrder], string orderStatus[][MaxOrder], int MaxOrder, int CusSize, string username, string pwd, string cusUsername[], string cusPwd[]);
//<------------------------file handling--------------------------------->
//<----------------------Employee data save & laod-------------------------------->
void saveEmployeeData(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], string empGender[], bool isEmpExist[], int EmpSize, int &empCount);
void loadEmployeeData(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], string empGender[], bool isEmpExist[], int EmpSize, int &empCount);
//<-------------------------------customer data save & load--------------------------------->
void SaveCustomerData(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount);
void loadCustomerData(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount);
//<-------------------------------inventry data save & load--------------------------------->
void saveInventryData(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount);
void loadInventryData(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount);
//<----------------------------profit save data---------------------------------->
void saveProfitReport(int &tCost, int &tRevenue, int &tProfit, int &mobSold);
void loadProfitReport(int &tCost, int &tRevenue, int &tProfit, int &mobSold);
//<-------------------------------order data save & load--------------------------------->
void saveOrders(bool isCustomerExit[], int orders[][10], int orderQty[][10], string orderStatus[][10], bool isOrderExist[][10], int MaxOrder, int CusSize, string typeofSave, string fileName);
void loadOrders(bool isCustomerExit[], int orders[][10], int orderQty[][10], string orderStatus[][10], bool isOrderExist[][10], int MaxOrder, int CusSize, int orderCounts[], string typeofSave, string fileName);

int main()
{
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
    int employeeChoice = -1;
    string notification;
    const int EmpSize = 10; // max no. of employes size
    int empCount = 0;       // counts no of employee added
    string empUsername[EmpSize];
    string empPwd[EmpSize];
    bool isUserFound = false;   // used in searching
    bool isEmpExist[EmpSize];   // check the variable is there exist any employee
    string empName[EmpSize];    // employee full name
    string empFname[EmpSize];   // emp father name
    string empCellNo[EmpSize];  // emp cell number
    string empAddress[EmpSize]; // emp address
    string empCnic[EmpSize];    // emp cnic number
    string empDOB[EmpSize];     // emp date of birth
    string empGender[EmpSize];  // emp gender
    // initilize arrays
    for (int i = 0; i < EmpSize; i++)
    {
        empName[i] = "nv";
        empFname[i] = "nv";
        empCellNo[i] = "nv";
        empAddress[i] = "nv";
        empCnic[i] = "nv";
        empDOB[i] = "nv";
        empGender[i] = "nv";
        isEmpExist[i] = false;
        empUsername[i] = "nv";
        empPwd[i] = "nv";
    }
    //<-------------------customer attributes---------------------->
    const int CusSize = 100; // max no. of customers size
    int customerChoice = -1;
    int customerCount = 0; // counts no of customer added
    string cusUsername[CusSize];
    string cusPwd[CusSize];
    bool isCustomerExit[CusSize]; // cheacks is customer have account or not
    string cusName[CusSize];      // customer full name
    string cusCell[CusSize];      // customer cell number
    string cusAddress[CusSize];   // customer address
    string cusDOB[CusSize];       // customer birthday
    string cusGender[CusSize];    // customer gender
    // initilize arrays
    for (int i = 0; i < CusSize; i++)
    {
        cusUsername[i] = "nv";
        cusPwd[i] = "nv";
        cusName[i] = "nv";
        cusCell[i] = "nv";
        cusAddress[i] = "nv";
        cusDOB[i] = "nv";
        cusGender[i] = "nv";
        isCustomerExit[i] = false;
    }
    //<------------------inventry attributes------------------>
    int inventryChoice = -1;
    int mobileCount = 0;
    // mobiles
    int tCost = 0;
    int tRevenue = 0;
    int tProfit = 0;
    int mobSold = 0;
    const int MaxMobile = 30; // max no. of items
    int totalRevenue[MaxMobile];
    int totalCost[MaxMobile];
    int mobProfit[MaxMobile];
    bool isProfitExist[MaxMobile];
    int mobItemId[MaxMobile];
    string mobileBrand[MaxMobile];
    string mobileModel[MaxMobile];
    string mobileSpecs[MaxMobile];
    string mobileSupplierName[MaxMobile];
    string mobileColor[MaxMobile];
    int mobileQty[MaxMobile];
    string mobileStorage[MaxMobile];
    int mobPurchasePrice[MaxMobile];
    int mobSalePrice[MaxMobile];
    int mobMinStockLevel[MaxMobile];
    double discount[MaxMobile];
    string status[MaxMobile];      // use to update status if mobile is out of stock
    bool isMobileExist[MaxMobile]; // check the variable is there exist any mobile

    for (int i = 0; i < MaxMobile; i++)
    {
        totalRevenue[i] = 0;
        totalCost[i] = 0;
        mobProfit[i] = 0;
        mobItemId[i] = -1;
        mobileBrand[i] = "nv";
        mobileModel[i] = "nv";
        mobileSpecs[i] = "nv";
        mobileSupplierName[i] = "nv";
        mobileColor[i] = "nv";
        mobileQty[i] = 0;
        mobileStorage[i] = "nv";
        mobPurchasePrice[i] = 0;
        mobSalePrice[i] = 0;
        mobMinStockLevel[i] = 0;
        discount[i] = 0;
        status[i] = "nv";
        isMobileExist[i] = false;
        isProfitExist[i] = false;
    }
    // order management attributes
    string typeofSave = "";
    string fileName = "";
    bool foundPendingOrder = false;
    bool isOrderExist[CusSize][MaxOrder];
    int orders[CusSize][MaxOrder];         // sotres item ids
    int orderPrices[CusSize][MaxOrder];    // Prices of each order
    int orderQty[CusSize][MaxOrder];       // Quantities of each order
    string orderStatus[CusSize][MaxOrder]; // for order status e.g shipped , pending
    int orderCounts[CusSize] = {0};
    // initilize 1d array
    for (int i = 0; i < CusSize; i++)
    {
        orderCounts[i] = 0;
    }
    // initilize 2d array
    for (int i = 0; i < CusSize; i++)
    {
        for (int j = 0; j < MaxOrder; j++)
        {
            orders[i][j] = 0;
            orderPrices[i][j] = 0;
            orderQty[i][j] = 0;
            orderStatus[i][j] = "Pending";
            isOrderExist[i][j] = false;
        }
    }
    //<------------------Load data------------------------>
    loadEmployeeData(empUsername, empPwd, empName, empFname, empCellNo, empAddress, empCnic, empDOB, empGender, isEmpExist, EmpSize, empCount);
    loadCustomerData(cusUsername, cusPwd, cusName, cusCell, cusAddress, cusDOB, cusGender, isCustomerExit, CusSize, customerCount);
    loadInventryData(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount);
    saveOrders(isCustomerExit, orders, orderQty, orderStatus, isOrderExist, MaxOrder, CusSize, "status", "orderStatus.txt");
    saveOrders(isCustomerExit, orders, orderQty, orderStatus, isOrderExist, MaxOrder, CusSize, "qty", "orderStatus.txt");
    saveOrders(isCustomerExit, orders, orderQty, orderStatus, isOrderExist, MaxOrder, CusSize, "order", "orderStatus.txt");
    loadOrders(isCustomerExit, orders, orderQty, orderStatus, isOrderExist, MaxOrder, CusSize, orderCounts, "", "orderId.txt");
    loadProfitReport(tCost, tRevenue, tProfit, mobSold);
    do
    {
        mainInterface();
        choice = getValidDigitInput(); // assures valid input digit 0-9

        // Main menu options handling
        switch (choice)
        {
        case 1:
        {   //after getting correct premeter it checks whether credentials are correct or not
            if(ManagerLoginChecker(managerUsername,managerPWD)) 
                loggedInUserType = 1;
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
            //it checks credentials if correct return true and move next
            if(EmployeeloginChecker(empUsername,empPwd,EmpSize))
                loggedInUserType = 2;
            else{
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
                    addCustomer(cusUsername, cusPwd, cusName, cusCell, cusAddress, cusDOB, cusGender, isCustomerExit, CusSize, customerCount);
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
                        if (username == cusUsername[i] && pwd == cusPwd[i])
                        {
                            loggedInUserType = 3;
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
                            addMobiles(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount);
                            break;
                        }
                        case 2:
                        { // update inventry
                            updateMobiles(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount);

                            break;
                        }
                        case 3:
                        {
                            deleteMobiles(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount);
                            break;
                        }
                        case 4:
                        {
                            viewMobiles(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount, 1);
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
                            addEmployee(empUsername, empPwd, empName, empFname, empCellNo, empAddress, empCnic, empDOB, empGender, isEmpExist, EmpSize, empCount);

                            break;
                        }
                        case 2:
                        { // update employee
                            updateEmployee(empUsername, empPwd, empName, empFname, empCellNo, empAddress, empCnic, empDOB, empGender, isEmpExist, EmpSize, empCount);
                            break;
                        }
                        case 3:
                        { // delete employee
                            deleteEmployee(empUsername, empPwd, empName, empFname, empCellNo, empAddress, empCnic, empDOB, empGender, isEmpExist, EmpSize, empCount);
                            break;
                        }
                        case 4:
                        { // view all employees
                            viewEmployee(empUsername, empPwd, empName, empFname, empCellNo, empAddress, empCnic, empDOB, empGender, isEmpExist, EmpSize, empCount);
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
                            viewAllCustomer(cusUsername, cusPwd, cusName, cusCell, cusAddress, cusDOB, cusGender, isCustomerExit, CusSize, customerCount);
                            break;
                        }
                        case 2:
                        { // add customer
                            addCustomer(cusUsername, cusPwd, cusName, cusCell, cusAddress, cusDOB, cusGender, isCustomerExit, CusSize, customerCount);
                            break;
                        }
                        case 3:
                        { // update customer data
                            updateCustomer(cusUsername, cusPwd, cusName, cusCell, cusAddress, cusDOB, cusGender, isCustomerExit, CusSize, customerCount);
                            break;
                        }
                        case 4:
                        { // delete customer
                            deleteCustomer(cusUsername, cusPwd, cusName, cusCell, cusAddress, cusDOB, cusGender, isCustomerExit, CusSize, customerCount);
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
                    managePendingOrders(mobileBrand, mobileModel, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount, mobProfit, orderQty, orders, orderPrices, orderCounts, isOrderExist, orderStatus, MaxOrder, CusSize, isCustomerExit, cusUsername, cusName, isProfitExist, totalRevenue, totalCost, tCost, tRevenue, tProfit, mobSold);
                    break;
                }
                case 5:
                { // low stock alert
                    lowStock(mobileBrand, mobileModel, mobileSupplierName, mobileQty, isMobileExist, MaxMobile, mobItemId, mobileCount, mobMinStockLevel);
                    break;
                }
                case 6:
                { // profit report
                    profitReport(tCost, tRevenue, tProfit, mobSold);
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
                            addMobiles(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount);
                            break;
                        }
                        case 2:
                        { // update items
                            updateMobiles(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount);
                            break;
                        }
                        case 3:
                        { // view all items
                            viewMobiles(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount, 0);
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
                            viewAllCustomer(cusUsername, cusPwd, cusName, cusCell, cusAddress, cusDOB, cusGender, isCustomerExit, CusSize, customerCount);
                            break;
                        }
                        case 2:
                        {
                            updateCustomer(cusUsername, cusPwd, cusName, cusCell, cusAddress, cusDOB, cusGender, isCustomerExit, CusSize, customerCount);
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
                    managePendingOrders(mobileBrand, mobileModel, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount, mobProfit, orderQty, orders, orderPrices, orderCounts, isOrderExist, orderStatus, MaxOrder, CusSize, isCustomerExit, cusUsername, cusName, isProfitExist, totalRevenue, totalCost, tCost, tRevenue, tProfit, mobSold);
                    break;
                }
                case 4:
                { // low stock alert
                    lowStock(mobileBrand, mobileModel, mobileSupplierName, mobileQty, isMobileExist, MaxMobile, mobItemId, mobileCount, mobMinStockLevel);
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
                    viewMobiles(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount, 0);
                    break;
                }
                case 2:
                { // place an order
                    placeOrder(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount, 0, orderQty, orders, orderPrices, orderCounts, isOrderExist, orderStatus, MaxOrder, CusSize, username, pwd, cusUsername, cusPwd, cusName, isCustomerExit, typeofSave, fileName);
                    break;
                }
                case 3:
                { // update profile
                    orderTracking(mobileBrand, mobileModel, mobileColor, mobileStorage, mobSalePrice, discount, isMobileExist, MaxMobile, mobItemId, orderQty, orders, orderPrices, orderCounts, isOrderExist, orderStatus, MaxOrder, CusSize, username, pwd, cusUsername, cusPwd);
                    break;
                }
                case 4:
                { // update profile
                    updateCustomer(cusUsername, cusPwd, cusName, cusCell, cusAddress, cusDOB, cusGender, isCustomerExit, CusSize, customerCount);
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
                    viewMobiles(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount, 0);
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
bool ManagerLoginChecker(string realUsername, string realPass){
    string username, pass;
    managerLoginHeader();
    for (int j = 2; j >= 0; j--) {
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
        if (username == realUsername && pass == realPass) {
            return true; // Successful login
        } else {
            setTextColor(12); // red
            cout <<" "<< j << " tries left" << endl;
        }
        
        // If no attempts are left, trigger cooldown
        if (j == 0) {
            for (int i = 9; i >= 1; i--) {
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
bool EmployeeloginChecker(string empUsername[], string empPwd[],int EmpSize){
    string username, pwd;
    employeeLoginHeader();
    for (int j = 2; j >= 0; j--) {
        setTextColor(14);
        cout << " Enter Username: ";
        setTextColor(11);
        cin >> username;
        setTextColor(14);
        cout << " Enter Password: ";
        setTextColor(11);
        pwd = maskedInputPass();
        // Check if both username and password match
        for (int i = 0; i < EmpSize; i++){
            if (username == empUsername[i] && pwd == empPwd[i])
            {
                return true; 
                break; //LOOP break and tells that employee is authorized
            }
        }
        //if this not happened then these statement will execute
        setTextColor(12);
        cout <<" "<< j << " tries left" << endl;
        // If no attempts are left, trigger cooldown
        if (j == 0) {
            for (int i = 9; i >= 1; i--) {
                employeeLoginHeader();
                setTextColor(12); //red
                cout << "\n Try again after seconds: 0" << i << endl;
                Sleep(1000);
                system("cls");
            }
            return false;
        }
    }
    return false; 
}
//<-------------------------------Functionalities functions & validations---------------------------------->
// this chacks whether input from 0 to 9
int getValidDigitInput() {
    int input = -1; 
    bool isValid = false; 
    do {
        setTextColor(14);
        cout << "\t\t\t\t\t\t\t\tSelect desired option: ";
        setTextColor(15);
        cin >> input;  

        // Check if the input is within the valid range (0-9)
        if (cin.fail()) {
            cin.clear();  
            cin.ignore(1000, '\n'); 
            setTextColor(12);
            cout<<"\t\t\t\t\t\t\t\tInvalid Choice!\n";
        }
        else {
            // Check if extra input in buffer
            char extra;
            if (cin.get(extra)) {
                // If found shows error msj
                if (extra != '\n') { 
                    cin.clear();
                    cin.ignore(1000, '\n');
                    setTextColor(12);
                    cout << "\t\t\t\t\t\t\t\tInvalid Choice!\n";
                    continue;
                }
            }
            isValid = true;  // Valid input
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
        monthDays[1] = 28;
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
// use to input masked password
string maskedInputPass()
{
    char input;
    string inputPass;
    // cout<<"Enter the password : "; //bcz there already have this line
    input = _getch();
    while (input != 13)
    {
        if (input == 8)
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
            cout << "*";                // print star to mask password
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

        getline(cin,cellNo);
        // Check if length is exactly 11
        bool lengthValid = true;
        int length = LengthOf(cellNo); // Use customLength function
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
        cin.getline(cnic,250);
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
    char name[300]; //large size for monkey tests
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
            cout << errorMsg<<endl;
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
        if (len < 4 || len > 100)
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

        cin.getline(username,600);

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
            cout << "Invalid username! Please try again.\n";
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
        getline(cin,gender);
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
        cin.getline(modelName, 600); //read with spaces

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

string validStorage() {
    char storage[600];   //large size so array hold large 
    int storageValue = 0;  //for int type manuplation to check right storage
    bool isValid = false;
    bool isTB = false; 

    while (!isValid) {
        
        cin.getline(storage, 600); 

        int length = LengthOf(storage);
        isValid = true; //valid until proved invalid

        // Check if gb or tb at last
        if (length >= 2 &&
            ((storage[length - 2] == 'G' || storage[length - 2] == 'g') &&
             (storage[length - 1] == 'B' || storage[length - 1] == 'b'))) {
            length -= 2;  // Ignore last 2 bcz to check int value that left 
        } else if (length >= 2 &&
                   ((storage[length - 2] == 'T' || storage[length - 2] == 't') &&
                    (storage[length - 1] == 'B' || storage[length - 1] == 'b'))) {
            length -= 2;  // Ignore the last 2 validate tb
            isTB = true;  
        } else {
            isValid = false; 
        }

        // Check if remaining input  numeric
        storageValue = 0;  // Reset storageValue before start..
        for (int i = 0; i < length; i++) {
            if (storage[i] < '0' || storage[i] > '9') { 
                isValid = false;
                break;
            }
            storageValue = storageValue * 10 + (storage[i] - '0');  // Convert char to int
        }

        // Convert TB to GB to check valid range
        if (isTB) {
            storageValue *= 1024; //now in GB is
        }

        // Check valid range (1 GB to 2048 gb)
        if (isValid && (storageValue < 1 || storageValue > 2048)) {
            isValid = false;
        }

        // If the input is valid then return
        if (isValid) {
            string result = intToString(storageValue);
            if (isTB) {
                result += " TB";
            } else {
                result += " GB";
            }
            return result; 
        } else {
            cout << "Invalid storage! Enter a valid storage capacity (1 GB to 2048 GB or 1 TB): ";
            storageValue = 0;  // Reset for next iteration
            isTB = false;      
        }
    }
    return "";  // This should never be reached
}

string validSpecs() {
    string specs;
    while (true) {
        
        getline(cin, specs);  

        bool isValid = true;
        int len = LengthOf(specs);

        if (len < 4 || len > 200) {
            isValid = false;
        }

        // Check if contain only valid characters (. + - )
        for (int i = 0; i < len; i++) {
            if (!(isalnum(specs[i]) || specs[i] == ' '  || specs[i] == '-' || specs[i] == '.' || specs[i] == '+')) {
                isValid = false;
                break;
            }
        }

        // Check if snot empty or last char not space
        if (len == 0 || specs[0] == ' ' ||  specs[len - 1] == ' ') {
            isValid = false;
        }

        // If specs contain multiple consecutive spaces, mark as invalid
        for (int i = 0; i < len - 1; i++) {
            if (specs[i] == ' ' && specs[i + 1] == ' ') {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            return specs;
        } else {
            cout << "Invalid specs! Please enter valid mobile specifications:";
        }
    }
}

int validIntInput(const string& fieldName, int minValue, int maxValue) {
    int num;
    while (true) {

        cin >> num;
        // Check if the input is a valid integer
        if (cin.fail()) {
            cin.clear();  
            cin.ignore(1000, '\n'); 
            cout << "Error! Please enter a valid integer for " << fieldName << ": ";
        }
        else if (num >= minValue && num <= maxValue) {
            return num;  
        }
        else {
            // If the number is out of range, ask the user to enter again
            cout << "Invalid number! "<<fieldName<<" must be between " << minValue << " and " << maxValue << ". Please try again: ";
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
string intToString(int number) {
    string result = ""; 
    // Check if the number is zero
    if (number == 0) {
        result = "0";  
        return result;
    }

    bool isNegative = false;  
    if (number < 0) {
        isNegative = true;  
        number = -number;  
    }

    while (number > 0) {
        char digit = (number % 10) + '0';  // Get last digit & convert to char
        result = digit + result;
        number /= 10;  // Remove the last digit
    }

    if (isNegative) {
        result = "-" + result;
    }

    return result;  // Return the final string
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
void addEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], string empGender[], bool isEmpExist[], int EmpSize, int &empCount)
{
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
            if (!isEmpExist[i])
            {
                cout << "Enter Username : ";
                empUsername[i] = validUsername();
                cout << "Enter Password : ";
                cin.ignore();
                empPwd[i] = validPwd();
                cout << "Enter employee full name : ";
                cin.ignore();
                empName[i] = validName(3,21,"Invalid name! Please enter valid name :");
                cout << "Enter employee father's name : ";
                empFname[i] = validName(3,21,"Invalid name! Please enter valid name :");
                cout << "Enter employee 11-degit phone number : ";
                empCellNo[i] = validPhoneNo();
                cout << "Enter employee cnic in format XXXXX-YYYYYYYY-Y : ";
                empCnic[i] = validCNIC();
                cout << "Enter employee address : ";
                empAddress[i] = validAddress();
                cout << "Enter employee date of birth (DD-MM-YYYY): ";
                empDOB[i] = validDate();
                cout << "Enter gender (M for male or F for Female): ";
                empGender[i] = validGender();
                empCount++;
                isEmpExist[i] = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tEmployee added successfully......." << endl;
                cin.ignore();
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
    saveEmployeeData(empUsername, empPwd, empName, empFname, empCellNo, empAddress, empCnic, empDOB, empGender, isEmpExist, EmpSize, empCount);
}
// Uemp :
void updateEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], string empGender[], bool isEmpExist[], int EmpSize, int &empCount)
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
            if (username == empUsername[i])
            {
                cout << "Enter updated Username : ";
                cin.ignore();
                empUsername[i] = validUsername();
                cout << "Enter new Password : ";
                empPwd[i] = validPwd();
                cout << "Enter employee full name : ";
                empName[i] = validName(3,21,"Invalid name! Please enter valid name :");
                cout << "Enter employee father's name : ";
                empFname[i] = validName(3,21,"Invalid name! Please enter valid name :");
                cout << "Enter employee 11-degit phone number : ";
                empCellNo[i] = validPhoneNo();
                cout << "Enter employee cnic number : ";
                empCnic[i] = validCNIC();
                cout << "Enter employee address : ";
                empAddress[i] = validAddress();
                cout << "Enter employee date of birth (DD-MM-YYYY): ";
                empDOB[i] = validDate();
                cout << "Enter gender (M for male or F for Female): ";
                empGender[i] = validGender();
                isUserFound = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tEmployee data updated successfully......." << endl;
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
    saveEmployeeData(empUsername, empPwd, empName, empFname, empCellNo, empAddress, empCnic, empDOB, empGender, isEmpExist, EmpSize, empCount);
    cin.get();
}
void deleteEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], string empGender[], bool isEmpExist[], int EmpSize, int &empCount)
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
            if (username == empUsername[i])
            {
                empName[i] = "nv";
                empFname[i] = "nv";
                empCellNo[i] = "nv";
                empAddress[i] = "nv";
                empCnic[i] = "nv";
                empDOB[i] = "nv";
                empGender[i] = 'u';
                isEmpExist[i] = false;
                empUsername[i] = "nv";
                empPwd[i] = "nv";
                empCount--;
                isEmpExist[i] = false;
                isUserFound = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tEmployee data deleted successfully......." << endl;
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
        cout << "\nNo employee added yet!" << endl;
    }
    cin.get();
    saveEmployeeData(empUsername, empPwd, empName, empFname, empCellNo, empAddress, empCnic, empDOB, empGender, isEmpExist, EmpSize, empCount);
}

// view employees
void viewEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], string empGender[], bool isEmpExist[], int EmpSize, int &empCount)
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
            if (isEmpExist[i])
            {
                cout << " | " << setw(4) << counter << "| "
                     << setw(11) << empUsername[i] << "| "
                     << setw(11) << empPwd[i] << "| "
                     << setw(14) << empName[i] << "| "
                     << setw(14) << empFname[i] << "| "
                     << setw(13) << empCellNo[i] << "| "
                     << setw(17) << empCnic[i] << "| "
                     << setw(13) << empDOB[i] << "| "
                     << setw(7) << empGender[i] << "| "
                     << setw(42) << empAddress[i] << "| " << endl;
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
void addMobiles(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount)
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
            if (!isMobileExist[i])
            {
                cout << "Enter mobile Brand : ";
                cin.ignore();
                mobileBrand[i] = validName(2,15,"Invalid Brand name! Please enter valid Brand :");
                cout << "Enter model: ";
                mobileModel[i] = validModelName();
                cout << "Enter storage in (GB or TB): ";
                mobileStorage[i] = validStorage();
                cout << "Enter specs: ";
                mobileSpecs[i] = validSpecs();
                cout << "Enter mobile color: ";
                mobileColor[i] = validName(3,10,"Invalid Color name! Please enter valid color :");
                cout << "Enter supplier name: ";
                mobileSupplierName[i] = validName(3,21,"Invalid name! Please enter valid name :");
                cout << "Enter quantity: ";
                mobileQty[i] = validIntInput("Quantity", 1, 1000);
                cout << "Enter purchase Price: ";
                mobPurchasePrice[i]  = validIntInput("Purchase Price", 1, 1000000);
                cout << "Enter sale Price: ";
                mobSalePrice[i] = validIntInput("Sale Price", 1, 1000000);
                cout << "Enter minimum Stock Level: ";
                mobMinStockLevel[i] = validIntInput("Minimum Stock Level", 1, 500);
                mobileCount++;
                mobItemId[i] = i + 1;
                isMobileExist[i] = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tMobile added successfully......." << endl;
                saveInventryData(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount);
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
void updateMobiles(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount)
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
            if (mobileModel[i] == searchMob)
            {
                cout << "Enter mobile Brand : ";
                mobileBrand[i] = validName(2,15,"Invalid Brand name! Please enter valid Brand :");
                cout << "Enter model: ";
                mobileModel[i] = validModelName();
                cout << "Enter storage in (GB or TB): ";
                mobileStorage[i] = validStorage();
                cout << "Enter specs: ";
                mobileSpecs[i] = validSpecs();
                cout << "Enter mobile color: ";
                mobileColor[i] = validName(3,10,"Invalid Color name! Please enter valid name :");
                cout << "Enter supplier name: ";
                mobileSupplierName[i] = validName(3,21,"Invalid name! Please enter valid name :");
                cout << "Enter quantity: ";
                mobileQty[i] = validIntInput("Quantity", 1, 1000);
                cout << "Enter purchase Price: ";
                mobPurchasePrice[i]  = validIntInput("Purchase Price", 1, 1000000);
                cout << "Enter sale Price: ";
                mobSalePrice[i] = validIntInput("Sale Price", 1, 1000000);
                cout << "Enter minimum Stock Level: ";
                mobMinStockLevel[i] = validIntInput("Minimum Stock Level", 1, 500);
                Found = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tMobile updated successfully......." << endl;
                saveInventryData(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount);
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

void deleteMobiles(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount)
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
            if (mobileModel[i] == searchMob)
            {
                mobileBrand[i] = "nv";
                mobileModel[i] = "nv";
                mobileStorage[i] = "nv";
                mobileSpecs[i] = "nv";
                mobileColor[i] = "nv";
                mobileSupplierName[i] = "nv";
                mobileQty[i] = -1;
                mobPurchasePrice[i] = -1;
                mobSalePrice[i] = -1;
                mobMinStockLevel[i] = -1;
                mobileCount--;
                mobItemId[i] = -1;
                isMobileExist[i] = false;
                Found = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tMobile deleted successfully......." << endl;
                saveInventryData(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount);
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

void viewMobiles(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, bool isAdmin)
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
            if (isMobileExist[i])
            {
                (mobileQty[i] != 0) ? setTextColor(14) : setTextColor(12);
                cout << "\t";
                cout << " | " << setw(8) << mobItemId[i] << "| "
                     << setw(8) << mobileBrand[i] << "| "
                     << setw(17) << mobileModel[i] << "| "
                     << setw(15) << mobileStorage[i] << "| "
                     << setw(36) << mobileSpecs[i] << "| "
                     << setw(8) << mobileColor[i] << "| ";
                if (isAdmin)
                {
                    cout << setw(15) << mobileSupplierName[i] << "| "
                         << setw(8) << mobileQty[i] << "| "
                         << setw(15) << mobPurchasePrice[i] << "| "
                         << setw(11) << mobSalePrice[i] << "| "
                         << endl;
                }
                else
                {
                    cout << setw(13) << mobSalePrice[i] << "| " << endl;
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

void lowStock(string mobileBrand[], string mobileModel[], string mobileSupplierName[], int mobileQty[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, int mobMinStockLevel[])
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
        foundItems = true;
        for (int i = 0; i < MaxMobile; i++)
        {
            if (isMobileExist[i] && mobileQty[i] < mobMinStockLevel[i])
            {
                setTextColor(7);  
                cout << "\t\t\t";
                cout << " | " << setw(7) << mobItemId[i] << "| "
                     << setw(11) << mobileBrand[i] << "| "
                     << setw(18) << mobileModel[i] << "| "
                     << setw(16) << mobileSupplierName[i]<< "| ";
                
                setTextColor(12);  // Red for low quantity
                cout << setw(9) << mobileQty[i] << "| " << endl;
            }
        }
        setTextColor(11);
        cout << "\t\t\t ------------------------------------------------------------------------" << endl;
    }
    else
    {
        setTextColor(12); 
        cout << "\n\t\t\tNo mobile added yet!" << endl;
    }
    if (foundItems)
    {
        setTextColor(10); // Green 
        cout << "\n\t\t\tAll items are sufficiently stocked!" << endl;
    }
    cin.get();
}

//<----------------------------profit report------------------------------------->
void profitReport(int &tCost, int &tRevenue, int &tProfit, int &mobSold)
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
    if (tProfit != 0 && tRevenue != 0 && tCost != 0)
    {
        setTextColor(10); // Light Green=
        cout << setw(20) << "\t\t\t\t\t\tMobiles Sold" << ": " << setw(10) << mobSold << endl;
        cout << setw(20) << "\t\t\t\t\t\tTotal Revenue" << ": " << setw(10) << tRevenue << endl;
        cout << setw(20) << "\t\t\t\t\t\tTotal Cost" << ": " << setw(10) << tCost << endl;
        cout << setw(20) << "\t\t\t\t\t\tTotal Profit" << ": " << setw(10) << tProfit << endl;
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
void cusOrderManagment(string mobileBrand[], string mobileModel[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, int orderQty[][MaxOrder], int orders[][MaxOrder], int orderPrices[][MaxOrder], int orderCounts[], bool isOrderExist[][MaxOrder], string orderStatus[][MaxOrder], int MaxOrder, int CusSize, bool isCustomerExit[], string cusUsername[], string cusName[])
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
    for (int cus = 0; cus < CusSize; cus++)
    {
        if (isCustomerExit[cus])
        { // is customer exist
            for (int cusField = 0; cusField < MaxOrder; cusField++)
            {
                if (isOrderExist[cus][cusField])
                {
                    for (int k = 0; k < MaxMobile; k++) // this loop just to show mobile details by retrive item id
                    {                                   // extrcting the data of mobile by itemId stores at field i
                        if (orders[cus][cusField] == mobItemId[k])
                        {
                            cout << "\t";
                            cout << " | " << setw(17) << cusName[cus] << "| "
                                 << setw(14) << cusUsername[cus] << "| "
                                 << setw(8) << mobItemId[k] << "| "
                                 << setw(8) << mobileBrand[k] << "| "
                                 << setw(17) << mobileModel[k] << "| "
                                 << setw(15) << mobileStorage[k] << "| "
                                 << setw(8) << mobileColor[k] << "| "
                                 << setw(11) << mobSalePrice[k] << "| "
                                 << setw(5) << orderQty[cus][cusField] << "| "
                                 << setw(13) << orderQty[cus][cusField] * mobSalePrice[k] << "| "
                                 << setw(14) << orderStatus[cus][cusField] << "|" << endl;
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

void managePendingOrders(string mobileBrand[], string mobileModel[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, int mobProfit[], int orderQty[][MaxOrder], int orders[][MaxOrder], int orderPrices[][MaxOrder], int orderCounts[], bool isOrderExist[][MaxOrder], string orderStatus[][MaxOrder], int MaxOrder, int CusSize, bool isCustomerExit[], string cusUsername[], string cusName[], bool isProfitExist[], int totalRevenue[], int totalCost[], int &tCost, int &tRevenue, int &tProfit, int &mobSold)
{
    int choice;
    int stChoice;
    string username = "";
    int itemId = 0;
    bool isUserFound = false;
    bool isItemIdCorrect = false;
    string updateStatus = "";
    do
    {
        cusOrderManagment(mobileBrand, mobileModel, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount, orderQty, orders, orderPrices, orderCounts, isOrderExist, orderStatus, MaxOrder, CusSize, isCustomerExit, cusUsername, cusName);

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
            cout << "Enter username of customer :";
            username = validUsername();
            cout << "Enter item id : ";
            itemId = validIntInput("Item Id",0,1000);
            cout << "Select new status:" << endl;
            cout << "1. Shipped" << endl;
            cout << "2. Delivered" << endl;
            cout << "3. Out of Stock" << endl;
            do
            {
                stChoice = -1;
                stChoice = getValidDigitInput();
                switch (stChoice)
                {
                case 1:
                {
                    updateStatus = "Shipped";
                    break;
                }
                case 2:
                {
                    updateStatus = "Delivered";
                    break;
                }
                case 3:
                {
                    updateStatus = "Out of Stock";
                    break;
                }
                default:
                {
                    invalidErrorMessage(); // shows invalid error message
                }
                }
            } while (stChoice != 1 && stChoice != 2 && stChoice != 3);
            // updating status
            for (int cus = 0; cus < CusSize; cus++) // customer rows
            {
                if (username == cusUsername[cus])
                {                                                           // cusotmer exist but check wwether placed order or not
                    for (int cusField = 0; cusField < MaxOrder; cusField++) // cus fields
                    {
                        if (isOrderExist[cus][cusField])
                        {
                            if (orders[cus][cusField] == itemId)
                            {
                                isUserFound = true;
                                orderStatus[cus][cusField] = updateStatus;
                                // mobile qty decreaded by this
                                for (int k = 0; k < MaxMobile; k++)
                                {
                                    if (mobItemId[k] == itemId)
                                    { // means that particuler mbl details exist at k index
                                        if (stChoice == 1 || stChoice == 2)
                                        {
                                            mobileQty[k] -= orderQty[cus][cusField];
                                            mobProfit[k] = mobSalePrice[k] - mobPurchasePrice[k];
                                            isProfitExist[k] = true;
                                            // total profit
                                            tProfit += (mobSalePrice[k] - mobPurchasePrice[k]);
                                            tRevenue += mobSalePrice[k];
                                            tCost += mobPurchasePrice[k];
                                            mobSold += orderQty[cus][cusField];
                                            orderCounts[cus]--;
                                            isOrderExist[cus][cusField] = false;
                                            saveProfitReport(tCost, tRevenue, tProfit, mobSold);
                                        }
                                        isItemIdCorrect = true;
                                        setTextColor(10); // green
                                        saveOrders(isCustomerExit, orders, orderQty, orderStatus, isOrderExist, MaxOrder, CusSize, "", "orderId.txt");
                                        cout << "\n\t\t\tOrder status updated successfully......." << endl;
                                        cin.get();
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
            }
            if (!isUserFound)
            {
                setTextColor(12); // Red
                cout << "\tNot found any customer!\n";
                cin.get();
            }
            if (!isItemIdCorrect)
            {
                setTextColor(12); // Red
                cout << "Incorrect Item id !" << endl;
                cin.get();
            }
            break; // case 1 break)
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
    } while (choice != 0);
    choice = -1;
}

//----------------------------------------------Customer related functions------------------------------------------------>

void addCustomer(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount)
{
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
            if (!isCustomerExit[i])
            {
                cout << "Enter Username : ";
                cusUsername[i] = validUsername();
                cout << "Enter Password : ";
                cin.ignore(100, '\n');
                cusPwd[i] = validPwd();
                cout << "Enter your name :";
                cusName[i] = validName(3,21,"Invalid name! Please enter valid name :");
                cout << "Enter your phone number : ";
                cusCell[i] = validPhoneNo();
                cout << "Enter your date of birth : ";
                cusDOB[i] = validDate();
                cout << "Enter your gender : ";
                cusGender[i] = validGender();
                cout << "Enter your Address : ";
                cin.ignore(100, '\n');
                cusAddress[i] = validAddress();
                customerCount++;
                isCustomerExit[i] = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tProfile Created Successfully......." << endl;
                SaveCustomerData(cusUsername, cusPwd, cusName, cusCell, cusAddress, cusDOB, cusGender, isCustomerExit, CusSize, customerCount);
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

void updateCustomer(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount)
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
        cout << " Enter username of Customer : ";
        username = validUsername();
        for (int i = 0; i < CusSize; i++)
        {
            if (username == cusUsername[i])
            {
                cout << "Enter Username : ";
                cusUsername[i] = validUsername();
                cout << "Enter Password : ";
                cin.ignore();
                cusPwd[i] = validPwd();
                cout << "Enter your name :";
                cusName[i] = validName(3,21,"Invalid name! Please enter valid name :");
                cout << "Enter your phone number : ";
                cusCell[i] = validPhoneNo();
                cout << "Enter your date of birth : ";
                cusDOB[i] = validDate();
                cout << "Enter your gender : ";
                cusGender[i] = validGender();
                cout << "Enter your Address : ";
                cusAddress[i] = validAddress();
                isUserFound = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tCustomer data updated successfully......." << endl;
                SaveCustomerData(cusUsername, cusPwd, cusName, cusCell, cusAddress, cusDOB, cusGender, isCustomerExit, CusSize, customerCount);
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

void deleteCustomer(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount)
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
            if (username == cusUsername[i])
            {
                cusUsername[i] = "nv";
                cusPwd[i] = "nv";
                cusName[i] = "nv";
                cusCell[i] = "nv";
                cusAddress[i] = "nv";
                cusDOB[i] = "nv";
                cusGender[i] = "nv";
                isCustomerExit[i] = false;
                customerCount--;
                isCustomerExit[i] = false;
                isUserFound = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tCustomer data deleted successfully......." << endl;
                SaveCustomerData(cusUsername, cusPwd, cusName, cusCell, cusAddress, cusDOB, cusGender, isCustomerExit, CusSize, customerCount);
                cin.get();
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

void viewAllCustomer(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount)
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
        if (isCustomerExit[i])
        {
            customerFound = true;
            cout << " | " << setw(13) << cusUsername[i] << "| "
                 << setw(14) << cusPwd[i] << "| "
                 << setw(18) << cusName[i] << "| "
                 << setw(14) << cusCell[i] << "| "
                 << setw(13) << cusDOB[i] << "| "
                 << setw(8) << cusGender[i] << "| "
                 << setw(53) << cusAddress[i] << "| "
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
int findCustomerIndex(string username, string pwd, string cusUsername[], string cusPwd[], int CusSize)
{
    int customerIndex = 0;
    for (int i = 0; i < CusSize; i++)
    {
        if (username == cusUsername[i] && pwd == cusPwd[i])
        {
            customerIndex = i;
        }
    }
    return customerIndex;
}

void placeOrder(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, bool isAdmin, int orderQty[][MaxOrder], int orders[][MaxOrder], int orderPrices[][MaxOrder], int orderCounts[], bool isOrderExist[][MaxOrder], string orderStatus[][MaxOrder], int MaxOrder, int CusSize, string username, string pwd, string cusUsername[], string cusPwd[], string cusName[], bool isCustomerExit[], string typeofSave, string fileName)
{

    viewMobiles(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount, 0);
    /*Here used i for customer order fields, k used for mobile details*/
    int itemId = 0, qty = 0; // these are temp variables
    bool isItemFound = false;
    int cusIndex = 0; // stores currenly logened customer index
    cusIndex = findCustomerIndex(username, pwd, cusUsername, cusPwd, CusSize);
    cout << endl;
    setTextColor(14);
    cout << "\t ===================================" << endl;
    setTextColor(11);
    cout << "\t        --- Place an order ---      " << endl;
    setTextColor(14);
    cout << "\t ===================================" << endl;
    if (mobileCount != 0) // if mbl exist
    {
        if (orderCounts[cusIndex] < MaxOrder)
        { // make sure not reach max order limit
            for (int i = 0; i < MaxOrder; i++)
            {
                if (!isOrderExist[cusIndex][i])
                { // where to store item id for order (at i index) related to order
                    cout << "\tEnter item id of product you wanna buy : ";
                    itemId = validIntInput("Item Id",0,1000);
                    cout << "\tEnter the quantity : ";
                    qty = validIntInput("Quantity", 1, 500);
                    for (int k = 0; k < MaxMobile; k++)
                    { /*search mobile for qty check all mobile details exist at k related to mobiles*/
                        if (mobItemId[k] == itemId)
                        {
                            isItemFound = true;
                            if (qty <= mobileQty[k])
                            {
                                // successfull order
                                orders[cusIndex][i] = itemId;
                                orderQty[cusIndex][i] = qty;
                                orderCounts[cusIndex]++; /*counts orders of this particuler customer*/
                                isOrderExist[cusIndex][i] = true;
                                setTextColor(10); // green
                                cout << "\n\tMobile model : " << mobileModel[k] << endl;
                                cout << "\tPrice        : " << mobSalePrice[k] << endl;
                                cout << "\tQuantity     : " << qty << endl;
                                cout << "\tTotal Price  : " << mobSalePrice[k] * qty << endl;
                                cout << "\tOrder placed successfully." << endl;
                                cin.get();
                                break;
                            }
                            else
                            {
                                setTextColor(12); // Red
                                if (mobileQty[k] != 0)
                                {
                                    cout << "\n Only " << mobileQty[k] << " items are available. Please select a lower quantity!";
                                }
                                else
                                {
                                    cout << mobileModel[k] << " is OUT OF Stock!";
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
        }
        else
        {
            setTextColor(12); // Red
            cout << "\nError: You have reached the maximum order limit!\n";
        }
    }
    else
    {
        setTextColor(12); // Red
        cout << "\n\tNo Mobile added Yet!" << endl;
    }
    // saveOrders(isCustomerExit, orders, orderQty, orderStatus, isOrderExist, MaxOrder, CusSize, typeofSave, fileName);
    saveOrders(isCustomerExit, orders, orderQty, orderStatus, isOrderExist, MaxOrder, CusSize, "", "orderId.txt");
    // saveOrders(isCustomerExit, orders, orderQty, orderStatus, isOrderExist, MaxOrder, CusSize, "qty", "orderQty.txt");
    // saveOrders(isCustomerExit, orders, orderQty, orderStatus, isOrderExist, MaxOrder, CusSize, "status", "orderStatus.txt");

    cin.get();
}
// order tracking
void orderTracking(string mobileBrand[], string mobileModel[], string mobileColor[], string mobileStorage[], int mobSalePrice[], double discount[], bool isMobileExist[], int MaxMobile, int mobItemId[], int orderQty[][MaxOrder], int orders[][MaxOrder], int orderPrices[][MaxOrder], int orderCounts[], bool isOrderExist[][MaxOrder], string orderStatus[][MaxOrder], int MaxOrder, int CusSize, string username, string pwd, string cusUsername[], string cusPwd[])
{
    system("cls");
    // k used for mobile details
    //  i used for order fields of particuler customer
    int cusIndex = 0; // stores currenly logened customer index
    cusIndex = findCustomerIndex(username, pwd, cusUsername, cusPwd, CusSize);
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
    if (orderCounts[cusIndex] != 0)
    { // is there any order placed by customer
        int counter = 1;
        for (int i = 0; i < MaxOrder; i++)
        { /*for order findind at which index order exist means field*/
            if (isOrderExist[i])
            {
                for (int k = 0; k < MaxMobile; k++)
                { // extrcting the data of mobile by itemId stores at field i
                    if (orders[cusIndex][i] == mobItemId[k])
                    { // if itemId stored in order 2d array matches with itemId of mobile
                        cout << "\t\t";
                        cout << " | " << setw(4) << counter << "| "
                             << setw(9) << mobileBrand[k] << "| "
                             << setw(17) << mobileModel[k] << "| "
                             << setw(15) << mobileStorage[k] << "| "
                             << setw(8) << mobileColor[k] << "| "
                             << setw(11) << mobSalePrice[k] << "| "
                             << setw(5) << orderQty[cusIndex][i] << "| "
                             << setw(13) << orderQty[cusIndex][i] * mobSalePrice[k] << "| "
                             << setw(13) << orderStatus[cusIndex][i] << "|" << endl;
                        grandTotal += orderQty[cusIndex][i] * mobSalePrice[k];
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
void saveEmployeeData(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], string empGender[], bool isEmpExist[], int EmpSize, int &empCount)
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
        if (isEmpExist[i])
        {
            fout << empUsername[i] << "," << empPwd[i] << "," << empName[i] << "," << empFname[i] << ","
                 << empCellNo[i] << "," << empAddress[i] << "," << empCnic[i] << "," << empDOB[i] << ","
                 << empGender[i] << endl;
        }
    }
    fout.close();
}

void loadEmployeeData(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], string empGender[], bool isEmpExist[], int EmpSize, int &empCount)
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
        if (!getline(fin, empUsername[i], ','))
            break;
        getline(fin, empPwd[i], ',');
        getline(fin, empName[i], ',');
        getline(fin, empFname[i], ',');
        getline(fin, empCellNo[i], ',');
        getline(fin, empAddress[i], ',');
        getline(fin, empCnic[i], ',');
        getline(fin, empDOB[i], ',');
        fin >> empGender[i];
        fin.ignore();

        // Check if any field is empty or invalid
        if (empUsername[i].empty() || empPwd[i].empty() || empName[i].empty() ||
            empFname[i].empty() || empCellNo[i].empty() || empAddress[i].empty() ||
            empCnic[i].empty() || empDOB[i].empty())
        {
            cout << "Warning: Incomplete or invalid data on line " << endl;
            continue; // skip if invalid
        }
        empCount++; // Increment employee count
        isEmpExist[i] = true;
        i++;
    }

    fin.close();

    if (empCount == 0)
    {
        cout << "Warning: The file is empty or contains no valid data." << endl;
    }
}

//<----------------------------customer data save & load---------------------------------->
void SaveCustomerData(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount)
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
        if (isCustomerExit[i])
        {
            fout << cusUsername[i] << "," << cusPwd[i] << "," << cusName[i] << "," << cusCell[i] << "," << cusDOB[i] << "," << cusGender[i] << "," << cusAddress[i] << endl;
        }
    }
    fout.close();
}

void loadCustomerData(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount)
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
        if (!getline(fin, cusUsername[i], ','))
            break;
        if (!getline(fin, cusPwd[i], ',') || !getline(fin, cusName[i], ',') ||

            !getline(fin, cusCell[i], ',') || !getline(fin, cusDOB[i], ',') ||

            !getline(fin, cusGender[i], ',') || !getline(fin, cusAddress[i]))
        {
            cout << "Warning: Incomplete data for customer at record " << i + 1 << endl;
            // Clear incomplete data for current record
            cusUsername[i].clear();
            cusPwd[i].clear();
            cusName[i].clear();
            cusCell[i].clear();
            cusDOB[i].clear();
            cusGender[i].clear();
            cusAddress[i].clear();
            continue; // Skip to next record
        }
        // Validate non-empty data
        if (cusUsername[i].empty() || cusPwd[i].empty() || cusName[i].empty() ||
            cusCell[i].empty() || cusDOB[i].empty() || cusGender[i].empty() || cusAddress[i].empty())
        {
            cout << "Warning: Incomplete data for customer at record " << i + 1 << endl;
            continue;
        }
        isCustomerExit[i] = true; // Mark customer as existing
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
void saveInventryData(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount)
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
        if (isMobileExist[i])
        {
            fout << mobileBrand[i] << ","
                 << mobileModel[i] << ","
                 << mobileStorage[i] << ","
                 << mobileSpecs[i] << ","
                 << mobileColor[i] << ","
                 << mobileSupplierName[i] << ","
                 << mobileQty[i] << ","
                 << mobPurchasePrice[i] << ","
                 << mobSalePrice[i] << ","
                 << mobMinStockLevel[i] << ","
                 << mobItemId[i] << endl;
        }
    }
    fout.close();
}

void loadInventryData(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount)
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
        if (!getline(fin, mobileBrand[i], ','))
            break;
        getline(fin, mobileModel[i], ',');
        getline(fin, mobileStorage[i], ',');
        getline(fin, mobileSpecs[i], ',');
        getline(fin, mobileColor[i], ',');
        getline(fin, mobileSupplierName[i], ',');
        fin >> mobileQty[i];
        fin.ignore();
        fin >> mobPurchasePrice[i];
        fin.ignore();
        fin >> mobSalePrice[i];
        fin.ignore();
        fin >> mobMinStockLevel[i];
        fin.ignore();
        fin >> mobItemId[i];
        fin.ignore();

        // check required field is empty
        if (mobileBrand[i].empty() || mobileModel[i].empty() || mobileStorage[i].empty() ||
            mobileSpecs[i].empty() || mobileColor[i].empty() || mobileSupplierName[i].empty())
        {
            cout << "Warning: Incomplete data for mobile item " << endl;
            continue; // Skip record
        }

        isMobileExist[i] = true;
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

void saveOrders(bool isCustomerExit[], int orders[][10], int orderQty[][10], string orderStatus[][10], bool isOrderExist[][10], int MaxOrder, int CusSize, string typeofSave, string fileName)
{
    ofstream fout(fileName); // Open the file for writing
    if (!fout)
    {
        cout << "Error: Could not open " << fileName << " for writing!" << endl;
        return;
    }

    for (int cusIndex = 0; cusIndex < CusSize; cusIndex++)
    {
        if (isCustomerExit[cusIndex])
        {
            // Write Orders (Line 1)
            bool firstOrder = true;
            for (int order = 0; order < MaxOrder; order++)
            {
                if (isOrderExist[cusIndex][order])
                {
                    if (!firstOrder)
                        fout << ","; // Add comma separator
                    fout << orders[cusIndex][order];
                    firstOrder = false;
                }
            }
            fout << endl; // End of the orders line

            // Write Quantities (Line 2)
            firstOrder = true;
            for (int order = 0; order < MaxOrder; order++)
            {
                if (isOrderExist[cusIndex][order])
                {
                    if (!firstOrder)
                        fout << ",";
                    fout << orderQty[cusIndex][order];
                    firstOrder = false;
                }
            }
            fout << endl; // End of the quantities line

            // Write Statuses (Line 3)
            firstOrder = true;
            for (int order = 0; order < MaxOrder; order++)
            {
                if (isOrderExist[cusIndex][order])
                {
                    if (!firstOrder)
                        fout << ",";
                    fout << orderStatus[cusIndex][order];
                    firstOrder = false;
                }
            }
            fout << endl; // End of the statuses line
        }
    }

    fout.close(); // Close the file
}

void loadOrders(bool isCustomerExit[], int orders[][10], int orderQty[][10], string orderStatus[][10], bool isOrderExist[][10], int MaxOrder, int CusSize, int orderCounts[], string typeofSave, string fileName)
{
    ifstream fin(fileName); // Open the file for reading
    if (!fin)
    {
        cout << "Error: Could not open " << fileName << " for reading!" << endl;
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
                break;                                // No more fields to extract
            orders[rows][cols++] = stringToInt(temp); // Store in orders array
            isOrderExist[rows][cols] = true;
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
            orderQty[rows][cols++] = stringToInt(temp); // Store in orderQty array
            orderCounts[rows]++;
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
            orderStatus[rows][cols++] = temp; // Store in orderStatus array
            if (cols >= MaxOrder)
                break;
        }

        rows++; // Move to the next customer
    }

    fin.close(); // Close the file
}

//<----------------------------profit save report----------------------------------->
void saveProfitReport(int &tCost, int &tRevenue, int &tProfit, int &mobSold)
{
    ofstream fout;
    fout.open("profit.txt"); // Open the file for writing
    if (!fout)
    {
        cout << "Error: Could not open profit.txt for writing!" << endl;
        return;
    }
    fout << mobSold << endl;
    fout << tRevenue << endl;
    fout << tCost << endl;
    fout << tProfit << endl;

    fout.close();
}

void loadProfitReport(int &tCost, int &tRevenue, int &tProfit, int &mobSold)
{
    ifstream fin;
    fin.open("profit.txt");
    if (!fin)
    {
        cout << "Error: Could not open profit.txt for reading!" << endl;
    }
    fin >> mobSold;
    fin >> tRevenue;
    fin >> tCost;
    fin >> tProfit;

    fin.close();
}
