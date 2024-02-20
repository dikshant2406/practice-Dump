#include<bits/stdc++.h>
using namespace std ;

class base {
    public :
    base() {
        cout<<"base"<<endl; 
    }

    virtual void printBase() {
        cout<<"printBase"<<endl ;
    }

    void displayBase() {
        cout<<"Display Base"<<endl ;
    }
} ;

class derived : public base {
    public:

    derived() {
        cout<<"derived"<<endl ;
    }

    void printBase() {
        cout<<"printDerived"<<endl ;
    }

     void displayBase() {
        cout<<"Display Derived"<<endl ;
    }
};

int main () {
    base* bptr ;

    derived d = derived() ;
    bptr = &d ;
    bptr->printBase() ;
    bptr->displayBase() ;
}