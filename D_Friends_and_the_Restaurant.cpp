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
    vector<int> cost(n), budget(n);
    for(auto& c : cost) cin >> c;
    for(auto& b : budget) cin >> b;
    // get the difference between the budget and cost
    vector<int> difference(n, 0);
    for (int i=0; i<n; i++){
        difference[i] = budget[i] - cost[i]; 
    }
    // we need a min of two, but if we use more, we decrease the number of days. thus, find 2 pairs balancing both budgets (min, max)
    sort(difference.begin(), difference.end());
    int left = 0;
    int right = n - 1;
    int days = 0;
    while (left < right){
        // not possible, always need a positve one  
        // if (difference[right] < 0) break;
        // if the negative is bigger then increase left pointer
        while (left + 1 < n && difference[left] < 0 && difference[left] * -1 > difference[right])
            left++;
        // possible, either neg + pos, pos + pos
        if (right > left && difference[right] + difference[left] >= 0){
            // dbg_out(left, right);
            right--;
            left++;
            days++;
        }else{
            break;
        }
    }

    cout << days << nl;
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