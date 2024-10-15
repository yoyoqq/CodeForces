#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    ll sm = 0;
    for (int i=0; i<n; i++){
        cin >> a[i];
        sm += a[i];
    }
    

    if (n <= 2){
        cout << -1 << nl;
        return;
    }

    sort(a.begin(), a.end());
    // make smaller than the j = n/2
    // formula to get the half of the average wealth -> w = (s + x) / (2 * n)
    // where s is the sum, x the variable to find, n the size of the array

    // final formula ->      x = aj * 2 * n - s
    ll j = a[n/2];

    cout << max(0LL, j * 2 * n - sm + 1) << nl;
    
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

