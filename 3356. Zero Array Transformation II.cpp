class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            // how many can we make 0 using queries 
            // after k operations 
            int left = 0, right = queries.size(); 
            int ans = -1;
            while (left <= right){
                int mid = (left + right) / 2;
                // cout << mid << endl;
                if (line_sweep(nums, queries, mid)){
                    ans = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            return ans;
        }
    
    private:
        bool line_sweep(vector<int>& nums, vector<vector<int>>& queries, int k){
            int n = nums.size();
            vector<int> line_sweep(n+1, 0);
            for (int i=0; i<k; i++){
                int x = queries[i][0], y = queries[i][1], z = queries[i][2];
                line_sweep[x] += z;
                line_sweep[y+1] -= z;
            }
            int count = 0;
            int decrement = 0;
            for (int i=0; i<n; i++){
                decrement += line_sweep[i];
                if (nums[i] - decrement <= 0) count++;
                // cout << nums[i]<< " " << decrement << endl;
            }
            return count == n;
        }
    };