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
int A[200010];

void solve(){
    int n; cin >> n;
    vector<int> a(n, 0);
    for (auto& x : a) cin >> x;
    int res = n;

    // SOLUTION 1 -> use prefix and suffix sum, if sides on i different, we can remove X numbers from either left or right
    // vector<int> pre(n, 0);
    // pre[0] = 1;
    // for (int i=1; i<n; i++){
    //     if (a[i] == a[i-1])
    //         pre[i] = pre[i-1] + 1;
    //     else{
    //         pre[i] = 1;
    //     }
    // }
    // vector<int> suf(n, 0);
    // suf[n-1] = 1;
    // for (int i=n-2; i>=0; i--){
    //     if (a[i] == a[i+1])
    //         suf[i] = suf[i+1] + 1;
    //     else suf[i] = 1;
    // }
    // dbg_out(pre, suf);
    // start from 1 to n - 1

    // start and end always gonna be the same.
    // find the numbers that are diff
    // for (int i=1; i<n-1; i++){
    //     if (a[i-1] == a[i+1] && a[i] != a[i-1])
    //         res = min(res, min(pre[i-1], suf[i+1]));
    // }
    // dbg_out(res);


    // SOLUTION 2 -> using the last record to get the positions to delete. first and last do not change, use this idea to find the values on middle and check if diff
    int last = -1;
    for (int i=0; i<n; i++){
        if (a[0] != a[i]){
            res = min(res, i - last - 1); // update with the last record 
            last = i;
        }
    }

    // OUTPUT 
    res = min(res, n - last - 1);
    if (res != n){
        cout << res << nl;
    }else{
        cout << -1 << nl;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 1e9; cin >> test;
    while (test--) solve();
    return 0;
}

/*



*/