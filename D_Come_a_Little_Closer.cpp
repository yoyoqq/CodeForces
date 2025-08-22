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
    int n; cin >> n;
    ll s1, s2, x[n], xs[n], y[n], ys[n];
    for (int i=0; i<n; i++){
        cin >> x[i] >> y[i];
        xs[i] = x[i];
        ys[i] = y[i];
    }
    sort(xs, xs+n);
    sort(ys, ys+n);
    ll ans = (xs[n-1] - xs[0] + 1) * (ys[n-1] - ys[0] + 1);    // without sorting  
    for (int i=0; i<n && n!=1; i++){
        s1 = xs[n-1-(xs[n-1] == x[i])] - xs[xs[0] == x[i]]+1;   // decrease if the same 
        s2 = ys[n-1-(ys[n-1] == y[i])] - ys[ys[0] == y[i]]+1;   // decrease in max or min if the same 
        if (s1*s2 != n-1) ans = min(ans, s1 * s2);      // rectangle area, remove the monster n-1  
        else ans = min({ans, s1 *(s2+1) , s2*(s1+1)});  // line test case 
    }
    cout << ans << endl;


    
    // multiset<int> rows;
    // multiset<int> cols;
    // for (int i=0; i<n; i++){
    //     int x, y; cin >> x >> y;
    //     rows.insert(x);
    //     cols.insert(y);
    // }
    // // *ms.begin()
    // // (max(x) - min(x) + 1) * (max(y) - min(y) + 1)
    // ll ans = (*rows.rbegin() - *rows.begin() + 1) * (*cols.rbegin() - *cols.begin() + 1);
    // if (ans == n){
    //     cout << ans << endl;
    //     return;
    // }
    // can we remove ? delete max and min and update 


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