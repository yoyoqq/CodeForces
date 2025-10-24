class Solution {
public:

    void get_nums(vector<vector<int>>& output, vector<int>& cur, int& count, string& num){
        // base case 
        int n = num.size();
        if (count == n){
            output.push_back(cur);
        }
        if (count == n+1){
            output.push_back(cur);
            return;
        }
        if (count > n) return;
        // children 
        for (int i=1; i<=9; i++){
            if (cur[i] != 0) continue;
            count += i;
            cur[i] += i;
            get_nums(output, cur, count, num);
            count -= i;
            cur[i] -= i;
        }
    }

    bool is_empty(vector<int>& combinations){
        for (int& x : combinations) if (x != 0) return false;
        return true;
    }
    
    void try_all_combinations(int& ans, vector<int>& combinations, int& cur, int& N){
        if (is_empty(combinations)){
            if (N < cur)
                ans = min(ans, cur);
            return;
        }
        for (int i=0; i<combinations.size(); i++){
            if (combinations[i]){
                combinations[i]--;
                cur = cur * 10 + i;
                try_all_combinations(ans, combinations, cur, N);
                cur /= 10;
                combinations[i]++;
            }
        }
    }

    int nextBeautifulNumber(int number) {
        /*
        1. numbers to use 
            1 -> 1 
            2 -> 2... 

        2. in any order 
            either n || n + 1 

            1000000

        3. all combinations till get min 
        */
        string num = to_string(number);
        int n = num.size();

        // 1. get all from n | n + 1
        vector<vector<int>> combinations;
        int count = 0;
        vector<int> cur(10, 0);
        get_nums(combinations, cur, count, num);
        


        // 2. get minimum by trying all the combinations 
        int ans = 1e9; 
        count = 0;
        for (int i=0; i<combinations.size(); i++){
            // for (int x : combinations[i]) cout << x << " ";cout << endl;
            try_all_combinations(ans, combinations[i], count, number);
        }
        return ans;

    }
};