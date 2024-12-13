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
ll A[200010];

ll count(ll w, ll b){

    ll pins = 0;
    ll n = 1;
    while (n * (n + 1) / 2 <= w){
        pins = n;
        n++;
    }
    // biggest b
    n--;
    ll nn = n + 1;
    while ((nn * (nn + 1) / 2) - (n * (n + 1) / 2) <= b){
        pins++;
        nn++;
    }
    return pins;
}

bool calc(ll w, ll b, ll mid){
    ll sm = w + b;
    if ((mid * (mid + 1) / 2) <= sm){
        return true;
    }
    return false;
}


void solve(){
    ll w, b; cin >> w >> b;

    // if we have the formula of n * (n + 1) / 2
    // whats the max n we can have?
    ll left = 1;
    ll right = INT_MAX;
    ll pins = 0;
    while (left <= right){
        ll mid = left + (right - left) / 2;
        if (calc(w, b, mid)){  // if possible, increase left as we can havve more nums 
            pins = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    cout << pins << endl;



    // ll mx = max(count(w, b), count(b, w));
    // cout << mx << endl;
    // can be greedy if wb and bw
    // NO CANT USEGREEDY 
    // if (w > b){
    //     swap(w, b);
    // }   
    // // greedy? 
    // // for whites (smallest)
    // cout << pins <<  endl;
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll test = 1e9; cin >> test;
    while (test--) solve();
    return 0;
}

/*



*/