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
    // test cases are terrible.. 
    // find how to put the weights on the bags to maximize the score 
    // w2 is the min 
    // w3 and w1 the max 
    int n; cin >> n;
    vector<int> a(n); for(int& x : a) cin >> x;
    sort(all(a));
    int ans = 0;
    // pattern on where to place the w1 w2 w3
    for (int i=0; i<n; i++){
        // w3 is last 
        if (n-3 >= i){
            int w2 = a[i], w1 = a[i+1], w3 = a[n-1];
            int cur = abs(w1-w2) + abs(w2-w3);
            ans = max(ans, cur);
        }
        // w3 is a[0]
        if (i >= 2){
            int w3 = a[0], w1 = a[i-1], w2 = a[i];
            int cur = abs(w1-w2) + abs(w2-w3);
            ans = max(ans, cur);
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