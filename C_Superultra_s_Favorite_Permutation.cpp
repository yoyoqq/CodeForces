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

// int find(int n) {
//     for (int i = 2; i <= n; i += 2) { // Check only even numbers
//         int x = i + 1;               // Odd candidate
//         bool is_composite = false;
//         for (int j = 2; j * j <= x; j++) { // Check divisors up to sqrt(x)
//             if (x % j == 0) {
//                 is_composite = true; // Found a divisor, so it's composite
//                 break;
//             }
//         }
//         if (is_composite) {
//             return i; // Return the first even number meeting the criteria
//         }
//     }
//     return 0; // Default return (shouldn't happen for valid inputs)
// }

// void solve(){
//     int n; cin >> n;
//     if (n <= 4) {
//         cout << -1 << endl;
//         return;
//     }
//     vector<int> a;
    
//         // Add odd numbers in descending order
//     for (int i = (n % 2 == 0) ? n - 1 : n; i > 0; i -= 2) {
//         a.push_back(i);
//     }
//     // find even number + 1 such is composite
//     int even_comp = find(n);
//     a.push_back(even_comp);
//     // Add even numbers in ascending order
//     for (int i = 2; i <= n; i += 2) {
//         if (i == even_comp) continue;
//         a.push_back(i);
//     }

//     // Output the permutation
//     for (int& x : a) {
//         cout << x << " ";
//     }
//     cout << '\n';

    // use two biggest 
    // odd 
    // for (int i=1; i<=n; i+=2){
    //     a.push_back(i);
    // }
    // // what number can we use such that max_odd + even is composite 
    // int two = 0;
    // int four = 0;
    // if ((a.back() + 2) % 2 == 0 || (a.back() + 2) % 3 == 0){
    //     a.push_back(2);
    //     two = 2;
    // }else{
    //     a.push_back(4);
    //     four = 4;
    // }
    // for (int i=2; i<=n; i+=2){
    //     if (two == i || four == i) continue;
    //     a.push_back(i);
    // }
    // a.pop_back();

    // for (int i=(n % 2 == 0) ? n-1 : n; i>0; i-=2){
    //     a.push_back(i);
    // }
    // for (int i=2; i<=n; i+=2){
    //     a.push_back(i);
    // }

    // odd 
    // int mid = n / 2;
    // for (int i=1; i<=n; i+=2){
    //     if (i == mid+1) continue;
    //     a.push_back(i);
    // }
    // a.push_back(mid+1);
    // a.push_back(mid);
    // for (int i= (n % 2 == 0) ? n : n-1; i>0; i-=2){
    //     if (mid == i) continue;
    //     a.push_back(i);
    // }

    // for (int& x : a){
    //     cout << x << " ";
    // }    
    // cout << endl;
// }



int find(int n) {
    int odd = (n % 2 == 0) ? n - 1 : n;
    for (int i = 2; i <= n; i += 2) { 
        int x = i + odd;              
        bool is_composite = false;
        for (int j = 2; j * j <= x; j++) { 
            if (x % j == 0) {
                is_composite = true; 
                break;
            }
        }
        if (is_composite) {
            return i; 
        }
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;

    if (n <= 4) {
        cout << -1 << endl; 
        return;
    }

    vector<int> a;

    for (int i = 1; i <= ((n % 2 == 0) ? (n - 1) : n); i += 2){
        a.push_back(i);
    }

    int even_comp = find(n);
    a.push_back(even_comp);

    for (int i = 2; i <= n; i += 2) {
        if (i == even_comp) continue;
        a.push_back(i);
    }

    for (int& x : a) {
        cout << x << " ";
    }
    cout << '\n';
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