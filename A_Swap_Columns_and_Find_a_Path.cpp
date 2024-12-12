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
    vector<vector<int>> a(2, vector<int>(n));
    int x = 0;
    for (int i=0; i<2; i++){
        for (int j=0; j<n; j++){
            cin >> x;
            a[i][j] = x;
        }
    }
    // 

    // dbg_out(a);
    
    int ans = 0;
    int mx = INT_MIN; 
    for (int i=0; i<n; i++){    // col 
        ans += max(a[0][i], a[1][i]);
        mx = max(mx, min(a[0][i], a[1][i]));
        
        // if (a[0][i] > a[1][i]){
        //     a[0][i] = INT_MIN;
        //     mx = max(mx, a[1][0]);
        // }else{
        //     a[1][i] = INT_MIN;
        //     mx = max(mx, a[0][i]);
        // }
        // if (max(a[0][i], a[1][i]) > mx){
        //     idx = i;
        //     mx = max(a[0][i], a[1][i]);
        //     if (a[0][i] == mx){
        //         row_zero = true;
        //     }else{
        //         row_zero = false;
        //     }
        // }
    }

    // ans += a[idx][row_zero];
    // dbg_out(ans, a[row_zero][idx]);

    cout << ans + mx << endl;
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