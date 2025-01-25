class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // 1. make groups 
        // 2. map them 
        vector<int> nums_sorted = nums; 
        sort(nums_sorted.begin(), nums_sorted.end());
        vector<queue<int>> groups;
        map<int, int> mapping;
        queue<int> cur_group;
        cur_group.push(nums_sorted[0]);
        mapping[nums_sorted[0]] = 0;
        int group_num = 0;
        for (int i=1; i<nums.size(); i++){
            if (nums_sorted[i] - cur_group.back() <= limit){
                cur_group.push(nums_sorted[i]);
            }else{
                groups.push_back(cur_group);
                group_num++;
                cur_group = {};
                cur_group.push(nums_sorted[i]);
            }
            mapping[nums_sorted[i]] = group_num;
        }
        if (cur_group.size() != 0) groups.push_back(cur_group);
        for (int i=0; i<nums.size(); i++){
            int find_group = mapping[nums[i]];
            nums[i] = groups[find_group].front(); 
            groups[find_group].pop();
        }
        return nums;
    }
};


// class Solution {
// public:
//     vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
//         // precoputation
//         int n = nums.size();
//         vector<int> unique;
//         map<int, vector<int>> freq;
//         for (int i=0; i<n; i++){
//             if (freq.find(nums[i]) == freq.end())
//                 unique.push_back(nums[i]);
//             freq[nums[i]].push_back(i);
//         }
//         sort(unique.begin(), unique.end());

//         // for (int i=0; i<unique.size(); i++){
//         //     cout << unique[i] << " ";
//         // }cout << endl;
        
//         // only swap value if smaller 
//         for (int i=0; i<n; i++){
//             int missing = max(0, nums[i] - limit);
//             int idx = bin_search(unique, missing);  // from unique
//             // cout << missing << " " << missing_idx << endl;
//             for (int j=idx; j<unique.size(); j++){
//                 if (nums[i] <= unique[j]) break;
//                 if (freq[unique[j]].size() != 0){
//                     int temp = unique[j];
//                     unique[j] = nums[i];
//                     nums[i] = temp;
//                     freq[unique[j]].pop_back();
//                     break;
//                 }
//             }
//         }
//         return nums;
//     }

//     // lower bound 
//     int bin_search(vector<int>& unique, int target){
//         // lower bound 
//         int left = 0, right = unique.size()-1;
//         int ans = 0;
//         while (left <= right){
//             int mid = (left + right) / 2;
//             if (unique[mid] <= target){
//                 ans = mid; 
//                 left = mid + 1;
//             }else{
//                 right = mid - 1;
//             }
//         }
//         return ans; 
//     }
// };