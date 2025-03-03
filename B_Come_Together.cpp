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
    int xa, ya, xb, yb, xc, yc; 
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    ll count = 0;
    // for x and y, xa cannot be in between 
    if ((xa > xb) == (xa > xc)){
        // int dist = min(xb, xc);
        // count += abs(xa - dist);
        count += min(abs(xa-xb), abs(xa-xc));
    }
    if ((ya > yb) == (ya > yc)){
        // ! need to calculate the min from YA YB    YA YC 
        count += min(abs(ya-yb), abs(ya-yc));
    }
    cout << count  + 1 << endl;
    
    // int distAB = abs(xa-xb) + abs(ya-yb);
    // int distAC = abs(xa-xc) + abs(ya-yc);
    // int distBC = abs(xb-xc) + abs(yb-yc);
    // dbg_out(distAB, distAC, distBC);
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
