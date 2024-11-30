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
    k = 2 * k;

    // two options, 
    // since we are looking at hte two parts (middles)
    // we can use same numbers, which will cancell out
    // or, use the 1 occ which will cancell out by iteself with the other part 
    vector<int> a(n*2, 0), occ(n+1, 0);
    for (auto& x : a) cin >> x;
    for (int i=0; i<n; i++) occ[a[i]]++;

    vector<int> g0, g1, g2;
    for (int i=1; i<=n; i++){
        if (occ[i] == 0) g0.push_back(i);
        else if (occ[i] == 1) g1.push_back(i);
        else g2.push_back(i);
    }
    
    // use occ of two 
    int v= 0;
    for (auto x : g2){
        if (v < k){
            v += 2;
            cout << x << " " << x << " ";
        }
    }
    // occ of 1, use from both sides, will cancell out 
    for (auto x : g1){
        if (v < k){
            v++;
            cout << x << " ";
        }
    }
    cout << endl;

    // reset, second half 
    v = 0;
    for (auto x : g0){
        if (v < k){
            v += 2; 
            cout << x << " " << x << " ";
        }
    }
    for (auto x : g1){
        if (v < k){
            v++;
            cout << x << " ";
        }
    }
    cout << endl;
    
    
    
    
    // // dbg_out(count, a);
    // // case 1 -> occ on both sides
    // bool ans = false;    
    // vector<int> le, ri;
    // for (int i=1; i<=n; i++){
    //     // left
    //     if (count[i] == 2){
    //         le.push_back(i);
    //     }
    //     else if (count[i] == 0){
    //         ri.push_back(i);
    //     }
    // }
    // // dbg_out(le, ri);
    // // dbg_out(le, ri, 2*k);
    // if (le.size() >= 2*k && ri.size() >= 2*k){
    //     for (int i=0; i<2*k; i++){
    //         cout << le[i] << " ";
    //     }
    //     cout << endl;
    //     for (int i=0; i<2*k; i++){
    //         cout << ri[i] << " ";
    //     }
    //     cout << endl;
    //     return;
    // }
    // // case 2 -> use occ of 1 on both sides 
    // vector<int> res;
    // for (int i=1; i<=n; i++){
    //     if (count[i] == 1){
    //         res.push_back(i);
    //     }
    // }
    // dbg_out(res);

    // for (int _=0; _<2; _++){
    //     for (int i=0; i<min(res.size(), k); i++){
    //         cout << res[i] << " " ;    
    //     }
    //     cout << endl;
    // }
    
    // !!! left - right side are same size
    // thus, check the occurrences as a ^ a = 0
    // two cases
    // 1. occ of 2 both sides 
    // 2. use occ of 1 on both sides 
    
    
    
    // in this case the subsq == substring 
    // slide the window 
    // how to negate xor ? 

    // brute force 
    // for (int i=0; i<n/2; i++){
    //     // get left 
    //     int left = 0;
    //     for (int j=i; j<i+k; j++){
    //         left ^= a[j];
    //     }
    //     // get right
    //     int right = 0;
    //     for (int j=i+k; j<i+k+k; j++){
    //         right ^= a[j];
    //     }
    //     if (left == right) dbg_out(left, right);
    //     dbg_out(left, right);
    // }
    // dbg_out();
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