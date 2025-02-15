class Solution {
    public:
        int punishmentNumber(int n) {
            // precompute 
            int punishment = 0;
            for (int i=1; i<=n; i++){
                if (punished(i, i*i, 0)){
                    punishment += i * i;
                }
            }
            return punishment;
        }
    
    private:
        bool punished(int& i, int cur, int sum){
            // cout << i << "  "<< cur << " " << sum << endl;
            // base case 
            if (cur == 0){
                if (sum == i) return true;
                return false;
            }
            bool poss = false;
            int num = cur;
            int power = 1;
    
            while (num > 0){
                int left = cur / (10*power);
                int right = cur % (10*power);
    
                poss |= punished(i, left, sum+right);
    
                power *= 10;
                num /= 10;
            }
            
            return poss;
        }
    
    
        // bool punished(int& i, int cur, int sum){
        //     // cout << i << "  "<< cur << " " << sum << endl;
        //     // base case 
        //     if (cur == 0){
        //         if (sum == i) return true;
        //         return false;
        //     }
        //     bool poss = false;
        //     // children
        //     // idea: everytime we divide by 10 
        //     string cur_str = to_string(cur);
        //     for (int j=1; j<=cur_str.size(); j++){
        //         // int next_sum = sum + cur % (j*10);
        //         // int next_cur = cur / (j*10);
        //         int next_sum = sum + stoi(cur_str.substr(0, j));
        //         string next_cur_str = cur_str.substr(j);
        //         int next_cur = next_cur_str.empty() ? 0 : stoi(next_cur_str);
        //         poss |= punished(i, next_cur, next_sum);
        //     }
        //     return poss;
        // }
    };