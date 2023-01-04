#include "OldCar.h"
#include <string>

class NewCar:
    public Car{
        private:
        string Provider;
        const float Mileage = 0.0;
        public:
        void setProvider(string provider);
        string getProvider();
        const float getMileage();
        NewCar();
        NewCar(string vin, int year, string make, string model, float price, float mileage, string provider);
        
    };