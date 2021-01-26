#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare(pair<int, int> a, pair<int,int>b)
{
    return a.first > b.first;
}
int main()
{

    int t, n, d, f, D, F, prev = 0, x, flag = 0,ans=0;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> v;
        priority_queue<int> pq;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> d >> f;
            v.push_back(make_pair(d, f));
        }

        //logic
        sort(v.begin(), v.end(), compare);

        cin >> D >> F;

        //update the distance of fuel station from the truck
        for (int i = 0; i < n; i++)
        {
            v[i].first = D - v[i].first;
        }

        //prev denotes the prev fuel station we visited
        prev = 0;
        x = 0; //current location

        while (x < n)
        {
            // if we have enough fuel to go to next city
            if (F >= v[x].first - prev)
            {
                F -= (v[x].first - prev);
                pq.push(v[x].second);
                prev = v[x].first;
            }
            //cannot reach next city
            // check if u visited some stations in pq
            else
            {
                if (pq.empty())
                {
                    flag = 1;
                    break;
                }
                //refuel the truck with fuel stations with higher capacity
                F += pq.top();
                //remove that fuel station form pq
                pq.pop();
                ans += 1;
                continue;
            }

            x++;
        }
        // actually travelled to n fuel stations
        // reach town from last fuel station

        if (flag == 1)
        {
            cout << -1 << endl;
            continue;
        }
        D = D - v[n - 1].first;
        if (F >= D)
        {
            cout << ans << endl;
            continue;
        }
        while (F < D)
        {
            if (pq.empty())
            {
                flag = 1;
                break;
            }
            F += pq.top();
            pq.pop();
            ans++;
        }

        if (flag == 1){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<endl;
    }

    return 0;
}