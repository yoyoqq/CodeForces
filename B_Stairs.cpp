#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


ll boxes(ll size){
    return (size * (size+1)/2);
}

void solve(){
    ll x; cin >> x;
    
    // multiply by 2 every time box
    // 1 2 4 8 16 .. 
    // every take is a power of 2 - 1 
    // 1 3 7 .. 
    ll count = 0;
    for (int i=1; boxes((1LL<<i)-1) <= x; i++){
        count++;
        x -= boxes((1LL<<i) - 1);
    }
    cout << count << endl;

    // ll box = 1;
    // while (boxes(1<<box)-1 <= x){
    //     x -= boxes(1<<box) - 1;
    //     box++; // powers of 2 
    //     count++;
    // }
    // cout << count << endl;
    
    
    // ll multp = 0;
    // ll count = 0;
    // while (x - multp > 0){
    //     if (multp == 0) multp = 1;
    //     x -= multp;
    //     multp *= 6;
    //     count++;
    //     dbg_out(multp);
    // }
    // cout << count << endl;
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