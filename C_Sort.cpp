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

vector<vector<int>> getPref(const string &s) {
    vector<vector<int>> ans;
    for (int i = 0; i < s.size(); i++) {
        vector<int> arr(27, 0); // Initialize to 0
        if (!ans.empty()) {
            arr = ans.back(); // Carry forward prefix counts
        }
        arr[s[i] - 'a'+1]++; // Update the current character count
        ans.push_back(arr); // Append updated prefix
    }
    return ans;
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> pre1(n + 1, vector<int>(26, 0));
    vector<vector<int>> pre2(n + 1, vector<int>(26, 0));
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        pre1[i][c - 'a']++;

        for (int j = 0; j < 26; j++)
            pre1[i][j] += pre1[i - 1][j];
    }
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        pre2[i][c - 'a']++;

        for (int j = 0; j < 26; j++)
            pre2[i][j] += pre2[i - 1][j];
    }
    // dbg_out(pre1, pre2);
    while (q--){
        int l, r;
        cin >> l >> r;

        int dif = 0;

        for (int c = 0; c < 26; c++){
            int v1 = pre1[r][c] - pre1[l - 1][c];
            int v2 = pre2[r][c] - pre2[l - 1][c];
            dif += abs(v1 - v2);
        }
        cout << dif / 2 << "\n";
    }
    


    
    
    // //
    // dbg_out(prefA);
    // int x, y;
    // for (int l=0; l<q; l++){
    //     cin >> x >> y;
    //     // int countA = prefA[x] - prefA[y-1];
    //     // int countB = prefB[x] - prefB[y-1];
    //     for 
    // }

    
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