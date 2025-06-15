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
    vector<int> a(n); for(int& x : a) cin >> x;

    map<int, int> freq;
    int num = -1;
    int mx = 0;
    int idx = -1;
    int count = -1;
    for (int i=0; i<n; i++){
        freq[a[i]]++;
        if (freq[a[i]] > mx){
            mx = freq[a[i]];
            num = a[i];
            idx = i;
            count = freq[a[i]];
        }
    }
    // bfs, expand from idx  
    // operation type, i, j
    // if cur < num  :  op type 1
    // else             op type 2 
    // dbg_out(num, idx, count);
    cout << n - count << endl;
    for (int i=idx+1; i<n; i++){    
        if (a[i] != num){
            if (a[i] < num){
                cout << "1 " << i+1 << " " << i - 1+1 << endl;
            }
            else{
                cout << "2 " << i+1 << " " << i-1+1 << endl;
            }
        }
    }
    
    for (int i=idx-1; i>=0; i--){    
        if (a[i] != num){
            if (a[i] < num){
                cout << "1 " << i+1 << " " << i+1+1 << endl;
            }
            else{
                cout << "2 " << i+1 << " " << i+1+1 << endl;
            }
        }
    }

    

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // int test = 0; cin >> test;
    // while (test--) solve();
    solve();
    return 0;
}