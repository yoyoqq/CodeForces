#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


void solve(){
    int n; cin >> n;
    vector<int> a(n); for(int& x : a) cin >> x;
    sort(all(a));
    // brute force is too slow 
    // eliminate one 
    // save bits on array, use the count - negation to get xor 
    // from the array sum up all the values in binary

    // count active bits 
    vector<int> tbits(32, 0);
    for (int num : a){
        for (int i=0; i<32; i++){
            if (num & (1<<i)){
                tbits[i]++;
            }
        }
    }
    dbg_out(a, tbits);
    // for each number take off 
    int size = n-1;
    ll res = 0;
    for (int i=0; i<n; i++){
        vector<int> bits = tbits;
        // take off a[i]
        for (int j=0; j<32; j++) if (a[i] & (1<<j)) bits[j]--;
        // if a[i] bit is on, reverse count (size - bits[i])
        for (int j=0; j<32; j++){
            if (a[i] & (1<<j)){
                bits[j] = size - bits[j];
            }
        }
        // count the sum, bin to dec 
        ll cur_count = 0;
        ll exp = 1;
        for (int j=0; j<32; j++){
            // dbg_out(exp*bits[i]);
            cur_count += (exp * bits[j]);
            exp *= 2;
        }
        res = max(res, cur_count);
    } 
    cout << res << endl;
    
    // ll sm = 0;
    // for (int i=0; i<n; i++){
        // sm += (a[i] ^ a.back());
        // sm += (a[i] ^ 8); 
    // }
    // cout << sm << endl;
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
