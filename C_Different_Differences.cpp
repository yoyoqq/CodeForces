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
    int k, n; cin >> k >> n;
    // operate from the back only if possible 
    // 1 2 3 .. n
    vector<int> a(k);
    for (int i=0; i<k; i++){
        a[i] = i + 1;
    }
    a[k-1] = n;
    // dbg_out(a);
    // reversed order start from a diff of 2 3 4 5 .. 
    int cur = 1; 
    for (int i=k-2; i>=0; i--){
        // if operate it has to be greater than prev 
        // else break 
        int poss_replace = a[i+1] - cur;
        if (a[i+1] - cur <= a[i]) break;
        a[i] = poss_replace;
        cur++;
    }

    for (int i=0; i<k; i++){
        cout << a[i] << " ";
    }cout << endl;

    
    // set<int> used;
    // int cur = 1;
    // int cur_sum = 0;
    // while (k && cur <= n){
    //     cout << cur << " ";
    //     used.insert(cur);
    //     cur_sum++;
    //     cur += cur_sum;
    //     k--;
    // }
    // cur -= cur_sum;
    // dbg_out(cur, cur_sum, k);
    // for (int i=cur+1; i<=40 && k>0; i++){
    //     if (used.find(i) == used.end()){
    //         cout << i << " ";
    //         k--;
    //     }
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