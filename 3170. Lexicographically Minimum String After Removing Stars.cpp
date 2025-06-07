// class Solution {
// public:
//     string clearStars(string s) {
//         // pq to get smallest -> char, idx
//         priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
//         for (int i=0; i<s.size(); i++){
//             char c = s[i];
//             if (c == '*'){
//                 if (pq.size()){
//                     s[pq.top().second] = '*';
//                     pq.pop();
//                 }
//             }else{
//                 pq.push({c, i});
//             }
//         }

//         string res = "";
//         for (char c : s){
//             if (c != '*') res += c;
//         }
//         return res;
//     }
// };

class Solution {
public:
    string clearStars(string s) {
        // delete the smallest char to its left 
        vector<vector<int>> freq(26);
        for (int i=0; i<s.size(); i++){
            // delete smallest char 
            if (s[i] == '*'){
                char chr = 'z'+1;
                int idx = -1;
                for (int i=0; i<26; i++){
                    char k = 'a'+i;
                    vector<int>& v = freq[i];
                    if (v.size() != 0 && chr > k){
                        chr = k;
                        idx = v.back();
                    }
                    if (idx != -1) break;
                }
                if (idx != -1){
                    s[idx] = '*';
                    freq[chr-'a'].pop_back();
                }
            }
            else{
                freq[s[i]-'a'].push_back(i);
            }
        }
        string res = "";
        for (char c : s){
            if (c != '*') res += c;
        }
        return res;
    }
};