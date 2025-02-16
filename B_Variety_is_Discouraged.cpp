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
    vector<int> a(n); for(int& x : a) cin >> x;

    map<int, int> freq;
    bool one = false;
    for (int& num : a) freq[num]++;

    int max_count = n - freq.size();
    // try to delete the subarray of occ 1 
    pair<int, int> output = {-1, -1};
    int j = 0;
    for (int i=0; i<n; i++){
        // dbg_out(i, j, output, a[j]);
        j = max(i, j);
        while (j<n && freq[a[j]] == 1){ 
            j++;
        }
        if (freq[a[i]] == 1 && j - i > output.second - output.first){
            output = {i, j};
        }
    }
    
    // ouptut 
    if (n == 1){
        cout << 1 << " " << 1 << endl;
    }
    else if (output.first == -1 && output.second == -1){
        cout << 0 << endl;
    }else{
        cout << output.first+1 << " " << output.second << endl;
    }
    
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