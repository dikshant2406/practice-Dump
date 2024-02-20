#include<bits/stdc++.h>
using namespace std ;

class Node {
    public :
    Node() {

    }
    int key ;
    int value ;
    Node* left;
    Node* right ;
    Node(int k, int v) {
        key = k ;
        value = v ;
        left = nullptr ;
        right = nullptr ;
    } 
};

class LRU {
    private:
    int size ;
    Node* first ;
    Node* last ;
    unordered_map<int, Node*> mp ;

    public :
    LRU(int n) {
        size = n ;
        first = new Node(-1,-1) ;
        last = new Node(-1,-1) ;
        first->right = last ;
        last->left = first ;
    }

    void addNode(Node* n) {
       Node* temp = first->right  ;
       n->left = first ;
       n->right = temp ;
       temp->left = n ;
       first->right = n ;
    }

    void removeNode(Node* n) {
        n->left->right = n->right ;
        n->right->left = n->left ;
        // delete n ;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* n = new Node(key, mp[key]->value) ;
            removeNode(mp[key]);
            addNode(n) ;
            mp[key] = n ;
            return mp[key]->value ;
            
        }

        return -1 ;
    }

    void put(int key, int value) {
        if(mp.find(key) == mp.end()) {
            if(mp.size() == size) {
                mp.erase(last->left->key) ;
                removeNode(last->left) ;
            }
            Node* newNode = new Node(key, value);
            addNode(newNode) ;
            mp[key] = newNode ;
        }else if(mp.find(key) != mp.end()) {
            removeNode(mp[key]) ;
            mp.erase(key) ;
            Node* n = new Node(key, value) ;
            mp[key] = n ;
            addNode(n) ;
        }
    }
    
};

int main() {
    LRU* l = new LRU(2);

    l->put(1,1) ;
    l->put(2,2) ;
    cout<<l->get(1)<<endl; ;
    l->put(3,3) ;  
    cout<<l->get(2)<<endl; ;
    l->put(4,4) ;
    cout<<l->get(1)<<endl; ;
    cout<<l->get(3)<<endl; ;
    cout<<l->get(4)<<endl; ;
}