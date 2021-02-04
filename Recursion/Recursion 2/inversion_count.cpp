#include <bits/stdc++.h>
using namespace std;

int mergee(int *a, int s, int e)
{
    int mid = (s + e) / 2;
    int temp[10000];
    int i = s;
    int j = mid + 1;
    int k = s;

    int ans = 0;
    while (i <= mid and j <= e)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            // imp step
            ans += mid - i + 1;
            temp[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= e)
    {
        temp[k++] = a[j++];
    }
    for(int i=s;i<=e;i++){
        a[i] = temp[i];
    }

    return ans;
}

int inversion_count(int *a, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    int x = inversion_count(a, s, mid);
    int y = inversion_count(a, mid + 1, e);
    int z = mergee(a, s, e);
    return x + y + z;
}

int main()
{
    int a[] = {1, 5, 2, 6, 3, 0};
    //inversion a[i]>a[j] for i < j
    int n = sizeof(a) / sizeof(int);
    cout << inversion_count(a, 0, n - 1);

    return 0;
}