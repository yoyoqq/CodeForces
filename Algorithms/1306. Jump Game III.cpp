class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> seen(n, false);
        seen[start] = true;
        queue<int> q; 
        q.push(start);
        while (q.size()) {
            int i = q.front(); q.pop();
            // cout << i << " " << arr[i] << endl;
            if (arr[i] == 0) return true;
            int forward = i + arr[i];
            if (forward < n && !seen[forward]) {
                seen[i] = true;
                q.push(i + arr[i]);
            }
            int backward = i - arr[i];
            if (backward >= 0 && !seen[backward]) {
                seen[i] = true;
                q.push(i - arr[i]);
            }
        }
        return false;
    }
};