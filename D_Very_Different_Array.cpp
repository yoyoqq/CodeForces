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
     int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // sort(b.rbegin(), b.rend());
    // 
    // dbg_out(a, b);
    // two pointers 
    long long diff = 0;
    for (int i=0; i<n; i++){
		diff += max(abs(a[i]-b[m-i-1]),abs(a[i]-b[n-i-1]));
    }
    cout << diff << endl;
    
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
6 1 2 4
3 5 1 7 2 3


sort to get the max diff min max 

1 2 4 6
1 2 3 3 5 7


*/