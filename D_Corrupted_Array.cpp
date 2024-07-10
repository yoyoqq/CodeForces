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

void solve(){
    int n; cin >> n;
    vector<int> b(n + 2);
    for (int& x : b) cin >> x;
    multiset<int> have(b.begin(), b.end());

    ll sm = accumulate(b.begin(), b.end(), 0LL);
    for (int x : b){
        have.erase(have.find(x));
        sm -= x;
        if (sm % 2 == 0 && sm <= 2'000'000'000 && have.find(sm/2) != have.end()){
            have.erase(have.find(sm/2));
            for (int y : have){
                cout << y << " ";
            }
            cout << nl;
            return;
        }
        sm += x;
        have.insert(x);
    }
    cout << -1 << nl;
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

/*



*/