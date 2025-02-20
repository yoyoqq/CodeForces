#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


void solve(){
    int n; cin >> n;
    vector<int> a(n); for(int& x : a) cin >> x;
    
    set<int> seen;
    int k = 1;
    while (k * k <= 1000 * 100){
        seen.insert(k*k);
        k+=2;
    }
    // find starters layers 
    int days = 0;
    int curSum = 0;
    for (int i=0; i<n; i++){
        curSum += a[i];
        if (seen.find(curSum) != seen.end()){
            days++;
        }   
    }
    cout << days << endl;
    
    // // 
    // ! there cannto be unfinished layers!!!
    // int days = 1;
    // int row = 3;
    // int col = 1;
    // int remaining = a[0]-1;
    // for (int i=1; i<n; i++){
    //     // compute block
    //     remaining += a[i];
    //     // days ? 
    //     bool poss = false;
    //     while (remaining >= row*2+col*2){
    //         row += 2;
    //         col += 2;
    //         remaining = remaining - (row*2+col*2);
    //         poss = true;
    //     }
    //     if (poss)
    //         days++;
    // }
    // cout << days << endl;
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
