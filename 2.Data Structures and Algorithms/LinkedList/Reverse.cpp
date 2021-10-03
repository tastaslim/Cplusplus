#include "takeInput.h"
Taslim *middleElement(Taslim *head)
{
  Taslim *slow = head, *fast = head->next;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
void print(Taslim *head)
{
  Taslim *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
int main()
{
  Taslim *head = takeInput();
  Taslim *middle = middleElement(head);
  cout << middle->data;
  // print(head);
}
