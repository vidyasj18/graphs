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