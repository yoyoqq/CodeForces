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

void solve(){
    int n; cin >>n;
    // https://www.youtube.com/watch?v=8dNGLQW4wSc
    // case where there is a intersection ai < bi < aj
    // there are 2 intersections, the way to find them is by its sum 
    vector<vector<ll>> a;
    int x, y;
    for (int i=0; i<n; i++){
        cin >>  x >> y;
        a.push_back({x+y, x, y});
    }
    sort(all(a));
    for (int i=0; i<n; i++){
        cout << a[i][1] << " " << a[i][2] << " ";
    }cout << endl;
    
    
    // a is always gonan be increasing 
    // when x > y there is always 1 value that is gonna be 
    // vector<pair<int, int>> a;
    // vector<pair<int, int>> b;
    // for (int i=0, x, y; i<n; i++){
    //     cin >> x >> y;
    //     if (x < y){
    //         a.push_back({x, y});
    //     }else{
    //         b.push_back({x, y});
    //     }
    // }   
    // sort(all(a));
    // sort(b.begin(), b.end(), [](auto& left, auto& right){
    //     return left.second < right.second;
    // });
    // for (int i=0; i<a.size(); i++){
    //     cout << a[i].first << " " << a[i].second << " ";
    // }
    // for (int i=0; i<b.size(); i++){
    //     cout << b[i].first << " " << b[i].second << " ";
    // }cout << endl;
    
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