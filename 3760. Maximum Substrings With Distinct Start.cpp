class Solution {
public:
    int maxDistinct(string s) {
        set<char> seen;
        for (char& c : s){
            seen.insert(c);
        }
        return seen.size();
    }
};