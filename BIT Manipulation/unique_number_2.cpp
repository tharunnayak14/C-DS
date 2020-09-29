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
    int pos=0;
    int old_result = r;
    while(r!=1)
    {
        r= r >> 1; // finds the pos of set bit in the result
        pos++;
    }
    int new_res = 0;
    // now take xor of all elements which have a set bit at pos
    for (int i = 0; i < n;i++)
    {
        if(ar[i]&(1<<pos)>0) //1<<i mask
        {
            new_res = new_res ^ ar[i]; //new_res has xor of all elements which have a set bit at pos
        }
    }
    //now new_res has 1 element and for other take xor of new result and old_result
	int x = new_res^old_result;
	if(new_res>x){
		cout<<x<<" "<<new_res;
	}
	else{
		cout<<new_res<<" "<<x;
	}
	return 0;
}
