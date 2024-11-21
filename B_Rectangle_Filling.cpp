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
    vector<vector<bool>> a(n, vector<bool>(m, 0));
    char c; 
    int whites = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> c;
            if (c == 'W') {a[i][j] = 1; whites++;} 
        }
    }    


    // 3 cases 
    // top != bot    (colours)
    // left != right (colours)
    // possible
    int ans = true;
    if (a[0][0] != a[n-1][m-1]){
        int imp = true;             // check if all are diff 
        for (int i=0; i<m-1; i++){
            if (a[0][i] != a[0][i+1] || a[n-1][i] != a[n-1][i+1])
                imp = false;
        }
        if (imp) ans = false;

        // move n rows 
        imp = true;
        for (int i=0; i<n-1; i++){
            if (a[i][0] != a[i+1][0] || a[i][m-1] != a[i+1][m-1])
                imp = false;
        }       
        if (imp){
            ans = false;
        }
    }
    
    cout << (ans ? "yes" : "no") << endl;
    
    
    
    // WHATS MISSING IS THE COLS 
    // // all same 
    // if (n * m == whites || whites == 0){
    //     cout << "yes" << endl;
    //     return;
    // }
    // // just one line 
    // if (n == 1 || m == 1){
    //     // convert the cols into rows 
    //     // check if first == last 
    //     if ((n == 1 && a[0] == a[m-1]) || (m == 1 && a[0] == a[n-1])){
    //         cout << "yes" << endl;
    //     }
    //     else{
    //         cout << "no" << endl;
    //     }
    //     return;
    // }
    // // the outer layer has to be a combination of both 
    // int t_o = 0;
    // int t_z = 0;
    // int b_o = 0;
    // int b_z = 0;
    // for (int i=0; i<n; i++){
    //     if (a[0][i] == 0) t_z = true;
    //     else t_o = true; 
    //     if (a[n-1][i] == 0) b_z = true;
    //     else b_o = true;
    // }
    // // if ( t_o && t_z && b_o && b_z) cout << "yes" << endl;
    // // as long as there is one is good 
    // if ((t_o && b_o) || (t_z && b_z)) cout << "yes" << endl;
    // else cout << "no" << endl;
    
    
    
    
    // // for each row and col there has to be at least 1 of each
    // dbg_out(a);
    // int res = true;
    // for (int i=0; i<n; i++){
    //     bool zero = 0;
    //     bool one = 0;
    //     for (int j=0; j<m; j++){
    //         if (a[i][j] == 0) zero = true;
    //         else one = true;
    //         if (one && zero) break;
    //     }
    //     if (!zero || !one) res = false;
    // }
    // dbg_out(res);
    // // do the same for col row 
    // for (int i=0; i<m; i++){
    //     bool zero = 0;
    //     bool one = 0;
    //     for (int j=0; j<n; j++){
    //         if (a[j][i] == 0) zero = true;
    //         else one = true;
    //         if (one && zero) break;
    //     }
    //     if (!zero || !one) res = false;
    // }
    // dbg_out(res);
    // cout << (res ? "yes" : "no") << endl;
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