#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


const int MOD = 1e9+7;

void solve(){
    // pattern is -> 
    // count on how much can go to right 
    // ans *= (times+1)     // number of swaps permutations possible 
    int n; cin >> n;
    vector<int> a(n); for(int& x : a) cin >> x;
    vector<int> b(n); for(int& x : b) cin >> x;
    sort(all(a));
    sort(b.begin(), b.end());
    // not possbile
    for (int i=0; i<n; i++){
        if (a[i] <= b[i]){
            cout << 0 << endl;
            return;
        }
    }
    ll ans = 1;
    for (int i=0; i<n-1; i++){
        int right = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        // dbg_out(i, right); 
        ans = (ans * (right-i)) % MOD;  // add to the permutations result 
    }
    cout << ans << endl;
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