class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // convert to its sum 
        // 22 14 33 7
        // 4 5 6 7 
        int n = nums.size();
        // vector<pair<int, int>> a(n);    // sum_digits, num
        vector<vector<int>> a(n);
        for (int i=0; i<n; i++){
            a[i] = {sum_digits(nums[i]), nums[i], i};
        }
        sort(a.begin(), a.end());
        vector<int> b(n);
        for (int i=0; i<n; i++) b[i] = a[i][1];

        // minimum swaps to sort array 
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i=0; i<n; i++){
            // if visited or in place 
            if (visited[i] || a[i][2] == i) continue;   
            int j = i;
            int cycle_size = 0;
            while(!visited[j]){
                visited[j] = true;
                j = a[j][2];    // make the jump 
                cycle_size++;
            }
            if (cycle_size > 0) swaps += (cycle_size - 1);
        }
        return swaps;

        // DOESNT WORK IF REPEATED ELELMENTS
        // map<int, int> pos;
        // for (int i=0; i<n; i++) pos[b[i]] = i;
        // int swaps = 0;
        // for (int i=0; i<n; i++){
        //     if (b[i] != nums[i]){
        //         // swap 
        //         int idx = pos[nums[i]];
        //         swap(nums[idx], nums[i]);
        //         // update map
        //         pos[nums[idx]] = idx;
        //         pos[nums[i]] = i;
        //         // count 
        //         swaps++;
        //     }
        // }
        // return swaps;
        
        // sort also sorts by the second 
        // for (auto num : a) cout << num[0] << " " << num[1] << " " << num[2] << endl; cout << endl;
        // n - number_of_cycles 
        // int count = n;
        // for (int i=0; i<n; i++){
        //     if (a[i][1] == nums[a[i][2]]) count--;
        // }
        // return count;
    }

    int sum_digits(int num){
        int count = 0;
        while (num){
            count += num % 10;
            num /= 10;
        }
        return count;
    }
};