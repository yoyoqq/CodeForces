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
    vector<int> a(n), b(n);
    for(int& x : a) cin >> x;       
    for(int& x : b) cin >> x;       
    // for every cell there exists at least one chip in col/row  
    // is either using a or b, then the min from that one 
    vector<int> tempA = a;
    vector<int> tempB = b;
    sort(all(tempA));
    sort(all(tempB));
    // 
    ll left = 0;
    ll right = 0;
    // dbg_out(a, tempA);
    // dbg_out(b, tempB);
    for (int i=0; i<n; i++){
        // take the min from one, fill either one col or one row 
        left += a[i] + tempB[0];
        right += b[i] + tempA[0];
    }
    cout << min(left, right) << endl;
    // cout << left << " " << right << endl;
    
    
    // // sort 
    // vector<ll> temp;
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<n; j++){
    //         temp.push_back(0LL + a[i] + b[j]);
    //     }
    // }
    // sort(all(temp));
    // ll ans = 0;
    // for (int i=0; i<n; i++){
    //     ans += temp[i];
    // }
    // dbg_out(temp);
    // cout << ans  << endl;

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