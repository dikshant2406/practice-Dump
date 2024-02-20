#include<bits/stdc++.h>
using namespace std ;

// Abstract Car class

class Car {
    // virtual Car(string company , string model) = 0 ;
    public:
    virtual void getCarName() = 0 ;
    virtual int getCost() = 0 ;  
} ;

class fordMustang : public Car {
    private :
        string company ;
        string model ;

    public:
        fordMustang(string c, string m) {
            company = c ;
            model = m ;
        }
        void getCarName() override {
            cout<<"Your new exotic car name is: "<<company<<' '<<model<<endl ;
        }
        int getCost() override{
            return 150 ;
        }
};

class nissanGtr : public Car {
    private :
        string company ;
        string model ;

    public:
        nissanGtr(string c, string m) {
            company = c ;
            model = m ;
        }
        void getCarName() override {
            cout<<"Your new exotic car name is: "<<company<<' '<<model<<endl ;
        }
        int getCost() override{
            return 250 ;
        }
};

class ICarDecorator: public Car {

};

class nitroGas: public ICarDecorator {

    private: 
    int noOfNitros ;
    Car* vahan ;

    public:

    nitroGas(Car* c, int n) {
        noOfNitros = n;
        vahan = c ;
    }
    void getCarName() override {
        vahan->getCarName() ;
    }
    int getCost() override {
        return vahan->getCost() + noOfNitros*5 ;
    }
};

class spoilers: public ICarDecorator {
    private: 
    int noOfSpoilers ;
    Car* vahan ;

    public:
    spoilers(Car* c, int n) {
        noOfSpoilers = n;
        vahan = c ;
    }
    void getCarName() override {
        vahan->getCarName() ;
    }
    int getCost() override {
        return vahan->getCost() + noOfSpoilers*15 ;
    }
};
int main() {
    Car* c1 = new fordMustang("Ford", "mustang") ;
    // c1 = new nissanGtr("Nissan", "skyline");
    c1 = new nitroGas(new spoilers(new nissanGtr("Nissan", "skyline"), 1), 2) ;

    cout<<c1->getCost() ;
    cout<<endl 
    ; c1->getCarName() ;
}