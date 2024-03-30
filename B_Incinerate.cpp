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
    int n, k; cin >> n >> k;
    vector<int> h(n, 0);
    vector<int> p(n, 0);
    for (auto& x : h) cin >> x;
    for (auto& x : p) cin >> x;
    // 
    // power, health 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    for (int i=0; i<n; i++){
        heap.push({p[i], h[i]});
    }
    int cur_dmg = 0;
    while (!heap.empty()){
        // make dmg 
        cur_dmg += k;
        // remove dead monsters
        while (!heap.empty() && cur_dmg >= heap.top().second){
            heap.pop();
        }
        // reduce attack 
        if (!heap.empty())
            k -= heap.top().first;
        // check if not possbile anymore 
        if (k <= 0){
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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