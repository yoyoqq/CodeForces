#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


void dfs(vector<string>& a, set<string>& lexico, set<pair<int, int>>& seen, int ii, int jj, string cur){
    if (cur.size() == 3){
        lexico.insert(cur);
        return;
    }   
    // children 
    for (int i=-1; i<2; i++){
        for (int j=-1; j<2; j++){
            int di = i + ii;
            int dj = j + jj;
            if (0 <= di && di <3 && 0 <=dj && dj < 3 && seen.find({di, dj}) == seen.end()){
                seen.insert({di, dj});
                dfs(a, lexico, seen, di, dj, cur+a[di][dj]);
                seen.erase({di, dj});
            }
        }
    }
}

void solve(){
    // brute force ? 
    vector<string> a(3); cin >> a[0] >> a[1] >> a[2];
    // dbg_out(a);
    set<string> lexico;
    set<pair<int, int>> seen;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            seen.insert({i, j});
            string cur = string(1, a[i][j]);
            dfs(a, lexico, seen, i, j, cur); 
            seen.erase({i, j});
        }
    }
    cout << *lexico.begin() << endl;
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