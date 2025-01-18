class Solution {
public:
    int minOperations(int n, int m) {
        vector<bool> isPrime = sieve(1e5+5);
        if (isPrime[n] || isPrime[m]) return -1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<int> visited; visited.insert(n);
        pq.push({n, n});
        

        while (!pq.empty()) {
            int cost = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            // If we've reached the target, return the total cost
            if (curr == m) return cost;

            string currStr = to_string(curr);

            for (int i = 0; i < currStr.size(); i++) {
                int digit = currStr[i] - '0';

                // Increment the digit if it's less than 9
                if (digit < 9) {
                    string nextStr = currStr;
                    nextStr[i] = currStr[i] + 1;
                    int nextNum = stoi(nextStr);
                    if (visited.find(nextNum) == visited.end() && !isPrime[nextNum]) {
                        pq.push({cost + nextNum, nextNum});
                        visited.insert(nextNum);
                    }
                }

                // Decrement the digit if it's greater than 0
                if (digit > 0) {
                    string nextStr = currStr;
                    nextStr[i] = currStr[i] - 1;
                    // Ensure no leading zeros in the transformed number
                    if (nextStr[0] != '0') {
                        int nextNum = stoi(nextStr);
                        if (visited.find(nextNum) == visited.end() && !isPrime[nextNum]) {
                            pq.push({cost + nextNum, nextNum});
                            visited.insert(nextNum);
                        }
                    }
                }
            }
        }
        return -1;
    }

private:
    vector<bool> sieve(int size) {
        vector<bool> primes(size + 1, true);
        primes[0] = primes[1] = false;
        for (int p = 2; p * p <= size; p++) {
            if (primes[p]) {
                for (int i = p * p; i <= size; i += p) {
                    primes[i] = false;
                }
            }
        }
        return primes;
    }
};