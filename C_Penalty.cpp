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
    string s; cin >> s;
    int cnt0 = 0, cnt1 = 0;
    int ans = 9;
    // favour of zero using 1 and ? 
    for (int i=0; i<10; i++){
        // 0 favour 
        if (i % 2 == 0) cnt0 += s[i] != '0';
        else cnt1 += s[i] == '1';
        if (cnt0 > cnt1 + (10-i)/2) ans = min(ans, i);
        if (cnt1 > cnt0 + (9-i)/2) ans = min(ans, i);
    }
    // reversed in favour of one 
    cnt0 = 0, cnt1 = 0;
    for (int i=0; i<10; i++){
        if (i % 2 == 0) cnt0 += s[i] == '1';
        else cnt1 += s[i] != '0';
        if (cnt0 > cnt1 + (10-i)/2) ans = min(ans, i);
        if (cnt1 > cnt0 + (9-i)/2) ans = min(ans, i);
    }
    cout << ans + 1 << nl;  // one indexed 
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