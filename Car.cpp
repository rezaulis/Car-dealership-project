#include "Car.h"
#include <string>

void Car :: setVIN(string vin){
    VIN = vin;
}
void Car :: setMake(string make){
    Make = make;
}
void Car :: setModel(string model){
    Model = model;
}
void Car :: setYear(int year){
    Year = year;
}
void Car :: setPrice(float price){
    Price = price;
}
void Car :: setCategory(string category){
    Category = category;
}
string Car :: getVIN(){
    return VIN;
}
string Car :: getMake(){
    return Make;
}
string Car :: getModel(){
    return Model;
}
int Car :: getYear(){
    return Year;
}
float Car :: getPrice(){
    return Price;
}
string Car :: getCategory(){
    return Category;
}
Car :: Car(){
    VIN = " ";
    Make = " ";
    Model = " ";
    Year = 0;
    Price = 0.0;
    //Category = " ";
}
Car :: Car(string vin, int year, string make, string model, float price){
    VIN = vin;
    Make = make;
    Model = model;
    Year = year;
    Price = price;
    //Category = category;
}












