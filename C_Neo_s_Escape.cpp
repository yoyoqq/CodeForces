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
    vector<int> a(n, 0);
    // find local maximum 
    for (int i=0, x; i<n; i++){
        cin >> x;
        if (a.size() && a.back() == x);
        else{
            a.push_back(x);
        }
    }
    // the number of peaks is the result
    // think as trapping water, drop from the top to the bottom
    // when its joined form group, otherwise we need to use it 
    int count = 0;
    for (int i=1; i<a.size()-1; i++){
        if (a[i-1] < a[i] && a[i] > a[i+1]) count++;
    }
    if (a.size() >= 2){
        if (a[0] > a[1])count++;
        if (a[a.size()-2] < a[a.size()-1]) count++;
    }
    cout << count << endl;
}
// if (i == 0){
//     if (a[i] > a[i+1]) count++;
// }
// else if (i+1 == n){
//     if (a[i] > a[i-1]) count++;
// }
// else if (a[i-1] <= a[i] && a[i] > a[i+1]) count++;

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