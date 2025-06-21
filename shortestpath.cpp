#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// shortest path calculation in directed a cyclic graph using dfs algo.
// step 1 : do a toposort on the graph.
// step 2 : take the nodes out of the stack and relax the stack.

class Solution {
private:
    void topoSort(int i,stack<int> &st,vector<pair<int,int>> adj[],int vis[]) {
        vis[i] = 1;
        for(auto it: adj[i]) {
            int v = it.first;
            if(!vis[v]) {
                topoSort(v,st,adj,vis);
            }
        }
        
        st.push(i);
    }

  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        // if number of nodes are absent, return empty vector function.
        if(V==0) {
            return {};
        }
        
        // creating adj list --- {u,v,wt} = adj element
        vector<pair<int,int>> adj[V];
        for(int i = 0; i<E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        int vis[V] = {0};
        stack<int> st;
        
        // T.C : O(V+E) = number of edges and nodes. - DFS t.c
        for(int i = 0; i<V; i++) {
            if(!vis[i]) {
                topoSort(i,st,adj,vis);
            }
        }
        
        // all the distances are initially marked as infinite.
        // source node is marked as zero. as the distance between source and itself is zerro.
        // here, source is zero.

        vector<int> dist(V,INT_MAX);
        dist[0] = 0;
        
        // T.C : O(V+E) - number of nodes for the stack and number of edges  for the for(auto ) function as it visits
        // all the list of adj of nodes.
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            // if node is unreachable use continue function so that it sees the other st elements first.
            if(dist[node]==INT_MAX) {
                continue;
            }
            
            for(auto it: adj[node]) {
                int v = it.first;
                int wt = it.second;
                
                // if we get shortest path smaller than the original one, we update the distance of the node.
                if(dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
            
        }

        // when the distance is INT_MAX update it to -1.
        for(int i = 0; i<V; i++) {
            if(dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        
        return dist;
        
        
    }
};


// shortest path in undirected graph having unit weights.

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    // adj list is given directly. 
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        int dist[n];
        
        // we mark infinite value to all the distances in the beginning.
        for(int i = 0; i<n; i++) {
            dist[i] =  INT_MAX;
        }
        
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    // we push it to change the distance for the respective it's nodes in adj list 
                    // as dist[t] has been changed.
                    q.push(it);
                }
            }
        }
        
        // all are marked -1 in the beginning.
        vector<int> ans(n,-1);
        for(int i = 0; i<n; i++) {
            // if the dist is not INT_MAX then mark dist or else -1.
            if(dist[i]!=INT_MAX) {
                ans[i] = dist[i];
            }
        }
        
        return ans;
        
    }
};
