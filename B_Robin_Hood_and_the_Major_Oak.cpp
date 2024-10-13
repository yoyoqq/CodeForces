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
    int n, k; cin >> n >> k;

    // k * (2n - k + 1) / 2
    int odd;
    if (n & 1){
        odd = (k + 1)/ 2;
    }else{
        odd = k / 2;
    }

    cout << ((odd & 1) ? "no" : "yes") << nl;


    // int odd_count = 0;
    // for (int i=n-k+1; i<=n; i++){
    //     odd_count += (i % 2 == 1);
    // }

    // if (odd_count % 2 == 0){
    //     cout << "yes" << nl;
    // }else{
    //     cout << "no" << nl;
    // }


    // it has the same parity the i ^ i == i
    // ll num = 0;
    // // i ^ i
    // for (int i=n-k+1; i<=n; i++){
    //     num += pow(i, i);
    // } 
    // cout << ((num % 2 == 0) ? "yes" : "no") << nl;
    
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