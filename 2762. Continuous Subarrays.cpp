class Solution {
private:
    bool compare(int a, int b){
        return (abs(a - b) > 2);
    }
    
public:
    long long continuousSubarrays(vector<int>& nums) {
        // if we are looknig for every pair, 
        // we need to have the max and min from that window 
        int n = nums.size();
        map<int, int> seen;   // value, idx 
        int left = 0;
        long long count = 0;
        for (int right=0; right<n; right++){
            // base case add 
            int cur = nums[right];
            seen[cur]++;

            // check if true 
            while (!seen.empty() && compare(seen.begin()->first, seen.rbegin()->first)){
                seen[nums[left]]--;
                if (seen[nums[left]] == 0) seen.erase(nums[left]);
                left++;
            }
            
            // count
            count += right - left + 1;
        }
        
        return count;
    }
};