class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while (n){
                if (n % 3 == 2) return false;
                n /= 3;
            }
            return true;
            
            
            // set<int> seen;
            // while (n){
            //     int power = find(n);
            //     // cout << power << " ";
            //     if (seen.find(power) != seen.end()){
            //         return false;
            //     }
            //     n -= (int)pow(3, power);
            //     seen.insert(power);
            // } 
            // return true;
        }
    
    private:
        int find(int n){
            if (n == 1) return 0;
            int times = 1; 
            int cur = 3;
            while (cur * 3 <= n){
                cur *= 3; 
                times++;
            }
            return times;
        }
    };