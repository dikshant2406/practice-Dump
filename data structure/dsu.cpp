#include<bits/stdc++.h>

using namespace std ;

class DisjointSet {
    vector<int> rank, parent, size ;
    public: 

    DisjointSet(int n) {
        rank = vector<int> (n+1, 0) ;
        parent = vector<int> (n+1) ;
        size = vector<int> (n+1) ;

        for(int i = 0 ; i < n ; i++) {
            parent[i] = i ;
            size[i] = 1 ;
        }
    }

    bool isSameSegment(int u, int v) {
        return findParent(u) == findParent(v) ;
    }

    int findParent(int n) {
        if(parent[n] == n) {
            return n ;
        }

        return parent[n] = findParent(parent[n]) ;
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u) ;
        int pv = findParent(v) ;

        if(pu == pv) {
            return ;
        }

        if(rank[pu] < rank[pv]) {
            parent[u] = pv ;
        } else if(rank[pv] < rank[pu]) {
            parent[v] = pu ;
        } else {
            parent[v] = pu ;
            rank[u]++ ;
        }
        return ;
    }     

    void unionBySize(int u, int v) {
        int pu = findParent(u) ;
        int pv = findParent(v) ;

        if(pu == pv) {
            return ;
        }

        if(size[pu] < size[pv]) {
            parent[pu] = pv ;
            size[pv] += size[pu] ;
        }else {
            parent[pv] = pu ;
            size[pu] += size[pu] ;
        }
        return ;
    }
} ;

int main() {
    DisjointSet dsu = DisjointSet(5) ;
    dsu.unionBySize(1,2) ;
    dsu.unionBySize(2,3) ;
    cout<<dsu.isSameSegment(5,3) ;
    cout<<dsu.isSameSegment(1,2) ;
    dsu.unionBySize(4,5) ;
    cout<<dsu.isSameSegment(4,1) ;
    dsu.unionBySize(5,3) ;
    cout<<dsu.isSameSegment(4,1) ;
    return 0 ;
}