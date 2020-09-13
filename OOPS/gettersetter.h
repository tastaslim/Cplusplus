#include<iostream>
using namespace std;
class Taslim
{
  private:
  char *name;
  char *address;
  int age;
  public:
  void setter(char *a, char *c, int b)
  {
    name=a;
    address=c;
    age=b;
  }
  
  char* getName()
  {
    return name;
  }
  
  char* getAddress()
  {
    return address;
  }
  
  int getAge()
  {
    return age;
  }
};
 
