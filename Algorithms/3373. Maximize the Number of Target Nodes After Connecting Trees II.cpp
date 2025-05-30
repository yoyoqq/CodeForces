class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        vector<int> ans(n+1); 
        // for the first one get res by adding target2 
        map<int, vector<int>> graph1; 
        for (int i=0; i<edges1.size(); i++){
            int x = edges1[i][0], y = edges1[i][1];
            graph1[x].push_back(y);
            graph1[y].push_back(x);
        }
        // for the second tree find the max node target 
        map<int, vector<int>> graph2;
        for (int i=0; i<edges2.size(); i++){
            int x = edges2[i][0], y = edges2[i][1];
            graph2[x].push_back(y);
            graph2[y].push_back(x);
        }

        auto [f, s] = connections(graph2, 0, -1, true);
        auto [ff, ss] = connections(graph1, 0, -1, true);

        // for each node check if its even or odd
        vector<bool> is_even(n+1, false);
        mark_even(graph1, 0, -1, true, is_even);

        
        for (int i=0; i<=n; i++){
            if (is_even[i]) ans[i] = ff + max(f, s);
            else ans[i] = ss + max(f, s);
        }
        
        return ans;
    }

private:
    void mark_even(map<int, vector<int>>& graph, int node, int parent, bool is_evenn, vector<bool>& is_even){
        is_even[node] = is_evenn;
        for (auto& neigh : graph[node]){
            if (neigh == parent) continue;
            mark_even(graph, neigh, node, !is_evenn, is_even);
        }
    }


    pair<int, int> connections(map<int, vector<int>>& graph, int node, int parent, bool is_even){
        // init 
        int even = 0;
        int odd = 0;
        if (is_even) even++;
        else odd++;
        // children
        for (auto& neigh : graph[node]){
            if (neigh == parent) continue;
            auto [e, o] = connections(graph, neigh, node, !is_even);
            even += e;
            odd += o;
        }
        return {even, odd};
    }
};