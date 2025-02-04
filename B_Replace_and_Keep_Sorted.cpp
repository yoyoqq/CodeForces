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


ll find(vector<int>& a, vector<int>& pref, int k, int left, int right){
    ll l = a[left] - 1;
    ll r = k - a[right];
    ll mid = pref[right] - pref[left];
    return l + r + mid*2;   
    
    // optmize ? prefix sum 
    // for (int i=left+1; i<=right; i++){
        // how many numbers are in between
        // mid += (a[i] - a[i-1] - 1); // each number can be used 2 times 
    // }
    // dbg_out(l, r, mid*2);

    // ll count = (a[i] - 1) + (k - a[right]);
    // for (int i=left; i<=right; i++){
    //     // check left
    //     if (i == left){
    //         count += (a[i] - 1);
    //     }
    //     else{
    //         count += (a[i] - a[i-1] - 1);
    //     }
    //     // check right
    //     if (i == right){
    //         count += (k - a[i]);
    //     }
    //     else{
    //         count += (a[i+1] - a[i] - 1);
    //     }
    // }
}



void solve(){
    int n, q, k; cin >> n >> q >> k;
    vector<int> a(n); for (int& x : a) cin >> x;

    // optmize prefix 
    vector<int> pref(n);
    pref[0] = a[0] - 1; 
    for (int i=1; i<n; i++){
        pref[i] = pref[i-1] + (a[i] - a[i-1] -1); 
    }
    // dbg_out(pref);
    while (q){
        int left, right; cin >> left >> right;
        left--; right--;    // 0 indexed 
        cout << find(a, pref, k, left, right) << endl;
        q--;
    }   
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // int test = 1e9; cin >> test;
    // while (test--) solve();
    solve();
    return 0;
}

/*



*/