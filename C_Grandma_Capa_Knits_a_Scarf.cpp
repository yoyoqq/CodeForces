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
    // iterate from a - z, check if palindrome 
    int n; cin >> n;
    string s; cin >> s;
    int ans = n + 1;

    for (int i=0; i<26; i++){
        int left = 0, right = n - 1, count = 0;
        // check palindrome 
        while (left <= right){
            if (s[left] == s[right]){
                left++;
                right--;
            }
            else if (s[left] == char('a'+i)){
                left++;
                count++;
            }
            else if (s[right] == char('a'+i)){
                right--;
                count++;
            }
            else{
                count = n + 1;
                break;
            }
        }
        ans = min(ans, count);
    } 
    if (ans == n + 1) ans = -1;
    cout << ans << nl;
}

// int is_palindrome(string& ss, char c){
//     // delete char
//     string ans = "";
//     int deleted = 0;
//     for (char& s : ss){
//         if (s == c) {
//             deleted++;
//             continue;
//         }
//         ans += s;
//     }
//     // check palindrome     
//     for(int i=0; i<ans.size()/2; i++){
//         if (ans[i] != ans[ans.size()-i-1]){
//             deleted = 1e9;
//             break;
//         }
//     }
//     return deleted;
// }

// void solve(){
//     int n; cin >> n; 
//     string s; cin >> s;
//     // if already palindrome 
//     if (is_palindrome(s, '@')){
//         cout << 0 << nl;
//         return;
//     }
//     // delete one char     
//     bool chars[26] = {false};
//     for (int i=0; i<n; i++){
//         chars[s[i]-'a'] = true; 
//     }
//     // delete char 
//     int ans = 1e9;
//     for (char i='a'; i<='z'; i++){
//         dbg_out(i);
//         if (chars[i-'a'] == false) continue;
//         int count = is_palindrome(s, i);
//         ans = min(ans, count);
//     }
//     cout << (ans != 1e9 ? ans : -1) << nl;
// }

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