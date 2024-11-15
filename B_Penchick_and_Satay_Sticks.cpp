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
    vector<int> a(n); for (int& x : a) cin >> x;   
    // 

    // wont possible to sort if the diff is too big from its original pos 
    for (int i=0; i<n; i++){
        int pos = i + 1; 
        // if (abs(a[i] - pos) <= 1){
        if (abs(a[i] - pos) > 1){
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;

    
    // int mn = a[0];
    // int mx = a[0];
    // // dbg_out(a);
    // for (int i=1; i<n; i++){
    //     // if diff != 1 false
    //     if (abs(mx - a[i]) == 1 || abs(mn - a[i]) == 1){
    //         mn = min(mn, a[i]);
    //         mx = max(mx, a[i]);
    //     }else{
    //         cout << "no" << endl;
    //         return;
    //     }
    // }
    // cout << "yes" << endl;
    
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