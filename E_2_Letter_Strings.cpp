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
    map<int, vector<int>> l;
    map<int, vector<int>> r;
    string s;
    int lchr, rchr;
    for (int i=0; i<n; i++){
        cin >> s; lchr = s[0]-'a'; rchr = s[1]-'a';
        if (l.find(lchr) == l.end())
            l[lchr] = vector<int>(26, 0);  // Initialize vector with 26 zeros
        if (r.find(rchr) == r.end()) 
            r[rchr] = vector<int>(26, 0);  // Initialize vector with 26 zeros
        
        l[lchr][rchr]++;
        r[rchr][lchr]++;
    }
    // dbg_out(l, r);
    // dbg_out();
    // for each map, iterate the char, if it is more thatn one char mutiply 
    ll res = 0;

    for (const auto& [k, vv] : l) {
        ll total = 0;
        for (int count : vv) {
            total += count;
        }
        for (int count : vv) {
            if (count > 0) {
                // how many pairs multiply 
                res += count * (total - count);
            }
        }
    }

    for (const auto& [k, vv] : r) {
        ll total = 0;
        for (int count : vv) {
            total += count;
        }
        for (int count : vv) {
            if (count > 0) {
                res += count * (total - count);
            }
        }
    }
    cout << res / 2 << nl;
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