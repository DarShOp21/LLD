#include<iostream>
#include<vector>

using namespace  std;

class Product{
  private:
    string name;
    double price;

  public:
    Product(string n , double p){
      this->name = n;
      this->price = p;
    } 

    string getName(){
      return name;
    }

    double getPrice(){
      return price;
    }
};

class ShoppingCart{
  private:
    vector<Product*>products;

  public:
    void addToCart(Product* p){
      products.push_back(p);
    }

    const vector<Product*>& getProducts(){
      return products;
    }

    double calculateTotal(){
      double total = 0;
      for(Product* p : products){
        total += p->getPrice();
      }

      return total;
    }
};

class ShoppingCartPrinter{
  private:
    ShoppingCart* cart;

  public:
    ShoppingCartPrinter(ShoppingCart *c){
      this->cart = c;
    }

    void printInvoice(){
      cout << "SHOPPING CART INVOICE : \n";

      for(auto p : cart->getProducts()){
        cout << p->getName()
                 << " - $"
                 << p->getPrice()
                 << endl;
      }

      cout << "-----------------------------" << endl;

      cout << "Total: $"
             << cart->calculateTotal()
             << endl;
    }
};

class ShoppingCartStorage{
  private:
    ShoppingCart* cart;

  public:

    ShoppingCartStorage(ShoppingCart* c){
      this->cart = c;
    }

    void saveToDB(){
      cout << "Saving data to the DB";
    }
};

int main(){

    // Create shopping cart
    ShoppingCart* cart = new ShoppingCart();


    int choice;

    while(true){

        cout << "\n========== SHOPPING CART ==========" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. View Total" << endl;
        cout << "3. Print Invoice" << endl;
        cout << "4. Save To DB" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;


        switch(choice){

            case 1:
            {
                string name;
                double price;

                cout << "Enter product name: ";
                cin >> name;

                cout << "Enter product price: ";
                cin >> price;


                // Dynamically create Product
                Product* product = new Product(name, price);

                // Add product to cart
                cart->addToCart(product);

                cout << "Product added successfully!" << endl;

                break;
            }


            case 2:
            {
                cout << "\nTotal Amount: $"
                     << cart->calculateTotal()
                     << endl;

                break;
            }


            case 3:
            {
                // Create printer for this cart
                ShoppingCartPrinter* printer =
                    new ShoppingCartPrinter(cart);

                printer->printInvoice();

                delete printer;

                break;
            }


            case 4:
            {
                // Create storage handler for this cart
                ShoppingCartStorage* storage =
                    new ShoppingCartStorage(cart);

                storage->saveToDB();

                delete storage;

                break;
            }


            case 5:
            {
                cout << "Exiting..." << endl;

                delete cart;

                return 0;
            }


            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
