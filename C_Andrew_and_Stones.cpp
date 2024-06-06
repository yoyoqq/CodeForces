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
    vector<int> a(n);
    int right = 0;
    int left = 0;
    int count = 0;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    // false 
    if (*max_element(a.begin()+1, a.end()-1) == 1 || (n == 3 && a[1] % 2 != 0)){
        cout << -1 << nl;
        return;
    } 

    // possible
    ll ans = 0;
    for (int i=1; i<n-1; i++){
        ans += (a[i] + 1) / 2;
    }
    
    cout << ans << nl;
    
    // // count from the left and right numbers needed (greedy
    // for  (int i=1; i<n-1; i++){
    //     // even
    //     if (a[i] % 2 == 0){
    //         if (i != 1){
    //             left += a[i] / 2;
    //             // left++;
    //         }
    //         right += a[i] / 2;
    //         // right++;
    //     }
    //     // odd 
    //     else{
    //         if (i != n-2){
    //             right--;
    //         }
    //         left--;
    //         a[i]++;
    //     }
    //     count += a[i] / 2;
    // }
    // // dbg_out(a);
    // // dbg_out(left, right, count);
    // if (left >= 0 && right >= 0) cout << count << nl;
    // else cout << -1 << nl;
    
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