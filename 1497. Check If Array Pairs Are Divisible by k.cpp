class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // count items and check (similar to 2 sum)
        unordered_map<int, int> count;
        for (int a : arr){
            // find the other pair with same remainder 
            int rem = (a % k + k) % k;
            count[rem]++;
        }
        // check if it exists 
        for (auto& [rem, freq] : count){
            // must be even count as cant pair with anything else
            if (rem == 0){
                if (freq % 2 != 0) return false;
            }else{
                int com = k - rem;      // check the freq of mod in the map
                if (count[com] != freq) return false;
            }
        }
        return true;
    }
};


// class Solution {
// public:
//     bool canArrange(vector<int>& arr, int k) {
//         int n = arr.size();
//         if (n % 2 == 1) return false;
//         // how to find the pairs, put into hashmap, find by formula
//         // b = x * k - a
//         // n1 = next_multiple * k - n2  
//         map<int, int> count;
//         int mx = 0;
//         int mn = 1e9;
//         for (int& a : arr){
//             count[a]++;
//         }

//         // find if possible, the pairs should be multiples of k 
//         for (auto it = count.begin(); it != count.end(); it++){
//             int a = it->first;
//             // int remainder = a % k;
//             int remainder = (a % k + k) % k;
//             int val_needed = remainder;
//             int multiple = 1;
//             // to find next multiple of k from n
//             // (a + b) / k = x
//             // search for b in map till greater than a 
//             while (count.find(val_needed) != count.end()) {
//                 val_needed = remainder + k * multiple;
//                 multiple++;
//                 if (val_needed > a) return false; 
//             }
//             // erase from map both values
//             count[val_needed]--;
//             count[a]--;
//             // if 0 erase()
//             if (count[val_needed] == 0) count.erase(val_needed);
//             if (count[a] == 0) count.erase(a);
//         }   
//         return true;
//     }
// };