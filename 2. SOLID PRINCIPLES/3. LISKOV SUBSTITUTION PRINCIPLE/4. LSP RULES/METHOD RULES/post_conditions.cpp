#include <iostream>
#include <ostream>

using namespace std;


// A Postcondition must be statisfied after a method is executed.
// Sub classes can strengthen the Postcondition but cannot weaken it.

class Car{
  protected :
    int speed;

  public:
    Car(){
      this->speed = 100;
    }

    void brake(){
      if(!speed)
        return;

      cout << "APPLYING BRAKE";
      speed -= 20;
    }
};

class ElectricCar : public Car{
  private :
    int charging;

  public:
    ElectricCar() : Car(){
      charging = 0;
    }

    void brake(){
      if(!speed)
          return;

      cout << "APPLYING BRAKE";
      speed -= 20;
      charging += 10;
    }

    void getCharging(){
      cout << charging << endl;
    } 
};


int main() {
    ElectricCar* electricCar = new ElectricCar();

    electricCar->getCharging();
    electricCar->brake();  // Works fine: HybridCar reduces speed and also increases charge.
    electricCar->getCharging();

    //Client feels no difference in substituting Hybrid car in place of Car.

    return 0;
}
