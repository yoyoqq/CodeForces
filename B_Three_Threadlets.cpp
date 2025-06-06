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
    priority_queue<int> pq;
    int mn = 1e9;
    for (int i=0; i<3; i++){
        int n; cin >> n;
        mn = min(mn, n);
        pq.push(n);
    }
    // all the same 
    if (pq.top() == mn){
        cout << "YES\n";
        return;
    }
    for (int i=0; i<3; i++){
        int first = pq.top(); pq.pop();
        // dbg_out(first, mn);
        // split first 
        pq.push(mn);
        pq.push(first - mn);
        mn = min({mn, first - mn});
        if (pq.top() == mn){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";

        
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