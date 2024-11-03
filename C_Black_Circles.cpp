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
int A[200010];

ll dist(int x1, int y1, int x2, int y2) {
    return 1ll * (x1 - x2) * (x1 - x2) + 1ll * (y1 - y2) * (y1 - y2);
}

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        arr.push_back({x, y});
    }
    int xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;

    // Calculate squared distance between (xs, ys) and (xt, yt)
    long long dist_xt_yt = dist(xt, yt, xs, ys);

    bool ok = true;
    for (int i = 0; i < n; i++) {
        pair<int, int> p = arr[i];
        
        // Check if any point is within distance of (xs, ys) compared to (xt, yt)
        if (dist(xt, yt, p.first, p.second) <= dist_xt_yt) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "yes" : "no") << endl;
 
    
    // int n; cin >> n;
    // vector<pair<int, int>> arr;
    // for (int i=0; i<n; i++){
    //     int x, y; cin >> x >> y;
    //     arr.push_back({x, y});
    // }
    // int xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
    // // middle point
    // // idea is if it can reach the middle point safely, then its yes 
    // // int row = (a + c) / 2;
    // // int col = (b + d) / 2;
    // // int dist = distance(a, row, b, col);
    // bool ok = true;
    // for (int i=0; i<n; i++){
    //     pair<int, int> p = arr[i];
    //     if (distance(xs, ys, p.first, p.second) <= distance(xt, yt, xs, ys)){
    //         ok = false;
    //         break;
    //     }
    //     // if (distance(row, p.first, col, p.second) <= dist){
    //     // }
    // }
    // cout << ((ok) ? "yes" : "no") << endl;
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 1e9; cin >> test;
    while (test--) solve();
    return 0;
}

/*



*/