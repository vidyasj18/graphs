#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<map>

using namespace std;


// based on DFS and BFS algorithm

// QS-1 : ROTTEN ORANGES - LEETCODE

class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int cnt = 0;
        queue<pair<int,int>> q;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                }

                if(grid[i][j]==1) {
                    fresh++;
                }
            }
        }

        vector<pair<int,int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
        while(!q.empty()) {
            int size = q.size();
            bool rot = false;

            for(int i = 0; i<size; i++) {
                int x1 = q.front().first;
                int y1 = q.front().second;
                q.pop();
                for(auto it: dir) {
                    int row = x1+it.first;
                    int col = y1+it.second;

                    if(row>=0 && col>=0 && row<m && col<n &&grid[row][col]==1) {
                        q.push({row,col});
                        grid[row][col] = 2;
                        fresh--;
                        rot = true;
                    }
                }

            }

            if(rot==true) {
                cnt++;
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


// QS - 2: NUMBER OF ISLANDS -GFG

class Solution {
private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = -1; i<=1; i++) {
            for(int j = -1; j<=1; j++) {
                int nrow = row+i;
                int ncol = col+j;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m) {
                    if(!vis[nrow][ncol] && grid[nrow][ncol]=='L') {
                        dfs(nrow,ncol,vis,grid);
                    }   
                }
            }
        }
    }
    
  public:
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]=='L') {
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        
        return cnt;
        
    }
};