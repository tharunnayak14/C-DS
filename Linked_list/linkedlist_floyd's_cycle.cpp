#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    { // parametrised constructor
        data = d;
        next = NULL;
    }
};
void insert(node *&head, int d)
{ // pass by ref so that copy is not created
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
}
void insertTail(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "\n";
}
node *take_input()
{
    int d;
    cin >> d;
    node *head = NULL;
    while (d != -1)
    {
        insert(head, d);
        //insertTail(head, d);
        cin >> d;
    }
    return head;
}
node *midpoint(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    node *slow = head;
    node *fast = head->next;
    while (fast->next != NULL and fast != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool detect_cycle(node *head)
{
    node *s = head;
    node *f = head;

    while (f->next != NULL and f != NULL)
    {
        f = f->next->next;
        s = s->next;
        if (f == s)
        {
            return true;
        }
    }
    return false;
}
node *break_cycle(node *head)
{
    node *s = head;
    node *f = head;

    while (fast->next != NULL and fast != NULL)
    {
        f = f->next->next;
        s = s->next;
        if (f == s)
        {
            s = head;
            break;
        }
    }
    while (f != s)
    {
        f = f->next;
        s = s->next;
    }
    node* n = s;
    node*temp = n;
    while(temp->next!=n){
        temp=temp->next;
    }
    temp->next = NULL;
}
int main()
{
    node *head = take_input();
    print(head);
    node *mid = midpoint(head);
    cout << mid->data;
}

  
