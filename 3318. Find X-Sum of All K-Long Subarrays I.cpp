class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        // brute force 
        vector<int> ans;
        for (int i=0; i<nums.size()-k+1; i++){
            // get the freq 
            map<int, int> freq; // optimization -> use map<int, set<>>
            for (int j=i; j<i+k; j++){
                freq[nums[j]]++;
            }
            // sort by freq 
            vector<pair<int, int>> ordered; 
            for (auto [k, v] : freq){
                ordered.push_back({v, k});
            }
            sort(ordered.begin(), ordered.end());
            int temp = x;
            int count = 0;
            for (int k=ordered.size()-1; k>=0 && temp; temp--, k--){
                auto& [f, s] = ordered[k];
                count += f * s;
            }
            ans.push_back(count);
        }
        return ans;
    }
};