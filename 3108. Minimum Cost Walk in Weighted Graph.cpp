class UnionFind{
    public:
        vector<int> parent;
        vector<int> count;
    
        UnionFind(int n){
            // each count is 1 
            count.resize(n, 1);
            // each is its own parent
            parent.resize(n);
            for (int i=0; i<n; i++){
                parent[i] = i;
            }
        }
    
        int find(int node){
            if (parent[node] != node){
                parent[node] = find(parent[node]);
            }
            return parent[node];
        }
    
        void unite(int node1, int node2){
            int p1 = find(node1), p2 = find(node2);
            if (p1 == p2) return;
            // move all to p1 
            if (count[p1] > count[p2]){
                count[p1] += count[p2];
                parent[p2] = p1;
            }
            else{
                count[p2] += count[p1];
                parent[p1] = p2; 
            }
        }
    };
    
    class Solution {
    public:
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            // make graph 
            UnionFind uf(n); 
            vector<int> cost(n, -1);
            for (int i=0; i<edges.size(); i++){
                int x = edges[i][0], y = edges[i][1], val = edges[i][2];
                int node1 = uf.find(x);
                int node2 = uf.find(y);
                uf.unite(node1, node2);
            } 
            // calcualte cost of each comp
            for (auto& edge : edges){
                int root = uf.find(edge[0]);
                cost[root] &= edge[2];
            }
            // output for each query
            vector<int> ans(query.size()); 
            for (int i=0; i<query.size(); i++){
                int x = query[i][0], y = query[i][1];
                // needs to be the same parent otherwise is not possible
                if (uf.find(x) == uf.find(y)){
                    ans[i] = cost[uf.find(x)];
                }else{
                    ans[i] = -1;
                }
            }
            return ans;
            
        }
    };