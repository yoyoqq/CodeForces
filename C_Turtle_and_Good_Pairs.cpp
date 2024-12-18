
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
    string s; cin >> s;
    

    vector<int> a(26);
    for (int i=0; i<n; i++){
        a[s[i]-'a']++;
    }
    string res = "";
    // append to get max difference 
    while (n){
        for (int i=0; i<26; i++){
            if (a[i]){
                res += (char)(i + 'a');
                a[i]--;
                n--;
            }
        }
    }
    cout << res << endl;

    
    // 
    // separate as much as possible the string 
    // vector<int> freq(26);
    // for (char& c : s){
    //     freq[(int)(c - 'a')]++;
    // }
    // string res = s;
    // int count = s.size();
    // int idx = 0;
    // for (int i=0; i<n; i+=2){
    //     while (freq[idx] == 0){
    //         idx++;
    //     }
    //     res[i] = (idx + 'a');
    //     freq[idx]--;
    // }
    // for (int i=1; i<n; i+=2){
    //     while (freq[idx] == 0){
    //         idx++;
    //     }
    //     res[i] = (idx + 'a');
    //     freq[idx]--;
    // }
    
    // cout << res << endl;

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