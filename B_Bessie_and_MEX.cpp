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
    vector<int> a(n);
    for(int& x : a) cin >> x;
    // mex - x = y
    // x = mex - y      find this 
    int mex = 0;
    vector<int> res(n), has(n+1);
    for (int i=0; i<n; i++){
        if (a[i] >= 0){
            res[i] = mex;           // use mex as no other option
        } else{
            res[i] = mex - a[i];    // formula
        }
        has[res[i]] = true;   // mark as true
        while(has[mex]) mex++;  // if already using the number skip
    }

    for (auto r : res){
        cout << r << " ";
    }
    cout << endl;
    

    
    // // 
    // // see pattern on the res 
    // // when positive, increases
    // // when engative, decreases 
    // int left = 0; 
    // int right = n-1;
    // for (int i=0; i<n; i++){
    //     if (a[i] < 0){
    //         cout << right << " ";
    //         right--;
    //     }else{
    //         cout << left << " ";
    //         left++;
    //     } 
    // }
    // cout << endl;
    
    
    
    // int cur = 0; 
    // int cur_mx = n - 1;
    // set<int> seen;
    // vector<int> res;
    // for (int i=0; i<n; i++){
    //     if (a[i] < 0){
    //         res.push_back(cur_mx);
    //         cur_mx--;
    //     }else{
    //         // put int res, two cases 
    //         res.push_back(cur);
    //         // update cur 
    //         seen.insert(cur);
    //         while (seen.count(cur)){
    //             cur++;
    //         }   
    //     }
    // }
    // for (int i=0; i<n; i++){
    //     cout << res[i] << " ";
    // }
    // cout << endl;
    
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