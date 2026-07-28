class Solution {
public:
    string smallestPalindrome(string s) {
        // count
        map<char, int> freq;
        for (char& c : s) {
            freq[c]++;
        }
        // make perm 
        string odd = ""; 
        string left = "";
        for (auto& [k, v] : freq) {
            int count = v / 2;
            for (int i=0; i<count; i++) {
                left += k;
            }
            if (v % 2 == 1 && odd.size() == 0) odd = k; 
        } 
        string right = left;
        reverse(right.begin(), right.end());
        string output = left + odd + right;
        return output;
    }
};