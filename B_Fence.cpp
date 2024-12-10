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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    // 
    // prefix 
    vector<int> pref(n, 0);
    pref[0] = a[0];
    for (int i=1; i<n; i++){
        pref[i] = pref[i-1] + a[i];
    }
    // dbg_out(pref);
    // find idx 
    int idx = -1; 
    int minimum = pref[k-1];
    for (int i=k; i<n; i++){
        // dbg_out(idx, minimum);
        // update if min
        if (minimum > pref[i] - pref[i-k]){
            idx = i - k;
            minimum = pref[i] - pref[i-k];
        }
    }
    cout << idx + 2 << endl;
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // int test = 1e9; cin >> test;
    solve();
    // while (test--) solve();
    return 0;
}

/*



*/