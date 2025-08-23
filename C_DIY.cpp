#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define all(x) (x).begin(), (x).end()   // sort(all(a))
using ll = long long;


int arr[200005];

void solve(){
    int n, q; cin >> n;
    map<int, int> m; 
    int num = 0;
    for (int i=0; i<n; i++){
        cin >> q;
        m[q]++;
        // if appears twice we can use it twice as a point 
        if (m[q] == 2){
            arr[num] = q;
            num++;
            m[q] = 0;   
        }
    }    

    // the 4 pairs must be distinct otherwise we are taking the same num 
    if (num < 4){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        sort(arr, arr+num);
        // bot left, bot right 
        cout << arr[0] << " " << arr[1] << " " << arr[0] << " " << arr[num-1] << " ";
        cout << arr[num-2] << " " << arr[1] << " " << arr[num-2] << " " << arr[num-1] << endl;
    }

    
    
    // int x1 = a[0], x2 = a[0], x3 = a[n-1], x4 = a[n-1];
    // int y1 = a[0], y2 = a[0], y3 = a[n-1], y4 = a[n-1];
    // long long width  = 1LL * (x_max - x_min);   // = 0
    // long long height = 1LL * (y_max - y_min);   // >= 0
    // long long area   = width * height;          // = 0
    // cout << area << '\n';
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