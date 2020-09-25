#include<iostream>
#include<queue>
using namespace std;


int main(){
    queue<char> q;
    int freq[27] = {0};

    char ch;
    cin >> ch;
    while(ch!='.'){
        //puch the character into the queue
        q.push(ch);
        //ch-'a' gives the integral index of alphabet
        freq[ch - 'a']++;

        while(!q.empty()){
            int element = q.front()-'a';// find the index of first element
            if(freq[element]>1){ // if its freq is greater than 1 pop it
                q.pop();
            }
            else{
                cout << q.front() << "\n"; //else print
                break;
            }
        }
        //if queue is empty
        if(q.empty())
        cout << "-1"
             << "\n";

        cin >> ch;

    }
}