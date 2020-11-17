#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> v){
   for(int i=0;i<v.size();i++){
      cout<<v[i]<<" ";
   }
   cout<<"\n";
}
int main()
{
   vector<int> v;
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);
   v.push_back(4);
   v.push_back(5);

   print(v);

   v.pop_back();

   print(v);

   v.insert(v.begin() + 3, 100);// inserts after 3 elements

   print(v);

   v.insert(v.begin() + 3, 4, 99);// inserts 99 four times after 3 elements

   print(v);

   v.erase(v.begin() + 2); // erases 3rd element

   print(v);

   v.erase(v.begin() + 5, v.end());// erases a part of vector

   print(v);

   cout << v.size() << "\n";

   if (v.empty())
   {
      cout << "wtf its mt"
           << "\n";
   }
   cout << v.front() << "\n";
   cout << v.back() << "\n";

   vector<int> v;
   v.reserve(2000); // as doubling is expensive always reserve memory
   
   cout<<*max_element(v.begin(), v.end());
   cout<<*min_element(v.begin(), v.end());
   
   return 0;
   
}
