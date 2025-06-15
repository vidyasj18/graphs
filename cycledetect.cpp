#include<iostream>
#include<queue>
#include<list>
#include<unordered_map>

using namespace std;

// FOR UNDIRECTED GRAPHS........................
// using BFS traversal

bool detectCycle(int src,int v,vector<int> adj[],int vis[]) {
    vis[src] = 1;
    queue<pair<int,int>> q;
    q.push(make_pair(src,-1));

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjNode: adj[node]) {
            if(!vis[adjNode]) {
                vis[adjNode] = 1;
                q.push(make_pair(adjNode,node));
            }

            else if(parent!=adjNode) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    
    bool isCycle(int v,vector<int> adj[]) {
        int vis[v] = {0};
        for(int i = 0; i<v; i++) {
            if(!vis[i]) {
                if(detectCycle(i,v,adj,vis)) {
                    return true;
                }
            }
        }

        return false;
    }

}


// using DFS traversal

class Solution {
private:
    bool detectCycle(int node,int parent,int V,vector<vector<int>> &adj, int vis[]) {
        vis[node] = 1;
        for(auto i: adj[node]) {
            if(vis[i]==0) {
                if(detectCycle(i,node,V,adj,vis)==true) {
                    return true;
                }
            }
            
            else if(i!=parent){
                return true;
            }
        }
        
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(int i = 0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int vis[V] = {0};
        int parent = -1;
        
        for(int i = 0; i<V; i++) {
            if(!vis[i]) {
                if(detectCycle(i,parent,V,adj,vis)==true) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
};



// FOR DIRECTED GRAPHS

class Solution {
private:
    bool dfsCheck(vector<vector<int>> &adj, int node,int vis[],int pathvis[]) {
        vis[node] = 1;
        pathvis[node] = 1;
        
        
        // traverse for adjacent nodes
        for(auto i: adj[node]) {
            
            // if not visited for i
            if(!vis[i]) {
                // if any 1 cycle is present, return true
                if(dfsCheck(adj,i,vis,pathvis)==true) {
                    return true;
                }
            }
            
            
            // if visited for i and pathvisited for i as well 
            // it shows that i is revisited now.
            else if(pathvis[i]==true) {
                return true;
            }
        }
        
        // recursively mark the pathvisited of nodes is not visited/mark 0
        pathvis[node] = 0;
        // returning false cz no cycle is found
        return false;
    }

  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        
        for(int i = 0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        int vis[V] = {0};
        // in the same path or not
        int pathvis[V] = {0};
        
        for(int i = 0; i<V; i++) {
            if(!vis[i]) {
                if(dfsCheck(adj,i,vis,pathvis)==true) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
};