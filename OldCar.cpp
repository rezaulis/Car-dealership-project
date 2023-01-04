#include "OldCar.h"
#include <string>

void OldCar :: setMileage(float mileage){
    Mileage = mileage;
}
float OldCar :: getMileage(){
    return Mileage;
}
OldCar :: OldCar(){
    Mileage = 0.0;
}
OldCar :: OldCar(string vin, int year, string make, string model, float mileage, float price):
Car(vin,  year, make, model, price){
    Mileage = mileage;
}