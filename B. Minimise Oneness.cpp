#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// using nl = '\n';
#define nl endl

void solve(){ 
    int n; cin >> n;
    string s; cin >> s;
    // f -> subsq of 0
    // g -> subsq of at least one 1
    // if just one one, f - g = 1
    // (2 ^n-1 - 1) - (2 ^n -1)
    cout << '1';
    for (int i=0; i<n-1; i++){
        cout << '0';
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
