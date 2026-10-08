#include <iostream>

using namespace std;

class Burger{
  public:
    virtual void prepare() = 0;
    virtual ~Burger(){} 
};

class StandardBurger : public Burger{
  public:
    void prepare() override{
      cout << "PREPARING STANDARD BURGER \n"; 
    }
};

class BasicBurger : public Burger{
  public:
    void prepare() override{
      cout << "PREPARING BASIC BURGER \n"; 
    }
};

class PremiumBurger : public Burger{
  public:
    void prepare() override{
      cout << "PREPARING PREMIUM BURGER \n"; 
    }
};

class StandardWheatBurger : public Burger{
  public:
    void prepare() override{
      cout << "PREPARING STANDARD WHEAT BURGER \n"; 
    }
};

class BasicWheatBurger : public Burger{
  public:
    void prepare() override{
      cout << "PREPARING BASIC WHEAT BURGER \n"; 
    }
};

class PremiumWheatBurger : public Burger{
  public:
    void prepare() override{
      cout << "PREPARING PREMIUM WHEAT BURGER \n"; 
    }
};

class BurgerFactory{
  public:
    virtual Burger* createBurger(string& type) = 0;
};

class KingBurger : public BurgerFactory{
  public:
    Burger* createBurger(string& type) override{
      if (type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        } else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }
};

class SinghBurger : public BurgerFactory{
  public:
    Burger* createBurger(string& type) override {
        if (type == "basic") {
            return new BasicWheatBurger();
        } else if (type == "standard") {
            return new StandardWheatBurger();
        } else if (type == "premium") {
            return new PremiumWheatBurger();
        } else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }
};


int main(){
  string type = "premium";

  BurgerFactory* singhBurgerFactory = new SinghBurger();

  Burger* premiumWheatBurger = singhBurgerFactory->createBurger(type);

  premiumWheatBurger->prepare();

  return  0;
}
