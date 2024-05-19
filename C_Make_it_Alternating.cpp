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

int mod = 998'244'353;

void upd(int& a, int b){
    a = (a * 1LL * b) % mod;
}

void solve(){
    string s; cin >> s; 
    int res = 1;
    int k = s.size(); 
    int n = s.size(); 
    for (int l=0; l<n;){
        int r = l + 1;
        while (r < n && s[l] == s[r]){
            r++;
        }
        upd(res, r - l);    // how many nums are in between 
        k--;
        l = r;
    }
    for (int i=1; i<=k; i++){
        upd(res, i);
    }
    cout << k << " " << res << nl;
    
    
    
    // string s; cin >> s;
    // // min operations
    // int mn = 0;
    // int cnt = 1;
    // int seq = 0;
    // bool prev_one = (s[0] == '1') ? true : false;
    // for (int i=1; i<s.size(); i++){
    //     // prev is one, cur is one 
    //     // prev is zero, cur is zero
    //     if (prev_one == true && s[i] == '1' || prev_one == false && s[i] == '0'){
    //         mn++;
    //         cnt++;
    //         seq += cnt;
    //     }
    //     // else, good, change sign
    //     else{
    //         prev_one = (s[i] == '1');
    //         cnt = 1;
    //     }
    // }
    // // if (cnt != 1){
    // //     seq += cnt;
    // // }
    // cout << mn << " " << seq << nl;
    // // shortest seq 
    // int mod = 998244353;

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