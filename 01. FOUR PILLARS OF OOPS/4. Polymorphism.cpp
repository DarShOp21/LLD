#include<iostream>
#include<string>

using namespace std;


// ================= BASE CLASS =================

class Car{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:

    Car(string b, string m){
        brand = b;
        model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    void startEngine(){

        isEngineOn = true;

        cout << brand << " " << model
             << " : Engine Started!!" << endl;
    }

    void stopEngine(){

        isEngineOn = false;
        currentSpeed = 0;

        cout << brand << " " << model
             << " : Engine Stopped!!" << endl;
    }

    // Virtual functions
    virtual void accelerate() = 0;
    virtual void brake() = 0;

    int getSpeed(){
        return currentSpeed;
    }

    virtual ~Car(){}
};


// ================= MANUAL CAR =================

class ManualCar : public Car{

private:
    int currentGear;

public:

    ManualCar(string b, string m) : Car(b,m){
        currentGear = 0;
    }

    void shiftGear(int gear){

        currentGear = gear;

        cout << brand << " " << model
             << " : Shifted to gear "
             << currentGear << endl;
    }

    // Manual car has its own accelerate behaviour
    void accelerate(){

        if(!isEngineOn){
            cout << "Engine is OFF!!" << endl;
            return;
        }

        currentSpeed += 20;

        cout << brand << " " << model
             << " : Manual acceleration -> Speed = "
             << currentSpeed << " km/h" << endl;
    }

    // Manual car has its own brake behaviour
    void brake(){

        if(currentSpeed > 0)
            currentSpeed -= 10;

        if(currentSpeed < 0)
            currentSpeed = 0;

        cout << brand << " " << model
             << " : Manual braking -> Speed = "
             << currentSpeed << " km/h" << endl;
    }
};


// ================= ELECTRIC CAR =================

class ElectricCar : public Car{

private:
    int batteryLevel;

public:

    ElectricCar(string b, string m) : Car(b,m){
        batteryLevel = 100;
    }

    // Electric car has different acceleration
    void accelerate() {

        if(!isEngineOn){
            cout << "Electric car is OFF!!" << endl;
            return;
        }

        currentSpeed += 30;

        batteryLevel -= 5;

        cout << brand << " " << model
             << " : Electric acceleration -> Speed = "
             << currentSpeed << " km/h"
             << " | Battery = "
             << batteryLevel << "%" << endl;
    }

    // Electric car has regenerative braking
    void brake() {

        if(currentSpeed > 0)
            currentSpeed -= 15;

        if(currentSpeed < 0)
            currentSpeed = 0;

        // Regenerative braking
        batteryLevel += 2;

        if(batteryLevel > 100)
            batteryLevel = 100;

        cout << brand << " " << model
             << " : Regenerative braking -> Speed = "
             << currentSpeed << " km/h"
             << " | Battery = "
             << batteryLevel << "%" << endl;
    }
};


// ================= MAIN =================

int main(){

    // Base class pointer
    Car* car;

    int choice;

    cout << "========== CAR SELECTION ==========" << endl;
    cout << "1. Manual Car" << endl;
    cout << "2. Electric Car" << endl;
    cout << "Enter your choice: ";
    cin >> choice;


    if(choice == 1){

        car = new ManualCar("Ford", "Mustang");

    }
    else if(choice == 2){

        car = new ElectricCar("Tesla", "Model 3");

    }
    else{

        cout << "Invalid choice!!" << endl;
        return 0;
    }


    cout << "\n========== CAR CONTROL ==========" << endl;

    car->startEngine();

    car->accelerate();

    car->accelerate();

    car->brake();

    cout << "Current Speed = "
         << car->getSpeed()
         << " km/h" << endl;

    car->stopEngine();


    delete car;

    return 0;
}
