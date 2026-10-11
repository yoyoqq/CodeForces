class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int, int>, int> freq;
        int ans = 0, mx = 0;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] == nums[i-1]) ans++;
            else {
                // 1 3 1 3 1 1 
                freq[{nums[i], nums[i-1]}]++;
                freq[{nums[i-1], nums[i]}]++;
            }
        }
        for (auto it: freq) {
            cout << it.first.first << " " << it.first.second << " " << it.second << endl;
            mx = max(mx, it.second);
        }
        cout << ans << " " << mx << endl;
        return ans + mx;
    }
};