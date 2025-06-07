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
    vector<int> arr(n); for (int& x : arr) cin >> x;
    // 
    int denied = 0;
    int c = 0;
    for (int i=0; i<n; i++){
        if (arr[i] == 1){
            // 1 seat
            if (a) a--;
            // 2s v
            else if (b){
                c++;
                b--;
            }
            // 2s o
            else if (c) c--;
            // denied 
            else denied++;
        }
        // two pp 
        else{
            if (b == 0) denied += 2;
            else{
                b--;
            }
        }
    }
    
    cout << denied << endl;
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