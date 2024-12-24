class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // calculate diameter for d1 and d2 
        // use 2 dfs for it 

        // create map for both graphs
        map<int, vector<int>> graph1 = create_map(edges1);
        map<int, vector<int>> graph2 = create_map(edges2);

        // get longest diameter
        int d1 = findDiameter(graph1, 0, -1).first;
        int d2 = findDiameter(graph2, 0, -1).first;
        int combined = ceil(d1 / 2.0) + ceil(d2 / 2.0) + 1;
        return max({d1, d2, combined});
    }

private:

    pair<int, int> findDiameter(map<int, vector<int>>& graph, int node, int parent){
        int depth1 = 0, depth2 = 0;
        int diameter = 0;
        for (int neigh : graph[node]){
            if (neigh == parent) continue;
            auto [child, depth] = findDiameter(graph, neigh, node);
            diameter = max(diameter, child);
            depth++;
            if (depth > depth1){
                depth2 = depth1;
                depth1 = depth;
            }else if (depth > depth2){
                depth2 = depth;
            }
        }
        diameter = max(diameter, depth1 + depth2);
        return {diameter, depth1};
    }

    pair<int,int> longest_diameter(map<int, vector<int>>& graph){
        vector<pair<int, int>> stack;
        set<int> seen;
        int a = graph.begin()->first;
        int b = -1;
        int c = -1;
        int level = 0;
        // a -> b
        stack.push_back({a, 1});
        while(stack.size()){
            auto [node, cur_level] = stack.back(); stack.pop_back();
            // base case
            if (cur_level > level){
               level = cur_level;
               b = node;
            }
            // children
            for (int& next_node : graph[node]){
                if (seen.find(next_node) == seen.end()){
                    seen.insert(next_node);
                    stack.push_back({next_node, cur_level+1});
                }
            }
        }
        // b -> c 
        seen.clear();
        stack.clear();
        stack.push_back({b, 1});
        while(stack.size()){
            auto [node, cur_level] = stack.back(); stack.pop_back();
            // base case
            if (cur_level > level){
               level = cur_level;
               c = node;
            }
            // children
            for (int& next_node : graph[node]){
                if (seen.find(next_node) == seen.end()){
                    seen.insert(next_node);
                    stack.push_back({next_node, cur_level+1});
                }
            }
        }
        // calculate distasnce from b to c 
        seen.clear();
        stack.clear();
        return {b, c};
    }

    map<int, vector<int>> create_map(vector<vector<int>>& arr){
        map<int, vector<int>> graph;
        for (auto a : arr){
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        return graph;
    }
};