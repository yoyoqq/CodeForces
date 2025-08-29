class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;

        for (int x=1; x<=n; x++){
            long long count;
            if (x % 2 == 0){
                // count odd from 1 to m
                count = m/2 + m%2;
            }
            else{
                count = m/2;
            }
            ans += count;
        }
        return ans;   
    }
};

// class Solution {
// public:
//     long long flowerGame(int n, int m) {
//         long long ans = 0;

//         for (int x=1; x<=n; x++){
//             int y;
//             if (x % 2 == 0){
//                 // count odd nums
//                 y = (m/2 + m%2==1);
//             }
//             else{
//                 // count even nums 
//                 y = (m/2);
//             }
//             ans += y;
//             cout << x << " " << y << endl;
//         }
//         cout << endl;
//         for (int y=1; y<=m; y++){
//             int x;
//             if (y % 2 == 0){
//                 // count odd nums
//                 x = (n/2 + n%2==1);
//             }
//             else{
//                 // count even nums 
//                 x = (n/2);
//             }
//             ans += x;
//             cout << x << " " << y << endl;
//         }
//         return ans;
//     }
// };
