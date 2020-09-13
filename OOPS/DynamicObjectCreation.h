#include<iostream>
using namespace std;
class Taslim
{
  private:
  char *name;
  char *address;
  int age;
  public:
  Taslim()
  {
   cout<<"Default constructor"<<endl;
  }
  Taslim(char *name, char* address, int age)
  {
    cout<<this<<endl;
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
