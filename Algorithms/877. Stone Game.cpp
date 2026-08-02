class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int dp[n+2][n+2];
        memset(dp, 0, sizeof(dp));

        for (int size = 1; size <= n; size++) {
            for (int i = 0, j = size - 1; j < n; i++, j++) {
                int parity = (j + i + n) % 2; 
                if (parity == 1) 
                    dp[i+1][j+1] = max(piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j]);
                else
                    dp[i+1][j+1] = min(-piles[i] + dp[i+2][j+1], -piles[j] + dp[i+1][j]); 
            }
        }
        return dp[1][n] > 0;
    }
};

// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
//         return true;
//     }
// };


// class Solution {
// public:
//     void give_to(int& i, int& alice, int& bob, int& pile) {
//         // alice
//         if (i % 2 == 0) {
//             alice += pile;
//             cout << "ALICE " << pile << endl;
//         }
//         // bob
//         else {
//             bob += pile;
//             cout << "BOB " << pile << endl;
//         }
//     }


//     bool stoneGame(vector<int>& piles) {
//         // does greedy work ? 
//         // need to look +2 steps ? 
//         int n = piles.size();
//         int left = 0, right = n - 1;
//         int alice = 0, bob = 0;
//         for (int i = 0; i < n - 1; i++) {
//             int l = piles[left] + piles[left+1];
//             int r = piles[right] - piles[right-1];
//             // take the smalleset count 
//             if (l < r) {
//                 give_to(i, alice, bob, piles[left]);
//                 left++;
//             } else {
//                 give_to(i, alice, bob, piles[right]);
//                 right--;
//             }
//         }
//         bob += piles[left];
//         return alice >= bob;
//     }
// };