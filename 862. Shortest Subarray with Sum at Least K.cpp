class Solution {
// private:
//     vector<int> prefix(vector<int>& nums){
//         vector<int> res(nums.size()+1, 0);
//         for (int i=0; i<nums.size(); i++){
//             res[i+1] = res[i] + nums[i];
//         }
//         return res;
//     }

//     bool possible_window(vector<int>& prefix, int window, int sum){
//         // left, +1 for right   
//         // check if reaches sum 
//         for (int i=window; i<prefix.size(); i++){
//             if (prefix[i] - prefix[i-window] >= sum){
//                 return true;
//             }
//         }
//         return false;
//     }
    
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int res = INT_MAX;
        long long cur_sum = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for (int r=0; r<nums.size(); r++){
            cur_sum += nums[r];
            
            if (cur_sum >= k){
                res = min(res, r + 1);
            }
            while (pq.size() && cur_sum - pq.top().first >= k){
                auto top = pq.top(); pq.pop();
                res = min(res, r - top.second);
            }
            pq.push({cur_sum, r});
        } 
        return res == INT_MAX ? -1 : res;
        
        
        
        // // binary search with sliding window (prefix sum)
        // vector<int> pre = prefix(nums);
        // int left = 1;
        // int right = nums.size();
        // int mn = INT_MAX;
        // while (left <= right){
        //     int mid = left + (right - left) / 2;
        //     if (possible_window(pre, mid, k)){
        //         mn = min(mn, mid);
        //         right = mid - 1;
        //     }else{
        //         left = mid + 1;
        //     }
        // }
        // if (mn == INT_MAX) {
        //     if (*max_element(nums.begin(), nums.end()) >= k) return 1;
        // }
        // return (mn == INT_MAX ? -1 : mn);
        
        // GREEDY ? 
        // int n = nums.size();
        // vector<int> dp(n, 0);
        // int cur = 0;
        // int mn = INT_MAX;
        // int count = 0;
        // for (int& x : nums){
        //     // CALCULATE cur 
        //     // posiive positive
        //     // negative negative 
        //     // negative positive
        //     // positive negative
        //     // positive
        //     if (cur + x > 0){
        //         cur += x;
        //         count++;
        //     }
        //     // negative. check biggest negative
        //     // biggest is by adding up 
        //     else if (cur + x > x){
        //         cur += x;
        //         count = 
        //     }else{
        //     }
        //     if (cur >= k){
        //         mn = min(mn, count);
        //     }
        // }
        // return (mn == INT_MAX ? -1 : mn);
        
        // // does normal sliding window work?
        // int n = nums.size();
        // int left = 0;
        // int cur_sum = 0;
        // int mn_len = INT_MAX;
        // for (int right=0; right<n; right++){
        //     // take right
        //     cur_sum += nums[right];
        //     // normal: move left, get res 
        //     while (left <= right && cur_sum >= k){
        //         mn_len = min(mn_len, right - left + 1);
        //         cur_sum -= nums[left];
        //         left++;
        //     }
        //     // if negative 
        //     while (left <= right && nums[left] < 0){
        //         cur_sum -= nums[left];
        //         left++;
        //     }
        //     if (cur_sum >= k) 
        //         mn_len = min(mn_len, right - left + 1);

        //     cout << right  << " " << left << " " << cur_sum << endl;
        // }
        // return (mn_len != INT_MAX ? mn_len : -1);
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0); // Prefix sum array
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + nums[i - 1];
        }

        deque<int> cand; // Deque to store candidate indices
        int shortest = INT_MAX;

        for (int i = 0; i <= n; i++) {
            // Check if we can find a valid subarray
            while (!cand.empty() && pref[i] - pref[cand.front()] >= k) {
                shortest = min(shortest, i - cand.front());
                cand.pop_front();
            }

            // Maintain a decreasing order of prefix sums in the deque
            while (!cand.empty() && pref[i] <= pref[cand.back()]) {
                cand.pop_back();
            }

            cand.push_back(i);
        }

        return shortest == INT_MAX ? -1 : shortest;
    }
};
