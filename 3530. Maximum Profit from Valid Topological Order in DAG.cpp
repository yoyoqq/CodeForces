class Solution {
    public:
        int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
            // greedy doesnt work -> 10 -> 1 -> 2      and  9 
            // find all the combinations ? brute force ? O(22!)
            // dp ? 
            // bitmask -> 1010   node 0 is not, 1 is , 2 istn, 3 is 
            // dp[bitmask] = max profit once placed all the bitmask in topo order  
            // [0, 1] 10 is invalid, never considered
    
            // bitmask
            vector<int> need(n, 0);
            for (auto& e : edges){
                int i =e[0], j = e[1];
                need[j] |= (1 << i);  // bitmask 1000110.. 
            }
    
            vector<int> dp(1<<n, -1);   // amount of nums in dp
            dp[0] = 0;
            for (int mask=0; mask<(1<<n); mask++){  // how many numbers we have processed so far 
                if (dp[mask] == -1) continue;
                int pos = __builtin_popcount(mask) + 1;   // count number of active bits
                for (int i=0; i<n; i++){    // for every node 
                    // if we can still use && mask possible 
                    if (((mask >> i) & 1) == 0 && (mask & need[i]) == need[i]){
                        int mask2= mask | (1 << i);
                        dp[mask2] = max(dp[mask2], dp[mask] + score[i] * pos);  // get the max dp 
                    }
                }
            }
            return dp[(1 << n) - 1];
        }
    };
    
    
    
    // // class Solution {
    // // public:
    // //     int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
    // //         // process DAG -> indegree 
    // //         map<int, int> indegree;
    // //         for (int i=0; i<edges.size(); i++){
    // //             int u = edges[i][0], v = edges[i][1];
    // //             indegree[u]++;
    // //         }
    // //         // get the indegree in array 
    // //         map<int, vector<int>> group;
    // //         for (auto& [node, count] : indegree){
    // //             group[count].push_back(node);
    // //         }
    // //         // if no indegree append as last 
    // //         for (int i=0; i<n; i++){
    // //             if (indegree.find(i) == indegree.end()){
    // //                 group[0].push_back(i);
    // //             }
    // //         }
    // //         // decreasing indegree -> group  
    // //         int profit = 0;
    // //         int multiplier = 1;
    // //         for (auto it=group.rbegin(); it!=group.rend(); it++){
    // //             vector<int>& nodes = it->second;
    // //             // for (auto nod : nodes) cout << nod << " "; cout << endl;
    // //             vector<int> scores;
    // //             // get scores in increasing
    // //             for (int i=0; i<nodes.size(); i++){
    // //                 scores.push_back(score[nodes[i]]);
    // //             }
    // //             sort(scores.begin(), scores.end());
    // //             for (int i=0; i<scores.size(); i++){
    // //                 cout << multiplier << " " << scores[i] << endl;
    // //                 profit += (multiplier * scores[i]);
    // //                 multiplier++;
    // //             }
    // //         }
    // //         return profit;
    // //     }
    // // };
    // //         // for (auto& [count, order] : group){
    // //         //     sort(order.begin(), order.end());
    // //         //     for (int i=0; i<order.size(); i++){
    // //         //         cout << order[i] << " " << multiplier << " " << score[order[i]] << endl;
    // //         //         profit += (multiplier * score[order[i]]); 
    // //         //         multiplier++;
    // //         //     }
    // //         // }      