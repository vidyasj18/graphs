#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// DISJOINT SET: VV IMP for OA's
// rank can be quoted as heirarchy

class DisjointSet {
    vector<int> rank,parent,size;

public:
    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);

        for(int i = 0; i<=n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) 
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Union by Rank:
    void unionByRank(int u,int v) {
        // ultimate parents
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        // they are already united 
        if(ulp_u == ulp_v) return;

        if(rank[ulp_u]<rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }

        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }

        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

    }

    // union by Size:
    void unionBySize(int u,int v) {
        // ultimate parents
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        // they are already united 
        if(ulp_u == ulp_v) return;

        if(size[ulp_u]<size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_v];
        }

        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

    }
};


int main() {

    return 0;
    // union by rank
    // to get union by size, change it to ds.unionbySize function.
    // rest is same.

    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "same" << endl;
    }

    else cout << "Not same" << endl;

    ds.unionByRank(3,7);

    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "same" << endl;
    }

    else cout << "Not same" << endl;
}