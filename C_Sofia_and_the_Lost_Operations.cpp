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
    vector<int> a(n), b(n);
    for (int& x : a) cin >> x; for (int& x : b) cin >> x;
    int m; cin >> m;
    vector<int> c(m); for(int& x : c) cin >> x;

    // check if can chagne a to b
    bool poss = true;
    
    map<int, int> freqA, freqB;
    for (int i=0; i<n; i++){
        // freqA[a[i]]++;
        freqB[b[i]]++;
    }
    for(int i=0; i<m; i++){
        freqA[c[i]]++;
    }

    // last num m in b 
    if (freqB.find(c[m-1]) == freqB.end()) poss = false;

    // ? a + c >= b 
    // for (auto [k, v] : freqA){
    //     if (v < freqB[k]) poss = false;
    // }
     
    // use all the nums 
    bool used = false;
    for (int i=0; i<n; i++){
        if (a[i] != b[i]){
            if (freqA.find(b[i]) == freqA.end() || freqA[b[i]] == 0){
                poss = false;
                break;
            }
            used = true;
            freqA[b[i]]--;
        }
    }
    
    cout << (poss ? "YES" : "NO") << endl;
    
    
    
    
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