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
    int n, m; cin >> n >> m;    // vertices, edges 
    map<int, vector<int>> graph;
    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }   
    int alone = -1;
    for (auto [k, v] : graph){
        if (v.size() == 1){
            alone = k;
            break;
        }
    }
    // to get X traverse twice 
    int x = -1;
    // dbg_out(alone, graph[graph[alone][0]]);
    for (int node : graph[graph[alone][0]]){ // Y node, find edge that is not size == 1
        // dbg_out(graph[node].size() != 1, node, graph[node], graph[node].size());
        if (graph[node].size() != 1){
            x = graph[node].size();
            break;
        }
    }
    // to get Y find an edge, the next parent count is Y-1 
    int y = graph[graph[alone][0]].size()-1; 
    
    cout << x << " " << y << endl;
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