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
    vector<ll> a(n*2); 
    for(auto& x : a){
        cin >> x;
    }
    sort(all(a));
    // 
    vector<ll> b(2*n+1);
    // big numbers, 
    for (int i=0; i<n+1; i++){
        b[2*i] = a[n+i-1];
    }
    // small numbers, 
    for (int i=0; i<n-1; i++){
        b[2*i+1] = a[i];
    }

    ll sum = 0;
    for (int i=0; i<=n; i++) sum += b[2*i];
    for (int i=1; i<2*n-1; i+=2) sum -= b[i];
    b[2*n-1] = sum;
    for (auto x : b) cout << x << " "; cout << endl;

    
    
    // vector<int> b;
    // int left = 0;
    // int right = n*2-1; 
    // int turn = true;
    // while (left <= right){
    //     if (turn){
    //         b.push_back(a[right]);
    //         right--;
    //     }else{
    //         b.push_back(a[left]);
    //         left++;
    //     }
    //     turn = !turn;
    // }
    // dbg_out(a, b, left, right);
    // ll sm = 0;
    // for (int i=0; i<b.size(); i+=2){
    //     sm += (b[i] - b[i+1]);
    // }
    // if (seen.find(sm) != seen.end()){
    //     sm = 0;
    //     for (int i=a.size()-1; i>=0; i-=2){
    //         sm += (a[i] - a[i-1]);
    //     }   
    //     cout << sm << " ";
    //     for (int i=a.size()-1; i>=0; i--){
    //         cout << a[i] << " ";
    //     }   
    //     cout << endl;
    //     return;
    // }
    // cout << sm << " ";
    // for(int& x : b) cout << x << " "; cout << endl;
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