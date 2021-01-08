#include<iostream>
#include<string>
using namespace std;

int main(){
    string s1("hello ");

    string s2 = "hello";

    string s3(s2);

    string s4 = s3;

    char ar[] = {'h', 'e', 'l', 'l', 'o','\0'};
    string s5(ar);

    cout << s1 << "\n";
    cout << s2 << "\n";
    cout << s3 << "\n";
    cout << s4 << "\n";
    cout << s5 << "\n";

    // methods on strings

    if(s1.empty()){
        cout << "Empty string"
             << "\n";
    }

    // append
    s1.append("I love c++");
    cout << "s1 after appending:-" << s1 << "\n";

    // length

    cout << s2.length() << "\n";

    // remove
   s2.clear();

    cout << s2.length()<<'\n';

    // compare lexographically

    cout << s3.compare(s4)<<'\n'; // 0 if equal 

    // overload

    s1 > s2;
    s1 < s2;

    // indexing

    cout << s1[3] << '\n';

    // find

    string n = "I love love my country";

    int index = n.find("love");
    cout <<"love found at index " <<index << "\n";

    // remove a word
    string word = "love";
    int l = word.length();
    n.erase(index, l+1); // start and length are 2 parameters
    cout << n << "\n";

    // iterating over strings

    for (int i = 0; i < n.length();i++){
        cout << n[i] << ",";
    }
    cout << "\n";

    // using iterators s.begin(), s.end()

    for (auto it = n.begin(); it != n.end(); it++){
        cout << *it << " ";// use *it as it is a pointer
    }
    cout << "\n";

    
    string s = "abcdef";
    s.substr(4,6);
    
    string s1 = "762";
    int x = stoi(s1);
    
    int y = 92;
    string s2 = tostring(y);
    // for each loop

    for(char x:n){
        cout << x << ".";
    }

    return 0;
}
