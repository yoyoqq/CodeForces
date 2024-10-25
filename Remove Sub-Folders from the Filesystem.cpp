class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        res.push_back(folder[0]);
        for (int i=1; i<folder.size(); i++){
            // get last folder
            string last = res.back();
            // check if the same as cur folder 
            // last == cur[:last_size]
            // add 
            cout << last << " " << folder[i].substr(0, last.size()) << endl;
            // if pre diff || contains / 
            if (last != folder[i].substr(0, last.size()) || folder[i][last.size()] != '/'){
                res.push_back(folder[i]);
            }
        }
        return res;
    }
};



// class Trie{
// public:
//     string word; 
//     unordered_set<Trie*> next;
//     bool end;
//     Trie(string w){
//         word = w;
//         end = false;
//     }
// };

// class ListTrie{
// public:
//     unordered_set<Trie*> tries;

//     void add(string& w){
//         // if exists good 

//         // else add 
//     }
// };

// class Solution {
// public:
//     vector<string> removeSubfolders(vector<string>& folder) {
//         // remove subfolders
//         // what is a subfolder /a/b (from /a)
//         // get the parent, children out 
//         ListTrie* root = new ListTrie();
//         ListTrie* dummy = root;
//         for (string& f : folder){
//             vector<string> path = subfolders(f);
//             for (string& p : path){
//                 // append it to the trie 
//                 // if exists 
//                 // else add 
//                 dummy.add(p);
//                 dummy = dummy->next;
//             }
//         }
//         // get res from trie 
//     }

// private:
//     vector<string> subfolders(string& w){
//         vector<string> res;
//         string cur = "";
//         for (int i=1; i<w.size(); i++){
//             char c = w[i];
//             if (c == '/'){
//                 res.push_back(cur);
//                 cur = "";
//             }else{
//                 cur += c;
//             }
//         }
//         return res;
//     }
// };