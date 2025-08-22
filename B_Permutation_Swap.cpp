#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;

bool possible(vector<int>& a, int k){
    int n = a.size();
    vector<int> b = a;
    
    for (int i=0; i<k; i++){    // k groups 
        vector<int> bucket; 
        for (int j=i; j<n; j+=k) bucket.push_back(b[j]);    // make jumps
        sort(bucket.begin(), bucket.end());
        int t = 0;
        for (int j=i; j<n; j+=k) b[j] = bucket[t++];
    }
    // is sorted ? 
    // dbg_out(k, b);
    for (int i=1; i<n; i++){
        if (b[i] < b[i-1]) return false;
    }
    return true;
    
    // int n = a.size();
    // vector<bool> seen(n+1, false);
    // map<int, set<int>> groups;
    // // put into groups 
    // int group = 1;
    // for (int i=1; i<=n; i++){
    //     int idx = i;
    //     if (seen[i]) continue;
    //     while (seen[idx] == false && idx <= n){
    //         groups[group].insert(idx);
    //         seen[idx] = true;
    //         idx += k;
    //     }
    //     group++;
    // }
    // // delete them 
    // seen.clear();
    // group = 1;
    // for (int i=0; i<n; i++){
    //     int idx = i;
    //     if (seen[i]) continue;
    //     while (seen[idx] == false && idx < n){
    //         if (groups[group].find(a[idx]) == groups[group].end()){
    //             return false;
    //             groups[group].erase(a[idx]);
    //         }
    //         seen[idx] = true;
    //         idx += k;
    //     }
    //     group++;
    // }
    // // dbg_out(groups);
    // return true;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    int res = 0;
    for (int i=1; i<=n; i++){
        res = __gcd(res, abs(a[i-1] - i));
    }
    cout << res << endl;

    // int k = 0;
    // for (int i=1; i<=n/2+1; i++){
    //     if (possible(a, i)) k = i;
    // }
    // cout << k << endl;
    
    // int left = 1;
    // int right = n;
    // int k = n;
    // while (left <= right){
    //     int mid = left + (right-left) / 2;
    //     if (possible(a, mid)){
    //         k = mid;
    //         left = mid + 1;
    //     }else{
    //         right = mid - 1;
    //     }
    // }
    // cout << k << endl;
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