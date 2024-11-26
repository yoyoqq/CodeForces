class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // DAG
        // reverse the graph 
        // iterate n 
        // if no children is champion
        //      if more than one chamion return -1

        // get graph reversed pointers
        unordered_map<int, vector<int>> graph;
        for (int i=0; i<edges.size(); i++){
            int x = edges[i][0], y = edges[i][1]; 
            graph[y].push_back(x);
        }
        // find champion
        int champion = -1; 
        for (int i=0; i<n; i++){
            if (graph[i].size() == 0){
                if (champion != -1){
                    return -1;
                }
                champion = i;
            }
        }
        return champion;
    }
};


class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // use count 
        vector<int> a(n); 
        for (auto& edge : edges){
            a[edge[1]]++;
        }
        int champ = -1; 
        for (int i=0; i<n; i++){
            if (a[i] == 0){
                if (champ != -1) return -1;
                champ = i;
            }
        }
        return champ;
    }
};