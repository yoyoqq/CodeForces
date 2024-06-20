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

void solve(){
    int n; cin >> n;
    char c; cin >> c;
    string s; cin >> s;
    // check if all equal 
    bool all_equal = true;
    for (char x : s){
        if (x != c){
            all_equal = false;
            break;
        }
    }
    if (all_equal){
        cout << 0 << nl;
        return;
    }

    // single pos 
    int ans = 0;
    int k = -1;
    for (int i=n/2+1; i<=n; i++){   // cut, get second half, nothing is div by that, unique division
        if (s[i-1] == c){
            ans = 0;
            k = i;
            break;
        }
    }
    
    // output 
    if (k != -1) {
        cout << 1 << nl;
        cout << k << nl;
    } else {    // last 2 are not divisible by anything before 
        cout << 2 << nl;
        cout << n << " " << n - 1 << nl;
    }

    
    
    
    
    // // 
    // // check what chars differ
    // // even -> odd: 3 (size 3)
    // // odd -> even: 2 
    // int even = 0, odd = 0; 
    // for (int i=0; i<n; i++){
    //     if (s[i] != c){
    //         if ((i + 1) % 2 == 0){
    //             even++;
    //         }else{
    //             odd++;
    //         }
    //     }
    // }
    // // output 
    // int count = (even != 0) + (odd != 0);
    // cout << count << nl;
    // if (count == 0) return;
    // if (odd) cout << 2 << " ";
    // if (even) cout << 3 << " ";
    // cout << nl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 0; cin >> test;
    while (test--) solve();
    return 0;
}

/*



*/