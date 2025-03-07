class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<int> primes = get_sieve(right+1);
    
            int diff = 1e9;
            vector<int> ans = {-1, -1};
            for (int i=1; i<primes.size(); i++){
                if (primes[i-1] < left || primes[i] > right) continue;
                if (diff > primes[i] - primes[i-1]){
                    diff = primes[i] - primes[i-1];
                    ans = {primes[i-1], primes[i]};
                }
            }
            return ans;
    
            // for (int i=0; i<primes.size(); i++){
            //     cout << primes[i] << " ";
            // }cout << endl;
            // int i = lower_bound(primes.begin(), primes.end(), left);
            // cout << i << " " << primes[i];
            // i++;
            // int diff = 1e9;
            // vector<int> ans = {-1, -1};
            // cout << i << endl;
            // while (i < primes.size() && primes[i] <= right){
            //     cout << primes [i] << " " << primes[i-1] << endl;
            //     if (primes[i] - primes[i-1] < diff){
            //         ans = {primes[i-1], primes[i]};
            //     }
            //     i++;
            // }
            // return ans;
        }
    
    private:
    
        vector<int> get_sieve(int n) {
            vector<bool> sieve(n + 1, true);
            vector<int> primes;
            sieve[0] = sieve[1] = false;
            for (int i = 2; i <= n; i++) {
                if (sieve[i]) {
                    primes.push_back(i);
                    for (int j = i * 2; j <= n; j += i) {
                        sieve[j] = false;
                    }
                }
            }
            return primes;
        }
    };