#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// overload cout and return pair<A, B>
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// return generic container (vector, set, list) to output stream 
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// debugging
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// generate random num
#define rng_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng_seed(x) mt19937 rng(x)
// shortcuts
#define all(x) (x).begin(), (x).end()   // sort(all(a))

using ll = long long;
typedef long double ld;
const char nl = '\n';

void solve(){
    // two pointers 
    int n, l, r; cin >> n >> l  >> r;
    vector<int> a(n);
    for(int& x : a) cin >> x; 
    int ans = 0, cur = 0, L = 0, R = 0;
    while (L < n){
        while (R < n && cur < l){
            cur += a[R];
            R++; 
        }
        // in range 
        if (l <= cur && cur <= r){
            ans++;
            L = R;
            cur = 0;
        }else{
            cur -= a[L];
            L++;
        }
    }
    cout << ans << nl;

    // does not work when too big, rather than reset, move leftmost pointer  
    // int n, l, r; cin >> n >> l >> r;
    // vector<int> a(n);
    // for(int& x : a) cin >> x;
    // //
    // int cur = 0, ans = 0;
    // for (int& x : a){
    //     // sum 
    //     cur += x;
    //     // too big 
    //     if (cur > r){
    //         cur = x;
    //     }
    //     // count
    //     if (l <= cur && cur <= r){
    //         cur = 0;
    //         ans++;
    //     }
    //     // dbg_out(cur, x, ans);
    // }
    // cout << ans << nl;    
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

/*



*/