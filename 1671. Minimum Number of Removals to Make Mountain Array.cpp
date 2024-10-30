class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // LIS and LIS reversed 
        int n = nums.size();
        vector<int> prefix(n, 1);
        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (nums[i] > nums[j]){
                    prefix[i] = max(prefix[i], prefix[j] + 1);
                }
            }
        }
        vector<int> suffix(n, 1);
        for (int i=n-1; i>=0; i--){
            for (int j=i + 1; j<n; j++){
                if (nums[i] > nums[j]){
                    suffix[i] = max(suffix[i], suffix[j] + 1);
                }
            }
        }
        print(prefix);
        print(suffix);
        // count max diff from left + right - 2
        int res = INT_MAX; 
        for (int i=0; i<n; i++){
            if (prefix[i] > 1 && suffix[i] > 1) // its mountain
                res = min(res, n - suffix[i] - prefix[i] + 1);
        }
        return res;
    }

private:
    void print(vector<int>& a){
        for (int& x : a) cout << x << " ";
        cout << endl;
    }
};