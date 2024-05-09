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
ll MOD = 1e9 + 7;
typedef long double ld;
const char nl = '\n';
int A[200010];

ll dfs(int k, int pos, vector<int>& p, vector<int>& a){
    k++;
    ll maximum = 0;
    unordered_set<int> seen;    // seen indexes
    ll cur_pos = pos;
    ll cur_count = 0;
    while (k--){
        // base case
        if (seen.find(cur_pos) != seen.end()) break;
        seen.insert(cur_pos);
        // get all
        maximum = max(maximum, cur_count + 1ll*k*a[cur_pos]);   // 1ll force the mult to avoid integer overflwo 
        // go next
        cur_count += a[cur_pos];
        cur_pos = p[cur_pos];
    }
    return maximum;
}

void solve(){
    int n, k, pb, ps; cin >> n >> k >> pb >> ps;
    vector<int> p(n), a(n);
    for (int i=0; i<n; i++){
        cin >> p[i];
        p[i]--;
    }
    for(int& x : a) cin >> x;
    // 
    // dbg_out(p, a);
    ll bodya = dfs(k, pb-1, p, a);
    // dbg_out("----------------");
    ll sasha = dfs(k, ps-1, p, a);
    // dbg_out("----------------");

    // dbg_out(bodya, sasha);
    // output
    if (bodya > sasha)
        cout << "Bodya\n"; 
    else if (bodya < sasha)
        cout << "Sasha\n"; 
    else
        cout << "Draw\n";
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