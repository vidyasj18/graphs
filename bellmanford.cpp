#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// shortest path calculation for the graph having negative weight
// works even if the negative cycle exists
// T.C : O(V*E)

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        vector<int> dist(V,1e8);
        dist[src] = 0;
        
        // iterating calculation for v-1 times.
        for(int i = 0; i<V-1; i++) {
            for(auto it: edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u]!=1e8 && dist[u]+ wt <dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            // if still this condition persists then return vector -1
            if(dist[u]!=1e8 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }
        
        return dist;
    }
};
