class Solution {
private:
    const long long MOD = 1e9 + 7;
    
    long long factorial(int n) {
        long long ans = 1;
        while (n) {
            ans = (ans * n) % MOD;
            n--;
        }
        return ans;
    }
    
    long long modInverse(long long a, long long MOD) {
        long long result = 1, power = MOD - 2;
        while (power > 0) {
            if (power % 2 == 1) result = (result * a) % MOD;
            a = (a * a) % MOD;
            power /= 2;
        }
        return result;
    }

    long long count(string word, vector<int>& chars) {
        long long bottom = 1, sum = 0;
        for (int& c : chars) {
            if (c > 0) bottom = (bottom * factorial(c)) % MOD;
            sum += c;
        }
        long long top = factorial(sum);
        return (top * modInverse(bottom, MOD)) % MOD;
    }

    void clear(vector<int>& chars) {
        fill(chars.begin(), chars.end(), 0);
    }
    
public:
    int countAnagrams(string s) {
        s += " ";
        vector<int> chars(26, 0);
        string word = "";
        long long ans = 1;
        for (char& c : s) {
            if (c == ' ') {
                ans = (ans * count(word, chars)) % MOD;
                clear(chars);
                word = "";
            } else {
                word += c;
                chars[c - 'a']++;
            }
        }
        return (int)ans;
    }
};
