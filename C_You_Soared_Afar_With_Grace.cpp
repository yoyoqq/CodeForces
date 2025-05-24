#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;

const int maxn = 200100;

int n, a[maxn], b[maxn], m, p[maxn], ans[maxn][2];

void work(int x, int y){
    // what if already correct 
    // swap at stay at same place 
    if (x == y) return;
    ans[++m][0] = x;
    ans[m][1] = y;
    swap(a[x], a[y]);
    swap(p[a[x]], p[a[y]]); // swap positions of the A
    swap(b[x], b[y]);
}

void solve(){

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
    }

    m = 0;
    int x = 0;
    for (int i=1; i<=n; i++){
        if (a[i] == b[i]){
            // if even or more than one same 
            if (n % 2 == 0 || x){
                cout << "-1\n";
                return;
            }
            x = i;
        }
        // the reversed is diff 
        // 3 2 
        // 2 4
        // bs need to match 
        else if (b[p[b[i]]] != a[i]){
            cout << "-1\n";
            return;
        }
    }

    // put into mid 
    if (n & 1){
        work(x, (n+1)/2);
    }
    // make the swaps 
    for (int i=1; i<=n/2; i++){
        // find where p[b[i]] should be and put it in n-i+1
        // find the A pos on top and swap 
        work(p[b[i]], n-i+1);
    }

    cout << m << endl;
    for (int i=1; i<=m; i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    
    
    // int n; cin >> n;
    // vector<int> a(n, 0);
    // vector<int> b(n, 0);
    // for(int& x : a) cin >> x;
    // for(int& x : b) cin >> x;

    // // check if possible 
    // // a && b == bx ax
    // // only point to the same 
    // map<int, set<int>> freq;
    // map<int, int> pos; 
    // int equals = 0;
    // for (int i=0; i<n; i++){
    //     freq[a[i]].insert(b[i]);
    //     freq[b[i]].insert(a[i]);
    //     if (a[i] == b[i]) equals++;
    //     pos[b[i]] = i;
    // }
    // for(auto [k, v] : freq){
    //     if (v.size() >= 2){
    //         cout << -1 << endl;
    //         return;
    //     }
    // }
    // if ((n % 2 == 0 && equals) || equals >= 2){
    //     cout << -1 << endl;
    //     return;
    // }

    // // make swaps 
    // vector<pair<int, int>> moves;
    // int j = n-1; 
    // for (int i=0; i<n/2; i++){
    //     // if equal put on mid 
    //     if (a[i] == b[i]){
    //         int idx = n/2+1;
    //         swap(a[i], a[idx]);
    //         swap(b[i], b[idx]);
    //         moves.push_back({i, idx});
    //         pos[b[i]] = i;
    //     }
    //     // make swap
    //     if (a[i] != b[j]){
    //         int idx = pos[a[i]];
    //         moves.push_back({j, idx});
    //         swap(a[j], a[idx]);
    //         swap(b[j], b[idx]);
    //         pos[b[idx]] = j;
    //         j--;
    //     }
    // }

    // // for(int x : a) cout << x << " "; cout << endl;
    // // for(int x : b) cout << x << " "; cout << endl;
    // // dbg_out(a);
    // // dbg_out(b);

    // cout << moves.size() << endl;
    // for (auto move : moves){
    //     cout << move.first+1 << " " << move.second+1 << "\n";
    // }
    
}

// set<pair<int, int>> freq;
// for (int i=0; i<n; i++){
//     freq.insert({a[i], b[i]});
// }
// for(int i=0; i<n; i++){
//     if (freq.find({b[i], a[i]}) != freq.end()){
//         freq.erase({b[i], a[i]});
//     }
// }
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
