#include "takeInput.h"
using namespace std;

Taslim *Insert(Taslim *head, int da, int pos)
{
  Taslim *temp=head;
  if(pos==0)
  {
    Taslim *newNode=new Taslim(da);
    newNode->next=head;
    head=newNode;
    return head;
  }
  int count=0;
  while(temp!=NULL && count<pos-1)
  {
    temp=temp->next;
    count++;
  }
  if(temp!=NULL)
  {
    Taslim *te=temp->next;
    Taslim *newNode=new Taslim(da);
    temp->next=newNode;
    newNode->next=te;
  }
  return head;
}

void print(Taslim *head)
{
  Taslim *temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}

int main()
{
  Taslim *head=takeInput();
  int pos;
  cin>>pos;
  head=Insert(head,200,pos);
  print(head);
}


