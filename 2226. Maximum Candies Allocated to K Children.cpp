class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            if (candies.size() == 1 && candies[0] < k) return 0;
            // use the proper right bound 
            long long left = 1, right = accumulate(candies.begin(), candies.end(), 0LL) / k;
            // BS
            long long ans = 0;
            while (left <= right){
                // long long mid = (left + right) / 2;
                // be careful of overflow!! 
                long long mid = left + (right - left) / 2;
                if (possible(candies, mid, k)){
                    ans = mid;
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
                // cout << mid << endl;
            }
            return ans;
        }
    
    private:
        bool possible(vector<int>& candies, long long threshold, int k){
            long long count = 0;
            for (int candy : candies){
                count += (candy / threshold);
            }
            // cout << count << " " << k << endl;
            return (count >= k ? true : false);
        }
    };