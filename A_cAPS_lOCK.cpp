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
    string a; cin >> a;
    // on if : 
    //      1. only uppercase
    //      2. all uppercase except first   

    int count = 0;
    int n = a.size();
    for (int i=0; i<a.size(); i++){
        if (a[i] < 97) count++;  
    }
    // if in the rules, change all letters lower-upper, upper-lower 
    if (count == n || count == n-1 && a[0] > 96){
        for (int i=0; i<n; i++){
            if (a[i] > 96){
                a[i] = a[i] - 32;
            } 
            else{
                a[i] = a[i] + 32;
            }
        }
    }
    cout << a << endl;
    
    //  dbg_out((int)'a', (int)'A', (char)96);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    // int test = 1e9; cin >> test;
    // while (test--) solve();
    return 0;
}

/*



*/