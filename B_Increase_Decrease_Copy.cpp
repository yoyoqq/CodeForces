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
    vector<ll> a(n), b(n+1);
    for (ll& x : a) cin >> x;
    for (ll& x : b) cin >> x;
    // dbg_out(a, b);
    // diff between them 
    ll count = 0;
    ll ext = INT_MAX;
    for (int i=0; i<n; i++){
        count += abs(a[i] - b[i]);
        // for last digit if in between
        // if ((a[i] <= b[n] && b[n] <= b[i]) || (a[i] >= b[n] && b[i] >= b[n])){
        ext = min(ext, abs(a[i] - b[n]));
        ext = min(ext, abs(b[i] - b[n]));
        if (min(a[i], b[i]) <= b[n] && b[n] <= max(a[i], b[i])){
            ext = 0;
        }
    }
    // dbg_out(count, ext);
    cout << count + ext + 1 << endl;
    
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