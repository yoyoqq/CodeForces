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
    int n, x; cin >> n >> x;

    // different test cases whne x = 0, 1, >=2
    // then n can be even or odd 
    int bits = __builtin_popcountll(x);
    if (n <= bits) cout << x;
    else if ((n-bits) % 2 == 0) cout << x + n - bits;
    else{
        if (x > 1) cout << x+n-bits+1;
        else if (x == 1) cout << n + 3;
        else{
            if (n == 1) cout << -1;
            else cout << n + 3;
        }
    }
    cout << endl;
    
    // if (n == 1){cout << x << endl; return;}
    // // put all ones - 2 
    // int sum = n - 2;
    // int previous = 0;
    // if ((n - 2) % 2 == 1){
    //     previous = 1;
    // }
    // // else{
    // //     // find the smallest rightbit of x 
    // //     // dbg_out(n, x, previous);
    // // }
    // // previous 2 z/y
    // int z = 0;
    // for (int i=0; i<32; i++){
    //     // if (((1<<i) || x) != x){
    //     // if (x & (1 << i)){
    //     if (((x>>i) & 1) == 0){
    //         z = (1<<i);
    //         break;
    //     }
    // }
    // z = z | previous;   // get that bit on 
    // int y = z | x;
    // sum += z + y;

    // cout << sum << endl;
    
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