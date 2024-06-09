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

bool find(vector<ll>& a, ll k, ll h){
    // if possible to make true
    // else false 
    ll cur_dmg = 0;
    for (int i=0; i<a.size()-1; i++){
        cur_dmg += min(k, a[i+1] - a[i]);
    }
    // last case 
    cur_dmg += k;

    if (cur_dmg >= h) return true;
    else return false;
}

void solve(){
    ll n, h; cin >> n >> h;
    vector<ll> a(n);
    for (ll& x : a) cin >> x;    
    //
    // binary search find the k
    // iterate differences 
    ll left = 0; 
    ll right = h;
    ll res = 0;
    while (left <= right){
        ll mid = (left + right) / 2;
        // too big 
        if (find(a, mid, h)){
            right = mid - 1;
            res = mid;
        }else{
            left = mid + 1;
        }
    }  
    cout << res << nl;
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