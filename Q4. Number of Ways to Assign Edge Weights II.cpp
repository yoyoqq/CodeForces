#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int result(int levels) {
        // powers of 2 bin 
        if (levels - 1 <= 0) return 1;
        return (1LL << (levels - 1)) % MOD;
    }

    int find_distance(int u, int v, unordered_map<int, vector<int>>& graph) {
        queue<pair<int, int>> q; // node, parent
        q.push({u, -1});
        int levels = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [node, parent] = q.front();
                q.pop();
                if (node == v) return levels;
                for (int neigh : graph[node]) {
                    if (neigh != parent) {
                        q.push({neigh, node});
                    }
                }
            }
            levels++;
        }
        return -1;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // make graph 
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int x = edge[0], y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        // output 
        vector<int> ans;
        map<pair<int, int>, int> cache;
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            if (cache.find({min(u, v), max(v, u)}) != cache.end()){
                ans.push_back(cache[{min(u, v), max(v, u)}]);
                continue;
            }
            int dist = find_distance(u, v, graph);
            cache[{min(u, v), max(v, u)}] = result(dist); 
            ans.push_back(result(dist));
        }
        return ans;
    }
};