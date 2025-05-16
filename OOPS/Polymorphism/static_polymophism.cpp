#include<iostream>
#include<string>

using namespace std;

class ManualCar{
    private:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;

    public: 
        ManualCar(string brand, string model){
            this->brand = brand;
            this->model = model;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
        }

        void startEngine(){
            isEngineOn = true;
            cout << brand << " " << model << " : Engine Started ." << endl;
        }

        void stopEngine(){
            isEngineOn = false;
            cout << brand << " " << model << " : Engine Stopped ." << endl;
        }

        // Method Overloading
        void accelerate() {
            if (!isEngineOn){
                cout << brand << " " << model << " : Engine is not started. Please start the engine first." << endl;
                return;
            }
            currentSpeed += 20;
            cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
        }

        void accelerate(int speed){
            if (!isEngineOn){
                cout << brand << " " << model << " : Engine is not started. Please start the engine first." << endl;
                return;
            }
            currentSpeed += speed;
            cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
        }

        void brake(){
            currentSpeed -= 20;
            if (currentSpeed < 0) currentSpeed = 0;
            cout << brand << " " << model << " : Braking ! Speed is now " << currentSpeed << " km/h" << endl; 
        }

        void shiftGear(int gear){
            currentGear = gear;
            cout << brand << " " << model << " : shifted to gear " << currentGear << endl;
        }
};

int main(){
    ManualCar* myCar = new ManualCar("Toyota", "Corolla");
    myCar->startEngine();
    myCar->accelerate();
    myCar->accelerate(40);
    myCar->brake();
    myCar->stopEngine();

    delete myCar;
    return 0;
}