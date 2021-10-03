#include"1.h"
using namespace std;
int main()
{
 char name[100];
 char address[100];
 int age;
 cin.getline(name,100);
 cin.getline(address,100);
 cin>>age;
 Taslim t;
 t.setter(name,address,age);
 cout<<"Name:"<<t.getName()<<endl;
 cout<<"Address:"<<t.getAddress()<<endl;
 cout<<"Age:"<<t.getAge()<<endl;
}
