#include "DynamicObjectCreation.h"
int main()
{
  char name[100];
  char address[100];
  int age;
  cin.getline(name,100);
  cin.getline(address,100);
  cin>>age;
  // proving that this holds address of current object
  Taslim *t=new Taslim(name,address,age);
  cout<<t<<endl; 
  /*Taslim *t1=new Taslim();
  Taslim t3;
  Taslim t4();
  */
  t->print();
}
