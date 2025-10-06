class UnionFind{
public:
    vector<int> parent;
    vector<int> ranks;
    UnionFind(int size){
        for(int i=0; i<size; i++){
            parent.push_back(i);
            ranks.push_back(1);
        } 
    }

    int find(int node){
        if (parent[node] == node) return parent[node];
        return parent[node] = find(parent[node]); 
    }

    void unite(int node1, int node2){
        int p1 = find(node1), p2 = find(node2);
        if (p1 == p2) return;
        if (ranks[p1] >= ranks[p2]){
            ranks[p1] += ranks[p2] ;
            parent[p2] = p1; 
        }else{
            ranks[p2] += ranks[p1];
            parent[p1] = p2;
        }
    }
};


class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        // put into groups 
        UnionFind uf(nums.size());      // uf of indeces UNIQUE  
        for (auto swap : swaps){
            uf.unite(swap[0], swap[1]);
        }
        // find groups 
        map<int, vector<int>> groups;
        for (int i=0; i<nums.size(); i++){
            int parent = uf.find(i);
            groups[parent].push_back(nums[i]);
        }
        // into deque 
        map<int, deque<int>> groups2;
        for (auto& [k, v] : groups){
            sort(v.begin(), v.end());
            for (auto x : v) groups2[k].push_back(x);
        }

        // simulation, put in decreasing order  
        long long ans = 0;
        for (int i=0; i<nums.size(); i++){
            int parent = uf.find(i);
            int cur = 0;
            // biggest num 
            if (i % 2 == 0){
                cur = groups2[parent].back(); groups2[parent].pop_back();
                ans += cur;                
            }
            // smallest num
            else{
                cur = groups2[parent].front(); groups2[parent].pop_front();
                ans -= cur;
            }
            // cout << ans << " " << cur << endl;
        }
        return ans;
    }
};
