#include<iostream>
#include<string>

using namespace std;

class sportsCar {
    private:
// Characters
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;
        string tyre;

// Constructor
    public:
        sportsCar(string b,string m){
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
            tyre = "MRF";
        }

// Getters and Setters
        int getCurrentSpeed(){
            return this->currentSpeed;
        }

        string getTyreName(){
            return this->tyre;
        }

        string setTyreName(string tyre){
            this->tyre = tyre;
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

        ~sportsCar() {}
};

int main(){
    sportsCar* myCar = new sportsCar("Ford","Mustang");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();
    myCar->shiftGear(0);
    myCar->brake();

    //setting arbitary value to speed
    // myCar->currentSpeed = 500;
    // cout << "Current Speed of Car is :" << myCar->currentSpeed << endl;

    cout << "Current Speed : " << myCar->getCurrentSpeed() << endl;
    delete myCar;

    return 0;
}