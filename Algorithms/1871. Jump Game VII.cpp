class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        int r = 0;  // limit to not look backward again 
        queue<int> q;
        q.push(0);
        while (q.size()) { 
            int idx = q.front(); q.pop();
            // base case 
            if (s[idx] == '1') continue;
            if (idx == n-1) return true;        
            // children    
            int left = idx + minJump;
            int right = idx + maxJump;
            for (int i=max(r+1, left); i<min(right+1, n); i++) {
                q.push(i);
            }
            r = right;
        }
        return false;
    }
};