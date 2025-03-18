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
    ll n; cin >> n;
    vector<ll> a(n); for(ll& x : a) cin >> x;
    // 
    // the avg needs to be same 
    // ! if odd, it can result in WA, its parity of even/odd 
    // ll sm = accumulate(a.begin(), a.end(), 0);
    // if (sm % n != 0){
    //     cout << "NO" << endl;
    //     return;
    // } 
    // even, odd can chagne values between them, the avg is the same as well 
    ll even = 0, odd = 0;
    ll even_count = 0, odd_count = 0;
    for (ll i=0; i<n; i++){
        if (i%2 == 0){
            even += a[i];
            even_count++;
        }
        else{
            odd += a[i];
            odd_count++;
        }
    }
    // check if possbile 
    // if not divisible or the count is not the same 
    if (odd % odd_count != 0 || even % even_count != 0 || (odd / odd_count != even/even_count)){
        cout << "NO"<< endl;
    }
    else{
        cout << "YES" << endl;
    }
    
    
    // bool poss = true;
    // dbg_out(even%even_count != 0, odd % odd_count != 0, (even/even_count != odd/odd_count));
    // dbg_out((even%even_count != 0 || odd % odd_count != 0) || (even/even_count != odd/odd_count));
    // if (even%even_count != 0 || odd % odd_count != 0){
    //     poss = false;
    // }else{
    //     // it is divisble 
    //     if (even/even_count != odd/odd_count)
    //         poss = false;
    // }
    // cout << (poss ? "YES" : "NO") << endl;
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