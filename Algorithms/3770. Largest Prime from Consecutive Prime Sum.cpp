#define ll long long 

class Solution {
public:

    vector<int> get_primes(){
        int n = 1e4;
        vector<int> is_prime(n, 1);
        for (int i=2; i<n/2+1; i++){
            // is prime already 
            if (is_prime[i] == 0) continue;
            for (int j=i*i; j<n; j+=i){
                is_prime[j] = 0;
            }
        }
        // get actual primes 
        vector<int> ans;
        for (int i=2; i<is_prime.size(); i++){
            if (is_prime[i]) ans.push_back(i);
        }
        return ans;
    }

    bool is_prime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i* i <=n; i++)
            if (n % i == 0)  
                return false;
        return true;
    }

    int largestPrime(int n) {
        if (n == 1) return 0;
        vector<int> primes = get_primes(); 
        // cout << primes.size() << endl;
        // cout << accumulate(primes.begin(), primes.end(), 0LL) << endl;
        // for (int i=0; i<20; i++){
        //     cout << i << " " << primes[i] << endl;
        // }

        // build prefix 
        vector<ll> pref;
        for (int i=0; i<primes.size(); i++){
            if (i == 0) pref.push_back(primes[i]);
            else pref.push_back(pref[i-1] + primes[i]);
        }
        // cout << pref.size() << endl;

        // check if its prime or not 
        vector<int> ans;
        for (int num : pref){
            if (is_prime(num)) {
                ans.push_back(num);
            }
        }

        // for (int num : ans) cout << num << endl;
        
        
        
        // for (int i=0; i<20; i++){
        //     cout << i << " " << pref[i] << endl;
        // }
        
        // binary search 
        int idx = lower_bound(ans.begin(), ans.end(), n) - ans.begin();
        if (ans[idx] != n) idx--; 
        
        return ans[idx];
    }
};