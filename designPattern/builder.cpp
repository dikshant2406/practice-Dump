#include<bits/stdc++.h> 
using namespace std ;

class url {
    private: 
    
    public:
    string protocol ;
    string hostName ;
    string port ;
    string path ;
    string query ;

    url() {
        this->protocol = "" ;
        this->hostName = "" ;
        this->port = "" ;
        this->path = "" ;
        this->query = "" ;
    }

    string getProtocol() {
        return this->protocol ;
    }
    string getHostName() {
        return this->hostName ;
    }
    string getPort() {
        return this->port ;
    }
    string getPath() {
        return this->path ;
    }

    string getQuery() {
        return this->query ;
    }
    void printURL() {
        cout<<this->protocol+this->hostName+this->port+this->path+this->query ;
    }
};

class urlBuilder {

    public :
    url* u  ;

    urlBuilder() {
        u = new url() ;
    }

    urlBuilder* protocol(string a) {
        u->protocol = a ;
        return this ;
    }
    urlBuilder* hostName(string a) {
        u->hostName = a ;
        return this ;
    }  
    urlBuilder* port(string a) {
        u->port = a ;
        return this ;
    } 
    urlBuilder* path(string a) {
        u->path = a ;
        return this ;
    } 
    urlBuilder* query(string a) {
        u->query = a ;
        return this ;
    } 
    

    url* build() {
        return u ;
    }
};
int main() {
    urlBuilder* ub = new urlBuilder() ;
    url* u = ub->protocol("https://")->hostName("youtube.com")->path("/videos")->query("?quality=1080p&utm=facebook")->build() ;
    u->printURL() ;
    return 0 ;
}