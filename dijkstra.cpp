#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// used to find shortest path from source node to current node for all nodes in  the given graph.
// uses BFS approach
// weight should always be positive.
// T.C : O(E.logV) - worst case scenario.

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // {u,v,w}
        vector<vector<pair<int,int>>> adj(V);
        for(int i = 0; i < (int)edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Min-heap - priority queue arranges the values on the basis of increasing values and lesser data more the value.
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // Distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Push starting node
        pq.push({0, src});

        while (!pq.empty()) {
            int curDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // if we are able to find a shorter path than the value which already exists
            if (curDist > dist[node]) continue;

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                // relax the node - update the distance.
                if (curDist + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = curDist + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
    }
};