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

int const MOD = 1e9 + 7;
    
void solve(){
    // pattern is 2 ** k 
    int t; cin >> t;
    vector<int> ks(t);
	for (int _ = 0; _ < 2; _++)
		for (int i = 0; i < t; i++)
			cin >> ks[i];
    // dbg_out(ks);
    // calculate powers of 2 
    vector<int> ans(1 + *max_element(ks.begin(), ks.end()), 1);
    for (int i=1; i<(int)ans.size(); i++){
        ans[i] = (2LL * ans[i - 1]) % MOD;
    }
    // get output from map
    for (int k: ks){
        cout << ans[k] << endl;
    }

    
    // int N; cin >> N;
    // int x;
    // vector<vector<int>> C(2, vector<int>(N));   
    // for (int i=0; i<2; i++){
    //     for (int j=0; j<N; j++){
    //         cin >> x;
    //         C[i][j] = x;
    //     }
    // }
    // dbg_out(C);
    // int cur = 0;
    // for (int n = 0; n < 2; n++) { // loop over n from 0 to N-1 (inclusive)
    //     C[n][0] = 1;
    //     C[n][n] = 1;
    //     for (int k = 1; k < n; k++){
    //         C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
    //     } // loop over k from 1 to n-1 (inclusive)
    //     cout << C[n][cur] << endl;
    //     cur++;
    // }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    // int test = 1e9; cin >> test;
    // while (test--) solve();
    return 0;
}

/*



*/