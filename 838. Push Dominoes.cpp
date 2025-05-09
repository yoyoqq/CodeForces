class Solution {
    public:
        string pushDominoes(string d) {
            d = 'L' + d + 'R';
            string res = "";
            for (int i=0, j=1; j<d.size(); j++){
                if (d[j] == '.') continue;
                int middle = j - i - 1;
                // append left value 
                if (i > 0){
                    res += d[i];
                }
                // append right value 
                if (d[i] == d[j]) 
                    res += string(middle, d[i]);
                else if (d[i] == 'L' && d[j] == 'R')
                    res += string(middle, '.');
                else
                    res += string(middle / 2, 'R') + string(middle % 2, '.') + string(middle / 2, 'L');
                i = j;
            }
            return res;
        }
    };