#define ll long long;

class Solution {
public:
    long long coloredCells(int n) {
        // lenght = n * 2 - 1
        long long ans = 0;
        for (int i=1; i<=n; i++){
            ans += (i * 2 - 1);
        }
        return ans * 2 - (n*2-1);
        
        
        // // there are total of 4 sides 
        // long long side = n * (n+1) / 2;
        // // take off repeated mid section 
        // long long line = (n + (n-1)); 
        // long long mid = line + line - 1;
        // cout << side << " " << line << " " << mid << endl;
        // return side * 4 - mid;
    }
};