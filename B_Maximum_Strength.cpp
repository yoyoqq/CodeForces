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
    string left, right; cin >> left >> right;

    if (left.size() == right.size()){
        int res = 0, sum = 0;
        for (int i=0; i<right.size(); i++){
            int a = left[i] - '0';
            int b = right[i] - '0';
            sum += abs(a - b);
            if (a != b){    // till longest prefix 
                sum += (left.size() - i - 1) * 9;
                break;
            }
        }
        cout << sum << endl;
    }
    else{
        cout << (right.size() - 1) * 9 + int(right[0]-'0') << endl;
    }

    
    

    // ! failed when sizes are the same, we take the longest prefix 
    // left = string(right.size()-left.size(), '0') + left;
    // dbg_out(left, right);
    // find real size 
    // ll diff = 0;

    // string ans(1, right[0]);
    // while (ans + '9' <= right){
    //     ans += '9';
    // }

    // cout << ans << endl;
    
    // cout << right[0];
    // for (int i=0; i<right.size()-1; i++){
        // cout << '9';
    // }
    // cout << endl;
    

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