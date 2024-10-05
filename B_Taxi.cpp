#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// overload cout and return pair<A, B>
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// return generic container (vector, set, list) to output stream 
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// debugging
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// generate random num
#define rng_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng_seed(x) mt19937 rng(x)
// shortcuts
#define all(x) (x).begin(), (x).end()   // sort(all(a))

using ll = long long;
typedef long double ld;
const char nl = '\n';
int A[200010];

void solve(){
    int n; cin >> n;
    vector<int> a(5);
    int x;
    for (int i=0; i<n; i++){
        cin >> x;
        a[x]++;
    }
    // dbg_out(a);
    // use math 

    int taxis = 0;
    taxis += a[4];
    taxis += a[3];

    int group1 = max(a[1] - a[3], 0);
    
    // for 2 
    taxis += a[2] / 2;
    if (a[2] % 2 == 1){
        taxis++;
        group1 = max(group1 - 2, 0);    // use gropu 2
    }

    taxis += (group1 + 3) / 4;  // round up remaining gruop of 1 

    cout << taxis << nl;
    
    
    // count 
    /*
    if cases for our current count  
        1: carry on
        2: 
        3: 
        4: taxi++
        5>= : 

    easy is to use a heapq
    */
    // priority_queue<int> pq;
    // int taxis = 0;
    // for (int& x : a){
    //     // what are the options 
    //     // group into 4 
    //     // just use the pq to see the n of taxis used that are not 4
    //     if (pq.size() == 0) pq.push(x);
    //     else{
    //         // take from pq the smallest number and add  
    //         int cur = pq.top(); pq.pop();
    //         // check if greater than 4
    //         // if need new car  
    //         if (cur == 4){
    //             taxis++;
    //             pq.push(x);
    //         }
    //         else if (cur + x == 4){
    //             taxis++;
    //         } 
    //         else if (cur + x > 4){
    //             pq.push(cur);
    //             pq.push(x);
    //         }else{
    //             pq.push(x + cur);
    //         }
    //     }
    // }
    // cout << taxis + pq.size() << nl;
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}

/*



*/