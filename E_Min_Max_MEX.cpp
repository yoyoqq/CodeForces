#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


void solve(){
    // bin serach if the MEX()
    int n, k; cin >> n >> k;
    vector<int> a(n); for(int& x : a) cin >> x;


    int left = 0, right = n; 
    int ans = 0;
    while (left <= right){
        int mid = left + (right - left) / 2;
        // count MEX reach mid 
        int subarrays = 0;
        set<int> mex;
        for (int i=0; i<n; i++){
            // only push values that are 0 to mid 
            if (a[i] < mid) mex.insert(a[i]);
            // if we found the a mex of size mid 
            if (mex.size() == mid){
                mex.clear();
                subarrays++;
            }
        }
        // if we can do the subarray
        if (subarrays >= k){
            ans = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 0; cin >> test;
    while (test--) solve();
    return 0;
}
