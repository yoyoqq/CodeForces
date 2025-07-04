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
    map<int, int> freq; 
    int dishes = 0;
    for (int i=0; i<n; i++){
        int x; cin >> x;
        freq[x]++;
    }
    for (auto& [key, v] : freq){
        // dbg_out(k, v);
        // dishes = max(dishes, v+k-1);

        // if its not divisible go up in dishes 
        // else stay 
        if (v % k == 0) dishes = max(dishes, v);
        else {
            dishes = max(dishes, (v+k-1)/k*k);
        }
    }
    // dbg_out(dishes);
    ll ans = 0;
    for (auto& [key, v] : freq){
        ans += (dishes - v);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // int test = 0; cin >> test;
    // while (test--) solve();
    solve();
    return 0;
}