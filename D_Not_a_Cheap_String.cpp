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
    string s; cin >> s;
    int p; cin >> p;
    // count cur sum  
    int count = 0;
    for (int i=0; i<s.size(); i++){
        count += (s[i] - 'a' + 1);
    } 
    // delete from z to a
    if (count <= p){
        cout << s << endl;
        return;
    }
    // dbg_out(s, count, p);
    bool found = false;
    for (int i=26; i>=0; i--){
        for (int j=0; j<s.size(); j++){
            if (s[j] == i + 'a'){
                s[j] = '#';
                count -= (i + 1);
                if (count <= p){
                    found = true;
                    break;
                }
            }
        }
        if (found) break;
    }
    for (int i=0; i<s.size(); i++){
        if (s[i] != '#') cout << s[i];
    }cout << endl;
    // dbg_out(s);
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