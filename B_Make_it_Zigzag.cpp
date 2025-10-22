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
    vector<int> a(n+1, 0); 
    for(int i=1; i<=n; i++) cin >> a[i];

    // 1. Operation 1, get max 
    int mx = 0;
    for (int i=1; i<=n; i++){
        mx = max(mx, a[i]);
        if (i % 2 == 0) a[i] = max(a[i], mx);
    }
    // 2. Compute operation 2 greedy jumps 
    int count = 0;
    for (int i=2; i<=n; i+=2){
        // left 
        if (a[i-1] >= a[i]){
            count += (a[i-1]-a[i] + 1);
            a[i-1] = a[i]-1;
        }
        // right 
        if (i+1 <= n && a[i] <= a[i+1]){
            count += (a[i+1]-a[i]+1);
            a[i+1] = a[i]-1;
        }
    }
    cout << count << endl;

    
    // ! NO NEED TO BEIN ORDER, USE 1 FIRST 
    // odd -> get max 
    // even -> pq max 
    // count += (mx - pq.top() + 1), decrease pq.top()
    

    // int mx = 0, count = 0;
    // priority_queue<int> pq;
    // for (int i=1; i<=n; i++){
    //     if (i%2 == 1){
    //         pq.push(a[i]);
    //     }
    //     // count operations 2 
    //     else{
    //         mx = max(mx, a[i]);
    //         while (pq.size() && pq.top() >= mx){
    //             // count++;
    //             int temp = pq.top(); pq.pop();
    //             count += (temp - mx + 1);   
    //             pq.push(mx - 1);
    //         }
    //     }
    //     dbg_out(mx, count, pq.top());
    // }
    // if (n % 2 == 1 && pq.top() >= mx){
    //     int temp = pq.top(); pq.pop();
    //     count += (temp - mx + 1);   
    //     pq.push(mx - 1);
    // }
    // cout << count << endl;
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
