class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        // count occurrences 
        map<char, int> m;
        for (char c : s){
            m[c]++;
        }
        if (!good(m, k)) return -1;
        // two pointers 
        int left = 0;
        int minutes = s.size();
        for (int right=0; right<s.size(); right++){
            // delete from
            m[s[right]]--;
            // good?
            // move left 
            if (!good(m, k)){
                while (!good(m, k)){
                    m[s[left]]++;
                    left++;
                }
            }
            // calculate new size
            minutes = min(minutes, static_cast<int>(s.size() - (right - left + 1)));
        }
        return minutes;
    }

bool good(map<char, int>& m, int k){
    if (m.size() != 3) return false;
    for (auto& [_, v] : m){
        if (v < k){
            return false;
        
    }
    return true;
}
};