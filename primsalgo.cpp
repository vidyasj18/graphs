#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// prim's algo used to find minimum spanning tree from the given graph.

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // min-heap is created
        priority_queue<pair<int,int>,
        vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> vis(V,0);
        // wt,node
        pq.push({0,0});
        int sum = 0;
        
        while(!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            
            if(vis[node]==1) continue;
            
            // if not visited, marking it visited and adding the wt to the sum
            vis[node] = 1;
            sum = sum + wt;
            
            // adj is node,wt inside the function vector
            for(auto it: adj[node]) {
                int adjNode = it[0];
                int edWt = it[1];
                
                if(!vis[adjNode]) {
                    pq.push({edWt,adjNode});
                }
            }
        }
        
        return sum;
        
    }
};