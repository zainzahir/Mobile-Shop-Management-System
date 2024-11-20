#include <iostream>
#include <windows.h> 
#include<string>
#include<iomanip>
#include <conio.h> //used to use _getch() in masked pass
using namespace std;

//main interface of App
void mainInterface(); //enables to select type of user

//1. Manager Portal
//Shows interfaces
void managerLoginHeader(); //manager login page
void managerMainMenu(); //manager portal options
void inventryManagementHeader(); //shows inventry management header
void managerInventryManagement(); //shows features of manager inventry
void employeeManagementHeader(); //show only header
void managerEmployeeManagement(); //manager user management windows like add,edit,delete 
void customerManagementHeader(); //shows customer managment header
void managerCustomerManagement(); // customer managment options
void orderManagementHeader(); //shows order Management Header
void managerOrderManagement(); // order of customer management

//2. Employee Portal
//Shows interfaces
void employeeLoginHeader(); //employee login page
void employeeMainMenu(); //employee portal options
void employeeInventryManagement(); //shows features of employee inventry
void employeeCustomerManagement(); // customer managment options under employee
void employeeOrderManagement(); // order of customer management under employee

//3. customer portal
//Shows interfaces
void customerPortalHeader();
void customerPortal(); //customer portal with options
void customerProfileMenu(); //customer within profile options
void customerWithoutLoginMenu(); ////customer without having a profile

//other functionalities 
void invalidErrorMessage(); //invalid option error
int getValidDigitInput(); //make sure input is 0 - 9 single digit
string maskedInputPass(); //input masked password from user
void setTextColor(int color); //changes the color of specific text

//<------------------employee management-------------------------->
//add employee
void addEmployee(string empUsername[],string empPwd[],string empName[], string empFname[], string empCellNo[],string empAddress[], string empCnic[], string empDOB[], char empGender[],bool isEmpExist[], int EmpSize,int &empCount);
//update employee
void updateEmployee(string empUsername[],string empPwd[],string empName[], string empFname[], string empCellNo[],string empAddress[], string empCnic[], string empDOB[], char empGender[],bool isEmpExist[], int EmpSize,int &empCount); //Uemp : 
//view all employees
void viewEmployee(string empUsername[],string empPwd[],string empName[], string empFname[], string empCellNo[],string empAddress[], string empCnic[], string empDOB[], char empGender[],bool isEmpExist[], int EmpSize,int &empCount);
//delete employee
void deleteEmployee(string empUsername[],string empPwd[],string empName[], string empFname[], string empCellNo[],string empAddress[], string empCnic[], string empDOB[], char empGender[],bool isEmpExist[], int EmpSize,int &empCount);

//<----------------------inventry management------------------->
// add inventry
void addInventry(string mobileBrand[],string mobileModel[],string mobileSpecs[],string mobileSupplierName[],string mobileColor[],   int mobileQty[],string mobileStorage[],double mobPurchasePrice[],double mobSalePrice[],int mobMinStockLevel[],double discount[],string status[],bool isMobileExist[],int MaxMobile,int &inventryChoice, //accessories
string accessoryName[],string accessorySpecs[],string accessorySupplier[],int accessoryQuantity[],double accessoryPurchasePrice[],double accessorySalePrice[],int accessoryMinStock[],double accessoryDiscount[],string accessoryStatus[],bool isAccessoryExist[],int MaxAccessory);
//add mobiles
void addMobiles(string mobileBrand[],string mobileModel[],string mobileSpecs[],string mobileSupplierName[],string mobileColor[],   int mobileQty[],string mobileStorage[],double mobPurchasePrice[],double mobSalePrice[],int mobMinStockLevel[],double discount[],string status[],bool isMobileExist[],int MaxMobile);
void addAccessories( string accessoryName[],string accessorySpecs[],string accessorySupplier[],int accessoryQuantity[],double accessoryPurchasePrice[],double accessorySalePrice[],int accessoryMinStock[],double accessoryDiscount[],string accessoryStatus[],bool isAccessoryExist[],int MaxAccessory);
    // accessoryName,
    // accessorySpecs,
    // accessorySupplier,
    // accessoryQuantity,
    // accessoryPurchasePrice,
    // accessorySalePrice,
    // accessoryMinStock,
    // accessoryDiscount,
    // accessoryStatus,
    // isAccessoryExist,

int main() {
    //<--------------for authentication--------------->
    int choice;
    string username, pwd;
    int loggedInUserType = -1; // 1 for manager, 2 for employee, 3 customer , 4 customer without profile

    //<------------manager attributes---------------> 
    string managerPWD, managerUsername;
    managerUsername = "Admin"; //admin username
    managerPWD = "admin123"; //admin password
    int managerChoice = -1;

    //<------------employee attributes------------------->
    // string empPWD, empUsername;
    // empUsername = "Emp";
    // empPWD = "emp123";
    int employeeChoice = -1;
    string notification;
    const int EmpSize = 10; //max no. of employes size
    int empCount = 0; //counts no of employee added
    string empUsername[EmpSize];
    string empPwd[EmpSize];
    bool isUserFound = false; //used in searching
    bool isEmpExist[EmpSize]; //check the variable is there exist any employee
    string empName[EmpSize]; //employee full name
    string empFname[EmpSize]; //emp father name
    string empCellNo[EmpSize]; //emp cell number
    string empAddress[EmpSize]; //emp address
    string empCnic[EmpSize]; //emp cnic number
    string empDOB[EmpSize]; //emp date of birth
    char empGender[EmpSize]; //emp gender
    //initilize arrays
    for(int i=0; i<EmpSize; i++){
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
    int customerChoice = -1;
    bool havingCusProfile = false; //cheacks is customer have account or not
    const int CusSize = 20; //max no. of customers size
    string cusName[CusSize]; //customer full name
    string cusCell[CusSize]; //customer cell number
    string cusAddress[CusSize]; //customer address
    string cusDOB[CusSize]; //customer birthday
    string cusGender[CusSize]; //customer gender

    //<------------------inventry attributes------------------>
    int inventryChoice = -1;
    int mobileCount = 0;
    int accessoryCount = 0;
    //mobiles
    const int MaxMobile = 30; //max no. of items
    string mobileBrand[MaxMobile];
    string mobileModel[MaxMobile];
    string mobileSpecs[MaxMobile];
    string mobileSupplierName[MaxMobile];
    string mobileColor[MaxMobile];
    int mobileQty[MaxMobile];
    string mobileStorage[MaxMobile];
    double mobPurchasePrice[MaxMobile];
    double mobSalePrice[MaxMobile];
    int mobMinStockLevel[MaxMobile];
    double discount[MaxMobile];
    string status[MaxMobile];
    bool isMobileExist[MaxMobile]; //check the variable is there exist any mobile
    //Accessories
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
    bool isAccessoryExist[MaxAccessory]; //check the variable is there exist any accessory
    //order management attributes
    string orderStatus[CusSize]; //for order status e.g shipped , pending



    do {
        mainInterface();
        choice = getValidDigitInput(); //assures valid input digit 0-9

        // Main menu options handling
        switch (choice) {
            case 1: {
                managerLoginHeader();
                setTextColor(14); //yellow
                cout << " Enter Username: ";
                setTextColor(11); //aqua
                cin >> username;
                cin.ignore(100, '\n');
                setTextColor(14);
                cout << " Enter Password: ";
                setTextColor(11);
                pwd = maskedInputPass(); //calls the function to take input and save in pwd
                // if (username == managerUsername && pwd == managerPWD)
                if (true) //delete this line after u done testing
                    loggedInUserType = 1;
                else {
                    loggedInUserType = -1;
                    setTextColor(12);
                    cout << "Invalid Manager Credentials!\n";
                    setTextColor(8);
                    system("pause");
                }
                break;
            }
            case 2: {
                employeeLoginHeader();
                setTextColor(14);
                cout << " Enter Username: ";
                setTextColor(11);
                cin >> username;
                setTextColor(14);
                cout << " Enter Password: ";
                setTextColor(11);
                isUserFound = false;
                pwd = maskedInputPass(); //calls the function to take input and save in pwd
                for(int i=0; i<EmpSize; i++){
                    if (username == empUsername[i] && pwd == empPwd[i]){
                        loggedInUserType = 2;
                        isUserFound = true;
                        break;
                    }
                }
                if (!isUserFound){  //if no user found
                    loggedInUserType = -1;
                    setTextColor(12);
                    cout << "Invalid Employee Credentials!\n";
                    setTextColor(8);
                    system("pause");
                }
                break;
            }
            case 3: {
                int cusPortalChoice;
                do{
                    customerPortal();
                    cusPortalChoice = getValidDigitInput();
                    switch(cusPortalChoice){
                            case 1:{
                                break;
                            }
                            case 2:{
                                break;
                            }
                            case 3:{
                                loggedInUserType = 4; //customer without profile
                                break;
                            }
                            case 0:{
                                break;
                            }
                            default: {
                                invalidErrorMessage(); //shows invalid error message
                            } 
                    }
                    if(cusPortalChoice==3)
                        break;
                }while (cusPortalChoice != 0 );
                    
                break;
            }
            case 0: {
                cout << "\n\t\t\t\t\t\t\tThank you for using the Mobile Shop Management System. Goodbye!" << endl;
                return 0;
            }
            default: {
                invalidErrorMessage(); //shows invalid error message
                
            }
        }
        
        // Show respective menu based on user type
        if (loggedInUserType == 1) { // Manager portal
            do {
                managerMainMenu();
                managerChoice = getValidDigitInput(); //assures valid input digit 0-9
                switch (managerChoice){
                    case 1:{ //inventry management
                        do{
                            managerInventryManagement(); //shows inventry management menu
                            managerChoice = getValidDigitInput(); //gets valid input 
                            switch (managerChoice){
                                case 1:{ //add inventry
                                    addInventry(mobileBrand,mobileModel,mobileSpecs,mobileSupplierName,mobileColor,mobileQty,mobileStorage,mobPurchasePrice,mobSalePrice, mobMinStockLevel,discount,status,isMobileExist,MaxMobile,inventryChoice,
                                    accessoryName,accessorySpecs,accessorySupplier,accessoryQuantity,accessoryPurchasePrice,accessorySalePrice,accessoryMinStock,accessoryDiscount,accessoryStatus,isAccessoryExist, MaxAccessory);
                                    break;
                                }
                                case 2:{
                                    /* code */
                                    break;
                                }
                                case 3:{
                                    /* code */
                                    break;
                                }
                                case 4:{
                                    /* code */
                                    break;
                                }
                                case 5:{
                                    /* code */
                                    break;
                                }
                                case 0:{
                                    break;
                                }
                                default:{
                                    invalidErrorMessage(); //shows invalid error message
                                }
                            }

                        }while(managerChoice != 0);
                        managerChoice = -1;
                        break;
                    }
                    case 2:{ //user (emp) management
                        do{
                            managerEmployeeManagement(); //shows employee management menu
                            managerChoice = getValidDigitInput(); //assures valid input digit 0-9
                            switch (managerChoice){
                                case 1:{ //add employee
                                    addEmployee(empUsername,empPwd,empName, empFname, empCellNo, empAddress, empCnic, empDOB, empGender,isEmpExist,EmpSize,empCount);

                                    break;
                                }
                                case 2:{ //update employee
                                    updateEmployee(empUsername,empPwd,empName, empFname, empCellNo, empAddress, empCnic, empDOB, empGender,isEmpExist,EmpSize,empCount);
                                    break;
                                }
                                case 3:{ //delete employee
                                    deleteEmployee(empUsername,empPwd,empName, empFname, empCellNo, empAddress, empCnic, empDOB, empGender,isEmpExist,EmpSize,empCount);
                                    break;
                                }
                                case 4:{ //view all employees
                                    viewEmployee(empUsername,empPwd,empName, empFname, empCellNo, empAddress, empCnic, empDOB, empGender,isEmpExist,EmpSize,empCount);
                                    break;
                                }
                                case 0:{
                                    break;
                                }
                                default:{
                                    invalidErrorMessage(); //shows invalid error message
                                }
                            }

                        }while(managerChoice != 0);
                        managerChoice = -1;
                        break;
                    }
                    case 3:{ //customer management
                        do{
                            managerCustomerManagement(); //shows customer management menu
                            managerChoice = getValidDigitInput(); //assures valid input digit 0-9
                            switch (managerChoice){
                                case 1:{
                                    /* code */
                                    break;
                                }
                                case 2:{
                                    /* code */
                                    break;
                                }
                                case 3:{
                                    /* code */
                                    break;
                                }
                                case 0:{
                                    break;
                                }
                                default:{
                                    invalidErrorMessage(); //shows invalid error message
                                }
                            }

                        }while(managerChoice != 0);
                        managerChoice = -1;
                        break;
                    }
                    case 4:{
                        //code
                        break;
                    }
                    case 0:{
                        loggedInUserType = -1;
                        break;
                    }

                    default:{
                        invalidErrorMessage(); //shows invalid error message
                    }
                }
            }while (managerChoice != 0);
            managerChoice = -1;
        } 
        else if (loggedInUserType == 2) { // Employee portal
            do {
                employeeMainMenu();
                employeeChoice = getValidDigitInput(); //assures valid input digit 0-9
                switch (employeeChoice){
                    case 1:{ //Inventry management
                        do{
                            employeeInventryManagement(); //Inventry management menu of employee
                            employeeChoice = getValidDigitInput(); //assures valid input digit 0-9
                            switch (employeeChoice){
                                case 1:{
                                    /* code */
                                    break;
                                }
                                case 2:{
                                    /* code */
                                    break;
                                }
                                case 3:{
                                    /* code */
                                    break;
                                }
                                case 4:{
                                    /* code */
                                    break;
                                }
                                case 0:{
                                    break;
                                }
                                default:{
                                    invalidErrorMessage(); //shows invalid error message
                                }
                            }

                        }while(employeeChoice != 0);
                        employeeChoice = -1; //resets the value so to remain in employee portal 
                        break;
                    }
                    case 2:{ //customer managment
                         do{
                            employeeCustomerManagement(); //shows customer managment menu of Emp
                            employeeChoice = getValidDigitInput(); //assures valid input digit 0-9
                            switch (employeeChoice){
                                case 1:{
                                    /* code */
                                    break;
                                }
                                case 2:{
                                    /* code */
                                    break;
                                }
                                case 0:{
                                    break;
                                }
                                default:{
                                    invalidErrorMessage(); //shows invalid error message
                                }
                            }

                        }while(employeeChoice != 0);
                        employeeChoice = -1; //resets the value so to remain in employee portal 
                        break;
                    }
                    case 3:{ //order managemnt
                        do{
                            employeeOrderManagement(); //shows order management menu of emp
                            employeeChoice = getValidDigitInput(); //assures valid input digit 0-9
                            switch (employeeChoice){
                                case 1:{
                                    /* code */
                                    break;
                                }
                                case 2:{
                                    /* code */
                                    break;
                                }
                                case 3:{
                                    /* code */
                                    break;
                                }
                                case 0:{
                                    break;
                                }
                                default:{
                                    invalidErrorMessage(); //shows invalid error message
                                }
                            }

                        }while(employeeChoice != 0);
                        employeeChoice = -1; //resets the value so to remain in employee portal 
                        break;
                    }
                    case 4:{ //notifications
                        /* code */
                        break;
                    }
                    case 0:{
                        loggedInUserType = -1;
                        break;
                    }

                    default:{
                        invalidErrorMessage(); //shows invalid error message
                    }
                }
            } while (employeeChoice != 0);
            employeeChoice = -1; //resets to make sure emp exit
        }
        else if (loggedInUserType == 3) { // Customer portal
            do{
                customerProfileMenu();
                customerChoice = getValidDigitInput(); //assures valid input digit 0-9
                switch (customerChoice){
                    case 1:{
                                break;
                    }
                    case 2:{
                    
                        break;
                    }
                    case 3:{
                        break;
                    }
                    case 0:{
                        break;
                    }
                    default: {
                        invalidErrorMessage(); //shows invalid error message
                    } 
                }
            }while(customerChoice !=0);
            customerChoice = -1;
        }
        else if (loggedInUserType == 4) { // Customer without profile
            int customerChoice;
            do{
                customerProfileMenu();
                customerChoice = getValidDigitInput(); //assures valid input digit 0-9
                switch (customerChoice){
                    case 1:{
                        break;
                    }
                    case 2:{
                        setTextColor(12); //red color
                        cout << "\nPlease create a profile to access this feature." << endl<<endl;
                        setTextColor(8); //grey color
                        system("pause");
                        break;
                    }
                    case 3:{
                        setTextColor(12); //red color
                        cout << "\nPlease create a profile to access this feature." << endl<<endl;
                        setTextColor(8); //grey color
                        system("pause");
                        break;
                    }
                    case 0:{
                        break;
                    }
                    default: {
                        invalidErrorMessage();
                    } 
                }
            }while(customerChoice !=0);
            customerChoice = -1;
        }
        
    } while (choice != 0);

    return 0;
}

//<-------------------------------Functionalities functions---------------------------------->
//this chacks whether input from 0 to 9
int getValidDigitInput(){
    int input = -1; //that will return the final correct input
    char choice[10];
    bool isDigit = false;
    do{
        setTextColor(14);
        cout << "\t\t\t\t\t\t\t\tSelect desired option: ";
        setTextColor(15);
        cin >> choice;
        cin.ignore(100,'\n');
        if((choice[0]>= '0' && choice[0]<='9') && choice[1]=='\0'){
            input = atoi(choice);
            return input;
        }
        else 
            return input;
            //that will return wrong input that detected by above used switch satement and shows error
            //after this again asked for input untill correct input
    }while(!isDigit);
}

//used in default case of switch to show invalid choice
void invalidErrorMessage(){
    setTextColor(12); //change color to red
    cout << "\n\t\t\t\t\t\t\t\tInvalid choice! Please try again." << endl;
    setTextColor(8); //change color to grey
    system("pause"); //waits the user to press any key
}
//changes the color to specfic text only
void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
//use to input masked password
string maskedInputPass(){
    char input;
    string inputPass;
    // cout<<"Enter the password : "; //bcz there already have this line 
    input = _getch();
    while(input!=13){
        if(input==8){
            if(!inputPass.empty()){ //checks if password not empty
                inputPass.pop_back(); //removes the last character
                cout<<"\b \b"; //moves curser back, print space to overwrite and move back
            }
        }
        else{
            inputPass.push_back(input); //adds character to this
            cout<<"*"; //print star to mask password
        }
        input = _getch();
    }
    cout<<endl;
    return inputPass;
}

//<-------------------------------Manager functionalities------------------------------->
//employee adding function
void addEmployee(string empUsername[],string empPwd[],string empName[], string empFname[], string empCellNo[],string empAddress[], string empCnic[], string empDOB[], char empGender[], bool isEmpExist[], int EmpSize,int &empCount){
    system("cls");
    setTextColor(14); cout << " ===================================" << endl;
    setTextColor(11); cout << "        --- Add a Employee ---      " << endl;
    setTextColor(14); cout << " ===================================" << endl;

    int day,month,year;
    if(empCount<EmpSize){
        for(int i=0; i<EmpSize; i++){
            if(!isEmpExist[i]){
                cout<<"Enter Username : ";
                getline(cin,empUsername[i]);
                cout<<"Enter Password : ";
                getline(cin,empPwd[i]);
                cout<<"Enter employee full name : ";
                getline(cin,empName[i]);
                cout<<"Enter employee father's name : ";
                getline(cin,empFname[i]);
                cout<<"Enter employee phone number : ";
                getline(cin,empCellNo[i]);
                cout<<"Enter employee cnic number : ";
                getline(cin,empCnic[i]);
                cout<<"Enter employee address : ";
                getline(cin,empAddress[i]);
                cout<<"Enter employee date of birth (DD-MM-YYYY): ";
                getline(cin,empDOB[i]);
                cout<<"Enter gender (M for male or F for Female): ";
                cin>>empGender[i];
                empCount++;
                isEmpExist[i] = true;
                setTextColor(10); //green
                cout << "\n\t\t\t\t\t\t\t\tEmployee added successfully......."<<endl;
                cin.ignore();
                cin.get();
                break;
            }
        }
    }
    else{
        setTextColor(12); //red
        cout<<"\n\tMaximum number of employees reached. Cannot add more employees!"<<endl;
        cin.get();
    }
}
//Uemp : 
void updateEmployee(string empUsername[],string empPwd[],string empName[], string empFname[], string empCellNo[],string empAddress[], string empCnic[], string empDOB[], char empGender[],bool isEmpExist[], int EmpSize,int &empCount){
    string username; //for searching by username 
    bool isUserFound = false; //checks if user found & data updated
    system("cls");
    setTextColor(14); cout << " ===================================" << endl;
    setTextColor(11); cout << "     --- Update Employee Data ---   " << endl;
    setTextColor(14); cout << " ===================================" << endl;
    if(empCount!=0){
        cout<<" Enter username of employee : ";
        cin>>username;
        for(int i=0; i<EmpSize; i++){
            if(username == empUsername[i]){
                cout<<"Enter updated Username : ";
                cin.ignore();
                getline(cin,empUsername[i]);
                cout<<"Enter new Password : ";
                getline(cin,empPwd[i]);
                cout<<"Enter employee full name : ";
                getline(cin,empName[i]);
                cout<<"Enter employee father's name : ";
                getline(cin,empFname[i]);
                cout<<"Enter employee phone number : ";
                getline(cin,empCellNo[i]);
                cout<<"Enter employee cnic number : ";
                getline(cin,empCnic[i]);
                cout<<"Enter employee address : ";
                getline(cin,empAddress[i]);
                cout<<"Enter employee date of birth (DD-MM-YYYY): ";
                getline(cin,empDOB[i]);
                cout<<"Enter gender (M for male or F for Female): ";
                cin>>empGender[i];
                isUserFound = true;
                setTextColor(10); //green
                cout << "\n\t\t\t\t\t\t\t\tEmployee data updated successfully......."<<endl;
                cin.get();
                break;
            }
        }
        if(!isUserFound){
            setTextColor(12); // Red 
            cout<<"\n  No user found!";
            cin.get();
        }
    }
    else{
        setTextColor(12); // Red 
        cout << "\nNo employee added yet!"<<endl;
    }
    cin.get();
}
void deleteEmployee(string empUsername[],string empPwd[],string empName[], string empFname[], string empCellNo[],string empAddress[], string empCnic[], string empDOB[], char empGender[],bool isEmpExist[], int EmpSize,int &empCount){
    string username; //for searching by username 
    bool isUserFound = false; //checks if user found & data deleted
    system("cls");
    setTextColor(14); cout << " ===================================" << endl;
    setTextColor(11); cout << "     --- Delete Employee Data ---   " << endl;
    setTextColor(14); cout << " ===================================" << endl;
    if(empCount!=0){
        cout<<" Enter username of employee : ";
        cin>>username;
        for(int i=0; i<EmpSize; i++){
            if(username == empUsername[i]){
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
                setTextColor(10); //green
                cout << "\n\t\t\t\t\t\t\t\tEmployee data deleted successfully......."<<endl;
                cin.get();
                break;
            }
        }
        if(!isUserFound){
            setTextColor(12); // Red 
            cout<<"\n No user found!";
            cin.get();
        }
    }
    else{
        setTextColor(12); // Red 
        cout << "\nNo employee added yet!"<<endl;
    }
    cin.get();    
}


//view employees
void viewEmployee(string empUsername[],string empPwd[],string empName[], string empFname[], string empCellNo[],string empAddress[], string empCnic[], string empDOB[], char empGender[],bool isEmpExist[], int EmpSize,int &empCount){
    system("cls");
    cout<<endl<<endl;
    setTextColor(14); cout << "\t\t\t\t\t\t\t\t===================================" << endl;
    setTextColor(11); cout << "\t\t\t\t\t\t\t\t     --- View all Employees ---    " << endl;
    setTextColor(14); cout << "\t\t\t\t\t\t\t\t===================================" << endl<<endl;
    cout<<left;
    cout<<" -----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout<<setw(7)<<" | No. "<<setw(13)<<"| Username"<<setw(13)<<"| Password"<<setw(16)<<"| Full Name"<<setw(16)<<"| Father Name"<<setw(15)<<"| Cell No"<<setw(19)<<"| CNIC"<<setw(15)<<"| DOB"<<setw(9)<<"| Gender"<<setw(44)<<"| Address"<<"|"<<endl;
    cout<<" -----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    if(empCount!=0){
        for(int i=0; i<EmpSize; i++){
            if(isEmpExist[i]){
                cout << " | " << setw(4) << i + 1 << "| "
                     << setw(11) << empUsername[i] << "| "
                     << setw(11) << empPwd[i] << "| "
                     << setw(14) << empName[i] << "| "
                     << setw(14) << empFname[i] << "| "
                     << setw(13) << empCellNo[i] << "| "
                     << setw(17) << empCnic[i] << "| "
                     << setw(13) << empDOB[i] << "| "
                     << setw(7) << empGender[i] << "| "
                     << setw(42) << empAddress[i] << "| " << endl;
            }
        }
        cout<<" -----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        
    }
    else{
        setTextColor(12); // Red 
        cout << "\n\tNo employee added yet!"<<endl;
    }
    cin.get();

}

//<-------------------------------inventry management---------------------------------->
//add mobiles
void addMobiles(string mobileBrand[],string mobileModel[],string mobileSpecs[],string mobileSupplierName[],string mobileColor[],   int mobileQty[],string mobileStorage[],double mobPurchasePrice[],double mobSalePrice[],int mobMinStockLevel[],double discount[],string status[],bool isMobileExist[],int MaxMobile){

}
//add accessories
void addAccessories( string accessoryName[],string accessorySpecs[],string accessorySupplier[],int accessoryQuantity[],double accessoryPurchasePrice[],double accessorySalePrice[],int accessoryMinStock[],double accessoryDiscount[],string accessoryStatus[],bool isAccessoryExist[],int MaxAccessory){

}

void addInventry(string mobileBrand[],string mobileModel[],string mobileSpecs[],string mobileSupplierName[],string mobileColor[],   int mobileQty[],string mobileStorage[],double mobPurchasePrice[],double mobSalePrice[],int mobMinStockLevel[],double discount[],string status[],bool isMobileExist[],int MaxMobile,int &inventryChoice, //accessories
string accessoryName[],string accessorySpecs[],string accessorySupplier[],int accessoryQuantity[],double accessoryPurchasePrice[],double accessorySalePrice[],int accessoryMinStock[],double accessoryDiscount[],string accessoryStatus[],bool isAccessoryExist[],int MaxAccessory
){
    system("cls");
    setTextColor(14); cout << " ===================================" << endl;
    setTextColor(11); cout << "        --- Add Inventory ---       " << endl;
    setTextColor(14); cout << " ===================================" << endl<<endl;
    setTextColor(14); cout << " 1. "; setTextColor(11); cout << "Add Mobile" << endl;
    setTextColor(14); cout << " 2. "; setTextColor(11); cout << "Add Accessory" << endl;
    setTextColor(14); cout << " 0. "; setTextColor(11); cout << "Exit" << endl;
    setTextColor(14); cout << " ===================================" << endl;
    do {
        inventryChoice = getValidDigitInput(); //assures valid input digit 0-9
        switch (inventryChoice) {
            case 1:{ //add mobile
                addMobiles(mobileBrand,mobileModel,mobileSpecs,mobileSupplierName,mobileColor,mobileQty,mobileStorage,mobPurchasePrice,mobSalePrice, mobMinStockLevel,discount,status,isMobileExist,MaxMobile);
                break;
            }  
            case 2:{ //add accessory
                addAccessories(accessoryName,accessorySpecs,accessorySupplier,accessoryQuantity,accessoryPurchasePrice,accessorySalePrice,accessoryMinStock,accessoryDiscount,accessoryStatus,isAccessoryExist, MaxAccessory);
                break;
            }
            case 0:{
                break;
            }
            default:{
                invalidErrorMessage();
            }
        }
    } while (inventryChoice!= 0);
    inventryChoice = -1;

}
//<-------------------------------interfaces functions---------------------------------->
void mainInterface() {
    system("cls"); // clears the screen
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
    cout << endl << endl;
    setTextColor(10); //light green
    cout << "\t\t\t\t\t\t\t\tChoose the desired option" << endl << endl;
    cout << "\t\t\t\t\t\t\t\t1. Manager Login" << endl;
    cout << "\t\t\t\t\t\t\t\t2. Employee Login" << endl;
    cout << "\t\t\t\t\t\t\t\t3. Customer Portal" << endl;
    cout << "\t\t\t\t\t\t\t\t0. Exit" << endl;
    cout << "\t\t\t\t\t\t\t\t*****************************" << endl;
}

//<-------------------------------MAnager interfaces functions---------------------------------->
void managerLoginHeader() {
    system("cls");
    setTextColor(14); cout << " ===================================" << endl;
    setTextColor(11); cout << "        --- Manager Login ---       " << endl;
    setTextColor(14); cout << " ===================================" << endl;
}

void managerMainMenu() {
    system("cls");
    setTextColor(14); cout << " ===================================" << endl;
    setTextColor(11); cout << "        --- Manager Portal ---      " << endl;
    setTextColor(14); cout << " ===================================" << endl;
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
    cout << "Reports" << endl;

    setTextColor(14);
    cout << " 0. ";
    setTextColor(11);
    cout << "Logout" << endl;

    setTextColor(14); // Light Yellow for border
    cout << " ===================================" << endl;
}

// Manager Inventory Management Interface
void inventryManagementHeader(){
    system("cls");
    setTextColor(14); cout << " ===================================" << endl;
    setTextColor(11); cout << "     --- Inventory Management ---   " << endl;
    setTextColor(14); cout << " ===================================" << endl;
}
void managerInventryManagement() {
    inventryManagementHeader();
    setTextColor(14); cout << " 1. "; setTextColor(11); cout << "Add Products" << endl;
    setTextColor(14); cout << " 2. "; setTextColor(11); cout << "Update Products" << endl;
    setTextColor(14); cout << " 3. "; setTextColor(11); cout << "Delete Products" << endl;
    setTextColor(14); cout << " 4. "; setTextColor(11); cout << "View All Products" << endl;
    setTextColor(14); cout << " 5. "; setTextColor(11); cout << "Check Stock Level" << endl;
    setTextColor(14); cout << " 0. "; setTextColor(11); cout << "Exit" << endl;

    setTextColor(14); cout << " ===================================" << endl;
}

// Manager Employee Management Interface

void employeeManagementHeader(){
    system("cls");
    setTextColor(14); cout << " ====================================" << endl;
    setTextColor(11); cout << "     --- Employee Management ---     " << endl;
    setTextColor(14); cout << " ====================================" << endl;
}
void managerEmployeeManagement() {
    employeeManagementHeader();
    setTextColor(14); cout << " 1. "; setTextColor(11); cout << "Add Employee" << endl;
    setTextColor(14); cout << " 2. "; setTextColor(11); cout << "Update Employee Data" << endl;
    setTextColor(14); cout << " 3. "; setTextColor(11); cout << "Delete Employee" << endl;
    setTextColor(14); cout << " 4. "; setTextColor(11); cout << "View All Employees" << endl;
    setTextColor(14); cout << " 0. "; setTextColor(11); cout << "Exit" << endl;

    setTextColor(14); cout << " ====================================" << endl;
}

// Manager Customer Management Interface
void customerManagementHeader(){
    system("cls");
    setTextColor(14); cout << " ====================================" << endl;
    setTextColor(11); cout << "     --- Customer Management ---     " << endl;
    setTextColor(14); cout << " ====================================" << endl;
}
void managerCustomerManagement() {
    customerManagementHeader();
    setTextColor(14); cout << " 1. "; setTextColor(11); cout << "View All Customers" << endl;
    setTextColor(14); cout << " 2. "; setTextColor(11); cout << "Delete Customer Account" << endl;
    setTextColor(14); cout << " 3. "; setTextColor(11); cout << "View Purchase History" << endl;
    setTextColor(14); cout << " 0. "; setTextColor(11); cout << "Exit" << endl;

    setTextColor(14); cout << " ====================================" << endl;
}

// Manager Order Management Interface
void orderManagementHeader(){
    system("cls");
    setTextColor(14); cout << " ====================================" << endl;
    setTextColor(11); cout << "       --- Order Management ---      " << endl;
    setTextColor(14); cout << " ====================================" << endl;
}
void managerOrderManagement() {
    orderManagementHeader();
    setTextColor(14); cout << " 1. "; setTextColor(11); cout << "View All Orders" << endl;
    setTextColor(14); cout << " 2. "; setTextColor(11); cout << "Update Order Status" << endl;
    setTextColor(14); cout << " 3. "; setTextColor(11); cout << "Cancel Orders" << endl;
    setTextColor(14); cout << " 0. "; setTextColor(11); cout << "Exit" << endl;

    setTextColor(14); cout << " ====================================" << endl;
}

//<-------------------------------Employee interfaces functions---------------------------------->
// Employee Login Header
void employeeLoginHeader() {
    system("cls");
    setTextColor(14); cout << " ===================================" << endl;
    setTextColor(11); cout << "       --- Employee Login ---       " << endl;
    setTextColor(14); cout << " ===================================" << endl;
}

// Employee Main Menu
void employeeMainMenu() {
    system("cls");
    setTextColor(14); cout << " ===================================" << endl;
    setTextColor(11); cout << "       --- Employee Portal ---      " << endl;
    setTextColor(14); cout << " ===================================" << endl;

    setTextColor(14); cout << " 1. "; setTextColor(11); cout << "Inventory Management" << endl;
    setTextColor(14); cout << " 2. "; setTextColor(11); cout << "Customer Management" << endl;
    setTextColor(14); cout << " 3. "; setTextColor(11); cout << "Order Management" << endl;
    setTextColor(14); cout << " 4. "; setTextColor(11); cout << "Notifications" << endl;
    setTextColor(14); cout << " 0. "; setTextColor(11); cout << "Logout" << endl;

    setTextColor(14); cout << " ===================================" << endl;
}
void employeeInventryManagement() {
    inventryManagementHeader();
    setTextColor(14); cout << " 1. "; setTextColor(11); cout << "Add Products" << endl;
    setTextColor(14); cout << " 2. "; setTextColor(11); cout << "Update Products" << endl;
    setTextColor(14); cout << " 3. "; setTextColor(11); cout << "View All Products" << endl;
    setTextColor(14); cout << " 4. "; setTextColor(11); cout << "Check Stock Level" << endl;
    setTextColor(14); cout << " 0. "; setTextColor(11); cout << "Exit" << endl;

    setTextColor(14); cout << " ===================================" << endl;
}

void employeeCustomerManagement() {
    customerManagementHeader();
    setTextColor(14); cout << " 1. "; setTextColor(11); cout << "View All Customers" << endl;
    setTextColor(14); cout << " 2. "; setTextColor(11); cout << "View Purchase History" << endl;
    setTextColor(14); cout << " 0. "; setTextColor(11); cout << "Exit" << endl;

    setTextColor(14); cout << " ====================================" << endl;
}

void employeeOrderManagement() {
    orderManagementHeader();
    setTextColor(14); cout << " 1. "; setTextColor(11); cout << "View All Orders" << endl;
    setTextColor(14); cout << " 2. "; setTextColor(11); cout << "Update Order Status" << endl;
    setTextColor(14); cout << " 3. "; setTextColor(11); cout << "Cancel Orders" << endl;
    setTextColor(14); cout << " 0. "; setTextColor(11); cout << "Exit" << endl;

    setTextColor(14); cout << " ====================================" << endl;
}

//<-------------------------------Customer interfaces functions---------------------------------->
// Customer Portal
void customerPortalHeader(){
    system("cls");
    setTextColor(14); cout << " ===================================" << endl;
    setTextColor(11); cout << "       --- Customer Portal ---      " << endl;
    setTextColor(14); cout << " ===================================" << endl;
}

void customerPortal() {
    customerPortalHeader(); //shows customer portal header
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

void customerProfileMenu() {
    customerPortalHeader(); //shows customer portal header

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

void customerWithoutLoginMenu() {
    customerPortalHeader(); //shows customer portal header

    setTextColor(14); 
    cout << " 1. "; 
    setTextColor(11); 
    cout << "View Available Items" << endl;
    setTextColor(14); 
    cout << " 2. "; 
    setTextColor(11); 
    cout << "Place an Order (Limited)" << endl; 
    setTextColor(14); 
    cout << " 3. "; 
    setTextColor(11); 
    cout << "Order Tracking (Limited)" << endl; 
    setTextColor(14); 
    cout << " 0. "; 
    setTextColor(11); 
    cout << "Exit" << endl;
    setTextColor(14); 
    cout << " ===================================" << endl;
}

