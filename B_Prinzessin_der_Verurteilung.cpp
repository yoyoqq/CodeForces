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

string rev(int i){
    if (i == 0) return "";
    else return rev((i-1)/26) + (char)((i-1)%26+'a');
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    // 
    // find smallest substr   
    // if n <= 1000
    // if one char n = 26
    // if two char n = 26 * 26 = 676
    // if three char n = 26 * 26 * 26 = 17500 (hiwhch is smaller than n)
    // when is 3, there are less permuations than n
    // 26^3 >= n, thus brute froce


    for (int i=1; ;i++){
        if (s.find(rev(i)) == s.npos){
            cout << rev(i) << nl;
            return;
        }
    }
    

    // // 1 
    // bool a[26] = {false};
    // for (int i=0; i<n; i++){
    //     if (a[s[i]-'a'] == false){
    //         a[s[i] - 'a'] = true;
    //     }
    // }
    // for (int i=0; i<26; i++){
    //     if (a[i] == false){
    //         char out = i + 'a';
    //         cout << out << nl;
    //         return;
    //     }
    // } 

    // // 2 
    // a[26] = {false};
    // for (int i=1; i<n; i++){
    //     if (a[i] == 'a' && a[i-1] == 'a'){
    //         a[s[i] - 'a'] = true;
    //     }
    // }
    // for (int i=0; i<26; i++){
    //     if (a[i] == false){
    //         char out = i + 'a';
    //         cout << out + out << nl;
    //         return;
    //     }
    // } 


    
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