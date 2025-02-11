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
    int n, k; cin >> n >> k;
    vector<int> a(n); 
    for(int& x : a) cin >> x;
    sort(all(a));
    dbg_out(a);
    int ans = 0;
    int j = 0;
    for (int i=0; i<n; i++){
        j = max(j, i);
        // in range, range k, x + 1
        while (j+1<n && a[j+1]-a[i]<k && a[j+1] - a[j] <= 1){
            j++;
        }
        ans = max(ans, j-i+1);
    }
    cout << ans << endl;
    
    // two steps 
    // 1. for the diff x+1
    // 2. make into gropus
    // int max_cards = 0;
    // map<int, int> freq;
    // vector<int> a;
    // for (int i=0, x; i<n; i++){
    //     cin >> x;
    //     if (freq.find(x) == freq.end()) a.push_back(x);
    //     freq[x]++;
    // }
    // a.push_back(1e9+7);
    // sort(all(a));
    // dbg_out(a);
    // int left = 0;
    // int cur_count = 0;
    // for (int right=0; right<n+1; right++){
    //     cur_count += freq[a[right]];
    //     // x+1
    //     if (right != 0 && a[right]+1 != a[right]){
    //         cur_count = freq[a[right]];
    //         left = right;
    //     }
    //     // while its in range and x+1
    //     while (right - left > k){
    //         cur_count -= freq[a[left]];
    //         left++;
    //     }
    //     max_cards = max(max_cards, cur_count);
    // }
    
    // cout << max_cards << endl;
    
    
    // dbg_out(freq);
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