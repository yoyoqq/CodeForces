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
    int n; cin >> n;
    vector<vector<bool>> matrix(101, vector<bool>(101, 0));
    for (int _=0; _<n; _++){
        int x, y; cin >> x >> y;
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++){
                matrix[i][j] = true;
            }
        } 
    }
    // how to calculate perim ? based on area 
    // count number of nei 
    int black = 0;
    for (int i=0; i<101; i++){
        for (int j=0; j<101; j++){
            // cout << matrix[i][j] << " ";
            // black += matrix[i][j];
            if (matrix[i][j]){
                black += 4;
                if (i && matrix[i-1][j]) black -= 2;
                if (j && matrix[i][j-1]) black -= 2;
            }
        } 
        // cout << endl;
    }
    cout << black << endl;
    
    // vector<int> dx(101, 0), dy(101, 0);
    // for (int i=0; i<n; i++){
    //     int width, height; cin >> width >> height;
    //     for (int x=0; x<height; x++){
    //         dx[x] = max(dx[x], width);
    //     }
    //     for (int y=0; y<width; y++){
    //         dy[y] = max(dy[y], height);
    //     }
    // }
    // dbg_out(dx, dy);
    // int black = 0;
    // for (int i=0; i<101; i++){
    //     black += dx[i];
    // }
    // for (int j=0; j<101; j++){
    //     black += dy[j];
    // }
    // cout << black << endl;
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
