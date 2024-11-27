#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <conio.h> //used to use _getch() in masked pass
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

// other functionalities
//<---------------validations----------------------->
void invalidErrorMessage();   // invalid option error
int getValidDigitInput();     // make sure input is 0 - 9 single digit
string correctDataEntry();    // ensures user enter b/w (A to Z) & 0 - 9
string maskedInputPass();     // input masked password from user
void setTextColor(int color); // changes the color of specific text

//<------------------employee management-------------------------->
// add employee
void addEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], char empGender[], bool isEmpExist[], int EmpSize, int &empCount);
// update employee
void updateEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], char empGender[], bool isEmpExist[], int EmpSize, int &empCount); // Uemp :
// view all employees
void viewEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], char empGender[], bool isEmpExist[], int EmpSize, int &empCount);
// delete employee
void deleteEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], char empGender[], bool isEmpExist[], int EmpSize, int &empCount);

//<----------------------inventry management------------------->
// add inventry
void addInventry(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int &inventryChoice, int mobItemId[], int &mobileCount, // accessories
                 string accessoryName[], string accessorySpecs[], string accessorySupplier[], int accessoryQuantity[], double accessoryPurchasePrice[], double accessorySalePrice[], int accessoryMinStock[], double accessoryDiscount[], string accessoryStatus[], bool isAccessoryExist[], int MaxAccessory, int &accessoryCount);
// add mobiles
void addMobiles(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount);
void addAccessories(string accessoryName[], string accessorySpecs[], string accessorySupplier[], int accessoryQuantity[], double accessoryPurchasePrice[], double accessorySalePrice[], int accessoryMinStock[], double accessoryDiscount[], string accessoryStatus[], bool isAccessoryExist[], int MaxAccessory, int &accessoryCount);
void updateMobiles(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount);
void deleteMobiles(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount);
void viewMobiles(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, bool isAdmin); // here bool isAdmin determine wether to show full detailed list or ristricted (1 for admin, 0 for others)

//<-----------------------customer order management---------------------------------------->
void cusOrderManagment(string mobileBrand[], string mobileModel[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, int orderQty[][MaxOrder], int orders[][MaxOrder], int orderPrices[][MaxOrder], int orderCounts[], bool isOrderExist[][MaxOrder], string orderStatus[][MaxOrder], int MaxOrder, int CusSize, bool isCustomerExit[], string cusUsername[], string cusName[]);
void managePendingOrders(string mobileBrand[], string mobileModel[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, int mobProfit[], int orderQty[][MaxOrder], int orders[][MaxOrder], int orderPrices[][MaxOrder], int orderCounts[], bool isOrderExist[][MaxOrder], string orderStatus[][MaxOrder], int MaxOrder, int CusSize, bool isCustomerExit[], string cusUsername[], string cusName[]);
//<------------------Customer profiles-------------------------->
void addCustomer(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount);
void viewAllCustomer(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount);
void deleteCustomer(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount);
void updateCustomer(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount);

//<-------------------------place an order--------------------------->
// find user index to specfic logined customer
int findCustomerIndex(string username, string pwd, string cusUsername[], string cusPwd[], int CusSize);
void placeOrder(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, bool isAdmin, int orderQty[][MaxOrder], int orders[][MaxOrder], int orderPrices[][MaxOrder], int orderCounts[], bool isOrderExist[][MaxOrder], string orderStatus[][MaxOrder], int MaxOrder, int CusSize, string username, string pwd, string cusUsername[], string cusPwd[]);
void orderTracking(string mobileBrand[], string mobileModel[], string mobileColor[], string mobileStorage[], int mobSalePrice[], double discount[], bool isMobileExist[], int MaxMobile, int mobItemId[], int orderQty[][MaxOrder], int orders[][MaxOrder], int orderPrices[][MaxOrder], int orderCounts[], bool isOrderExist[][MaxOrder], string orderStatus[][MaxOrder], int MaxOrder, int CusSize, string username, string pwd, string cusUsername[], string cusPwd[]);

int main()
{
    //<--------------for authentication--------------->
    int choice;
    string username, pwd;
    int loggedInUserType = -1; // 1 for manager, 2 for employee, 3 customer , 4 customer without profile

    //<------------manager attributes--------------->
    string managerPWD, managerUsername;
    managerUsername = "Admin"; // admin username
    managerPWD = "admin123";   // admin password
    int managerChoice = -1;

    //<------------employee attributes------------------->
    // string empPWD, empUsername;
    // empUsername = "Emp";
    // empPWD = "emp123";
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
    char empGender[EmpSize];    // emp gender
    // initilize arrays
    for (int i = 0; i < EmpSize; i++)
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
    int accessoryCount = 0;
    // mobiles
    const int MaxMobile = 30; // max no. of items
    int mobProfit[MaxMobile];
    enum MobProfit {brand,mblModel,profit};
    string isProfitExist[MaxMobile];
    string mobProfit[MaxMobile][3];
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
    // Accessories
    const int MaxAccessory = 30; // Maximum number of accessories
    string accessoryName[MaxAccessory];
    string accessorySpecs[MaxAccessory];
    string accessorySupplier[MaxAccessory];
    int accessoryQuantity[MaxAccessory];
    double accessoryPurchasePrice[MaxAccessory];
    double accessorySalePrice[MaxAccessory];
    int accessoryMinStock[MaxAccessory];
    double accessoryDiscount[MaxAccessory];
    string accessoryStatus[MaxAccessory];
    bool isAccessoryExist[MaxAccessory]; // check the variable is there exist any accessory
    for (int i = 0; i < MaxMobile; i++)
    {
        mobItemId[i] = -1;
        mobProfit[i] = 0;
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
    }
    // order management attributes
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

    do
    {
        mainInterface();
        choice = getValidDigitInput(); // assures valid input digit 0-9

        // Main menu options handling
        switch (choice)
        {
        case 1:
        {
            managerLoginHeader();
            setTextColor(14); // yellow
            cout << " Enter Username: ";
            setTextColor(11); // aqua
            cin >> username;
            cin.ignore(100, '\n');
            setTextColor(14);
            cout << " Enter Password: ";
            setTextColor(11);
            pwd = maskedInputPass(); // calls the function to take input and save in pwd
            // if (username == managerUsername && pwd == managerPWD)
            if (true) // delete this line after u done testing
                loggedInUserType = 1;
            else
            {
                loggedInUserType = -1;
                setTextColor(12);
                cout << "Invalid Manager Credentials!\n";
                setTextColor(8);
                system("pause");
            }
            break;
        }
        case 2:
        {
            employeeLoginHeader();
            setTextColor(14);
            cout << " Enter Username: ";
            setTextColor(11);
            cin >> username;
            setTextColor(14);
            cout << " Enter Password: ";
            setTextColor(11);
            isUserFound = false;
            pwd = maskedInputPass(); // calls the function to take input and save in pwd
            for (int i = 0; i < EmpSize; i++)
            {
                if (username == empUsername[i] && pwd == empPwd[i])
                {
                    loggedInUserType = 2;
                    isUserFound = true;
                    break;
                }
            }
            if (!isUserFound)
            { // if no user found
                loggedInUserType = -1;
                setTextColor(12);
                cout << "Invalid Employee Credentials!\n";
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
                            // addInventry(mobileBrand,mobileModel,mobileSpecs,mobileSupplierName,mobileColor,mobileQty,mobileStorage,mobPurchasePrice,mobSalePrice, mobMinStockLevel,discount,status,isMobileExist,MaxMobile,inventryChoice,mobileCount,
                            // accessoryName,accessorySpecs,accessorySupplier,accessoryQuantity,accessoryPurchasePrice,accessorySalePrice,accessoryMinStock,accessoryDiscount,accessoryStatus,isAccessoryExist, MaxAccessory,accessoryCount);

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
                        { // update customer data
                            updateCustomer(cusUsername, cusPwd, cusName, cusCell, cusAddress, cusDOB, cusGender, isCustomerExit, CusSize, customerCount);
                            break;
                        }
                        case 3:
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
                    managePendingOrders(mobileBrand, mobileModel, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount, mobProfit, orderQty, orders, orderPrices, orderCounts, isOrderExist, orderStatus, MaxOrder, CusSize, isCustomerExit, cusUsername, cusName);
                    break;
                }
                // case 5:
                // {
                //     // code
                //     break;
                // }
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
                            // addInventry(mobileBrand,mobileModel,mobileSpecs,mobileSupplierName,mobileColor,mobileQty,mobileStorage,mobPurchasePrice,mobSalePrice, mobMinStockLevel,discount,status,isMobileExist,MaxMobile,inventryChoice,mobileCount,
                            // accessoryName,accessorySpecs,accessorySupplier,accessoryQuantity,accessoryPurchasePrice,accessorySalePrice,accessoryMinStock,accessoryDiscount,accessoryStatus,isAccessoryExist, MaxAccessory,accessoryCount);

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
                    managePendingOrders(mobileBrand, mobileModel, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount, mobProfit, orderQty, orders, orderPrices, orderCounts, isOrderExist, orderStatus, MaxOrder, CusSize, isCustomerExit, cusUsername, cusName);
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
                    placeOrder(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount, 0, orderQty, orders, orderPrices, orderCounts, isOrderExist, orderStatus, MaxOrder, CusSize, username, pwd, cusUsername, cusPwd);
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

//<-------------------------------Functionalities functions & validations---------------------------------->
// this chacks whether input from 0 to 9
int getValidDigitInput()
{
    int input = -1; // that will return the final correct input
    char choice[10];
    bool isDigit = false;
    do
    {
        setTextColor(14);
        cout << "\t\t\t\t\t\t\t\tSelect desired option: ";
        setTextColor(15);
        cin >> choice;
        cin.ignore(100, '\n');
        if ((choice[0] >= '0' && choice[0] <= '9') && choice[1] == '\0')
        {
            input = atoi(choice);
            return input;
        }
        else
            return input;
        // that will return wrong input that detected by above used switch satement and shows error
        // after this again asked for input untill correct input
    } while (!isDigit);
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
string correctDataEntry()
{
    string input;
    bool correct = false;
    do
    {
        getline(cin, input); // input
        // Check if input is not empty and contains at least one valid character
        correct = false;
        for (int i = 0; i < input.length(); ++i)
        { // validate here char by char
            char c = input[i];
            // check if lies b/w (A to Z)
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z' || (c >= '0' && c <= '9')))
            {
                correct = true;
                break;
            }
        }
        if (!correct)
        {
            cout << "Invalid input! Enter again : ";
        }
    } while (!correct);
    return input;
}
//<-------------------------------Manager functionalities------------------------------->
// employee adding function
void addEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], char empGender[], bool isEmpExist[], int EmpSize, int &empCount)
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
                empUsername[i] = correctDataEntry();
                cout << "Enter Password : ";
                empPwd[i] = correctDataEntry();
                cout << "Enter employee full name : ";
                empName[i] = correctDataEntry();
                cout << "Enter employee father's name : ";
                empFname[i] = correctDataEntry();
                cout << "Enter employee phone number : ";
                empCellNo[i] = correctDataEntry();
                cout << "Enter employee cnic number : ";
                empCnic[i] = correctDataEntry();
                cout << "Enter employee address : ";
                empAddress[i] = correctDataEntry();
                cout << "Enter employee date of birth (DD-MM-YYYY): ";
                getline(cin, empDOB[i]);
                cout << "Enter gender (M for male or F for Female): ";
                cin >> empGender[i];
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
}
// Uemp :
void updateEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], char empGender[], bool isEmpExist[], int EmpSize, int &empCount)
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
        cin >> username;
        for (int i = 0; i < EmpSize; i++)
        {
            if (username == empUsername[i])
            {
                cout << "Enter updated Username : ";
                cin.ignore();
                empUsername[i] = correctDataEntry();
                cout << "Enter new Password : ";
                empPwd[i] = correctDataEntry();
                cout << "Enter employee full name : ";
                empName[i] = correctDataEntry();
                cout << "Enter employee father's name : ";
                empFname[i] = correctDataEntry();
                cout << "Enter employee phone number : ";
                empCellNo[i] = correctDataEntry();
                cout << "Enter employee cnic number : ";
                empCnic[i] = correctDataEntry();
                cout << "Enter employee address : ";
                empAddress[i] = correctDataEntry();
                cout << "Enter employee date of birth (DD-MM-YYYY): ";
                getline(cin, empDOB[i]);
                cout << "Enter gender (M for male or F for Female): ";
                cin >> empGender[i];
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
    cin.get();
}
void deleteEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], char empGender[], bool isEmpExist[], int EmpSize, int &empCount)
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
        cin >> username;
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
}

// view employees
void viewEmployee(string empUsername[], string empPwd[], string empName[], string empFname[], string empCellNo[], string empAddress[], string empCnic[], string empDOB[], char empGender[], bool isEmpExist[], int EmpSize, int &empCount)
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
                mobileBrand[i] = correctDataEntry();
                cout << "Enter model: ";
                mobileModel[i] = correctDataEntry();
                cout << "Enter storage: ";
                mobileStorage[i] = correctDataEntry();
                cout << "Enter specs: ";
                mobileSpecs[i] = correctDataEntry();
                cout << "Enter mobile color: ";
                mobileColor[i] = correctDataEntry();
                cout << "Enter supplier name: ";
                mobileSupplierName[i] = correctDataEntry();
                cout << "Enter quantity: ";
                cin >> mobileQty[i];
                cout << "Enter purchase Price: ";
                cin >> mobPurchasePrice[i];
                cout << "Enter sale Price: ";
                cin >> mobSalePrice[i];
                cout << "Enter minimum Stock Level: ";
                cin >> mobMinStockLevel[i];
                mobileCount++;
                mobItemId[i] = i + 1;
                isMobileExist[i] = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tMobile added successfully......." << endl;
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
// add accessories
void addAccessories(string accessoryName[], string accessorySpecs[], string accessorySupplier[], int accessoryQuantity[], double accessoryPurchasePrice[], double accessorySalePrice[], int accessoryMinStock[], double accessoryDiscount[], string accessoryStatus[], bool isAccessoryExist[], int MaxAccessory, int &accessoryCount)
{
    system("cls");
    setTextColor(14);
    cout << " ===================================" << endl;
    setTextColor(11);
    cout << "        --- Add Accessory ---       " << endl;
    setTextColor(14);
    cout << " ===================================" << endl
         << endl;
    if (accessoryCount <= MaxAccessory)
    {
        for (int i = 0; i < MaxAccessory; i++)
        {
            if (!isAccessoryExist[i])
            {
                cout << "Enter accessory name : ";
                cin.ignore();
                accessoryName[i] = correctDataEntry();
                cin.ignore();
                cout << "Enter accessory specs : ";
                accessorySpecs[i] = correctDataEntry();
                cout << "Enter supplier name: ";
                accessorySupplier[i] = correctDataEntry();
                cout << "Enter quantity: ";
                cin >> accessoryQuantity[i];
                cout << "Enter purchase Price: ";
                cin >> accessoryPurchasePrice[i];
                cout << "Enter sale Price: ";
                cin >> accessorySalePrice[i];
                cout << "Enter minimum Stock Level: ";
                cin >> accessoryMinStock[i];
                accessoryCount++;
                isAccessoryExist[i] = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tMobile added successfully......." << endl;
                cin.ignore();
                cin.get();
                break;
            }
        }
    }
    else
    {
        setTextColor(12); // red
        cout << "\n\tMaximum number of accessory reached. Cannot add more accoessory!" << endl;
        cin.get();
    }
}
// add inventry
void addInventry(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int &inventryChoice, int mobItemId[], int &mobileCount, // accessories
                 string accessoryName[], string accessorySpecs[], string accessorySupplier[], int accessoryQuantity[], double accessoryPurchasePrice[], double accessorySalePrice[], int accessoryMinStock[], double accessoryDiscount[], string accessoryStatus[], bool isAccessoryExist[], int MaxAccessory, int &accessoryCount)
{
    do
    {
        system("cls");
        setTextColor(14);
        cout << " ===================================" << endl;
        setTextColor(11);
        cout << "        --- Add Inventory ---       " << endl;
        setTextColor(14);
        cout << " ===================================" << endl;
        setTextColor(14);
        cout << " 1. ";
        setTextColor(11);
        cout << "Add Mobile" << endl;
        setTextColor(14);
        cout << " 2. ";
        setTextColor(11);
        cout << "Add Accessory" << endl;
        setTextColor(14);
        cout << " 0. ";
        setTextColor(11);
        cout << "Exit" << endl;
        setTextColor(14);
        cout << " ===================================" << endl;
        inventryChoice = getValidDigitInput(); // assures valid input digit 0-9
        switch (inventryChoice)
        {
        case 1:
        { // add mobile
            addMobiles(mobileBrand, mobileModel, mobileSpecs, mobileSupplierName, mobileColor, mobileQty, mobileStorage, mobPurchasePrice, mobSalePrice, mobMinStockLevel, discount, status, isMobileExist, MaxMobile, mobItemId, mobileCount);
            break;
        }
        case 2:
        { // add accessory
            addAccessories(accessoryName, accessorySpecs, accessorySupplier, accessoryQuantity, accessoryPurchasePrice, accessorySalePrice, accessoryMinStock, accessoryDiscount, accessoryStatus, isAccessoryExist, MaxAccessory, accessoryCount);
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
    } while (inventryChoice != 0);
    inventryChoice = -1;
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
        searchMob = correctDataEntry();
        for (int i = 0; i < MaxMobile; i++)
        {
            if (mobileModel[i] == searchMob)
            {
                cout << "Enter mobile Brand : ";
                mobileBrand[i] = correctDataEntry();
                cout << "Enter model: ";
                mobileModel[i] = correctDataEntry();
                cout << "Enter storage: ";
                mobileStorage[i] = correctDataEntry();
                cout << "Enter specs: ";
                mobileSpecs[i] = correctDataEntry();
                cout << "Enter mobile color: ";
                mobileColor[i] = correctDataEntry();
                cout << "Enter supplier name: ";
                mobileSupplierName[i] = correctDataEntry();
                cout << "Enter quantity: ";
                cin >> mobileQty[i];
                cout << "Enter purchase Price: ";
                cin >> mobPurchasePrice[i];
                cout << "Enter sale Price: ";
                cin >> mobSalePrice[i];
                cout << "Enter minimum Stock Level: ";
                cin >> mobMinStockLevel[i];
                Found = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tMobile updated successfully......." << endl;
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
        searchMob = correctDataEntry();
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
        } //-----------
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


void managePendingOrders(string mobileBrand[], string mobileModel[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, int mobProfit[], int orderQty[][MaxOrder], int orders[][MaxOrder], int orderPrices[][MaxOrder], int orderCounts[], bool isOrderExist[][MaxOrder], string orderStatus[][MaxOrder], int MaxOrder, int CusSize, bool isCustomerExit[], string cusUsername[], string cusName[])
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
            cin >> username;
            cout << "Enter item id : ";
            cin >> itemId;
            cout << "Select new status:" << endl;
            cout << "1. Shipped" << endl;
            cout << "2. Delivered" << endl;
            cout << "3. Out of Stock" << endl;
            do
            {
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
                        updateStatus =  "Delivered";
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
            } while (stChoice!=1 &&stChoice!=2 && stChoice!=3);
            stChoice = -1;
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
                                        }
                                        isItemIdCorrect = true;
                                        setTextColor(10); // green
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
                cusUsername[i] = correctDataEntry();
                cout << "Enter Password : ";
                cusPwd[i] = correctDataEntry();
                cout << "Enter your name :";
                cusName[i] = correctDataEntry();
                cout << "Enter your phone number : ";
                cusCell[i] = correctDataEntry();
                cout << "Enter your date of birth : ";
                cusDOB[i] = correctDataEntry();
                cout << "Enter your gender : ";
                cusGender[i] = correctDataEntry();
                cout << "Enter your Address : ";
                cusAddress[i] = correctDataEntry();
                customerCount++;
                isCustomerExit[i] = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tProfile Created Successfully......." << endl;
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
        cin >> username;
        for (int i = 0; i < CusSize; i++)
        {
            if (username == cusUsername[i])
            {
                cout << "Enter Username : ";
                cin >> cusUsername[i];
                cout << "Enter Password : ";
                cin.ignore();
                cusPwd[i] = correctDataEntry();
                cout << "Enter your name :";
                cusName[i] = correctDataEntry();
                cout << "Enter your phone number : ";
                cusCell[i] = correctDataEntry();
                cout << "Enter your date of birth : ";
                cusDOB[i] = correctDataEntry();
                cout << "Enter your gender : ";
                cusGender[i] = correctDataEntry();
                cout << "Enter your Address : ";
                cusAddress[i] = correctDataEntry();
                isUserFound = true;
                setTextColor(10); // green
                cout << "\n\t\t\t\t\t\t\t\tCustomer data updated successfully......." << endl;
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
    cin.get();
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
        cin >> username;
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
    cin.get();
}

void viewAllCustomer(string cusUsername[], string cusPwd[], string cusName[], string cusCell[], string cusAddress[], string cusDOB[], string cusGender[], bool isCustomerExit[], int CusSize, int &customerCount)
{
    system("cls");
    cout << endl
         << endl;
    setTextColor(14);
    cout << "\t\t\t\t\t\t\t===================================" << endl;
    setTextColor(11);
    cout << "\t\t\t\t\t\t\t     --- Customers Details ---     " << endl;
    setTextColor(14);
    cout << "\t\t\t\t\t\t\t===================================" << endl
         << endl;
    cout << left;
    cout << " ----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(16) << " | Username " << setw(16) << "| Password" << setw(20) << "| Customer Name" << setw(16) << "| Phone No" << setw(15) << "| DOB" << setw(10) << "| Gender" << setw(55) << "| Address" << "|" << endl;
    cout << " ----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    if (customerCount != 0)
    {
        for (int i = 0; i < CusSize; i++)
        {
            if (isCustomerExit[i])
            {
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
    }
    else
    {
        setTextColor(12); // Red
        cout << "\n\tNo Customer Found!" << endl;
    }
    cin.get();
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

void placeOrder(string mobileBrand[], string mobileModel[], string mobileSpecs[], string mobileSupplierName[], string mobileColor[], int mobileQty[], string mobileStorage[], int mobPurchasePrice[], int mobSalePrice[], int mobMinStockLevel[], double discount[], string status[], bool isMobileExist[], int MaxMobile, int mobItemId[], int &mobileCount, bool isAdmin, int orderQty[][MaxOrder], int orders[][MaxOrder], int orderPrices[][MaxOrder], int orderCounts[], bool isOrderExist[][MaxOrder], string orderStatus[][MaxOrder], int MaxOrder, int CusSize, string username, string pwd, string cusUsername[], string cusPwd[])
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
    if (mobileCount != 0)
    {
        if (orderCounts[cusIndex] < MaxOrder)
        { // make sure not reach max order limit
            for (int i = 0; i < MaxOrder; i++)
            {
                if (!isOrderExist[cusIndex][i])
                { // where to store item id for order (at i index) related to order
                    cout << "\tEnter item id of product you wanna buy : ";
                    cin >> itemId;
                    cout << "\tEnter the quantity : ";
                    cin >> qty;
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
                                cout << "\n\t Mobile model : " << mobileModel[k] << endl;
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
        cout << "\t\t   Grand Total :      " << grandTotal<<" rupees" <<endl;
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

    // setTextColor(14);
    // cout << " 5. ";
    // setTextColor(11);
    // cout << "Profit Report" << endl;

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
    cout << "Update customer data" << endl;
    setTextColor(14);
    cout << " 3. ";
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
