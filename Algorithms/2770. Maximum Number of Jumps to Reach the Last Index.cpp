class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        // BFS WONT WORK.. need to know whats in front either way ... :/
        
        queue<pair<int, int>> q;
        q.push({0, 0}); // idx, jumps
        set<int> seen; 
        while (q.size()) {
            
        }
    }
};


class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        // brute force 
        int n = nums.size();
        vector<int> arr(n, -1);
        for (int j=0; j<n; j++) {
            for (int i=0; i<j; i++) {
                int calc = nums[j] - nums[i];
                if (-target <= calc && calc <= target) {
                    if (i == 0) {
                        arr[j] = max(arr[j], 1);
                    }
                    else if (arr[i] == -1) {
                        continue;
                    }
                    else {
                        arr[j] = max(arr[j], arr[i] + 1);
                    }
                }
            }
        }
        for (int x : arr) cout << x << " ";
        return arr[n-1];
    }
};