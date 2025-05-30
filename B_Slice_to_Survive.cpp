#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;

// where MONSTER in the middle 
int calc(int blocks){
    int count = 0;
    // lets say it is always in the middle 
    while (blocks != 1){
        if (blocks % 2 == 0){
            blocks = blocks/2;
        }else{
            blocks = blocks/2+1;
        }
        count++;
    }
    return count;
}

void solve(){
    int n, m, a, b; cin >> n >> m >> a >> b;
    // calculate row, col independent 

    // left, right 
    int row = min(a, n-a+1);
    int col = min(b, m-b+1);

    // take from one side 
    int crn = calc(n);
    int crm = calc(m);
    int crr = calc(row);
    int crc = calc(col);

    int ans = 1 + min(crr+crm, crn+crc);    // either from col or row 
    cout << ans << endl;
    
    // int ans = min({
    //     calc(a) + calc(col)+1,
    //     calc(n-a+1) + calc(col)+1,
    //     calc(b) + calc(row)+1,
    //     calc(m-b+1) + calc(row)+1,
    // });
    // cout << ans << endl;
    // cout << (calc(row) + calc(col)+1) << endl;
    
    // int left = calc(a);
    // int right = calc(b);
    // int up = calc(n-a+1);
    // int down = calc(m-b+1);

    // dbg_out(left, right, up, down);
    // int mx = max({left+right, up+down, left+up, right+down});
    // cout << mx << endl;
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