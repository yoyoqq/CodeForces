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
    vector<vector<int>> a;
    for (int i=0; i<n; i++){
        vector<int> temp;
        for (int j=0; j<4; j++){
            int x; cin >> x;
            temp.push_back(x);
        }
        a.push_back(temp);
    }
    // check if want or not 
    vector<vector<int>> aa;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (a[i][0] < a[j][0] && a[i][1] < a[j][1] && a[i][2] < a[j][2]){
                a[i][3] = INT_MAX;
                break;
            }    
        }
    }
    // dbg_out(a);
    // get the smallest 
    int idx = 1; 
    int mn = a[0][3];
    for (int i=1; i<n; i++){
        if (mn > a[i][3]){
            idx = i + 1;
            mn = a[i][3];
        }
    }
    cout << idx << nl;
    
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