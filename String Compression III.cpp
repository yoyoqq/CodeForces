class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 0;
        char cur_char = '0';
        for (char& c : word){
            // '0'
            // same char
            // new char 
            // 9 times 
            if (cur_char == '0'){
                cur_char = c;
                count = 1;
                continue;
            }
            // append 
            else if (cur_char == c){
                count++;
            }
            // diff 
            else{
                comp += to_string(count) + cur_char;
                cur_char = c;
                count = 1;
            }
            // base case 
            if (count == 9){
                comp += to_string(count) + cur_char;
                count = 0;
                cur_char = '0';
            }
        }
        if (count != 0) comp += to_string(count) + cur_char;

        return comp;
    }
};