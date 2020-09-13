#include "takeInput.h"
using namespace std;

Taslim *Delete(Taslim *head, int pos)
{
  Taslim *temp=head;
  if(pos==0)
  {
    Taslim *temp=head;
    head=head->next;
    delete temp;
    return head;
  }
  int count=0;
  while(temp!=NULL && count<pos-1)
  {
    temp=temp->next;
    count++;
  }
  
  if(temp->next!=NULL)
  {
    Taslim *te=temp->next;
    temp->next=te->next;
    delete te;
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
  head=Delete(head,pos);
  print(head);
}


