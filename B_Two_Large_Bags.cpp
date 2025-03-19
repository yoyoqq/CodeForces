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
    vector<int> a(n+1); 
    for (int i=0, x; i<n; i++){
        cin >> x;
        a[x]++;
    }
    // carry it forward 
    bool poss = true;
    for (int i=0; i<a.size()-1; i++){
        if (a[i]>=3){
            a[i+1] += (a[i] - 2);
            a[i] = 2;
        }
        if (a[i] == 1) poss = false;
    }
    if (a.back() % 2 == 1) poss = false;
    cout << (poss ? "YES" : "NO") << endl;
    // dbg_out(a);
    
    
    // int carry = 0;
    // bool poss = true;
    // for (int i=0; i<a.size(); i++){
    //     carry += a[i];
    //     if (carry >= 2){
    //         a[i] = 2;
    //         carry -= 2;
    //     }
    //     if (a[i] % 2 != 0) poss=  false;
    // }
    // dbg_out(carry, a);
    // // carry and a is all with 2 vals 
    // if (carry % 2 == 0 && poss){
    //     cout << "YES" << endl;
    // }
    // else{
    //     cout << "NO" << endl;
    // }
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
