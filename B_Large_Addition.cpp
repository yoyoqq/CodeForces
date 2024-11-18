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
    ll n; cin >> n;
    n = n - n % 10 + (n % 10 + 1) % 10;
    while (n > 9) {
    if (n % 10 == 0) {
        cout << "NO\n";
        return;
    }
    n /= 10;
    }
    cout << (n == 1 ? "YES\n" : "NO\n");
    
    
    // ll n; cin >> n;
    // int len = 0;
    // ll copy = n;
    // while (copy){
    //     len++;
    //     copy = copy / 10;
    // }
    // // create 5 * len
    // ll lower = 5;
    // for (int i=2; i<len; i++){
    //     lower = lower * 10 + 5; 
    // }
    // // cout << len << " " << lower << endl;
    // dbg_out(n, len, copy, lower);
    // if (n - lower >= lower * 10){
    //     cout << "yes" << nl;
    // }else{
    //     cout << "no" << nl;
    // }
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