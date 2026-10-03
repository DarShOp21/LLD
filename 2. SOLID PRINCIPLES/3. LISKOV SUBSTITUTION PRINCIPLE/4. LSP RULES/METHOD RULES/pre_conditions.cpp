#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// A Precondition must be statisfied before a method can be executed.
// Sub classes can weaken the precondition but cannot strengthen it.

class User{
  private:
    string password;

  public:
    //password length >= 8
    void setPassword(string p){
      if(p.length() < 8)
        throw invalid_argument("Password must be at least of 8 characters");

      this->password = p;
      cout << "PASSWORD HAS BEEN SET";

    }
};

class AdminUser : public User{
  private:
    string password;

  public:
    //password length >= 6
    void setPassword(string p){
      if(p.length() < 6)
        throw invalid_argument("assword must be at least of 6 characters");

      this->password = p;
      cout << "PASSWORD HAS BEEN SET";
    }
};

int main(){
  AdminUser *user = new AdminUser();
  user->setPassword("dfsfs7");

  return 0;
}
