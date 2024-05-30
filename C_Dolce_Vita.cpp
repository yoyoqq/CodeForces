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
    int n, x; cin >> n >> x; 
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(all(a));
    // 
    int sum = 0;
    int ans = 0;
    // for each store, max days count.. remaining/ time + cur
    for (int i=0; i<n; i++){
        sum += a[i];
        if (x - sum >= 0)
            ans += (x-sum)/(i+1) + 1;        
    }
    cout << ans << nl;
    
    
    // int n, x; cin >> n >> x;
    // vector<int> a(n);
    // int sm = 0;
    // for (int& x : a) cin >> x, sm += x;
    // sort(all(a));
    // // SUM 
    // int packets = 0;
    // if (x >= sm) packets++;
    // int time = 1;
    // while (a.size()){
    //     // if possible take all
    //     if (x >= sm * time){
    //         time++;
    //         packets++;
    //     }
    //     // else tawke off from sm 
    //     else{
    //         sm -= a.back();
    //         a.pop_back();
    //     }   
    // }
    // dbg_out(packets, time, a);
    // cout << packets << nl;

    
    
    // IMPLEMENTATION  
    // int packets = 0;
    // bool possible = true;
    // int time = 0;
    // int cur_money = x;
    // while (possible){
    //     for (int i=0; i<n; i++){
    //         // dbg_out(packets, time, cur_money, i);
    //         // buy
    //         if (cur_money >= a[i] + time){
    //             cur_money -= a[i] + time;
    //             packets++;
    //         }
    //         // cannot buy
    //         else if (i == 0){
    //             possible = false;
    //         }
    //     }
    //     cur_money = x;
    //     time++;
    // }

    // cout << packets << nl;

    
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