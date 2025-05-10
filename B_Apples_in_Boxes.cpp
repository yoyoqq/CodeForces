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
    // take apple
    // max - min <= k 
    int n, k; cin >> n >> k;
    int mn = 1e9;
    int mx = -1;
    vector<int> a(n); for(int& x : a) {cin >> x; mn = min(mn, x); mx = max(mx, x);}
    ll sm = 0;
    for (int& x : a) sm += x;
    
    // for the reverse op, on who finishes 
    sort(all(a));
    a[n-1]--;
    sort(all(a));

    // output
    // mx - mn > k || after all operations is zero 
    if (a[n-1]-a[0] > k || sm % 2 == 0){
        cout << "Jerry\n";
    }
    else{
        cout << "Tom\n";
    }
    
    
    // if (mx-1-mn > k || mx - mn > k && mx != mn){
    //     cout << "Jerry" << endl;
    //     return;
    // }
    // if (sm % 2 == 1){
    //     cout << "Tom" << endl;
    // }
    // else{
    //     cout << "Jerry" << endl;
    // }
    
    
    // // Tom cannot play in the first move
    // // dbg_out(mx, mn);
    // if (mx - mn > k) {
    //     cout << "Jerry" << endl;
    // }
    // // otherwise make all to zero 
    // else{
    //     // dbg_out("HI", sm % 2 == 1);
    //     cout << (sm % 2 == 1 ? "Tom" : "Jerry") << endl;
    // }
    
    
    // bool tom = true;

    // sort(all(a));
    // dbg_out(a);

    // can decrease x - mn 
    // ll count = 0;
    // for (int i=0; i<n; i++){
    //    count += (mn - a[i]); 
    // }

    // cout << (count % 2 == 0 && count != 0 ? "Tom" : "Jerry") << endl;
    
    
    
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