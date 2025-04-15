#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


void solve(){
    int n, m; cin >> n >> m;
    bool pi[100][100];
    vector<int> vec;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
            pi[i][j] = false;
            vec.push_back(a[i][j]);
        }
    }
    // store the min and swap it 
    sort(vec.begin(), vec.end());

    // for every runner find a min and assign to it 
    for (int i=0; i<m; i++){
        // iterate the grid 
        for  (int j=0; j<n; j++){
            bool p = false;
            for (int r=0; r<m; r++){
                // if smallest and runner not assigned  -> swap  
                if ((vec[i] == a[j][r]) && (pi[j][r] == false)){
                    int temp = a[j][r];
                    a[j][r] = a[j][i];
                    a[j][i] = temp;
                    p = true;
                    pi[j][i] = true;
                    break;
                }
            }
            if (p) break;
        }
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }cout << endl;
    }
    
    
    // // make swap each runner  
    // for (int runner=0; runner<m; runner++){
    //     // find the location
    //     // swap, row, col      swap the cols 
    //     vector<int> smallest = pq.top(); pq.pop();
    //     int row = smallest[1], col = smallest[2];
    //     swap(a[row][runner], a[row][col]);
    // }
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m; j++){
    //         cout << a[i][j] << " ";
    //     } cout << endl;
    // }
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