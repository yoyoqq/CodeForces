class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // put in 
        bool a[1000000] = {false};
        for (int& n : nums){
            a[n] = true;
        }
        // count and chec k
        int max_length = 0;
        for (int i=2; i<317; i++){
            if (a[i] == 0) continue;
            // check max 
            int count = 0;
            long long cur = i;
            while (cur < 1000000 && a[cur]){
                a[cur] = false;
                count++;
                cur = cur * cur;
            }
            max_length = max(max_length, count);
        }
        return (max_length <= 1 ? -1 : max_length);
        
        // // point to the prev 
        // map<int, int> m;
        // for (int& n : nums){
        //     int sq = sqrt(n);
        //     m[n] = (sq * sq == n) ? sq : 1;
        // }
        // // from nums to 
        // int length = 0;
        // for (auto it=m.rbegin(); it!=m.rend(); it++){
        //     // cur and pop the rest smallest till 1
        //     int count = 1;
        //     auto cur = it;
        //     while (cur->second != 1){
        //         auto temp = cur;
        //         m.erase(cur.base());
        //         cur = temp->second;
        //         count++;
        //     }
        //     length = max(length, count);
        // }
        // return length;
    }
};