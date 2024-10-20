class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        string cur = "0";
        while (n--){
            cur = reverse_invert(cur);
            if (cur.size() > k) return cur[k-1];
        }
        cout << cur;
        return cur[k-1];
    }

private: 
    string reverse_invert(string& s){
        string temp = s;
        reverse(temp.begin(), temp.end());
        for (int i=0; i<s.size(); i++){
            temp[i] = (temp[i] == '0') ? '1' : '0';
        }
        return s + '1' + temp;
    }
};
