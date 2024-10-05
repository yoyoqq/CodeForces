#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// overload cout and return pair<A, B>
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// return generic container (vector, set, list) to output stream 
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// debugging
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// generate random num
#define rng_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng_seed(x) mt19937 rng(x)
// shortcuts
#define all(x) (x).begin(), (x).end()   // sort(all(a))

using ll = long long;
typedef long double ld;
const char nl = '\n';

void solve(){
    int x, y, k; cin >> x >> y >> k;

    // min moves from 0, 0 to x, y
    // go max x and y using k (alternate)

    int xx = x / k + (x % k != 0);
    int yy = y / k + (y % k != 0);

    if (yy >= xx) cout << yy * 2 << nl;
    else cout << xx * 2 - 1 << nl;
    
    // use math 
    // min moves for x and y, min() * 2 + 1 (if y)
    // when is it -1?
    //  
    // int res = max(x / k + (x % k != 0), y / k + (y % k != 0)) * 2;
    // dbg_out(res, x / k + (x % k != 0), y / k + (y % k != 0));
    
    // if (x / k == y && x % k == 0){
    //     cout << res - 1 << nl;
    // }else{
    //     cout << res << nl;
    // }


    // simulation 
    // int use_x = true;
    // int count = 0;
    // while (x > 0 || y > 0){
    //     // dbg_out(count, use_x);
    //     if (use_x){
    //         x = x - k;
    //     }else{
    //         y = y - k;
    //     }
    //     count++;
    //     use_x = !use_x;
    // }
    // cout << count << nl;

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

/*



*/
