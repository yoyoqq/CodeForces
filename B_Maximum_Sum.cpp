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
    int n, k; cin >> n >> k;
    vector<int> a(n); 
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    // 
    sort(all(a));
    vector<ll> prefix(n, 0);
    for (int i=0; i<n; i++){
        if (i) prefix[i] = prefix[i-1];
        prefix[i] += a[i];
    }
    // dbg_out(a);
    // dbg_out(prefix);
    // cannot be greedy, then just brute force it 
    // remove m minimums then the rest with maximums 
    ll sum = 0;
    for (int i=0; i<=k; i++){
        int l = i * 2; // l -> min removals
        int r = n-(k-i)-1;   // r -> max removals
        ll cur = prefix[r] - (l ? prefix[l-1] : 0);     // at zero we count it 
        sum = max(sum, cur);
    }
    cout << sum << endl;
    
    // // start from mid choose which side is better to expand with 
    // int left = n/2;
    // int right = n/2 + 1;
    // ll sum = 0;
    // for (int i=0; i<k; i++){
    //     if (left > 0 && a[left] + a[left-1] > a[right]){
    //         sum += a[left] + a[left-1];
    //         left -= 2;
    //     }
    //     else{
    //         sum += a[right];
    //         right++;
    //     }
    // }
    // dbg_out("indx", left, right);
    // left = 0, right = n-1;
    // // k times 
    // for (int i=0; i<k; i++){
    //     // either remove 2 min/max
    //     int l = a[left] + a[left+1];
    //     int r = a[right];
    //     if (l < r){
    //         left += 2;
    //     }
    //     else{
    //         right -= 1;
    //     }
    // }
    // // dbg_out(a);
    // // sum 
    // ll sum1 = 0;
    // for (int i=left; i<=right; i++){
    //     sum1 += a[i];
    // }
    // // till n-k
    // ll till = 0;
    // for (int i=0; i<n-k; i++){
    //     till += a[i];
    // }
    // dbg_out(till, sum, sum1);
    // cout << max({till, sum, sum1}) << endl;
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