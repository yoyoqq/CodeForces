class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        int n = word.size();
        int split = n - numFriends + 1;
        // we want as many chars as we want, bigger the better 
        string ans = "";
        for (int i=0; i<n; i++){
            string cur = word.substr(i, split); // can optimize with vector type of queue DS
            // cout << cur << endl;
            ans = get_largest(ans, cur);
        }
        return ans;
        
        // some sort of BF
        // string ans = word;
        // for (int i=0; i<n; i++){
        //     for (int j=i; j<=min(n, i+split); j++){
        //         string cur = word.substr(i, j);
        //         if (cur.size() == 0) continue;
        //         cout << cur << " ";
        //         if (check_smaller(ans, cur)) ans = cur;               
        //     }
        // }
        // return ans;
    }

private:
    string get_largest(string& w1, string& w2){
        // w1 cur, w2 new 
        // return true if w2 is smaller 
        int n = min(w1.size(), w2.size());
        for (int i=0; i<n; i++){
            if (w1[i] == w2[i]) continue;
            else if (w1[i] < w2[i]) return w2;
            else return w1;
        }
        if (w1.size() <= w2.size()) return w2;
        return w1;
    }
};