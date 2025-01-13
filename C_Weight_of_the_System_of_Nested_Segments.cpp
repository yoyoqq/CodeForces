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

struct point{
    int id, weight, position;
};

void solve(){
    int n, m; cin >> n >> m;

    vector<point> arr(m);
    for (int i=0; i<m; i++){
        cin >> arr[i].position >> arr[i].weight;
        arr[i].id = i + 1;
    }

    // get the weight sum 
    sort(arr.begin(), arr.end(), [](point a, point b){
        return a.weight < b.weight;
    });

    int sum = 0;
    for (int i=0; i<m; i++){
        if (i < n*2) sum += arr[i].weight;
        else arr.pop_back();
    }

    // pair them 
    sort(arr.begin(), arr.end(), [](point a, point b){
        return a.position < b.position;
    });

    cout << sum << endl;
    for (int i=0; i<n; i++){
        cout << arr[i].id << " " << arr[arr.size()-i-1].id << endl;
    }
    cout << endl;

    
    // vector<pair<int, int>> arr(m);  // w, x
    // for (int i=0, x, w; i<m; i++){
    //     cin >> arr[i].second >> arr[i].first;
    // }
    // sort(arr.begin(), arr.end());
    // // get only the min values
    // while (arr.size() > n*2){
    //     arr.pop_back();
    // }
    // // dbg_out(arr);
    // sort(arr.begin(), arr.end(), [](auto& left, auto& right){
    //     return left.second < right.second;
    // });
    // // dbg_out(n, m);
    // // get the segments 
    // dbg_out(arr);
    // // if we want to return the minimum sum, we want to take the min values
    // vector<pair<int, int>> pairs;
    // int j = m - 2 * n;
    // int count = 0;
    // for (int i=0; i<n; i++){
    //     count += (arr[i].first + arr[arr.size()-1-i].first);
    //     pairs.push_back({arr[i].second, arr[arr.size()-1-i].second});
    // }
    // // output 
    // cout << count << endl;
    // for (int i=0; i<pairs.size(); i++){
    //     cout << pairs[i].first << " " << pairs[i].second << endl;
    // }
    // cout << endl;
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