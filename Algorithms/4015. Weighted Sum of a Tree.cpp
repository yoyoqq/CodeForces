class Solution {
public:
    int get_height(unordered_map<int, vector<int>>& graph, int cur, int prev) {
        int ans = 0;
        for (int i=0; i<graph[cur].size(); i++) {
            int node = graph[cur][i];
            // if seen 
            if (node == prev) continue;
            // go 
            ans = max(ans, 1 + get_height(graph, node, cur));
        }
        return ans; 
    }

    long long get_depth(unordered_map<int, vector<int>>& graph, vector<int>& nums, int& height, int cur, int prev, int depth) {
        long long ans = nums[cur] * 1LL * (height - depth + 1);
        for (int i=0; i<graph[cur].size(); i++) {
            int node = graph[cur][i];
            // if seen 
            if (node == prev) continue;
            // go 
            ans += get_depth(graph, nums, height, node, cur, depth + 1);
        }
        return ans; 
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        unordered_map<int, vector<int>> graph;
        for (int i=0; i<parent.size(); i++) {
            // if (parent[i] == -1) continue;
            graph[i].push_back(parent[i]);
            graph[parent[i]].push_back(i);
        }
        int height = 1 + get_height(graph, 0, -1);
        // get whole sum 
        long long depth = get_depth(graph, nums, height, 0, -1, 1);
        return depth;
    }
};