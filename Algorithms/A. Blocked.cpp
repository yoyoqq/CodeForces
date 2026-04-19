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
    sort(a.rbegin(), a.rend());

    // if the first equal to the last 
    // if (a[0] == a[n-1]) swap(a[0], a[n-1]);
    
    bool possible = true;
    map<int, int> freq;
    for (int i=0; i<n; i++) {
        // if (a[i] == cur_sum) possible = false;
        // cur_sum += a[i];
        freq[a[i]]++;
        if (freq[a[i]] == 2){ 
            cout << -1 << endl;
            return;
        }
    }
    for (int& x : a) cout << x << " ";
    cout << endl;
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
