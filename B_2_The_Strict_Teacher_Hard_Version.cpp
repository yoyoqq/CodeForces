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
    int n, m, q; cin >> n >> m >> q;
    vector<int> b(m);
    for (int& x : b) cin >> x;
    sort(b.begin(), b.end());

    // dbg_out(b);
    for (int i=0, x; i<q; i++){
        cin >> x;
        // case 1 
        if (x < b[0]) cout << (b[0] - 1) << endl;
        // case 2 
        else if (x > b[m-1]) cout << (n - b[m-1]) << endl;
        else{
            int idx = upper_bound(b.begin(), b.end(), x) - b.begin();   // lower bound doesnt work, case: b.end() goes out of bound 
            // cout << ((b[idx+1] - b[idx]) / 2) << endl;
            cout << ((b[idx] - b[idx-1]) / 2) << endl;
        }
    }
    
    
    
    // int l;
    // // get input and if fisrt and last in   -> no teacher in 
    // bool first = false, last = false;
    // for (int i=0; i<m; i++){
    //     cin >> l;
    //     if (i == 0 && l != 1) {
    //         b.push_back(1);
    //         first = true;
    //     }
    //     b.push_back(l);
    //     if (i == m-1 && l != n){
    //         b.push_back(n);
    //         last = true;
    //     }
    // }
    // dbg_out(b, first, last);

    // int pos;
    // while (q--){
    //     cin >> pos;
    //     int idx = lower_bound(b.begin(), b.end(), pos) - b.begin();

    // }
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