#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// using nl = '\n';
#define nl endl

void solve(){ 
    //if there is a true in the start or end is always true
    // if there are 2 consc true, is true (greedy) or and or 
    int n; cin >> n; 
    string s; cin >> s;
    bool win = false;
    if (s[0] == '1' || s[n-1] == '1') win = true;
    for (int i=1; i<n; i++){
        if (s[i] == '1' && s[i-1] == '1') win = true;
    }
    cout << ((win) ? 'yes' : 'no') << nl;


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
