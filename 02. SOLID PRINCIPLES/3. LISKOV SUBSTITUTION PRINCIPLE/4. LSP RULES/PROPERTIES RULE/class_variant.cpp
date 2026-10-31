#include <iostream>
#include <stdexcept>

using namespace  std;

class BankAccount{
  protected:
    int balance;

  public:
    BankAccount(double b){
      if(b < 0) throw invalid_argument("BALANCE CANT BE LESS THAN ZERO");
      this->balance = b;
    }

    virtual void withdraw(double val){
      if( balance - val < 0)
        throw runtime_error("INSUFFICIENT BALANCE");
      balance -= val;
      cout << "AMOUNT $"<<val<<"WITHDRAWN";
    }
};

class CheatAccount : public BankAccount{
  public:
    CheatAccount(double a) : BankAccount(a){};

    void withdraw(double val) override{
      balance-=val;     //LSP break! Negative balance allowed
      cout << "AMOUNT $"<<val<<"WITHDRAWN";
    }
};

int main() {
    BankAccount* bankAccount = new BankAccount(100);
    bankAccount->withdraw(100);

    cout << endl;

    CheatAccount* cheatAccount = new CheatAccount(100);
    cheatAccount->withdraw(200);
}

