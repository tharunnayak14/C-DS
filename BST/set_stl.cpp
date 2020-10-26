#include<iostream>
#include<set>
using namespace std;

int main(){

    set<int> s;
    // set stores only unique elements in sorting order
    // if input is 1,1,4,3,2,5,5,6,5,7 set stores them as 1,2,3,4,5,6,7
    // data structure in set is a tree like one (red black tree)
    // insertion and deletion take O(log n)

    int ar[] = {1, 1, 4, 3, 2, 5, 5, 6, 5, 7};
    int n = sizeof(ar) / sizeof(int);

    for (int i = 0; i < n;i++){
        s.insert(ar[i]);
    }

    s.erase(4);
    
    for (set<int>::iterator it = s.begin(); it != s.end(); it++){
        cout << *it<<" ";

    }

        return 0;
}
