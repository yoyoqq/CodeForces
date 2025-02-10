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
    vector<ll> a(n);
    for (ll& x : a) cin >> x;
    if (n == 1){
        cout << 1 << endl;
        return;
    }
    // 
    sort(all(a));

    // if even
    if (n % 2 == 0){
        ll ans = 1;
        for (int i=1; i<n; i+=2){   // ! we do 2 jumps rather than 1 
            ans = max(ans, a[i] - a[i-1]);
        }
        cout << ans << endl;
    }else{
        ll ans = 1e18;
        // for each i eliminate and check the max diff 
        for (int i=0; i<n; i++){
            vector<ll> temp;
            for (int j=0; j<n; j++){
                if (j == i) continue;
                temp.push_back(a[j]);
            }
            ll cur = 0;
            for (int j=0; j<n-1; j+=2){
                cur = max(cur, temp[j+1] - temp[j]);
            }
            ans = min(ans, cur);
        }
        cout << ans << endl;
    }

    
    // use from sides 
    // ll to_right = 0, to_left = 0;
    // for (ll i=2; i<n; i++){
    //     to_right = max(to_right, a[i] - a[i-1]);
    // }
    // for (ll i=n-3; i>=0 ;i--){
    //     to_left = max(to_left, a[i+1] - a[i]);
    // }

    
    // if its in mid, diff is the second max 
    // ll mid = max(first_max/2, second_max);
    // // dbg_out(to_right, to_left, first_max/2, second_max, mid);
    // if (n == 2){
    //     cout << a[1] - a[0] << endl;
    // }else if (n == 1){
    //     cout << 1 << endl;
    // }else{
    //     cout << min({to_right, to_left, mid}) << endl;
    // }
    
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