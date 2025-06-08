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
    string x, y; cin >> x >> y;
    reverse(all(x));
    reverse(all(y));
    int posx = 0;
    int posy = 0;
    for (int i=0; i<y.size(); i++){
        if (y[i] == '1'){
            posy = i;
            break;
        }
    }
    for (int i=posy; i<x.size(); i++){
        if (x[i] == '1'){
            posx = i;
            break;
        }   
    }
    // posx = x.find('1', posy);  // index of first '1' in x starting from posY

    // dbg_out(x, y, posx, posy);
    cout << (posx-posy) << endl;
    // cout << max(0, int(x.size()) - posx - (int(y.size()) - posy)) << endl;
    // cout << max(0, ((int)(x.size()-posx)-(y.size()-posy))) << endl;
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