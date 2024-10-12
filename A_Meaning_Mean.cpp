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
    int n; cin >> n; 
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a + n);
    int x = a[0];
    for (int i=1; i<n; i++){
        x = (x + a[i]) / 2;
    }
    cout << x << nl;
    
    
    // priority_queue<int, vector<int>, greater<int>> pq; 
    // int x = 0;
    // for(int i=0; i<n; i++){
    //     cin >> x;
    //     pq.push(x);
    // }
    // // 
    // while (pq.size() != 1){
    //     int x = pq.top(); pq.pop();
    //     int y = pq.top(); pq.pop();
    //     pq.push((x + y) / 2);
    // }
    // cout << pq.top() << nl;
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