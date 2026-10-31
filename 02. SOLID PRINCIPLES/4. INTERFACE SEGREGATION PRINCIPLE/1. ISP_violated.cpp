#include <iostream>
#include <stdexcept>

using namespace std;

class Shape{
  public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public Shape{
  private: 
    double side;

  public:
    Square(int s){
      this->side = s;
    }

    double area() override{
      return side*side;
    }

    double volume() override{
      throw logic_error("Volume not applicable in Square");
    }
};

class Cube : public Shape{
  private:
    double side;

  public:
    Cube(double s){
      this->side = s;
    }

    double area() override{
      return 6*(side*side);
    };

    double volume() override{
      return side*side*side;
    }
};

int main() {

    cout << "========================================\n";
    cout << "          SHAPE CALCULATOR\n";
    cout << "========================================\n";

    int n;

    cout << "Enter number of shapes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        int choice;

        cout << "\nSelect Shape\n";
        cout << "1. Square\n";
        cout << "2. Cube\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {

            double side;

            cout << "Enter side of Square: ";
            cin >> side;

            Shape* square = new Square(side);

            cout << "Area   : " << square->area() << endl;

            cout << "Volume : " << square->volume() << endl;

            delete square;
        }

        else if (choice == 2) {

            double side;

            cout << "Enter side of Cube: ";
            cin >> side;

            Cube* cube = new Cube(side);

            cout << "Surface Area : " << cube->area() << endl;
            cout << "Volume       : " << cube->volume() << endl;

            delete cube;
        }

        else {
            cout << "Invalid choice! Try again.\n";
            i--;
        }
    }

    cout << "\n========================================\n";
    cout << "        CALCULATION COMPLETED\n";
    cout << "========================================\n";

    return 0;
}
