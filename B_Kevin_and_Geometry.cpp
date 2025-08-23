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
    vector<int> a(n); for(int& x : a) cin >> x;
    // get repeated elements 
    sort(all(a));
    map<int, int> freq;
    for (int i=0; i<n; i++){
        freq[a[i]]++;
    }
    for (auto it=freq.begin(); it!=freq.end();){
        if (it->second == 1) it = freq.erase(it);
        else it++;
    }
    // 3 cases 
    // 1. if freq == 0 impossible 
    if (freq.size() == 0) cout << -1 << endl;
    // 2. if greater than 2, means that we can get a rectangle 
    else if (freq.size() >= 2) {
        cout << freq.begin()->first << " " << freq.begin()->first << " ";
        cout << freq.rbegin()->first << " " << freq.rbegin()->first << " ";
        cout << endl;
    }
    // otherwise we can check if 2c > abs(b - a)
    else {
        int c = freq.begin()->first;
        a.erase(find(a.begin(), a.end(), c));
        a.erase(find(a.begin(), a.end(), c));
        // dbg_out(a, c, 2*c);
        for (int i=1; i<a.size(); i++){
            if (2*c > abs(a[i] - a[i-1])){
                // dbg_out(2*c, abs(a[i]-a[i-1]));
                cout << c << " " << c << " " << a[i] << " " << a[i-1] << endl;
                return;
            }
        }
        cout << -1 << endl;
    }
    
    
    
    
    
    // for (int i=1; i<n; i++){

    // }
    // map<int, int> count;
    // // for (auto [k, v] : freq) if (v == 1) freq.erase(k);
    // // SAFE: erase while iterating with an iterator
    // for (auto it = freq.begin(); it != freq.end(); ) {
    //     if (it->second == 1) it = freq.erase(it);
    //     else ++it;
    // }

    // // brute force 
    // for (auto [k, v] : freq){
    //     for (int i=1; i<n; i++){
    //         if (2*k + a[i-1] >= a[i]){
    //             cout << k << " " << k << " " << a[i-1] << " " << a[i] << endl;
    //             return;
    //         }
    //     }
    // }
    // cout << -1 << endl;
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