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
    // gcd of two numbers
    // 4 8 -> 4 
    // 2 4 6 8 -> 2 
    // gcd(b) != gcd(c)        

    // min max 
    // one number to max 
    // rest min 
    int n; cin >>n ;
    vector<int> a(n);
    int mn = 1e9, mx = 0;
    for (int i=0; i<n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    // calc 
    if (mx == mn){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i=0; i<n; i++){
        if (mx == a[i]){
            cout << 2 << " ";
            mx = 1e9;
        }else{
            cout << 1 << " ";
        }
    }
    cout << endl;
    
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