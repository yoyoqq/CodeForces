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
    
    ll n, m; cin >> n >> m;

    ll l = max(0LL, n-m), r = n+m, count = 0;
    for (int i=31; i>=0; i--){
        // if the left or right bit match is one
        // if diff, it has been flipped , apparently if we shift it, we can know the bits that were on before 
        if ((l & (1LL << i)) || (r & (1LL << i)) || (l >> (i + 1)) != (r >> (i + 1))) {
            count |= (1LL << i);
        }
    }
    cout << count << endl;
    
    
    // ? if we have right, all th bits from the last 1 should be on 
    // int count = n + m;
    // for (int i=0; i<32; i++){
    //     int shift = (1 << i);
    //     if (count & shift) break;
    //     // we can turn this on 
    //     count = count | shift;
    // }
    // cout << count << endl;
    
    
    // ? how to solve TLE, with cur implementation 
    // for (int i=max(0, n-m); i<=n+m; i++){
    // int count = n;
    // goes both ways, front and back, get the or of all since by m iterations it will be joint
    // for (int i=max(0, n-m); i<=n+m; i++){
    //     count |= i;
    // }
    // cout << count << endl;
    
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