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
    // k -> s1, s2... sk
    // find the Union of all 
    // find max S != all(Union)
    // values are from 1 to 50 
    // find values not with i
    vector<set<int>> a; 
    set<int> all_union;
    int k = 0;
    for (int i=0; i<n; i++){
        cin >> k;
        set<int> temp;
        int x;
        for (int j=0; j<k; j++){
            cin >> x;
            temp.insert(x);
            all_union.insert(x);
        }
        a.push_back(temp);
    }
    // dbg_out(a, all_union);
    // iterate all union.. find all the sets such that i does not appear in set
    set<int> res; 
    for (auto i : all_union){
        set<int> temp;
        for (auto cur_set : a){
            if (cur_set.find(i) == cur_set.end()){
                for (int x : cur_set){
                    temp.insert(x);
                }
            }
        }
        // dbg_out(temp);
        if (res.size() < temp.size()){
            res = temp;
        }
    }
    // dbg_out(res);
    cout << res.size() << nl;
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