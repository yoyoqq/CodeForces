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
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size(); 
    int ans = n + m;
    // two pointers, check if same 
    for (int i=0; i<m; i++){
        int j = i;
        for (char& c : a)
            if (c == b[j]) j++;
        ans = min(ans, n + m - (j - i));   
    }
    cout << ans << nl;
    
    
    // string a, b; cin >> a >> b;
    // new string X where 
    // a -> substring
    // b -> subsequence

    /* idea 
        substring never gonna change
        left -> a + b
        right -> b + a;
        middle -> find common chars from a in b
    */ 
    
    // left side, use two pointers 
    // int j = b.size() - 1;
    // for (int i=a.size(); i>=0; i--){
    //     if (j >= 0 && a[i] == b[j]) j--;
    // } 
    // string left = b.substr(0, j+1) + a;
    // // right side 
    // j = 0;
    // for (int i=0; i<a.size(); i++){
    //     if (j < b.size() && a[i] == b[j]) j++;
    // }
    // string right = a + b.substr(j);

    // // dbg_out(left, right); 
    // // cout << min(left.size(), right.size()) << nl;

    // // for middle ? dp? brute force 
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