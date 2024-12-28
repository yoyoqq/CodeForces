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
    // find mex by iterating the array vector
    // we know that we can have k == 2 
    
    int n; cin >> n;
    vector<int> a(n, 0); for(auto& x : a) cin >> x;
    //
    int mex1 = 0, mex2 = 0;
    // map<int, int> c1, c2; 
    vector<int> c1(n+1), c2(n+1);
    // init state for count1
    for (int& x :a){
        c1[x]++;
    }
    // update mex1
    while (c1[mex1]){
        mex1++;
    }
    // find for mex2
    for (int i=0; i<n; i++){
        int num = a[i];
        c2[num]++;
        c1[num]--;
        // update, c1, c2, mex1, mex2
        // c1 take out 
        if (c1[num] == 0 && mex1 > num) {
            mex1 = num;
        }
        // update c1
        // while (mex1 > 0 && c1.find(mex1) == c1.end()){
        while (mex1 && !c1[mex1-1]){
            mex1--;
        }   
        
        // c2 add 
        // while (c2.find(num) != c2.end()){
        while (c2[mex2]){
            mex2++;
        }

        // base case
        if (mex1 == mex2){
            cout << 2 << endl;
            cout << 1 << " " << i+1 << endl;
            cout << i+2 << " " << n << endl;
            return;
        }
    }
    
    // return 
    cout << -1 << endl; 
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