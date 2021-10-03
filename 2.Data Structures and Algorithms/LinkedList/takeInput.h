#include<iostream>
using namespace std;
class Taslim
{
  public:
  int data;
  Taslim *next;
  Taslim(int data)
  {
   this->data=data;
   this->next=NULL;
  }
};
Taslim *takeInput()
{
  int data;
  cin>>data;
  Taslim *head=NULL;
  Taslim *tail=NULL;
  while(data!=-1)
  {
    Taslim *newNode=new Taslim(data);
    if(head==NULL)
    {
      head=newNode;
      tail=newNode;
    }
    else
    {
      tail->next=newNode;
      tail=tail->next;
    }
    cin>>data;
  }
  return head;
}
