#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


bool check(string ans, string t){
    // ans / t 
    int j = 0;
    for (int i=0; i<ans.size(); i++){
        if (t[j] != ans[i]) return false;
        j++; j %= t.size();
    }
    if (j == 0) return true;
    return false;
}

void solve(){
    // find bigger string divisible by both, take min and multiply by itself 
    string s, t; cin >> s >> t;
    if (s.size() > t.size()) swap(s, t);
    int n = s.size(), m = t.size();
    string ans = t;
    while (ans.size() <= m*1000){
        bool lcm = check(ans, s);
        if (lcm){
            cout << ans << endl;
            return;
        }
        ans += t;    
    }
    cout << -1 << endl;

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