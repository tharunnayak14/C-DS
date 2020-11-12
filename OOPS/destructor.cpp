#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class car{
private:
    float price;
public:
    int model;
    char *name;
    car(){
        name = NULL;
    }
    car(float f,int m, char * n){
        price = f;
        model = m;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    car(car &x){
        price = x.price;
        model = x.model;
        //name = x.name; this makes the copy consturctor a shallow copy
        name = new char[strlen(x.name) + 1]; // this is used for deep copy
        strcpy(x.name, name);
    }
    void print(){
        cout << "Name " << name << "\n";
        cout << "Model " << model << "\n";// no need to use c.name, c.model etc
        cout << "Price " << price << "\n";
        cout << "\n";
    }
    ~car(){
        if(name!=NULL){
            delete[] name;
            cout << "destorying car " << name << "\n";
        }
    }
};

int main(){
    car c(100, 3772, "tahrun");
    car d(c);
    d.name[0] = 'a'; // both change as it is a shallow copy so we need a deep copy so write own copy constructor
    c.print();
    d.print();

    car *e = new car(10, 20, "freeea");
    e->print();
    delete e; // for dynamically created
}