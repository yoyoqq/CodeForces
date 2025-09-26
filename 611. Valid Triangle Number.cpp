class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                int k = (lower_bound(nums.begin(), nums.end(), nums[i]+nums[j]) - nums.begin()) - 1;
                if (j < k) ans += (k-j);
            }
        }
        return ans;
    }
};


class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums = sorted(nums)
        n = len(nums)
        ans = 0
        for i in range(n):
            for j in range(i+1, n):
                k = bisect_left(nums, nums[i]+nums[j])-1
                if j < k:
                    ans += (k-j)
        return ans
