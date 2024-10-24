#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin >> n;
    string vowels = "aeiou";
    string res = "";
    
    // its separate, the nums first, then the remainding 
    vector<int> a(5, n/5);
    for (int i=0; i<n%5; i++) a[i]++;
    for (int i=0; i<5; i++)
        for (int j=0; j<a[i]; j++)
            cout << vowels[i];
    cout << endl;
    
// 
    // for (int i=0; i<6; i++){
        // for (int j=0; j<n/5 + (n % 5 != 0); j++){
            // res += vowels[i];
        // }
    // }
    // cout << res << endl;
// 

    // string a = string('a', n / 5 + (n % 5 != 0));
    // string e = string('e', n / 5 + (n % 5 != 0));
    // string i = string('i', n / 5 + (n % 5 != 0));
    // string o = string('o', n / 5 + (n % 5 != 0));
    // string u = string('u', n / 5 + (n % 5 != 0));
    // cout << a << endl;
    // cout << a + e + i + o + u << endl;
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
