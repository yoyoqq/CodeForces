class Solution {
    public:
        int numberOfSubstrings(string s) {
            int count = 0;
            int left = 0;
            map<char, int> freq;
            for(int right=0; right<s.size(); right++){
                freq[s[right]]++;
                // count 
                while (freq.size() == 3){
                    count += (s.size() - right);
                    freq[s[left]]--;
                    if (freq[s[left]] == 0) freq.erase(s[left]);
                    left++;
                }
            }
            return count;
        }
    };