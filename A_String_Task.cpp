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
    // 3 rules
    // all upper to lower 
    string s; cin >> s;
    for (int i=0; i<s.size(); i++){
        if (s[i] )
        if (isupper(s[i]))
            s[i] = tolower(s[i]); 
        
    }
    dbg_out(s);

    // delete vowels 
    string vowels = "aoyeui";
    string no_vowels;
    for (int i=0; i<s.size(); i++){
        if (vowels.find(s[i]) != string::npos) continue;
        no_vowels += s[i];
    }
    dbg_out(no_vowels);
    // before consonant .
    for (auto& c : no_vowels){
        cout << '.' << c;
    }
    cout << endl;
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // int test = 1e9; cin >> test;
    // while (test--) solve();
    solve();
    return 0;
}

/*



*/