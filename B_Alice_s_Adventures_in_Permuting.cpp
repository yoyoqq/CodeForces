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
    ll n, b, c; cin >> n >> b >> c;
    
    // if multiplier is 0 
    if (b == 0){
        if (c >= n){
            cout << n << endl;
        }
        else if (c >= n - 2){
            cout << n - 1 << endl;
        }
        else{
            cout << -1  << endl;
        }
    }
    else{
        // if c is greater than n, we use al lthe nums  
        if (c >= n){
            cout << n << endl;
        }
        // else find the max(ai)  < n
        else{
            cout << n - max(0LL, 1 + (n-c-1)/b) << endl; 
        //     ll i = 0;
        //     ll left = 0, right = n;
        //     while (left <= right){
        //         ll mid = (left+right)/2;
        //         ll formula = b * (mid - 1) + c;
        //         // is it in the perm range 
        //         if (formula <= n){
        //             i = mid;
        //             left = mid + 1;
        //         }else{
        //             right = mid - 1;
        //         }
        //     }    
        //     cout << n - i << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll test = 0; cin >> test;
    while (test--) solve();
    return 0;
}
