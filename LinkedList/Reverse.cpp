#include "takeInput.h"
Taslim *reverse(Taslim *head)
{
  Taslim *curr=head;
  Taslim *prev=NULL;
  Taslim *fo=NULL;
  while(curr!=NULL)
  {
    curr->next=prev;
    fo=curr->next;
    prev=curr;
    curr=fo;
  }
  head=prev;
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
  head=reverse(head);
  print(head);
}
