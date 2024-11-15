class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // since we have a gap in the middle, two pointers 
        // find the LIsq in the right
        int n = arr.size();
        int right = n - 1;
        while (right > 0 && arr[right] >= arr[right-1]){
            right--;
        }
        int ans = right;
        int left = 0;
        while (left < right && (left == 0 || arr[left-1] <= arr[left])){
            while (right < n && arr[left] > arr[right]){
                right++;
            }
            ans = min(ans, right - left  - 1);
            left++;
        }
        return ans;
    }
};