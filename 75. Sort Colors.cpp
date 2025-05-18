class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 1. count: 0 1 2 (not in place) 
        int n = nums.size();
        int zero = 0, one = 0, two = 0;
        for (int i=0; i<n; i++){
            if (nums[i] == 0) zero++;   
            if (nums[i] == 1) one++;   
            if (nums[i] == 2) two++;   
        }
        for (int i=0; i<n; i++){
            if (zero != 0) {nums[i] = 0; zero--;}
            else if (one != 0) {nums[i] = 1; one--;}
            else if (two != 0) {nums[i] = 2; two--;}
        }
        

        // 2. in place (bubble sort, insertion sort..) any sort O(n2)
        // int n = nums.size();
        // for (int i=0; i<n; i++){
        //     for (int j=i+1; j<n; j++){
        //         if (nums[i] > nums[j]) swap(nums[i], nums[j]);
        //     }
        // }
        
        // 3. sliding window twice 
        // int n = nums.size();
        // int i=0;
        // for (int j=0; i<n && j<n; i++){
        //     if (nums[i] == 0) continue;
        //     j = max(j, i);
        //     while (j < n && nums[j] != 0){
        //         j++;
        //     }
        //     if (j < n) swap(nums[i], nums[j]); 
        // }
        // for (int i=0, j=1; i<n && j<n; i++, j=max(j, i)){
        //     if (nums[i] == 0) continue;
        //     while (j < n && nums[j] != 1){
        //         j++;
        //     }
        //     if (j < n && nums[i] > nums[j]) swap(nums[i], nums[j]);
        // }
    }
};