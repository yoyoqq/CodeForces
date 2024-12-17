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
    string n; cin >> n;

    // sum of its digits is divisble by 9
    // length of the num < 1e6
    // map<char, int> freq;
    int count = 0;
    int two = 0, three = 0;
    for (char chr : n){
        count += chr - '0';
        if (chr == '2') two++;
        if (chr == '3') three++;
    }
    // x * 2 + y * 6 
    bool poss =false;
    for (int x=0; x<=min(two, 10); x++){
        for (int y=0; y<=min(three, 10); y++){
            if ((x * 2 + y * 6 + count ) % 9 == 0){
                poss = true;
                break;
            }
        }
    }
    cout << (poss ? "YES" : "NO") << endl;
    

    // int rem = 9 - (count % 9);
    // int sum_to = 0;
    // for (auto [k, v] : freq){
    //     if (k == '2'){
    //         sum_to += (2 * v);
    //     }else if (k == '3'){
    //         sum_to += (6 * v);
    //     }
    //     // sum_to += ((key-1) * v);
    // } 
    // dbg_out(count, rem, sum_to, freq);

    // cout << (sum_to >= rem ? "YES" : "NO") << endl;


    
    
    
    // // 
    // if (stoll(n) % 9 == 0){
    //     cout << "YES" << endl;   
    //     return;
    // }
    // bool poss = false;

    // for (int i=0; i<n.size()-1; i++){
    //     // check for i && i+1
    //     int temp = n;
    //     // 4 combinations 
    //     // temp
    //     if (stoll(temp) % 9 == 0){
    //         poss = true;
    //     }
    //     // i 
    //     if (n[i] < 4){
    //         string temp_i = n;
    //         temp[i] = char(stoll(temp[i]) * 2);
    //         if (temp_i % 9 == 0){
    //             poss = true;
    //         }
    //     }
    //     // i  i+1

    // }
    
     
    // cout << (poss == true ? "YES" : "NO") << endl;
    
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