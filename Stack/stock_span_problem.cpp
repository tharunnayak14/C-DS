#include <bits/stdc++.h>
using namespace std;
void stock_span(int *ar, int n)
{
    // stack<pair<int, int>> s;
    // s.push(make_pair(0, ar[0]));
    vector<int> span;
    stack<int> s;
    s.push(0);
    span.push_back(1);
    for (int i = 1; i < n; i++)
    {
        // while (!s.empty() and ar[i] > s.top().second)
        // {
        //     s.pop();
        // }
        // span.push_back(i - (s.top().first));
        // s.push(make_pair(i, ar[i]));
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
        s.push(i);
    }
    for (int x : span)
    {
        cout << x << " ";
    }
}

int main()
{
    int ar[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(ar) / sizeof(int);
    stock_span(ar, n);
}