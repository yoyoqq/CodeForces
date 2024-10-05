#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// overload cout and return pair<A, B>
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// return generic container (vector, set, list) to output stream
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
// debugging
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
// generate random num
#define rng_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng_seed(x) mt19937 rng(x)
// shortcuts
#define all(x) (x).begin(), (x).end() // sort(all(a))

using ll = long long;
typedef long double ld;
const char nl = '\n';

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    //
    sort(all(a));
    // two steps
    // 1. find the extreme points -> min value
    // 2. max the increasing
    int mn = INT_MAX, pos = -1;
    for (int i = 1; i < n; i++)
    {
        if (mn > a[i] - a[i - 1])
        {
            pos = i;
            mn = a[i] - a[i - 1];
        }
    }
    // tricky case with n = 2 
    if (n == 2){
        cout << a[0] << " " << a[1] << nl;
        return;
    }
    // we have the pos where same ... 2 2 .... (abs == 0)
    // put the right side then left
    for (int i = pos; i < n; i++)
    {
        cout << a[i] << " ";
    }
    for (int i = 0; i < pos; i++)
    {
        cout << a[i] << " ";
    }
    cout << nl;

    // bool repeated = false;
    // map<int, int> m;
    // for (int& x : a){
    //     m[x]++;
    //     if (m[x] >= 2) repeated = true;
    // }
    // // first minimize between nums
    // int x = 0;
    // int y = 0;
    // int mn = INT_MAX;
    // for (int i=1; i<n; i++){
    //     if (a[i] - a[i-1] < mn){
    //         mn = a[i] - a[i-1];
    //         x = i - 1;
    //         y = i;
    //     }
    // }
    // int f = a[x], s = a[y];
    // if (n == 2){
    //     cout << f << " " << s << nl;
    //     return;
    // }
    // a[x] = -1;
    // a[y] = -1;
    // // find the biggest to put in
    // int cur_mx = 0;
    // int mx = 0;
    // for (int i=0; i<n; i++){
    //     if (a[i] > cur_mx){
    //         cur_mx = a[i];
    //         mx = i;
    //     }
    // }
    // a[mx] = -1;
    // // dbg_out(mn, x, y);
    // // print with x  n-2 .. y
    // cout << f << " " << cur_mx << " ";
    // for (int i=0; i<n; i++){
    //     if (a[i] == -1) continue;
    //     cout << a[i] << " ";
    // }
    // cout << s << nl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test = 0;
    cin >> test;
    while (test--)
        solve();
    return 0;
}

/*



*/