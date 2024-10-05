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

void no(){
    cout << -1 << nl;
}

void solve() {
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  for (int times = 0; times < 2; times++) {
    for (int i = 0; i < (int) s.size(); i++) {
      int j = (int) s.size() - i - 1;
      if (s[i] != '?') {
        if (s[j] == '?') {
          s[j] = s[i];
        } else if (s[i] != s[j]) {
          no();
          return;
        }
      }
    }
    reverse(s.begin(), s.end());
  }
  a -= count(s.begin(), s.end(), '0');
  b -= count(s.begin(), s.end(), '1');
  int ques = count(s.begin(), s.end(), '?');
  bool emptyMid = (s.size() % 2 == 1 && s[s.size() / 2] == '?');
  if (a < 0 || b < 0 || a + b != ques || (emptyMid && a % 2 == 0 && b % 2 == 0)) {
    no();
    return;
  }
  if (a % 2 == 1 || b % 2 == 1) {
    int i = s.size() / 2;
    if (s[i] != '?') {
      no();
      return;
    }
    s[i] = (a % 2 == 1 ? '0' : '1');
    if (a % 2 == 1) {
      a--;
    } else {
      b--;
    }
  }
  if (a % 2 == 1 || b % 2 == 1) {
    no();
    return;
  }
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '?') {
      int j = s.size() - i - 1;
      if (a > 0) {
        a -= 2;
        s[i] = s[j] = '0';
      } else {
        b -= 2;
        s[i] = s[j] = '1';
      }
    }
  }
  cout << s << endl;
}

// void solve(){
//     int a, b; cin >> a >> b;
//     string s; cin >> s;
//     int n = s.size();
//     //
//     // two passes
//     // 1. the nums that already have num, 1 to 1, 0 to 0
//     // 5 -> n/2: 2  n/2+1      0 1 2 3
//     for (int i=0; i<n/2; i++){
//         int j = n - 1 - i;
//         if (s[i] )
//         // one side, other not 
//         bool changed = false;
//         if (s[i] == '?' && s[j] != '?') {
//             s[i] = s[j];
//             changed = true;
//         } else if (s[i] != '?' && s[j] == '?') {
//             s[j] = s[i];
//             changed = true;
//         }

//         if (changed){
//             if (s[i] == '0'){
//                 a--;
//             }else{
//                 b--;
//             }
//         }
//     }
//     if (n % 2 == 1){
//         int mid = n / 2;
//         if (s[mid] == '?'){
//             if (a > b){
//                 s[mid] = '0';
//                 a--;
//             }else{
//                 s[mid] = '1';
//                 b--;
//             }
//         }
//     }

//     // 2. fill the rest using a or b
//     for (int i=0; i<n/2; i++){
//         if (s[i] == '?'){
//             int j = n - 1 - i;
//             if (a > b){
//                 s[i] = '0';
//                 s[j] = '0';
//                 a -= 2;
//             }else{
//                 s[i] = '1'; 
//                 s[j] = '1'; 
//                 b -= 2;
//             }
//         }
//     }

//     // res 
//     if (a < 0 || b < 0){
//         cout << -1 << nl;
//     }else{
//         cout << s << nl;
//     }

//     // o(n), o(1)
// }

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