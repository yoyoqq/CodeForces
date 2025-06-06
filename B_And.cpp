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
    int n, x; cin >> n >> x;
    map<int, int> map;

    // 1. there are equal elements 
    for (int i=0; i<n; i++){
        int x; cin >> x;
        map[x]++;
        if (map[x] >= 2){
            cout << 0 << endl;
            return;
        }
    }
    // 2. if all the elements are still distinct -1 
    set<int> distinct;
    for (auto [k, v] : map){
        distinct.insert(k & x);
    }
    if (distinct.size() == map.size()){
        cout << -1 << endl;
        return;
    }
    // 3. if element changes and its in array -> 1 
    for (auto [k, v] : map){
        if (((k & x) != k) && map.find(k&x) != map.end()){
            cout << 1 << endl;
            return;
        }
    }
    // 4. else is 2 
    cout << 2 << endl;





    // if there is equal vals 
    // if all x >= all(map)
    // // if (map.rend())
    // if (x >= map.rbegin()->first){
    //     cout << -1 << endl;
    //     return;
    // }
    // bool two_op = false;
    // set<int> seen;
    // // use the big vals to 
    // for (auto it=map.rbegin(); it!=map.rend(); it++){
    //     // cout << it->first << " " << it->second << endl;
    //     // if (it->first <= x) break;
    //     // one operation 
    //     if (map.find(it->first & x) != map.end()){
    //         dbg_out(it->first);
    //         cout << 1 << endl;
    //         return;
    //     }
    //     // two operations 
    //     if (seen.find(it->first & x) != seen.end()) two_op = true;
    //     seen.insert(it->first & x);
    // }
    // cout << (two_op ? 2 : -1) << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // int test = 0; cin >> test;
    // while (test--) solve();
    solve();
    return 0;
}