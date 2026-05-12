class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // greedy 
        // 1. sort by waste 
        sort(tasks.begin(), tasks.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return (a[1] - a[0]) > (b[1] - b[0]);
            });
        // 2. calc by jumps 
        int ans = 0;
        int energy = 0;
        for (int i=0; i<tasks.size(); i++) {
            auto t = tasks[i];
            int actual = t[0]; int minimum = t[1];

            if (energy < minimum) {
                ans += minimum - energy;
                energy = minimum;
            }
            energy -= actual;
        }
        return ans;
    }
};


// class Solution {
// public:
//     bool poss(vector<vector<int>>& tasks, int x) {
//         long long energy = x;
//         for (auto& t : tasks) {
//             int actual = t[0]; int minimum = t[1];
//             if (energy < minimum) return false;
//             energy -= actual;
//         }
//         return true;
//     }

//     int minimumEffort(vector<vector<int>>& tasks) {
//         // WAYS ? 
//         // dp + math ? -> iterate tasks O(n), how to prove ...  
//         // binary search ? -> get the mid  n log n  
        
//         // sort by wasted resources 
//         sort(tasks.begin(), tasks.end(),
//             [](const vector<int>& a, const vector<int>& b) {
//                 return (a[1] - a[0]) > (b[1] - b[0]);
//             });

//         // for (auto t : tasks) cout << t[0] << " " << t[1] << endl;

//         int ans = -1;
//         int left = 0;
//         int right = INT_MAX;
//         while (left <= right) {
//             long long mid = (1LL*right + 1LL*left) / 2;
//             cout << left << " " << right << " " << ans << endl;
//             if (poss(tasks, mid)) {
//                 ans = mid;
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }
//         } 
//         return ans;
//     }
// };