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
    map<string, int> freqA;
    map<string, int> freqB;
    for (int i=0; i<n; i++){
        string x; cin >> x;
        freqA[x]++;
    }
    for (int i=0; i<n; i++){
        string x; cin >> x;
        freqB[x]++;
    }
    // match a with b's 
    // dbg_out(freqA);
    // dbg_out(freqB);
    int count = 0;
    for (auto& [k, v] : freqB){
        v = max(0, v-freqA[k]);
        // dbg_out(k, v, freqA[k], max(0, v-freqA[k]));
        count += v;
    }
    // dbg_out(freqB);
    cout << count << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    // int test = 0; cin >> test;
    // while (test--) solve();
    return 0;
}