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
    ll n; cin >> n;
    string s; cin >> s;

    ll eye = 0, mouth = 0;
    for (char c : s){
        if (c == '_'){
            mouth++;
        }else{
            eye++;
        }
    }
    // dbg_out(eye, mouth);
    if (eye <= 1 || mouth == 0){
        cout << 0 << endl;
        return;
    }
    ll count = 0;
    ll times = eye/2 + (eye % 2 == 1);
    for (ll i=0; i<times; i++){
        count += (eye/2) * mouth;
    }
    cout << count << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll test = 0; cin >> test;
    while (test--) solve();
    return 0;
}
