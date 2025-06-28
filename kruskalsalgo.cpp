#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// used to find wt in MST 
// algo uses disjoint set and union
// can use unionByrank or union by size.

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
};

class Solution {

  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int,pair<int,int>>> edges;
        for(int i = 0; i<V; i++) {
            for(auto it: adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt,{node,adjNode}});
            }
        }
        
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        
        int mstwt = 0;
        for(auto it: edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u)!=ds.findUPar(v)) {
                mstwt = mstwt + wt;
                ds.unionByRank(u,v);
            }
        }
        
        return mstwt;
        
    }
};