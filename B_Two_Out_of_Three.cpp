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
    vector<int> a(n, 0); for(int& x : a) cin >> x;
    // get freq 
    map<int, int> freq;
    for (int num : a) freq[num]++;
    int pairs = 0;
    int first = -1;
    int second = -1;
    for (auto [k, v] : freq){
        if (v >= 2){
            pairs++;
            if (first == -1) first = k;
            else if (second = -1) second = k;
        } 
    }
    if (pairs < 2) {cout << -1 << "\n"; return;}

    vector<int> ans(n, 1);
    bool ignore_first = true, ignore_second = true;
    for (int i=0; i<n; i++){
        if (a[i] == first && ignore_first) ignore_first = false;
        else if (a[i] == first) ans[i] = 2;
        else if (a[i] == second && ignore_second) ignore_second= false;
        else if (a[i] == second) ans[i] = 3;
    }
    for (int& x : ans) cout << x << " "; cout << endl;
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