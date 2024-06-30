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
    // simulate the process 
    // optimzie by adding more than 1 -> min(k, x/y * y - x)
    ll x, y, k; cin >> x >> y >> k;
    while (k > 0 && x != 1){
        ll ost = (x / y + 1) * y - x;
        ost = max(1ll, ost);
        ost = min(ost, k);
        x += ost;
        while (x % y == 0){
            x /= y;
        }
        k -= ost;
    }
    cout << x + k % (y - 1) << nl;

    
    
    // // 
    // // increase to the last multiple using k steps 
    // // while we have k
    // // add to x 

    // // put to the next remainder 
    // int to_mod = y - (x % y);
    // // not possible, use brute force 
    // if (to_mod > k){
    //     int op = x / y + k;
    //     if (op % y == 0) op = op / y;
    //     cout << op << nl;
    //     return;
    // }

    // // otherwise, use to_mod and then remeaidner 
    // x += to_mod; 
    // k -= to_mod;
    // int op = x / y + k;
    // if (op % y == 0) op = op / y;
    // cout << op << nl; 
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