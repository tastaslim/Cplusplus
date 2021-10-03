#include <iostream>
using namespace std;

//Take Input Code
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
node *TakeInput()
{
    int value;
    cin >> value;
    node *head = NULL;
    node *tail = NULL;
    while (value != -1)
    {
        node *newNode = new node(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> value;
    }
    return head;
}

// Merging Two Sorted LinkedList
node *MergeTwoSortedLL(node *head1, node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    node *finalListHead = NULL;
    node *finalList = NULL;
    node *temp1 = head1, *temp2 = head2;
    while (temp1 && temp2)
    {
        if (temp1->data > temp2->data)
        {
            if (!finalList)
            {
                finalList = temp2;
                finalListHead = temp2;
            }
            else
            {
                finalList->next = temp2;
                finalList = finalList->next;
            }
            temp2 = temp2->next;
        }
        else
        {
            if (!finalList)
            {
                finalList = temp1;
                finalListHead = temp1;
            }
            else
            {
                finalList->next = temp1;
                finalList = finalList->next;
            }
            temp1 = temp1->next;
        }
    }
    while (temp1)
    {
        finalList->next = temp1;
        temp1 = temp1->next;
        finalList = finalList->next;
    }
    while (temp2)
    {
        finalList->next = temp2;
        temp2 = temp2->next;
        finalList = finalList->next;
    }
    return finalListHead;
}

//Finding Mid Point

node *MidPoint(node *head)
{
    node *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Merge Sort
node *MergeSort(node *head)
{
    if (!head || !head->next)
        return head;

    node *midPoint = MidPoint(head);
    node *nextPart = midPoint->next;
    midPoint->next = NULL;
    node *firstPart = MergeSort(head);
    node *secondPart = MergeSort(nextPart);
    return MergeTwoSortedLL(firstPart, secondPart);
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    node *head = TakeInput();
    // node *head2 = TakeInput();
    node *finalList = MergeSort(head);
    // node *sortedList = MergeTwoSortedLL(head, head2);
    // print(head);
    // print(head2);
    print(finalList);
    cout << endl;
    return 0;
}