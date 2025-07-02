#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// disjoint set/ minimu spanning tree questions.

// QS - 1 : NUMBER OF OPERATIONS TO MAKE NETWORK CONNECTED.

class DisJointSet {
    public:
    vector<int> parent,size;

    DisJointSet(int n) {
        parent.resize(n+1,0);
        size.resize(n+1);

        for(int i = 0; i<n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if(node==parent[node]) {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u,int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) {
            return;
        }

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_u] += size[ulp_v];
        }

        else {
            parent[ulp_v] = ulp_u;
            size[ulp_v] += size[ulp_u];
        }
    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
       // if extra edges are more than or equal to scc - 1
        // then return true

        DisJointSet ds(n);
        int cntExtras = 0;
        int cnt = 0;

        for(auto it: connections) {
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u)==ds.findUPar(v)) {
                cntExtras++;
            }

            else {
                ds.unionBySize(u,v);
            }
        }

        for(int i = 0; i<n; i++) {
            if(ds.parent[i]==i) {
                cnt++;
            }
        }

        int ans = cnt - 1;

        if(cntExtras>=ans) {
            return ans;
        }

        return -1;
    }
};