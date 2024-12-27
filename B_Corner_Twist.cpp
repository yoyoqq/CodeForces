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
    vector<string> a;
    vector<string> b;
    string x;
    for (int i=0; i<n; i++){
        cin >> x;
        a.push_back(x); 
    }
    for (int i=0; i<n; i++){
        cin >> x;
        b.push_back(x); 
    }
    // dbg_out(a, b);
    // count the col values 
    int sr1[m]{}, sr2[m]{}, sc1[n]{}, sc2[n]{};
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){ 
            sr1[j] += (int)(a[i][j] - '0');
            sr1[j] %= 3;
            sr2[j] += (int)(b[i][j] - '0');
            sr2[j] %= 3;
            sc1[i] += (int)(a[i][j] -'0');
            sc1[i] %= 3;
            sc2[i] += (int)(b[i][j] -'0');
            sc2[i] %= 3;
        }
    }
    // dbg_out(sc1, sc2);
    // vector<int> count1(m);
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m; j++){
    //         count1[j] = (count1[j] + (a[i][j] - '0')) % 3;
    //     }
    // }
    // vector<int> count2(m);
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m; j++){
    //         count2[j] = (count2[j] + (b[i][j] - '0')) % 3;
    //     }
    // }
    // check diff 
    bool poss = true;
    for (int i=0; i<n; i++){
        poss &= (sc1[i] == sc2[i]);
    }
    for (int i=0; i<m; i++){
        poss &= (sr1[i] == sr2[i]);   
        // if (count1[i] != count2[i]){
        //     poss = false;
        //     break;
        // }
    }
    // dbg_out(count1, count2);
    cout << (poss ? "YES" : "NO") << endl;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 1e9; cin >> test;
    // dbg_out(test);
    while (test--) solve();
    return 0;
}

/*



*/