class Solution {
public:
    bool is_palindrome(string s){
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t) return true;
        return false;
    }

    string to_bin(int n){
        string ans = "";
        while (n){
            ans += (n%2 == 0 ? '0' : '1');
            n = n / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> minOperations(vector<int>& nums) {
        // 1. list of palindromes 
        // 0 1 3   7 
        // 0 1 101 111 
        // 2. BS 

        // 5049 closest upper bound palindrome 
        // for (int i=5000; i<10000; i++){
        //     string t = to_bin(i);
        //     if (is_palindrome(t)){
        //         cout << i << endl;
        //         break;
        //     }
        // }

        // get the palindromes 
        vector<int> idx;
        for (int i=1; i<=5000; i++){
            string t = to_bin(i);
            if (is_palindrome(t)){
                idx.push_back(i);
            }
        }
        idx.push_back(5049);

        // serach them 
        vector<int> ans;
        for (int& num : nums){
            // return iterator greater or equal to the val 
            auto it = lower_bound(idx.begin(), idx.end(), num);
            int best = INT_MAX; 
            if (it != idx.end()){
                best = min(best, abs(num-*it));
            }
            if (it != idx.begin()){
                it--;
                best = min(best, abs(num-*it));
            }
            ans.push_back(best);
        }
        return ans;
    }
};