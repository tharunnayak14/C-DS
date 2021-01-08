#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};
void insert_head(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head->prev = n;
    head = n;
}
int length(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
void insert_tail(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    node *n = new node(d);
    temp->next = n;
    n->prev = temp;
}
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
int main()
{
    node *head = NULL;
    insert_head(head, 2);
    insert_head(head, 3);
    insert_head(head, 4);
    print(head);
    insert_tail(head, 99);
    print(head);
    insert_head(head, 45);
    print(head);
    insert_tail(head, 12);
    insert_tail(head, 6);
    print(head);
    insert_head(head, 4);
    insert_tail(head, 99);
    print(head);
    return 0;
}