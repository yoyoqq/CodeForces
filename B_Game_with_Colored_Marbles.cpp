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
    map<int, int> freq;
    for (auto& x : a) freq[x]++;
    
    int one_counts = 0;
    for (auto& [k, v] : freq){
        if (v == 1) one_counts++;
    }
    int rest = freq.size() - one_counts;
    one_counts = (one_counts + 1) / 2;
    // dbg_out(freq, rest, one_counts);
    cout << one_counts * 2 + rest << endl;

    
    
}
// for (int& val : b){
//     if (turn && val == 1) alice++;  // all values of same colour
//     bool once = true;
//     while (val){
//         if (turn && ) alice++;
//         turn = !turn;
//         val--;
//     }
//     // dbg_out(alice);
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