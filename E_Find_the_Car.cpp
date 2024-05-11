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
    int n, k, q; cin >> n >> k >> q;
    vector<int> a(k+1, 0), b(k+1, 0);
    for(int i=1; i<k+1; i++) cin >> a[i];
    for(int i=1; i<k+1; i++) cin >> b[i];
    // for each query
    for (int i=0; i<q; i++){
        ll c; cin >> c;
        int l = 0, r = k;
        // find the upper bound binary search 
        while (l <= r){
            int mid = l + r >> 1;
            if (a[mid] > c) r = mid - 1;
            else l = mid + 1;
        }
        if (a[r] == c) cout << b[r] << " ";
        else {
            // prevtime + cur pos * mins / dist     (how many MINS it needs from that pos)
            ll ans = b[r] + (c - a[r]) * (b[r+1] - b[r]) / (a[r+1] - a[r]);  
            cout << ans << " ";
        }
    }
    cout << nl;

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