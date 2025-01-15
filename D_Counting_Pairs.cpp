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
ll A[200010];

void solve(){
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n); 
    for (ll& num : a) cin >> num;
    sort(a.begin(), a.end());   
    ll sum = accumulate(a.begin(), a.end(), 0);

    int pairs = 0;
    for (int i=0; i<n; i++){
        ll low = sum - a[i] - y;
        ll high = sum - a[i] - x;
        int l = lower_bound(a.begin() + i + 1, a.end(), low) - a.begin();
        int u = upper_bound(a.begin() + i + 1, a.end(), high) - a.begin();
        pairs += u - l;  
    } 
    cout << pairs << endl;
    
    // int pairs = 0;
    // for (int i=n-1, j=0, k=0; i>=0; i--){
    //     while (a[k] + a[i] <= sum - x) k++; // upper bound 
    //     while (a[j] + a[i] < sum - y) j++;  // lower bound 
    //     pairs += min(i, k) - min(i, j); 
    // }
    // cout << pairs << endl;
    
    // 
    // dbg_out(sum, a);
    // // dbg_out(a, x, y, sum);
    // ll pairs = 0;
    // for (ll i=0; i<n-1; i++){
    //     if (a[i] > y) break;
    //     // binary search to check range
    //     ll need1 = x - a[i] - 1, need2 = y - a[i];
    //     ll left = i+1; 
    //     ll right = n-1; 
    //     while (left <= right){
    //         ll mid = (left + right) / 2;
    //         if (a[mid] <= need1){
    //             left = mid +1;
    //         }else{
    //             right = mid + 1;
    //         }
    //     } 
    //     ll left2 = i+1;
    //     ll right2 = n-1;
    //     while (left2 <= right2){
    //         ll mid = (left2 + right2) / 2;
    //         if (a[mid] <= need2){
    //             left2 = mid + 1;
    //         }else{
    //             right2 = mid - 1;
    //         }
    //     }
    //     pairs += left2 - left;
    // }
    // cout << pairs << endl;
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll test = 1e9; cin >> test;
    while (test--) solve();
    return 0;
}

/*



*/