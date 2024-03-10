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

void solve(){
    int n, m, h; cin >> n >> m >> h;
    vector<vector<int>> a(n, vector<int>(m));
    // points -> (minutes, person)
    // map<int, vector<pair<int, int>>> map;
    int ans = 1;
    pair<ll, ll> rud;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
        // dbg_out(a[i]);
        // iterate though time and add to map (points -> (pp, penalty))
        int participant = i + 1;
        ll points = 0;
        // count penalty 
        ll penalty = 0;
        ll acc = 0;
        for (int j=0; j<a[i].size(); j++){
            if (acc + a[i][j] > h) break;
            points++;
            acc = acc + a[i][j];
            penalty += acc;
        }
        // if not the first value,
        if (i){
            if (points > rud.first || points == rud.first && penalty < rud.second) ans++;
        }else rud = {points, penalty};

        // if (i){
        //     if (make_pair(-points, penalty) < rud) ans++;
        // } else rud = {-points, penalty};
    }
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