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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int b_count = 0;
    for (char c : s){
        if (c == 'B') b_count++;
    }
    // 
    if (b_count == k){
        cout << 0 << endl;
    }
    // add 
    else if (b_count < k){
        for (int i=0; i<n; i++){
            if (s[i] == 'A') b_count++;
            if (b_count == k){
                cout << 1 << endl << (i + 1) << " " << 'B' << endl;
                return;
            }
        }
    }
    // delete
    else{
        for (int i=0; i<n; i++){
            if (s[i] == 'B') b_count--;
            if (b_count == k){
                cout << 1 << endl << (i + 1) << " " << 'A' << endl;
                return;
            }
        }
    }
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