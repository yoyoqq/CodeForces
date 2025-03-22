class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            // make graph
            map<int, vector<int>> graph;
            for (int i=0; i<edges.size(); i++){
                int x = edges[i][0], y = edges[i][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
            // subgraph of graph check iterations 
            // iterate ndoes 
            int complete = 0;
            vector<bool> seen(n, 0);
            for (int i=0; i<n; i++){
                if (seen[i] == true) continue;
                // check if comp is complete 
                int count = 0, edges = 0;
                stack<int> stack;
                stack.push(i);
                while(stack.size()){
                    int node = stack.top(); stack.pop();
                    if (seen[node]) continue;
                    // base case 
                    seen[node] = true;
                    count++;
                    edges += graph[node].size();
                    // children
                    for (int neigh : graph[node]){
                        if (seen[neigh] == true) continue;
                        stack.push(neigh);
                    }
                }
                // check output 
                // ! EVERY PAIR NEEDS TO HAVE AN EDGE TO ALL THE OTHER PAIRS
                if ((count * (count-1)) == edges){
                    complete++;
                }
            }
            // all its a connected graph
            return complete;
            
        }
    };