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
    int n, m; cin >> n >> m;
    vector<int> a(m); for (int& x : a) cin >> x;
    //
    ll time = 0;
    int cur_pos = 1; 
    for (int& next_pos : a){
        // easier way to wrap around is by
        // n - b + a 
        if (next_pos < cur_pos){
            time += n - cur_pos + next_pos;
        }
        else{
            time += next_pos - cur_pos;   
        }
        cur_pos = next_pos;

         
        // // wrap around ? 
        // if (next_pos < cur_pos){
        //     time += n - cur_pos + 1;
        //     cur_pos = 1;
        // }
        // // normal case
        // time += next_pos - cur_pos;
        // cur_pos = next_pos; 
        // // dbg_out(time, cur_pos, next_pos);
    }
    cout << time << endl;   
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    // int test = 1e9; cin >> test;
    // while (test--) solve();
    return 0;
}

/*



*/