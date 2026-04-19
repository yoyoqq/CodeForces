class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp; 
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for (auto [k, v] : mp) {
            if (v.size() < 3) continue;
            // for (auto val : v) cout << k << " " << val << endl;
            for (int x = 2; x < v.size(); x++) {
                int i = v[x-2];
                int j = v[x-1];
                int k = v[x];
                int calc = abs(i-j) + abs(k-j) + abs(k-i);
                ans = min(ans, calc);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};