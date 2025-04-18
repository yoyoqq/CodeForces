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
    // 
    vector<int> pref(n+1, 0);     // pref[i+1] - pref[j]
    for (int i=1; i<=n; i++){
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    // dbg_out(a);
    // dbg_out(pref);

    int left = 1;
    int right = n; 
    int ans = 0;
    while (left <= right){
        int mid = left + (right - left) / 2;
        // ask query, is it from left to mid 
        // ? k x1 x2 x3 .. xn 
        cout << "? " << (mid - left + 1) << " ";
        for (int i=left; i<=mid; i++){
            cout << i << " ";
        }cout << endl;
        // get input 
        int returned_sum = 0;
        cin >> returned_sum;
        int actual_sum = pref[mid] - pref[left-1]; 
        // if the sum matches its on the right 
        if (returned_sum == actual_sum){
            left = mid + 1;
        }else{
            ans = mid;
            right = mid - 1;
        }
    }
    cout << "! " << ans << endl;
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