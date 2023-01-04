#include "Car.h"
#include <string>

class OldCar:
    public Car{
        private:
        float Mileage;
        public:
        void setMileage(float mileage);
        float getMileage();
        OldCar();
        OldCar(string vin, int year, string make, string model, float price, float mileage);
        
    };