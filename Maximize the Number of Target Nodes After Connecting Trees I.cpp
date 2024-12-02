class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        auto g1 = buildGraph(edges1), g2 = buildGraph(edges2);
        int count = 0, n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> ans;
        // get the max diff count starting at any point of the graph
        // k - 1 as we need to connect it to the next tree
        for (int i=0; i<m; i++){    
            count = max(count, dfs(g2, i, -1, k-1));
        }
        // for graph1, get the max count going all directions + maxCount from the g2 
        for (int i=0; i<n; i++){
            ans.push_back(count + dfs(g1, i, -1, k));
        }
        return ans;
    }

private:
    int dfs(vector<vector<int>>& g, int root, int par, int k, int count = 1){
        if (k < 0) return 0;
        for (auto node : g[root]){
            count += (node != par) ? dfs(g, node, root, k-1) : 0;
        }
        return count;
    }
    

    vector<vector<int>> buildGraph(vector<vector<int>>& edges){
        vector<vector<int>> g(edges.size() + 1);
        for (auto e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return g;
    }
};