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
    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    // check in binary the digits that are equal
    // if last digits are equal is divisible 
    ll k = 2; 
    while (true){
        set<ll> seen;
        for (auto& x : a){
            ll mod = x % k;
            seen.insert(mod);
        }
        if (seen.size() == 2){
            break;
        }
        k *= 2;
    }
    cout << k << endl;

    


    // bool even = false;
    // bool odd = false;
    // for (auto& x : a){
    //     int mod = x % 2;
    //     if (mod == 0) even = true;
    //     if (mod == 1) odd = true;
    // }

    // if (even && odd){
    //     cout << 2 << endl;
    // }
    // else{

    // }
    // else if (even){
    //     cout << 4 << endl;
    // }
    // else {
    //     cout << 3 << endl;
    // }

    // vector<int> ans;
    // for(int& x : a){
    //     ans.push_back(x % 3);
    // } 
    // dbg_out(ans);


    
    // int k = 2;
    // while (100){
    //     set<int> have;
    //     for (int& x : a){
    //         int mod = x % k;
    //         have.insert(mod);
    //     }
    //     if (have.size() == 2){
    //         break;
    //     }else{
    //         k++;
    //     }
    // }
    // cout << k << endl;
    
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