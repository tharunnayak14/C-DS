#include <iostream>
using namespace std;
class queue
{
    int *arr;
    int max_size, front, rear, cur_size;

public:
    queue(int size = 100)
    {
        arr = new int[size];
        cur_size = 0;
        front = 0;
        max_size = size;
        rear = max_size - 1;
    }
    bool isfull()
    {
        return cur_size == max_size;
    }
    bool isempty()
    {
        return cur_size == 0;
    }
    void push(int data)
    {
        if (!isfull())
        {
            rear = (rear + 1) % max_size; // important
            arr[rear] = data;
            cur_size++;
        }
    }
    void pop()
    {
        // increment the front to next element for popping
        if (!isempty())
        {
            front = (front + 1) % max_size;
            cur_size--;
        }
    }
    int front_element()
    {
        if (!isempty())
        {
            return arr[front];
        }
        return -1;
    }
    ~queue()
    {
        if (arr != NULL)
        {
            delete[] arr;
            arr = NULL;
        }
    }
};

int main()
{
    queue q;
    for (int i = 0; i < 6; i++)
    {
        q.push(i);
    }
    cout << q.front_element() << "\n";
    q.pop();
    cout << q.front_element() << "\n";
    q.pop();
    cout << q.front_element() << "\n";
    q.pop();
    cout << q.front_element() << "\n";
    q.pop();
    cout << q.front_element() << "\n";
    q.pop();
    cout << q.front_element() << "\n";
    q.pop();
}
