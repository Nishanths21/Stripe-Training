#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<int,int> PII;
    typedef pair<int,PII> NODE;
    int findCheapestPrice(int n, vector<vector<int>>& A, int src, int dst, int k) {
        unordered_map<int, vector<PII>> next;
        for (auto e : A) {
            next[e[0]].push_back({e[1], e[2]});
        }
        // priority_queue<PII, vector<PII>, greater<>> pq;
        priority_queue<NODE, vector<NODE>, greater<>> pq;
        pq.push({0,{src, -1}});

        set<PII> vis;
        while (!pq.empty()) {
            auto [w, e] = pq.top();
            int u = e.first;
            int cnt = e.second;
            pq.pop();
            if (vis.count({u,cnt})) continue;
            vis.insert({u,cnt});
            if (u == dst) return w;
            for (auto [v, cost] : next[u]) {
                if (cnt+1 > k) continue;
                pq.push({w+cost, {v, cnt+1}});
            }
        }
        return -1;
    }
};