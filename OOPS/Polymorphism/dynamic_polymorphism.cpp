#include<iostream>
#include<string>

using namespace std;

class Car{
    protected:
        string brand;
        string model;
        int isEngineOn;
        int currentSpeed;

    public:
        Car(string b,string m){
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
        }

        void startEngine() {
            isEngineOn = true;
            cout << brand << " " << model << " : Engine Started !" << endl;
        }

        void stopEngine() {
            isEngineOn = false;
            cout << brand << " " << model << " : Engine Stopped !" << endl;
        }

        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual ~Car() {}
};

class ManualCar : public Car {
    private:
        int currentGear;
    
    public:
        ManualCar(string b,string m) : Car(b,m){
            currentGear = 0;
        }

        void shiftGear(int gear){
            currentGear = gear;
            cout << brand << " " << model << " : Gear shifted to " << gear << endl;
        }

        void accelerate(){
            if (!isEngineOn){
                cout << brand << " " << model << " : Engine is not started !" << endl;
                return;
            }
            currentSpeed += 20;
            cout << brand << " " << model << " : Accelerating... Current Speed : " << currentSpeed << endl;
        }

        void brake(){
            if (!isEngineOn){
                cout << brand << " " << model << " : Engine is not started !" << endl;
                return;
            }
            currentSpeed -= 10;
            cout << brand << " " << model << " : Braking... Current Speed : " << currentSpeed << endl;
        }

        ~ManualCar() {}
};

class ElectricCar : public Car { 
    private:
        int batteryLevel;
    
    public:
        ElectricCar(string b,string m) : Car(b,m){
            batteryLevel = 100;
        }

        void accelerate(){
            if (!isEngineOn){
                cout << brand << " " << model << " : Engine is Off !" << endl;
                return;
            }
            if (batteryLevel <= 0) {
                cout << brand << " " << model << " : Battery Over ! " << endl;
                return;
            }
            batteryLevel -= 10;
            currentSpeed += 20;
            cout << brand << " " << model << " : Accelerating... Current Speed : " << currentSpeed << " km/h. Battery at " << batteryLevel << " %" << endl;
        }

        void brake(){
            if (!isEngineOn){
                cout << brand << " " << model << " : Engine is Off !" << endl;
                return;
            }
            currentSpeed -= 15;
            if (currentSpeed < 0) currentSpeed = 0;
            batteryLevel += 5;
            cout << brand << " " << model << " : Regentrative Braking ! Speed is now " << currentSpeed << " km/h. Battery at " << batteryLevel << " %" << endl;
        }
        ~ElectricCar() {}
};

int main(){
    ManualCar* myManualCar = new ManualCar("Toyota","Corrola");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();

    delete myManualCar;

    cout << "----------------------------------" << endl;

    ElectricCar* myElectricCar = new ElectricCar("Tesla","Model S");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->brake();
    myElectricCar->stopEngine();

    delete myElectricCar;
}