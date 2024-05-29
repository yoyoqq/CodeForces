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
    ll n, q, x, y, z; cin >> n >> q;
    ll sm = 0;
    map<ll, ll> m;
    for (int i=1; i<=n; i++){
        cin >> x;
        sm += x;
        m[i] = x;
    } 
    // dbg_out(sm, q);
    // queries
    ll prev = 0;
    while (q > 0){
        q--;
        cin >> x; 
        // value y to z 
        if (x == 1){
            cin >> y >> z;
            if (m.find(y) == m.end()){ // doesnt exists
                sm -= prev;
            }
            // exists
            else{
                sm -= m[y];
            }
            m[y] = z;
            sm += z;
            cout << sm << nl;
        }  
        // all values to y
        else if (x == 2){
            cin >> y;
            sm = (ll) y * n;
            prev = y;
            m.clear();
            cout << sm << nl;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}

/*



*/