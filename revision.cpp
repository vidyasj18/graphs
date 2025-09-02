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


// number of provinces

class Solution {
private:
    void dfs(int i,vector<int> &visited, vector<vector<int>> &adj) {
        visited[i] = 1;

        for(auto j: adj[i]) {
            if(!visited[j]) {
                dfs(j,visited,adj);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // matrix to vector conversion
        int n = isConnected.size();
        int m = isConnected[0].size();

        vector<vector<int>> adj(n);

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(isConnected[i][j]==1 && i!=j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<int> visited(n,0);
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                cnt++;
                dfs(i,visited,adj);
            }
        }

        return cnt;
    }
};

// rotten oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = -1;
        int fresh = 0;
        queue<pair<int,int>> q;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                }

                else if(grid[i][j]==1) {
                    fresh++;
                }
            }
        }

        if(fresh==0) {
            return 0;
        }

        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()) {
            int s = q.size();
            cnt++;

            for(int k = 0; k<s; k++) {
                auto[i,j] = q.front();
                q.pop();

                for(auto d: dir) {
                    int newi = i + d.first;
                    int newj = j + d.second;

                    if(newi>=0 && newi<n && newj>=0 && newj<m &&
                    grid[newi][newj]==1) {
                        grid[newi][newj] = 2;
                        q.push({newi,newj});
                        fresh--;
                    }
                }
            }
        }

        if(fresh==0) {
            return cnt;
        }

        else {
            return -1;
        }

        
    }
};