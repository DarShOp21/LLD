//Encapsulation : Bundling data and methods together in a class and restricting direct access to the data using access modifiers like private, protected, and public

#include<iostream>
#include<string>

using namespace std;

class SportsCar{
    private:
        //Characters
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;

    public:

        //Constructors
        SportsCar(string b , string m){
            this -> brand = b;
            this -> model = m;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0 ; //Neutral
        };

        //Behaviours
        void startEngine(){
            isEngineOn = true;
            cout << brand << " " << model << " : Engine Started!!" << endl;
        }

        void shiftGear(int gear){
            if(!isEngineOn){
                cout << brand << " " << model << " : Engine is off !! Can't shift the gear" << endl;
                return;
            }
            currentGear = gear;
            cout << brand << " " << model << " : Shifted to gear " << gear << endl;
        }

        void accelerate(){
            if(!isEngineOn){
                cout << brand << " " << model << " : Engine is off !! Can't accelerate" << endl;
                return;
            }
            currentSpeed += 20;
            cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/hr" << endl;
        }

        void brake(){
            if(!isEngineOn){
                cout << brand << " " << model << " : Engine is off !! Can't apply brake" << endl;
                return;
            }

            if(currentSpeed < 0) currentSpeed = 0;
            else currentSpeed -= 10;
            cout << brand << " " << model << " :Braking ! Speed is now " << currentSpeed << " km/h" << endl;
        }

        void stopEngine(){
            isEngineOn = false;
            currentSpeed = 0 ;
            currentGear = 0;
            cout << brand << " " << model << " : Engine turned off " << endl;
        }

        ~SportsCar(){}
};

int main(){

    SportsCar* mySportsCar = new SportsCar("Ford", "Mustang");

    int choice;
    int gear;

    while(true){

        cout << "\n===== SPORTS CAR CONTROL =====" << endl;
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
                mySportsCar->startEngine();
                break;

            case 2:
                cout << "Enter gear: ";
                cin >> gear;
                mySportsCar->shiftGear(gear);
                break;

            case 3:
                mySportsCar->accelerate();
                break;

            case 4:
                mySportsCar->brake();
                break;

            case 5:
                mySportsCar->stopEngine();
                break;

            case 6:
                delete mySportsCar;
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
