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


string calc(int s){
    string ans = "";
    while (s > 0){
        ans += (s % 2 == 0 ? '0' : '1');
        s = s / 2;
    }
    reverse(all(ans));
    return ans;
}


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int& x : a) cin >> x;
    
    // observation
    //      1. and is always bigger if the max bit is the  same 
    map<int, int> freq;
    for (int i=0; i<n; i++){
        // ! if using bitset 8, returns WA, using bitset of 32 
        string to_binary = bitset<32>(a[i]).to_string();
        // string to_binary = calc(a[i]);
        int idx = 0;
        for (int i=0; i<to_binary.size(); i++){
            if (to_binary[i] == '1'){
                idx = i;
                break;
            }
        }
        freq[idx]++;
        // freq[to_binary.size() - idx - 1]++;
    }
    // dbg_out(freq);
    ll count = 0;
    for (auto [k, v] : freq){
        if (v >= 2){
            // to calculate all pairs combinatorics : n * (n-1) / 2
            count += 1LL*v*(v-1)/2; 
        }
    }
    cout << count << endl;
        
    // 
    // sort(all(a));
    // vector<string> in_bits(n);
    // for(int i=0; i<n; i++){
    //     in_bits[i] = bitset<8>(a[i]).to_string();
        // in_bits[i] = to_binary(a[i]);
    // }
    // dbg_out(a);
    // dbg_out(in_bits);
    // dbg_out();
    
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