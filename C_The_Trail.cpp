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
    // observation
    // when D -> row    R -> col 
    // make to 0 
    // update value to make to 0
    // at the end the sum of all rows/cols == 0
    // why is the last val 0 as well 

    // sum of row, col 
    // update each iteration 
    ll n, m; cin >> n >> m;
    string path; cin >> path;
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    vector<ll> row(n), col(m);
    for (ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin >> a[i][j];
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }
    // iterate path update weights
    // dbg_out(row, col); 
    ll i=0, j = 0;
    for (char step : path){
        if (step == 'D'){
            // row
            ll target = row[i] * -1;
            row[i] += target;
            a[i][j] = target;
            col[j] += target;
            i++;
        }else{
            // col 
            ll target = col[j] * -1;
            col[j] += target;
            a[i][j] = target;
            row[i] += target;
            j++; 
        }
    }
    // last value 
    a[i][j] = row[i] * -1;
    for (ll i=0; i<n; i++){
        for (ll j=0; j<m; j++){
            cout << a[i][j] << " ";
        }cout << endl;
    }
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
