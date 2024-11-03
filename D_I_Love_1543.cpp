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
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    // iterate clockwise find 1543
    int idx = 0;
    int count = 0;
    
    int top = 0, bot = n - 1;
    int left = 0, right = m - 1;

    while (left <= right && top <= bot) {
        vector<char> layer;

        // Traverse from left to right on the top row
        for (int i = left; i <= right; i++) {
            layer.push_back(a[top][i]);
        }
        top++;
        
        // Traverse from top to bottom on the right column
        for (int i = top; i <= bot; i++) {
            layer.push_back(a[i][right]);
        }
        right--;
        
        if (!(left <= right && top <= bot)) {
            break;
        }

        // Traverse from right to left on the bottom row
        for (int i = right; i >= left; i--) {
            layer.push_back(a[bot][i]);
        }
        bot--;

        // Traverse from bottom to top on the left column
        for (int i = bot; i >= top; i--) {
            layer.push_back(a[i][left]);
        }
        left++;

        layer.push_back(layer[0]);
        layer.push_back(layer[1]);
        layer.push_back(layer[2]);
        // Check for the sequence "1543"
        // dbg_out(layer);
        // check the sequence if appears count++
        for (int i=3; i<layer.size(); i++){
            // if (layer.substr(i-3, 4) == "1543") count++;
            if (layer[i-3] == '1' && layer[i-2] == '5' && layer[i-1] == '4' && layer[i] == '3') count++;
        }
    }
    cout << count << endl;
    
    // SIZE INCLUDED
    // outisde in 
    // height -> n 
    // int top = 0, bot = n;
    // int left = 0, right = m;
    // while (left < right && top < bot){
    //     vector<string> layer;
    //     // for tdop 
    //     for (int i=left; i<right; i++){
    //         // top, i
    //         layer.push_back(a[top, i]);
    //     }
    //     top++;
    //     // top to bottom
    //     for (int i=top, i<bot; i++){
    //         // i, right
    //         layer.push_back(a[i, right]);
    //     }
    //     right--;
    //     if (!(left < right && top < bot)){
    //         break;
    //     }
    //     // right to left
    //     for (int i=right-1; i>=left; i--){
    //         // bot, i
    //         layer.push_back(a[bot, i]);
    //     }
    //     bot--;
    //     // bottom top 
    //     for (int i=bot; i>=top; i--){
    //         // i, left
    //         layer.push_back(a[i, left]);
    //     }
    //     left++;
    //     layer.push_back(layer[0]);  
    //     layer.push_back(layer[1]);
    //     layer.push_back(layer[2]);
    //     // check 1543
    //     dbg_out(layer);
    // }
    
    // cout << count << endl;
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test = 1e9; cin >> test;
    while (test--) solve();
    return 0;
}

/*



*/