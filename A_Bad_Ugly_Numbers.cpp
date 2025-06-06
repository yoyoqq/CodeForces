#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


void proof(string n){
    int digit_sum = 0;
    for (char c : n) digit_sum += c - '0';
    cout << (digit_sum % 9 == 0) << endl;
    // ll num = stoll(n);
    // cout << (num % 9 != 0) << endl;
    // bool div = true;
    // if (num % 2 != 0) div = false;
    // if (num % 9 != 0) div = false;
    // cout << div << endl;
}


void solve(){
    int n; cin >> n;
    if (n == 1){cout << "-1\n"; return;}
    // for (int i=0; i<n-1; i++){
    //     cout << 
    // }   
    string left(1, '2');
    // string mid = "5";
    string right(n-1, '9');
    string ans = left + right;
    cout << ans << endl;

    // proof(ans);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 0; cin >> test;
    while (test--) solve();

    // for (int i=1; i<10000; i++){
        
    //     string left(1, '2');
    //     // string mid = "5";
    //     string right(i-1, '9');
    //     string ans = left + right;
    //     // cout << ans << endl;
    //     proof(ans); 
    // }
    return 0;
}