#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n); for(int i=0; i<n; i++) {cin >> a[i]; a[i]--;}
    // 
    int inv = 0;
    for (int i=0; i<n; i++){
        // idx to a[i]  
        if (a[i] % k != i % k) inv++;
    }
    
    if (inv == 0){
        cout << 0 << endl;
    }
    else if (inv == 2){
        cout << 1 << endl;
    }
    else{
        cout << -1 << endl;
    }
    
    // if (k == 1){
    //     cout << 0 << endl;
    // }     
    // else if (k == 2){
    //     // odd even odd even odd ..
    //     // count number of wrong 
    //     int inv = 0;
    //     for (int i=0; i<n; i++){
    //         // odd 
    //         if (i%2 == 0 && a[i] % 2 == 0) inv++;
    //         // even 
    //         else if (i%2 == 1 && a[i] % 2 == 1) inv++;
    //     }
    //     if ()
    // }
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
