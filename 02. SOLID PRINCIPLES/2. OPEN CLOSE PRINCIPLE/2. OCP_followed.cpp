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

class Persistence{
  private:
    ShoppingCart* cart;

  public:
    virtual void save(ShoppingCart* cart) = 0;

    virtual ~Persistence() {}
};

class SQLPersistence : public Persistence{
  public:
    void save(ShoppingCart* cart) override{
      cout << "SAVING TO SQL DATABASE";
    }
};

class MongoPersistence : public Persistence{
  public:
    void save(ShoppingCart* cart) override{
      cout << "SAVING TO THE MONGO DATABASE";
    }
};

class FilePersistence : public Persistence{
  public:
    void save(ShoppingCart* cart) override{
      cout << "SAVING TO THE FILES";
    }
};

int main() {

    // Create shopping cart
    ShoppingCart* cart = new ShoppingCart();

    int n;

    cout << "========================================\n";
    cout << "        SHOPPING CART SYSTEM\n";
    cout << "========================================\n";

    cout << "Enter number of products: ";
    cin >> n;

    // Dynamically create products
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

    // Persistence objects
    Persistence* sql =
        new SQLPersistence();

    Persistence* mongo =
        new MongoPersistence();

    Persistence* file =
        new FilePersistence();

    cout << "\n\n========================================\n";
    cout << "           PERSISTENCE\n";
    cout << "========================================\n";

    sql->save(cart);
    cout << endl;

    mongo->save(cart);
    cout << endl;

    file->save(cart);
    cout << endl;

    // Free memory
    delete sql;
    delete mongo;
    delete file;

    delete printer;

    for (Product* product : cart->getProducts()) {
        delete product;
    }

    delete cart;

    return 0;
}
