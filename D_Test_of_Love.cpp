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
    int n, m, k; cin >> n >> m >> k;    // length, jump, swim
    string s; cin >> s;
    // greedy

    int c = 0, p = 1;
    for (int i=0; i<n; i++){
        // jump 
        c++;
        if (s[i] == 'L') c = 0;
        // need to swim or C
        if (c >= m){
            k--;
            // found crocodile, couldnt jump
            if (s[i] == 'C') p = 0;
        }
    }
    if (k >= 0 && p) cout << "YES" << nl;
    else cout << "NO" << nl;

    // int pos = m;
    // for (int i=0; i<n; i++){
    //     // we can jump (greedy)
    //     if (s[i] == 'L'){
    //         pos = i + m; 
    //     } 
    //     // must use water no jumps left 
    //     else if (pos <= i + 1 && k && s[i] == 'W'){
    //         k--;
    //         pos++;
    //     }
    //     // not possible 
    //     // else if (pos < i + 1 || (s[i] == 'C' && pos <= i + 1)){
    //     else if (s[i] == 'C' && pos <= i + 1){
    //         cout << "NO" << nl;
    //         return;
    //     }
    // }
    // cout << "YES" << nl;
    
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