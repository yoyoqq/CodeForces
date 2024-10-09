#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    // maximum rating ? 
    // choose i < j, decrease j = j - i
    // use the n-2
    // till last n-1
    // res = n-1 - n-2
    ll count = 0;
    int n; cin >> n;
    vector<int> a(n); 
    for (int i=0; i<n; i++){
        cin >> a[i];
        count += a[i];
    }
    // sum - n-2 (out from sum) - n-2 (for n-1)
    cout << count - (2 * a[n-2]) << endl;
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