class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // build prefix 
        // count 
        vector<int> prefA(51, 0);
        vector<int> prefB(51, 0);
        vector<int> res;
        for (int i=0; i<A.size(); i++){
            // add both prefix 
            prefA[A[i]]++;
            prefB[B[i]]++;
            // check 
            int count = 0;
            for (int i=0; i<prefA.size(); i++){
                count += min(prefA[i], prefB[i]);
            }
            res.push_back(count);
        }
        return res;
    }
};