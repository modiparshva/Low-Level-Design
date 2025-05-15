#include<iostream>
#include<string>

using namespace std;

class Car{
    public:
        virtual void startEngine() = 0;
        virtual void shiftGear(int gear) = 0;
        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual void stopEngine() = 0;
        virtual ~Car() {}
};

class sportsCar : public Car{
    public:
// Characters

        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;

// Constructor

        sportsCar(string b,string m){
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
        }

// Behavoiurs

        void startEngine() {
            isEngineOn = true;
            cout << brand << " " << model << " : Engine Started ! " << endl; 
        }

        void shiftGear(int gear) {
            if (!isEngineOn) {
                cout << brand << " " << model << " : Engine is not started. Please start the engine first." << endl;
            }  
            currentGear = gear;
            cout << brand << " " << model << " : shifted to gear " << currentGear << endl;
        }

        void accelerate() {
            if (!isEngineOn) {
                cout << brand << " " << model << " : Engine is not started. Please start the engine first." << endl;
            }

            currentSpeed += 20;
            cout << brand << " " << model << " : Accelerating at " << currentSpeed << endl;
        }

        void brake() {
            if (!isEngineOn) {
                cout << brand << " " << model << " : Engine is not started. Please start the engine first." << endl;
            }
            currentSpeed -= 10;
            cout << brand << " " << model << " : Braking at " << currentSpeed << endl;
        }

        void stopEngine() {
            if (!isEngineOn) {
                cout << brand << " " << model << " : Engine is already stopped." << endl;
            }
            isEngineOn = false;
            cout << brand << " " << model << " : Engine stopped !" << endl;
        }
};