class Solution {
public:
    bool canChange(string start, string target) {
        pair<int, int> count1 = counter(start);
        pair<int, int> count2 = counter(target);
        // cout << count1.first << " " << count1.second << endl;
        // cout << count2.first << " " << count2.second << endl;
        if (count1 != count2){
            return false;
        }
        int p1 = 0, p2 = 0;
        while (p1 <start.size() && p2 < target.size()){
            skip(start, p1);
            skip(target, p2);
            // diff chars 
            if (start[p1] != target[p2]){
                return false;
            }
            // false, R
            // if L
            else if ((start[p1] == 'R' && p1 > p2) || (start[p1] == 'L' && p2 > p1)){
                return false;
            }
            // otherwise its the same 
            else{
                p1++;
                p2++;
            }
        }
        return true;
    }

private:
    void skip(string& s, int& idx){
        while(idx < s.size() && s[idx] == '_'){
            idx++;
        }
    }

    pair<int, int> counter(string s){
        pair<int, int> ans;
        for (char& c : s){
            if (c == 'L'){
                ans.first++;
            } 
            else if (c == 'R') ans.second++;
        }
        return ans;
    }
};