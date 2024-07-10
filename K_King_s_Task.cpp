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
    int n; cin >> n;
    int a[2005];
    for(int& x : a) cin >> x;

    int cyc = (n % 2 == 0 ? 4 : 2*n);
    int pos = -1;
    for (int i=0; i<cyc; i++){
        if (is_sorted(a, a+n+n)){
            pos = i;
            break;
        }
        if (i % 2) for (int j=0; j<n; j++) swap(a[j], a[j+n]);
        else for (int j=0; j<n+n; j+=2) swap(a[j], a[j+1]);
    }   
    cout << min(pos, cyc-pos) << nl;
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // int test = 0; cin >> test;
    // while (test--) solve();
    solve();
    return 0;
}

/*



*/