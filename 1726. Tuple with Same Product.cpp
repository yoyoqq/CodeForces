class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // if the nums are diff, multiplications are diff 
        map<int, int> freq;
        int n = nums.size();
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                freq[nums[i] * nums[j]]++;
            }
        }
        int count = 0;
        for (auto [k, v] : freq){
            if (v >= 2){
                count += (v*(v-1)/2) * 8;   // num of pairs * 8 num of ways to organize  
            }
        }
        return count;
    }
};


// class Solution {
// public:
//     int tupleSameProduct(vector<int>& nums) {
//         int count = 0;
//         int n = nums.size();
//         set<int> have;
//         for (int i=0; i<n; i++){
//             have.insert(nums[i]);
//         }
//         // find ab = cd
//         for (int a=0; a<n; a++){
//             for (int b=a+1; b<n; b++){
//                 for (int c=0; c<n; c++){
//                     if (c == a || c == b) continue;
//                     // cout << nums[a] * nums[b] / nums[c] << endl;
//                     int d = nums[a] * nums[b] / nums[c];
//                     if ((nums[a] * nums[b] % nums[c]) == 0 && !(nums[a] == d || nums[b] == d || nums[c] == d) && have.find(nums[a]*nums[b]/nums[c]) != have.end()){
//                         // cout << nums[a] << " " << nums[b] << " " << nums[c] << " " << nums[a] * nums[b] / nums[c] << endl; 
//                         count += 2;
//                     }
//                 }
//             }
//         }

//         return count;
//     }
// };