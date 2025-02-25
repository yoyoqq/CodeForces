class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int MOD = 1e9 + 7;
            int cur_sum = 0;
            int odd = 0, even = 0;
            int res = 0;
            for (int& num : arr){
                cur_sum += num;
                if (cur_sum % 2 == 0){
                    even++;
                    res += odd;
                }else{
                    odd++;
                    res += even;
                }
                res += (cur_sum % 2 == 1);
                res %= MOD;
            }
            return res;
        }
    };