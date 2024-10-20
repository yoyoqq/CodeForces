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
int A[200010];

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    // vector<int> b(m); for (int& x : b) cin >> x;
    int m1, m2;
    cin >> m1 >> m2;
    int pos;
    cin >> pos;
    if (m1 > m2)
        swap(m1, m2);

    if (m1 == pos || m2 == pos){
        cout << 0 << nl;
        return;
    }
    int res = 0;
    // either surrounded, go mid
    if (m1 < pos && pos < m2)
    {
        // dbg_out("mid");
        // cout << min(pos - m1, m2 - pos) << nl;
        cout << (m2 - m1) / 2 << nl;
    }
    // left most pos
    else if (pos < m1 && pos < m2)
    {
        // dbg_out('left');
        cout << m1 - 1 << nl;
    }
    // rightmost pos
    else
    {
        // dbg_out("right");
        cout << n - m2 << nl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test = 1e9;
    cin >> test;
    while (test--)
        solve();
    return 0;
}

/*



*/