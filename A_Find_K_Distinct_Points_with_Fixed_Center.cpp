#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;

const int diff = 1e6;

void solve(){
    // dbg_out(diff);
    ll x, y, k; cin >> x >> y >> k;
    // ll sum = (k * (k-1) / 2);
    ll sum = 0;
    for (ll i=1; i<k; i++){
        cout << i+diff << " " << i+diff << endl;
        sum += i + diff;
    }
    
    ll left = x * k - sum;
    ll right = y * k - sum;
    // dbg_out(x, k, x * k, sum, (x < 0 ? -1 : 1));
    cout << left << " " << right << endl;


    // ll left = x * k - sum * (x < 0 ? -1 : 1);
    // ll right = y * k - sum * (y < 0 ? -1 : 1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll test = 0; cin >> test;
    while (test--) solve();
    return 0;
}