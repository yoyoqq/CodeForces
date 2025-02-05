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
    vector<int> a(n); for (int& x : a) cin >> x;
    // make any type of grpah 
    int count = 0;
    int first = -1;
    int second = -1;
    for (int i=0; i<n; i++){
        if (a[i] == a[0]) count++;
        if (first == -1){
            first = i;
        }
        else if (second == -1 && a[i] != a[first]){
            second = i;
        }
    }   
    // the only way to be false is if all the values are same
    if (count == n){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    // conenct all to first val, unless its same
    for (int i=1; i<n; i++){
        // connet to the second val
        if (a[i] == a[first]){
            cout << i+1 << " " << second+1 << endl;
        }else{
            cout << i+1 << " " << first+1 << endl;
        }
    }
    
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