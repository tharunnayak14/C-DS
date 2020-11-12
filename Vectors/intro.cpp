#include<iostream>

#include<vector>// header file
using namespace std;

int main(){
    //vector is a class
    vector<int> a;// vector object
    vector<int> b(5, 10); // 5 integers with value 10
    vector<int> c(b.begin(), b.end()); // creates new vector c and copies values of b into it
    vector<int> d{1, 2, 3, 4, 5};

    for (auto it = d.begin(); it != d.end();it++){
        cout << *it <<" ";
    }
    cout << "\n";
    // for each loop
    for (int x:d){
        cout << x << " ";
    }

    int n;
    cin>> n;
    vector<int> v;
    for (int i = 0; i < n;i++){
        int no;
        cin >> no;
        v.push_back(no);
    }
    cout << v.size() << " " << v.max_size() << " " << v.capacity() << "\n";
    cout << b.size() << " " << b.max_size() << " " << b.capacity() << "\n";
    return 0;
}