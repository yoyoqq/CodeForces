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
// #define int long long 

void solve(){
    ll n, x; cin >> n >> x;
    map<ll, ll> m;
    for (int i=0; i<n; i++){
        int v; cin >> v;
        m[v]++;
    }
    // dbg_out(m);
    ll res = 0;
    for (auto it = m.begin(); it != m.end();){
        // find 
        ll left = it->first;
        ll count_left = it->second;
        ll right = (ll)left * x;
        if (m.find(right) != m.end()){
            ll count_right = m[right];
            ll min_count = min(count_left, count_right);
            m[left] -= min_count;
            m[right] -= min_count;
        }
        // dbg_out(left, count_left, right, m[left]);
        res += m[left];
        m[left] = 0;
        it = m.erase(it);
    }
    cout << res << nl;
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