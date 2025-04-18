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
    int n, m; cin >> n;
    vector<int> a(n, 0); for(int& x : a) cin >> x;
    cin >> m;
    vector<int> b(m, 0); for (int& x : b) cin >> x;
    // 
    sort(all(a));
    sort(all(b));
    int Alice = a.back();
    int Bob = b.back();
    // dbg_out(Alice, Bob);
    // who has the biggest card 
    if (Alice < Bob){
        cout << "Bob" << endl;
        cout << "Bob" << endl;
    }
    else if (Alice > Bob){
        cout << "Alice" << endl;
        cout << "Alice" << endl;
    }else{
        cout << "Alice" << endl;
        cout << "Bob" << endl;
    }
    
    
    
    // int idx = abs(n-m);
    // // Alice starts 
    // bool Alice = true;
    // for (int i=idx+1; i<n; i++){
    //     if (a[i] < b[i-1]) Alice = false;
    // }
    // // last idx ? 
    // if (Alice && a.back() < b.back()) Alice = false;
    // if (Alice) cout << "Alice" << endl;
    // else cout << "Bob" << endl;
    
    // // Bob starts 
    // bool Bob = true;
    // for (int i=idx+1; i<n; i++){
    //     if (b[i] < a[i-1]) Bob = false;
    // }
    // if (Bob && b.back() < a.back()) Bob = false;
    // if (Bob) cout << "Bob" << endl;
    // else cout << "Alice" << endl;
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