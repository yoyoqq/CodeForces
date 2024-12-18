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
    ll n; cin >> n;
    vector<ll> a(n); for(ll& x : a) cin >> x;
    string s; cin >> s;
    // two pollers and prefix 
    vector<ll> pref(n+1);
    for (ll i=1; i<=n; i++){
        pref[i] = pref[i-1] + a[i-1];
    }
    // dbg_out(pref);
    // two poitners 
    ll count = 0;
    ll left = 0;
    ll right = n - 1;
    while (left <= right){
        // calc
        if (left < right && s[left] == 'L' && s[right] == 'R'){
            // dbg_out(left, right, pref[right+1], pref[left]);
            count += pref[right+1] - pref[left];
            left++;
            right--;
        }
        // move left
        while (s[left] != 'L' && left < n){
            left++;
        }
        // move right
        while (s[right] != 'R' && right >= 0){
            right--;
        }

    }
    cout << count << endl;
    
    
    
    // // leftmost L and rightmost R
    // ll leftmost = n;
    // ll rightmost = 0;
    // for (ll i=0; i<n; i++){
    //     if (i < leftmost && s[i] == 'L'){
    //         leftmost = i;
    //     }
    //     if (i > rightmost && s[i] == 'R'){
    //         rightmost = i;
    //     }
    // }
    // // calculate
    // ll count = 0;
    // for (ll i=leftmost; i<=rightmost; i++){
    //     count += a[i];
    // }
    // cout << count << endl;

    
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