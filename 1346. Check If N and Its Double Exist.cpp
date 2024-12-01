class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // use a set to find the missing value 
        int n = arr.size();
        unordered_set<int> seen;
        for (int i=0; i<n; i++){
            // arr[i] * 2
            int first = arr[i] * 2;
            // arr[i] % 2 == 0 && arr[i] / 2
            int second = (arr[i] % 2 == 0) ? arr[i] / 2 : INT_MIN;
            if (seen.count(first) || seen.count(second)){
                return true;
            }
            seen.insert(arr[i]);
        }
        return false;
        
        // // brute force 
        // int n = arr.size();
        // for (int i=0; i<n; i++){
        //     for (int j=i+1; j<n; j++){
        //         // i = 2 * j
        //         // i * 2 = j
        //         if (arr[i] == 2 * arr[j] || arr[i] * 2 == arr[j]){
        //             return true;
        //         }
        //     }
        // }
        // return false;
    }
};