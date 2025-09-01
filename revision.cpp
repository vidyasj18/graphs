#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>

using namespace std;

// BFS
class solution {
    vector<int> bfs(int v,vector<int> adj[]) {
        int vis[v] = {0};
        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();

            if(vis[frontNode]==0) {
                vis[frontNode] = 1;
                q.push(frontNode);

                for(auto i: adj[frontNode]) {
                    if(vis[i]==0) {
                        vis[i] = 1;
                        q.push(i);
                    }
                }
            }
        }
    }
};

// DFS

class solution {

    void dfs(int node,unordered_map<int,bool> &visited, vector<int> &component, vector<vector<int>> &adjList) {
        visited[node] = true;
        component.push_back(node);

        for(auto i: adjList[node]) {
            if(!visited[i]) {
                dfs(i,visited,component,adjList);
            }
        }
    }

    vector<vector<int>> dfs(int v,int E, vector<vector<int>> &edges) {
        vector<vector<int>> adjList;
        unordered_map<int,bool> visited;
        vector<vector<int>> ans;
        for(int i = 0; i<E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for(int i = 0; i<v; i++) {
            if(!visited[i]) {
                vector<int> component;
                dfs(i,visited,component,adjList);
                ans.push_back(component);
            }
        }

        return ans;
    }
};