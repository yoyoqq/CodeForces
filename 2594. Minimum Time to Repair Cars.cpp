#define ll long long 

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll left = 1, right = 1LL * cars * cars * ranks[0];
        ll ans = right;
        while (left <= right){
            ll mid = left + (right - left) / 2;
            // cout << left << " " << mid << " " << right << endl;
            // cout << repaired(ranks, mid) << " "<< cars << endl;
            if (repaired(ranks, mid) >= cars){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }

private:
    long long repaired(vector<int>& ranks, long long time){
        ll cars = 0;
        for (auto rank : ranks)
            cars += sqrt(1.0 * time / rank);
        return cars;
    }
};