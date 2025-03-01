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
    int n, m; cin >> n >> m;

    // beuty nubmer
    if (m == 1) cout << 0 << endl;
    else if (n > m - 1) cout << m << endl;
    else cout << n + 1 << endl;
    // calc matrix
    for (int i=0; i<min(m-1, n); i++){
        for (int j=0; j<m; j++){
            cout << (j+i) % m << " ";
        }
        cout << endl;
    }

    if (n > m - 1){
        for (int i=m-1; i<n; i++){
            for (int j=0; j<m; j++){
                cout << j << " ";
            }
        }cout << endl;
    }
    
    
    // if (n == 1){
    //     cout << m << endl;
    //     for (int i=0; i<m; i++){
    //         cout << i << " ";
    //     }cout << endl;
    //     return;
    // }
    // else if (m == 1){
    //     cout << 0 << endl;
    //     for (int i=0; i<n; i++){
    //         cout << 0 << endl;
    //     }   
    //     return;
    // }
    // vector<vector<int>> a(m-1, vector<int>(m));
    // int rem_rows = n-(m-1);
    // // from m-1 put val in 
    // for (int i=0; i<a.size(); i++){
    //     int cur = i+1;
    //     for (int j=0; j<m; j++){
    //         a[i][j] = cur;
    //         cur = (cur+1) % m;
    //     }
    // }
    // // vector<int> last_row = a[a.size()-1];
    // for (int i=0; i<rem_rows; i++){
    //     a.push_back(a.back());
    // }
    // // dbg_out(a);
    // // dbg_out();
    // cout << min(n+1, m) << endl;
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m; j++){
    //         cout << a[i][j] << " ";
    //     }cout << endl;
    // }
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
