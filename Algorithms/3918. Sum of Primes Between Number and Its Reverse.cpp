class Solution {
public:
    int sz;
    vector<bool> primes; 

    Solution() : sz(1500), primes(sz, true) {}

    void sieve() {
        primes[0] = false;
        primes[1] = false;
        for (int i=2; i*i<sz; i++) {
            if (primes[i]) {
                for (int j=i*i; j<sz; j+=i) {
                    primes[j] = false;
                }
            }
        }
    }

    int reverse_int(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stoi(s); 
    }

    int sumOfPrimesInRange(int n) {
        sieve();
        int r = reverse_int(n);
        int mn = min(n, r);
        int mx = max(n, r);

        int ans = 0;
        for (int i=mn; i<=mx; i++) {
            if (primes[i]) ans += i;
        }
        return ans;
    }
};