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
    if (n == 1) {
        a[0] = k;
    }
    else{
        // get greatest bit 
        int msb = 0;
        for (int i=0; i<31; i++){
            if (k & (1 << i)){
                msb = i;
            }
        }
        // calc 
        a[0] = (1 << msb) - 1;
        a[1] = k - a[0];
        for (int i=2; i<n; i++){
            a[i] = 0;
        }
        
    }
    for (int& x : a){
        cout << x << " ";
    }
    cout << endl;
    
    // take all the bits in the right
    // vector<int> res;
    // int k_copy = k;
    // int sm = 0;
    // int i = 0;
    // while (pow(2, i) <= k){
    //     if (sm + pow(2, i) < k){
    //         res.push_back(pow(2, i));
    //         sm += pow(2, i);
    //     }
    //     i++;
    // }
    // // only can have n numbers 
    // if (k - sm != 0)
    //     res.push_back(k - sm);
    // while (res.size() > n){
    //     int x = res.back(); res.pop_back();
    //     int y = res.back(); res.pop_back();
    //     res.push_back(x + y);
    // }
    // // dbg_out(res);
    // for (int& x : res){
    //     cout << x << " ";
    // } 
    // cout << endl;
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