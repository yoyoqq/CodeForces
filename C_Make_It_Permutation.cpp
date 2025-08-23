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
    int n, c, d; cin >> n >> c >> d;
    vector<int> a(n+1, 0);
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }    
    // delete the repeated nums 
    sort(all(a));
    vector<int> b;
    ll deletions = 0;
    for (int i=0; i<a.size(); i++){
        if (i == 0) b.push_back(a[i]);
        else if (a[i] != a[i-1]) b.push_back(a[i]);
        else{
            deletions++;
        }
    }
    // dbg_out(b, b.size());

    n = b.size();
    ll cost = LLONG_MAX;
    for (int i=1; i<n; i++){
        ll cur_cost = 1LL * (b[i] - i) * d; // missing numbers behind 
        ll del_front = 1LL * (n - (i + 1)) * c;
        // dbg_out(cur_cost, del_front);
        cost = min(cost, cur_cost + del_front);
    }
    // what if it is better if we remove all ? 
    ll delete_all = (a.size()-1) * c + (b[1] == 1 ? 0 : d);
    // dbg_out(delete_all, a.size()-1, c, (b[1] == 1 ? 0 : d));
    cout << min(delete_all, cost + deletions * c) << endl;
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