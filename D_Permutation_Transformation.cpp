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

int max_val(vector<int>& a, int left, int right){
    int max = 0;
    int idx = 0;
    for (int i=left; i<=right; i++){
        if (a[i] > max){
            max = a[i];
            idx = i;
        }
    }
    return idx;
}

void solve(){
    int n; cin >>n;
    vector<int> a(n); for(int& x : a) cin >> x;
    vector<int> ans(n, -1);
    // 
    stack<vector<int>> stack;
    stack.push({0, n-1, 0});    // left right depth
    while (stack.size()){
        auto cur_node = stack.top(); stack.pop();
        int left = cur_node[0], right = cur_node[1], depth = cur_node[2];
        int cur_max = max_val(a, left, right);
        // make it mid
        ans[cur_max] = depth;
        // dbg_out(cur_max, left, right, depth);
        if (left >= right) continue;
        // go left
        if (left <= cur_max-1)
            stack.push({left, cur_max-1, depth+1});
        // go right 
        if (cur_max+1 <= right)
            stack.push({cur_max+1, right, depth+1}); 
    }
    
    for (int i=0; i<n; i++){
        cout << ans[i] << " ";
    }cout << endl;
    
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