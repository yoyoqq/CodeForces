class UnionFind{
public:
    vector<int> parent;
    vector<int> count;
    
    UnionFind(int sz){
        for (int i=0; i<=sz; i++){
            parent.push_back(i);
            count.push_back(1);
        }
    }

    int find(int node){
        if (parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }

    void unite(int n1, int n2){
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) return;
        if (count[p1] < count[p2]){
            swap(p1, p2);
        }
        parent[p2] = p1;
        count[p1] += count[p2];
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        UnionFind uf(c);
        // 1. Union find -> put into groups 
        for (auto& con : connections){
            uf.unite(con[0], con[1]);
        }
        // 2. for each have the parent 
        // map<int, priority_queue<int>> group;
        map<int, set<int>> group;
        for (int i=1; i<=c; i++){
            // group -> set(nodes)
            group[uf.find(i)].insert(i);
        }
        // 3. for each group -> heap, get min 
        vector<int> ans;
        for (auto& q : queries){
            set<int>& st = group[uf.find(q[1])];
            if (q[0] == 1){
                if (st.find(q[1]) != st.end()){
                    ans.push_back(q[1]);
                }
                else if (group[uf.find(q[1])].size() == 0){
                    ans.push_back(-1);
                }else{
                    ans.push_back(*group[uf.find(q[1])].begin());
                }
                // ans.push_back(sz != 0 ? sz : -1);           
            }
            else{
                st.erase(q[1]);
            }
        }
        return ans;
    }
};