#include<bits/stdc++.h>

using namespace std ;


// strategy interface
class dialpadStrategy {
    public :
        virtual void dialpad() = 0 ;
        virtual ~dialpadStrategy() {} ;
};

class Mobile{

    public :
        dialpadStrategy* strategy ;

        // constructor injection
        Mobile(dialpadStrategy * d) {
            this->strategy = d ; 
            cout<<"Mobile class constructor"<<endl ;
        }

        void dialpad() {
            strategy->dialpad() ;
        }

};

//strategy 1

class screentouch : public dialpadStrategy {
    public: 
        screentouch() {
            cout<<"screentouch strategy constructor"<<endl; 
        }

    void dialpad() override{
        cout<<"dialpad strategy screenstouch"<<endl;
    }
};

// strategy 2

class buttontouch : public dialpadStrategy {
    public: 
        buttontouch() {
            cout<<"buttontouch strategy constructor"<<endl; 
        }

    void dialpad() override {
        cout<<"dialpad strategy buttontouch"<<endl;
    }
};

int main() {
        Mobile m = Mobile(new screentouch());
        m.dialpad();
        return 0;
}