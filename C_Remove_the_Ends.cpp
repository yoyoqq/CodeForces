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
    ll n; cin >> n; vector<ll> a(n);
    for(ll& x : a) cin >> x;

    
    
    // ? just get the max from the prefix or suffix  
    vector<ll> prefix(n+1); 
    vector<ll> suffix(n+1);
    for (ll i=0; i<n; i++){
        if (a[i] > 0) prefix[i+1] += a[i];
        prefix[i+1] += prefix[i];
    }
    for (ll i=n-1; i>=0; i--){
        if (a[i] < 0) suffix[i] += abs(a[i]);
        if (i-1 >= 0) suffix[i-1] += suffix[i];
    }
    
    ll coins = 0;
    for (ll i=0; i<=n; i++){
        coins = max({coins, prefix[i] + suffix[i]});
    }
    // dbg_out(prefix, suffix);
    cout << coins << endl;

    
    // take off from 
    // positives
    // negatives
    // ll coins = 0;
    // ll i = 0, j = n-1;
    // for(; i<n; i++){
    //     if (a[i] > 0) coins += a[i];
    //     else break;
    // }

    // for(;j>=0; j--){
    //     dbg_out("HI", a[i]);
    //     if (a[j] < 0) coins += abs(a[j]);
    //     else break;
    // }
    // // 
    // vector<ll> b;
    // ll negative = 0;
    // ll positive = 0;
    // for(ll idx=i; idx<=j; idx++){
    //     if (a[idx] > 0){
    //         positive += a[idx];
    //     }else{
    //         negative += a[idx] * -1;
    //     }
    // }
    // cout << max(positive, negative) + coins << endl;

    
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