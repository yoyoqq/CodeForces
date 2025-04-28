#include <vector>
#include <iostream>

class UnionFind{
    public:
        vector<int> parent;
        vector<int> count;
        UnionFind(int size){
            parent.resize(size);
            count.resize(size);
            for (int i=0; i<size; i++){
                parent[i] = i;
                count[i] = 1;
            }
        }
    
        int find(int node){
            if (parent[node] == node) return parent[node];
            parent[node] =  find(parent[node]);
            return parent[node];
        }
    
        void unite(int node1, int node2){
            int parent1 = find(node1), parent2 = find(node2);
            if (parent1 == parent2) return;
            if (count[parent1] > count[parent2]){
                count[parent1] += count[parent2];
                parent[parent2] = parent1;
            }else{
                count[parent2] += count[parent1];
                parent[parent1] = parent2;
            }
        }
    };
    
    class Solution {
    public:
        vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
            // ways -> bin serach (nlogn), unionfind(n?), grouping(n)
            // bin search ? 
            // lower_bound - arr.begin();
            
        }
    };
            // // use union find 
            // UnionFind uf(n);
            // for (int i=1; i<n; i++){
            //     if (abs(nums[i]-nums[i-1]) <= maxDiff){
            //         uf.unite(i, i-1);
            //     }
            // }
            // // output queries
            // int m = queries.size();
            // vector<bool> output(m);
            // for (int i=0; i<m; i++){
            //     int parent1 = uf.find(queries[i][0]);
            //     int parent2 = uf.find(queries[i][1]);
            //     if (parent1 == parent2) output[i] = true;
            //     else output[i] = false;
            // }
            // return output;
    
    
            // // put into groups 
            // vector<int> groups(n);
            // for (int i=1; i<n; i++){
            //     if (abs(nums[i]-nums[i-1]) <= maxDiff){
            //         groups[i] = groups[i-1];
            //     }else{
            //         groups[i] = i;
            //     }
            // }
            // // for (int& g : groups) cout << g << " "; cout << endl;
            // // output queries
            // int m = queries.size();
            // vector<bool> output(m);
            // for (int i=0; i<m; i++){
            //     if (groups[queries[i][0]] == groups[queries[i][1]]) output[i] = true;
            //     else output[i] = false;
            // }
            // return output;