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
    int n, m; cin >> n >> m;
    vector<int> x(n), y(n);
    for (int i=0; i<n; i++) cin >> x[i] >> y[i]; 
    // dbg_out(n, m, x, y);
    int cur_x = 0;
    int cur_y = 0;
    int perim = 0;
    for (int i=0; i<n; i++){
        int prev = 0;
        cur_x += x[i];
        cur_y += y[i];
        if (i == 0) prev = 0;
        else{
            // int row = 2 * abs(x[i] - (x[i-1] + m)); 
            // int col = 2 * abs(y[i] - (y[i-1] + m));
            int row = 2 * abs(cur_x - (cur_x-x[i]+m));
            int col = 2 * abs(cur_y - (cur_y-y[i]+m));
            prev = row + col;
            // dbg_out(prev, row, col);
        }
        perim += (4 * m) - prev;
        // dbg_out(perim, prev);
    }
    cout << perim << endl;
    
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