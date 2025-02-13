#define ll long long 

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // take smallest 
        // at the end -> all >= k
        priority_queue<ll, vector<ll>, greater<ll>> pq(nums.begin(), nums.end());
        int count = 0;
        while (pq.size() >= 2 && pq.top() < k){
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            pq.push(min(x,y)*2+max(x,y));
            count++;
        }
        return count;
    }
};