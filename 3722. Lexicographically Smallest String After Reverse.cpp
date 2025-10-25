class Solution {
public:

    string rev(string left, string right, bool front){
        // reverse the front
        if (front){
            reverse(left.begin(), left.end());
            return left + right;
        }else{
            reverse(right.begin(), right.end());
            return left + right;
        }
        return "";
    }

    string lexSmallest(string s) {
        string ans = s;
        int n = s.size();
        // reverse front/back 
        for (int i=0; i<n; i++){
            string left = s.substr(0, i);
            string right = s.substr(i, n);
            // front 
            string front = rev(left, right, true);
            string back = rev(left, right, false);
            if (front < ans) ans = front;
            if (back < ans) ans = back; 
        }
        return ans;
    }
};