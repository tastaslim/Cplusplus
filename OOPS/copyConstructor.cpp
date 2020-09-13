#include "copyConstructor.h"
int main()
{
  char name[100];
  char address[100];
  int age;
  cin.getline(name,100);
  cin.getline(address,100);
  cin>>age;
  
  //Taslim *t=new Taslim(name,address,age);
  /*Taslim *t2(t);
  t2->print();*/
  Taslim t3(name,address,age);
  Taslim *t4=new Taslim("Tas","NPP",21);
  
  //Since we can call constructor only once for an object, now we can't use copy constructor for t3 and t4 as 
  //Already for them constructor(Parameterised) has been called. hence to solve it we will use "=" operator.
  Taslim *t2(&t3); // Here we are copying address of t3 into t2.
  //Taslim t2=t3; In this way we copying content of t3 object into t2 object.
  t3=*t4;
  t3.print();
  t2.print();
}
