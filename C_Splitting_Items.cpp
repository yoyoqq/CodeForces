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

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& x : a) cin >> x;   
    sort(a.begin(), a.end(), greater<int>());

    int count = 0;
    for (int i=0; i<n; i++){
        // alice
        if (i % 2 == 0){
            count += a[i];
        }
        // bob
        else{
            int increase = min(k, a[i-1] - a[i]);
            count -= (a[i] + increase);
            k -= increase; 
        }
    }
    cout << max(0, count) << nl;

    // // greedy, the leftmost increase to max  
    // // dbg_out(a);
    // for (int i=n-1; i>=0; i--){
    //     if (k == 0 || a[0] == a[i]) break;
    //     int increase = min(k, a[0] - a[i]);
    //     a[i] += increase;
    //     k -= increase;
    // }
    // sort(all(a), greater<int>());
    // // dbg_out(a);

    // // get res greedy
    // int count = 0;
    // for (int i=0; i<n; i++){
    //     if (i % 2 == 0){
    //         count += a[i];
    //     } else{
    //         count -= a[i];
    //     }
    // }
    // cout << count << nl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 0; cin >> test;
    while (test--) solve();
    return 0;
}

/*



*/