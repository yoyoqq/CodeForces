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
    vector<int> a(n+1, 0);
    // for(int& x : a) cin >> x;
    // 
    // get prefix and suffix 
    vector<int> l(k+1, n+1), r(k+1, -1), sl, sr;
    vector<bool> seen(k+1, 0);
    for (int i=1; i<=n; i++){
        cin >> a[i];
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = i;
        seen[a[i]] = 1;
    }
    sl = l;
    sr = r;
    for (int i=k-1; i>=1; i--){
        sl[i] = min(sl[i], sl[i+1]);
        sr[i] = max(sr[i], sr[i+1]);   
    }
    for (int i=1; i<=k; i++){
        if (seen[i] == 0)
            cout << 0 << " ";
        else
            cout << 2 * (sr[i] - sl[i] + 1) << " ";
    }
    cout << nl;
    
    // int n, k; cin >> n >> k;
    // vector<int> a(n, 0);
    // for (int& x : a) cin >> x;
    // //
    // vector<vector<int>> b;
    // // fill rows
    // for (int i=0; i<n; i++){
    //     vector<int> temp(n, a[i]);
    //     b.push_back(temp);
    // }
    // // fill cols 
    // for (int cols=0; cols<n; cols++){
    //     for (int rows=0; rows<n; rows++){
    //         b[rows][cols] = min(b[rows][cols], a[cols]);
    //     }
    // }
    // // dbg_out(b);

    // // for each k
    // vector<vector<int>> res(k, vector<int>(4, -1));
    // for (int row=0; row<n; row++){
    //     for(int col=0; col<n; col++){

    //     }
    // }

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