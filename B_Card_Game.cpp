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

int f(int a, int b){
    if (a > b) return 1;
    if (a == b) return 0;
    if (a < b) return -1;
    return 0;
}

void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    int ans = 0;
    // create tree and play game, count on win or loose 
    if (f(a, c) + f(b, d) > 0) ans++;
    if (f(a, d) + f(b, c) > 0) ans++;
    if (f(b, c) + f(a, d) > 0) ans++;
    if (f(b, d) + f(a, c) > 0) ans++;
    cout << ans << endl;
    
    // vector<int> a(2); cin >> a[0] >> a[1];
    // vector<int> b(2); cin >> b[0] >> b[1];
    // for (int i=0; i<2; i++){
    //     for (int j=0; j<2; j++){


    //     }
    // }
    
    
    // int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
    // if (a1 > a2) swap(a1, a2);
    // if (b1 > b2) swap(b1, b2);
    // 3 res: 0, 2, 4
    // all greater 
    // cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
    // for each game try and play 

    
    // if (a1 > b1 && a2 > b2 && a1 < b2) cout << 2 << endl;
    // else if (a1 > b1 && a2 > b2) cout << 4 << endl;
    // else if (b1 > a1 && b2 >> a2) cout << 0 << endl;
    // else cout << 0 << endl;   
    
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