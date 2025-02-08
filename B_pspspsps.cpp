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
    string s; cin >> s;


    bool a = 0, b = 0;
    for (int i=1; i<n; i++){
        if (s[i] == 's') a = true;
    }
    for (int i=0; i<n-1; i++){
        if (s[i] == 'p') b = true;
    }
    if (a && b) cout << "NO" << endl;
    else cout << "YES" << endl;
    
    
    
    // ! it fails with sspp , we can only have one s .... p, inside either s or p 
    // int sp = 0;
    // char prev = s[0];
    // int first_s = -1;
    // int first_p = -1;
    // int dots = 0;
    // int ps = 0;
    // for (int i=1; i<n; i++){
    //     if (prev == 's' && s[i] == 'p') sp++;
    //     if (s[i] == '.') dots++;
    //     if (prev == 'p' && s[i] == 's') ps++;
    //     if (s[i] == 'p') first_p = i;
    //     if (s[i] == 's' && first_s == -1) first_s = i;
    //     // update 
    //     if (s[i] != '.') prev = s[i];
    // }
    // // sp can only happen once and cannot be surrounded by dots, or all dots, or just one char  
    // bool poss = false;
    // if (sp == 1 && ((first_s == 0) || (first_p == n-1)) && ps == 0) poss = true;
    // if (dots == n) poss = true;
    // if ((first_p == -1 && first_s != -1) || (first_p != -1 && first_s == -1) || ps == 0) poss = true;
    // cout << (poss ? "YES" : "NO") << endl;
}
    
    // dbg_out(s, n);
    // sp once 
    // ps cannot happen
    // . X . cannot happen 
    // int sp = 0;
    // int ps = 0;
    // char prev = s[0];
    // int gaps = 0;
    // for (int i=1; i<n; i++){
    //     // count, update 
    //     if (s[i] == '.' && s[i] != s[i-1]) gaps++;
    //     if (prev == 's' && s[i] == 'p') sp++;
    //     if (prev == 'p' && s[i] == 's') ps++;
    //     if (s[i] != '.') prev = s[i];
    // }
    // // output 
    // bool poss = true;
    // // dbg_out(sp, ps);
    // // dbg_out();
    // if (s[0] == '.' &&  s[n-1] == '.' && sp) poss = false;
    // // if (sp >= 2 || ps >= 1) poss = false;
    // if (gaps >= 2) poss = false;
    // if (ps >= 1) poss = false;
    // cout << (poss ? "YES" : "NO") << endl;
// }

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