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
const int MAXN = 2000;
int a[MAXN][MAXN];

void solve(){
    int n, m, sum = 0;
    cin >> n >> m;
    string s; 
    // count number of ones 
    // get pos of the zeroes and ones 
    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<m; j++){
            a[i][j] = s[j] - '0';
            sum += a[i][j];
        }
    }
    // 
    int zeroes = INT_MAX;
    // iterate entire grid - last pos, check the square 
    for (int i=0; i<n-1; i++){
        for (int j=0; j<m-1; j++){
            int count = a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1];
            if (count == 0) continue;
            // zeroes = min(zeroes, max(1, count - 1));
            zeroes = min(zeroes, max(1, count - 1));
        }
    }
    if (sum == 0) cout << "0\n";
    else cout << 1 + sum - zeroes << nl;
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