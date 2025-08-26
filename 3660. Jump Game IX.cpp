class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n), suff(n), ans(n);
        // prefix 
        pref[0] = nums[0];
        for (int i=1; i<n; i++){
            pref[i] = max(pref[i-1], nums[i]);
        }
        // suffix 
        suff[n-1] = nums[n-1];
        for (int i=n-2; i>=0; i--){
            suff[i] = min(suff[i+1], nums[i]);
        }
        // output 
        ans[n-1] = pref[n-1]; 
        for (int i=n-2; i>=0; i--){
            ans[i] = pref[i];  // leftmost max 
            // rightmost min, can take max value from the right 
            if (ans[i] > suff[i+1]){   
                ans[i] = ans[i+1];
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> maxValue(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> pointer;
//         for(int i=0; i<n; i++) pointer.push_back(i);      
//         // point to the biggest 
//         int j = 0;
//         int val = nums[0];
//         for (int i=0; i<n; i++){
//             // maximum found so far 
//             if (nums[i] > val){
//                 val = nums[i];
//                 j = i;
//             }
//             // update pointer if smaller 
//             if (nums[i] < nums[j]){
//                 pointer[i] = j;
//             }
//         }   
//         // for (auto x : pointer) cout << nums[x] << " ";
//         for (int i=0; i<n; i++) cout << pointer[i] << " ";
//         j = n-1; 
//         val = nums[n-1];
//         for (int i=n-1; i>=0; i--){
//             // get the min val 
//             if (nums[i] < val){
//                 val = nums[i];
//                 j = i;
//             }
//             // compare to the min val
//             if (nums[i] > nums[j]){
//                 if (nums[pointer[i]] < nums[pointer[j]]){
//                     pointer[i] = j;
//                 }
//             }
//         }
//         cout << endl;
//         cout << j << " "<< val << endl;
//         for (int i=0; i<n; i++) cout << pointer[i] << " ";
//         // for (auto x : pointer) cout << nums[x] << " ";
//         // ouptut 
//         vector<int> b;
//         for (int i=0; i<n; i++){
//             b.push_back(nums[pointer[i]]);
//         }
//         return b;
//     }
// };