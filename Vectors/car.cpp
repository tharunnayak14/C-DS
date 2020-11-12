#include<bits/stdc++.h>

using namespace std;
class car{
    public:
        int p1, p2;
        string car_name;
    car(string s, int x, int y){
        car_name = s;
        pl = x;
        p2 = y;
    }
    void dist(){
        return p1 * p1 + p2 * p2;
    }
};
/*
bool compare(pair<int, int >p1, pair<int, int>p2){
    int d1 = p1.first * p1.first + p1.second * p1.second;
    int d2 = p2.first * p2.first + p2.second * p2.second;
    if(d1==d2){
        return p1.first < p2.first;
    }
    return d1 < d2;
}
*/
bool compare(car a, car b){
    int d1 = a.dist();
    int d2 = b.dist();
    if(d1==d2){
        return a.lenght() < b.lenght();
    }
    return d1 < d2;
}
int main(){
    /*
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    v.reserve(1000);

    for (int i = 0; i < n;i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), compare);

    for(auto x:v){
        cout <<"car"<<" "<< x.first << " "<<x.second<<"\n";
    }
    */
    int n;
    cin >> n;
    vector<car> v;
    for (int i = 0; i < n;i++){
        int x, y;
        string name;
        cin >> name;
        cin >> x >> y;
        car temp(name, x, y);
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compare);

    for(auto c:v){
        cout << "car " << c.car_name << " "
             << "Location " << c.p1 << " " << c.p2 << "\n";
    }

}