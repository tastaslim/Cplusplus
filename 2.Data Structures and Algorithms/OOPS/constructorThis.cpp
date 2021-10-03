#include "constructorThis.h"
int main()
{
  char name[100];
  char address[100];
  int age;
  cin.getline(name,100);
  cin.getline(address,100);
  cin>>age;
  Taslim t(name,address,age);
  t.print();
}
