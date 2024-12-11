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
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++){
        pair<int, int> pair;
        cin >> pair.first;
        cin >> pair.second;
        a[i] = pair;
    }   
    sort(a.begin(), a.end());
    // vector<pair<int, int>> suff;
    dbg_out(a);
    
    // price, quality 
    // price1 < price2
    // quality 1 > quality 2
    // is there a quality1 > quality 2 -> suffix
    vector<int> suff(n);   // get min quality seen
    suff[n-1] = a[n-1].second;
    for(int i=n-2; i>=0; i--){
        suff[i] = min(suff[i+1], a[i].second); 
    }

    // check ans
    bool ans = false;
    for (int i=0; i<n-1; i++){
        if (a[i].second > suff[i]){
            ans = true;
            break;
        }
    }
    if (ans){
        cout << "Happy Alex" << endl;
    }
    else{
        cout << "Poor Alex" << endl;
    }
    
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