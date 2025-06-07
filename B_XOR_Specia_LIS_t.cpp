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
    int n; cin >>n;
    vector<int> a(n); for(int& x : a) cin >> x;

    if (n % 2 == 0){
        cout << "YES\n";
        return;
    }
    // find 2 LIS 
    int lis = 0;
    bool inc = true;
    // we just need one decreasing for this to join 
    // 1 1 2 1 1 1 1 
    //     join here stil the same 
    for (int i=1; i<n; i++){
        inc = inc & a[i] > a[i-1];  // decreasing 
        // if (a[i] > a[i-1]) ;
        // dbg_out(lis, a[i], a[i-1]);
        // if (a[i] > a[i-1]){
        //     lis++;
        // }
        // if (a[i] < a[i-1]) dec = true;
    }
    if (!inc) cout << "YES\n";
    else cout << "NO\n";
    
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