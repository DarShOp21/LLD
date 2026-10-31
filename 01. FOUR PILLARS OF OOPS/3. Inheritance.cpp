//Inheritance: A mechanism where one class (child/derived class) acquires the properties and methods of another class (parent/base class).

#include<iostream>
#include<string>

using namespace std;

class Car{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:

    Car(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    void startEngine(){
        if(isEngineOn){
            cout << brand << " " << model
                 << " : Engine is already ON!!" << endl;
            return;
        }

        isEngineOn = true;

        cout << brand << " " << model
             << " : Engine Started!!" << endl;
    }

    void stopEngine(){

        if(!isEngineOn){
            cout << brand << " " << model
                 << " : Engine is already OFF!!" << endl;
            return;
        }

        if(currentSpeed > 0){
            cout << brand << " " << model
                 << " : Can't stop engine while car is moving!!" << endl;
            return;
        }

        isEngineOn = false;

        cout << brand << " " << model
             << " : Engine Stopped!!" << endl;
    }

    void accelerate(){

        if(!isEngineOn){
            cout << brand << " " << model
                 << " : Engine is OFF!! Can't accelerate." << endl;
            return;
        }

        currentSpeed += 20;

        cout << brand << " " << model
             << " : Accelerating!! Speed is now "
             << currentSpeed << " km/h" << endl;
    }

    void brake(){

        if(!isEngineOn){
            cout << brand << " " << model
                 << " : Engine is OFF!! Can't apply brake." << endl;
            return;
        }

        currentSpeed -= 10;

        if(currentSpeed < 0)
            currentSpeed = 0;

        cout << brand << " " << model
             << " : Braking!! Speed is now "
             << currentSpeed << " km/h" << endl;
    }

    int getSpeed(){
        return currentSpeed;
    }

    virtual ~Car(){}
};


class ManualCar : public Car{

private:
    int currentGear;

public:

    ManualCar(string b, string m) : Car(b,m){
        currentGear = 0;
    }

    void shiftGear(int g){

        if(!isEngineOn){
            cout << brand << " " << model
                 << " : Engine is OFF!! Can't shift gear." << endl;
            return;
        }

        if(g < 0 || g > 6){
            cout << "Invalid gear!!" << endl;
            return;
        }

        currentGear = g;

        cout << brand << " " << model
             << " : Shifted to gear "
             << currentGear << endl;
    }
};


class ElectricCar : public Car{

private:
    int batteryLevel;

public:

    ElectricCar(string b, string m) : Car(b,m){
        batteryLevel = 100;
    }

    void chargeBattery(){

        batteryLevel = 100;

        cout << brand << " " << model
             << " : Battery fully charged!!"
             << endl;
    }

    void showBattery(){

        cout << brand << " " << model
             << " : Battery Level = "
             << batteryLevel << "%" << endl;
    }
};


int main(){

    ManualCar* manualCar =
        new ManualCar("Ford", "Mustang");

    ElectricCar* electricCar =
        new ElectricCar("Tesla", "Model 3");

    int carChoice;
    int choice;
    int gear;

    while(true){

        cout << "\n========== CAR SELECTION ==========" << endl;
        cout << "1. Manual Car" << endl;
        cout << "2. Electric Car" << endl;
        cout << "3. Exit" << endl;

        cout << "Choose car: ";
        cin >> carChoice;


        if(carChoice == 3){
            break;
        }


        if(carChoice == 1){

            while(true){

                cout << "\n===== MANUAL CAR =====" << endl;
                cout << "1. Start Engine" << endl;
                cout << "2. Shift Gear" << endl;
                cout << "3. Accelerate" << endl;
                cout << "4. Brake" << endl;
                cout << "5. Stop Engine" << endl;
                cout << "6. Show Speed" << endl;
                cout << "7. Back" << endl;

                cout << "Enter choice: ";
                cin >> choice;


                switch(choice){

                    case 1:
                        manualCar->startEngine();
                        break;

                    case 2:
                        cout << "Enter gear: ";
                        cin >> gear;

                        manualCar->shiftGear(gear);
                        break;

                    case 3:
                        manualCar->accelerate();
                        break;

                    case 4:
                        manualCar->brake();
                        break;

                    case 5:
                        manualCar->stopEngine();
                        break;

                    case 6:
                        cout << "Current Speed = "
                             << manualCar->getSpeed()
                             << " km/h" << endl;
                        break;

                    case 7:
                        goto manualMenu;

                    default:
                        cout << "Invalid choice!!" << endl;
                }
            }

            manualMenu:;
        }


        else if(carChoice == 2){

            while(true){

                cout << "\n===== ELECTRIC CAR =====" << endl;
                cout << "1. Start Engine" << endl;
                cout << "2. Accelerate" << endl;
                cout << "3. Brake" << endl;
                cout << "4. Stop Engine" << endl;
                cout << "5. Show Speed" << endl;
                cout << "6. Charge Battery" << endl;
                cout << "7. Show Battery" << endl;
                cout << "8. Back" << endl;

                cout << "Enter choice: ";
                cin >> choice;


                switch(choice){

                    case 1:
                        electricCar->startEngine();
                        break;

                    case 2:
                        electricCar->accelerate();
                        break;

                    case 3:
                        electricCar->brake();
                        break;

                    case 4:
                        electricCar->stopEngine();
                        break;

                    case 5:
                        cout << "Current Speed = "
                             << electricCar->getSpeed()
                             << " km/h" << endl;
                        break;

                    case 6:
                        electricCar->chargeBattery();
                        break;

                    case 7:
                        electricCar->showBattery();
                        break;

                    case 8:
                        goto electricMenu;

                    default:
                        cout << "Invalid choice!!" << endl;
                }
            }

            electricMenu:;
        }

        else{
            cout << "Invalid car choice!!" << endl;
        }
    }


    delete manualCar;
    delete electricCar;

    cout << "\nProgram Exited..." << endl;

    return 0;
}
