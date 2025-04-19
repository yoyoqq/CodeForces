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
    ll n, k; cin >> n >> k;
    vector<ll> l(n), r(n); for(ll& x : l) cin >> x; for(ll& x : r) cin >> x;

    ll base = 0;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        base += max(l[i], r[i]);    // take line of max 
        a[i] = min(l[i], r[i]);  // get min 
    }
    sort(a.rbegin(), a.rend());
    // get the min possible and add 1 for last pair 
    for(int i = 0; i < k - 1; i++) base += a[i];
    cout << base + 1 << endl;

    
    
    
    // vector<pair<int, bool>> a;
    // int x;
    // for (int i=0; i<n; i++){
    //     cin >> x;
    //     a.push_back({x, 0});
    // }
    // for (int i=0; i<n; i++){
    //     cin >> x;
    //     a.push_back({x, 1});
    // }
    // take as much as possible greedy, it needs to be together
    // till we have the same amount of left and right 
    // take one off  
    // sort(a.rbegin(), a.rend());
    // dbg_out(a);
    // dbg_out();
    // int left = 0, right = 0;
    // ll count = 0;
    // int last = 0;
    // for (int i=0; i<n; i++){
    //     auto [num, is_right] = a[i];
    //     // count 
    //     count += num;
    //     // base cases
    //     last = num;
    //     if (is_right) right++;
    //     else left++;
    //     if (left >= k && right >= k) break;
    // }
    // cout << count << endl;
    
    
    
    // vector<int> l(n), r(n); for(int& x : l) cin >> x; for(int& x : r) cin >> x;
    // ll top = 0;
    // ll bottom = 0;
    // for (int i=0; i<n; i++){
    //     top += l[i];
    //     bottom += r[i];
    // }
    // sort(all(l));
    // sort(all(r));
    // // take the max 
    // // right take all, left take only k max 
    // dbg_out(l, r, top, bottom, top+bottom);
    // if (bottom >= top){
    //     ll temp = 0;
    //     for (int i=n-1; i>=n-k+1; i--){
    //         temp += l[i];
    //     }
    //     cout << (bottom + temp) << endl;
    // }else{
    //     ll temp = 0;
    //     for (int i=n-1; i>=n-k+1; i--){
    //         temp += r[i];
    //     }
    //     cout << (top + temp) << endl;
    // }

    // vector<pair<int, string>> a;
    // for (int i=0, x; i<n; i++){
    //     cin >> x;
    //     a.push_back({x, "left"});
    //     sm += x;
    // }
    // for (int i=0, x; i<n; i++){
    //     cin >> x;
    //     a.push_back({x, "right"});
    //     sm += x;
    // }
    // // 
    // sort(all(a));
    // dbg_out(a);
    // dbg_out(sm);
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