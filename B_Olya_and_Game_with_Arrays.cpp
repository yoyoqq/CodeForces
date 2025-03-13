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
    vector<pair<int, int>> a;
    for (int i=0, nn; i<n; i++){
        cin >> nn;
        int first_mn = 1e9;
        int second_mn = 1e9;
        for (int j=0, x; j<nn; j++){
            cin >> x;
            if (x < first_mn){
                second_mn = first_mn;
                first_mn = x;
            }else if (x < second_mn){
                second_mn = x;
            }
        }
        a.push_back({first_mn, second_mn});
    }    
    // put the mn to the first pair 
    sort(all(a), [](pair<int, int> x, pair<int, int> y){
        return x.second < y.second;
    });
    ll ans = 0;
    int mn = 1e9;
    for (int i=0; i<n; i++){
        if (i == 0){
            mn = a[i].first;
        }
        else{
            mn = min(mn, a[i].first);
            ans += a[i].second;
        }
    }
    // dbg_out(a);
    // dbg_out(ans, mn);
    cout << ans + mn << endl;
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