#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


long long dp(int coins, int desserts, int power, int eaten){
    if (eaten > desserts) return 0;
    long long ans = 0;
    // eat
    if (coins >= pow(2, power))
        ans += 1 + dp(coins - pow(2, power), desserts, power++, eaten++);
    // no eat 
    ans += dp(coins, desserts, power++, eaten++);
    return ans;
}


void solve(){
    int n, k; cin >> n >> k;
    // cout << dp(n, k, 0, 0) << endl;    
    // if we have unlimited number of coins we can eat up to 2^k desserst
    // if we have unlimited desserst, we can eat a dessert for every power of coins of 2: 1 2 4 8 16
    // cout << min((int)pow(2, k), n+1) + 1 << endl;    
    k = min(k, 30);   // cannot eat more than 30 desserts due to the power of 2 (int) < 1e9
    cout << min(n, (1<<k)-1) + 1 << endl; 
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 0; cin >> test;
    while (test--) solve();
    // for (int i=0; i<10; i++){
    //     dbg_out((1<<i) -1);
    // }
    return 0;
}