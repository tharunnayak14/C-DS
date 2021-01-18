#include <bits/stdc++.h>
using namespace std;
void stock_span(int *ar, int n)
{
    vector<int> span;
    stack<int> s;
    s.push(0);
    span.push_back(1);
    for (int i = 1; i < n; i++)
    {
        int cur_price = ar[i];
        // remove all the smaller elements below 
        while(!s.empty() and cur_price>ar[s.top()]){
            s.pop();
        }
        if(!s.empty()){
            int prev_highest = s.top();
            span.push_back(i-prev_highest);
        }
        else{
            span.push_back(i+1);
        }
        //push this element into the stack
        s.push(i);
    }
    for (int x : span)
    {
        cout << x << " ";
    }
}

int main()
{
    
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    stock_span(ar, n);
    cout<<"END"<<endl;
}