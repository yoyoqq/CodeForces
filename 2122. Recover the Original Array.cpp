class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        multiset<int> s(nums.begin(), nums.end());
        int start = *begin(s);
        for (auto it = next(begin(s)); it != end(s); it++){
            int k = (*it - start) / 2;
            if (k > 0 && start + 2 * k == *it){ // if positive and its pair 
                auto ss = s;
                vector<int> res;
                while (ss.size()){
                    // make pair 
                    auto it_h = ss.find(*begin(ss) + 2 * k);
                    if (it_h == end(ss)) break;
                    res.push_back(*begin(ss) + k);
                    ss.erase(begin(ss));
                    ss.erase(it_h);
                }
                if (ss.empty()){
                    return res;
                }
            }
        }
        return {};
    }
    
};


// class Solution {
// public:
//     vector<int> recoverArray(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         // get k with nums[0] with the rest 
//         int n = nums.size();
//         map<int, int> freq;
//         for (int i=0; i<n; i++){
//             freq[nums[i]]++;
//         }
//         for (int i=1; i<n; i++){
//             // get k 
//             if ((nums[i] - nums[0]) % 2 != 0) continue;
//             int k = nums[i] - ((nums[i] - nums[0] )/ 2);
//             // int k = ((nums[i] - nums[0] )/ 2);
//             // how to pair given k ?  
//             map<int, int> cur_freq = freq;
//             vector<int> res;
//             for (int i=0; i<n; i++){    // lower bound 
//                 int lower = nums[i];
//                 int mid = nums[i] + k;
//                 int upper = nums[i] + k + k;
//                 cout << lower << " " << mid << " " << upper << endl;
//                 if (freq.find(lower) != freq.end() && freq.find(upper) != freq.end()){
//                     freq[lower]--;
//                     freq[upper]--;
//                     if (freq[lower] == 0) freq.erase(lower);
//                     if (freq[upper] == 0) freq.erase(upper);
//                     res.push_back(mid);
//                 }
//             }
//             // return k
//             cout << k << endl;
//             for (int i=0; i<res.size(); i++){
//                 cout << res[i] << " ";
//             }cout << endl;
//             if (res.size() == n / 2){
//                 return res;
//             }
//         }
//         return {};
//     }
// };