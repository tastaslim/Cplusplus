#include<iostream>
using namespace std;
class Fraction
{
  private:
  int num;
  int de;
  public:
  Fraction(int num, int de)
  {
    this->num=num;
    this->de=de;
  }
  
  int gcd(int x, int y)
  {
    int gcd=1;
    for(int i=1;i<=x;i++) // we can choose y as well
    {
      if(x%i==0 && y%i==0)
      {
       gcd=i;
      }
    }
    return k;
  }
  
  void calculate(const Fraction &f1)
  {
   int lcm=this->de*f1.de;
   int x=this->num*f1.de;
   int y=this->de*f1.num;
   int z=x+y;
   int l=gcd(z,lcm);
   lcm=lcm/l;
   z=z/l;
   num=z;
   de=lcm;
   cout<<num<<"/"<<de<<endl;
  }
  
  ~Fraction()
  {
  
  }
};

int main()
{
  Fraction f1(10,3);
  Fraction *f2=new Fraction(3,4);
  f1.calculate(*f2);
}
