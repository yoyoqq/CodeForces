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
    int sz; cin >> sz;
    vector<int> a(sz); 
    unordered_map<int, int> map;
    for(int& x : a){
        cin >> x;
        map[x]++;
    }
    // formula is: sz - 2 = n * m
    // find m 
    for (int& n : a){
        if ((sz - 2) % n != 0) continue;
        int m = (sz - 2) / n;
        if (n == m && map[n] < 2) continue; // same val, not enough count
        if (map[m] >= 1) {
            cout << n << " " << m << endl;
            return;
        }
    }
    
    // for (auto& [n, v] : map){
    //     // can use the same n
    //     if (v >= 2 && (n * n == sz-2)){
    //         cout << n << " " << n << endl;
    //         return;
    //     }
    //     // find m
    //     int m = -1;
    //     if (((sz-2) % n != 0) && map.find((sz-2)/2) != map.end()){
    //         m = sz - 2 / 2; 
    //     }
    //     if (m != -1){
    //         cout << n << " " << m << endl;
    //         return;
    //     } 
    // }
    // find n m in array 
    // n - x = m
    // m = n - n
    // dbg_out(a);
    // dbg_out(map);
    // int m = sz - 2;
    // for (int& n : a){
    //     int m = (sz - 2) % n == 0 ? (sz-2)/2 : -1;
    //     if (map.find(m) != map.end()){
    //         cout << n << " " << m <<  endl;
    //         return;
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