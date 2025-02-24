class Solution {
    public:
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = amount.size();
            tree.resize(n);
            visited.assign(n, false);
            for (vector<int> edge : edges){
                tree[edge[0]].push_back(edge[1]);
                tree[edge[1]].push_back(edge[0]);
            }
            findBobPath(bob, 0);
            visited.assign(n, false);
            findAlicePath(0, 0, 0, amount);
            return maxIncome;
        }
    
    private:
        unordered_map<int, int> bobPath;
        vector<bool> visited;
        vector<vector<int>> tree;
        int maxIncome = INT_MIN;
    
        // dfs bob 
        // thre is only one path, there are no cycles -> n-1
        bool findBobPath(int source, int time){
            bobPath[source] = time;
            visited[source] = true;
            if (source == 0) return true;
            for (int adj : tree[source]){
                if (!visited[adj] && findBobPath(adj, time+1)) return true;
            }
            bobPath.erase(source);
            return false;
        }
    
        void findAlicePath(int source, int time, int income, vector<int>& amount){
            visited[source] = true;
            if (bobPath.find(source) == bobPath.end() || time < bobPath[source]){
                income += amount[source];
            }
            else if (time == bobPath[source]){
                income += amount[source]/2;
            }
    
            if (tree[source].size() == 1 && source != 0){
                maxIncome = max(maxIncome, income);
            }
            for (int adj : tree[source]){
                if (!visited[adj]){
                    findAlicePath(adj, time+1, income, amount);
                }
            }
        }
    };