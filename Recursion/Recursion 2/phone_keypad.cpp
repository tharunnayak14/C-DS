// #include <bits/stdc++.h>
// using namespace std;
// char keyMapping[][10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

// void phoneKey(int in[], char out[], int i, int j)
// {
// 	if(in[i]==-1)
// 	{
// 		out[j]='\0';
// 		cout<<out<<" ";
// 		return;
// 	}
// 	int digit=in[i];
// 	if(digit==0 or digit==1)
// 	{
// 		phoneKey(in,out,i+1,j);
// 	}
// 	for(int k=0;keyMapping[digit][k]!='\0';k++)
// 	{
// 		out[j]=keyMapping[digit][k];
// 		phoneKey(in,out,i+1,j+1);
// 	}
// }


// int main()
// {
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 		int n;
// 		cin>>n;
// 		int in[n+1];
// 		memset(in,-1,sizeof(in));
// 		for(int j=0;j<n;j++)
// 		{
// 			cin>>in[j];
// 		}
// 		char out[n];
// 		phoneKey(in,out,0,0);
// 	}

// 	return 0;
// }
#include<iostream>
#include<cstring>
using namespace std;
char keypad[][10] = { " ","abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wx","yz" };
void print(char* in , char* out, int i, int j, int &count)
{
     /// base case
     
     if(in[i]=='\0')
     {
         out[j]=='\0';
         cout<<out<<" ";
         count++;
         return;
     }

     /// rec case
     int digit=in[i]-'0';
    // if( digit==0)
     //{
      //   print(in,out,i+1,j);
     //}

     for(int k=0;keypad[digit][k]!='\0';k++)
     {
         out[j]= keypad[digit][k];
         print(in ,out, i+1, j+1,count);
     }
}

int main()
{
   char in[11];
   char out[11]={0};
   cin>>in;
   int count=0;
   print(in,out,0,0,count);
   cout<<endl;
   cout<<count<<endl;
   return 0;

}

