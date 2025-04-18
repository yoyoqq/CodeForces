class Solution {
    public:
        string countAndSay(int n) {
            if (n == 1) return "1"; 
            return recursion(n, 2, "1");
    
            // iteratively 
            int idx = 2;
            string cur = "1";
            while (idx <= n){
                string next = "";
                char chr = cur[0];
                int chr_count = 1;
                for (int i=1; i<cur.size(); i++){
                    // same 
                    if (cur[i] == chr) chr_count++;
                    // diff 
                    else if (cur[i] != chr){
                        next = next + to_string(chr_count) + chr;
                        chr = cur[i];
                        chr_count = 1;
                    }
                }
                next = next + to_string(chr_count) + chr;
                cur = next;
                idx++;
            }
            return cur;
        }
    
    private:
        string recursion(int& n, int idx, string cur){
            if (idx > n) return cur;
            // children, find count and say
            string next = "";
            char chr = cur[0];
            int chr_count = 1;
            for (int i=1; i<cur.size(); i++){
                // same 
                if (cur[i] == chr) chr_count++;
                // diff 
                else if (cur[i] != chr){
                    next = next + to_string(chr_count) + chr;
                    chr = cur[i];
                    chr_count = 1;
                }
            }
            next = next + to_string(chr_count) + chr;
            // cout << cur << " " << next << endl;
            return recursion(n, idx+1, next);
        }
    };