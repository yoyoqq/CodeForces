class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // Just be smarter? 
        // the bigger the int**2 the bigger the number 
        // put 9's 
        string ans = "";
        while (sum){
            // ans += (char(sum % 10)+'0'); 
            int to_put = min(sum, 9);
            ans += (to_put+'0');
            sum -= to_put;
        }
        while (ans.size() < num){
            ans += '0';
        }
        if (ans.size() > num) return "";
        return ans;
    }
};


// class Solution {
// public:
//     // sum of digits, squared 
//     pair<int, int> sum_of_digits(int num){
//         int sum = 0;
//         int sqr = 0;
//         while (num){
//             sum += num % 10;
//             sqr += (num % 10) * (num % 10);
//             num = num / 10;
//         }
//         return {sum, sqr};
//     }
    
//     string maxSumOfSquares(int num, int sum) {
//         // 1. find good integers -> must have X digits 
//         int low = 1, high = 1, ans = 0, cur_int = 0;
//         for (int i=0; i<num-1; i++) low *= 10;
//         for (int i=0; i<num; i++) high *= 10;
//         // 2. sum of digits must be SUM 
//         // 3. get maximum squared 
//         for (int i=low; i<high; i++){
//             auto [sm, sqr] = sum_of_digits(i);
//             // cout << i << " " << sm << " " << sqr << endl;
//             if (sm == sum && cur_int <= sqr){
//                 ans = i;
//                 cur_int = sqr;
//             }
//         }
//         if (ans == 0) return "";
//         return to_string(ans);
//     }
// };