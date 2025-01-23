#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// overload cout and return pair<A, B>
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// return generic container (vector, set, list) to output stream 
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// debugging
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// generate random num
#define rng_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng_seed(x) mt19937 rng(x)
// shortcuts
#define all(x) (x).begin(), (x).end()   // sort(all(a))

using ll = long long;
typedef long double ld;
const char nl = '\n';
int A[200010];

int max_indegree(map<int, set<int>>& nodes){
    int node = -1;
    int count = -1;
    for (auto& [k, v] : nodes){
        if ((int)v.size() > count){
            node = k;
            count = v.size();
        }
        // dbg_out(v.size(), count, (int)v.size() > count, node);
    }
    // dbg_out("node ", node, count);
    return node;
}

void delete_node(map<int, set<int>>& nodes, int& node){
    nodes.erase(node);
    for (auto& [k, v] : nodes){
        if (v.find(node) != v.end()){
            v.erase(node);
        }
    }
}

void print_graph(map<int, set<int>>& nodes){
    for (auto& [k, v] : nodes){
        dbg_out(k, v);
    }
}

void dfs(map<int, set<int>>& nodes, set<int>& seen, int node){
    seen.insert(node);
    for (int next_node : nodes[node]){
        if (seen.find(next_node) == seen.end()){
            dfs(nodes, seen, next_node);
        }
    }
}

map<int, int> mp[200001];
pair<int, int> d[200001];

void solve(){

    int n; cin >> n;

    // init 
    for (int i=1; i<=n; i++){
        d[i].first = 0;
        d[i].second = i;
        mp[i].clear();
    }
    // get input 
    for (int i=1; i<n; i++){
        int x, y; cin >> x >> y;
        mp[x][y] = mp[y][x] = 1;
        d[x].first++;
        d[y].first++;
    }
    sort(d+1, d+1+n, greater<pair<int, int>>());
    int ans = 0;
    for (int i=1; i<=min(n, 3); i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,d[i].first+d[j].first-1-mp[d[i].second][d[j].second]);
        }
    }
    cout << ans << endl;
    
    
    
    // remove max number of in degree 
    // count 
    // remove

    // int n; cin >> n;
    // map<int, set<int>> nodes;
    // for (int i=0, u, v; i<n-1; i++){
    //     cin >> u >> v;
    //     nodes[u].insert(v);
    //     nodes[v].insert(u);
    // }
    
    // // delete 2 nodes 
    // int node1 = max_indegree(nodes);
    // delete_node(nodes, node1);
    // int node2 = max_indegree(nodes);
    // delete_node(nodes, node2);
    
    // // dfs 
    // // dbg_out(node1, node2);
    // // print_graph(nodes);

    // int components = 0;
    // set<int> seen;
    // for (int i=1; i<=n; i++){
    //     if (i == node1 || i == node2) continue;
    //     if (seen.find(i) == seen.end()){
    //         dfs(nodes, seen, i);
    //         components++;
    //     }
    // }
    // cout << components << endl;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 1e9; cin >> test;
    while (test--) solve();
    return 0;
}

/*



*/