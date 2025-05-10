class Solution {
    public:
        long long minSum(vector<int>& nums1, vector<int>& nums2) {
            // sum1, sum2 
            // count1, count2 
    
            // increase the bigger one 
            // all by one 
    
            int n = nums1.size(), m = nums2.size();
            long long sum1 = 0, sum2 = 0;
            int count1 = 0, count2 = 0;
            for (int i=0; i<n; i++){
                if (nums1[i] == 0) count1++;
                sum1 += nums1[i]; 
            }
            for (int i=0; i<m; i++){
                if (nums2[i] == 0) count2++;
                sum2 += nums2[i]; 
            }
    
            long long left = sum1 + count1;
            long long right = sum2 + count2;
            // it is possible if the smaller reaches the bigger
            if (left <= right && count1) return max(left, right);
            if (left >= right && count2) return max(left, right);
            if (left == right) return max(left, right);
            return -1;
            
            // NOT POSSIBLE IF: 
            // sum equal, and one of these is zero 
            // if no count1/2 
            // cout << left << " " << right << endl;
            // if (sum1 == sum2 && (count1 == 0 && count2 != 0) || (count1 != 0 && count2 == 0)){
            //     return -1;
            // }
            // if (count1 == 0 && count2 == 0 && sum1 != sum2) return -1;
            // if (right > left && count1 == 0) return -1;
            // if (left > right && count2 == 0) return -1;
            // cout << left << " " << right << endl;
            // return max(left, right);
        }
    };