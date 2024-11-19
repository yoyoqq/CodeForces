class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // intial state
        long long cur = 0;
        long long sm = 0;
        map<int, int> seen;
        for (int i=0; i<k; i++){
            cur += nums[i];
            seen[nums[i]]++;
        }  
        if (seen.size() == k)
            sm = max(sm, cur);
            
        // cout << seen.size() << endl;
        // sliding window
        int left = 0;
        for (int right=k; right<nums.size(); right++){
            // get new window
            seen[nums[right]]++;
            seen[nums[left]]--;
            if (seen[nums[left]] == 0) seen.erase(nums[left]);
            cur += nums[right];
            cur -= nums[left];
            // new res? 
            if (seen.size() == right - left){
                sm = max(sm, cur);
            }
            // cout << left << " " << right << " " << sm << " " << seen.size() << endl;
            left++;
        }
        return sm;



        // for (int right=k+1; right<nums.size(); right++){
        //     // repeated?
        //     if (seen.find(nums[right]) != seen.end()){
        //         left = r;
        //         cur = 0;
        //         seen.clear();
        //     }
        //     // move pointers and update seen
        //     // else
        //     seen.insert(nums[right]);
        //     seen.erase(nums[left]); 
        //     cur -= nums[left];
        //     cur += nums[right];
        // }
        // return sm;
    }
};