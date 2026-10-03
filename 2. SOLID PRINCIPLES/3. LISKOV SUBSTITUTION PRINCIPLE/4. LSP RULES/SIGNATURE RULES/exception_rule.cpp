#include <iostream>
#include <stdexcept>

using namespace std;

// Exception Rule:
// A subclass should throw fewer or narrower exceptions 
// (but not additional or broader exceptions) than the parent.
// C++ does not enforces this. Hence no compilation error.

/*
├── std::logic_error        <-- For logical errors detected before runtime
│   ├── std::invalid_argument   <-- Invalid function argument
│   ├── std::domain_error       <-- Function argument domain error
│   ├── std::length_error       <-- Exceeding valid length limits
│   ├── std::out_of_range       <-- Array or container index out of bounds
│
├── std::runtime_error      <-- For errors that occur at runtime
│   ├── std::range_error        <-- Numeric result out of range
│   ├── std::overflow_error     <-- Arithmetic overflow
│   ├── std::underflow_error   
*/

class Parent{
  public:
    virtual void getValue() noexcept(false){
      throw logic_error("Parent error");
    }
};

class Child : public Parent{
  public:
    void getValue() noexcept(false) override{
      throw runtime_error("Child error");
    }
};

class Client{
  private:
    Parent* p;

  public:
    Client(Parent* p){
      this->p = p;
    }

    void takeValue(){
      try{
        p->getValue();
      }catch(const logic_error& e){
        cout << "Logic error exception occured : " << e.what() << endl;
      }
    }
};

int main(){
  Parent* p = new  Parent();
  Child* c = new Child();

  Client* client = new Client(c);   //will cause error bcoz the child is passed in the Client and the child throw runtime error which is out of hierarchy of the error thrown by the parent i.e logical error

  client->takeValue();

  return  0;
}
