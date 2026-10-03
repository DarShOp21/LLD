#include <iostream>

using namespace  std;

class Animal{

};

class Dog : public Animal{

};


class Parent{
  public: 
    virtual Animal* getAnimal(){
      cout << "Parent : Returning Animal instance" << endl;
      return new Animal();
    }
};

class Child : public Parent{
  public:
    Animal* getAnimal() override{
      cout << "Child : Returning Dog instance" << std::endl;
      return new Dog();
    }
};


class Client{
  private:
    Parent* p;

  public:
    Client(Parent* p){
      this->p = p;
    }

    void takeAnimal(){
      p->getAnimal();
    }
};


int main(){
  Parent* parent = new Parent();
  Child* child = new Child();

  Client* client = new Client(child);
  client->takeAnimal();

  Client* client2 = new Client(parent);
  client2->takeAnimal();

  return 0;
}
