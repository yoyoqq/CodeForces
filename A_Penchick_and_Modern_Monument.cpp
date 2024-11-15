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
    vector<int> h(n); for(int& x : h) cin >> x;
    // 

    int count = 1;
    vector<int> dp(n, 1);
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (h[j] <= h[i]){
                dp[i] = max(dp[i], dp[j] + 1);
                count = max(count, dp[i]);
            }
        }
    }
    // dbg_out(n, count);
    cout << n - count << endl;    
    
    // dp ? 
    // dbg_out(a);

    // int operations = 0;
    // // Traverse from right to left
    // for (int i = n - 2; i >= 0; --i) {
    //     if (h[i] > h[i + 1]) {
    //         operations += (h[i] - h[i + 1]);
    //         h[i] = h[i + 1]; // Modify to match the next pillar
    //     }
    // }

    // cout << operations << endl;

    // brute force since n = 50
    // for each i, has to be increasing 
    // int count = INT_MAX;
    // for (int i=0; i<n; i++){
    //     int cur = 0;
    //     for (int j=0; j<n; j++){
    //         if (i == j) continue;
    //         if (j < i && a[j] > a[i]){
    //             cur++;
    //         }
    //         else if (j > i && a[i] > a[j]){
    //             cur++;
    //         }
    //     }
    //     count = min(count ,cur);
    //     dbg_out(count);
    // }
    // dbg_out();
    // cout << count << endl;

    
//     int count = 0;
//     for (int i=1; i<n; i++){
//         if (a[i-1] > a[i]) {
//             count++;
//             // a[i] = 0;
//         }
// }
//     cout << count << endl;
    
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