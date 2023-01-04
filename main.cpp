#include <iostream>
using namespace std;
#include "NewCar.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include<algorithm>

#include <cctype>

//Menu function
int menu(){
    int menuselect;
    cout << "\n \t \tIdiots Scholar Dealership!!! \t \t" << endl;
    cout << endl;
    cout << "1. Search inventory \t \t" << "2. Sell/ lease cars" << endl;
    cout << "3. Return leased Car \t \t" << "4. Add car to inventory"  << endl;
    cout << endl;
    cout << "\t \t \t 5. Exit \t" << endl;
    cout << endl;
    cout << "Enter the option : ";
    cin >> menuselect;
    cout << endl;
    return menuselect;
}

//void search(int input);
void search(){
    int searchOption;
    cout << "1. By VIN \t \t" << "2. By Make " << endl;
    cout << "3. By Model \t \t" << "4. By Price " << endl;
    cout << endl;
    cout << "Choose search option : ";
    cin >> searchOption;
    
    ifstream inNewcar("NewCar.txt");
    ifstream inOldcar("OldCar.txt");
    string line, searchVIN, vinFromText;
    string searchMake, makeFromText;
    string searchModel, modelFromText;
    int searchYear, yearFromText;
    float searchPrice, priceFromText;
    float searchMile, mileFromText;
    string searchProvider, ProviderFromText;
    Car carobj;
    NewCar newcarobj;
    size_t textRead;
    int count = 0;
    
    
        switch(searchOption){
            
            case 1:
            cout << "\n Enter VIN to find car : ";
            cin >> searchVIN;
            transform(searchVIN.begin(), searchVIN.end(), searchVIN.begin(), :: toupper);
            //carobj.setVIN(searchVIN);
            while(inOldcar >> vinFromText >> yearFromText >> makeFromText >> modelFromText >>
            mileFromText >> priceFromText >> ProviderFromText){
                if(vinFromText == searchVIN){
                    OldCar oldcarobj(vinFromText, yearFromText, makeFromText, modelFromText, mileFromText, priceFromText);
                    
                    cout << oldcarobj.getVIN() << " " << oldcarobj.getYear() << " " << oldcarobj.getMake() << " " <<
                    oldcarobj.getModel() << " " << oldcarobj.getMileage() << " " << oldcarobj.getPrice() << " " <<
                    "No Provider" << endl;
                    count++;
                    break;
                }
            }
            
            while(inNewcar >> vinFromText >> yearFromText >> makeFromText >> modelFromText >>
            mileFromText >> priceFromText >> ProviderFromText){
                if(vinFromText == searchVIN){
                    NewCar newcarobj(vinFromText, yearFromText, makeFromText, modelFromText,
                    mileFromText, priceFromText, ProviderFromText);
                    
                    cout << newcarobj.getVIN() << " " << newcarobj.getYear() << " " << newcarobj.getMake() << " " <<
                    newcarobj.getModel() << " " << newcarobj.getMileage() << " " << newcarobj.getPrice() << " " <<
                    newcarobj.getProvider() << " " << endl;
                    count++;
                    //break;
                }
            }
            if(count == 0){
                cout << "Car not found." << endl;
                //break;
            }
        
            
            break;
            
            case 2:
            cout << "\n Enter make to find cars : ";
        
            cin >> searchMake;
        
            transform(searchMake.begin(), searchMake.end(), searchMake.begin(), :: toupper);
            carobj.setMake(searchMake);
        
            while(inOldcar.good()){
                getline(inOldcar, line);
                textRead = line.find(carobj.getMake());
                if(textRead != string :: npos){
                    cout << line << endl;
                    count++;
            }
                else if(inNewcar.good()){
                    getline(inNewcar, line);
                    textRead = line.find(carobj.getMake());
                    if(textRead != string :: npos){
                        cout << line << endl;
                        count++;
                }
            }
        }
            if(count == 0){
                cout << "Car not found.\n" << endl;
        }
        
            break;
            
            case 3:
            cout << "\n Enter model to find cars : ";
            cin >> searchModel;
            transform(searchModel.begin(), searchModel.end(), searchModel.begin(), :: toupper);
            carobj.setModel(searchModel);
        
            while(inOldcar.good()){
                getline(inOldcar, line);
                textRead = line.find(carobj.getModel());
                if(textRead != string :: npos){
                    cout << line << endl;
                    count++;
            }
                else if(inNewcar.good()){
                    getline(inNewcar, line);
                    textRead = line.find(carobj.getModel());
                    if(textRead != string :: npos){
                        cout << line << endl;
                        count++;
                }
            }
        }
    
            if(count == 0){
                cout << "Car not found.\n" << endl;
    }

            break;
            
            case 4:
            cout << "\n Enter Max price : ";
            cin >> searchPrice;
            carobj.setPrice(searchPrice);
            
            while(inOldcar >> vinFromText >> yearFromText >> makeFromText >> modelFromText >>
            mileFromText >> priceFromText >> ProviderFromText){
                if(priceFromText <= searchPrice){
                
                    OldCar oldcarpriceobj(vinFromText, yearFromText, makeFromText, modelFromText, mileFromText, priceFromText);
                    
                    cout << oldcarpriceobj.getVIN() << " " << oldcarpriceobj.getYear() << " " <<
                    oldcarpriceobj.getMake() << " " << oldcarpriceobj.getModel() << " " << 
                    oldcarpriceobj.getMileage() << " " << oldcarpriceobj.getPrice() << " " << "No Provider" << endl;
                    count++;
                    //break;
                }
            }
            
            while(inNewcar >> vinFromText >> yearFromText >> makeFromText >> modelFromText >>
            mileFromText >> priceFromText >> ProviderFromText){
                if(priceFromText <= searchPrice){
                    
                    NewCar newcarpriceobj(vinFromText, yearFromText, makeFromText, modelFromText, mileFromText, priceFromText, ProviderFromText);
                    
                    cout << newcarpriceobj.getVIN() << " " << newcarpriceobj.getYear() << " " <<
                    newcarpriceobj.getMake() << " " << newcarpriceobj.getModel() << " " << 
                    newcarpriceobj.getMileage() << " " << newcarpriceobj.getPrice() << " " <<
                    newcarpriceobj.getProvider() << " " << endl;
                    count++;
                    //break;
                }
            }
            if(count == 0){
            cout << "Car not found.\n" << endl;
    }
            
            break;
            }
            
}
    // Old search function



//fourth search done
//}

void SelloldCar();
void SellNewCar();
void leaseNewcar();

void SellorLease(){
    int userinput;
    cout << "\n Wanna make a purchase ?" << endl;
    cout << "1. Sell a car. \t \t" << "2. Lease a car." << endl;
    cin >> userinput;
    
    switch(userinput){
        case 1:
        cout << "\n Selling old car or new car?" << endl;
        cout << "1. New car. \t \t" << "2. Old car." << endl;
        int sellcar;
        cin >> sellcar;
        if(sellcar == 1){
            SellNewCar();
        }
        else if(sellcar == 2){
            SelloldCar();
        }
        break;
    
        case 2:
        cout << "1. Lease new car " << endl;
        cout << "Enter 1 to lease : ";
        int leasecar;
        cin >> leasecar;
        if(leasecar == 1){
            leaseNewcar();
        }
        break;
    
}

}



//SelloldCar function

void SelloldCar(){
    ifstream inOldcar;
    string path = "OldCar.txt";
    inOldcar.open(path);
    ofstream temp("OldoutFile.txt");
    string line, searchVIN, vinFromText;
    string searchMake, makeFromText;
    string searchModel, modelFromText;
    int searchYear, yearFromText;
    float searchPrice, priceFromText;
    float searchMile, mileFromText;
    string searchProvider, ProviderFromText;
    Car carobj;
    NewCar newcarobj;
    size_t textRead;
    int count = 0;
    
    cout << "Enter VIN : ";
    cin >> searchVIN;
    
    while(inOldcar >> vinFromText >> yearFromText >> makeFromText >> modelFromText >>
            mileFromText >> priceFromText >> ProviderFromText){
        if(searchVIN == vinFromText){
            count++;
        }
        else if(searchVIN != vinFromText){
            OldCar oldcarobj(vinFromText, yearFromText, makeFromText, modelFromText, mileFromText, priceFromText);
            temp << oldcarobj.getVIN() << " " << oldcarobj.getYear() << oldcarobj.getMake() <<
            " " << oldcarobj.getModel() << " " << oldcarobj.getMileage() << " " <<
            oldcarobj.getPrice() << " " << "NA" << endl;
        }
        
    }
    if(count == 0){
        cout << "Car not found. " << endl;
    }
    temp.close();
    inOldcar.close();
    const char *tempfile = path.c_str();
    remove(tempfile);
    rename("OldoutFile.txt", tempfile);
}

//SellNewCar function

void SellNewCar(){
    ifstream inNewcar;
    string path1 = "NewCar.txt";
    inNewcar.open(path1);
    ofstream temp1("NewoutFile.txt");
    string line, searchVIN, vinFromText;
    string searchMake, makeFromText;
    string searchModel, modelFromText;
    int searchYear, yearFromText;
    float searchPrice, priceFromText;
    float searchMile, mileFromText;
    string searchProvider, ProviderFromText;
    Car carobj;
    NewCar newcarobj;
    size_t textRead;
    int count = 0;
    
    cout << "Enter VIN : ";
    cin >> searchVIN;
    
    while(inNewcar >> vinFromText >> yearFromText >> makeFromText >> modelFromText >>
            mileFromText >> priceFromText >> ProviderFromText){
        if(searchVIN == vinFromText){
            count++;
        }
        else if(searchVIN != vinFromText){
            NewCar newcarobj(vinFromText, yearFromText, makeFromText, modelFromText, mileFromText, priceFromText, ProviderFromText);
            temp1 << newcarobj.getVIN() << " " << newcarobj.getYear() << " " << newcarobj.getMake() <<
            " " << newcarobj.getModel() << " " << newcarobj.getMileage() << " " << newcarobj.getPrice() <<
            " " << newcarobj.getProvider() << endl;
        }
    }
    if(count == 0){
        cout << "Car not found. " << endl;
    }
    temp1.close();
    inNewcar.close();
    const char *tempfile1 = path1.c_str();
    remove(tempfile1);
    rename("NewoutFile.txt", tempfile1);
}

// end of sell function


// Lease a new car function

void leaseNewcar(){
    ifstream inNewcar;
    string path = "NewCar.txt";
    inNewcar.open(path);
    ofstream temp("NewoutFile.txt");
    ofstream OutLease("LeaseList.txt", ios :: in | ios :: out | ios :: ate);
    string line, searchVIN, vinFromText;
    string searchMake, makeFromText;
    string searchModel, modelFromText;
    int searchYear = 0, yearFromText;
    float searchPrice = 0, priceFromText;
    float searchMile = 0, mileFromText;
    string searchProvider, ProviderFromText;
    int count = 0;
    
    cout << "Enter VIN : ";
    cin >> searchVIN;
    
    while(inNewcar >> vinFromText >> yearFromText >> makeFromText >> modelFromText
    >> mileFromText >> priceFromText >> ProviderFromText){
        if(vinFromText == searchVIN){
            NewCar newcarobj(vinFromText, yearFromText, makeFromText, modelFromText, mileFromText, priceFromText, ProviderFromText);
            
                OutLease << newcarobj.getVIN() << " " << newcarobj.getYear() << " " << newcarobj.getMake() <<
                " " << newcarobj.getModel() << " " << newcarobj.getMileage() << " " << newcarobj.getPrice() << 
                " " << newcarobj.getProvider() << endl;
                cout << "Lease process succeed. " << endl;
                count++;
            
        }
        else{
            NewCar newcarobj(vinFromText, yearFromText, makeFromText, modelFromText, mileFromText, priceFromText, ProviderFromText);
            temp << newcarobj.getVIN() << " " << newcarobj.getYear() << " " << newcarobj.getMake() <<
            " " << newcarobj.getModel() << " " << newcarobj.getMileage() << " " << newcarobj.getPrice() << 
            " " << newcarobj.getProvider() << endl;

        }
    }
    if(count == 0){
        cout << "Car not found. " << endl;
    }
    temp.close();
    OutLease.close();
    inNewcar.close();
    const char *tempfile = path.c_str();
    remove(tempfile);
    rename("NewoutFile.txt", tempfile);
}
// end of SellorLease function




void ReturnCar(){
    ifstream LeaseList;
    string path = "LeaseList.txt";
    LeaseList.open(path);
    ofstream temp("NewoutFile.txt");
    //ofstream newList;
    //ifstream newList1;
    ofstream newList("NewCar.txt", ios :: in | ios :: out | ios :: ate);
    ofstream newList1("NewCar.txt", ios :: in | ios :: out | ios :: ate);
    string line, searchVIN, vinFromText;
    string searchMake, makeFromText;
    string searchModel, modelFromText;
    int searchYear, yearFromText;
    float searchPrice, priceFromText;
    float searchMile, mileFromText;
    string searchProvider, ProviderFromText;
    int count = 0;
    
    cout << "Enter VIN : ";
    cin >> searchVIN;
    
    while(LeaseList >> vinFromText >> yearFromText >> makeFromText >> modelFromText >>
            mileFromText >> priceFromText >> ProviderFromText){
        if(searchVIN == vinFromText){
            NewCar newcarobj(vinFromText, yearFromText, makeFromText, modelFromText, mileFromText, priceFromText, ProviderFromText);
            newList << newcarobj.getVIN() << " " << newcarobj.getYear() << " " << newcarobj.getMake() <<
            " " << newcarobj.getModel() << " " << newcarobj.getMileage() << " " << newcarobj.getPrice() << " " << newcarobj.getProvider()
            << " " << endl;
            count++;
            cout << "Returned." << endl;
        }
        
        //newList.close();
        //newList1.close();
    }
    if(count == 0){
        cout << "Car not found. " << endl;
    }
    //newList.close();
    temp.close();
    newList1.close();
    LeaseList.close();
    
    const char *tempfile = path.c_str();
    remove(tempfile);
    rename("NewoutFile.txt", tempfile);
    
    
}



void AddNewCar();
void AddOldCar();

void AddCar(){
    int optionforAddCar;
    cout << "Select the option below to add old or new car. \n" << endl;
    cout << "1. New car. \t \t " << "2. Old car. " << endl << endl;
    cout << "Enter your option : ";
    cin >> optionforAddCar;
    
    switch(optionforAddCar){
        case 1:
        AddNewCar();
        break;
        case 2:
        AddOldCar();
        break;
    }
}

void AddNewCar(){
    ifstream inOldcar("OldCar.txt");
    ifstream inNewcar("NewCar.txt");
    ofstream OutLease;
    ifstream InLease;
    InLease.open("NewCar.txt");
    OutLease.open("NewCar.txt", ios :: app);
    string line, searchVIN, vinFromText;
    string searchMake, makeFromText;
    string searchModel, modelFromText;
    int searchYear, yearFromText;
    float searchPrice, priceFromText;
    float searchMile, mileFromText;
    string searchProvider, ProviderFromText;
    //Car carobj;
    //NewCar newcarobj;
    size_t textRead;
    int count = 0;
    float defaultMileage = 0;
    
    cout << "\n Enter VIN : ";
    cin >> searchVIN;
    transform(searchVIN.begin(), searchVIN.end(), searchVIN.begin(), :: toupper);
    while(inOldcar >> vinFromText >> yearFromText >> makeFromText >> modelFromText >> 
    priceFromText >> mileFromText >> ProviderFromText || inNewcar >> vinFromText >> 
    yearFromText >> makeFromText >> modelFromText >> priceFromText >> mileFromText >> ProviderFromText){
        if(searchVIN == vinFromText){
            cout << "Car exist in inventory " << endl;
            //break a kam kore na tey exit(1) dis
            //break;
            exit(1);
        }
    }
    cout << "Enter year : ";
    cin >> searchYear;
    cout << "Enter Make : ";
    cin >> searchMake;
    transform(searchMake.begin(), searchMake.end(), searchMake.begin(), :: toupper);
    cout << "Enter Model : ";
    cin >> searchModel;
    transform(searchModel.begin(), searchModel.end(), searchModel.begin(), :: toupper);
    cout << "Enter Price : ";
    cin >> searchPrice;
    cout << "Mileage is 0 by default." << endl;
    cout << "Enter Provider : ";
    cin >> searchProvider;
    transform(searchProvider.begin(), searchProvider.end(), searchProvider.begin(), :: toupper);
    
    if(InLease.is_open()){
        OutLease << searchVIN << " " << searchYear << " " << searchMake << " " <<
        searchModel << " " << defaultMileage << " " << searchPrice << " " <<
        searchProvider << endl;
        
        InLease.close();
        OutLease.close();
    }
    
}

// Add old Car

void AddOldCar(){
    ifstream inOldcar("OldCar.txt");
    ifstream inNewCar("NewCar.txt");
    ofstream OutLease;
    ifstream InLease;
    InLease.open("OldCar.txt");
    OutLease.open("OldCar.txt", ios :: app);
    string line, searchVIN, vinFromText;
    string searchMake, makeFromText;
    string searchModel, modelFromText;
    int searchYear, yearFromText;
    float searchPrice = 0.0, priceFromText;
    float searchMile = 0.0, mileFromText;
    string searchProvider, ProviderFromText;
    size_t textRead;
    int count = 0;
    string defaultProvider = "NA";
    
    cout << "Enter VIN : ";
    cin >> searchVIN;
    while(inOldcar >> vinFromText >> yearFromText >> makeFromText >> modelFromText >> 
    priceFromText >> mileFromText >> ProviderFromText || inNewCar >> vinFromText >> 
    yearFromText >> makeFromText >> modelFromText >> priceFromText >> mileFromText >> ProviderFromText){
        if(searchVIN == vinFromText){
            cout << "Car exist in inventory. " << endl;
            //break;
            exit(1);
        }
    }
    cout << "Enter year : ";
    cin >> searchYear;
    cout << "Enter Make : ";
    cin >> searchMake;
    transform(searchMake.begin(), searchMake.end(), searchMake.begin(), :: toupper);
    cout << "Enter Model : ";
    cin >> searchModel;
    transform(searchModel.begin(), searchModel.end(), searchModel.begin(), :: toupper);
    cout << "Enter Price : ";
    cin >> searchPrice;
    cout << "Enter Mileage : ";
    cin >> searchMile;
    cout << "Provider for old car is NA by default." << endl;
    
    if(InLease.is_open()){
        OutLease << searchVIN << " " << searchYear << " " << searchMake << " " <<
        searchModel << " " << searchPrice << " " << searchMile << " " <<
        defaultProvider << endl;
        InLease.close();
        OutLease.close();
        
    }
}









//Main function needs edit
int main(){
    
    int userentry = menu();
    while (userentry != 5){
        switch (userentry){
        case 1:
            search();
            break;
        case 2:
            SellorLease();
            break;
        case 3:
            ReturnCar();
            break;
        case 4:
            AddCar();
            break;
        
        }
         
        userentry = menu();
    }


    }

    