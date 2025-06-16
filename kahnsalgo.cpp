#include<iostream>
#include <bits/stdc++.h> 
#include<stack>
#include<unordered_map>

using namespace std;

// topological sorting using BFS algorithm

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>>adj(v);
    for(int i = 0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // indegree is count which tells how many incoming nodes are present for that particular node
    unordered_map<int,int> indegree;

    for(int i = 0; i<v; i++) {
        for(auto it:adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i<v; i++) {
        // if indegree is zero that means it is kinda starting node
        if(indegree[i]==0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // for the node in q, we increment the indegrees of the elements present in that adjlist node.

        for(auto i:adj[node]) {
            indegree[i]--;
            if(indegree[i]==0) {
                q.push(i);
            }
        }
    }

    return ans;
}