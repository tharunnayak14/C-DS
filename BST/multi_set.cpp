#include<iostream>
#include<set>
using namespace std;

typedef multiset<int>::iterator IT;
int main(){

    // underlying data structure - BST
    // can have same multiple elements

    int ar[] = {10, 20, 30, 20, 10, 10};
    multiset<int> m(ar, ar + 6);


    //erase all occurances of 20
    m.erase(20);

    //insert
    m.insert(80);

    //count
    cout <<"Count of 10 "<< m.count(10)<<"\n";

    //find
    multiset<int>::iterator it = m.find(10);
    cout << *it << "\n";

    //get all elements equal to 30
    pair<IT, IT> range = m.equal_range(30);

    for (auto it = range.first; it != range.second; it++){
        cout << *it << " ";
    }
    cout << "\n";

    //lower bound  >= and upper bound >
    for (multiset<int>::iterator it = m.lower_bound(10); it != m.upper_bound(77);it++){
        cout << *it << " ";
    }
    cout << "\n";

    for (multiset<int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << *it << " ";
        }
    return 0;
}