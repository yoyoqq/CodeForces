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
    vector<vector<int>> arr(n, vector<int>(n));
    // 
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    // dbg_out(arr);
    // get only the bits that are 1's in all the i, j
    vector<int> res(n, (1<<30)-1);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i == j) continue;
            res[i] = res[i] & arr[i][j];
            res[j] = res[j] & arr[i][j];
        }
    }
    bool poss = true;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i == j) continue;
            if (arr[i][j] != (res[i] | res[j])){
                poss = false;
                break;
            }
        }
    }
    if (!poss){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        for (int& x : res){
            cout << x << " ";
        }
        cout << endl;
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