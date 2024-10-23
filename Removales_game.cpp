#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (int& x : a) cin >> x;
    vector<int> b(n); for (int& x : b) cin >> x;
    // if diff alice wins, in order to bob to win he need to take out the same op as alice 
    bool same = true;
    bool rev = true;
    for (int i=0; i<n; i++){
        if (same && a[i] != b[i]) same = !same;   
        if (rev && a[i] != b[n-i-1]) rev = !rev;
    }
    if (same || rev){
        cout << "Bob" << endl;
    }
    else {
        cout << "Alice" << endl;
    }
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
