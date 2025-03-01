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
    ll n, x, k; cin >> n >> x >> k;
    string s; cin >> s;
    // can we ever reach 0 
    for (int i=0; i<n; i++){
        x += (s[i] == 'L' ? -1 : 1);
        k--;
        if (x == 0)break;
    }
    // dbg_out(n, x, k);
    ll ans = 0;
    if (x == 0){
        ans += 1;   // we found one 0 
        // how many moves do we need to reach 0 again
        for (int i=0; i<n; i++){
            x += (s[i] == 'L' ? -1 : 1);
            if (x == 0){
                ans += (k/(i+1)); 
                break;
            }
        }
    }
    cout << ans << endl;
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
