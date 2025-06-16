#include<iostream>
#include <bits/stdc++.h> 
#include<stack>
#include<unordered_map>

// only occurs in undirected acyclic graph done using dfs
// linearly represented/ output format is linear
// T.C : O(v+e)  S.C : O(N)

using namespace std;

void dfs(int node,vector<vector<int>> &adj,unordered_map<int,bool> &vis,stack<int> &st) {
    vis[node] = true;
    for(auto i: adj[node]) {
        // if i not visited we recursively trverse through dfs function and mark it visited in the beginning.
        if(!vis[i]) {
            dfs(i,adj,vis,st);
        }
    }

    // if all i's in adj[node] are visited already then simply push that node inside the stack

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v);
    for(int i = 0; i<e; i++) {
        int u = edges[i][0];
        int V = edges[i][1];

        adj[u].push_back(V);
    }

    unordered_map<int,bool> vis;
    stack<int> st;
    for(int i = 0; i<v; i++) {
        if(!vis[i]) {
            dfs(i,adj,vis,st);
        }
    }

    // stack contains all the nodes in which their all i's in adjlist are already visited
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}