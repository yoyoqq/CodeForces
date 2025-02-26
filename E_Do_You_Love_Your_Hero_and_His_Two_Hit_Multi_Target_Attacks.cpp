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
    int staffs; cin >> staffs;
    vector<pair<int, int>> ans;
    ans.push_back({0, 0});
    int x = 0, y = 0;
    int col_count = 0;
    int cur_staffs = 0;
    while (cur_staffs < staffs){
        // too big 
        if (col_count+1 + cur_staffs > staffs){
            x++;
            y++;
            col_count = 0;
        }
        // count 
        else{
            y++;
            col_count++;
        }
        cur_staffs += col_count;
        ans.push_back({x, y});
    }
    cout << ans.size() << endl;
    for (auto [f, s] : ans){
        cout << f << " "<< s << endl;
    }
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
