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
    int n, k; cin >> n >> k;
    vector<int> a(n); for(int& x : a) cin >> x;    
    // int ans = 1e9;
    // for (int& val : a){
    //     ans = min(ans, val % k);
    // }
    // cout << ans << endl;

    int ans = 6;
    for (auto& val : a){
        ans = min(ans, (k-val%k)%k);
        // ans = min(ans, k - (val % k));
    }    
    if (k == 4){
        int even = 0;
        for (int i=0; i<n; i++){
            even += (a[i]%2 == 0);
        }
        ans = min(ans, max(2-even, 0));
    }
    cout << ans << endl;
    
    
    // if (k == 4){
    //     if (2 - even < k-count) ans = 2 - count;
    //     else ans = k - count;
    // }
    // else{
    //     ans = k - count;
    // }
    // cout << ans << endl;
    // if (k == 2){
    //     if (even) ans = 0;
    //     else ans = 1;
    // }
    // else if (k == 3){
    //     if (odd) ans = 0;
    //     else ans = 1;
    // }
    // if (k == 4){
        // if (even >= 2) ans = 0;
        // else ans = 2 - even;
        // ans = max(0, 2 - even);
    //     if (2 <= n) ans = max(0, 2-even);
    //     else if (even >= 2) ans = 0;
    //     else ans = 2-even;
    // }
    // else{
    //     for (int& val : a){
    //         if (val % k == 0){
    //             ans = 0;
    //             break;
    //         }
    //         ans = min(ans, k - (val % k));   
    //     }
    // }
    // cout << ans << endl;

    
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
}120. Triangle