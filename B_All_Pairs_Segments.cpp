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
ll A[200010];

void solve(){
    ll n, q; cin >> n >> q;
    vector<ll> a(n); for(auto& x : a) cin >> x;
    map<ll, ll> map;
    for (ll i=0; i<n; i++){
        ll before = i;
        ll after = n - i - 1;
        ll segments = (before + 1) * (after + 1) - 1;
        map[segments]++;
        if (i > 0){
            ll inBetween = a[i] - a[i-1] - 1;
            segments = before * (after + 1);
            map[segments]  += inBetween;
        }
    }   
    // dbg_out(map);
    while (q--){
        ll x;
        cin >> x;
        if (map[x]){
            cout << map[x] << " ";
        }
        else{
            cout << 0 << " ";
        }
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll test = 1e9; cin >> test;
    while (test--) solve();
    return 0;
}

/*



*/