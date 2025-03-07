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
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    
    int i = 0;
    int zero_count = 0;
    int ans = 0;
    for (; i<n; i++){
        if (s[i] == '1'){
            zero_count = 0;
        } 
        else if (s[i] == '0'){
            zero_count++;
            if (zero_count == m){
                ans++;
                i += k-1;
                zero_count = 0;
            }
            // dbg_out(i, zero_count);
        }
    }
    // dbg_out(zero_count, m, i);
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
