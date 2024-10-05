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

void solve(){
    int n; cin >> n;
    // all odds
    // e + e = e 
    // o + o = e 
    // o + e = o
    // cant convert all to even as we always need one odd 
    // so all to ODDS
    vector<int> a;
    int mx = -1;
    int x;
    for (int i=0; i<n; i++){
        cin >> x;
        if (x % 2 == 0){
            a.push_back(x);
        }else if (mx < x){
            mx = x;
        }
    }
    sort(a.begin(), a.end());

    // if all the same base case
    if (mx == -1 || a.size() == 0){
        cout << 0 << nl;
        return;
    }
    
    // count 
    int count = mx;
    for (int& t : a){
        if (t < mx){    // to surpass a bigger even
            mx += t;
        }else{
            count++;    // if doesnt reach then ++
            break;
        }
    }
    cout << count << nl;
    
    // int n; cin >> n;
    // // priority_queue<int> a; 
    // // int x;
    // // // test case all numbers equal 
    // // // int first;
    // // // bool equal = true;
    // // // int even = 0;
    // // for(int i=0; i<n; i++){
    // //     cin >> x;
    // //     a.push(x);
    // //     if (x % 2 == 0) even++;
    // //     if (i == 0) first = x;
    // //     if (i != 0 && first != x) equal = false;
    // // }
    // if (equal) {
    //     cout << 0 << nl;
    //     return;
    // }
    // // 
    // // all even to odd ? 
    // int count = 0;
    // while (a.size() && even){
    //     x = a.top(); a.pop();
    //     if (x % 2 == 0) even--;
    //     if (x % 2 == 1){
    //         count += 2;
    //     }else{
    //         count += 2;
    //     }
    // }
    // cout << count << nl;
    
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

/*



*/