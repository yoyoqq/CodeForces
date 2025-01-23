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
    ll n, l, r; cin >> n >> l >> r;
    vector<ll> left, mid, right;
    ll total_mid = 0;
    for (ll i=1, x; i<=n; i++){
        cin >> x;
        if (i < l){
            left.push_back(x);
        }
        else if (l <= i && i <= r){
            mid.push_back(x);
            total_mid += x;
        }else{
            right.push_back(x);
        }
    }
    sort(left.begin(), left.end());
    sort(mid.begin(), mid.end());
    sort(right.begin(), right.end());
    // swap left mid 
    ll mid_sum = 0;
    ll left_sum = 0;
    for (ll i=0; i<min(left.size(), mid.size()); i++){
        ll left_idx = left.size()-1-i;
        ll mid_idx = mid.size()-1-i;
        // while left smaller than mid 
        if (left[i] >= mid[mid_idx]) break;
        // use the val from left and swap 
        left_sum += left[i];
        mid_sum += mid[mid_idx];
    }

    ll res = __LONG_LONG_MAX__;
    res = min(total_mid, total_mid + left_sum - mid_sum);
    mid_sum = 0;
    ll right_sum = 0;
    for (ll i=0; i<min(right.size(), mid.size()); i++){
        ll right_idx = right.size()-1-i;
        ll mid_idx = mid.size()-1-i;
        if (right[i] >= mid[mid_idx]) break;
        right_sum += right[i];
        mid_sum += mid[mid_idx];
    }
    res = min(res, total_mid + right_sum - mid_sum);
    cout << res << endl;
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