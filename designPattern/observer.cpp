#include<bits/stdc++.h>

using namespace std ;

// Publisher class


class ISubscriber {
    virtual void update(string m) = 0;
};

class Subscriber :public ISubscriber {

    private:
     string name ;
    public:
    Subscriber(string n) {
        name = n ;
    }
    void update (string message) {
        cout<<"Message from publisher: "<<message<<endl ;
    }
};

class Publisher {
    private: 
        vector<Subscriber*> list ;
        string state ;

    public:
        void attach(Subscriber* s) {
            list.push_back(s) ;
        }

        void dettach(Subscriber* s) {
            //  auto it = find(list.begin(), list.end(), s);
            // list.erase(it) ;
        }

        void setState(string message) {
            state = message ;
            notify() ;
        }

        void notify() {
            for(int i = 0 ; i < list.size() ; i++) {
                list[i]->update(state);
            }
        }

};

int main() {

    Publisher p ;

    Subscriber s1 = Subscriber("sub 1") ;
    Subscriber s2 = Subscriber("sub 2");

    p.attach(&s1) ;
    p.attach(&s2) ;

    p.setState("new message");

    return 0 ;
}