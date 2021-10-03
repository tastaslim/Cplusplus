#include<iostream>
using namespace std;
class Taslim
{
  private:
  string name;
  string address;
  int age;
  public:
  Taslim()
  {
   cout<<"Default constructor"<<endl;
  }
  Taslim(string name, string address, int age)
  {
    cout<<this<<endl;
    this->name=name;
    this->address=address;
    this->age=age;
  }
  Taslim(Taslim *t)
  {
    this->name=t->name;
    this->address=t->address;
    this->age=t->age;
  }
  void print()
  {
    cout<<"Name:"<<name<<endl;
    cout<<"Address:"<<address<<endl;
    cout<<"Age:"<<age<<endl;
  }
};
