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
    string s; cin >> s;

    stack<int> stack;
    int ans = 0;
    // if balance == 0: opening 
    // else closing 
    for (int i=0; i<n; i++){
        char c = s[i];
        if (c == '_'){
            if (stack.empty()) c = '(';
            else c = ')';
        }
        if (c == ')'){
            ans += i - stack.top(); 
            stack.pop();
        }else{
            stack.push(i);
        }
    }
    cout << ans << nl;
    
    
    // // stack<int> help;
    // int count = 0;
    // for (int i=0; i<n; i++){
    //     // even
    //     if (i % 2 == 0){
    //         // open 
    //         if (s[i] == '('){
    //             // push to stack no other option
    //             stack.push(i);
    //         }
    //         // close
    //         else{
    //             // check if open in stack
    //             if (stack.size()) {count += i - stack.top(); stack.pop();}
    //             // otherwise need to close with helper
    //             else{
    //                 count += i - help.top();
    //                 help.pop();
    //             }
    //         }
    //     }
    //     // odd
    //     else{
    //         help.push(i);
    //     }
    // }
    // cout << count << nl;
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