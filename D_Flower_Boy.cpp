#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;
const int INF = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m); 
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    // insert on A anywhere except sides 
    // build prefix and suffix of where it uses it 
    vector<int> backwards(m);
    int j = n-1; 
    for (int i=m-1; i>=0; i--){
        while (j >=0 && a[j] < b[i]) j--;
        backwards[i] = j--;
    }
    vector<int> forwards(m);
    j = 0;
    for (int i=0; i<m; i++){
        while(j < n && a[j] < b[i]) j++;
        forwards[i] = j++;
    }
    // we dont need to append
    if (forwards.back() < n){
        cout << 0 << endl;
        return;
    }
    int ans = INF;
    for (int i=0; i<m; i++){
        int previous = (i == 0) ? -1 : forwards[i-1];
        int next = (i+1 == m) ? n : backwards[i+1];
        // delete if the diff is large 
        if (next > previous){
            ans = min(ans, b[i]);
        } 
    }
    cout << (ans == INF ? -1 : ans) << endl;
        
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
