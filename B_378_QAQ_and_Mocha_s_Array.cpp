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
    // there is 1 
    // there is 2 and 3 
    // else -> take the 2 min and divide them 
    int n; cin >> n;
    vector<int> a(n); for(int& x : a) cin >> x;
    sort(all(a));
    // 
    bool poss = false;
    if (a[0] == 1){
        poss = true;
    } 
    int x = a[0], y = a[1];
    for (int i=1; i<n; i++){
        if (a[i] % x != 0){
            y = a[i];
            break;
        }
    }
    bool divisible = true;
    for (int i=2; i<n; i++){
        if (!(a[i] % x == 0 || a[i] % y == 0)){
            divisible = false;
        }
    }
    if (divisible || poss){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
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