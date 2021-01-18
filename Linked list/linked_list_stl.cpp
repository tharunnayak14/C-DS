#include <iostream>
#include <list>
#include <string>
using namespace std;
void print(list<int> l)
{
    for (auto n : l)
    {
        cout << n << " -> ";
    }
    cout << "\n";
}
int main()
{
    list<int> l;

    // initialization
    list<int> l1{1, 23, 3, 4, 56, 4, 77};

    list<string> l2{"apple", "banana"};

    cout << "Normal ";
    print(l1);

    //sort
    cout << "Sorted ";
    l1.sort();
    print(l1);

    //reverse
    cout << "Reversed ";
    l1.reverse();
    print(l1);

    //remove front
    cout << "Pop front ";
    l1.pop_front();
    print(l1);

    //add front
    cout << "push front ";
    l1.push_front(99);
    print(l1);

    //remove last
    cout << "Pop back ";
    l1.pop_back();
    print(l1);

    //add last
    cout << "Push back ";
    l1.push_back(1000);
    print(l1);

    // some more functions

    //remove all occurances of a number
    cout << "Remove all occurances of four ";
    l1.remove(4);
    print(l1);

    //erase element at an index
    auto it = l1.begin();
    it++;
    it++;
    // 2 times to del 3rd element
    l1.erase(it);
    print(l1);

    // insert elements
    it = l1.begin();
    it++;
    l1.insert(it, 3423);
    print(l1);
    return 0;
}