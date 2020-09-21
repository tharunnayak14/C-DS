#include<iostream>
#include<list>
using namespace std;

void print(list<int> l){
    for(auto n:l){
        cout<<n<<" ->";
    }
    cout<<"\n";
}
int main(){
    list<int> l;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        l.push_back(x);
    }
    int k;
    cin >> k;
    auto it = l.begin();
    int t = n - k-1;
    while(t--){
        it++;
    }
    print(l);
}