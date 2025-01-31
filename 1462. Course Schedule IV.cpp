class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // make graph
        map<int, vector<int>> graph;
        for (int i=0; i<prerequisites.size(); i++){
            int x = prerequisites[i][0], y = prerequisites[i][1];
            graph[x].push_back(y);
        }
        // output 
        vector<bool> res;
        for (int i=0; i<queries.size(); i++){
            int x = queries[i][0], y = queries[i][1];
            res.push_back(dfs(graph, x, y));
        }
        return res;
    }

private:
    bool dfs(map<int, vector<int>>& graph, int x, int y){
        set<int> seen;
        seen.insert(x);
        stack<int> stack;
        stack.push(x);
        while(stack.size()){
            int cur_node = stack.top(); stack.pop();
            if (y == cur_node) return true;
            for (int next_node : graph[cur_node]){
                if (seen.find(next_node) == seen.end()){
                    seen.insert(next_node);
                    stack.push(next_node);
                }
            }
        }
        return false;
    }
};