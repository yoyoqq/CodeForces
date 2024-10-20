#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// using nl = '\n';
#define nl endl

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n); for(int& x : a) cin >> x;
    // operations are only found on the greatest int
    int mx = 0;
    for (int& x : a) mx = max(mx, x);
    // output for each op
    char op; 
    int x, y;
    for (int i=0; i<m; i++){
        cin >> op;
        cin >> x >> y;
        // if in range 
        if (x <= mx && mx <= y){
            mx += (op == '+') ? 1 : -1;
        }
        cout << mx << " ";   
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test; cin >> test;
    while(test--) solve();
    return 0;
}
