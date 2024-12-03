class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        stringstream ans;
        int spaces_idx = 0;
        for (int i=0; i<s.size(); i++){
            if (spaces_idx < spaces.size() && spaces[spaces_idx] == i){
                ans << " ";
                spaces_idx++;
            }
            ans << s[i];
        }
        return ans.str();
    }
};