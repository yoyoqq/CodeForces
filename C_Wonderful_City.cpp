#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;

long long INF = 1e18;


// solve dp 
long long solveHor(int n, vector<vector<int>>& h, vector<int>& a){
    // solve only hor, dp with 0 or 1, take/no take    
    vector<vector<long long>> dp(n, vector<long long>(2, INF));
    dp[0][0] = 0;       // no operation
    dp[0][1] = a[0];    // operation a[i]

    // find row 
    for (int i=1; i<n; i++){
        // make op? we can sum it up to 2 each a[i][j]
        for (int x=0; x<2; x++){
            for (int y=0; y<2; y++){
                bool ok = true;
                for (int j=0; j<n; j++){
                    ok &= (h[i-1][j] + y != h[i][j] + x);   // is the whole row good?
                }
                if (ok){
                    if (x == 0){    // make no op, take the min
                        dp[i][x] = min(dp[i][x], dp[i-1][y]);
                    }
                    if (x == 1){    // make operation take from a[i]
                        dp[i][x] = min(dp[i][x], dp[i-1][y] + a[i]);
                        
                    }
                }
            }
        }
    }
    return min(dp[n-1][0], dp[n-1][1]);
}


// transpose rows cols 
void transpose(int n, vector<vector<int>>& h){
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            swap(h[i][j], h[j][i]);
        }
    }
}


void solve(){
    // get input
    int n; cin >> n;
    vector<vector<int>> h(n, vector<int>(n));
    for (int i=0; i<n; i++){
        for (int j=0, x; j<n; j++){
            cin >> h[i][j];
        }
    }
    vector<int>a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    // solve for 2 different cases 
    long long horCost = solveHor(n, h, a);
    transpose(n, h);
    long long verCost = solveHor(n, h, b); 
    long long totalCost = horCost + verCost;

    if (totalCost >= INF){
        cout << -1 << endl;
    }
    else{
        cout << totalCost << endl;
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 0; cin >> test;
    while (test--) solve();
    return 0;
}
