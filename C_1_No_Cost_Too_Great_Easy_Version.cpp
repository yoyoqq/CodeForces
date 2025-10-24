#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


const int N = 2e5 + 10;
vector<vector<int>> pfac(N);


void solve(){
    int n; cin >> n;
    vector<int> a(n); for(int& x : a) cin >> x;
    vector<int> b(n); for(int& x : b) cin >> x;
    // 

    int ans = 2;
    // 1. 0 if -> seen prime more than once 
    map<int, int> freq;
    for (int num : a){
        for (int p : pfac[num]){
            if (freq[p]) ans = 0;
            freq[p]++;
        }
    }

    // 2. 1 if -> count+1 is in prime 
    for (int num : a){
        num++;
        for (int p : pfac[num]){
            if (freq[p]) ans = min(ans, 1);
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    // sieve erastothenes 
    for (int i=2; i<=N; i++){
        // if we have seen it before is not a prime 
        if (!pfac[i].empty()) continue;
        // push prime number to arr  
        for (int j=i; j<=N; j+=i){
            pfac[j].push_back(i);
        }
    }
    

    
    int test = 0; cin >> test;
    while (test--) solve();
    return 0;
}
