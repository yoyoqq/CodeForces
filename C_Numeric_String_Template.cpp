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
    int m; cin >> m;
    for (int i=0; i<m; i++){
        string s; cin >> s;
        bool yes = true;
        if (s.size() != n) {cout << "no" << endl; continue;}
        unordered_map<char, int> for_char;
        unordered_map<int, char> for_int;
        for (int j=0; j<s.size(); j++){
            // for_char, found in 
            if (for_char.find(s[j]) != for_char.end()){
                // check if s[j] != forchar s[j] 
                if (for_char[s[j]] != a[j]) yes = false;
            }else{
                for_char[s[j]] = a[j];
            }
            // for_int
            if (for_int.find(a[j]) != for_int.end()){
                // check if s[j] != forchar s[j] 
                if (for_int[a[j]] != s[j]) yes = false;
            }else{
                for_int[s[j]] = a[j];
            } 
        }
        if (yes) cout << "yes" << endl;
        else cout << "no" << endl;
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