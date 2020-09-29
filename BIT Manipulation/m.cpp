#include<iostream>
#include<algorithm>
using namespace std;
bool compare(int a, int b){
	return b<a;
}
int main() {
	int n;
	cin>>n;
	int arr[10000];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int t;
	cin>>t;
	while(t--){
		int key;
		cin>>key;
bool present = binary_search(arr, arr + n, key);
    if (present) {


    auto lb = lower_bound(arr, arr + n, key);
    cout  << (lb - arr) << " ";


    //uppper bound method
    auto ub = upper_bound(arr, arr + n, key, compare);
    cout << (ub - arr) << endl;
	}
		else{
			cout<<-1<<" "<<-1;
		}
	}
	return 0;
}