class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            long long MOD = 1e9+7;
            // make graph
            map<long long, vector<pair<long long, long long>>> graph;
            for (long long i=0; i<roads.size(); i++){
                long long x = roads[i][0], y = roads[i][1], val = roads[i][2];
                graph[x].push_back({y, val});
                graph[y].push_back({x, val});
            }
            // djikstra algorirthm, min amount of time to reach n-1
            priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
            vector<long long> dist(n, LLONG_MAX);
            vector<long long> ways(n, 0);
            dist[0] = 0;
            ways[0] = 1;
            pq.push({0, 0});    // val, node
            long long mn = 1e9;
            long long count = 0;
            while(pq.size()){
                auto [val, node] = pq.top(); pq.pop();
                if (val > dist[node]) continue;
                // found dir 
                for (auto [next_node, next_val] : graph[node]){
                    long long newDist = val + next_val;
                    if (newDist < dist[next_node]){
                        dist[next_node] = newDist;
                        ways[next_node] = ways[node];
                        pq.push({newDist, next_node});
                    } else if (newDist == dist[next_node]){
                        ways[next_node] = (ways[next_node] + ways[node]) % MOD;
                    }
                }
            }
            return (int)ways[n-1];
        }
    };
    
    
    // class Solution {
    // public:
    
    //     void dfs(long long& count, long long& mn, long long& n, vector<bool>& seen,  map<long long, vector<pair<long long, long long>>>& graph, long long node, long long val){
    //         // base case
    //         if (node == n-1){
    //             if (mn > val){
    //                 mn = val;
    //                 count = 1;
    //             }else if (mn == val){
    //                 count++;
    //             }
    //             return;
    //         }
    //         // children
    //         for (auto [next_node, next_val] : graph[node]){
    //             if (seen[next_node]) continue;
    //             seen[next_node] = true;
    //             dfs(count, mn, n, seen, graph, next_node, val + next_val);
    //             seen[next_node] = false;
    //         }
    //         return;
    //     }
    
    //     long long countPaths(long long n, vector<vector<long long>>& roads) {
    //         // make grpah
    //         map<long long, vector<pair<long long, long long>>> graph;
    //         for (long long i=0; i<roads.size(); i++){
    //             long long x = roads[i][0], y = roads[i][1], val = roads[i][2];
    //             graph[x].push_back({y, val});
    //             graph[y].push_back({x, val});
    //         }
    //         // dfs
    //         long long count = 0;
    //         long long mn = 1e9;
    //         vector<bool> seen(n, 0);
    //         dfs(count, mn, n, seen, graph, 0, 0);
    //         return count;
    //     }
    
    // };
    //         // vector<bool> seen(n, 0);
    //         // seen[0] = true;
    //         // long long mn = 1e9;
    //         // long long count = 0;
    //         // stack<pair<long long, long long>> stack;    // bfs
    //         // stack.push({0, 0}); // node, val
    //         // while (stack.size()){
    //         //     auto [node, val] = stack.top(); stack.pop();
    //         //     cout << node << " " << val << endl;
    //         //     // base case, found the last pos 
    //         //     if (node == n-1){
    //         //         // found smaller value 
    //         //         if (mn > val){
    //         //             mn = val;
    //         //             count = 1;
    //         //         }
    //         //         else if (val == mn){
    //         //             count++;
    //         //         }
    //         //         continue;
    //         //     }
    //         //     // children
    //         //     for (auto [next_node, next_val] : graph[node]){
    //         //         if (seen[next_node]) continue;
    //         //         seen[next_node] = true;
    //         //         stack.push({next_node, val+next_val});
    //         //         seen[next_node] = false;
    //         //     }
    //         // }
    //         // return count;