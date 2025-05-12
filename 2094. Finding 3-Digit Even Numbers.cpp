class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        // calculate frequencies
        map<int, int> freq;
        for (int num : digits){
            freq[num]++;
        }
        // 
        vector<int> ans;
        for (int i=100; i<1000; i++){
            if (i % 2 == 0 && have_digits(i, freq)) ans.push_back(i); 
        }
        return ans;
    }

    bool have_digits(int num, map<int, int> freq){
        for (int i=0; i<3; i++){
            freq[num%10]--;
            if (freq[num%10] == -1) return false;
            num /= 10;
        }
        return true;
    }
};

// class Solution {
// public:
//     set<int> seen;

//     vector<int> findEvenNumbers(vector<int>& digits) {
//         // for each number take or no take 
//         // dp
//         // reduce each num to 3 occ 
//         map<int, int> freq;
//         for (int num : digits){
//             freq[num]++;
//             if (freq[num] > 3) freq[num] = 3;
//         }
//         dp(0, freq);
//         vector<int> ans;
//         for (auto s : seen) ans.push_back(s);
//         // sort(ans.begin(), ans.end());
//         return ans;
//     }

//     void dp(int cur, map<int, int>& freq){
//         if (to_string(cur).size() == 3){
//             if (cur % 2 == 0) seen.insert(cur);
//             return;
//         }
//         for (auto [k, v] : freq){
//             if (v >= 1){
//                 freq[k]--;
//                 dp(cur * 10 + k, freq);
//                 freq[k]++;
//             }
//         }
//     }
// };