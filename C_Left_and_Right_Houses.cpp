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

const int MX = 200'000 + 1;
int a[MX];

int count_sum_of_digits(int num){
    int sm = 0;
    while (num != 0){
        sm += num % 10;
        num = num / 10;
    }
    return sm;
}

void solve(){
    // get test cases
    int n; cin >> n;
    string a; cin >> a;
    //
    vector<int> suf(n + 1, 0);
    for (int i=n-1; i>=0; i--){
        suf[i] = suf[i+1] + (a[i] == '1');
    }
    int pref = 0;

    int ans = -1;
    int dist = n * 2;

    for (int i=0; i<n+1; i++){
        if (pref >= (i + 1) / 2 && suf[i] >= (n - i + 1) / 2 && dist > abs(n - 2 * i)){
            dist = abs(n - 2 * i);
            ans = i;
        }
        if (i != n){
            pref += (a[i] == '0');
        }
    }
    cout << ans << nl;
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // precomputation 
    a[0] = 0;
    for (int i=1; i<MX; i++){
        a[i] = count_sum_of_digits(i) + a[i-1];
    }
    
    int test = 1e9; cin >> test;
    while (test--) solve();
    return 0;
}

/*

other methods:
brute force for each test case -> too slow 
    precomputation 

time:
    n * n (precomp)
    finding o(1)

    memory (n)

*/