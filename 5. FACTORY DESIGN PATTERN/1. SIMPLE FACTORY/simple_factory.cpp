#include <iostream>

using namespace std;

class Burger{
  public:
    virtual void prepare() = 0;
    virtual ~Burger(){}
};

class ClassicBurger : public Burger{
  public:
    void prepare() override{
      cout << "Preparing classic burger";
    }
};

class StandardBurger : public Burger{
  public:
    void prepare() override{
      cout << "Preparing standard burger";
    }
};

class PremiumBurger : public Burger{
  public:
    void prepare() override{
      cout << "Preparing premium burger";
    }
};

class BurgerFactory{
  public:
    Burger* createBurger(string type){
      if(type == "classic")
        return new ClassicBurger();
      else if(type == "standard")
        return  new StandardBurger();
      else if(type == "premium")
        return  new PremiumBurger();
      else{
        cout << "INVALID BURGER TYPE \n";
        return nullptr;
      }
    }
};

int main(){
  string type = "premium";

  BurgerFactory* burgerFactory = new BurgerFactory();

  Burger* burger = burgerFactory->createBurger(type);

  burger->prepare();

  return 0;
}
