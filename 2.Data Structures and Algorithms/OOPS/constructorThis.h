#include<iostream>
using namespace std;
class Taslim
{
  private:
  char *name;
  char *address;
  int age;
  public:
  Taslim(char *name, char* address, int age)
  {
    this->name=name;
    this->address=address;
    this->age=age;
  }
  
  void print()
  {
    cout<<"Name:"<<name<<endl;
    cout<<"Address:"<<address<<endl;
    cout<<"Age:"<<age<<endl;
  }
};
