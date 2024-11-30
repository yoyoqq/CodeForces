class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // eulerian algorithm, visit every node just once 
        unordered_map<int, deque<int>> adjacencyMatrix;
        unordered_map<int, int> inDegree, outDegree;
        for (auto& pair: pairs){
            int start = pair[0], end = pair[1];
            adjacencyMatrix[start].push_back(end);
            outDegree[start]++;
            inDegree[end]++;
        }

        // find start node, has to be outdegree == indegree+1
        vector<int> result;
        int startNode = -1;
        for (auto& entry: outDegree){
            int node = entry.first;
            if (outDegree[node] == inDegree[node] + 1){
                startNode = node;
                break;
            }
        }

        if (startNode == -1){
            startNode = pairs[0][0];
        }
        stack<int> nodeStack;
        nodeStack.push(startNode);

        while (!nodeStack.empty()){
            int node = nodeStack.top();
            if (!adjacencyMatrix[node].empty()){
                int nextNode = adjacencyMatrix[node].front();
                adjacencyMatrix[node].pop_front();
                nodeStack.push(nextNode);
            }else{
                result.push_back(node);
                nodeStack.pop();
            }
        }

        reverse(result.begin(), result.end());
        vector<vector<int>> pairedResult;
        for (int i = 1; i < result.size(); ++i) {
            pairedResult.push_back({result[i - 1], result[i]});
        }
        return pairedResult;
        
    }
};



// class Solution {
// public:
//     vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
//         unordered_map<int, vector<vector<int>>> m;
//         for (int i=0; i<pairs.size(); i++){
//             int start = pairs[i][0], end = pairs[i][1];
//             m[start].push_back({start, end});
//             m[end].push_back({start, end});
//         }
//         // for (auto& [k, v] : m){
//         //     cout << k << endl;
//         //     for (vector<int> x : v){
//         //         cout << x[0] << " " << x[1] << endl;
//         //     }
//         //     cout << endl;
//         // }
//         // bfs around, when found a m[key].size != 1 then we have the arrangement 
//         vector<vector<int>> res;
//         for (int i=0; i<pairs.size(); i++){
//             int start = pairs[i][0], end = pairs[i][1];
//             if (m[start].size() == 1 && m[end].size() == 1) continue;
//             // found valid arrangement
//             int key = 0;
//             if (m[start].size() != 1) key = start;
//             else key = end;
//             // create a dfs 
//             set<pair<int, int>> seen;
//             set<int> seen_key;
//             stack<int> stack;
//             stack.push(key);
//             while (stack.size()){
//                 // process key 
//                 auto k = stack.top(); stack.pop();
//                 if (seen_key.find(k) != seen_key.end()) continue;
//                 seen_key.insert(k);
//                 // bfs 
//                 for (auto x : m[k]){
//                     int f = x[0], s = x[1];
//                     // BUG GETTIGN INSERTED {4, 5}, {4, 5}
//                     if (seen.find({f, s}) == seen.end()) {
//                         cout << f << " " << s << endl;
//                         res.push_back({f, s});
//                         seen.insert({f, s});
//                     }
//                     if (seen_key.find(f) == seen_key.end()){
//                         seen_key.insert(f);
//                         stack.push(f);
//                     }
//                     if (seen_key.find(s) == seen_key.end()){
//                         seen_key.insert(s);
//                         stack.push(s);
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };