class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());

        // Store the sieve array.
        vector<int> sieve(maxElement + 1, 1);
        sieve[1] = 0;
        for (int i = 2; i <= sqrt(maxElement + 1); i++) {
            if (sieve[i] == 1) {
                for (int j = i * i; j <= maxElement; j += i) {
                    sieve[j] = 0;
                }
            }
        }

        int cur = 1;
        int i = 0;
        while (i < nums.size()){
            int diff = nums[i] - cur;
            if (diff < 0) return false;
            if (sieve[diff] == 1 or diff == 0){
                i++;
                cur++;
            }
            else{
                cur++;
            }
        }
        return 1;
    }
};


// class Solution {
// public:
//     bool primeSubOperation(vector<int>& nums) {
//         // make all smaller [i] < [i+1]
//         // nums[i] - p
        
//         // create prime numbers, 2,3,5,7,11,13
//         vector<bool> primes(1001, true);
//         primes[1] = false;
//         for (int i=2; i*i<1001; i++){
//             if (primes[i] == false) continue;
//             for (int j=i*i; j<1001; j+=i){
//                 primes[j] = false;
//             }
//         }
//         // print primes
//         // for (int i=0; i<primes.size(); i++) cout << primes[i] << " ";
//         // get primes
//         vector<int> primes_arr;
//         for (int i=0; i<primes.size(); i++){
//             if (primes[i]) primes_arr.push_back(i);
//         }
//         // for (int i=0; i<primes_arr.size(); i++) cout << primes_arr[i] << " ";
//         // for each one, nums[i-1] < (nums[i] - p)
//         // cout << endl << lower_bound(primes_arr.begin(), primes_arr.end(), nums[0]) << endl;
//         // cout << endl << *lower_bound(primes_arr.begin(), primes_arr.end(), nums[0]) << endl;
//         // cout << endl << primes_arr[*lower_bound(primes_arr.begin(), primes_arr.end(), nums[0])] << endl;
//         // nums[0] = nums[0] - primes_arr[*lower_bound(primes_arr.begin(), primes_arr.end(), nums[0])];
//         for (int i=1; i<nums.size(); i++){
//             auto it = lower_bound(primes_arr.begin(), primes_arr.end(), nums[i]);
//             while(it != primes_arr.begin() && nums[i] - *(it - 1) > (i > 0 ? nums[i-1] : 0)){
//                 it--;
//             }
//             if (it != primes_arr.end() && nums[i] - *it > (i > 0 ? nums[i-1] : 0)){
//                 nums[i] -= *it;
//             }
//             if (i > 0 && nums[i] <= nums[i-1]) return false;
//             // // get the smallest for each 
//             // int x = *lower_bound(primes_arr.begin(), primes_arr.end(), nums[i]);
//             // cout << x << " " << primes_arr[x] << endl;
//             // while (nums[i-1] >= nums[i] - primes_arr[x]){
//             //     x++;
//             // }
//         }
//         // for (int i=0; i<nums.size(); i++) cout << nums[i] << " " ;
//         // for (int i=1; i<nums.size(); i++){
//         //     if (nums[i-1] >= nums[i]){
//         //         return false;
//         //     }
//         // }
//         return true;
//     }
// };