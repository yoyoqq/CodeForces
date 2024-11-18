class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res;
        // brute force
        int x;
        for (int i=0; i<n; i++){
            // positive
            int sm = 0;
            for (int j=0; j<abs(k); j++){
                if (k >= 0){
                    x = (i + 1 + j) % n;
                }else{
                    x = (i - 1 - j + n) % n;
                }
                sm += code[x];
            }
            res.push_back(sm);
        }
        return res;
    }
};