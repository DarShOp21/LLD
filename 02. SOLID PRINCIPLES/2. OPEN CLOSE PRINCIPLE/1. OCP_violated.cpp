#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Product {
private:
    string name;
    double price;

public:
    Product(string n, double p) {
        this->name = n;
        this->price = p;
    }

    string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }
};

class ShoppingCart {
private:
    vector<Product*> products;

public:
    void addProduct(Product* p) {
        products.push_back(p);
    }

    const vector<Product*>& getProducts() {
        return products;
    }

    double calculateTotal() {
        double total = 0;

        for (Product* p : products) {
            total += p->getPrice();
        }

        return total;
    }
};

class ShoppingCartPrinter {
private:
    ShoppingCart* cart;

public:
    ShoppingCartPrinter(ShoppingCart* c) {
        this->cart = c;
    }

    void printInvoice() {

        cout << "\n========================================\n";
        cout << "              INVOICE\n";
        cout << "========================================\n";

        cout << left << setw(25) << "Product"
             << right << setw(10) << "Price" << endl;

        cout << "----------------------------------------\n";

        for (Product* p : cart->getProducts()) {
            cout << left << setw(25) << p->getName()
                 << right << setw(10)
                 << fixed << setprecision(2)
                 << p->getPrice() << endl;
        }

        cout << "----------------------------------------\n";

        cout << left << setw(25) << "Total"
             << right << setw(10)
             << fixed << setprecision(2)
             << cart->calculateTotal() << endl;

        cout << "========================================\n";
    }
};

class ShoppingCartStorage {
private:
    ShoppingCart* cart;

public:
    ShoppingCartStorage(ShoppingCart* c) {
        this->cart = c;
    }

    void saveToSQLDatabase() {
        cout << "\n[Storage] Saving cart to SQL database...\n";
    }

    void saveToMongoDatabase() {
        cout << "[Storage] Saving cart to MongoDB...\n";
    }

    void saveToFile() {
        cout << "[Storage] Saving cart to file...\n";
    }
};

int main() {

    ShoppingCart* cart = new ShoppingCart();

    int n;

    cout << "========================================\n";
    cout << "        SHOPPING CART SYSTEM\n";
    cout << "========================================\n";

    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        string name;
        double price;

        cout << "\nProduct " << i + 1 << endl;

        cout << "Enter product name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter product price: $";
        cin >> price;

        Product* product = new Product(name, price);

        cart->addProduct(product);
    }

    // Print invoice
    ShoppingCartPrinter* printer =
        new ShoppingCartPrinter(cart);

    printer->printInvoice();

    // Storage
    ShoppingCartStorage* storage =
        new ShoppingCartStorage(cart);

    cout << "\n";
    storage->saveToSQLDatabase();
    storage->saveToMongoDatabase();
    storage->saveToFile();

    // Free memory
    delete printer;
    delete storage;

    for (Product* product : cart->getProducts()) {
        delete product;
    }

    delete cart;

    return 0;
}
