#include<iostream>
#include<list>
using namespace std;

int main(){

    list<pair<int, int>> *l;
    int n;
    cin>>n;

    l = new list<pair<int, int>>[n]; // pointer to array of ll's
    int edges;
    cin>>edges;

    for(int i=0;i<edges;i++){
        int x,y,dist;
        cin>>x>>y>>dist;

        l[x].push_back(make_pair(y, dist));
        l[y].push_back(make_pair(x, dist));
    }

    for(int i=0;i<n;i++){
        for(auto s:l[i]){
            cout<<"("<<s.first<<", "<<s.second<<")"<<", ";
        }
        cout<<endl;
    }

    return 0;
}