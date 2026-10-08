#include <iostream>
#include <string>

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


class GarlicBread {
public:
    virtual void prepare() = 0;
};

class BasicGarlicBread : public GarlicBread {
public:
    void prepare() override {
        std::cout << "Preparing Basic Garlic Bread with butter and garlic!\n";
    }
};

class CheeseGarlicBread : public GarlicBread {
public:
    void prepare() override {
        std::cout << "Preparing Cheese Garlic Bread with extra cheese and butter!\n";
    }
};

class BasicWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        std::cout << "Preparing Basic Wheat Garlic Bread with butter and garlic!\n";
    }
};

class CheeseWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        std::cout << "Preparing Cheese Wheat Garlic Bread with extra cheese and butter!\n";
    }
};


class MealFactory{
  public:
    virtual Burger* createBurger(string& type) = 0;
    virtual GarlicBread* createGarlicBread(string& type) = 0;
};

class KingFactory : public MealFactory{
  public:
    Burger* createBurger(string &type) override{
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

    GarlicBread * createGarlicBread(string &type) override{
      if (type == "basic") {
        return new BasicWheatGarlicBread();
      } else if (type == "cheese") {
        return new CheeseWheatGarlicBread();
      } 
      else {
        cout << "Invalid Garlic bread type! " << endl;
        return nullptr;
      }
    }
};

class SinghBurger : public MealFactory {
public:
    Burger* createBurger(string& type) override {
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

    GarlicBread* createGarlicBread(string& type) override {
        if (type == "basic") {
            return new BasicGarlicBread();
        } else if (type == "cheese") {
            return new CheeseGarlicBread();
        } 
        else {
            cout << "Invalid Garlic bread type! " << endl;
            return nullptr;
        }
    }
};

int main(){
  MealFactory* factory = new SinghBurger();

  string type = "cheese";

  GarlicBread* cheeseGarlicBread = factory->createGarlicBread(type);

  cheeseGarlicBread->prepare();
}
