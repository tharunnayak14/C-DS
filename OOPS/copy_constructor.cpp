#include<iostream>
#include<string>
using namespace std;
class car{
private:
    int price;
public:
    int model;
    string name;
    car(){
        cout << "Constructor"
             << "\n";
    }
    car(car &x){ //pass by ref // copy constructor
        cout << "Copy constructor"
             << "\n";
        price = x.price;
        model = x.model;
        name = x.name;
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
    car c;
    c.name = "tharun";
    c.model = 807;
    c.update_price(124);
    cout << "Car c"
         << "\n";
    c.print();

    car d(c); // copy constructor

    cout << "Car D"
         << "\n";
    d.update_price(-1);
    d.print();
    return 0;
}