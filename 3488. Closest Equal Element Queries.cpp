class Solution {
    public:
        vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
            // bs for each nums[i]
            int n = nums.size();
            map<int, vector<int>> freq; // num, group_idx 
            map<int, int> group_idx;    // i, idx
            for (int i=0; i<nums.size(); i++){
                group_idx[i] = freq[nums[i]].size(); 
                freq[nums[i]].push_back(i);
            }
            // find shortest for each query
            vector<int> ans;
            for (int query : queries){
                // 0 2 4 
                vector<int>& arr = freq[nums[query]]; // get the idx
                int sz = arr.size();
                int idx = group_idx[query];
                // find shortest 
                if (sz == 1) {
                    ans.push_back(-1);  
                } 
                // front or back 
                else if (sz == 2) {
                    ans.push_back(min(arr[1] - arr[0], n - arr[1] + arr[0])); 
                } 
                // at first, front or back 
                else if (idx == 0) {
                    ans.push_back(min(arr[1] - arr[0], n - arr[sz - 1] + arr[0]));
                } 
                // at end
                else if (idx == sz - 1) {
                    ans.push_back(min(arr[idx] - arr[idx - 1], n - arr[idx] + arr[0]));
                } 
                // on mid 
                else { 
                    ans.push_back(min(arr[idx] - arr[idx - 1], arr[idx + 1] - arr[idx]));
                }
            }
            return ans;
        }
    };