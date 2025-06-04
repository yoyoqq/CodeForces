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
    int a, b; cin >> a >>  b;
    // if (b == 0){
    //     if (a % 2 == 0)
    //         cout << 0 << endl;
    //     else{
    //         cout << 1 << endl;
    //     }
    // } 
    if (a < b) cout  << b - a << endl;
    else if (a % 2 == b % 2){
        cout << 0 << endl;
    }
    // move one bit, place then B in the negative side 
    else{
        cout << 1 << endl;
    }
    // ? hwo to fix this 
    // move to the next multiple of b 
    // else if (a > b) {
    //     cout << (a-b)/2 << endl;
    //     // if (b == 0 && a % 2 == 0){
    //     //     cout << 0 << endl;
    //     // }
    //     // else if (b == 0 && a % 2 == 1){
    //     //     cout << 1 << endl;
    //     // }
    //     // else{
    //     //     int left = a % b;
    //     //     int right = b - (a % b);
    //     //     cout << min(left, right) << endl;
    //     //     // cout << 1 << endl;   
    //     // }
    // }    
    // else{
    //     cout << 0 << endl;
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