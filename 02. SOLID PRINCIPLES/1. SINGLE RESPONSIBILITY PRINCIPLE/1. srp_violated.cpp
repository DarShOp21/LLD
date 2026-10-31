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

    void printInvoice(){
      for(Product* p : products){
        cout << p->getName() << " - $" << p->getPrice() << endl;  
      }

      cout << "Total: $" << calculateTotal() << endl;
    }
    
    void saveToDB(){
      cout << "SAVING DATA TO DB......" << endl ;

    }
};

int main(){

    ShoppingCart cart;

    int choice;

    while(true){

        cout << "\n========== SHOPPING CART ==========" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. View Cart" << endl;
        cout << "3. Calculate Total" << endl;
        cout << "4. Print Invoice" << endl;
        cout << "5. Save To DB" << endl;
        cout << "6. Exit" << endl;

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

                Product* product = new Product(name, price);

                cart.addToCart(product);

                cout << "Product added to cart!" << endl;

                break;
            }


            case 2:
            {
                const vector<Product*>& products = cart.getProducts();

                cout << "\n========== CART ==========" << endl;

                if(products.empty()){
                    cout << "Cart is empty!" << endl;
                }
                else{
                    for(Product* p : products){
                        cout << p->getName()
                             << " - $"
                             << p->getPrice()
                             << endl;
                    }
                }

                break;
            }


            case 3:
            {
                cout << "\nTotal = $"
                     << cart.calculateTotal()
                     << endl;

                break;
            }


            case 4:
            {
                cart.printInvoice();

                break;
            }


            case 5:
            {
                cart.saveToDB();

                break;
            }


            case 6:
            {
                cout << "Exiting..." << endl;
                return 0;
            }


            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
