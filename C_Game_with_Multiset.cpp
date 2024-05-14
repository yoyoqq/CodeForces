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
    int x, y;
    vector<int> a(30, 0);
    for (int i=0; i<n; i++){
        cin >> x >> y;
        if (x == 1){
            a[y]++;
        }
        // else if (x == 2){
        else{
            for (int i=29; i>=0; i--){
                // how many of a[i] we can take 
                // y / number of _ that can take, all the a[i] 
                // how many take out << right shift 
                y -= min(y >> i, a[i]) << i;
            }
            if (y == 0)
                cout << "yes" << nl;
            else
                cout << "no" << nl;
        }
    }
    
    
    
    //  WE CANNOT BE THATTTT GREEDY..
    // IF WE ONLY HAVE 32, WHAT IF ASKSS FOR 2? .. -> use a table and take the max as possible  
    // int n; cin >> n;
    // // vector<int> a(30, 0);
    // // dbg_out(a.size());
    // int x, y;
    // bool odd = false;
    // ll total = 0;
    // for (int i=0; i<n; i++){
    //     cin >> x >> y;
    //     if (x == 1){
    //         ll power = pow(2, y);
    //         total += power;
    //         if (power % 2 == 1) odd = true;
    //     }
    //     else if (x == 2){
    //         // even
    //         if (y % 2 == 0 && y <= total) cout << "yes" << nl;
    //         // odd 
    //         else if (y % 2 == 1 && odd == true && y <= total) cout << "yes" << nl;
    //         else{
    //             cout << "no" << nl;
    //         }
    //     }
    //     // dbg_out(total, odd, x, y);
    // }
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}

/*



*/