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
    vector<int> a(n);
    vector<int> h(n);
    for (int& x : a) cin >> x;
    for (int& x : h) cin >> x;
    //
    int ans = 0;
    for (auto i : a){
        if (i <= k) ans = 1;
    }

    // put divisible blocks in arr
    vector<vector<int>> arr;
    int i = 1;
    while (i < n){
        if (h[i-1] % h[i] == 0){
            vector<int> temp;
            temp.push_back(a[i-1]);
            while (i < n && h[i-1] % h[i] == 0){
                temp.push_back(a[i]);
                i++;
            }
            arr.push_back(temp);
        }
        else i++;
    }

    // dbg_out(arr);
    // for each possible subarray, sliding window 
    for (auto& a : arr){
        int i = 0;
        int j = 0;
        int sm = 0;
        while (j < a.size()){
            sm += a[j];
            while(sm > k){
                sm -= a[i];
                i++;
            }
            j++;
            ans = max(ans, j - i);
        }
    }
    cout << ans << nl;
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