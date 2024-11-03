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

int count(string& s, int i){
    int c = 0;
    if (i - 3 >= 0 && s[i-3] == '1' && s[i-2] == '1' && s[i-1] == '0' && s[i] == '0') c++;
    if (i - 2 >= 0 && i + 1 < s.size() && s[i-2] == '1' && s[i-1] == '1' && s[i] == '0' && s[i+1] == '0') c++;
    if (i - 1 >= 0 && i + 2 < s.size() && s[i-1] == '1' && s[i] == '1' && s[i+1] == '0' && s[i+2] == '0') c++;
    if (i + 3 < s.size() && s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0') c++;
    return c;
}

void solve(){
    string s; cin >> s;
    // count yes 
    // whenever we change chck behind if changb to no 
    // decrease count 
    int yes_count = 0;
    for (int i=3; i<s.size(); i++){
        if (s[i-3] == '1' && s[i-2] == '1' && s[i-1] == '0' && s[i] == '0')
            yes_count++; 
    }   
    int n; cin >> n;
    int idx; char num;
    for (int i=0; i<n; i++){
        cin >> idx >> num; 
        idx--;
        // change?
        if (s[idx] != num){
            // remove count 
            int prev = count(s, idx);
            yes_count -= prev;
            s[idx] = num;
            // create new counts 
            yes_count += count(s, idx);
        }
        // yes or no 
        cout << ((yes_count > 0) ? "yes" : "no") << endl;
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