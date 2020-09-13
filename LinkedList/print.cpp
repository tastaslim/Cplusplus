#include "takeInput.cpp"

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
  Taslim *head=TakeInput();
  print(head);
}
