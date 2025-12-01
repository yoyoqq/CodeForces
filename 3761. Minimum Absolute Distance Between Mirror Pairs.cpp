// ! optimzed solution 

class Solution {
public:

    int rev(int num){
        int val = 0;
        while (num){
            val *= 10;
            val += num % 10;
            num /= 10;
        }
        return val;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp; 
        // check the min 
        int ans = n;
        for (int i=0; i<n; i++){
            if (mp.count(nums[i])){
                ans = min(ans, i-mp[nums[i]]);
            }
            mp[rev(nums[i])] = i;
        }
        return (ans == n ? -1 : ans);
    }
};



// ! fisrt solution
class Solution {
public:

    int rev(int num){
        // string s = to_string(num);
        // reverse(s.begin(), s.end());
        // return stoi(s);
        int val = 0;
        while (num){
            val *= 10;
            val += num % 10;
            num /= 10;
        }
        return val;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        // add to map 
        map<int, queue<int>> mp; 
        for (int i=0; i<n; i++){
            // int s = rev(nums[i]);
            mp[nums[i]].push(i);
            // cout << s << " " << mp[s].front() << endl;
        }
        // check the min 
        int ans = n;
        for (int i=0; i<n; i++){
            // pop the front as the front one is nums[i]
            int s = rev(nums[i]);
            // cout << i << " " << s << " " << mp[s].size() << endl;
            while (mp[s].size() && mp[s].front() <= i){
                mp[s].pop();
            }
            // find the min 
            if (mp[s].size() != 0){
                ans = min(ans, mp[s].front()-i);
            }
        }
        return (ans == n ? -1 : ans);
    }
};