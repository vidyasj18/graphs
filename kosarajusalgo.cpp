#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// To find the number of strongly connected components in a given graph.
// This happens only in the directed graph.

class Solution {
private:
    void dfs(int node,vector<vector<int>> &adj,stack<int> &st,vector<int> &vis) {
        vis[node] = 1;
        for(auto i: adj[node]) {
            if(!vis[i]) {
                dfs(i,adj,st,vis);
            }
        }
       
        // when all adjacent nodes for the given node are all visited already.
        // they are pushed into this st stack.
        st.push(node);
    }
    
    void dfs3(int node,vector<vector<int>> &adjT,vector<int> &vis) {
        vis[node] = 1;
        for(auto it: adjT[node]) {
            if(!vis[it]) {
                dfs3(it,adjT,vis);
            }
        }
    }

    
  public:
    int kosaraju(vector<vector<int>> &adj) {

        // step 1 : collect all the nodes in stack and mark them visited.
        
        vector<int> vis(adj.size(),0);
        stack<int> st;
        
        for(int i = 0; i<adj.size(); i++) {
            if(!vis[i]) {
                dfs(i,adj,st,vis);
            }
        }
        
        
        // step - 2 : create transpose of the graph
        
        vector<vector<int>> adjT(adj.size());
        for(int i = 0; i<adj.size(); i++) {
            vis[i] = 0;
            for(auto it: adj[i]) {
                // initially it was i->it
                // later it should get turned out to it->i
                adjT[it].push_back(i);
            }
        }
        
        // strongly connected components
        int scc = 0;
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            if(!vis[node]) {
                // increment when visited is not true
                // and then dfs will mark their components as true when 
                // there is a small cycle formed in the graph. considering a scc.

                scc++;
                dfs3(node,adjT,vis);
            }
        }
        
        return scc;
        
    }
};