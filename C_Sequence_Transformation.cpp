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
    vector<int> a(n); 
    for (int& x : a) cin >> x;

    // if the last values are the same pop
    while (a.size() >= 2 && a[a.size()-1] == a[a.size()-2]){
        a.pop_back();
    }
    
    map<int, int> freq;
    for (int i=0; i<n; i++){
        if (i && a[i] == a[i-1]) continue;  // if prev is the same we dont count again 
        if (freq.find(a[i]) == freq.end()){
            freq[a[i]] = 2;
        }else{
            freq[a[i]]++;
        }
        if (i == 0 || i == a.size()-1) freq[a[i]]--;
    }
    // get min operations 
    int mn = 1e9;
    for (auto [k, v] : freq){
        mn = min(mn, v);
    }
    if (freq.size() == 1) mn = 0;
    cout << mn << endl;
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