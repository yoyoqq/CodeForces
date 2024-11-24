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


bool in_binary(int n){
    // divide by 10, all has to be mod to 1 or 0
    while (n){
        if (n % 10 == 0 || n % 10 == 1){
            n = n / 10;
        }else{
            return false;
        }
    }
    return true;
}


vector<int> binary_dec;

// recursion 
bool good(int n){
    if (n == 1) return true;
    bool ans = false;
    for (int i : binary_dec){
        if (n % i == 0){
            ans = ans | good(n / i);
        }
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    // one or not 
    cout << (good(n) ? "yes" : "no") << endl;
    
    
    
    // int n; cin >> n;
    // bool ans = true;
    // if (in_binary(n)) n = 0;
    // while (n > 1){
    //     // mod 11
    //     if (n % 11 == 0){
    //         n = n / 11;
    //     }
    //     // mod 10
    //     else if (n % 10 == 0){
    //         n = n / 10;
    //     }
    //     // in_binary
    //     else{
    //         // check if all values in bin 
    //         if (!in_binary(n)){
    //             ans = false;
    //         }
    //         break;
    //     }
    // }   
    
    // cout << (ans ? "yes" : "no") << endl;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // get all the values, its no more than 32 
    for (int i=2; i<100'007; i++){
        int cur = i;
        bool bad = false;
        while (cur){
            if (cur % 10 > 1) {bad = true; break;}
            cur /= 10;
        }
        if (!bad) binary_dec.push_back(i);
    }
    // dbg_out(binary_dec.size());
    int test = 1e9; cin >> test;
    while (test--) solve();
    return 0;
}

/*



*/