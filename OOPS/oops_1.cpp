#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace  std;
//creating a class
class car{
private:
    int price;
public:
    int model;
    string name;
    car(){
        cout << "inside constructor"
             << "\n";  // constructor
    }
    car(float p, int m, string n ){ // parameterised constructor
        price = p;
        model = m;
        name = n;
    }
    void print(){
        cout << "Name " << name << "\n";
        cout << "Model " << model << "\n";// no need to use c.name, c.model etc
        cout << "Price " << price << "\n";
        cout << "\n";
    }
    float get_discount(int x){
        return price*(1.0-(x/100.0));
    }
    void get_price(){
        cout << price << "\n";
    }
    void update_price(int p){
        int min = 10;
        if(p>min){
            price = p;
        }
        else{
            price = min;
        }
    }
    void apply_discount(float x){
        price = get_discount(x);
    }
};
int main(){

    //creating object
    car c,d,e,f; // constructor
    //cout << sizeof(c) << " " << sizeof(car) << "\n";
    //initialising object
    //c.price = 100; price is private so no initialization
    c.model = 3772;
    c.name = "BMW";
    car h(12, 3433, "tharun");
    //printing object
    //cout << c.name << " " << c.model << " " << c.price << "\n";
    /*
    float discount;
    cin >> discount;
    cout << c.get_discount(discount) << "\n";
    */

    //c.print();

    //c.apply_discount(discount);

    //c.print();

    c.update_price(-1);

    c.get_price();

    c.update_price(123);

    c.get_price();

    return 0;
}