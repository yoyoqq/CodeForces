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

ll gcd(ll a, ll b)
{
    if (b==0)return a;
    return gcd(b, a % b);   
}


void solve(){
    int n; cin >> n;
    vector<int> a(n); for(int& x : a) cin >> x;
    // 
    bool even = false, odd = false; 
    int mx = 0;
    for (int i=0; i<n; i++){
        if (a[i]% 2 == 0) even = true;
        if (a[i]% 2 == 1) odd = true;
        mx = max(mx, a[i]);
    } 
    // if odd and even alternate, impossible 
    if (odd && even){
        cout << -1 << endl;
        return;
    }


    vector<int> op;
    for (int i=29; i>=0; i--){
        op.push_back(1<<i);
    }
    // dbg_out(op);
    if (even) op.push_back(1);
    cout << op.size() << endl;
    for (int i=0; i<op.size(); i++){
        cout << op[i] << " ";
    }
    cout << endl;
    
    
    // reduce from 2**30
    // vector<bool> arr(31, 0);
    // int count = 0;

    // for (int j=30; j>=0; j--){
        
    //     if (mx >= (1<<j)){
    //         count++;
    //         arr[j]= true;
    //     }
    // }

    // cout << count << endl;
    // for (int i=30; i>=0; i--){
    //     if (arr[i] == 1){
    //         cout << (1 << i) << " ";
    //     }
    // }
    // cout << endl;
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