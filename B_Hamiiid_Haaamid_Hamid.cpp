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
    int n, x;
    string s;
    cin >> n >> x >> s;
    // either to the right or to the left 
    
    // bool no_walls = true;
    // for (auto val : s){
    //     if (val == '#') no_walls = false;
    // }
    // if (no_walls) {
    //     cout << 1 << endl;
    //     return;
    // }
    if(x==1 || x==n) {
        cout << "1\n";
        return;
    }
    
    // WHATS MISSING IF: THERE IS A WEAKER SIDE WE ARE MISSING IT SINCE WE CAN ADVANCE MORE 
    // WE DO NOT START AT X WE START AT THE CLOSEST L/R WALLS 
    x--;
    int inf = 1e9;
    int lf=-inf, rg=inf;

    for(int i=x-1; i>=0; i--)
        if(s[i]=='#') {
            lf=i;
            break;
        }
    for(int i=x+1; i<n; i++)
        if(s[i]=='#') {
            rg=i;
            break;
        }
    // if no walls 
    if (lf == -inf  && rg == inf){
        cout << "1" << endl;
        return;
    }
    // from one side or the other
    cout << max(min(lf+2, n-x), min(x+1, n-rg+1)) << endl;

    
    // int leftCand = min(lf+1, n-x+1);
    // int rightCand = min(x, n-rg+2);
    // cout << max(leftCand, rightCand) << endl;


    // if one side is not blocked 
    // int left_walls = 0;
    // for (int i=x-1; i>=0; i--){
    //     if (s[i] == '#') left_walls++;
    // }  
    // int right_walls = 0;
    // for (int i=x+1; i<n; i++){
    //     if (s[i] == '#') right_walls++;
    // }
    // if (left_walls == 0 || right_walls == 0)
    
    
//     // dbg_out(n-x+1, x+1);
//     cout << min(n-x+1, x+1) << endl;
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