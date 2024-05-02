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

int power_2(int n){
    int count = 0;
    while (n > 0 && n % 2 == 0){
        count++;
        n = n / 2;
    }
    return count;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n, 0), b;
    int count = 0, extra = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        count += power_2(a[i]);
        int cur_extra = power_2(i + 1);
        extra += cur_extra;
        b.push_back(cur_extra);
    }
    // 2 base cases
    // 1. the count is greater or equals to the 2^n, it is possible to divide 
    if (count >= n){
        cout << 0 << nl;
        return;
    }
    // if even with the extras we cannot reach the number
    if (count + extra < n){
        cout << -1 << nl;
        return;
    }
    // else we can use the biggest extras to match count with n
    sort(b.rbegin(), b.rend());
    int res = 0;
    for (int x : b){
        count += x;
        res++;
        if (count >= n) break;
    }
    cout << res << nl;
    
    
    
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