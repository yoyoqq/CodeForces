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
    string s; cin >> s;
    // less than 2 chars 
    vector<int> freq(3, 0);
    for (int i=0; i<n; i++){
        if (s[i] == '<') freq[0]++;
        if (s[i] == '>') freq[1]++; 
        if (s[i] == '-') freq[2]++;
    }
    if (freq[0] == 0 || freq[1] == 0){
        cout << n << endl;
        return;
    }
    if (n == 2 && (s == "<>" || s == "><")){
        cout << 0 << endl; 
        return;
    }
    // evaluate if can come back by !><
    int count = 0;
    for (int i=0; i<n; i++){
        // char left = i-1 == -1 ? s[n-1] : s[(i-1)%n];
        char mid = s[i];               
        char right = s[(i+1)%n];
        if (right == '-' || mid == '-') count++;
        // dbg_out(mid, right, count);
    }
    cout << count << endl;
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