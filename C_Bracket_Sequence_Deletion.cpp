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
    int count = 0;
    int left = 0;
    while (left + 1 < n){
        // regular || palindrome
        if (s[left] == '(' || s[left] == ')' && s[left+1] == ')'){
            left += 2;
        }
        // long palindrome
        else{
            int right = left + 1;
            while (right < n && s[right] != ')'){
                right++;
            }
            if (right >= n) break;
            left = right + 1;
        }
        // after finalizing operation
        count++;
    }
    dbg_out(count, n, left);
    cout << count << " " << n - left << nl;
    
    
    // int n; cin >> n;
    // string s; cin >> s;

    // // 
    // map<char, char> m = {'(': ')', ')': '('};
    // stack<char> s;
    // int count = 0;
    // for (char& c : s){
    //     // 4 possibiilities 
    //     // ()   ))   ((   )(
    //     if (c == ')'){
    //         if (s.size() != 0){
    //             // regular 
    //             if (s.top() == '('){
    //                 count++;
    //                 s.pop();
    //             }
    //             // palindrome  
    //             else if (s.top() == ')'){
    //                 count++;
    //                 s.pop();
    //             }
    //             else{

    //             }
    //         }else{
    //             s.push(c);
    //         }
    //     }
    // }
    
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