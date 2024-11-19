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
    ll x; cin >> x;
    cout << 32 << endl;
    for (int i=0; i<32; i++, x>>=1){
        if (x & 1){
            if (x&2){
                x++;    // avoid consecutive ones 
                cout << -1 << " ";  // -1 0 1
            }else{
                cout << 1 << " ";
            }
        }else{
            cout << 0 << " ";
        }
    }
    cout << endl;
    
    
    // int n; cin >> n;
    // if (n == 1){
    //     cout << 1 << endl;
    //     return;
    // }
    // // if multiple of 2 
    // vector<int> f = {2, 4, 8, 16, 32};
    // // if (f.find(n) != f.end()){
    // if (find(f.begin(), f.end(), n) != f.end()){
    //     while (n){
    //         cout << 0 << " ";
    //         n = n >> 1;
    //     }
    //     cout << 1 << endl;
    //     return;
    // }
    
    // // get length of n
    // int copy_n = n;
    // int len = 0;
    // while (copy_n){
    //     copy_n = copy_n >> 1;
    //     len++;
    // }
    // // dbg_out(n, copy_n, len);
    // // positive
    // vector<int> a(len+1, 0);
    // a[len] = 1;
    // // negatives 
    // int calc = (1 << len) - n;
    // // dbg_out(calc, len, a);
    // // get calc in there 
    // int idx = 0;
    // while (calc){
    //     if (calc & 1){
    //         a[idx] = -1;
    //     }
    //     idx++;
    //     calc = calc >> 1;
    // }
    // // dbg_out(a);
    // for (int& x : a){
    //     cout << x << " ";
    // }
    // cout << endl;
    
    
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