#include<bits/stdc++.h>
using namespace std ;

template<class K, class V> 
class HashNode {

    public: 
    K key ;
    V value ;
    HashNode* next ;
    HashNode* prev ; 
    HashNode(K k, V v) {
        key = k ;
        value = v ;
    }

    V getValue(K k){
        return this->value ;
    }

};

template<class K, class V > 
class HashMap {
    private:
    vector<HashNode<K,V>*> arr ;
    int size ;

    public :
    HashMap() {
        size = 100 ;
        arr = vector<HashNode<K,V>*> (size, nullptr) ;    
    }

    void put(K k, V v) {
        K key = k%size ;
        if(arr[key] == nullptr) {
            HashNode<K,V>* h = new HashNode<K,V>(k,v) ;
            h->next = nullptr ;
            h->prev = nullptr ;
            arr[key] = h ;
        }else {
            auto h = arr[key] ;
            auto prev = arr[key] ;
            while(h->next != nullptr) {
                prev = h ;
                h = h->next ;
            }
            HashNode<K,V>* newH = new HashNode<K,V>(k,v) ;
            h->next = newH ;
            h->prev = prev ;
        }
        return ;
    }

    HashNode<K,V>* get(K k ) {
       K key = k%size ;
       HashNode<K,V>* h = arr[key] ;
       while(h != nullptr && h->key != k) {
        h = h->next ;
       }

       if(h == nullptr) {
        cout<<"No value found"<<endl ;
       } 

       return h ;
    }

    void remove(K k) {
        K key = k%size ;
        HashNode<K,V>* h = arr[key] ;
        if(h == nullptr ){
            return  ;
        }
        if(h->key == k){
            arr[key] = h->next ;
            return ;
        }
        while(h != nullptr && h->key != k) {
            h = h->next ;
        }
        if(h == nullptr){
            return ; 
        }
        if(h->next == nullptr){
            h->prev = nullptr ;
            return ;
        }
        h->prev = h->next ;
        h->next = h->prev ;

        delete h ;
        return ;
    }


    ~HashMap() {
        delete this ;
    }
};

int main() {
    HashMap<int, string> mp ;
    mp.put(2,"two") ;
    mp.remove(2) ;
    mp.put(3, "three");
    cout<<mp.get(3)->value<<endl; 

}