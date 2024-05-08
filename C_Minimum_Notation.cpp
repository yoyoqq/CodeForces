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
    string s; cin >> s;
    int n = s.size();
    // last position of number
    map<char, int> last;
    for (int i=0; i<n; i++){
        last[s[i]] = i;
    }
    // from 0 to 9
    multiset<char> ans;
    int cur = 0;
    for (char c='0'; c<='9'; c++){
        if (last.find(c) == last.end()) continue;
        // iterate till last pos of c
        for (; cur <= last[c]; cur++){
            // if same or 9 
            if (s[cur] == c || s[cur] == '9')
                ans.insert(s[cur]);
            else
                ans.insert(s[cur]+1);
        }   
    }

    // output
    for (auto a : ans)
        cout << a;
    cout << nl;
    
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