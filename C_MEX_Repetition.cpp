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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    ll sum = 0;
    for (int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
    // append the MEX AT THE END
    // perform k op -> shift to the right 
    // perform acyclic rotation
    ll end = 1LL * n*(n+1)/2 - sum;
    k = k % (n+1);
    a.push_back((int)end);
    rotate(a.begin(), a.begin()+(n+1)-k, a.end());
    for (int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    
    // int missing = -1;
    // for (int i=0; i<n+1; i++){
    //     if (seen[i] == false){
    //         missing = i;
    //         break;
    //     }
    // }
    // dbg_out(a, missing);


    // int times = k;
    // if (n && n < k){
    //     times = k % (n + 1);
    // }
    // for (int p=0; p<k % (n+1); p++){
    //     for (int i=0; i<n; i++){
    //         // apply op 
    //         int temp = a[i];
    //         a[i] = missing;
    //         missing = temp;
    //     }
    //     // dbg_out(a);
    // }

    // for (int i=0; i<n; i++){
    //     cout << a[i] << " ";
    // }cout << endl;
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