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

bool sortcol(const vector<int>& v1, const vector<int>& v2){
return v1[1] < v2[1];
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    // we cann only sum f its 1 
    vector<int> suf(n);
    for (int i=0; i<n; i++){
        for (int j=n-1; j>=0; j--){
            if (a[i][j] != 1) break;
            suf[i]++;
        }
        // dbg_out(suf);
    }
    // dbg_out(suf);
    multiset<int> s;
    for (int i=0; i<n; i++){
        s.insert(suf[i]);
    }
    int ans = 1;
    while (!s.empty()){
        int cur = *s.begin();
        if (cur >= ans){
            ans++;
        }
        s.extract(cur);
    }
    // cout << ans << endl;
    cout << min(ans, n) << endl;
    
    
    // 
    // 1. start from the end
    // sort them on order 
    // for (int i=0; i<n; i++){
    //     sort(a[i].begin(), a[i].end());
    // }
    // sort(a.begin(), a.end(), sortcol);
    // dbg_out(a);

    // count suffix  
    // map<int, int> freq;
    // for (int i=0; i<n; i++){
    //     int sum = 0;
    //     for (int j=n-1; j>=0; j--){
    //         sum += a[i][j];
    //         // freq[sum]++;
    //     }
    // }
    // dbg_out(freq);
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