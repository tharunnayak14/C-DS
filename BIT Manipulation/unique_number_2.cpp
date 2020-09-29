#include<iostream>
using namespace std;

int main() {
    int n,r=0;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n;i++)
    {
        cin >> ar[i];
        r = r ^ ar[i];
    }
    //cout << r << "\n";
    int pos=0;
    int t = r;
    while(r!=1)
    {
        r= r >> 1;
        pos++;
    }
    //cout << pos << "\n";
    int new_res = 0;
    for (int i = 0; i < n;i++)
    {
        if(ar[i]&(1<<pos)>0)
        {
            new_res = new_res ^ ar[i];
        }
    }
	int x = new_res^t;
	if(new_res>x){
		cout<<x<<" "<<new_res;
	}
	else{
		cout<<new_res<<" "<<x;
	}
}