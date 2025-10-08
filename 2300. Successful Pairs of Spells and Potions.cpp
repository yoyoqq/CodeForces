class Solution {
public:

    int binary_search(vector<int>& potions, long long find){
        int l = 0, r = potions.size()-1;
        if (potions[r] < find) return r+1;
        int ans = 0;
        while (l <= r){
            int mid = l + (r-l)/2;
            if (potions[mid] >= find){
                r = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        vector<int> ans(n, 0);
        for (int i=0; i<n; i++){
            long long find = success/spells[i] + (success%spells[i] == 0 ? 0 : 1); 
            // int idx = lower_bound(potions.begin(), potions.end(), find)-potions.begin();
            int idx = binary_search(potions, find);
            cout << find << " " << idx << endl;
            ans[i] = max(0, m-idx);
        }
        return ans;
    }
};