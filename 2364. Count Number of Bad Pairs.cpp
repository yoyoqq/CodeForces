class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            // equals to -> j - i == nj - ni 
            // to        -> j - nj = i - ni
            // keep track of the pairs that have the same ans (freq)
            long long n = nums.size();
            map<int, int> freq;
            for (int i=0; i<n; i++){
                freq[i-nums[i]]++;
            }   
            // calculate the number of good pairs
            long long ans = n*(n-1)/2;    // bad pairs 
            for (auto& [k, v] : freq){
                if (v >= 2){
                    ans -= (1LL*v*(v-1)/2);
                }
            }
            return ans; 
        }
    };