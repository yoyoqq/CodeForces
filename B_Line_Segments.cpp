#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


void print(string s){
    cout << s << endl;
}

void solve(){
    int n; cin >> n;
    ll px, py, qx, qy; cin >> px >> py >> qx >> qy;
    


    // make degenerate polygon 
    // look at the longest line and should be able to do with the rest sum 
    vector<double> a(n+1);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    a[n] = sqrt(1LL * (qx - px) * (qx - px) + 1LL * (qy - py) * (qy - py));
    // a[n] = distance;
    sort(all(a));

    // max - sum(rest) <= 0
    // the rest of the values should be higher than the max itself otherwise we cannot close the polygon 
    double sm = a[n];
    for (int i=0; i<n; i++){
        sm -= a[i];
    }
    // need to use double for it otherwise we are losing info 
    cout << (sm <= 0 ? "yes" : "no") << endl;
 
    
    
    
    
    
    // vector<int> a(n); for(int& x : a) cin >> x;
    // 
    // if (px == qx && py == qy){
    //     if (n == 1) print("no");
    //     else if (n == 2){
    //         if (a[0] != a[1]) print("no");
    //         else print("yes");
    //     }
    //     else{
    //         int sm = 0;
    //         for (int i=0; i<n-1; i++){
    //             sm += a[i];
    //         }
    //         if (sm >= a[n-1]) print("yes");
    //         else print("no");
    //     }
    //     return;
    // }
    // // if (n == 1){
    // //     print("no");
    // //     return;
    // // }

    // // enoguh distance from a to b 
    // int sm = 0;
    // for (int i=0; i<n; i++){
    //     sm += a[i]; 
    // }
    // // int euclid = sqrt(abs(x))
    // int distance = sqrt((qx - px) * (qx - px) + (qy - py) * (qy - py));
    // if (distance == sm || distance < sm && (sm-a[n-1] >= a[n-1])) print("Yes");
    // else print("no");
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