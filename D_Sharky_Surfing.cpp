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
    int n, m, l; cin >> n >> m >> l;
    vector<pair<int, int>> hurdle(n);
    vector<pair<int, int>> power_up(m);
    for (int i=0, x, y; i<n; i++){
        cin >> x >> y;
        hurdle[i] = {x, y};
    }
    for (int i=0, x, y; i<m; i++){
        cin >> x >> y;
        power_up[i] = {x, y};
    }
    // dbg_out(hurdle);
    // dbg_out(power_up);
    // 
    priority_queue<int> jumps; // store the jumps we can make 
    int power_idx = 0;
    int k = 1; 
    int count = 0;
    for (int i=0; i<n; i++){
        int l = hurdle[i].first, r = hurdle[i].second;
        // take all the power_ups 
        while (power_idx < power_up.size() && power_up[power_idx].first < l){
            jumps.push(power_up[power_idx].second);
            power_idx++;
        }
        // can we make the jump with cur k ? 
        while (jumps.size() && k < (r-l) + 2){
            k += jumps.top(); jumps.pop();
            count++;
        }
        // dbg_out(l, r, k, count);
        if (k < (r-l) + 2){
            count = -1;
            break;
        }
    }
    cout << count << endl;
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