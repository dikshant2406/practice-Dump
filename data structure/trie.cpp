#include<bits/stdc++.h>

using namespace std ;

struct Node {
    Node* key[26] ;
    bool isEndHere = false ;
};

class Trie {
    private: 
        Node* root ;
    public: 

        Trie () {
            root = new Node ;
        }

        void insert(string str) {
            Node* newRoot = root ;
            for(int i = 0 ; i < str.size() ; i++ ){
                if(newRoot->key[str[i] - 'a'] == nullptr){
                    newRoot->key[str[i] - 'a'] = new Node ;
                }

                newRoot = newRoot->key[str[i] - 'a'] ;
            }

            newRoot->isEndHere = true ;
            return;
        }

        bool search(string str) {
            Node* newRoot = root ;
            for(int i = 0 ;i < str.size() ; i++ ){
               if(newRoot->key[str[i] - 'a'] == nullptr){
                    return false ;
                }
                newRoot = newRoot->key[str[i] - 'a'] ;
            }

            return newRoot->isEndHere ;
        }

        bool startsWith(string str) {
            Node* newRoot = root ;
            for(int i = 0 ;i < str.size() ; i++ ){
               if(newRoot->key[str[i] - 'a'] == nullptr){
                    return false ;
                }
                newRoot = newRoot->key[str[i] - 'a'] ;
            }
            return newRoot != nullptr ;
        }
};

int main() {
    Trie trie = Trie() ;
    trie.insert("string") ;
    cout<<trie.search("string")<<endl;
    cout<<trie.startsWith("string");

    return 0 ;
}