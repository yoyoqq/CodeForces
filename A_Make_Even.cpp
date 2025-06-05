#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


int position(int num){
    int pos = -1;
    int idx = 0; 
    while (num){
        // dbg_out(num, num % 2 == 0);
        if (num % 2 == 0){
            pos = idx;
        }
        idx++;
        num /= 10;
    }
    if (pos == -1) return -1;
    else if (pos == idx-1) return -2;
    return 1;
}

void solve(){
    int n; cin >> n;
    if (n % 2 == 0){
        cout << 0 << endl;
        return;
    }
    int pos = position(n);
    if (pos == -1) cout << -1 << endl;
    else if (pos == -2) cout << 1 << endl;
    else cout << 2 << endl;

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