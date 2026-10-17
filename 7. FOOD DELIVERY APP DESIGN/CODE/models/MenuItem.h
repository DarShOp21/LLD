#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
using namespace std;

class MenuItem{
  private:
    string name;
    string code;
    int price;

  public:
    MenuItem(const string& name , const string& code , int price){
      this->code = code;
      this->name = name;
      this->price = price;
    }

    string getCode() const {
        return code;
    }

    void setCode(const string &c) {
        code = c;
    }

    string getName() const {
        return name;
    }

    void setName(const string &n) {
        name = n;
    }

    int getPrice() const {
        return price;
    }

    void setPrice(int p) {
        price = p;
    }
};

#endif // !MENUITEM_H

