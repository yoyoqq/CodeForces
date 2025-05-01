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
    vector<int> a(n+1, 0); for(int i=1; i<=n; i++) cin >> a[i];
    // get prefix, get the max 
    vector<int> prefix(n+1, 0);
    for (int i=1; i<=n; i++){
        prefix[i] = max(prefix[i-1], a[i-1]);
    }
    dbg_out(a);
    dbg_out(prefix);
    // based on the cur a[i] if there is a greater val
    ll sum = 0;
    for (int i=n; i>=1; i--){
        sum += a[i];
        // replace ? 
        if (prefix[i] > a[i]){
            cout << sum - a[i] + prefix[i] << " ";
        }else{
            cout << sum << " ";
        }
    }cout << endl;
    
    
    // ! move at the end, thus wrong (not replace..)
    // get k operations 
    // ll sum = 0;
    // int mn = 1e9;
    // for (int i=n; i>=1; i--){
    //     mn = min(mn, a[i]);
    //     sum += a[i];
    //     // calc
    //     if (i == 1) cout << sum << " ";
    //     else{
    //         cout << (sum - mn + prefix[i]) << " ";
    //     }
    // }
    // cout << endl;
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