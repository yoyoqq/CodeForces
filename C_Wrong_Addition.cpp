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
    string a, s; cin >> a >> s;
    /*
    steps 
        leading zeroes 
        right to left
        last digit a + b to ans 
        each step 

        simulate the iterations
        from s check the s[i], s[i+1]
        check if s[i] > a[i]
        else{
            add one num more 
        }
    */
    string res = "";
    int j = s.size()-1;
    bool valid = true;
    for (int i=a.size()-1; i>=0; i--){
        // base case
        if (j < 0){
            valid = false;
            break;
        }
        int s_digit = s[j] - '0';
        int a_digit = a[i] - '0';
        if (s_digit >= a_digit){
            res += to_string(s_digit-a_digit);
            j--;
        }else{
            if (j == 0 || s[j-1] != '1'){
                valid = false; break;
            }
            int comb = (s[j-1] -'0') * 10 + s_digit;
            res += to_string(comb - a_digit);
            j -= 2;
        }
    }
    //
    
    
    while (j >= 0) {
    res += s[j];
    j--;
    }
    dbg_out(a, s, res);
    // Remove leading zeros
    while (!res.empty() && res.back() == '0') {
        res.pop_back();
    }
    if (res.empty() || !valid) {
        cout << -1 << nl;
    } else {
        reverse(res.begin(), res.end());
        cout << res << nl;
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