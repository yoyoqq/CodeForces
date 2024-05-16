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

int ans, n, t, tree[300010][2]; 
string s;

void dfs(int node, int sum){
    if (!tree[node][0] && !tree[node][1]) ans = min(ans, sum);
    // left tree 
    if (tree[node][0]) dfs(tree[node][0], sum + (s[node-1] != 'L' ? 1 : 0));
    // right tree
    if (tree[node][1]) dfs(tree[node][1], sum + (s[node-1] != 'R' ? 1 : 0));
}

void solve(){
    cin >> n >> s;
    ans = n + 1;
    for (int i=1; i<=n; i++){
        cin >> tree[i][0] >> tree[i][1];
    }
    dfs(1, 0);
    cout << ans << nl;
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