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
    int a; cin >> a;


    // https://www.youtube.com/watch?v=nlpH0QgK_gg
    // a = (n - 2) 180 /n 
    // n*a - 180n = - 360
    // (n * a) - 180n / - 60 = -360/ -60
    // _ = X / _ if division good 

    int x = a - 180; 
    if (-360 % x == 0){
        cout << "YES" << endl;
        // cout << -360 / x << endl;
    }else{
        cout << "NO" << endl;
    }

    
    
    // angle == a
    // what polygon can we make 
    // equilateral triangle 
    // whats the min angle of a polygon    
    
    // formula to find angles based on n of sides: 
    // (n - 2) * (180 / n)
    // bool ans = false;
    // for (int i=2; i<1000; i++){
    //     // if (180 % i != 0) continue;
    //     int x = (i-2) * (180 / i);
    //     if (x == a){
    //         ans = true;
    //         break; 
    //     }
    // }
    // cout << (ans ? "YES" : "NO") << endl;
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