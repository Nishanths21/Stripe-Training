#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indeg(n , 0);
        vector<vector<int>> graph(n);
        for(int i = 0, m = relations.size(); i < m; ++i){
            graph[relations[i][0] - 1].push_back(relations[i][1] - 1);
            ++indeg[relations[i][1] - 1];
        }
       
        vector<int> dist = time;
        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(indeg[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            int curr = dist[u];
            for(int v : graph[u]){
                dist[v] = max(dist[v] , curr + time[v]);
                if(--indeg[v] == 0) q.push(v);
            }
        }
        return *max_element(dist.begin() , dist.end());
    }
};