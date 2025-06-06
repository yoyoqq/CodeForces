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
    string s; cin >> s;
    // 2 ^ k mask operations, take or no take 
    int x = (1<<s.size()), ans = -1;
    // apply the operations from 1 to x 
    for (int i=1; i<x; i++){
        string a; 
        // take all the chars that are allowed from I if on
        for (int j=0; j<s.size(); j++){
            // dbg_out(i, (1<<j), i&(1<<j)); 
            if (i & (1<<j)) a.push_back(s[j]);
        }
        // if its squared ? 
        if (a.size() && a[0] == '0') continue;  // no leading zeroes 
        int b = stoi(a), c = sqrt(b);
        if (b == c * c) ans = max(ans, (int)a.size());
    }
    // dbg_out(ans, ans == -1 ? -1 : s.size() - ans);
    // cout << (ans == -1 ? -1 : s.size() - ans) << endl;
    if (ans == -1) cout << -1 << endl;
    else cout << s.size() - ans << endl;

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