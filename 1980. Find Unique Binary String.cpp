class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            // convert nums to set int 
            set<int> seen;
            for (int i=0; i<nums.size(); i++){
                seen.insert(stoi(nums[i], nullptr, 2));
            }
            // from 1++, till not found 
            int num = 0;
            while (seen.find(num) != seen.end()){
                num++;
            }
            // convert num to string 
            int n = nums.size(); 
            string ans = to_binary(num);
            return string(n-ans.size(), '0') + ans;
        }
    
    private:
        string to_binary(int num){
            string ans = "";
            while (num){
                ans =  (num%2 == 0 ? '0' : '1') + ans;
                num /= 2;            
            }
            return ans;
        }
    };