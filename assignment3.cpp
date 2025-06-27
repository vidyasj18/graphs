#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Q.S : 1 - shortest path in binary matrix - LEETCODE

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) {
            return -1;
        }

        int n = grid.size();
        // for [[0]] - return 1
        if(n==1) {
            return 1;
        }

        // distance, {src.first,src.second} --> q representation
        queue<pair<int,pair<int,int>>> q;
        // dist matrix m*n is created in that initially all are marked 
        // as infinite
        vector<vector<int>> dist(n, vector<int> (n,INT_MAX));
        dist[0][0] = 1;
        vector<pair<int,int>> dr = {{-1,0},{1,0},{0,-1},{0,1},
        {-1,-1},{-1,1},{1,1},{1,-1}};

        q.push({0,{0,0}});
        while(!q.empty()) {
            int dis = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            for(int i = 0; i<8; i++) {
                int newr = dr[i].first + r;
                int newc = dr[i].second + c;

                if(newr>=0 && newc>=0 && newr<n && newc<n && 
                grid[newr][newc]==0 && dis + 2<dist[newr][newc]) {
                    dist[newr][newc] = dis + 2;
                    if(newr==n-1 && newc==n-1) {
                        return dis+2;
                    }

                    q.push({dis+1,{newr,newc}});
                }
            }

        }

        return -1;

    }
};

// QS - 2 : PATH WITH MINIMUM EFFORT - LEETCODE

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        dist[0][0] = 0;

        priority_queue<pair<int, pair<int,int>>, 
                       vector<pair<int, pair<int,int>>>, 
                       greater<>> q;

        q.push({0,{0,0}});

        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()) {
            int maxi = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();

            if(r==m-1 && c==n-1) {
                return maxi;
            }

            for(int i = 0; i<4; i++) {
                int newr = r + dir[i].first;
                int newc = c + dir[i].second;

                if(newr>=0 && newc>=0 && newr<m && newc<n) {
                    int newmaxi = max(maxi,abs(heights[r][c] - heights[newr][newc]));
                    if(newmaxi<dist[newr][newc]) {
                        dist[newr][newc] = newmaxi;
                        q.push({newmaxi,{newr,newc}});
                    }
                }
            }

        }

        return -1;
    }
};




// QS - 3 : CHEAPEST FLIGHTS WITHIN K STOPS - LEETCODE - VVVVV IMP.........
// MUST DO THIS QUESTION 

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i<flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v,wt});
        }

        // stops - to track k value, will it become more than k or something
        priority_queue<tuple<int,int,int>, 
               vector<tuple<int,int,int>>, 
               greater<tuple<int,int,int>>> pq;
        pq.push({0,src,0});
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0] = 0;

        while(!pq.empty()) {
            auto[dis,node,stops] = pq.top();
            // int dis = pq.top().first;
            // int node = pq.top().second;
            // int stops = pq.top().third;
            pq.pop();

            if(node==dst) {
                return dis;
            }

            if(stops>k) {
                continue;
            }

            for(auto it: adj[node]) {
                int edw = it.second;
                int adjNode = it.first;

                if(edw + dis < dist[adjNode][stops+1]) {
                    dist[adjNode][stops+1] = edw + dis;
                    pq.push({dist[adjNode][stops+1],adjNode,stops+1});
                }
            }

        }

        return -1;

    }
};


// QS - 4 : Network Delay time - LEETCODE


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0; i<times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v,w});
        }

        // *
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0,k});
        // *
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;

        while(!q.empty()) {
            auto[wt,node] = q.top();
            q.pop();

            for(auto it: adj[node]) {
                int edw = it.second;
                int adjNode = it.first;

                if(dist[node] + edw <dist[adjNode]) {
                    dist[adjNode] = dist[node] + edw;
                    q.push({dist[adjNode],adjNode});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i<=n; i++) {
            if(dist[i]==INT_MAX) {
                return -1;
            }

            ans = max(ans,dist[i]);
        }

        return ans;
    }
};

