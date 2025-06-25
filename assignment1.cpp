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


//  QS - 3:  FLOOD FILL - LEETCODE

class Solution {
private:
    void dfs(int i,int j,vector<vector<int>>& image,int color,
    int colorog) {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        image[i][j] = color;

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            vector<pair<int,int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};

            for(auto it:dir) {
                int x1 = it.first + x;
                int y1 = it.second + y;

                if(x1>=0 && y1>=0 && x1<m && y1<n) {
                    if(image[x1][y1]==colorog) {
                        image[x1][y1] = color;
                        q.push({x1,y1});
                    }
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int colorog = image[sr][sc];

        if(colorog==color) {
            return image;
        }
        
        dfs(sr,sc,image,color,colorog);

        return image;
    }
};

// QS - 4 : surrounding regions - leetcode

class Solution {
private:
    void bfs(int i, int j, vector<vector<char>> &board) {
        int m = board.size();
        int n = board[0].size();
        board[i][j] = 'T';
        queue<pair<int,int>> q;
        q.push({i,j});

        vector<pair<int,int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto it: dir) {
                int x1 = x + it.first;
                int y1 = y + it.second;

                if(x1>=0 && y1>=0 && x1<m && y1<n) {
                    if(board[x1][y1]=='O') {
                        board[x1][y1] = 'T';
                        q.push({x1,y1});
                    }
                }

            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i<m; i++) {
            if(board[i][0] == 'O') {
                bfs(i,0,board);
            }

            if(board[i][n-1] == 'O') {
                bfs(i,n-1,board);
            }
        }

        for(int j = 0; j<n; j++) {
            if(board[0][j] == 'O') {
                bfs(0,j,board);
            }

            if(board[m-1][j] == 'O') {
                bfs(m-1,j,board);
            }
        }

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {

                if(board[i][j]=='O') {
                    board[i][j] = 'X';               
                }

                if(board[i][j]=='T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};


// QS - 5: number of enclaves - leetcode

class Solution {
private:
    void bfs(int i,int j,vector<vector<int>>& grid,
    vector<vector<int>> &vis) {
        vis[i][j] = 1;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});

        vector<pair<int,int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto it: dir) {
                int x1 = it.first + x;
                int y1 = it.second + y;

                if(x1>=0 && y1>=0 && x1<m && y1<n) {
                    if(grid[x1][y1]==1 && !vis[x1][y1]) {
                        vis[x1][y1] = 1;
                        q.push({x1,y1});
                    }
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i = 0; i<m; i++) {
            if(grid[i][0]==1) {
                bfs(i,0,grid,vis);
            }

            if(grid[i][n-1]==1) {
                bfs(i,n-1,grid,vis);
            }
        }

        for(int j = 0; j<n; j++) {
            if(grid[0][j]==1) {
                bfs(0,j,grid,vis);
            }

            if(grid[m-1][j]==1) {
                bfs(m-1,j,grid,vis);
            }
        }

        int cnt = 0;

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j]==1 && !vis[i][j]) {
                    cnt++;
                }
            }
        }

        return cnt;

    }
};