class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        for (int i=0; i<n; i++){
            for (int node : graph[i]){
                indegree[i]++;
                adj[node].push_back(i); // reversed 
            }
        }
        queue<int> q;
        for (int i=0; i<n; i++){
            // no edges 
            if (indegree[i] == 0){
                q.push(i);
            }
        }
        // find 
        vector<bool> safe(n, 0);
        while (q.size()){
            int node = q.front(); q.pop();
            safe[node] = true;
            for (int next : adj[node]){
                indegree[next]--; 
                if (indegree[next] == 0){  // all the edges have been exhausted 
                    q.push(next);
                }
            }
        }
        vector<int> ans;
        for (int i=0; i<n; i++)
            if (safe[i] == true) ans.push_back(i);
        return ans;
    }
};



// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         map<int, bool> safe;

//         vector<int> res;
//         for (int i=0; i<n; i++){
//             if (dfs(graph, safe, i)){
//                 res.push_back(i);
//             }
//         }
//         return res;
//     }

//     bool dfs(vector<vector<int>>& graph, map<int, bool>& safe, int node){
//         if (safe.find(node) != safe.end()) return safe[node];
//         safe[node] = false;
//         for (int next_node : graph[node]){
//             if (!dfs(graph, safe, next_node)) return false;
//         }
//         safe[node] = true;
//         return true;
//     }
// };