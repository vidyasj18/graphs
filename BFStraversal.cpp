#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

// to store in sorted order use set instead of list and for 
// in preparedAdjList function instead of push_back use insert.
using namespace std;


// when adjList is given 
class solution {
    public:
    vector<int> bfsofGraph(int v,vector<int> adj[]) {
        int vis[v] = {0};
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        vector<int> ans;

        while(!q.empty()) {
            int frontNode = q.front();
            ans.push_back(frontNode);

            for(auto i:adj[frontNode]) {
                if(vis[i]==0) {
                    q.push(i);
                    vis[i]=1;
                }
            }
        }

    }
};

