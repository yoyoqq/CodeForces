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
    vector<int> a(n); for (int& x : a) cin >> x;
    set<int> use;
    for (int i=1; i<=n; i++){
        use.insert(i);
    }
    // algo
    bool poss = true;
    vector<int> ans(n, 0);
    for (int i=0; i<n; i++){
        if (i == 0 || a[i-1] < a[i]){
            ans[i] = a[i];
            use.erase(a[i]);
        }else{
            int mn = *use.begin(); 
            use.erase(use.begin());
            if (mn >= a[i]){
                poss = false;
                // break;
            }
            ans[i] = mn;
        }
    }
    // dbg_out(ans);
    if (!poss){
        cout << -1 << endl;
        return;
    }
    for (int num : ans) cout << num << " "; cout << endl;

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