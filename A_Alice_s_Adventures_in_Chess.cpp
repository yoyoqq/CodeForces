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
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    int x = 0;
    int y = 0;
    bool poss = false;
    // repeat 20 times (simulation)
    for (int i=0; i<20; i++){ // 20 times since if NE, we advance one move, max(10) for n a b
        for (int j=0; j<s.size(); j++){
            if (s[j] == 'N') y++;
            if (s[j] == 'S') y--;
            if (s[j] == 'E') x++;
            if (s[j] == 'W') x--;
            if (x == a && b == y) poss= true;
        }
    }
    cout << (poss ? "YES" : "NO") << endl;
    
    // map<char, int> freq;
    // for(char c : s) freq[c]++;
    // // E W       S N 
    // freq['E'] -= freq['W'];
    // freq['N'] -= freq['S'];
    
    // bool positive = true;
    // if (freq['E'] < 0 || freq['N'] < 0) positive = false;
    // // up, right, perpendicular 
    // bool poss = false;
    // if (a == 0 && freq['N'] == 0 && b % freq['E'] == 0) poss = true;
    // else if (a == b && freq['E'] )
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
