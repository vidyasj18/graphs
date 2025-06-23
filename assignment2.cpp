#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// DID AFTER TOPOLOGICAL SORTING AND CYCLEDETECTION ALGORITHMS

// QS - 1: Course Schedule - 1 - LEETCODE

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto it: prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
        }
        
        // use topological sorting algo to sort the courses.
        vector<int> indegree(numCourses,0);
        queue<int> q;

        for(int i = 0; i<numCourses; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }

        for(int i = 0; i<numCourses; i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }

        // store all the courses when their indegree becomes 0 int topo vector.
        vector<int> topo;

        while(!q.empty()) {
            int front = q.front();
            topo.push_back(front);
            q.pop();
        
            for(auto it: adj[front]) {
                indegree[it]--;
                if(indegree[it]==0) {
                    q.push(it);
                }
            }
        }


        // if the topo vector size and the number of courses are equal.
        // it shows that there is no cycle and all the courses are present inside the topo vector.
        if(topo.size()==numCourses) {
            return true;
        }

        return false;

    }
};


// QS - 2 : Course Schedule - 2 - LEETCODE

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
        }

        vector<int> indegree(numCourses,0);
        for(int i = 0; i<numCourses; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i<numCourses; i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()) {
            int front = q.front();
            topo.insert(topo.begin(),front);
            q.pop();

            for(auto it: adj[front]) {
                indegree[it]--;
                if(indegree[it]==0) {
                    q.push(it);
                }
            }
        }

        // return topo if size is same else return empty array

        if(topo.size()==numCourses) {
            return topo;
        }

        else {
            return {};
        }
    }
};


// QS - 3 : FIND EVENTUAL SAFE PLACES - LEETCODE
// done using BFS
// all paths should end up at terminal nodes or safenodes
// safenodes endup at terminal nodes
// terminal nodes does not have outgoing edges.

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // reverse the edges, as in convert incoming edges to 
        // outgoing and outgoing to incoming.
        vector<vector<int>> adj(graph.size());
        vector<int> indegree(graph.size(),0);
        for(int i = 0; i<graph.size(); i++) {

            // initially i->it
            // now convert that to it->i
            for(auto it: graph[i]) {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i<graph.size(); i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            int front = q.front();
            ans.push_back(front);
            q.pop();

            for(auto it:adj[front]) {
                indegree[it]--;
                if(indegree[it]==0) {
                    q.push(it);
                }
            }
        }

        // sorted cz they needed it in sorted manner.
        sort(ans.begin(),ans.end());
        return ans;

    }
};