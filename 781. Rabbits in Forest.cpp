class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            // where each num is one color 
            // we join them as find -> min
            // num + 1          RETURN AMOUTN OF RABBITS 
            map<int, int> freq;
            int count = 0;
            for (int& num : answers){
                if (num == 0) count++;  // the color is unique 
                else{
                    int color = num+1;
                    freq[color]++;
                    if (freq[color] == color){
                        freq[color] = 0;
                        count += color;
                    }
                }
            } 
            for (auto [k, v] : freq){
                if (v != 0) count += k;
            }
            return count;
        }
    };