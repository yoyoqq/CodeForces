class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n+1, 0), suff(n+1, 0);
        for (int i=0; i<n; i++){
            if (i == 0) pref[i] = nums[i];
            else if (nums[i-1] < nums[i]) pref[i] = pref[i-1] + nums[i];
            else break;       
        }
        for (int i=n-1; i>=0; i--){
            if (i == n-1) suff[i] = nums[i];
            else if (nums[i] > nums[i+1]) suff[i] = suff[i+1] + nums[i];
            else break;
        }

        // for (auto& x : pref) cout << x << " "; cout << endl;
        // for (auto& x : suff) cout << x << " "; cout << endl;

        long long ans = LLONG_MAX;
        bool used = false;
        for (int i=0; i<n; i++){
            if (pref[i] == 0 || suff[i+1] == 0) continue;
            // cout << pref[i] << " " << suff[i+1] << endl;
            ans = min(ans, abs(pref[i] - suff[i+1]));
            used = true;
        }
        if (used == false) return -1;
        return (ans == INT_MAX ? -1 : ans);
    }
};

// class Solution {
// public:
//     long long splitArray(vector<int>& nums) {
//         int n = nums.size();
//         int left = 0, right = n-1;
//         long long ls = 0, rs = 0;
//         while (left + 1 < n && nums[left] < nums[left+1]){
//             ls += nums[left];
//             left++;
//         }
//         while (right != 0 && nums[right-1] > nums[right]){
//             rs += nums[right];
//             right--;
//         }
//         cout << right << " " << left << endl;
//         cout << ls << " " << rs << endl;
//         // size 2 ? 
//         if (n == 2) return abs(nums[0] - nums[1]); 
//         if (nums[left] == nums[right] && right-left==1) return abs(left-right);
//         // not possible is not inc/dec 
//         if (left < right) return -1;

//         // remove from both sides 
//         long long total = 0;
//         for (int i=right; i<=left; i++){
//             ls -= nums[i];
//             rs -= nums[i];
//             total += nums[i];
//         }
//         if (right == left){
//             return min(abs((ls+total) - rs) , abs(ls - (rs+total)));
//         }
//         // ans from right to left 
//         long long ans = LLONG_MAX;
//         for (int i=right; i<=left; i++){
//             total -= nums[i];
//             long long l = ls + nums[i];
//             long long r = rs + total;
//             ans = min(ans, abs(l - r));
//         }
//         return ans;
//     }
// };