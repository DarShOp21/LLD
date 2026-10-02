#include<iostream>
#include<string>
//Abstraction --> It hides unncessary details from the client and showcase what is necessary 

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

class SportsCar : public Car{
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string brand, string model){
        this->brand = brand;
        this->model = model;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine(){
        isEngineOn = true;

        cout << brand << " " << model
             << " : Engine has been started" << endl;
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout << brand << " " << model
                 << " : Engine is Off, cannot shift gear" << endl;
        }
        else{
            currentGear = gear;

            cout << brand << " " << model
                 << " : Shifted to gear "
                 << currentGear << endl;
        }
    }

    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model
                 << " : Engine is Off, cannot accelerate" << endl;
        }
        else{
            currentSpeed += 20;

            cout << brand << " " << model
                 << " : Accelerating, current speed is "
                 << currentSpeed << " km/h" << endl;
        }
    }

    void brake(){
        if(currentSpeed == 0){
            cout << brand << " " << model
                 << " : Car is already stopped" << endl;
        }
        else{
            currentSpeed -= 20;

            if(currentSpeed < 0)
                currentSpeed = 0;

            cout << brand << " " << model
                 << " : Braking, current speed is "
                 << currentSpeed << " km/h" << endl;
        }
    }

    void stopEngine(){
        if(!isEngineOn){
            cout << brand << " " << model
                 << " : Engine is already Off" << endl;
        }
        else if(currentSpeed > 0){
            cout << brand << " " << model
                 << " : Cannot stop engine while car is moving" << endl;
        }
        else{
            isEngineOn = false;
            currentGear = 0;

            cout << brand << " " << model
                 << " : Engine has been stopped" << endl;
        }
    }
};

int main(){

    Car* car = new SportsCar("Ferrari", "488");

    int choice;
    int gear;

    while(true){

        cout << "\n===== CAR CONTROL =====" << endl;
        cout << "1. Start Engine" << endl;
        cout << "2. Shift Gear" << endl;
        cout << "3. Accelerate" << endl;
        cout << "4. Brake" << endl;
        cout << "5. Stop Engine" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){

            case 1:
                car->startEngine();
                break;

            case 2:
                cout << "Enter gear: ";
                cin >> gear;
                car->shiftGear(gear);
                break;

            case 3:
                car->accelerate();
                break;

            case 4:
                car->brake();
                break;

            case 5:
                car->stopEngine();
                break;

            case 6:
                delete car;
                cout << "Program exited." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
