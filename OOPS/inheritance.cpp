#include<iostream>
#include<string>
using namespace std;

class Car {
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;

    public:
        Car(string b,string m){
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
        }

        void startEngine(){
            isEngineOn = true;
            cout << brand << " " << model << " : Engine Started ." << endl;
        }

        void stopEngine(){
            if (!isEngineOn){
                cout << brand << " " << model << " : Engine is already stopped." << endl;
            }
            isEngineOn = false;
            cout << brand << " " << model << " : Engine Stopped ." << endl;
        }

        void accelerate(){
            if (!isEngineOn){
                cout << brand << " " << model << " : Engine is not started." << endl;
                return;
            }
            currentSpeed += 20;
            cout << brand << " " << model << " : Accelerated to " << currentSpeed << " km/h" << endl;
        }

        void brake(){
            if (!isEngineOn){
                cout << brand << " " << model << " : Engine is not started." << endl;
            }
            if (currentSpeed > 10){
                currentSpeed -= 20;
                cout << brand << " " << model << " : Braked to " << currentSpeed << " km/h" << endl;
            }
        }
        
        virtual ~Car() {}
};

class ManualCar : public Car{
    private:
        int currentGear;
    public:
        ManualCar(string b,string m) : Car(b,m){
            currentGear = 0;
        }

        void shiftGear(int gear){
            currentGear = gear;
            cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
        }
};

class ElectricCar : public Car{
    private:
        int batteryLevel;
    public:
        ElectricCar(string b,string m) : Car(b,m){
            batteryLevel = 100;
        }

        void chargedBattery(){
            batteryLevel = 100;
            cout << brand << " " << model << " : Battery Fully Charged !" << endl;
        }
};  

int main(){
    ManualCar* manualCar = new ManualCar("Toyota", "Corolla");
    manualCar->startEngine();
    manualCar->shiftGear(1);
    manualCar->accelerate();
    manualCar->brake();
    manualCar->stopEngine();

    delete manualCar;

    cout << "--------------------------" << endl;

    ElectricCar electricCar("Tesla", "Model S");
    electricCar.startEngine();
    electricCar.accelerate();
    electricCar.brake();
    electricCar.stopEngine();
    electricCar.chargedBattery();

    delete &electricCar;

    return 0;
}