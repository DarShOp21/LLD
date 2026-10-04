#include <iostream>

using namespace std;

// Separate interface for 2D shapes
class TwoDimensionalShape {
public:
    virtual double area() = 0;
};

// Separate interface for 3D shapes
class ThreeDimensionalShape {
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};


class Square : public TwoDimensionalShape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override {
        return side * side;
    }
};


class Rectangle : public TwoDimensionalShape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }
};


class Cube : public ThreeDimensionalShape {
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double area() override {
        return 6 * side * side;
    }

    double volume() override {
        return side * side * side;
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
        cout << "2. Rectangle\n";
        cout << "3. Cube\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {

            double side;

            cout << "Enter side: ";
            cin >> side;

            TwoDimensionalShape* square = new Square(side);

            cout << "Square Area : "
                 << square->area() << endl;

            delete square;
        }

        else if (choice == 2) {

            double length, width;

            cout << "Enter length: ";
            cin >> length;

            cout << "Enter width: ";
            cin >> width;

            TwoDimensionalShape* rectangle =
                new Rectangle(length, width);

            cout << "Rectangle Area : "
                 << rectangle->area() << endl;

            delete rectangle;
        }

        else if (choice == 3) {

            double side;

            cout << "Enter side: ";
            cin >> side;

            ThreeDimensionalShape* cube =
                new Cube(side);

            cout << "Cube Surface Area : "
                 << cube->area() << endl;

            cout << "Cube Volume       : "
                 << cube->volume() << endl;

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
