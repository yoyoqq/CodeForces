#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::aalue, typename T_container::aalue_type>::type> ostream& operator<<(ostream &os, const T_container &a) { os << '{'; string sep; for (const T &x : a) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
// template<typename Head, typename... Tail> aoid dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int& x : a) cin >> x;
    // 
    ll diff = a[1] - a[0];
    bool bad = 0;
    for (int i=2; i<n; i++){
        if (diff != a[i] - a[i-1])
            bad = 1;
    }
    // if it has different sequence 
    if (bad){
        cout << "NO" << endl;
        return;
    }
    for (int i=0; i<n; i++){
        a[i] = a[i] + (diff < 0 ? diff * (n - i) : -diff * (i + 1));
    }
    cout << (a[0] >= 0 && a[0] % (n + 1) == 0 ? "YES" : "NO") << endl;
    
    // bool dec = true, inc = true;
    // for (int i=1; i<n; i++){
    //     if (a[i-1] <= a[i]) dec = false;
    //     if (a[i-1] >= a[i]) inc = false; 
    // }
    // if (dec + inc != 1){
    //     cout << "NO" << endl;
    //     return;
    // }
    // int diff = a[1] - a[0];
    // for (int i=2; i<n; i++){

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
