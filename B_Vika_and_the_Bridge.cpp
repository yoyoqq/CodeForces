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
typedef vector<int> vi;

// 15 

void solve(){
    int n, k; cin >> n >> k;
    vi a(n); for (auto& x : a) cin >> x; 

    // STEPS
    // precompute for each colour in a map 
    // take the distances from one index to another 
    // calculate the distances and the ans is the second max 
    
    map<int, vi> colours;
    for (int i=1; i<=k; i++){
        colours[i].push_back(0);
    }
    for (int i=0; i<n; i++){
        colours[a[i]].push_back(i+1);
    }
    for (int i=1; i<=k; i++){
        colours[i].push_back(n+1);
    } 
    // take distances and use second max 
    int ans = INT_MAX;
    for (auto [colour, indexes] : colours){
        vi colour_dist;
        for (int i=1; i<indexes.size(); i++){
            int distance = indexes[i] - indexes[i-1] - 1;
            colour_dist.push_back(distance);
        }
        sort(colour_dist.begin(), colour_dist.end());
        int first_max = colour_dist.back() / 2;
        int second_max = colour_dist[colour_dist.size()-2];
        ans = min(ans, max(first_max, second_max));
    }

    cout << ans << endl;
    
    // for (auto [k, v] : colours){
    //     cout << k << endl;
    //     for (int& x : v){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    
    
    // // dp, greedy? 
    // vector<pair<int, int>> dist(k+1, {-1, 0});
    // for (int i=0; i<n; i++){
    //     int num = a[i];
    //     dist[num].second = max(dist[num].second, (i-dist[num].first-1));
    //     // dist[num].second = max(dist[num].second, (i-dist[num].first+1)/2);
    //     dist[num].first = i;
    // }
    // // last pos 
    // for (int i=1; i<dist.size(); i++){
    //     int num = i;
    //     dist[num].second = max(dist[num].second, (n-dist[num].first-1));
    //     // dist[num].first = i; 
    // }
    // // dbg_out(dist);
    // // with the distances, how to use the extra  

    
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