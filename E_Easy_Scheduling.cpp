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

    int h, p; cin >> h >> p;
    int ready = 1, ans = 0, tot = (1ll << h) - 1;
    while (ready < tot){
        ans++;
        tot -= min(p, ready);
        ready *= 2;
    }
    ans += (tot + p - 1) / p;
    cout << ans << nl;
    
    
    
    // int h, p; cin >> h >> p;
    // return min time needed
    // level by level? 
    // 1 - one task ready (root)
    // then, go to its children 
    // if we cant the whole line? take rest line + subtrees
    // crete variable possible, take from here 

    // iterate the tree
    // with variable possible, take off from processes 
    // 

    // what if not a ble to take all of the nodes, you can take them later on as it is smaller
    // if it is bigger, it is capped by each level
    // int time = 0; 
    // int possible = 0;
    // for (int i=1; i<=h; i++){
    //     int nodes = pow(2, i-1);
    //     int take = max(nodes, nodes - p);
    //     time++;
    // } 
    // dbg_out(time, possible);
    // while (possible > 0){
    //     time++;
    //     possible -= p;
    // }
    // dbg_out(time, possible);
    // dbg_out();
    // cout << time << nl;
    
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