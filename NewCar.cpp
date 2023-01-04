#include "NewCar.h"
#include <string>

void NewCar :: setProvider(string provider){
    Provider = provider;
}
string NewCar :: getProvider(){
    return Provider;
}
const float NewCar :: getMileage(){
    return Mileage;
}
NewCar :: NewCar(){
    Provider = " ";
    const float Mileage = 0.0;
}
NewCar :: NewCar(string vin, int year, string make, string model, float mileage, float price, string provider):
Car(vin, year, make, model, price){
    Provider = provider;
    const float Mileage = mileage;
}