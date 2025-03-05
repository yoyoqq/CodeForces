#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


int lucky(int n){
    int mn = 10;
    int mx = 0;
    while (n){
        int cur = n % 10;
        n /= 10;
        mn = min(mn, cur);
        mx = max(mx, cur);
    }
    return mx - mn;
}


void solve(){
    int l, r; cin >> l >> r;
    

    // then we can try the nums 
    int luck_num = 0;
    int output = r;
    for(int i=l; i<=r; i++){
        int cur_lucky = lucky(i);
        if (cur_lucky > luck_num){
            luck_num = cur_lucky;
            output = i;
        }
        if (luck_num == 9) break;
    } 
    cout << output << endl;
    
    
    // // edge case when both lenghts are 1 
    // if (l / 10 == 0 && r / 10 == 0){
    //     cout << r;
    //     return;
    // }
    
    // int luck_num = 0;
    // int output = 0;
    // for (int i=r; i>=max(l, r-); i--){
    //     int cur_lucky = lucky(i);
    //     // dbg_out(cur_lucky, luck_num);
    //     if (cur_lucky > luck_num){
    //         luck_num = cur_lucky;
    //         output = i;
    //     }
    // }
    // cout << output << endl;
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