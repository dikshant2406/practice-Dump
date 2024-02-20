#include<bits/stdc++.h>
using namespace std ;

class base {
    public :
        base() ;
        void printBase() {
            cout<<"base"<<endl ;
        }
} ;

// base::base() {
//     cout<<"from outside"<<endl ;
// } ;

int main () {
    base b ;
    return 0;
}