class Solution {
public:
    int minimumLength(string s) {
        // count alphabet
        vector<int> alphabet(26, 0);
        for (char& chr : s){
            alphabet[chr-'a']++;
        }
        // output
        int count = 0;
        for (int& freq : alphabet){
            if (freq <= 2) count += freq;
            else
                count += (freq % 2 == 0 ? 2 : 1);
        }
        return count;
    }
};