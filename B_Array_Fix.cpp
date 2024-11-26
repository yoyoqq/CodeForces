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
    vector<int> a(n); for(int& x : a) cin >> x;
    vector<int> b({a[n-1]});
    
    // from right to left is it bigger than the last one?
    for (int i=n-2; i>=0; i--){
        if (a[i] > b.back()){
            b.push_back(a[i] % 10);
            b.push_back(a[i] / 10);
        }
        else{
            b.push_back(a[i]);
        }
    }
    // dbg_out(b);
    cout << (is_sorted(b.rbegin(), b.rend()) ? "yes" : "no") << endl;
    
    
    // dbg_out(b);
    // easier to keep track of the min and max values of each num with another vector 

    // 
    // if x > x + 1
    //      split
    //      get max int for cur pos 
    // REVERSED MIGHT MAKEIT EASIER 
    // i < i + 1
    // int mx = 0;
    // bool ans = true;
    // for (int i=n-1; i>0; i--){
    //     if (a[i-1] <= a[i]) continue;
    //     // split into diff parts 
    //     // a[i-1] > a[i]
    //     // split and get min number 
    //     int cur_mn = 100;
    //     int cur_mx = 0;
    //     int num = a[i-1];
    //     while (num){
    //         cur_mn = min(cur_mn, num % 10);
    //         cur_mx = max(cur_mx , num%10);
    //         num /= 10;
    //     }
    //     // dbg_out("i", i);
    //     // dbg_out(cur_mn);
    //     // check if its good, 
    //     if (a[i] < cur_mn && cur_mx > a[i]){
    //         ans = false;
    //         // break;
    //     }
    //     // update
    //     a[i-1] = cur_mn;
    // }
    // dbg_out(a);
    // cout << (ans ? "yes" : "no") << endl;
    
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