// using brute force, two pointers O(n * k)

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        // if (nums.size() == 1) return {nums[0]};
        if (k == 1) return nums;
        vector<int> powers; 
        int n = nums.size();
        for (int i=0; i<n-k+1; i++){
            int mx = 0; 
            // k increasing elements
            for (int j=i; j<i+k-1; j++){
                if (nums[j] - nums[j+1] != -1){
                    mx = -1;
                    break;                    
                }
                mx = max(mx, nums[j+1]);
                // cout << nums[j] << " " << nums[j+1] << "  ";
            }
            powers.push_back(mx);
            // cout << endl;
        }
        return powers;
    }

};




// Find the Power of K-Size Subarrays I


// USING counter o(n)

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums;
        int n = nums.size();
        int count = 1;
        vector<int> a(n-k+1, -1);   // output 
        for (int i=0; i<n-1; i++){  // compare all the nums + 1 
            // update counter
            if (nums[i] + 1 == nums[i+1]){
                count++;
            }else{
                count = 1;
            }
            // update ans for the prevous -k with max 
            if (count >= k){
                a[i-k+2] =  nums[i+1];
            }
            // cout << count << " ";
        }
        return a;
    }
};