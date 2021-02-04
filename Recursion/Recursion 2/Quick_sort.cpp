#include <bits/stdc++.h>
using namespace std;
int partition(int a[], int s, int e)
{
    int i = s - 1;
    int j = s;

    int pivot = a[e];
    for (; j < e; j++)
    {
        if (a[j] <= pivot)
        {
            // merge smaller elements into smaller array

            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}
void quick_sort(int ar[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(ar, s, e);
    quick_sort(ar, s, p - 1);
    quick_sort(ar, p + 1, e);
}
int main()
{
    int ar[] = {2, 7, 8, 6, 1, 5, 4};
    int n = sizeof(ar) / sizeof(ar[0]);
    quick_sort(ar, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    return 0;
}